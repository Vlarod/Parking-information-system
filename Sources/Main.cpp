#include "MyForm.h"

//PRINT ALL PARKS FROM DATABASE TO LISTVIEW
void ParkingAdministration::MyForm::printParks(std::vector<Park*>* parks)
{
	if (parks->size() > 0) {
		if (mainSystem->getSyncParksInsert() == false) {
			listViewParkList->Items->Clear();
		}
		else {
			mainSystem->setSyncParksInsert(false);
		}

		for (int i = 0; i < parks->size(); i++) {
			ListViewItem^ item = gcnew ListViewItem();
			item->UseItemStyleForSubItems = false;

			item->Text = gcnew String(std::to_string(parks->at(i)->getId()).c_str());
			item->SubItems->Add("");

			item->SubItems[1]->Text = gcnew String(parks->at(i)->getName().c_str());
			item->SubItems->Add("");

			std::string status;
			if (parks->at(i)->getStatus() == PARK_NOT_ACTIVE) {
				item->SubItems[2]->BackColor = System::Drawing::Color::OrangeRed;
				status = "Neaktívne";
			} 
			else if (parks->at(i)->getStatus() == PARK_ACTIVE) {
				item->SubItems[2]->BackColor = System::Drawing::Color::ForestGreen;
				status = "Aktívne";
			}
			item->SubItems[2]->Text = gcnew String(status.c_str());
			
			item->SubItems->Add("");
			
			listViewParkList->Items->Add(item);
		}

		for (Park *a : *parks) {
			delete a;
		}

		parks->clear();
		delete parks;
	}
	else {
		delete parks;
		listViewParkList->Items->Clear();
	}
}

void ParkingAdministration::MyForm::printDeletedStallsToList(std::vector<Stall*>* stalls)
{
	listViewDeletedStalls->Items->Clear();

	for (int i = 0; i < stalls->size(); i++) {
		ListViewItem^ item = gcnew ListViewItem();
		Stall *currentStall = stalls->at(i);

		item->Text = gcnew String(std::to_string(currentStall->getId()).c_str());
		item->SubItems->Add("");

		item->SubItems[1]->Text = gcnew String(std::to_string(currentStall->getParkId()).c_str());
		item->SubItems->Add("");

		std::string stallState;
		if (currentStall->getState() == STALL_STATUS_FREE) {
			stallState = "Volné";
		} 
		else if (currentStall->getState() == STALL_STATUS_RESERVED) {
			stallState = "Rezervované";
		}
		item->SubItems[2]->Text = gcnew String(stallState.c_str());
		item->SubItems->Add("");

		std::string stallType;
		if (currentStall->getType() == STALL_TYPE_FREE) {
			stallType = "Volné";
		}
		else if (currentStall->getType() == STALL_TYPE_RESERVE) {
			stallType = "Rezervované";
		}
		else if (currentStall->getType() == STALL_TYPE_SERVICE) {
			stallType = "Servis";
		}

		item->SubItems[3]->Text = gcnew String(stallType.c_str());
		item->SubItems->Add("");

		item->SubItems[4]->Text = gcnew String(std::to_string(currentStall->getX()).c_str());
		item->SubItems->Add("");

		item->SubItems[5]->Text = gcnew String(std::to_string(currentStall->getY()).c_str());
		item->SubItems->Add("");

		listViewDeletedStalls->Items->Add(item);
	}

	for (Stall *a : *stalls) {
		delete a;
	}

	stalls->clear();
	delete stalls;
}

void ParkingAdministration::MyForm::printUpdateParks(std::vector<Park*>* parks)
{
	for (int i = 0; i < parks->size(); i++) {
		int id = parks->at(i)->getId();
		int indexInListView = mainSystem->getIndexInListview(id);
		std::string newName = parks->at(i)->getName();
		std::string status;
		if (parks->at(i)->getStatus() == PARK_NOT_ACTIVE) {
			listViewParkList->Items[indexInListView]->SubItems[2]->BackColor = System::Drawing::Color::OrangeRed;
			status = "Neaktívne";
		}
		else if (parks->at(i)->getStatus() == PARK_ACTIVE) {
			listViewParkList->Items[indexInListView]->SubItems[2]->BackColor = System::Drawing::Color::ForestGreen;
			status = "Aktívne";
		}
		listViewParkList->Items[indexInListView]->SubItems[2]->Text = gcnew String(status.c_str());
		listViewParkList->Items[indexInListView]->SubItems[1]->Text = gcnew String(newName.c_str());
	}
	for (Park *a : *parks) {
		delete a;
	}

	parks->clear();
	delete parks;
}

//PRINT ALL STALLS FROM CURRENT PARK TO WINDOW
void ParkingAdministration::MyForm::printStalls(std::vector<Stall*>* stalls)
{	
	if (stalls != nullptr) {
		Stall *currentStall;
		for (int i = 0; i < stalls->size(); i++) {
			currentStall = stalls->at(i);

			//DELETE EXISTING STALLS FOR SYNCHRONIZATION
			if (mainSystem->getSyncStallsUpdate() == true) {
				System::String ^stallKey = gcnew String(std::to_string(currentStall->getId()).c_str());
				this->Controls->RemoveByKey(stallKey);
			}
			if (currentStall->getDeleted() == 0) {
				//PRINT STALLS ON SCREEN
				std::string butt = std::to_string(currentStall->getId());

				Button^ button = gcnew System::Windows::Forms::Button();
				button->Text = gcnew String(butt.c_str());

				this->Controls->Add(button);

				System::String ^ buttonKey = gcnew String(butt.c_str());
				button->Name = buttonKey;

				if (currentStall->getOrientation() == STALL_HORIZONTAL) {
					button->Size = System::Drawing::Size(currentStall->getStallHeight() / STALL_COEFFICIENT, currentStall->getStallWidth() / STALL_COEFFICIENT);
					int heig = currentStall->getStallHeight() / STALL_COEFFICIENT;
					int wi = currentStall->getStallWidth() / STALL_COEFFICIENT;
				}
				else if (currentStall->getOrientation() == STALL_VERTICAL) {
					button->Size = System::Drawing::Size(currentStall->getStallWidth() / STALL_COEFFICIENT, currentStall->getStallHeight() / STALL_COEFFICIENT);
				}

				button->Location = System::Drawing::Point((currentStall->getX() / STALL_COEFFICIENT) + STALLS_PRINT_LEFT_OFFSET - (this->currentStartScreenPositionX / STALL_COEFFICIENT), (currentStall->getY() / STALL_COEFFICIENT) + STALLS_PRINT_TOP_OFFSET - (this->currentStartScreenPositionY / STALL_COEFFICIENT));
				int a = currentStall->getX() / STALL_COEFFICIENT;
				std::string color;

				if (currentStall->getState() == 0) {
					button->BackColor = System::Drawing::Color::ForestGreen;
				}
				else {
					button->BackColor = System::Drawing::Color::Red;
				}

				if (currentStall->getType() == STALL_TYPE_FREE) {
					//button->Size = System::Drawing::Size(PARK_SIZE_X, PARK_SIZE_Y);
					//button->Image = ParkingAdministration::Properties::Resources::images.png;
					//button->Image = Image::FromFile("C:\\Users\\paliesek.vladimir\\Documents\\Visual Studio 2015\\Projects\\ParkingAdministration\\IMAGES\\images.png");
				}
				else if (currentStall->getType() == STALL_TYPE_RESERVE) {
					button->FlatStyle = FlatStyle::Flat;
					button->FlatAppearance->BorderColor = Color::Orange;
					button->FlatAppearance->BorderSize = 8;
				}
				else if (currentStall->getType() == STALL_TYPE_SERVICE) {
					button->BackColor = System::Drawing::Color::Aqua;
				}

				button->Click += gcnew System::EventHandler(this, &MyForm::button_Click);
			}
		}
		mainSystem->setSyncStallsUpdate(false);

		for (Stall *a : *stalls) {
			delete a;
		}

		stalls->clear();
		delete stalls;
	}
}

void ParkingAdministration::MyForm::printStallsFromRange(int shiftDirection)
{
	//READING FROM LISTVIEW
	std::string currId = msclr::interop::marshal_as<std::string>(listViewParkList->SelectedItems[0]->SubItems[0]->Text);
	int id = std::stoi(currId);

	if (shiftDirection == STALLS_SHIFT_DIRECTION_LEFT) {
		this->currentStartScreenPositionX -= (this->Width - STALLS_PRINT_RIGHT_OFFSET - STALLS_PRINT_LEFT_OFFSET) * STALL_COEFFICIENT;
	}
	else if (shiftDirection == STALLS_SHIFT_DIRECTION_RIGHT) {
		this->currentStartScreenPositionX += (this->Width - STALLS_PRINT_RIGHT_OFFSET - STALLS_PRINT_LEFT_OFFSET) * STALL_COEFFICIENT;
	}
	else if (shiftDirection == STALLS_SHIFT_DIRECTION_UP) {
		this->currentStartScreenPositionY -= (this->Height - STALLS_PRINT_TOP_OFFSET - STALLS_PRINT_BOTTOM_OFFSET) * STALL_COEFFICIENT;
	}
	else if (shiftDirection == STALLS_SHIFT_DIRECTION_DOWN) {
		this->currentStartScreenPositionY += (this->Height - STALLS_PRINT_TOP_OFFSET - STALLS_PRINT_BOTTOM_OFFSET) * STALL_COEFFICIENT;
	}

	std::string minX = std::to_string(this->currentStartScreenPositionX);
	std::string maxX = std::to_string(this->currentStartScreenPositionX + ((this->Width - STALLS_PRINT_RIGHT_OFFSET - STALLS_PRINT_LEFT_OFFSET) * STALL_COEFFICIENT));
	std::string minY = std::to_string(this->currentStartScreenPositionY);
	std::string maxY = std::to_string(this->currentStartScreenPositionY + ((this->Height - STALLS_PRINT_TOP_OFFSET - STALLS_PRINT_BOTTOM_OFFSET) * STALL_COEFFICIENT));

	std::vector<Stall*> *stalls;
	if (this->currentShowStalls == SHOW_STALLS_CURRENT_TIME) {
		std::string sql = LOAD_STALLS_FROM_RANGE(std::to_string(id), minX, maxX, minY, maxY);
		stalls = mainSystem->loadStalls(sql);
	}
	else if (this->currentShowStalls == SHOW_STALLS_CHOSED_TIME) {
		oracle::occi::Timestamp timestamp = mainSystem->getTimestampFromDateTimePicker(this->dateTimePickerShowStallsTime);
		std::string timestampS = mainSystem->getStringFromTimeStamp(timestamp);

		stalls = new std::vector<Stall*>;

		std::string sql = LOAD_STALLS_FROM_TIME_RESERVED_RESERVE(std::to_string(id), minX, maxX, minY, maxY, timestampS);
		mainSystem->loadStallsFull(sql, stalls, LOAD_RESERVED_RESERVE_STALL);

		std::string sql1 = LOAD_STALLS_FROM_TIME_RESERVED_FREE(std::to_string(id), minX, maxX, minY, maxY, timestampS);
		mainSystem->loadStallsFull(sql1, stalls, LOAD_RESERVED_FREE_STALL);

		std::string sql2 = LOAD_STALLS_FROM_TIME_FREE_FREE(std::to_string(id), minX, maxX, minY, maxY, timestampS);
		mainSystem->loadStallsFull(sql2, stalls, LOAD_FREE_FREE_STALL);
	}

	this->deleteStallsFromScreen();

	if (stalls != nullptr) {
		currParkNumberOfStalls = stalls->size();
	}
	this->printStalls(stalls);

	this->setStallsArrows();
}

void ParkingAdministration::MyForm::showStallInformations(int stallId, int parkId)
{
	std::string sql = LOAD_STALL(std::to_string(parkId), std::to_string(stallId));
	std::vector<Stall*> *stall = mainSystem->loadStalls(sql);
	if (stall != nullptr) {
		Stall *currentStall = stall->at(0);

		std::string stallID = std::to_string(currentStall->getId());
		std::string parkID = std::to_string(currentStall->getParkId());
		std::string stallStatus;
		std::string stallType;

		if (currentStall->getState() == STALL_STATUS_FREE) {
			stallStatus = "Volné";
		}
		else {
			stallStatus = "Obsadené";
		}

		if (currentStall->getType() == STALL_TYPE_FREE) {
			stallType = "Volné";
			this->checkBoxStallFree->Checked = true;
			this->checkBoxStallReserve->Checked = false;
			this->checkBoxStallOutOfService->Checked = false;
		}
		else if (currentStall->getType() == STALL_TYPE_RESERVE) {
			stallType = "Rezervacné";
			this->checkBoxStallReserve->Checked = true;
			this->checkBoxStallFree->Checked = false;
			this->checkBoxStallOutOfService->Checked = false;
		}
		else if (currentStall->getType() == STALL_TYPE_SERVICE) {
			stallType = "Servis";
			this->checkBoxStallOutOfService->Checked = true;
			this->checkBoxStallReserve->Checked = false;
			this->checkBoxStallFree->Checked = false;
		}

		if (this->currentShowStalls == SHOW_STALLS_CURRENT_TIME) {
			std::string sqlResInfo = LOAD_STALL_RESERVATION_INFO_CURRENT_TIME(parkID, stallID);
			currentStall = mainSystem->loadStallReservationInformations(currentStall, sqlResInfo);
		}
		else if (this->currentShowStalls == SHOW_STALLS_CHOSED_TIME) {
			System::String ^ time = this->dateTimePickerShowStallsTime->Value.ToString();
			std::string timeS = msclr::interop::marshal_as<std::string>(time);
			std::string sqlResInfo = LOAD_STALL_RESERVATION_INFO(parkID, stallID, timeS);
			currentStall = mainSystem->loadStallReservationInformations(currentStall, sqlResInfo);
		}

		this->labelSPZ->Text = gcnew String(currentStall->getSpz().c_str());
		this->labelStart->Text = gcnew String(currentStall->getReservationStart().c_str());
		this->labelEnd->Text = gcnew String(currentStall->getReservationEnd().c_str());

		std::string stallX = std::to_string(currentStall->getX());
		std::string stallY = std::to_string(currentStall->getY());


		this->labelStallId->Text = gcnew String(stallID.c_str());
		this->labelParkId->Text = gcnew String(parkID.c_str());
		this->labelStallStatus->Text = gcnew String(stallStatus.c_str());
		this->labelStallType->Text = gcnew String(stallType.c_str());
		this->labelStallX->Text = gcnew String(stallX.c_str());
		this->labelStallY->Text = gcnew String(stallY.c_str());

		delete currentStall;
	}
	delete stall;
}

void ParkingAdministration::MyForm::showParkingInformations()
{
	if (this->listViewParkList->SelectedItems->Count > 0) {
		this->groupBoxInformationsAboutParking->Visible = true;

		std::string parkId = msclr::interop::marshal_as<std::string>(listViewParkList->SelectedItems[0]->SubItems[0]->Text);

		std::vector<Park*> *parks = mainSystem->loadParksFromDatabase(LOAD_PARK_VIA_ID(parkId));
		if (parks != nullptr) {
			Park *park = parks->at(0);

			std::string id = std::to_string(park->getId());
			std::string name = park->getName();
			std::string adress = park->getAdress();
			std::string capacity = std::to_string(park->getCapacity());
			std::string latitude = std::to_string(park->getLatitude());
			std::string longtitude = std::to_string(park->getLongtitude());
			std::string status;
			if (park->getStatus() == 0) {
				status = "Neaktívne";
				checkBoxParkStatusOff->Checked = true;
				checkBoxParkStatusOn->Checked = false;
			} 
			else if (park->getStatus() == 1) {
				status = "Aktívne";
				checkBoxParkStatusOn->Checked = true;
				checkBoxParkStatusOff->Checked = false;
			}

			this->labelParkInformationsName->Text = gcnew String(name.c_str());
			this->labelParkInformationsId->Text = gcnew String(id.c_str());
			this->labelParkInformationsAdress->Text = gcnew String(adress.c_str());
			this->labelParkInformationsCapacity->Text = gcnew String(capacity.c_str());
			this->labelParkInformationsStatus->Text = gcnew String(status.c_str());
			this->labelParkInformationsLatitude->Text = gcnew String(latitude.c_str());
			this->labelParkInformationsLongtitude->Text = gcnew String(longtitude.c_str());

			delete park;
			parks->clear();
			delete parks;
		}
	}
	else {
		this->groupBoxInformationsAboutParking->Visible = false;
	}
}

void ParkingAdministration::MyForm::searchingParks()
{
	bool somethingChecked = false;
	bool badWord = false;
	std::string sqlFinding;
	std::string findingWord = msclr::interop::marshal_as<std::string>(this->textBoxSearchParkFindingWord->Text);
	
	if (this->currentScreen == NOT_DELETED_PARKS_SCREEN) {
		std::string comboBoxString = msclr::interop::marshal_as<std::string>(this->comboBoxParkSearchStatus->Text);
		if (checkBoxParkSearchName->Checked == true) {
			somethingChecked = true;
			if (this->textBoxSearchParkFindingWord->Text->Length > 0) {
				if (comboBoxString == "Aktivne") {
					sqlFinding = LOAD_FINDING_PARK_NAME_NOT_DELETED_ON(findingWord);
				}
				else if (comboBoxString == "Neaktivne") {
					sqlFinding = LOAD_FINDING_PARK_NAME_NOT_DELETED_OFF(findingWord);
				}
				else {
					sqlFinding = LOAD_FINDING_PARK_NAME_NOT_DELETED(findingWord);
				}
			}
			else {
				sqlFinding = LOAD_PARKS_NOT_DELETED;
			}
		}
		else if (checkBoxParkSearchId->Checked == true) {
			somethingChecked = true;
			if (this->textBoxSearchParkFindingWord->Text->Length > 0) {
				try
				{
					std::stoi(findingWord);
					if (comboBoxString == "Aktivne") {
						sqlFinding = LOAD_FINDING_PARK_ID_NOT_DELETED_ON(findingWord);
					}
					else if (comboBoxString == "Neaktivne") {
						sqlFinding = LOAD_FINDING_PARK_ID_NOT_DELETED_OFF(findingWord);
					}
					else {
						sqlFinding = LOAD_FINDING_PARK_ID_NOT_DELETED(findingWord);
					}
				}
				catch (const std::exception&)
				{
					badWord = true;
					this->textBoxSearchParkFindingWord->Clear();
					MessageBox::Show("Zadajte celé Císlo!");
				}			
			}
			else {
				sqlFinding = LOAD_PARKS_NOT_DELETED;
			}
		}
	}
	else if (this->currentScreen == DELETED_PARKS_SCREEN) {
		if (checkBoxParkSearchName->Checked == true) {
			somethingChecked = true;
			if (this->textBoxSearchParkFindingWord->Text->Length > 0) {
				sqlFinding = LOAD_FINDING_PARK_NAME_DELETED(findingWord);
			}
			else {
				sqlFinding = LOAD_PARKS_DELETED;
			}
		}
		else if (checkBoxParkSearchId->Checked == true) {
			somethingChecked = true;
			if (this->textBoxSearchParkFindingWord->Text->Length > 0) {
				try
				{
					std::stoi(findingWord);
					sqlFinding = LOAD_FINDING_PARK_ID_DELETED(findingWord);
				}
				catch (const std::exception&)
				{
					badWord = true;
					this->textBoxSearchParkFindingWord->Clear();
					MessageBox::Show("Zadajte celé ?íslo!");
				}
			}
			else {
				sqlFinding = LOAD_PARKS_DELETED;
			}
		}
	}

	if (somethingChecked == true && badWord == false) {
		std::vector<Park*> *parks = mainSystem->loadParksFromDatabase(sqlFinding);
		if (parks->size() > 0) {
			this->printParks(parks);
		}
		else {
			this->listViewParkList->Items->Clear();
		}
	}
}

void ParkingAdministration::MyForm::searchingStalls()
{
	bool somethingChecked = false;
	bool badWord = false;
	std::string sqlFinding;
	std::string findingWord = msclr::interop::marshal_as<std::string>(this->textBoxSearchingWordDeletedStalls->Text);
	if (this->currentScreen == DELETED_STALLS_SCREEN) {
		if (checkBoxSearchInDeletedStallsStallId->Checked == true) {
			somethingChecked = true;
			if (this->textBoxSearchingWordDeletedStalls->Text->Length > 0) {
				try
				{
					std::stoi(findingWord);
					sqlFinding = LOAD_FINDING_STALL_ID_DELETED(findingWord);
				}
				catch (const std::exception&)
				{
					badWord = true;
					this->textBoxSearchingWordDeletedStalls->Clear();
					MessageBox::Show("Zadajte celé ?íslo!");
				}
			}
			else {
				sqlFinding = LOAD_DELETED_STALLS;
			}
		}
		else if (checkBoxSearchInDeletedStallsParkId->Checked == true) {
			somethingChecked = true;
			if (this->textBoxSearchingWordDeletedStalls->Text->Length > 0) {
				try
				{
					std::stoi(findingWord);
					sqlFinding = LOAD_FINDING_STALL_PARKID_DELETED(findingWord);
				}
				catch (const std::exception&)
				{
					badWord = true;
					this->textBoxSearchingWordDeletedStalls->Clear();
					MessageBox::Show("Zadajte celé ?íslo!");
				}
			}
			else {
				sqlFinding = LOAD_DELETED_STALLS;
			}
		}
		else if (checkBoxSearchInDeletedStallsStallX->Checked == true) {
			somethingChecked = true;
			if (this->textBoxSearchingWordDeletedStalls->Text->Length > 0) {
				try
				{
					std::stoi(findingWord);
					sqlFinding = LOAD_FINDING_STALL_X_DELETED(findingWord);
				}
				catch (const std::exception&)
				{
					badWord = true;
					this->textBoxSearchingWordDeletedStalls->Clear();
					MessageBox::Show("Zadajte celé ?íslo!");
				}
			}
			else {
				sqlFinding = LOAD_DELETED_STALLS;
			}
		}
		else if (checkBoxSearchInDeletedStallsStallY->Checked == true) {
			somethingChecked = true;
			if (this->textBoxSearchingWordDeletedStalls->Text->Length > 0) {
				try
				{
					std::stoi(findingWord);
					sqlFinding = LOAD_FINDING_STALL_Y_DELETED(findingWord);
				}
				catch (const std::exception&)
				{
					badWord = true;
					this->textBoxSearchingWordDeletedStalls->Clear();
					MessageBox::Show("Zadajte celé ?íslo!");
				}
			}
			else {
				sqlFinding = LOAD_DELETED_STALLS;
			}
		}
	}

	if (somethingChecked == true && badWord == false) {
		std::vector<Stall*> *stalls = mainSystem->loadStalls(sqlFinding);
		if (stalls->size() > 0) {
			this->printDeletedStallsToList(stalls);
		}
		else {
			this->listViewDeletedStalls->Items->Clear();
		}
	}
}

void ParkingAdministration::MyForm::deleteStallsFromScreen()
{
	//DELETE ALL STALLS FROM VIEW BEFORE
	if (this->currentScreen == STALLS_SCREEN) {
		for (int i = 0; i < currParkNumberOfStalls; i++) {
			int size = this->Controls->Count - 1;
			this->Controls->RemoveAt(size);
		}
	}
}

void ParkingAdministration::MyForm::setStallsArrows()
{
	std::string currId = msclr::interop::marshal_as<std::string>(listViewParkList->SelectedItems[0]->SubItems[0]->Text);
	int id = std::stoi(currId);

	int startPositionOnLeft = this->currentStartScreenPositionX - ((this->Width + STALLS_PRINT_RIGHT_OFFSET + STALLS_PRINT_LEFT_OFFSET) * STALL_COEFFICIENT);
	int startPositionOnRight = this->currentStartScreenPositionX + ((this->Width - STALLS_PRINT_RIGHT_OFFSET - STALLS_PRINT_LEFT_OFFSET) * STALL_COEFFICIENT);
	int startPositionOnUp = this->currentStartScreenPositionY - ((this->Height + STALLS_PRINT_TOP_OFFSET + STALLS_PRINT_BOTTOM_OFFSET) * STALL_COEFFICIENT);
	int startPositionOnDown = this->currentStartScreenPositionY + ((this->Height - STALLS_PRINT_TOP_OFFSET - STALLS_PRINT_BOTTOM_OFFSET) * STALL_COEFFICIENT);

	std::string sqlLeft = CHECK_COUNT_STALLS_FROM_RANGE(currId, std::to_string(-999999), std::to_string(currentStartScreenPositionX), std::to_string(currentStartScreenPositionY), std::to_string(startPositionOnDown));
	std::string sqlRight = CHECK_COUNT_STALLS_FROM_RANGE(currId, std::to_string(startPositionOnRight), std::to_string(999999), std::to_string(currentStartScreenPositionY), std::to_string(startPositionOnDown));
	std::string sqlUp = CHECK_COUNT_STALLS_FROM_RANGE(currId, std::to_string(currentStartScreenPositionX), std::to_string(startPositionOnRight), std::to_string(-999999), std::to_string(currentStartScreenPositionY));
	std::string sqlDown = CHECK_COUNT_STALLS_FROM_RANGE(currId, std::to_string(currentStartScreenPositionX), std::to_string(startPositionOnRight), std::to_string(startPositionOnDown), std::to_string(999999));

	if (mainSystem->loadIntegerFromDatabase(sqlLeft) > 0) {
		this->buttonStallsPrintPageLeft->Enabled = true;
	}
	else {
		this->buttonStallsPrintPageLeft->Enabled = false;
	}

	if (mainSystem->loadIntegerFromDatabase(sqlRight) > 0) {
		this->buttonStallsPrintPageRight->Enabled = true;
	}
	else {
		this->buttonStallsPrintPageRight->Enabled = false;
	}

	if (mainSystem->loadIntegerFromDatabase(sqlUp) > 0) {
		this->buttonStallsPrintPageUp->Enabled = true;
	}
	else {
		this->buttonStallsPrintPageUp->Enabled = false;
	}

	if (mainSystem->loadIntegerFromDatabase(sqlDown) > 0) {
		this->buttonStallsPrintPageDown->Enabled = true;
	}
	else {
		this->buttonStallsPrintPageDown->Enabled = false;
	}
}

void ParkingAdministration::MyForm::readDataFromINI()
{
	INIReader reader("config.ini");

	coordinateStallsTime = reader.GetInteger("STALLS_COORDINATION", "timeToCheck", 5000);
}

void ParkingAdministration::MyForm::hideStallsArrows()
{
	//HIDE PAGE ARROWS
	this->buttonStallsPrintPageLeft->Visible = false;
	this->buttonStallsPrintPageRight->Visible = false;
	this->buttonStallsPrintPageUp->Visible = false;
	this->buttonStallsPrintPageDown->Visible = false;
}

void ParkingAdministration::MyForm::synchronization()
{
	//PARKS SYNCHRONIZATION
	//INSERT
	std::vector<Park*> *parksInsert = mainSystem->synchronizationParksInsert();
	if (parksInsert != nullptr) {
		this->printParks(parksInsert);
	} 
	//UPDATE
	std::vector<Park*> *parksUpdate = mainSystem->synchronizationParksUpdate();
	if (parksUpdate != nullptr) {
		this->printUpdateParks(parksUpdate);
		this->showParkingInformations();
	}
	//DELETE
	bool deleted = mainSystem->synchronizationParksDelete();
	if (deleted != false) {
		std::vector<Park*> *parks;
		if (this->currentScreen == NOT_DELETED_PARKS_SCREEN) {
			parks = mainSystem->loadParksFromDatabase(LOAD_PARKS_NOT_DELETED);
		}
		else if (this->currentScreen == DELETED_PARKS_SCREEN) {
			parks = mainSystem->loadParksFromDatabase(LOAD_PARKS_DELETED);
		}
		this->printParks(parks);
	}
}

void ParkingAdministration::MyForm::synchronizationStalls(int parkId)
{
	std::string minX = std::to_string(this->currentStartScreenPositionX);
	std::string maxX = std::to_string(this->currentStartScreenPositionX + ((this->Width - STALLS_PRINT_RIGHT_OFFSET - STALLS_PRINT_LEFT_OFFSET) * STALL_COEFFICIENT));
	std::string minY = std::to_string(this->currentStartScreenPositionY);
	std::string maxY = std::to_string(this->currentStartScreenPositionY + ((this->Height - STALLS_PRINT_TOP_OFFSET - STALLS_PRINT_BOTTOM_OFFSET) * STALL_COEFFICIENT));

	//UPDATE
	std::vector<Stall*> *stallsUpdate = mainSystem->synchronizationStallsUpdate(parkId, minX, maxX, minY, maxY);
	if (stallsUpdate != nullptr) {
		mainSystem->setSyncStallsUpdate(true);
		this->printStalls(stallsUpdate);
		stallsUpdate = nullptr;
		
		if (this->groupBoxTools->Visible == true) {
			int stallId = std::stoi(msclr::interop::marshal_as<std::string>(this->labelStallId->Text));
			int parkId = mainSystem->getCurrentPark()->getParkoId();
			this->showStallInformations(stallId, parkId);
		}

		this->didUpdateThisApk = false;
		this->setStallsArrows();
	} 

	//INSERT
	std::vector<Stall*> *stallsInsert = mainSystem->synchronizationStallsInsert(parkId, minX, maxX, minY, maxY);
	if (stallsInsert != nullptr) {
		this->printStalls(stallsInsert);
		this->setStallsArrows();
	}
}

