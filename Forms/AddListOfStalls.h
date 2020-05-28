#pragma once
#include <msclr\marshal_cppstd.h>
#include "MainSystem.h"

#include <fstream>
#include <iostream>
#include <sstream> 
namespace ParkingAdministration {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddListOfStalls
	/// </summary>
	public ref class AddListOfStalls : public System::Windows::Forms::Form
	{
	public:
		AddListOfStalls(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void showListOfStallsFromCSV(std::string path);
		void setMain(MainSystem * newMain);
		void setCurrentCapacity(int capacity);
		void setParkId(int parkId);

		std::vector<Stall*> *readAllStallsFromDataGrid();
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddListOfStalls()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonChooseCSVFile;
	private: System::Windows::Forms::TextBox^  textBoxAddListOfStallsPath;
	protected:

	private: System::Windows::Forms::Label^  labelTitlePath;
	private: System::Windows::Forms::DataGridView^  dataGridViewAddStallsList;




	private: System::Windows::Forms::Button^  buttonAddListOfStalls;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;



			 MainSystem * mainSystem;
			 int currentCapacity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnX;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnY;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Orientation;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Height;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Width;










			 int parkId;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->buttonChooseCSVFile = (gcnew System::Windows::Forms::Button());
			this->textBoxAddListOfStallsPath = (gcnew System::Windows::Forms::TextBox());
			this->labelTitlePath = (gcnew System::Windows::Forms::Label());
			this->dataGridViewAddStallsList = (gcnew System::Windows::Forms::DataGridView());
			this->buttonAddListOfStalls = (gcnew System::Windows::Forms::Button());
			this->ColumnX = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnY = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Orientation = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Height = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Width = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAddStallsList))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonChooseCSVFile
			// 
			this->buttonChooseCSVFile->Location = System::Drawing::Point(410, 13);
			this->buttonChooseCSVFile->Name = L"buttonChooseCSVFile";
			this->buttonChooseCSVFile->Size = System::Drawing::Size(110, 23);
			this->buttonChooseCSVFile->TabIndex = 0;
			this->buttonChooseCSVFile->Text = L"Vyberte súbor";
			this->buttonChooseCSVFile->UseVisualStyleBackColor = true;
			this->buttonChooseCSVFile->Click += gcnew System::EventHandler(this, &AddListOfStalls::buttonChooseCSVFile_Click);
			// 
			// textBoxAddListOfStallsPath
			// 
			this->textBoxAddListOfStallsPath->Location = System::Drawing::Point(63, 43);
			this->textBoxAddListOfStallsPath->Name = L"textBoxAddListOfStallsPath";
			this->textBoxAddListOfStallsPath->ReadOnly = true;
			this->textBoxAddListOfStallsPath->Size = System::Drawing::Size(457, 20);
			this->textBoxAddListOfStallsPath->TabIndex = 1;
			// 
			// labelTitlePath
			// 
			this->labelTitlePath->AutoSize = true;
			this->labelTitlePath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelTitlePath->Location = System::Drawing::Point(10, 44);
			this->labelTitlePath->Name = L"labelTitlePath";
			this->labelTitlePath->Size = System::Drawing::Size(52, 16);
			this->labelTitlePath->TabIndex = 2;
			this->labelTitlePath->Text = L"Cesta:";
			// 
			// dataGridViewAddStallsList
			// 
			this->dataGridViewAddStallsList->AllowUserToAddRows = false;
			this->dataGridViewAddStallsList->AllowUserToDeleteRows = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::ButtonFace;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewAddStallsList->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridViewAddStallsList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewAddStallsList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->ColumnX,
					this->ColumnY, this->Orientation, this->Height, this->Width
			});
			this->dataGridViewAddStallsList->Location = System::Drawing::Point(37, 69);
			this->dataGridViewAddStallsList->Name = L"dataGridViewAddStallsList";
			this->dataGridViewAddStallsList->Size = System::Drawing::Size(483, 229);
			this->dataGridViewAddStallsList->TabIndex = 5;
			// 
			// buttonAddListOfStalls
			// 
			this->buttonAddListOfStalls->Location = System::Drawing::Point(105, 304);
			this->buttonAddListOfStalls->Name = L"buttonAddListOfStalls";
			this->buttonAddListOfStalls->Size = System::Drawing::Size(344, 23);
			this->buttonAddListOfStalls->TabIndex = 6;
			this->buttonAddListOfStalls->Text = L"Pridat";
			this->buttonAddListOfStalls->UseVisualStyleBackColor = true;
			this->buttonAddListOfStalls->Click += gcnew System::EventHandler(this, &AddListOfStalls::buttonAddListOfStalls_Click);
			// 
			// ColumnX
			// 
			this->ColumnX->FillWeight = 70;
			this->ColumnX->HeaderText = L"Súradnica X";
			this->ColumnX->Name = L"ColumnX";
			// 
			// ColumnY
			// 
			this->ColumnY->HeaderText = L"Súradnica Y";
			this->ColumnY->Name = L"ColumnY";
			// 
			// Orientation
			// 
			this->Orientation->HeaderText = L"Orientácia";
			this->Orientation->Name = L"Orientation";
			this->Orientation->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Orientation->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Height
			// 
			this->Height->HeaderText = L"Dåžka";
			this->Height->Name = L"Height";
			this->Height->Width = 70;
			// 
			// Width
			// 
			this->Width->HeaderText = L"Šírka";
			this->Width->Name = L"Width";
			this->Width->Width = 70;
			// 
			// AddListOfStalls
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(554, 342);
			this->Controls->Add(this->buttonAddListOfStalls);
			this->Controls->Add(this->dataGridViewAddStallsList);
			this->Controls->Add(this->labelTitlePath);
			this->Controls->Add(this->textBoxAddListOfStallsPath);
			this->Controls->Add(this->buttonChooseCSVFile);
			this->Name = L"AddListOfStalls";
			this->Text = L"Pridanie listu parkovacích miest";
			this->Load += gcnew System::EventHandler(this, &AddListOfStalls::AddListOfStalls_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAddStallsList))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AddListOfStalls_Load(System::Object^  sender, System::EventArgs^  e) {
		this->buttonAddListOfStalls->Enabled = false;
	}

	private: System::Void buttonChooseCSVFile_Click(System::Object^  sender, System::EventArgs^  e) {
		System::String ^ folderName;
		OpenFileDialog^ folderBrowserDialog1;
		//FolderBrowserDialog^ folderBrowserDialog1;
		//folderBrowserDialog1 = gcnew System::Windows::Forms::FolderBrowserDialog;
		folderBrowserDialog1 = gcnew System::Windows::Forms::OpenFileDialog;

		System::Windows::Forms::DialogResult result = folderBrowserDialog1->ShowDialog();
		if (result == System::Windows::Forms::DialogResult::OK)
		{
			folderName = folderBrowserDialog1->FileName;
			if (folderName->Substring(folderName->Length - 3, 3) == "csv") {
				textBoxAddListOfStallsPath->Text = folderName;
				std::string filePath = msclr::interop::marshal_as<std::string>(folderName);

				this->showListOfStallsFromCSV(filePath);
				if (dataGridViewAddStallsList->RowCount > 0) {
					this->buttonAddListOfStalls->Enabled = true;
				}
			}
			else {
				MessageBox::Show("Vyberte CSV súbor!.");
			}
		}
	}
private: System::Void buttonAddListOfStalls_Click(System::Object^  sender, System::EventArgs^  e) {
	std::vector<Stall*> *newStalls = this->readAllStallsFromDataGrid();
	int capacity = this->currentCapacity;
	System::String ^ numberOfSuccesAddedStalls = gcnew String((std::to_string(mainSystem->addStallsToPark(std::to_string(parkId), newStalls, capacity)).c_str()));
	MessageBox::Show("Pocet úspesne pridaných parkovacích miest: " + numberOfSuccesAddedStalls + ".");
	this->Close();
}
};
}
