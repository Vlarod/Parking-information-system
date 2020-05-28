#pragma once
#include <string>
#include <occi.h>
#include <vector>
#include <map>
#include "Park.h"
#include "Stall.h"
#include "Park_StallSync.h"
#include "ParkAutoCooInfo.h"

#include "COMMANDS.h"
#include "DEFINES.h"

class MainSystem
{
public:
	MainSystem();
	~MainSystem();

	std::vector<Park*> *synchronizationParksInsert();
	std::vector<Park*> *synchronizationParksUpdate();
	std::vector<Stall*> *synchronizationStallsUpdate(int parkId, std::string minX, std::string maxX, std::string minY, std::string maxY);
	std::vector<Stall*> *synchronizationStallsInsert(int parkId, std::string minX, std::string maxX, std::string minY, std::string maxY);
	bool synchronizationParksDelete();
	bool automaticCoordinateStalls();

	void setSyncVersionsInApk(int newVersion);
	void loadAllTimestamps();
	void loadDataForStallSync();
	void doUpdateSyncData(std::string sqlTimestamp);

	oracle::occi::Timestamp loadTimestampFromDatabase(std::string sql);
	std::vector<Park*> *loadParksFromDatabase(std::string sql);

	int loadCurrentSynchVersion(std::string sql);
	int getSynchVersionInAPK();
	int loadIntegerFromDatabase(std::string sql);

	bool connectToDatabase();
	bool doUpdate(std::string sql);

	std::vector<Stall*> *loadStalls(std::string sql);
	std::vector<Stall*> *loadStallsFull(std::string sql, std::vector<Stall*>* stalls, int action);
	bool loadAutoInfoFromDatabase(std::string sql, std::vector<ParkAutoCooInfo*> *autoCooInfo);
	Stall * loadStallReservationInformations(Stall* stall, std::string sql);
	bool changeStallType(std::string parkId, std::string stallId, int newType);
	bool addStall(std::string x, std::string y, std::string newCapacity, std::string orientation, std::string heidth, std::string width);
	bool deleteStall(std::string parkId, std::string stallId, std::string newCapacity);
	bool addPark(std::string parkId, std::string name, std::string adress, int capacity, std::string x, std::string y);
	int addStallsToPark(std::string parkId, std::vector<Stall*> *stalls, int oldCapacity);
	bool checkExistingData(std::string sql);
	bool checkPlaceForNewStall(std::string parkId, std::string orientation, std::string X, std::string Y, std::string height, std::string width);
	bool getSyncStallsUpdate();
	bool getSyncParksInsert();

	void setTimeStampParkInsert(oracle::occi::Timestamp newTimestamp);
	void setCurrentPark(Park_StallSync *newCurrentPark);
	void setSyncStallsUpdate(bool newState);
	void setSyncParksInsert(bool newState);

	std::string getStringFromTimeStamp(oracle::occi::Timestamp timestamp);
	std::string getStringDateOrTimeFromInt(unsigned int intg);

	std::string copyString(std::string stringg);

	oracle::occi::Timestamp getTimestampFromDateTimePicker(System::Windows::Forms::DateTimePicker ^ dateTimeSticker);

	int getIndexInListview(int parkId);
	Park_StallSync *getCurrentPark();
	std::map<int, Park_StallSync*> *getParksData();
private:
	int parkIndexInListView;
	int synchVersionInAPK;

	bool syncStallsUpdate;
	bool syncParklInsert;

	oracle::occi::Timestamp timestampParkInsert;
	oracle::occi::Timestamp timestampParkUpdate;
	oracle::occi::Timestamp timestampParkDelete;

	Park_StallSync * currentPark;

	//NEED FOR MAP IN LISTVIEW IN SYNCHRONIZATION
	std::map<int, int> *parksIdsInListView;
	std::map<int, Park_StallSync*> *parksDataForSync;

	oracle::occi::Environment *env;
	oracle::occi::Connection *conn;
};

