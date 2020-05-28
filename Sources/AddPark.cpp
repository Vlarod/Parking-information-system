#include "AddPark.h"

bool ParkingAdministration::AddPark::checkTextBoxesFull()
{
	if (this->textBoxAddParkAdress->Text->Length > 0 && this->textBoxAddParkCapacity->Text->Length > 0 && this->textBoxAddParkName->Text->Length > 0 && this->textBoxAddParkX->Text->Length > 0 && this->textBoxAddParkY->Text->Length > 0 && this->textBoxAddParkAdressCity->Text->Length > 0) {
		return true;
	}
	else {
		return false;
	}
}

bool ParkingAdministration::AddPark::getParkAdded()
{
	return this->parkAdded;
}

std::vector<Stall*> * ParkingAdministration::AddPark::readAllStallsFromDataGrid()
{
	std::vector<Stall*> *stalls = new std::vector<Stall*>;
	for (int i = 0; i < int::Parse(this->textBoxAddParkCapacity->Text); i++) {
		if (this->dataGridViewAddStalls->Rows[i]->Cells[0]->Value->ToString()->Length > 0 &&
			this->dataGridViewAddStalls->Rows[i]->Cells[1]->Value->ToString()->Length > 0 &&
			this->dataGridViewAddStalls->Rows[i]->Cells[2]->Value->ToString()->Length > 0 &&
			this->dataGridViewAddStalls->Rows[i]->Cells[3]->Value->ToString()->Length > 0 &&
			this->dataGridViewAddStalls->Rows[i]->Cells[4]->Value->ToString()->Length > 0 &&
			this->dataGridViewAddStalls->Rows[i]->Cells[5]->Value->ToString()->Length > 0) {
			try
			{
				int id = std::stoi(msclr::interop::marshal_as<std::string>(this->dataGridViewAddStalls->Rows[i]->Cells[0]->Value->ToString()));
				int x = std::stoi(msclr::interop::marshal_as<std::string>(this->dataGridViewAddStalls->Rows[i]->Cells[1]->Value->ToString()));
				int y = std::stoi(msclr::interop::marshal_as<std::string>(this->dataGridViewAddStalls->Rows[i]->Cells[2]->Value->ToString()));
				int orientation;
				if (msclr::interop::marshal_as<std::string>(this->dataGridViewAddStalls->Rows[i]->Cells[3]->Value->ToString()) == "Horizontalne") {
					orientation = 1;
				}
				else {
					orientation = 2;
				}

				int lenght = std::stoi(msclr::interop::marshal_as<std::string>(this->dataGridViewAddStalls->Rows[i]->Cells[4]->Value->ToString()));
				int width = std::stoi(msclr::interop::marshal_as<std::string>(this->dataGridViewAddStalls->Rows[i]->Cells[5]->Value->ToString()));
				Stall *newStall = new Stall(id, x, y, orientation, lenght, width);

				stalls->push_back(newStall);
			}
			catch (const std::exception&)
			{
				System::Windows::Forms::MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
			}		
		}
		else {
			return nullptr;
		}
	}

	return stalls;
}

System::String^ ParkingAdministration::AddPark::getNameFromTextBox()
{
	return this->textBoxAddParkName->Text;
}

System::String ^ ParkingAdministration::AddPark::getAdressFromTextBox()
{
	return this->textBoxAddParkAdress->Text + ", " + this->textBoxAddParkAdressCity->Text;
}

System::String ^ ParkingAdministration::AddPark::getCapacityFromTextBox()
{
	return this->textBoxAddParkCapacity->Text;
}

System::String ^ ParkingAdministration::AddPark::getXFromTextBox()
{
	return this->textBoxAddParkX->Text;
}

System::String ^ ParkingAdministration::AddPark::getYFromTextBox()
{
	return this->textBoxAddParkY->Text;
}

std::vector<Stall*>* ParkingAdministration::AddPark::getNewStalls()
{
	return this->newStalls;
}
