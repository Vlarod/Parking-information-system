#pragma once
#include <vector>
#include <msclr\marshal_cppstd.h>
#include "Stall.h"
namespace ParkingAdministration {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddPark
	/// </summary>
	public ref class AddPark : public System::Windows::Forms::Form
	{
	public:
		AddPark(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		bool checkTextBoxesFull();
		bool getParkAdded();
		std::vector<Stall*> *readAllStallsFromDataGrid();
		System::String^ getNameFromTextBox();
		System::String^ getAdressFromTextBox();
		System::String^ getCapacityFromTextBox();
		System::String^ getXFromTextBox();
		System::String^ getYFromTextBox();

		std::vector<Stall*> *getNewStalls();
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddPark()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelTitleAddPark;
	protected:
	private: System::Windows::Forms::GroupBox^  groupBoxAddParkdata;
	private: System::Windows::Forms::Button^  buttonAddParkConfirmData;
	private: System::Windows::Forms::TextBox^  textBoxAddParkCapacity;
	private: System::Windows::Forms::Label^  labelAddParkTitleCapacity;
	private: System::Windows::Forms::TextBox^  textBoxAddParkAdress;
	private: System::Windows::Forms::Label^  labelAddParkTitleAdress;
	private: System::Windows::Forms::TextBox^  textBoxAddParkName;
	private: System::Windows::Forms::Label^  labelAddParkTitleName;

	protected:

	private:

		bool parkAdded;
		std::vector<Stall*> *newStalls;



	private: System::Windows::Forms::Button^  buttonAddParkNewStallsConfirm;
	private: System::Windows::Forms::DataGridView^  dataGridViewAddStalls;



	private: System::Windows::Forms::TextBox^  textBoxAddParkY;
	private: System::Windows::Forms::Label^  labelAddParkTitleY;
	private: System::Windows::Forms::TextBox^  textBoxAddParkX;
	private: System::Windows::Forms::Label^  labelAddParkTitleX;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnX;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnY;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  ColumnOrientation;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnLenght;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnWidth;
	private: System::Windows::Forms::TextBox^  textBoxAddParkAdressCity;
	private: System::Windows::Forms::Label^  labelAddParkTitleAdressCity;









		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->labelTitleAddPark = (gcnew System::Windows::Forms::Label());
			this->groupBoxAddParkdata = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxAddParkY = (gcnew System::Windows::Forms::TextBox());
			this->labelAddParkTitleY = (gcnew System::Windows::Forms::Label());
			this->textBoxAddParkX = (gcnew System::Windows::Forms::TextBox());
			this->labelAddParkTitleX = (gcnew System::Windows::Forms::Label());
			this->buttonAddParkConfirmData = (gcnew System::Windows::Forms::Button());
			this->textBoxAddParkCapacity = (gcnew System::Windows::Forms::TextBox());
			this->labelAddParkTitleCapacity = (gcnew System::Windows::Forms::Label());
			this->textBoxAddParkAdress = (gcnew System::Windows::Forms::TextBox());
			this->labelAddParkTitleAdress = (gcnew System::Windows::Forms::Label());
			this->textBoxAddParkName = (gcnew System::Windows::Forms::TextBox());
			this->labelAddParkTitleName = (gcnew System::Windows::Forms::Label());
			this->buttonAddParkNewStallsConfirm = (gcnew System::Windows::Forms::Button());
			this->dataGridViewAddStalls = (gcnew System::Windows::Forms::DataGridView());
			this->ColumnId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnX = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnY = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnOrientation = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->ColumnLenght = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnWidth = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBoxAddParkAdressCity = (gcnew System::Windows::Forms::TextBox());
			this->labelAddParkTitleAdressCity = (gcnew System::Windows::Forms::Label());
			this->groupBoxAddParkdata->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAddStalls))->BeginInit();
			this->SuspendLayout();
			// 
			// labelTitleAddPark
			// 
			this->labelTitleAddPark->AutoSize = true;
			this->labelTitleAddPark->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitleAddPark->Location = System::Drawing::Point(384, 9);
			this->labelTitleAddPark->Name = L"labelTitleAddPark";
			this->labelTitleAddPark->Size = System::Drawing::Size(290, 33);
			this->labelTitleAddPark->TabIndex = 0;
			this->labelTitleAddPark->Text = L"Pridanie parkoviska";
			// 
			// groupBoxAddParkdata
			// 
			this->groupBoxAddParkdata->Controls->Add(this->textBoxAddParkAdressCity);
			this->groupBoxAddParkdata->Controls->Add(this->labelAddParkTitleAdressCity);
			this->groupBoxAddParkdata->Controls->Add(this->textBoxAddParkY);
			this->groupBoxAddParkdata->Controls->Add(this->labelAddParkTitleY);
			this->groupBoxAddParkdata->Controls->Add(this->textBoxAddParkX);
			this->groupBoxAddParkdata->Controls->Add(this->labelAddParkTitleX);
			this->groupBoxAddParkdata->Controls->Add(this->buttonAddParkConfirmData);
			this->groupBoxAddParkdata->Controls->Add(this->textBoxAddParkCapacity);
			this->groupBoxAddParkdata->Controls->Add(this->labelAddParkTitleCapacity);
			this->groupBoxAddParkdata->Controls->Add(this->textBoxAddParkAdress);
			this->groupBoxAddParkdata->Controls->Add(this->labelAddParkTitleAdress);
			this->groupBoxAddParkdata->Controls->Add(this->textBoxAddParkName);
			this->groupBoxAddParkdata->Controls->Add(this->labelAddParkTitleName);
			this->groupBoxAddParkdata->Location = System::Drawing::Point(28, 62);
			this->groupBoxAddParkdata->Name = L"groupBoxAddParkdata";
			this->groupBoxAddParkdata->Size = System::Drawing::Size(402, 285);
			this->groupBoxAddParkdata->TabIndex = 1;
			this->groupBoxAddParkdata->TabStop = false;
			// 
			// textBoxAddParkY
			// 
			this->textBoxAddParkY->Location = System::Drawing::Point(162, 180);
			this->textBoxAddParkY->Name = L"textBoxAddParkY";
			this->textBoxAddParkY->Size = System::Drawing::Size(234, 20);
			this->textBoxAddParkY->TabIndex = 10;
			this->textBoxAddParkY->TextChanged += gcnew System::EventHandler(this, &AddPark::textBoxAddParkY_TextChanged);
			// 
			// labelAddParkTitleY
			// 
			this->labelAddParkTitleY->AutoSize = true;
			this->labelAddParkTitleY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelAddParkTitleY->Location = System::Drawing::Point(6, 180);
			this->labelAddParkTitleY->Name = L"labelAddParkTitleY";
			this->labelAddParkTitleY->Size = System::Drawing::Size(144, 20);
			this->labelAddParkTitleY->TabIndex = 9;
			this->labelAddParkTitleY->Text = L"Zemepisná dĺžka";
			// 
			// textBoxAddParkX
			// 
			this->textBoxAddParkX->Location = System::Drawing::Point(162, 147);
			this->textBoxAddParkX->Name = L"textBoxAddParkX";
			this->textBoxAddParkX->Size = System::Drawing::Size(234, 20);
			this->textBoxAddParkX->TabIndex = 8;
			this->textBoxAddParkX->TextChanged += gcnew System::EventHandler(this, &AddPark::textBoxAddParkX_TextChanged);
			// 
			// labelAddParkTitleX
			// 
			this->labelAddParkTitleX->AutoSize = true;
			this->labelAddParkTitleX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelAddParkTitleX->Location = System::Drawing::Point(7, 147);
			this->labelAddParkTitleX->Name = L"labelAddParkTitleX";
			this->labelAddParkTitleX->Size = System::Drawing::Size(145, 20);
			this->labelAddParkTitleX->TabIndex = 7;
			this->labelAddParkTitleX->Text = L"Zemepisná šírka:";
			// 
			// buttonAddParkConfirmData
			// 
			this->buttonAddParkConfirmData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonAddParkConfirmData->Location = System::Drawing::Point(11, 229);
			this->buttonAddParkConfirmData->Name = L"buttonAddParkConfirmData";
			this->buttonAddParkConfirmData->Size = System::Drawing::Size(368, 23);
			this->buttonAddParkConfirmData->TabIndex = 6;
			this->buttonAddParkConfirmData->Text = L"Potvrdiť";
			this->buttonAddParkConfirmData->UseVisualStyleBackColor = true;
			this->buttonAddParkConfirmData->Click += gcnew System::EventHandler(this, &AddPark::buttonAddParkConfirmData_Click);
			// 
			// textBoxAddParkCapacity
			// 
			this->textBoxAddParkCapacity->Location = System::Drawing::Point(99, 116);
			this->textBoxAddParkCapacity->Name = L"textBoxAddParkCapacity";
			this->textBoxAddParkCapacity->Size = System::Drawing::Size(297, 20);
			this->textBoxAddParkCapacity->TabIndex = 5;
			this->textBoxAddParkCapacity->TextChanged += gcnew System::EventHandler(this, &AddPark::textBoxAddParkCapacity_TextChanged);
			// 
			// labelAddParkTitleCapacity
			// 
			this->labelAddParkTitleCapacity->AutoSize = true;
			this->labelAddParkTitleCapacity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelAddParkTitleCapacity->Location = System::Drawing::Point(7, 116);
			this->labelAddParkTitleCapacity->Name = L"labelAddParkTitleCapacity";
			this->labelAddParkTitleCapacity->Size = System::Drawing::Size(84, 20);
			this->labelAddParkTitleCapacity->TabIndex = 4;
			this->labelAddParkTitleCapacity->Text = L"Kapacita:";
			// 
			// textBoxAddParkAdress
			// 
			this->textBoxAddParkAdress->Location = System::Drawing::Point(99, 51);
			this->textBoxAddParkAdress->Name = L"textBoxAddParkAdress";
			this->textBoxAddParkAdress->Size = System::Drawing::Size(297, 20);
			this->textBoxAddParkAdress->TabIndex = 3;
			this->textBoxAddParkAdress->TextChanged += gcnew System::EventHandler(this, &AddPark::textBoxAddParkAdress_TextChanged);
			// 
			// labelAddParkTitleAdress
			// 
			this->labelAddParkTitleAdress->AutoSize = true;
			this->labelAddParkTitleAdress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelAddParkTitleAdress->Location = System::Drawing::Point(7, 51);
			this->labelAddParkTitleAdress->Name = L"labelAddParkTitleAdress";
			this->labelAddParkTitleAdress->Size = System::Drawing::Size(71, 20);
			this->labelAddParkTitleAdress->TabIndex = 2;
			this->labelAddParkTitleAdress->Text = L"Adresa:";
			// 
			// textBoxAddParkName
			// 
			this->textBoxAddParkName->Location = System::Drawing::Point(99, 20);
			this->textBoxAddParkName->Name = L"textBoxAddParkName";
			this->textBoxAddParkName->Size = System::Drawing::Size(297, 20);
			this->textBoxAddParkName->TabIndex = 1;
			this->textBoxAddParkName->TextChanged += gcnew System::EventHandler(this, &AddPark::textBoxAddParkName_TextChanged);
			// 
			// labelAddParkTitleName
			// 
			this->labelAddParkTitleName->AutoSize = true;
			this->labelAddParkTitleName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelAddParkTitleName->Location = System::Drawing::Point(7, 20);
			this->labelAddParkTitleName->Name = L"labelAddParkTitleName";
			this->labelAddParkTitleName->Size = System::Drawing::Size(63, 20);
			this->labelAddParkTitleName->TabIndex = 0;
			this->labelAddParkTitleName->Text = L"Názov:";
			// 
			// buttonAddParkNewStallsConfirm
			// 
			this->buttonAddParkNewStallsConfirm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonAddParkNewStallsConfirm->Location = System::Drawing::Point(447, 320);
			this->buttonAddParkNewStallsConfirm->Name = L"buttonAddParkNewStallsConfirm";
			this->buttonAddParkNewStallsConfirm->Size = System::Drawing::Size(574, 27);
			this->buttonAddParkNewStallsConfirm->TabIndex = 3;
			this->buttonAddParkNewStallsConfirm->Text = L"Pridať";
			this->buttonAddParkNewStallsConfirm->UseVisualStyleBackColor = true;
			this->buttonAddParkNewStallsConfirm->Click += gcnew System::EventHandler(this, &AddPark::buttonAddParkNewStallsConfirm_Click);
			// 
			// dataGridViewAddStalls
			// 
			this->dataGridViewAddStalls->AllowUserToAddRows = false;
			this->dataGridViewAddStalls->AllowUserToDeleteRows = false;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::ButtonFace;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewAddStalls->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridViewAddStalls->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewAddStalls->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->ColumnId,
					this->ColumnX, this->ColumnY, this->ColumnOrientation, this->ColumnLenght, this->ColumnWidth
			});
			this->dataGridViewAddStalls->Location = System::Drawing::Point(447, 62);
			this->dataGridViewAddStalls->Name = L"dataGridViewAddStalls";
			this->dataGridViewAddStalls->Size = System::Drawing::Size(574, 252);
			this->dataGridViewAddStalls->TabIndex = 4;
			// 
			// ColumnId
			// 
			this->ColumnId->FillWeight = 90;
			this->ColumnId->HeaderText = L"Id miesta";
			this->ColumnId->Name = L"ColumnId";
			this->ColumnId->ReadOnly = true;
			// 
			// ColumnX
			// 
			this->ColumnX->FillWeight = 90;
			this->ColumnX->HeaderText = L"Súradnica X";
			this->ColumnX->Name = L"ColumnX";
			// 
			// ColumnY
			// 
			this->ColumnY->FillWeight = 90;
			this->ColumnY->HeaderText = L"Súradnica Y";
			this->ColumnY->Name = L"ColumnY";
			// 
			// ColumnOrientation
			// 
			this->ColumnOrientation->FillWeight = 90;
			this->ColumnOrientation->HeaderText = L"Orientácia";
			this->ColumnOrientation->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Horizontalne", L"Vertikalne" });
			this->ColumnOrientation->Name = L"ColumnOrientation";
			this->ColumnOrientation->Width = 90;
			// 
			// ColumnLenght
			// 
			this->ColumnLenght->FillWeight = 90;
			this->ColumnLenght->HeaderText = L"Dĺžka";
			this->ColumnLenght->Name = L"ColumnLenght";
			this->ColumnLenght->Width = 70;
			// 
			// ColumnWidth
			// 
			this->ColumnWidth->FillWeight = 90;
			this->ColumnWidth->HeaderText = L"Šírka";
			this->ColumnWidth->Name = L"ColumnWidth";
			this->ColumnWidth->Width = 70;
			// 
			// textBoxAddParkAdressCity
			// 
			this->textBoxAddParkAdressCity->Location = System::Drawing::Point(99, 84);
			this->textBoxAddParkAdressCity->Name = L"textBoxAddParkAdressCity";
			this->textBoxAddParkAdressCity->Size = System::Drawing::Size(297, 20);
			this->textBoxAddParkAdressCity->TabIndex = 12;
			this->textBoxAddParkAdressCity->TextChanged += gcnew System::EventHandler(this, &AddPark::textBoxAddParkAdressCity_TextChanged);
			// 
			// labelAddParkTitleAdressCity
			// 
			this->labelAddParkTitleAdressCity->AutoSize = true;
			this->labelAddParkTitleAdressCity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelAddParkTitleAdressCity->Location = System::Drawing::Point(7, 84);
			this->labelAddParkTitleAdressCity->Name = L"labelAddParkTitleAdressCity";
			this->labelAddParkTitleAdressCity->Size = System::Drawing::Size(63, 20);
			this->labelAddParkTitleAdressCity->TabIndex = 11;
			this->labelAddParkTitleAdressCity->Text = L"Mesto:";
			// 
			// AddPark
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1030, 370);
			this->Controls->Add(this->dataGridViewAddStalls);
			this->Controls->Add(this->buttonAddParkNewStallsConfirm);
			this->Controls->Add(this->groupBoxAddParkdata);
			this->Controls->Add(this->labelTitleAddPark);
			this->Name = L"AddPark";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AddPark";
			this->Load += gcnew System::EventHandler(this, &AddPark::AddPark_Load);
			this->groupBoxAddParkdata->ResumeLayout(false);
			this->groupBoxAddParkdata->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAddStalls))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AddPark_Load(System::Object^  sender, System::EventArgs^  e) {

		this->buttonAddParkConfirmData->Enabled = false;
		this->parkAdded = false;
	}

	private: System::Void textBoxAddParkName_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->checkTextBoxesFull() == true) {
			this->buttonAddParkConfirmData->Enabled = true;
		}
		else {
			this->buttonAddParkConfirmData->Enabled = false;
		}
	}
	private: System::Void textBoxAddParkAdress_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->checkTextBoxesFull() == true) {
			this->buttonAddParkConfirmData->Enabled = true;
		}
		else {
			this->buttonAddParkConfirmData->Enabled = false;
		}
	}
	private: System::Void textBoxAddParkCapacity_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->checkTextBoxesFull() == true) {
			this->buttonAddParkConfirmData->Enabled = true;
		}
		else {
			this->buttonAddParkConfirmData->Enabled = false;
		}
	}
	private: System::Void buttonAddParkConfirmData_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			std::stoi(msclr::interop::marshal_as<std::string>(this->getCapacityFromTextBox()));
			std::stod(msclr::interop::marshal_as<std::string>(this->getXFromTextBox()));
			std::stod(msclr::interop::marshal_as<std::string>(this->getYFromTextBox()));

			this->buttonAddParkConfirmData->Enabled = false;
			for (int i = 0; i < int::Parse(this->textBoxAddParkCapacity->Text); i++) {
				this->dataGridViewAddStalls->Rows->Add(i + 1, "", "");
			}
		}
		catch (const std::exception&)
		{
			MessageBox::Show("Súradnice a kapacita musia byť číslo!");
		}
	}
	private: System::Void textBoxAddParkX_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->checkTextBoxesFull() == true) {
			this->buttonAddParkConfirmData->Enabled = true;
		}
		else {
			this->buttonAddParkConfirmData->Enabled = false;
		}
	}
	private: System::Void textBoxAddParkY_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->checkTextBoxesFull() == true) {
			this->buttonAddParkConfirmData->Enabled = true;
		}
		else {
			this->buttonAddParkConfirmData->Enabled = false;
		}
	}
	private: System::Void buttonAddParkNewStallsConfirm_Click(System::Object^  sender, System::EventArgs^  e) {
			newStalls = this->readAllStallsFromDataGrid();
			if (newStalls != nullptr) {
				this->parkAdded = true;
				this->Close();
			}
	}
private: System::Void textBoxAddParkAdressCity_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->checkTextBoxesFull() == true) {
		this->buttonAddParkConfirmData->Enabled = true;
	}
	else {
		this->buttonAddParkConfirmData->Enabled = false;
	}
}
};
}
