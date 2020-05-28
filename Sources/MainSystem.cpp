#include "MainSystem.h"
#include <iostream>
MainSystem::MainSystem()
{
	env = oracle::occi::Environment::createEnvironment();

	parksIdsInListView = new std::map<int, int>;

	parkIndexInListView = 0;
	syncStallsUpdate = false;
	syncParklInsert = false;
}

MainSystem::~MainSystem()
{
	for (std::map< int, Park_StallSync* >::iterator it = parksDataForSync->begin(); it != parksDataForSync->end(); ++it) {
		Park_StallSync* point = it->second;
		delete point;
	}

	delete parksDataForSync;
	delete parksIdsInListView;

	env->terminateConnection(conn);
	oracle::occi::Environment::terminateEnvironment(env);
}

std::vector<Park*> * MainSystem::synchronizationParksInsert()
{
	//PARKS INSERT SYNCHRONIZATION
	oracle::occi::Timestamp parkInsertTimeStamp = loadTimestampFromDatabase(LOAD_PARKS_INSERT_TIMESTAMP);
	//CHECK IF WERE CHANGES IN THIS 
	if (parkInsertTimeStamp.isNull() == false) {
		if (parkInsertTimeStamp > this->timestampParkInsert) {
			std::string timestamp = this->getStringFromTimeStamp(this->timestampParkInsert);

			this->syncParklInsert = true;
			this->timestampParkInsert = parkInsertTimeStamp;

			return loadParksFromDatabase(SYNC_LOAD_PARKS_INSERT(timestamp));
		}
	}
	return nullptr;
}

std::vector<Park*>* MainSystem::synchronizationParksUpdate()
{
	//PARKS UPDATE SYNCHRONIZATION
	oracle::occi::Timestamp parkUpdateTimeStamp = loadTimestampFromDatabase(LOAD_PARKS_UPDATE_TIMESTAMP);
	//CHECK IF WERE CHANGES IN THIS 
	if (parkUpdateTimeStamp.isNull() == false) {
		if (parkUpdateTimeStamp > this->timestampParkUpdate) {
			std::string timestamp = this->getStringFromTimeStamp(this->timestampParkUpdate);

			this->timestampParkUpdate = parkUpdateTimeStamp;

			return loadParksFromDatabase(SYNC_LOAD_PARKS_UPDATE(timestamp));
		}
	}
	return nullptr;
}

std::vector<Stall*>* MainSystem::synchronizationStallsUpdate(int parkId, std::string minX, std::string maxX, std::string minY, std::string maxY)
{
	//PARKS UPDATE SYNCHRONIZATION
	oracle::occi::Timestamp stallsUpdateTimeStamp = loadTimestampFromDatabase(LOAD_STALLS_UPDATE_TIMESTAMP(std::to_string(parkId)));
	oracle::occi::Timestamp stallsUpdateTimeStampApk = this->getCurrentPark()->getUpdateTimestamp();
	//CHECK IF WERE CHANGES IN THIS 
	if (stallsUpdateTimeStamp.isNull() == false) {
		if (stallsUpdateTimeStamp > stallsUpdateTimeStampApk) {
			std::string timestamp = this->getStringFromTimeStamp(stallsUpdateTimeStampApk);

			this->currentPark->setUpdateTimestamp(stallsUpdateTimeStamp);

			std::string sql = SYNC_LOAD_STALLS_UPDATE(timestamp, std::to_string(parkId), minX, maxX, minY, maxY);
			return loadStalls(sql);
		}
	}
	return nullptr;
}

std::vector<Stall*>* MainSystem::synchronizationStallsInsert(int parkId, std::string minX, std::string maxX, std::string minY, std::string maxY)
{
	//PARKS INSERT SYNCHRONIZATION
	oracle::occi::Timestamp stallsInsertTimeStamp = loadTimestampFromDatabase(LOAD_STALLS_INSERT_TIMESTAMP(std::to_string(parkId)));
	oracle::occi::Timestamp stallsInsertTimeStampApk = this->getCurrentPark()->getInsertTimestamp();
	//CHECK IF WERE CHANGES IN THIS 
	if (stallsInsertTimeStamp.isNull() == false) {
		if (stallsInsertTimeStamp > stallsInsertTimeStampApk) {
			std::string timestamp = this->getStringFromTimeStamp(stallsInsertTimeStampApk);

			this->currentPark->setInsertTimestamp(stallsInsertTimeStamp);

			std::string sql = SYNC_LOAD_STALLS_INSERT(timestamp, std::to_string(parkId), minX, maxX, minY, maxY);
			return loadStalls(sql);
		}
	}
	return nullptr;
}

bool MainSystem::synchronizationParksDelete()
{
	//PARKS UPDATE SYNCHRONIZATION
	oracle::occi::Timestamp parkDeleteTimeStamp = loadTimestampFromDatabase(LOAD_PARKS_DELETE_TIMESTAMP);
	//CHECK IF WERE CHANGES IN THIS 
	if (parkDeleteTimeStamp.isNull() == false) {
		if (parkDeleteTimeStamp > this->timestampParkDelete) {
			return true;
		}
	}
	return false;
}

bool MainSystem::automaticCoordinateStalls()
{
	std::string loadIdsSQL = LOAD_AUTO_COO_INFO;
	std::vector<ParkAutoCooInfo*> *autoCooInfo = new std::vector<ParkAutoCooInfo*>;
	//LOAD PARKS IDS
	if (this->loadAutoInfoFromDatabase(loadIdsSQL, autoCooInfo) == true) {
		//CHECK FOR EVERY PARK
		for (int i = 0; i < autoCooInfo->size(); i++) {
			ParkAutoCooInfo * currentInfo = autoCooInfo->at(i);
			int countFreeStalls = currentInfo->getCountFreeFree() + currentInfo->getCountFreeFull();
			int countReserveStalls = currentInfo->getCountReserveFree() + currentInfo->getCountReserveFull();
			std::string parkId = std::to_string(currentInfo->getParkId());

			if (currentInfo->getCountFreeFree() < (countFreeStalls * 0.05) && currentInfo->getCountReserveFree() > countReserveStalls * 0.3) {
				//SET RESERVATION STALL TO FREE STALL
				try
				{
					std::string selectMaxFreeStallIdSql = LOAD_MAX_ID_RESERVE_FREE_STALL(parkId);
					std::string stallId = std::to_string(this->loadIntegerFromDatabase(selectMaxFreeStallIdSql));
					std::string newType = "0";
					std::string changeStallTypeSql = CHANGE_STALL_TYPE(parkId, stallId, newType);
					oracle::occi::Statement *stmt = conn->createStatement(changeStallTypeSql);
					stmt->executeUpdate();
					conn->commit();
					conn->terminateStatement(stmt);

					//CHANGE SYNC DATA
					int currentVersionInDatabase = this->loadCurrentSynchVersion(LOAD_CURRENT_SYNC_VER_STALLS(parkId));
					std::string sql1 = CHANGE_SYNC_DATA_STALLS_UPDATE(parkId, std::to_string(currentVersionInDatabase + 1));
					this->doUpdate(sql1);
				}
				catch (const std::exception&)
				{
					System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
					return false;
				}
			}
			else if (currentInfo->getCountFreeFree() > (countFreeStalls * 0.3) && currentInfo->getCountReserveFree() < countReserveStalls * 0.05) {
				//SET FREE STALL TO RESERVATION STALL
				try
				{
					std::string selectMaxFreeStallIdSql = LOAD_MAX_ID_FREE_FREE_STALL(parkId);
					std::string stallId = std::to_string(this->loadIntegerFromDatabase(selectMaxFreeStallIdSql));
					std::string newType = "1";
					std::string changeStallTypeSql = CHANGE_STALL_TYPE(parkId, stallId, newType);
					oracle::occi::Statement *stmt = conn->createStatement(changeStallTypeSql);
					stmt->executeUpdate();
					conn->commit();
					conn->terminateStatement(stmt);

					//CHANGE SYNC DATA
					int currentVersionInDatabase = this->loadCurrentSynchVersion(LOAD_CURRENT_SYNC_VER_STALLS(parkId));
					std::string sql1 = CHANGE_SYNC_DATA_STALLS_UPDATE(parkId, std::to_string(currentVersionInDatabase + 1));
					this->doUpdate(sql1);
				}
				catch (const std::exception&)
				{
					System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
					return false;
				}
			}
		}
	}
	else {
		return false;
	}
		
	for (ParkAutoCooInfo *a : *autoCooInfo) {
		delete a;
	}
	autoCooInfo->clear();
	delete autoCooInfo;
	return true;
}

void MainSystem::setSyncVersionsInApk(int newVersion)
{
	this->synchVersionInAPK = newVersion;
}


void MainSystem::loadAllTimestamps()
{
	try
	{
		oracle::occi::Timestamp timeStampParkInsert = loadTimestampFromDatabase(LOAD_PARKS_INSERT_TIMESTAMP);
		this->timestampParkInsert = timeStampParkInsert;
		oracle::occi::Timestamp timeStampParkUpdate = loadTimestampFromDatabase(LOAD_PARKS_UPDATE_TIMESTAMP);
		this->timestampParkUpdate = timeStampParkUpdate;
		oracle::occi::Timestamp timeStampParkDelete = loadTimestampFromDatabase(LOAD_PARKS_DELETE_TIMESTAMP);
		this->timestampParkDelete = timeStampParkDelete;
	}
	catch (const std::exception&)
	{
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
	}
	
}

void MainSystem::loadDataForStallSync()
{
	try
	{
		this->parksDataForSync = new std::map<int, Park_StallSync*>;

		oracle::occi::Statement *stmt = conn->createStatement(SYNC_LOAD_PARKS_DATA);
		oracle::occi::ResultSet *rs = stmt->executeQuery();

		while (rs->next()) {
			int parkId = rs->getInt(1);
			oracle::occi::Timestamp lastChange = rs->getTimestamp(3);
			oracle::occi::Timestamp lastInsert = rs->getTimestamp(4);

			Park_StallSync *newParkData = new Park_StallSync(parkId, lastChange, lastInsert);
			this->parksDataForSync->insert(std::make_pair(parkId, newParkData));
		}
		stmt->closeResultSet(rs);
		conn->terminateStatement(stmt);
	}
	catch (const std::exception&)
	{
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
	}
	
}

void MainSystem::doUpdateSyncData(std::string sqlTimestamp)
{
	try
	{
		//CHANGE VERSION
		int currentVersionInDatabase = this->loadCurrentSynchVersion(LOAD_CURRENT_SYNC_VER);
		std::string sql1 = CHANGE_SYNC_VERSION(std::to_string(currentVersionInDatabase + 1));
		this->doUpdate(sql1);

		//CHANGE TIMESTAMP
		this->doUpdate(sqlTimestamp);
	}
	catch (const std::exception&)
	{
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
	}
}

oracle::occi::Timestamp MainSystem::loadTimestampFromDatabase(std::string sql)
{
	oracle::occi::Timestamp finallTimestamp;
	try
	{
		oracle::occi::Statement *stmt = conn->createStatement(sql);
		oracle::occi::ResultSet *rs = stmt->executeQuery();

		rs->next();
		finallTimestamp = rs->getTimestamp(1);
		stmt->closeResultSet(rs);
		conn->terminateStatement(stmt);

		return finallTimestamp;
	}
	catch (const std::exception&)
	{
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
		return finallTimestamp;
	}
}

std::vector<Park*>* MainSystem::loadParksFromDatabase(std::string sql)
{
	try
	{
		std::vector<Park*> *parks = new std::vector<Park*>;
		oracle::occi::Statement *stmt = conn->createStatement(sql);
		oracle::occi::ResultSet *rs = stmt->executeQuery();

		while (rs->next()) {

			int id = rs->getInt(1);
			std::string adress = rs->getString(2);
			int capacity = rs->getInt(3);
			std::string name = rs->getString(6);
			int status = rs->getInt(8);
			double latitude = rs->getDouble(9);
			double longtitude = rs->getDouble(10);

			Park *newPark = new Park(id, name, adress, capacity, status, latitude, longtitude);
			parks->push_back(newPark);

			parksIdsInListView->insert(std::make_pair(id, parkIndexInListView));
			parkIndexInListView++;
		}
		stmt->closeResultSet(rs);
		conn->terminateStatement(stmt);

		return parks;
	}
	catch (const std::exception&)
	{
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
		return nullptr;
	}
}

int MainSystem::loadCurrentSynchVersion(std::string sql)
{
	try
	{
		oracle::occi::Statement *stmt = conn->createStatement(sql);
		oracle::occi::ResultSet *rs = stmt->executeQuery();

		int version;
		rs->next();
		version = rs->getInt(1);
		stmt->closeResultSet(rs);
		conn->terminateStatement(stmt);
		return version;
	}
	catch (const std::exception&)
	{
		return LOAD_VERSION_ERROR;
	}
}

int MainSystem::getSynchVersionInAPK()
{
	return this->synchVersionInAPK;
}

int MainSystem::loadIntegerFromDatabase(std::string sql)
{
	try
	{
		oracle::occi::Statement *stmt = conn->createStatement(sql);
		oracle::occi::ResultSet *rs = stmt->executeQuery();

		rs->next();
		int data = rs->getInt(1);

		stmt->closeResultSet(rs);
		conn->terminateStatement(stmt);

		return data;
	}
	catch (const std::exception&)
	{
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
		return 0;
	}
	
}

bool MainSystem::connectToDatabase()
{
	const std::string userName = "parkovisko";
	const std::string password = "shdoaf09ernbJHDJFG";
	const std::string connectString = CONNECT;
	
	try
	{
		conn = env->createConnection(userName, password, connectString);
	}
	catch (const std::exception&)
	{
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
		return false;
	}
	return true;
}

bool MainSystem::doUpdate(std::string sql)
{
	try
	{
		oracle::occi::Statement *stmt = conn->createStatement(sql);
		stmt->executeUpdate();
		conn->commit();
		conn->terminateStatement(stmt);
		return true;
	}
	catch (const std::exception&)
	{
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
		return false;
	}
	
}

//READING STALLS FROM DATABASE
std::vector<Stall*> *MainSystem::loadStalls(std::string sql)
{
	try
	{
		std::vector<Stall*> *stalls = new std::vector<Stall*>;

		oracle::occi::Statement *stmt = conn->createStatement(sql);
		oracle::occi::ResultSet *rs = stmt->executeQuery();

		while (rs->next()) {
			int id = rs->getInt(1);
			int parkidnew = rs->getInt(2);
			int state = rs->getInt(3);
			int type = rs->getInt(4);
			int x = rs->getInt(5);
			int y = rs->getInt(6);
			int deleted = rs->getInt(9);
			int orientation = rs->getInt(10);
			int stallHeight = rs->getInt(11);
			int stallWidth = rs->getInt(12);
			Stall *stall = new Stall(id, parkidnew, state, type, x, y, deleted, orientation, stallHeight, stallWidth);
			stalls->push_back(stall);
		}
		stmt->closeResultSet(rs);
		conn->terminateStatement(stmt);

		return stalls;
	}
	catch (const std::exception&)
	{
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
		return nullptr;
	}
}

std::vector<Stall*>* MainSystem::loadStallsFull(std::string sql, std::vector<Stall*>* stalls, int action)
{
	try
	{
		oracle::occi::Statement *stmt = conn->createStatement(sql);
		oracle::occi::ResultSet *rs = stmt->executeQuery();

		while (rs->next()) {
			int id = rs->getInt(1);
			int parkidnew = rs->getInt(2);
			int x = rs->getInt(5);
			int y = rs->getInt(6);
			int deleted = rs->getInt(9);
			int orientation = rs->getInt(10);
			int stallHeight = rs->getInt(11);
			int stallWidth = rs->getInt(12);


			int state;
			int type;
			std::string spz = "";
			std::string reservationStart = "";
			std::string reservationEnd = "";
			if (action == LOAD_RESERVED_RESERVE_STALL) {
				state = STALL_STATUS_RESERVED;
				type = STALL_TYPE_RESERVE;
				spz = rs->getString(15);
				reservationStart = rs->getString(16);
				reservationEnd = rs->getString(17);
			}
			else if (action == LOAD_RESERVED_FREE_STALL) {
				state = STALL_STATUS_RESERVED;
				type = STALL_TYPE_FREE;
				spz = rs->getString(15);
				reservationStart = rs->getString(16);
				reservationEnd = rs->getString(17);
			}
			else if (action == LOAD_FREE_FREE_STALL) {
				state = STALL_STATUS_FREE;
				type = STALL_TYPE_FREE;
			}

			Stall *stall = new Stall(id, parkidnew, state, type, x, y, deleted, spz, reservationStart, reservationEnd, orientation, stallHeight, stallWidth);
			stalls->push_back(stall);
		}
		stmt->closeResultSet(rs);
		conn->terminateStatement(stmt);

		return stalls;
	}
	catch (const std::exception&)
	{
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
		return nullptr;
	}

}

bool MainSystem::loadAutoInfoFromDatabase(std::string sql, std::vector<ParkAutoCooInfo*> *autoCooInfo)
{
	try
	{
		oracle::occi::Statement *stmt = conn->createStatement(sql);
		oracle::occi::ResultSet *rs = stmt->executeQuery();

		while (rs->next()) {
			int parkId = rs->getInt(1);
			int countFreeFree = rs->getInt(2);
			int countFreeFull = rs->getInt(3);
			int countReserFree = rs->getInt(4);
			int countReserFull = rs->getInt(5);

			ParkAutoCooInfo * newParkAutoCooInfo = new ParkAutoCooInfo(parkId, countFreeFree, countFreeFull, countReserFree, countReserFull);
			autoCooInfo->push_back(newParkAutoCooInfo);
		}
		stmt->closeResultSet(rs);
		conn->terminateStatement(stmt);
	}
	catch (const std::exception&)
	{
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
		return false;
	}
	return true;
}

Stall * MainSystem::loadStallReservationInformations(Stall * stall, std::string sql)
{
	try
	{
		oracle::occi::Statement *stmt = conn->createStatement(sql);
		oracle::occi::ResultSet *rs = stmt->executeQuery();

		while (rs->next()) {
			std::string spz = rs->getString(1);
			std::string startReservation = rs->getString(2);
			std::string endReservation = rs->getString(3);

			startReservation = startReservation.substr(0, 18);
			endReservation = endReservation.substr(0, 18);

			stall->setSpz(spz);
			stall->setReservationStart(startReservation);
			stall->setReservationEnd(endReservation);
		}
		stmt->closeResultSet(rs);
		conn->terminateStatement(stmt);

		return stall;
	}
	catch (const std::exception&)
	{
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
		return nullptr;
	}
}

//CHANGE STALL TYPE IN DATABASE
bool MainSystem::changeStallType(std::string parkId, std::string stallId, int newType)
{
	try
	{
		std::string sqlLoadStall = LOAD_STALL(parkId, stallId);
		std::vector<Stall*> *stall = this->loadStalls(sqlLoadStall);
		if (stall != nullptr) {
			Stall * currStall = stall->at(0);

			std::string newTypeString = std::to_string(newType);
			if (currStall->getState() == STALL_STATUS_FREE) {

				std::string sql = CHANGE_STALL_TYPE(parkId, stallId, newTypeString);
				oracle::occi::Statement *stmt = conn->createStatement(sql);
				stmt->executeUpdate();
				conn->commit();
				conn->terminateStatement(stmt);

				//CHANGE SYNC DATA
				int currentVersionInDatabase = this->loadCurrentSynchVersion(LOAD_CURRENT_SYNC_VER_STALLS(parkId));
				std::string sql1 = CHANGE_SYNC_DATA_STALLS_UPDATE(parkId, std::to_string(currentVersionInDatabase + 1));
				this->doUpdate(sql1);

				delete currStall;
				delete stall;
				return true;
			}
			delete currStall;
		}
		delete stall;
		return false;
	}
	catch (const std::exception&)
	{
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
		return false;
	}
}

bool MainSystem::addStall(std::string x, std::string y, std::string newCapacity, std::string orientation, std::string heidth, std::string width)
{
	std::string parkId = std::to_string(this->getCurrentPark()->getParkoId());
	std::string sqlStallId = LOAD_MAX_ID_FROM_STALLS(parkId);
	std::string stallId = std::to_string(this->loadIntegerFromDatabase(sqlStallId) + 1);
	std::string sql = INSERT_STALL(stallId, parkId, x, y, orientation, heidth, width);
	std::string sqlIncCapacity = CHANGE_PARK_CAPACITY(parkId, newCapacity);
	try
	{
		if (this->doUpdate(sql) == true) {
			//CHANGE SYNC DATA
			int currentVersionInDatabase = this->loadCurrentSynchVersion(LOAD_CURRENT_SYNC_VER_STALLS(parkId));
			std::string sqlStallSync = CHANGE_SYNC_DATA_STALLS_INSERT(parkId, std::to_string(currentVersionInDatabase + 1));
			this->doUpdate(sqlStallSync);
			this->doUpdate(sqlIncCapacity);

			return true;
		}
		else {
			return false;
		}
	}
	catch (const std::exception&)
	{
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
		return false;
	}
}

bool MainSystem::deleteStall(std::string parkId, std::string stallId, std::string newCapacity)
{
	try
	{
		std::string sqlToDelete = CHANGE_STALL_TO_DELETED(parkId, stallId);
		std::string sqlNewCapacity = CHANGE_PARK_CAPACITY(parkId, newCapacity);
		if (this->doUpdate(sqlToDelete) == true) {
			this->doUpdate(sqlNewCapacity);
			//CHANGE SYNC DATA
			int currentVersionInDatabase = this->loadCurrentSynchVersion(LOAD_CURRENT_SYNC_VER_STALLS(parkId));
			std::string sql1 = CHANGE_SYNC_DATA_STALLS_UPDATE(parkId, std::to_string(currentVersionInDatabase + 1));
			this->doUpdate(sql1);

			return true;
		}
		else {
			return false;
		}
	}
	catch (const std::exception&)
	{
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
		return false;
	}
}

bool MainSystem::addPark(std::string parkId, std::string name, std::string adress, int capacity, std::string x, std::string y)
{
		try
		{			
			std::string capacityS = std::to_string(capacity);

			std::string sql = INSERT_PARK(parkId, adress, capacityS, name, x, y);
			oracle::occi::Statement *stmt = conn->createStatement(sql);
			stmt->executeUpdate();

			conn->commit();
			conn->terminateStatement(stmt);

			//CHANGE SYNC VERSIONS
			std::string syncSql = CHANGE_TIMESTAMP_PR_PARKOVISKO_INSERT_NOW;
			this->doUpdateSyncData(syncSql);

			return true;
		}
		catch (const std::exception&)
		{
			System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
			return false;
		}
	return false;
}

int MainSystem::addStallsToPark(std::string parkId, std::vector<Stall*>* stalls, int oldCapacity)
{
	try
	{
		int numberOfSuccesAddedStalls = 0;
		std::string sqlStallId = LOAD_MAX_ID_FROM_STALLS(parkId);
		int index = this->loadIntegerFromDatabase(sqlStallId) + 1;

		for (int i = 0; i < stalls->size(); i++) {
			Stall *newStall = stalls->at(i);
			std::string X = std::to_string(newStall->getX());
			std::string Y = std::to_string(newStall->getY());
			std::string orientation = std::to_string(newStall->getOrientation());
			std::string height = std::to_string(newStall->getStallHeight());
			std::string width = std::to_string(newStall->getStallWidth());
			std::string stallId = std::to_string(index);
			std::string sql = INSERT_STALL(stallId, parkId, X, Y, orientation, height, width);
			//std::string parkId = std::to_string(currentPark->getParkoId());

			if (this->checkPlaceForNewStall(parkId, orientation, X, Y, height, width) == true) {
				if (this->doUpdate(sql) == true) {
					numberOfSuccesAddedStalls++;
					index++;
				}
			}
			delete newStall;
		}
		std::string sqlChangeCapacity = CHANGE_PARK_CAPACITY(parkId, std::to_string(oldCapacity + numberOfSuccesAddedStalls));
		this->doUpdate(sqlChangeCapacity);
		//CHANGE SYNC DATA
		int currentVersionInDatabase = this->loadCurrentSynchVersion(LOAD_CURRENT_SYNC_VER_STALLS(parkId));
		std::string sqlStallSync = CHANGE_SYNC_DATA_STALLS_INSERT(parkId, std::to_string(currentVersionInDatabase + 1));
		this->doUpdate(sqlStallSync);

		delete stalls;

		return numberOfSuccesAddedStalls;
	}
	catch (const std::exception&)
	{
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
		return 0;
	}
}

bool MainSystem::checkExistingData(std::string sql)
{
	try
	{
		oracle::occi::Statement *stmt = conn->createStatement(sql);
		oracle::occi::ResultSet *rs = stmt->executeQuery();

		rs->next();
		int count = rs->getInt(1);
		if (count > 0) {

			stmt->closeResultSet(rs);
			conn->terminateStatement(stmt);
			return true;
		}
		else {
			stmt->closeResultSet(rs);
			conn->terminateStatement(stmt);
			return false;
		}
	}
	catch (const std::exception&)
	{
		return false;
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
	}
}

bool MainSystem::checkPlaceForNewStall(std::string parkId, std::string orientation, std::string X, std::string Y, std::string height, std::string width)
{
	try
	{
		std::string sql;
		if (orientation == "1") {
			sql = CHECK_PLACE_FOR_STALL_HORIZONTAL(parkId, X, height, Y, width);
		}
		else if (orientation == "2") {
			sql = CHECK_PLACE_FOR_STALL_VERTICAL(parkId, X, height, Y, width);
		}
		oracle::occi::Statement *stmt = conn->createStatement(sql);
		oracle::occi::ResultSet *rs = stmt->executeQuery();
		rs->next();
		int count = rs->getInt(1);
		if (count > 0) {
			stmt->closeResultSet(rs);
			conn->terminateStatement(stmt);
			return false;
		}
		else {
			stmt->closeResultSet(rs);
			conn->terminateStatement(stmt);
			return true;
		}
	}
	catch (const std::exception&)
	{
		return false;
		System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
	}
	
}

bool MainSystem::getSyncStallsUpdate()
{
	return this->syncStallsUpdate;
}

bool MainSystem::getSyncParksInsert()
{
	return this->syncParklInsert;
}

void MainSystem::setTimeStampParkInsert(oracle::occi::Timestamp newTimestamp)
{
	this->timestampParkInsert = newTimestamp;
}

void MainSystem::setCurrentPark(Park_StallSync *newCurrentPark)
{
	this->currentPark = newCurrentPark;
}

void MainSystem::setSyncStallsUpdate(bool newState)
{
	this->syncStallsUpdate = newState;
}

void MainSystem::setSyncParksInsert(bool newState)
{
	this->syncParklInsert = newState;
}

std::string MainSystem::getStringFromTimeStamp(oracle::occi::Timestamp timestamp)
{
	int year;
	unsigned int mounth;
	unsigned int day;
	timestamp.getDate(year, mounth, day);
	year -= 2000;
	unsigned int hour;
	unsigned int minutes;
	unsigned int seconds;
	unsigned int f;
	timestamp.getTime(hour, minutes, seconds, f);
	std::string yeaS = std::to_string(year);
	std::string mounthS = this->getStringDateOrTimeFromInt(mounth);
	std::string dayS = this->getStringDateOrTimeFromInt(day);

	std::string hourS = this->getStringDateOrTimeFromInt(hour);
	std::string minutesS = this->getStringDateOrTimeFromInt(minutes);
	std::string secondsS = this->getStringDateOrTimeFromInt(seconds);

	std::string timestampS = dayS + "." + mounthS + "." + yeaS + " " + hourS + ":" + minutesS + ":" + secondsS;

	return timestampS;
}

std::string MainSystem::getStringDateOrTimeFromInt(unsigned int intg)
{
	if (intg < 10) {
		return "0" + std::to_string(intg);
	}
	else {
		return std::to_string(intg);
	}
}

std::string MainSystem::copyString(std::string stringg)
{
	std::string newString;
	newString.resize(stringg.length());
	for (int i = 0; i < stringg.length(); i++) {
		newString.at(i) = stringg.at(i);
	}
	newString = "aaa";
	return newString;
}

oracle::occi::Timestamp MainSystem::getTimestampFromDateTimePicker(System::Windows::Forms::DateTimePicker ^ dateTimeSticker)
{
	int year = dateTimeSticker->Value.Year;
	int month = dateTimeSticker->Value.Month;
	int day = dateTimeSticker->Value.Day;

	int hour = dateTimeSticker->Value.Hour;
	int minutes = dateTimeSticker->Value.Minute;
	int seconds = dateTimeSticker->Value.Second;
	int miSeconds = dateTimeSticker->Value.Millisecond;

	oracle::occi::Timestamp timestamp;
	timestamp = this->timestampParkInsert;
	timestamp.setDate(year, month, day);
	timestamp.setTime(hour, minutes, seconds, miSeconds);

	return timestamp;
}

int MainSystem::getIndexInListview(int parkId)
{
	int index = this->parksIdsInListView->find(parkId)->second;
	return index;
}

Park_StallSync * MainSystem::getCurrentPark()
{
	return this->currentPark;
}

std::map<int, Park_StallSync*>* MainSystem::getParksData()
{
	return parksDataForSync;
}


