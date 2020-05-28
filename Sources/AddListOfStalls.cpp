#include "AddListOfStalls.h"

void ParkingAdministration::AddListOfStalls::showListOfStallsFromCSV(std::string path)
{
	std::string tmp;
	std::ifstream f(path);
	int index = 0;
	int indexRow = 1;
	while (!f.eof()) {
		getline(f, tmp);
		std::stringstream ss(tmp);
		std::string token;

		int index = 0;
		while (getline(ss, token, ';')) {
			int X;
			int Y;
			int orientation;
			int height;
			int width;
			if (index == 0) {
				X = std::stoi(token);
				index++;
			}
			else if (index == 1) {
				Y = std::stoi(token);
				index++;
			}
			else if (index == 2) {
				orientation = std::stoi(token);
				index++;
			}
			else if (index == 3) {
				height = std::stoi(token);
				index++;
			}
			else if (index == 4) {
				width = std::stoi(token);
				this->dataGridViewAddStallsList->Rows->Add(X, Y, orientation, height, width);
				indexRow++;
			}
		}

	}
	f.close();
}

void ParkingAdministration::AddListOfStalls::setMain(MainSystem * newMain)
{
	this->mainSystem = newMain;
}

void ParkingAdministration::AddListOfStalls::setCurrentCapacity(int capacity)
{
	this->currentCapacity = capacity;
}

void ParkingAdministration::AddListOfStalls::setParkId(int parkId)
{
	this->parkId = parkId;
}

std::vector<Stall*>* ParkingAdministration::AddListOfStalls::readAllStallsFromDataGrid()
{
	std::vector<Stall*> *stalls = new std::vector<Stall*>;
	for (int i = 0; i < this->dataGridViewAddStallsList->RowCount; i++) {
		if (this->dataGridViewAddStallsList->Rows[i]->Cells[0]->Value->ToString()->Length > 0 &&
			this->dataGridViewAddStallsList->Rows[i]->Cells[1]->Value->ToString()->Length > 0) {
			int x = std::stoi(msclr::interop::marshal_as<std::string>(this->dataGridViewAddStallsList->Rows[i]->Cells[0]->Value->ToString()));
			int y = std::stoi(msclr::interop::marshal_as<std::string>(this->dataGridViewAddStallsList->Rows[i]->Cells[1]->Value->ToString()));
			int orientation = std::stoi(msclr::interop::marshal_as<std::string>(this->dataGridViewAddStallsList->Rows[i]->Cells[2]->Value->ToString()));
			int height = std::stoi(msclr::interop::marshal_as<std::string>(this->dataGridViewAddStallsList->Rows[i]->Cells[3]->Value->ToString()));
			int width = std::stoi(msclr::interop::marshal_as<std::string>(this->dataGridViewAddStallsList->Rows[i]->Cells[4]->Value->ToString()));
			Stall *newStall = new Stall(x, y, orientation, height, width);

			stalls->push_back(newStall);
		}
		else {
			return nullptr;
		}
	}

	return stalls;
}

