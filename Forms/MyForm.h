#pragma once
#include <msclr\marshal_cppstd.h>

#include <string>
#include <iostream>
#include <random>
#include <vector>

#include <occi.h>

#include "DEFINES.h"
#include "MainSystem.h"
#include "AddPark.h"
#include "AddListOfStalls.h"
#include "INIReader.h"

namespace ParkingAdministration {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void printParks(std::vector<Park*> *parks);
		void printDeletedStallsToList(std::vector<Stall*> *stalls);
		void printUpdateParks(std::vector<Park*> *parks);
		void printStalls(std::vector<Stall*> *stalls);
		void printStallsFromRange(int shiftDirection);
		void showStallInformations(int stallId, int parkId);
		void showParkingInformations();
		void searchingParks();
		void searchingStalls();
		void deleteStallsFromScreen();
		void setStallsArrows();
		void readDataFromINI();

		void hideStallsArrows();
		//SYNCHRONIZATION METHODS
		void synchronization();
		void synchronizationStalls(int parkId);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;	
			}

			if (destructored == false) {
				delete mainSystem;
				destructored = true;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  showToolStripMenuItem;
	protected:

	private: System::Windows::Forms::GroupBox^  groupBoxTools;
	private: System::Windows::Forms::Label^  labelStallId;

	private: System::Windows::Forms::Label^  labelTitleButtonId;

	private: System::Windows::Forms::GroupBox^  groupBoxParkList;
	private: System::Windows::Forms::ListView^  listViewParkList;
	private: System::Windows::Forms::ColumnHeader^  columnHeaderName;

	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		MainSystem *mainSystem;
		bool showedStalls = false;
		bool destructored = false;
		bool didUpdateThisApk = false;
		int currentScreen;
		int currentShowStalls;
		int currentStartScreenPositionX;
		int currentStartScreenPositionY;
		int timerCountValue = 0;
		int coordinateStallsTime = 5000;

	private: System::Windows::Forms::Label^  labelParkId;

	private: System::Windows::Forms::Label^  labelTitleParkId;
	private: System::Windows::Forms::Label^  labelStallY;
	private: System::Windows::Forms::Label^  labelTitleStallY;
	private: System::Windows::Forms::Label^  labelStallX;
	private: System::Windows::Forms::Label^  labelTitleStallX;
	private: System::Windows::Forms::Label^  labelStallType;

	private: System::Windows::Forms::Label^  labelTitleStallType;
	private: System::Windows::Forms::Label^  labelStallStatus;
	private: System::Windows::Forms::Label^  labelTitleStallStatus;

	private: System::Windows::Forms::Timer^  timerSync;
	private: System::Windows::Forms::GroupBox^  groupBoxInformationsAboutParking;
	private: System::Windows::Forms::Label^  labelTitleInformationsAboutParking;
	private: System::Windows::Forms::Label^  labelParkInformationsCapacity;
	private: System::Windows::Forms::Label^  labelTitleParkInformationsCapacity;
	private: System::Windows::Forms::Label^  labelParkInformationsAdress;
	private: System::Windows::Forms::Label^  labelTitleParkInformationsAdress;
	private: System::Windows::Forms::Label^  labelParkInformationsId;
	private: System::Windows::Forms::Label^  labelTitleParkInformationsId;
	private: System::Windows::Forms::Label^  labelParkInformationsName;
	private: System::Windows::Forms::Label^  labelTitleParkInformationsName;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonAddPark;
	private: System::Windows::Forms::ToolStrip^  toolStripParkChanges;

	private: System::Windows::Forms::ToolStripButton^  toolStripButtonChangeParkName;
	private: System::Windows::Forms::GroupBox^  groupBoxParkChanges;
	private: System::Windows::Forms::GroupBox^  groupBoxNewParkName;
	private: System::Windows::Forms::Label^  labelTitleNewParkName;
	private: System::Windows::Forms::Button^  buttonConfirmParkNameChange;
	private: System::Windows::Forms::TextBox^  textBoxNewParkName;
	private: System::Windows::Forms::GroupBox^  groupBoxNewParkAdress;
	private: System::Windows::Forms::Label^  labelTitleNewParkAdress;
	private: System::Windows::Forms::Button^  buttonConfirmParkAdressChange;
	private: System::Windows::Forms::TextBox^  textBoxNewParkAdress;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonChangeAdress;
private: System::Windows::Forms::ColumnHeader^  columnHeaderId;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemParksList;
private: System::Windows::Forms::ToolStripMenuItem^  zoznamZmazanýchParkovískToolStripMenuItem;
private: System::Windows::Forms::ToolStripButton^  toolStripButtonDeletePark;
private: System::Windows::Forms::Button^  buttonParkRecover;
private: System::Windows::Forms::Timer^  timerStallsSync;

private: System::Windows::Forms::CheckBox^  checkBoxStallOutOfService;

private: System::Windows::Forms::CheckBox^  checkBoxStallReserve;
private: System::Windows::Forms::CheckBox^  checkBoxStallFree;
private: System::Windows::Forms::GroupBox^  groupBoxChangeStallType;
private: System::Windows::Forms::Button^  buttonChangeTypeConfirm;
private: System::Windows::Forms::ToolStrip^  toolStripStallsConfig;
private: System::Windows::Forms::ToolStripButton^  toolStripButtonAddStall;
private: System::Windows::Forms::GroupBox^  groupBoxAddStall;
private: System::Windows::Forms::Button^  buttonAddStallConfirm;
private: System::Windows::Forms::TextBox^  textBoxAddStallY;
private: System::Windows::Forms::Label^  labelTitleAddStallY;
private: System::Windows::Forms::TextBox^  textBoxAddStallX;
private: System::Windows::Forms::Label^  labelTitleAddStallX;
private: System::Windows::Forms::ToolStrip^  toolStripStallSetting;
private: System::Windows::Forms::ToolStripButton^  toolStripButtonDeleteStall;
private: System::Windows::Forms::ToolStripButton^  toolStripButtonChangeStallType;
private: System::Windows::Forms::ToolStripMenuItem^  zoznamZmazanýchParkovacíchMiestToolStripMenuItem;









private: System::Windows::Forms::GroupBox^  groupBoxSearchInParks;
private: System::Windows::Forms::TextBox^  textBoxSearchParkFindingWord;
private: System::Windows::Forms::CheckBox^  checkBoxParkSearchId;
private: System::Windows::Forms::CheckBox^  checkBoxParkSearchName;








private: System::Windows::Forms::ColumnHeader^  columnHeaderStatus;
private: System::Windows::Forms::Label^  labelParkInformationsStatus;
private: System::Windows::Forms::Label^  labelTitleParkInformationsStatus;
private: System::Windows::Forms::ToolStripButton^  toolStripButtonLoadStalls;
private: System::Windows::Forms::ListView^  listViewDeletedStalls;
private: System::Windows::Forms::ColumnHeader^  stallId;
private: System::Windows::Forms::ColumnHeader^  parkId;
private: System::Windows::Forms::ColumnHeader^  stallState;
private: System::Windows::Forms::ColumnHeader^  stallType;
private: System::Windows::Forms::ColumnHeader^  x;
private: System::Windows::Forms::ColumnHeader^  y;
private: System::Windows::Forms::ToolStrip^  toolStripDeletedStalls;
private: System::Windows::Forms::GroupBox^  groupBoxSearchingDeletedStalls;
private: System::Windows::Forms::TextBox^  textBoxSearchingWordDeletedStalls;
private: System::Windows::Forms::CheckBox^  checkBoxSearchInDeletedStallsStallY;
private: System::Windows::Forms::CheckBox^  checkBoxSearchInDeletedStallsStallX;
private: System::Windows::Forms::CheckBox^  checkBoxSearchInDeletedStallsParkId;
private: System::Windows::Forms::CheckBox^  checkBoxSearchInDeletedStallsStallId;
private: System::Windows::Forms::GroupBox^  groupBoxDeletedStalls;
private: System::Windows::Forms::Button^  buttonStallsPrintPageLeft;
private: System::Windows::Forms::Button^  buttonStallsPrintPageRight;
private: System::Windows::Forms::Button^  buttonStallsPrintPageDown;
private: System::Windows::Forms::Button^  buttonStallsPrintPageUp;
private: System::Windows::Forms::Label^  labelTitleShowingStallTime;
private: System::Windows::Forms::Label^  labelShowingStallTime;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
private: System::Windows::Forms::ToolStripButton^  toolStripButtonShowStallsInTime;
private: System::Windows::Forms::DateTimePicker^  dateTimePickerShowStallsTime;
private: System::Windows::Forms::Button^  buttonConfirmStallsShowingTime;
private: System::Windows::Forms::ToolStripButton^  toolStripButtonShowStallsCurrentTime;
private: System::Windows::Forms::GroupBox^  groupBoxReservationInformations;
private: System::Windows::Forms::Label^  labelSPZ;

private: System::Windows::Forms::Label^  labelTitleSPZ;
private: System::Windows::Forms::Label^  labelStart;

private: System::Windows::Forms::Label^  labelTitleStart;
private: System::Windows::Forms::Label^  labelEnd;

private: System::Windows::Forms::Label^  labelTitleEnd;
private: System::Windows::Forms::Label^  labelAddStallTitleOrientation;
private: System::Windows::Forms::CheckBox^  checkBoxAddStallVertical;
private: System::Windows::Forms::CheckBox^  checkBoxAddStallHorizontal;
private: System::Windows::Forms::TextBox^  textBoxAddStallWidth;
private: System::Windows::Forms::Label^  labelAddStallTitleWidth;
private: System::Windows::Forms::TextBox^  textBoxAddStallHeight;
private: System::Windows::Forms::Label^  labelAddStallTitleHeight;
private: System::Windows::Forms::ToolStripButton^  toolStripButtonParkStatusChange;
private: System::Windows::Forms::GroupBox^  groupBoxChangeParkStatus;
private: System::Windows::Forms::CheckBox^  checkBoxParkStatusOff;
private: System::Windows::Forms::CheckBox^  checkBoxParkStatusOn;
private: System::Windows::Forms::Label^  labelTitleChangeParkStatus;
private: System::Windows::Forms::Button^  buttonConfirmChangeParkStatus;
private: System::Windows::Forms::ComboBox^  comboBoxParkSearchStatus;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
private: System::Windows::Forms::Label^  labelParkInformationsLongtitude;
private: System::Windows::Forms::Label^  labelTitleParkInformationsLongtitude;
private: System::Windows::Forms::Label^  labelParkInformationsLatitude;
private: System::Windows::Forms::Label^  labelTitleParkInformationsLatitude;
private: System::Windows::Forms::GroupBox^  groupBoxNewParkLatitude;

private: System::Windows::Forms::Label^  labelTitleNewParkLatitude;
private: System::Windows::Forms::Button^  buttonConfirmParkLatitudeChange;
private: System::Windows::Forms::TextBox^  textBoxNewParkLatitude;
private: System::Windows::Forms::ToolStripButton^  toolStripButtonChangeLatitude;
private: System::Windows::Forms::GroupBox^  groupBoxNewParkLongtitude;

private: System::Windows::Forms::Label^  labelTitleNewParkLongtitude;
private: System::Windows::Forms::Button^  buttonConfirmParkLatitudeChangeLongtitude;
private: System::Windows::Forms::TextBox^  textBoxNewParkLongtitude;
private: System::Windows::Forms::ToolStripButton^  toolStripButtonChangeLongtitude;
















			 int currParkNumberOfStalls = 0;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->showToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemParksList = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoznamZmazanýchParkovískToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zoznamZmazanýchParkovacíchMiestToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBoxTools = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxReservationInformations = (gcnew System::Windows::Forms::GroupBox());
			this->labelEnd = (gcnew System::Windows::Forms::Label());
			this->labelStart = (gcnew System::Windows::Forms::Label());
			this->labelTitleEnd = (gcnew System::Windows::Forms::Label());
			this->labelTitleStart = (gcnew System::Windows::Forms::Label());
			this->labelSPZ = (gcnew System::Windows::Forms::Label());
			this->labelTitleSPZ = (gcnew System::Windows::Forms::Label());
			this->toolStripStallSetting = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButtonDeleteStall = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonChangeStallType = (gcnew System::Windows::Forms::ToolStripButton());
			this->groupBoxChangeStallType = (gcnew System::Windows::Forms::GroupBox());
			this->buttonChangeTypeConfirm = (gcnew System::Windows::Forms::Button());
			this->checkBoxStallFree = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxStallOutOfService = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxStallReserve = (gcnew System::Windows::Forms::CheckBox());
			this->labelStallY = (gcnew System::Windows::Forms::Label());
			this->labelTitleStallY = (gcnew System::Windows::Forms::Label());
			this->labelStallX = (gcnew System::Windows::Forms::Label());
			this->labelTitleStallX = (gcnew System::Windows::Forms::Label());
			this->labelStallType = (gcnew System::Windows::Forms::Label());
			this->labelTitleStallType = (gcnew System::Windows::Forms::Label());
			this->labelStallStatus = (gcnew System::Windows::Forms::Label());
			this->labelTitleStallStatus = (gcnew System::Windows::Forms::Label());
			this->labelParkId = (gcnew System::Windows::Forms::Label());
			this->labelTitleParkId = (gcnew System::Windows::Forms::Label());
			this->labelStallId = (gcnew System::Windows::Forms::Label());
			this->labelTitleButtonId = (gcnew System::Windows::Forms::Label());
			this->groupBoxAddStall = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxAddStallWidth = (gcnew System::Windows::Forms::TextBox());
			this->labelAddStallTitleOrientation = (gcnew System::Windows::Forms::Label());
			this->labelAddStallTitleWidth = (gcnew System::Windows::Forms::Label());
			this->checkBoxAddStallVertical = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxAddStallHeight = (gcnew System::Windows::Forms::TextBox());
			this->labelAddStallTitleHeight = (gcnew System::Windows::Forms::Label());
			this->checkBoxAddStallHorizontal = (gcnew System::Windows::Forms::CheckBox());
			this->buttonAddStallConfirm = (gcnew System::Windows::Forms::Button());
			this->textBoxAddStallY = (gcnew System::Windows::Forms::TextBox());
			this->labelTitleAddStallY = (gcnew System::Windows::Forms::Label());
			this->textBoxAddStallX = (gcnew System::Windows::Forms::TextBox());
			this->labelTitleAddStallX = (gcnew System::Windows::Forms::Label());
			this->groupBoxParkList = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxSearchInParks = (gcnew System::Windows::Forms::GroupBox());
			this->comboBoxParkSearchStatus = (gcnew System::Windows::Forms::ComboBox());
			this->textBoxSearchParkFindingWord = (gcnew System::Windows::Forms::TextBox());
			this->checkBoxParkSearchId = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxParkSearchName = (gcnew System::Windows::Forms::CheckBox());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButtonAddPark = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->groupBoxInformationsAboutParking = (gcnew System::Windows::Forms::GroupBox());
			this->labelParkInformationsLongtitude = (gcnew System::Windows::Forms::Label());
			this->labelTitleParkInformationsLongtitude = (gcnew System::Windows::Forms::Label());
			this->labelParkInformationsLatitude = (gcnew System::Windows::Forms::Label());
			this->labelTitleParkInformationsLatitude = (gcnew System::Windows::Forms::Label());
			this->labelParkInformationsStatus = (gcnew System::Windows::Forms::Label());
			this->labelTitleParkInformationsStatus = (gcnew System::Windows::Forms::Label());
			this->buttonParkRecover = (gcnew System::Windows::Forms::Button());
			this->groupBoxParkChanges = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxNewParkLongtitude = (gcnew System::Windows::Forms::GroupBox());
			this->labelTitleNewParkLongtitude = (gcnew System::Windows::Forms::Label());
			this->buttonConfirmParkLatitudeChangeLongtitude = (gcnew System::Windows::Forms::Button());
			this->textBoxNewParkLongtitude = (gcnew System::Windows::Forms::TextBox());
			this->groupBoxNewParkLatitude = (gcnew System::Windows::Forms::GroupBox());
			this->labelTitleNewParkLatitude = (gcnew System::Windows::Forms::Label());
			this->buttonConfirmParkLatitudeChange = (gcnew System::Windows::Forms::Button());
			this->textBoxNewParkLatitude = (gcnew System::Windows::Forms::TextBox());
			this->groupBoxChangeParkStatus = (gcnew System::Windows::Forms::GroupBox());
			this->checkBoxParkStatusOff = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxParkStatusOn = (gcnew System::Windows::Forms::CheckBox());
			this->labelTitleChangeParkStatus = (gcnew System::Windows::Forms::Label());
			this->buttonConfirmChangeParkStatus = (gcnew System::Windows::Forms::Button());
			this->groupBoxNewParkAdress = (gcnew System::Windows::Forms::GroupBox());
			this->labelTitleNewParkAdress = (gcnew System::Windows::Forms::Label());
			this->buttonConfirmParkAdressChange = (gcnew System::Windows::Forms::Button());
			this->textBoxNewParkAdress = (gcnew System::Windows::Forms::TextBox());
			this->groupBoxNewParkName = (gcnew System::Windows::Forms::GroupBox());
			this->labelTitleNewParkName = (gcnew System::Windows::Forms::Label());
			this->buttonConfirmParkNameChange = (gcnew System::Windows::Forms::Button());
			this->textBoxNewParkName = (gcnew System::Windows::Forms::TextBox());
			this->toolStripParkChanges = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButtonParkStatusChange = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButtonChangeParkName = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonChangeAdress = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonChangeLatitude = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonChangeLongtitude = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButtonDeletePark = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButtonLoadStalls = (gcnew System::Windows::Forms::ToolStripButton());
			this->labelParkInformationsCapacity = (gcnew System::Windows::Forms::Label());
			this->labelTitleParkInformationsCapacity = (gcnew System::Windows::Forms::Label());
			this->labelParkInformationsAdress = (gcnew System::Windows::Forms::Label());
			this->labelTitleParkInformationsAdress = (gcnew System::Windows::Forms::Label());
			this->labelParkInformationsId = (gcnew System::Windows::Forms::Label());
			this->labelTitleParkInformationsId = (gcnew System::Windows::Forms::Label());
			this->labelParkInformationsName = (gcnew System::Windows::Forms::Label());
			this->labelTitleParkInformationsName = (gcnew System::Windows::Forms::Label());
			this->labelTitleInformationsAboutParking = (gcnew System::Windows::Forms::Label());
			this->listViewParkList = (gcnew System::Windows::Forms::ListView());
			this->columnHeaderId = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeaderName = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeaderStatus = (gcnew System::Windows::Forms::ColumnHeader());
			this->timerSync = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerStallsSync = (gcnew System::Windows::Forms::Timer(this->components));
			this->toolStripStallsConfig = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButtonAddStall = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButtonShowStallsInTime = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonShowStallsCurrentTime = (gcnew System::Windows::Forms::ToolStripButton());
			this->listViewDeletedStalls = (gcnew System::Windows::Forms::ListView());
			this->stallId = (gcnew System::Windows::Forms::ColumnHeader());
			this->parkId = (gcnew System::Windows::Forms::ColumnHeader());
			this->stallState = (gcnew System::Windows::Forms::ColumnHeader());
			this->stallType = (gcnew System::Windows::Forms::ColumnHeader());
			this->x = (gcnew System::Windows::Forms::ColumnHeader());
			this->y = (gcnew System::Windows::Forms::ColumnHeader());
			this->toolStripDeletedStalls = (gcnew System::Windows::Forms::ToolStrip());
			this->groupBoxSearchingDeletedStalls = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxSearchingWordDeletedStalls = (gcnew System::Windows::Forms::TextBox());
			this->checkBoxSearchInDeletedStallsStallY = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxSearchInDeletedStallsStallX = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxSearchInDeletedStallsParkId = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxSearchInDeletedStallsStallId = (gcnew System::Windows::Forms::CheckBox());
			this->groupBoxDeletedStalls = (gcnew System::Windows::Forms::GroupBox());
			this->buttonStallsPrintPageLeft = (gcnew System::Windows::Forms::Button());
			this->buttonStallsPrintPageRight = (gcnew System::Windows::Forms::Button());
			this->buttonStallsPrintPageDown = (gcnew System::Windows::Forms::Button());
			this->buttonStallsPrintPageUp = (gcnew System::Windows::Forms::Button());
			this->labelTitleShowingStallTime = (gcnew System::Windows::Forms::Label());
			this->labelShowingStallTime = (gcnew System::Windows::Forms::Label());
			this->dateTimePickerShowStallsTime = (gcnew System::Windows::Forms::DateTimePicker());
			this->buttonConfirmStallsShowingTime = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->groupBoxTools->SuspendLayout();
			this->groupBoxReservationInformations->SuspendLayout();
			this->toolStripStallSetting->SuspendLayout();
			this->groupBoxChangeStallType->SuspendLayout();
			this->groupBoxAddStall->SuspendLayout();
			this->groupBoxParkList->SuspendLayout();
			this->groupBoxSearchInParks->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->groupBoxInformationsAboutParking->SuspendLayout();
			this->groupBoxParkChanges->SuspendLayout();
			this->groupBoxNewParkLongtitude->SuspendLayout();
			this->groupBoxNewParkLatitude->SuspendLayout();
			this->groupBoxChangeParkStatus->SuspendLayout();
			this->groupBoxNewParkAdress->SuspendLayout();
			this->groupBoxNewParkName->SuspendLayout();
			this->toolStripParkChanges->SuspendLayout();
			this->toolStripStallsConfig->SuspendLayout();
			this->groupBoxSearchingDeletedStalls->SuspendLayout();
			this->groupBoxDeletedStalls->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->showToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1561, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// showToolStripMenuItem
			// 
			this->showToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolStripMenuItemParksList,
					this->zoznamZmazanýchParkovískToolStripMenuItem, this->zoznamZmazanýchParkovacíchMiestToolStripMenuItem
			});
			this->showToolStripMenuItem->Name = L"showToolStripMenuItem";
			this->showToolStripMenuItem->Size = System::Drawing::Size(79, 24);
			this->showToolStripMenuItem->Text = L"Zobraziť";
			// 
			// toolStripMenuItemParksList
			// 
			this->toolStripMenuItemParksList->Name = L"toolStripMenuItemParksList";
			this->toolStripMenuItemParksList->Size = System::Drawing::Size(338, 26);
			this->toolStripMenuItemParksList->Text = L"Zoznam parkovísk";
			this->toolStripMenuItemParksList->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItemParksList_Click);
			// 
			// zoznamZmazanýchParkovískToolStripMenuItem
			// 
			this->zoznamZmazanýchParkovískToolStripMenuItem->Name = L"zoznamZmazanýchParkovískToolStripMenuItem";
			this->zoznamZmazanýchParkovískToolStripMenuItem->Size = System::Drawing::Size(338, 26);
			this->zoznamZmazanýchParkovískToolStripMenuItem->Text = L"Zoznam zmazaných parkovísk";
			this->zoznamZmazanýchParkovískToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::zoznamZmazanýchParkovískToolStripMenuItem_Click);
			// 
			// zoznamZmazanýchParkovacíchMiestToolStripMenuItem
			// 
			this->zoznamZmazanýchParkovacíchMiestToolStripMenuItem->Name = L"zoznamZmazanýchParkovacíchMiestToolStripMenuItem";
			this->zoznamZmazanýchParkovacíchMiestToolStripMenuItem->Size = System::Drawing::Size(338, 26);
			this->zoznamZmazanýchParkovacíchMiestToolStripMenuItem->Text = L"Zoznam zmazaných parkovacích miest";
			this->zoznamZmazanýchParkovacíchMiestToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::zoznamZmazanýchParkovacíchMiestToolStripMenuItem_Click);
			// 
			// groupBoxTools
			// 
			this->groupBoxTools->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxTools->Controls->Add(this->groupBoxReservationInformations);
			this->groupBoxTools->Controls->Add(this->toolStripStallSetting);
			this->groupBoxTools->Controls->Add(this->groupBoxChangeStallType);
			this->groupBoxTools->Controls->Add(this->labelStallY);
			this->groupBoxTools->Controls->Add(this->labelTitleStallY);
			this->groupBoxTools->Controls->Add(this->labelStallX);
			this->groupBoxTools->Controls->Add(this->labelTitleStallX);
			this->groupBoxTools->Controls->Add(this->labelStallType);
			this->groupBoxTools->Controls->Add(this->labelTitleStallType);
			this->groupBoxTools->Controls->Add(this->labelStallStatus);
			this->groupBoxTools->Controls->Add(this->labelTitleStallStatus);
			this->groupBoxTools->Controls->Add(this->labelParkId);
			this->groupBoxTools->Controls->Add(this->labelTitleParkId);
			this->groupBoxTools->Controls->Add(this->labelStallId);
			this->groupBoxTools->Controls->Add(this->labelTitleButtonId);
			this->groupBoxTools->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBoxTools->Location = System::Drawing::Point(1180, 64);
			this->groupBoxTools->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxTools->Name = L"groupBoxTools";
			this->groupBoxTools->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxTools->Size = System::Drawing::Size(355, 673);
			this->groupBoxTools->TabIndex = 1;
			this->groupBoxTools->TabStop = false;
			this->groupBoxTools->Text = L"Informácie o mieste";
			// 
			// groupBoxReservationInformations
			// 
			this->groupBoxReservationInformations->Controls->Add(this->labelEnd);
			this->groupBoxReservationInformations->Controls->Add(this->labelStart);
			this->groupBoxReservationInformations->Controls->Add(this->labelTitleEnd);
			this->groupBoxReservationInformations->Controls->Add(this->labelTitleStart);
			this->groupBoxReservationInformations->Controls->Add(this->labelSPZ);
			this->groupBoxReservationInformations->Controls->Add(this->labelTitleSPZ);
			this->groupBoxReservationInformations->Location = System::Drawing::Point(11, 336);
			this->groupBoxReservationInformations->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxReservationInformations->Name = L"groupBoxReservationInformations";
			this->groupBoxReservationInformations->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxReservationInformations->Size = System::Drawing::Size(329, 110);
			this->groupBoxReservationInformations->TabIndex = 19;
			this->groupBoxReservationInformations->TabStop = false;
			this->groupBoxReservationInformations->Text = L"Informácie o zákazníkovi";
			// 
			// labelEnd
			// 
			this->labelEnd->AutoSize = true;
			this->labelEnd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelEnd->Location = System::Drawing::Point(183, 73);
			this->labelEnd->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelEnd->Name = L"labelEnd";
			this->labelEnd->Size = System::Drawing::Size(0, 17);
			this->labelEnd->TabIndex = 21;
			// 
			// labelStart
			// 
			this->labelStart->AutoSize = true;
			this->labelStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelStart->Location = System::Drawing::Point(183, 50);
			this->labelStart->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelStart->Name = L"labelStart";
			this->labelStart->Size = System::Drawing::Size(0, 17);
			this->labelStart->TabIndex = 11;
			// 
			// labelTitleEnd
			// 
			this->labelTitleEnd->AutoSize = true;
			this->labelTitleEnd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitleEnd->Location = System::Drawing::Point(11, 70);
			this->labelTitleEnd->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleEnd->Name = L"labelTitleEnd";
			this->labelTitleEnd->Size = System::Drawing::Size(81, 24);
			this->labelTitleEnd->TabIndex = 20;
			this->labelTitleEnd->Text = L"Koniec:";
			// 
			// labelTitleStart
			// 
			this->labelTitleStart->AutoSize = true;
			this->labelTitleStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitleStart->Location = System::Drawing::Point(11, 48);
			this->labelTitleStart->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleStart->Name = L"labelTitleStart";
			this->labelTitleStart->Size = System::Drawing::Size(94, 24);
			this->labelTitleStart->TabIndex = 10;
			this->labelTitleStart->Text = L"Začiatok:";
			// 
			// labelSPZ
			// 
			this->labelSPZ->AutoSize = true;
			this->labelSPZ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSPZ->Location = System::Drawing::Point(183, 28);
			this->labelSPZ->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelSPZ->Name = L"labelSPZ";
			this->labelSPZ->Size = System::Drawing::Size(0, 17);
			this->labelSPZ->TabIndex = 9;
			// 
			// labelTitleSPZ
			// 
			this->labelTitleSPZ->AutoSize = true;
			this->labelTitleSPZ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitleSPZ->Location = System::Drawing::Point(11, 26);
			this->labelTitleSPZ->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleSPZ->Name = L"labelTitleSPZ";
			this->labelTitleSPZ->Size = System::Drawing::Size(55, 24);
			this->labelTitleSPZ->TabIndex = 8;
			this->labelTitleSPZ->Text = L"ŠPZ:";
			// 
			// toolStripStallSetting
			// 
			this->toolStripStallSetting->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStripStallSetting->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripButtonDeleteStall,
					this->toolStripButtonChangeStallType
			});
			this->toolStripStallSetting->Location = System::Drawing::Point(4, 23);
			this->toolStripStallSetting->Name = L"toolStripStallSetting";
			this->toolStripStallSetting->Size = System::Drawing::Size(347, 27);
			this->toolStripStallSetting->TabIndex = 18;
			this->toolStripStallSetting->Text = L"Možnosti pre p. miesto";
			// 
			// toolStripButtonDeleteStall
			// 
			this->toolStripButtonDeleteStall->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonDeleteStall->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonDeleteStall.Image")));
			this->toolStripButtonDeleteStall->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonDeleteStall->Name = L"toolStripButtonDeleteStall";
			this->toolStripButtonDeleteStall->Size = System::Drawing::Size(24, 24);
			this->toolStripButtonDeleteStall->Text = L"Zmazať miesto";
			this->toolStripButtonDeleteStall->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonDeleteStall_Click);
			// 
			// toolStripButtonChangeStallType
			// 
			this->toolStripButtonChangeStallType->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonChangeStallType->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonChangeStallType.Image")));
			this->toolStripButtonChangeStallType->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonChangeStallType->Name = L"toolStripButtonChangeStallType";
			this->toolStripButtonChangeStallType->Size = System::Drawing::Size(24, 24);
			this->toolStripButtonChangeStallType->Text = L"Zmena typu miesta";
			this->toolStripButtonChangeStallType->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonChangeStallType_Click);
			// 
			// groupBoxChangeStallType
			// 
			this->groupBoxChangeStallType->Controls->Add(this->buttonChangeTypeConfirm);
			this->groupBoxChangeStallType->Controls->Add(this->checkBoxStallFree);
			this->groupBoxChangeStallType->Controls->Add(this->checkBoxStallOutOfService);
			this->groupBoxChangeStallType->Controls->Add(this->checkBoxStallReserve);
			this->groupBoxChangeStallType->Location = System::Drawing::Point(17, 171);
			this->groupBoxChangeStallType->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxChangeStallType->Name = L"groupBoxChangeStallType";
			this->groupBoxChangeStallType->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxChangeStallType->Size = System::Drawing::Size(332, 92);
			this->groupBoxChangeStallType->TabIndex = 17;
			this->groupBoxChangeStallType->TabStop = false;
			// 
			// buttonChangeTypeConfirm
			// 
			this->buttonChangeTypeConfirm->Location = System::Drawing::Point(8, 59);
			this->buttonChangeTypeConfirm->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->buttonChangeTypeConfirm->Name = L"buttonChangeTypeConfirm";
			this->buttonChangeTypeConfirm->Size = System::Drawing::Size(315, 28);
			this->buttonChangeTypeConfirm->TabIndex = 17;
			this->buttonChangeTypeConfirm->Text = L"Potvrdiť";
			this->buttonChangeTypeConfirm->UseVisualStyleBackColor = true;
			this->buttonChangeTypeConfirm->Click += gcnew System::EventHandler(this, &MyForm::buttonChangeTypeConfirm_Click);
			// 
			// checkBoxStallFree
			// 
			this->checkBoxStallFree->AutoSize = true;
			this->checkBoxStallFree->Location = System::Drawing::Point(8, 26);
			this->checkBoxStallFree->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBoxStallFree->Name = L"checkBoxStallFree";
			this->checkBoxStallFree->Size = System::Drawing::Size(75, 24);
			this->checkBoxStallFree->TabIndex = 14;
			this->checkBoxStallFree->Text = L"Voľné";
			this->checkBoxStallFree->UseVisualStyleBackColor = true;
			this->checkBoxStallFree->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxStallFree_CheckedChanged);
			// 
			// checkBoxStallOutOfService
			// 
			this->checkBoxStallOutOfService->AutoSize = true;
			this->checkBoxStallOutOfService->Location = System::Drawing::Point(236, 26);
			this->checkBoxStallOutOfService->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBoxStallOutOfService->Name = L"checkBoxStallOutOfService";
			this->checkBoxStallOutOfService->Size = System::Drawing::Size(78, 24);
			this->checkBoxStallOutOfService->TabIndex = 16;
			this->checkBoxStallOutOfService->Text = L"Servis";
			this->checkBoxStallOutOfService->UseVisualStyleBackColor = true;
			this->checkBoxStallOutOfService->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxOutOfService_CheckedChanged);
			// 
			// checkBoxStallReserve
			// 
			this->checkBoxStallReserve->AutoSize = true;
			this->checkBoxStallReserve->Location = System::Drawing::Point(100, 26);
			this->checkBoxStallReserve->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBoxStallReserve->Name = L"checkBoxStallReserve";
			this->checkBoxStallReserve->Size = System::Drawing::Size(115, 24);
			this->checkBoxStallReserve->TabIndex = 15;
			this->checkBoxStallReserve->Text = L"Rezervácia";
			this->checkBoxStallReserve->UseVisualStyleBackColor = true;
			this->checkBoxStallReserve->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxStallReserve_CheckedChanged);
			// 
			// labelStallY
			// 
			this->labelStallY->AutoSize = true;
			this->labelStallY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelStallY->Location = System::Drawing::Point(184, 294);
			this->labelStallY->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelStallY->Name = L"labelStallY";
			this->labelStallY->Size = System::Drawing::Size(13, 17);
			this->labelStallY->TabIndex = 11;
			this->labelStallY->Text = L"-";
			// 
			// labelTitleStallY
			// 
			this->labelTitleStallY->AutoSize = true;
			this->labelTitleStallY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitleStallY->Location = System::Drawing::Point(13, 289);
			this->labelTitleStallY->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleStallY->Name = L"labelTitleStallY";
			this->labelTitleStallY->Size = System::Drawing::Size(126, 24);
			this->labelTitleStallY->TabIndex = 10;
			this->labelTitleStallY->Text = L"Y súradnica:";
			// 
			// labelStallX
			// 
			this->labelStallX->AutoSize = true;
			this->labelStallX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelStallX->Location = System::Drawing::Point(184, 267);
			this->labelStallX->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelStallX->Name = L"labelStallX";
			this->labelStallX->Size = System::Drawing::Size(13, 17);
			this->labelStallX->TabIndex = 9;
			this->labelStallX->Text = L"-";
			// 
			// labelTitleStallX
			// 
			this->labelTitleStallX->AutoSize = true;
			this->labelTitleStallX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitleStallX->Location = System::Drawing::Point(12, 267);
			this->labelTitleStallX->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleStallX->Name = L"labelTitleStallX";
			this->labelTitleStallX->Size = System::Drawing::Size(128, 24);
			this->labelTitleStallX->TabIndex = 8;
			this->labelTitleStallX->Text = L"X súradnica:";
			// 
			// labelStallType
			// 
			this->labelStallType->AutoSize = true;
			this->labelStallType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelStallType->Location = System::Drawing::Point(184, 145);
			this->labelStallType->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelStallType->Name = L"labelStallType";
			this->labelStallType->Size = System::Drawing::Size(13, 17);
			this->labelStallType->TabIndex = 7;
			this->labelStallType->Text = L"-";
			// 
			// labelTitleStallType
			// 
			this->labelTitleStallType->AutoSize = true;
			this->labelTitleStallType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelTitleStallType->Location = System::Drawing::Point(12, 143);
			this->labelTitleStallType->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleStallType->Name = L"labelTitleStallType";
			this->labelTitleStallType->Size = System::Drawing::Size(117, 24);
			this->labelTitleStallType->TabIndex = 6;
			this->labelTitleStallType->Text = L"Typ miesta:";
			// 
			// labelStallStatus
			// 
			this->labelStallStatus->AutoSize = true;
			this->labelStallStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelStallStatus->Location = System::Drawing::Point(184, 117);
			this->labelStallStatus->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelStallStatus->Name = L"labelStallStatus";
			this->labelStallStatus->Size = System::Drawing::Size(13, 17);
			this->labelStallStatus->TabIndex = 5;
			this->labelStallStatus->Text = L"-";
			// 
			// labelTitleStallStatus
			// 
			this->labelTitleStallStatus->AutoSize = true;
			this->labelTitleStallStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelTitleStallStatus->Location = System::Drawing::Point(12, 114);
			this->labelTitleStallStatus->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleStallStatus->Name = L"labelTitleStallStatus";
			this->labelTitleStallStatus->Size = System::Drawing::Size(121, 24);
			this->labelTitleStallStatus->TabIndex = 4;
			this->labelTitleStallStatus->Text = L"Stav miesta:";
			// 
			// labelParkId
			// 
			this->labelParkId->AutoSize = true;
			this->labelParkId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelParkId->Location = System::Drawing::Point(184, 90);
			this->labelParkId->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelParkId->Name = L"labelParkId";
			this->labelParkId->Size = System::Drawing::Size(13, 17);
			this->labelParkId->TabIndex = 3;
			this->labelParkId->Text = L"-";
			// 
			// labelTitleParkId
			// 
			this->labelTitleParkId->AutoSize = true;
			this->labelTitleParkId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitleParkId->Location = System::Drawing::Point(12, 87);
			this->labelTitleParkId->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleParkId->Name = L"labelTitleParkId";
			this->labelTitleParkId->Size = System::Drawing::Size(131, 24);
			this->labelTitleParkId->TabIndex = 2;
			this->labelTitleParkId->Text = L"Id parkoviska";
			// 
			// labelStallId
			// 
			this->labelStallId->AutoSize = true;
			this->labelStallId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelStallId->Location = System::Drawing::Point(183, 63);
			this->labelStallId->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelStallId->Name = L"labelStallId";
			this->labelStallId->Size = System::Drawing::Size(13, 17);
			this->labelStallId->TabIndex = 1;
			this->labelStallId->Text = L"-";
			// 
			// labelTitleButtonId
			// 
			this->labelTitleButtonId->AutoSize = true;
			this->labelTitleButtonId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelTitleButtonId->Location = System::Drawing::Point(12, 60);
			this->labelTitleButtonId->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleButtonId->Name = L"labelTitleButtonId";
			this->labelTitleButtonId->Size = System::Drawing::Size(99, 24);
			this->labelTitleButtonId->TabIndex = 0;
			this->labelTitleButtonId->Text = L"Id miesta:";
			// 
			// groupBoxAddStall
			// 
			this->groupBoxAddStall->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxAddStall->Controls->Add(this->textBoxAddStallWidth);
			this->groupBoxAddStall->Controls->Add(this->labelAddStallTitleOrientation);
			this->groupBoxAddStall->Controls->Add(this->labelAddStallTitleWidth);
			this->groupBoxAddStall->Controls->Add(this->checkBoxAddStallVertical);
			this->groupBoxAddStall->Controls->Add(this->textBoxAddStallHeight);
			this->groupBoxAddStall->Controls->Add(this->labelAddStallTitleHeight);
			this->groupBoxAddStall->Controls->Add(this->checkBoxAddStallHorizontal);
			this->groupBoxAddStall->Controls->Add(this->buttonAddStallConfirm);
			this->groupBoxAddStall->Controls->Add(this->textBoxAddStallY);
			this->groupBoxAddStall->Controls->Add(this->labelTitleAddStallY);
			this->groupBoxAddStall->Controls->Add(this->textBoxAddStallX);
			this->groupBoxAddStall->Controls->Add(this->labelTitleAddStallX);
			this->groupBoxAddStall->Location = System::Drawing::Point(1179, 68);
			this->groupBoxAddStall->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxAddStall->Name = L"groupBoxAddStall";
			this->groupBoxAddStall->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxAddStall->Size = System::Drawing::Size(356, 260);
			this->groupBoxAddStall->TabIndex = 18;
			this->groupBoxAddStall->TabStop = false;
			this->groupBoxAddStall->Text = L"Pridať parkovacie miesto";
			// 
			// textBoxAddStallWidth
			// 
			this->textBoxAddStallWidth->Location = System::Drawing::Point(156, 170);
			this->textBoxAddStallWidth->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxAddStallWidth->Name = L"textBoxAddStallWidth";
			this->textBoxAddStallWidth->Size = System::Drawing::Size(132, 22);
			this->textBoxAddStallWidth->TabIndex = 9;
			// 
			// labelAddStallTitleOrientation
			// 
			this->labelAddStallTitleOrientation->AutoSize = true;
			this->labelAddStallTitleOrientation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelAddStallTitleOrientation->Location = System::Drawing::Point(119, 92);
			this->labelAddStallTitleOrientation->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelAddStallTitleOrientation->Name = L"labelAddStallTitleOrientation";
			this->labelAddStallTitleOrientation->Size = System::Drawing::Size(96, 20);
			this->labelAddStallTitleOrientation->TabIndex = 9;
			this->labelAddStallTitleOrientation->Text = L"Orientácia";
			// 
			// labelAddStallTitleWidth
			// 
			this->labelAddStallTitleWidth->AutoSize = true;
			this->labelAddStallTitleWidth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelAddStallTitleWidth->Location = System::Drawing::Point(13, 175);
			this->labelAddStallTitleWidth->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelAddStallTitleWidth->Name = L"labelAddStallTitleWidth";
			this->labelAddStallTitleWidth->Size = System::Drawing::Size(97, 20);
			this->labelAddStallTitleWidth->TabIndex = 8;
			this->labelAddStallTitleWidth->Text = L"Šírka(cm):";
			// 
			// checkBoxAddStallVertical
			// 
			this->checkBoxAddStallVertical->AutoSize = true;
			this->checkBoxAddStallVertical->Location = System::Drawing::Point(189, 116);
			this->checkBoxAddStallVertical->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBoxAddStallVertical->Name = L"checkBoxAddStallVertical";
			this->checkBoxAddStallVertical->Size = System::Drawing::Size(93, 21);
			this->checkBoxAddStallVertical->TabIndex = 8;
			this->checkBoxAddStallVertical->Text = L"Vertikálne";
			this->checkBoxAddStallVertical->UseVisualStyleBackColor = true;
			this->checkBoxAddStallVertical->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxAddStallVertical_CheckedChanged);
			// 
			// textBoxAddStallHeight
			// 
			this->textBoxAddStallHeight->Location = System::Drawing::Point(156, 144);
			this->textBoxAddStallHeight->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxAddStallHeight->Name = L"textBoxAddStallHeight";
			this->textBoxAddStallHeight->Size = System::Drawing::Size(132, 22);
			this->textBoxAddStallHeight->TabIndex = 7;
			// 
			// labelAddStallTitleHeight
			// 
			this->labelAddStallTitleHeight->AutoSize = true;
			this->labelAddStallTitleHeight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelAddStallTitleHeight->Location = System::Drawing::Point(13, 149);
			this->labelAddStallTitleHeight->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelAddStallTitleHeight->Name = L"labelAddStallTitleHeight";
			this->labelAddStallTitleHeight->Size = System::Drawing::Size(102, 20);
			this->labelAddStallTitleHeight->TabIndex = 6;
			this->labelAddStallTitleHeight->Text = L"Dĺžka(cm):";
			// 
			// checkBoxAddStallHorizontal
			// 
			this->checkBoxAddStallHorizontal->AutoSize = true;
			this->checkBoxAddStallHorizontal->Checked = true;
			this->checkBoxAddStallHorizontal->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxAddStallHorizontal->Location = System::Drawing::Point(61, 116);
			this->checkBoxAddStallHorizontal->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBoxAddStallHorizontal->Name = L"checkBoxAddStallHorizontal";
			this->checkBoxAddStallHorizontal->Size = System::Drawing::Size(113, 21);
			this->checkBoxAddStallHorizontal->TabIndex = 7;
			this->checkBoxAddStallHorizontal->Text = L"Horizonzálne";
			this->checkBoxAddStallHorizontal->UseVisualStyleBackColor = true;
			this->checkBoxAddStallHorizontal->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxAddStallHorizontal_CheckedChanged);
			// 
			// buttonAddStallConfirm
			// 
			this->buttonAddStallConfirm->Location = System::Drawing::Point(15, 220);
			this->buttonAddStallConfirm->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->buttonAddStallConfirm->Name = L"buttonAddStallConfirm";
			this->buttonAddStallConfirm->Size = System::Drawing::Size(327, 28);
			this->buttonAddStallConfirm->TabIndex = 6;
			this->buttonAddStallConfirm->Text = L"Pridať";
			this->buttonAddStallConfirm->UseVisualStyleBackColor = true;
			this->buttonAddStallConfirm->Click += gcnew System::EventHandler(this, &MyForm::buttonAddStallConfirm_Click);
			// 
			// textBoxAddStallY
			// 
			this->textBoxAddStallY->Location = System::Drawing::Point(156, 57);
			this->textBoxAddStallY->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxAddStallY->Name = L"textBoxAddStallY";
			this->textBoxAddStallY->Size = System::Drawing::Size(132, 22);
			this->textBoxAddStallY->TabIndex = 5;
			// 
			// labelTitleAddStallY
			// 
			this->labelTitleAddStallY->AutoSize = true;
			this->labelTitleAddStallY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelTitleAddStallY->Location = System::Drawing::Point(13, 62);
			this->labelTitleAddStallY->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleAddStallY->Name = L"labelTitleAddStallY";
			this->labelTitleAddStallY->Size = System::Drawing::Size(122, 20);
			this->labelTitleAddStallY->TabIndex = 4;
			this->labelTitleAddStallY->Text = L"Súradnica Y: ";
			// 
			// textBoxAddStallX
			// 
			this->textBoxAddStallX->Location = System::Drawing::Point(156, 31);
			this->textBoxAddStallX->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxAddStallX->Name = L"textBoxAddStallX";
			this->textBoxAddStallX->Size = System::Drawing::Size(132, 22);
			this->textBoxAddStallX->TabIndex = 3;
			// 
			// labelTitleAddStallX
			// 
			this->labelTitleAddStallX->AutoSize = true;
			this->labelTitleAddStallX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelTitleAddStallX->Location = System::Drawing::Point(13, 36);
			this->labelTitleAddStallX->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleAddStallX->Name = L"labelTitleAddStallX";
			this->labelTitleAddStallX->Size = System::Drawing::Size(123, 20);
			this->labelTitleAddStallX->TabIndex = 2;
			this->labelTitleAddStallX->Text = L"Súradnica X: ";
			// 
			// groupBoxParkList
			// 
			this->groupBoxParkList->Controls->Add(this->groupBoxSearchInParks);
			this->groupBoxParkList->Controls->Add(this->toolStrip1);
			this->groupBoxParkList->Controls->Add(this->groupBoxInformationsAboutParking);
			this->groupBoxParkList->Controls->Add(this->listViewParkList);
			this->groupBoxParkList->Location = System::Drawing::Point(0, 30);
			this->groupBoxParkList->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxParkList->Name = L"groupBoxParkList";
			this->groupBoxParkList->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxParkList->Size = System::Drawing::Size(1561, 719);
			this->groupBoxParkList->TabIndex = 2;
			this->groupBoxParkList->TabStop = false;
			// 
			// groupBoxSearchInParks
			// 
			this->groupBoxSearchInParks->Controls->Add(this->comboBoxParkSearchStatus);
			this->groupBoxSearchInParks->Controls->Add(this->textBoxSearchParkFindingWord);
			this->groupBoxSearchInParks->Controls->Add(this->checkBoxParkSearchId);
			this->groupBoxSearchInParks->Controls->Add(this->checkBoxParkSearchName);
			this->groupBoxSearchInParks->Location = System::Drawing::Point(1163, 49);
			this->groupBoxSearchInParks->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxSearchInParks->Name = L"groupBoxSearchInParks";
			this->groupBoxSearchInParks->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxSearchInParks->Size = System::Drawing::Size(357, 646);
			this->groupBoxSearchInParks->TabIndex = 3;
			this->groupBoxSearchInParks->TabStop = false;
			this->groupBoxSearchInParks->Text = L"Vyhladávanie";
			// 
			// comboBoxParkSearchStatus
			// 
			this->comboBoxParkSearchStatus->FormattingEnabled = true;
			this->comboBoxParkSearchStatus->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Aktivne", L"Neaktivne", L"-" });
			this->comboBoxParkSearchStatus->Location = System::Drawing::Point(183, 20);
			this->comboBoxParkSearchStatus->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->comboBoxParkSearchStatus->Name = L"comboBoxParkSearchStatus";
			this->comboBoxParkSearchStatus->Size = System::Drawing::Size(160, 24);
			this->comboBoxParkSearchStatus->TabIndex = 3;
			this->comboBoxParkSearchStatus->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxParkSearchStatus_SelectedIndexChanged);
			// 
			// textBoxSearchParkFindingWord
			// 
			this->textBoxSearchParkFindingWord->Location = System::Drawing::Point(17, 53);
			this->textBoxSearchParkFindingWord->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxSearchParkFindingWord->Name = L"textBoxSearchParkFindingWord";
			this->textBoxSearchParkFindingWord->Size = System::Drawing::Size(331, 22);
			this->textBoxSearchParkFindingWord->TabIndex = 2;
			this->textBoxSearchParkFindingWord->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxSearchParkFindingWord_TextChanged);
			// 
			// checkBoxParkSearchId
			// 
			this->checkBoxParkSearchId->AutoSize = true;
			this->checkBoxParkSearchId->Location = System::Drawing::Point(128, 23);
			this->checkBoxParkSearchId->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBoxParkSearchId->Name = L"checkBoxParkSearchId";
			this->checkBoxParkSearchId->Size = System::Drawing::Size(41, 21);
			this->checkBoxParkSearchId->TabIndex = 1;
			this->checkBoxParkSearchId->Text = L"Id";
			this->checkBoxParkSearchId->UseVisualStyleBackColor = true;
			this->checkBoxParkSearchId->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxParkSearchId_CheckedChanged);
			// 
			// checkBoxParkSearchName
			// 
			this->checkBoxParkSearchName->AutoSize = true;
			this->checkBoxParkSearchName->Checked = true;
			this->checkBoxParkSearchName->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxParkSearchName->Location = System::Drawing::Point(17, 23);
			this->checkBoxParkSearchName->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBoxParkSearchName->Name = L"checkBoxParkSearchName";
			this->checkBoxParkSearchName->Size = System::Drawing::Size(70, 21);
			this->checkBoxParkSearchName->TabIndex = 0;
			this->checkBoxParkSearchName->Text = L"Názov";
			this->checkBoxParkSearchName->UseVisualStyleBackColor = true;
			this->checkBoxParkSearchName->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxParkSearchName_CheckedChanged);
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripButtonAddPark,
					this->toolStripSeparator1
			});
			this->toolStrip1->Location = System::Drawing::Point(4, 19);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1553, 27);
			this->toolStrip1->TabIndex = 2;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButtonAddPark
			// 
			this->toolStripButtonAddPark->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonAddPark->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonAddPark.Image")));
			this->toolStripButtonAddPark->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonAddPark->Name = L"toolStripButtonAddPark";
			this->toolStripButtonAddPark->Size = System::Drawing::Size(24, 24);
			this->toolStripButtonAddPark->Text = L"Pridanie parkoviska";
			this->toolStripButtonAddPark->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton1_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 27);
			// 
			// groupBoxInformationsAboutParking
			// 
			this->groupBoxInformationsAboutParking->Controls->Add(this->labelParkInformationsLongtitude);
			this->groupBoxInformationsAboutParking->Controls->Add(this->labelTitleParkInformationsLongtitude);
			this->groupBoxInformationsAboutParking->Controls->Add(this->labelParkInformationsLatitude);
			this->groupBoxInformationsAboutParking->Controls->Add(this->labelTitleParkInformationsLatitude);
			this->groupBoxInformationsAboutParking->Controls->Add(this->labelParkInformationsStatus);
			this->groupBoxInformationsAboutParking->Controls->Add(this->labelTitleParkInformationsStatus);
			this->groupBoxInformationsAboutParking->Controls->Add(this->buttonParkRecover);
			this->groupBoxInformationsAboutParking->Controls->Add(this->groupBoxParkChanges);
			this->groupBoxInformationsAboutParking->Controls->Add(this->toolStripParkChanges);
			this->groupBoxInformationsAboutParking->Controls->Add(this->labelParkInformationsCapacity);
			this->groupBoxInformationsAboutParking->Controls->Add(this->labelTitleParkInformationsCapacity);
			this->groupBoxInformationsAboutParking->Controls->Add(this->labelParkInformationsAdress);
			this->groupBoxInformationsAboutParking->Controls->Add(this->labelTitleParkInformationsAdress);
			this->groupBoxInformationsAboutParking->Controls->Add(this->labelParkInformationsId);
			this->groupBoxInformationsAboutParking->Controls->Add(this->labelTitleParkInformationsId);
			this->groupBoxInformationsAboutParking->Controls->Add(this->labelParkInformationsName);
			this->groupBoxInformationsAboutParking->Controls->Add(this->labelTitleParkInformationsName);
			this->groupBoxInformationsAboutParking->Controls->Add(this->labelTitleInformationsAboutParking);
			this->groupBoxInformationsAboutParking->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->groupBoxInformationsAboutParking->Location = System::Drawing::Point(663, 49);
			this->groupBoxInformationsAboutParking->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxInformationsAboutParking->Name = L"groupBoxInformationsAboutParking";
			this->groupBoxInformationsAboutParking->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxInformationsAboutParking->Size = System::Drawing::Size(484, 646);
			this->groupBoxInformationsAboutParking->TabIndex = 1;
			this->groupBoxInformationsAboutParking->TabStop = false;
			this->groupBoxInformationsAboutParking->Text = L"Informácie o parkovisku";
			// 
			// labelParkInformationsLongtitude
			// 
			this->labelParkInformationsLongtitude->AutoSize = true;
			this->labelParkInformationsLongtitude->Location = System::Drawing::Point(253, 246);
			this->labelParkInformationsLongtitude->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelParkInformationsLongtitude->Name = L"labelParkInformationsLongtitude";
			this->labelParkInformationsLongtitude->Size = System::Drawing::Size(85, 20);
			this->labelParkInformationsLongtitude->TabIndex = 17;
			this->labelParkInformationsLongtitude->Text = L"Zem dlzka";
			// 
			// labelTitleParkInformationsLongtitude
			// 
			this->labelTitleParkInformationsLongtitude->AutoSize = true;
			this->labelTitleParkInformationsLongtitude->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelTitleParkInformationsLongtitude->Location = System::Drawing::Point(27, 242);
			this->labelTitleParkInformationsLongtitude->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleParkInformationsLongtitude->Name = L"labelTitleParkInformationsLongtitude";
			this->labelTitleParkInformationsLongtitude->Size = System::Drawing::Size(155, 20);
			this->labelTitleParkInformationsLongtitude->TabIndex = 16;
			this->labelTitleParkInformationsLongtitude->Text = L"Zemepisná dĺžka:";
			// 
			// labelParkInformationsLatitude
			// 
			this->labelParkInformationsLatitude->AutoSize = true;
			this->labelParkInformationsLatitude->Location = System::Drawing::Point(253, 213);
			this->labelParkInformationsLatitude->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelParkInformationsLatitude->Name = L"labelParkInformationsLatitude";
			this->labelParkInformationsLatitude->Size = System::Drawing::Size(82, 20);
			this->labelParkInformationsLatitude->TabIndex = 15;
			this->labelParkInformationsLatitude->Text = L"Zem sirka";
			// 
			// labelTitleParkInformationsLatitude
			// 
			this->labelTitleParkInformationsLatitude->AutoSize = true;
			this->labelTitleParkInformationsLatitude->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelTitleParkInformationsLatitude->Location = System::Drawing::Point(27, 213);
			this->labelTitleParkInformationsLatitude->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleParkInformationsLatitude->Name = L"labelTitleParkInformationsLatitude";
			this->labelTitleParkInformationsLatitude->Size = System::Drawing::Size(152, 20);
			this->labelTitleParkInformationsLatitude->TabIndex = 14;
			this->labelTitleParkInformationsLatitude->Text = L"Zemepisná šírka:";
			// 
			// labelParkInformationsStatus
			// 
			this->labelParkInformationsStatus->AutoSize = true;
			this->labelParkInformationsStatus->Location = System::Drawing::Point(253, 187);
			this->labelParkInformationsStatus->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelParkInformationsStatus->Name = L"labelParkInformationsStatus";
			this->labelParkInformationsStatus->Size = System::Drawing::Size(57, 20);
			this->labelParkInformationsStatus->TabIndex = 13;
			this->labelParkInformationsStatus->Text = L"Status";
			// 
			// labelTitleParkInformationsStatus
			// 
			this->labelTitleParkInformationsStatus->AutoSize = true;
			this->labelTitleParkInformationsStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelTitleParkInformationsStatus->Location = System::Drawing::Point(25, 187);
			this->labelTitleParkInformationsStatus->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleParkInformationsStatus->Name = L"labelTitleParkInformationsStatus";
			this->labelTitleParkInformationsStatus->Size = System::Drawing::Size(69, 20);
			this->labelTitleParkInformationsStatus->TabIndex = 12;
			this->labelTitleParkInformationsStatus->Text = L"Status:";
			// 
			// buttonParkRecover
			// 
			this->buttonParkRecover->BackColor = System::Drawing::SystemColors::Info;
			this->buttonParkRecover->Location = System::Drawing::Point(17, 58);
			this->buttonParkRecover->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->buttonParkRecover->Name = L"buttonParkRecover";
			this->buttonParkRecover->Size = System::Drawing::Size(467, 28);
			this->buttonParkRecover->TabIndex = 11;
			this->buttonParkRecover->Text = L"Obnoviť parkovisko";
			this->buttonParkRecover->UseVisualStyleBackColor = false;
			this->buttonParkRecover->Click += gcnew System::EventHandler(this, &MyForm::buttonParkRecover_Click);
			// 
			// groupBoxParkChanges
			// 
			this->groupBoxParkChanges->Controls->Add(this->groupBoxNewParkLongtitude);
			this->groupBoxParkChanges->Controls->Add(this->groupBoxNewParkLatitude);
			this->groupBoxParkChanges->Controls->Add(this->groupBoxChangeParkStatus);
			this->groupBoxParkChanges->Controls->Add(this->groupBoxNewParkAdress);
			this->groupBoxParkChanges->Controls->Add(this->groupBoxNewParkName);
			this->groupBoxParkChanges->Location = System::Drawing::Point(9, 279);
			this->groupBoxParkChanges->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxParkChanges->Name = L"groupBoxParkChanges";
			this->groupBoxParkChanges->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxParkChanges->Size = System::Drawing::Size(467, 359);
			this->groupBoxParkChanges->TabIndex = 10;
			this->groupBoxParkChanges->TabStop = false;
			// 
			// groupBoxNewParkLongtitude
			// 
			this->groupBoxNewParkLongtitude->Controls->Add(this->labelTitleNewParkLongtitude);
			this->groupBoxNewParkLongtitude->Controls->Add(this->buttonConfirmParkLatitudeChangeLongtitude);
			this->groupBoxNewParkLongtitude->Controls->Add(this->textBoxNewParkLongtitude);
			this->groupBoxNewParkLongtitude->Location = System::Drawing::Point(7, 107);
			this->groupBoxNewParkLongtitude->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxNewParkLongtitude->Name = L"groupBoxNewParkLongtitude";
			this->groupBoxNewParkLongtitude->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxNewParkLongtitude->Size = System::Drawing::Size(452, 90);
			this->groupBoxNewParkLongtitude->TabIndex = 19;
			this->groupBoxNewParkLongtitude->TabStop = false;
			// 
			// labelTitleNewParkLongtitude
			// 
			this->labelTitleNewParkLongtitude->AutoSize = true;
			this->labelTitleNewParkLongtitude->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelTitleNewParkLongtitude->Location = System::Drawing::Point(8, 20);
			this->labelTitleNewParkLongtitude->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleNewParkLongtitude->Name = L"labelTitleNewParkLongtitude";
			this->labelTitleNewParkLongtitude->Size = System::Drawing::Size(225, 24);
			this->labelTitleNewParkLongtitude->TabIndex = 0;
			this->labelTitleNewParkLongtitude->Text = L"Nová zemepisná dĺžka:";
			// 
			// buttonConfirmParkLatitudeChangeLongtitude
			// 
			this->buttonConfirmParkLatitudeChangeLongtitude->Location = System::Drawing::Point(12, 50);
			this->buttonConfirmParkLatitudeChangeLongtitude->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->buttonConfirmParkLatitudeChangeLongtitude->Name = L"buttonConfirmParkLatitudeChangeLongtitude";
			this->buttonConfirmParkLatitudeChangeLongtitude->Size = System::Drawing::Size(431, 28);
			this->buttonConfirmParkLatitudeChangeLongtitude->TabIndex = 2;
			this->buttonConfirmParkLatitudeChangeLongtitude->Text = L"Povrdiť";
			this->buttonConfirmParkLatitudeChangeLongtitude->UseVisualStyleBackColor = true;
			this->buttonConfirmParkLatitudeChangeLongtitude->Click += gcnew System::EventHandler(this, &MyForm::buttonConfirmParkLatitudeChangeLongtitude_Click);
			// 
			// textBoxNewParkLongtitude
			// 
			this->textBoxNewParkLongtitude->Location = System::Drawing::Point(256, 18);
			this->textBoxNewParkLongtitude->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxNewParkLongtitude->Name = L"textBoxNewParkLongtitude";
			this->textBoxNewParkLongtitude->Size = System::Drawing::Size(185, 26);
			this->textBoxNewParkLongtitude->TabIndex = 1;
			// 
			// groupBoxNewParkLatitude
			// 
			this->groupBoxNewParkLatitude->Controls->Add(this->labelTitleNewParkLatitude);
			this->groupBoxNewParkLatitude->Controls->Add(this->buttonConfirmParkLatitudeChange);
			this->groupBoxNewParkLatitude->Controls->Add(this->textBoxNewParkLatitude);
			this->groupBoxNewParkLatitude->Location = System::Drawing::Point(7, 10);
			this->groupBoxNewParkLatitude->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxNewParkLatitude->Name = L"groupBoxNewParkLatitude";
			this->groupBoxNewParkLatitude->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxNewParkLatitude->Size = System::Drawing::Size(452, 90);
			this->groupBoxNewParkLatitude->TabIndex = 18;
			this->groupBoxNewParkLatitude->TabStop = false;
			// 
			// labelTitleNewParkLatitude
			// 
			this->labelTitleNewParkLatitude->AutoSize = true;
			this->labelTitleNewParkLatitude->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelTitleNewParkLatitude->Location = System::Drawing::Point(8, 20);
			this->labelTitleNewParkLatitude->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleNewParkLatitude->Name = L"labelTitleNewParkLatitude";
			this->labelTitleNewParkLatitude->Size = System::Drawing::Size(220, 24);
			this->labelTitleNewParkLatitude->TabIndex = 0;
			this->labelTitleNewParkLatitude->Text = L"Nová zemepisná šírka:";
			// 
			// buttonConfirmParkLatitudeChange
			// 
			this->buttonConfirmParkLatitudeChange->Location = System::Drawing::Point(12, 50);
			this->buttonConfirmParkLatitudeChange->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->buttonConfirmParkLatitudeChange->Name = L"buttonConfirmParkLatitudeChange";
			this->buttonConfirmParkLatitudeChange->Size = System::Drawing::Size(431, 28);
			this->buttonConfirmParkLatitudeChange->TabIndex = 2;
			this->buttonConfirmParkLatitudeChange->Text = L"Povrdiť";
			this->buttonConfirmParkLatitudeChange->UseVisualStyleBackColor = true;
			this->buttonConfirmParkLatitudeChange->Click += gcnew System::EventHandler(this, &MyForm::buttonConfirmParkLatitudeChange_Click);
			// 
			// textBoxNewParkLatitude
			// 
			this->textBoxNewParkLatitude->Location = System::Drawing::Point(256, 18);
			this->textBoxNewParkLatitude->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxNewParkLatitude->Name = L"textBoxNewParkLatitude";
			this->textBoxNewParkLatitude->Size = System::Drawing::Size(185, 26);
			this->textBoxNewParkLatitude->TabIndex = 1;
			// 
			// groupBoxChangeParkStatus
			// 
			this->groupBoxChangeParkStatus->Controls->Add(this->checkBoxParkStatusOff);
			this->groupBoxChangeParkStatus->Controls->Add(this->checkBoxParkStatusOn);
			this->groupBoxChangeParkStatus->Controls->Add(this->labelTitleChangeParkStatus);
			this->groupBoxChangeParkStatus->Controls->Add(this->buttonConfirmChangeParkStatus);
			this->groupBoxChangeParkStatus->Location = System::Drawing::Point(8, 209);
			this->groupBoxChangeParkStatus->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxChangeParkStatus->Name = L"groupBoxChangeParkStatus";
			this->groupBoxChangeParkStatus->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxChangeParkStatus->Size = System::Drawing::Size(451, 145);
			this->groupBoxChangeParkStatus->TabIndex = 5;
			this->groupBoxChangeParkStatus->TabStop = false;
			// 
			// checkBoxParkStatusOff
			// 
			this->checkBoxParkStatusOff->AutoSize = true;
			this->checkBoxParkStatusOff->Location = System::Drawing::Point(257, 66);
			this->checkBoxParkStatusOff->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBoxParkStatusOff->Name = L"checkBoxParkStatusOff";
			this->checkBoxParkStatusOff->Size = System::Drawing::Size(104, 24);
			this->checkBoxParkStatusOff->TabIndex = 4;
			this->checkBoxParkStatusOff->Text = L"Neaktívne";
			this->checkBoxParkStatusOff->UseVisualStyleBackColor = true;
			this->checkBoxParkStatusOff->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxParkStatusOff_CheckedChanged);
			// 
			// checkBoxParkStatusOn
			// 
			this->checkBoxParkStatusOn->AutoSize = true;
			this->checkBoxParkStatusOn->Location = System::Drawing::Point(91, 66);
			this->checkBoxParkStatusOn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBoxParkStatusOn->Name = L"checkBoxParkStatusOn";
			this->checkBoxParkStatusOn->Size = System::Drawing::Size(85, 24);
			this->checkBoxParkStatusOn->TabIndex = 3;
			this->checkBoxParkStatusOn->Text = L"Aktívne";
			this->checkBoxParkStatusOn->UseVisualStyleBackColor = true;
			this->checkBoxParkStatusOn->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxParkStatusOn_CheckedChanged);
			// 
			// labelTitleChangeParkStatus
			// 
			this->labelTitleChangeParkStatus->AutoSize = true;
			this->labelTitleChangeParkStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelTitleChangeParkStatus->Location = System::Drawing::Point(100, 22);
			this->labelTitleChangeParkStatus->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleChangeParkStatus->Name = L"labelTitleChangeParkStatus";
			this->labelTitleChangeParkStatus->Size = System::Drawing::Size(233, 24);
			this->labelTitleChangeParkStatus->TabIndex = 0;
			this->labelTitleChangeParkStatus->Text = L"Zmena stavu parkoviska";
			// 
			// buttonConfirmChangeParkStatus
			// 
			this->buttonConfirmChangeParkStatus->Location = System::Drawing::Point(13, 110);
			this->buttonConfirmChangeParkStatus->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->buttonConfirmChangeParkStatus->Name = L"buttonConfirmChangeParkStatus";
			this->buttonConfirmChangeParkStatus->Size = System::Drawing::Size(431, 28);
			this->buttonConfirmChangeParkStatus->TabIndex = 2;
			this->buttonConfirmChangeParkStatus->Text = L"Povrdiť";
			this->buttonConfirmChangeParkStatus->UseVisualStyleBackColor = true;
			this->buttonConfirmChangeParkStatus->Click += gcnew System::EventHandler(this, &MyForm::buttonConfirmChangeParkStatus_Click);
			// 
			// groupBoxNewParkAdress
			// 
			this->groupBoxNewParkAdress->Controls->Add(this->labelTitleNewParkAdress);
			this->groupBoxNewParkAdress->Controls->Add(this->buttonConfirmParkAdressChange);
			this->groupBoxNewParkAdress->Controls->Add(this->textBoxNewParkAdress);
			this->groupBoxNewParkAdress->Location = System::Drawing::Point(8, 112);
			this->groupBoxNewParkAdress->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxNewParkAdress->Name = L"groupBoxNewParkAdress";
			this->groupBoxNewParkAdress->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxNewParkAdress->Size = System::Drawing::Size(451, 90);
			this->groupBoxNewParkAdress->TabIndex = 4;
			this->groupBoxNewParkAdress->TabStop = false;
			// 
			// labelTitleNewParkAdress
			// 
			this->labelTitleNewParkAdress->AutoSize = true;
			this->labelTitleNewParkAdress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelTitleNewParkAdress->Location = System::Drawing::Point(8, 20);
			this->labelTitleNewParkAdress->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleNewParkAdress->Name = L"labelTitleNewParkAdress";
			this->labelTitleNewParkAdress->Size = System::Drawing::Size(133, 24);
			this->labelTitleNewParkAdress->TabIndex = 0;
			this->labelTitleNewParkAdress->Text = L"Nová adresa:";
			// 
			// buttonConfirmParkAdressChange
			// 
			this->buttonConfirmParkAdressChange->Location = System::Drawing::Point(12, 50);
			this->buttonConfirmParkAdressChange->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->buttonConfirmParkAdressChange->Name = L"buttonConfirmParkAdressChange";
			this->buttonConfirmParkAdressChange->Size = System::Drawing::Size(431, 28);
			this->buttonConfirmParkAdressChange->TabIndex = 2;
			this->buttonConfirmParkAdressChange->Text = L"Povrdiť";
			this->buttonConfirmParkAdressChange->UseVisualStyleBackColor = true;
			this->buttonConfirmParkAdressChange->Click += gcnew System::EventHandler(this, &MyForm::buttonConfirmParkAdressChange_Click);
			// 
			// textBoxNewParkAdress
			// 
			this->textBoxNewParkAdress->Location = System::Drawing::Point(155, 18);
			this->textBoxNewParkAdress->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxNewParkAdress->Name = L"textBoxNewParkAdress";
			this->textBoxNewParkAdress->Size = System::Drawing::Size(287, 26);
			this->textBoxNewParkAdress->TabIndex = 1;
			// 
			// groupBoxNewParkName
			// 
			this->groupBoxNewParkName->Controls->Add(this->labelTitleNewParkName);
			this->groupBoxNewParkName->Controls->Add(this->buttonConfirmParkNameChange);
			this->groupBoxNewParkName->Controls->Add(this->textBoxNewParkName);
			this->groupBoxNewParkName->Location = System::Drawing::Point(7, 15);
			this->groupBoxNewParkName->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxNewParkName->Name = L"groupBoxNewParkName";
			this->groupBoxNewParkName->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxNewParkName->Size = System::Drawing::Size(452, 90);
			this->groupBoxNewParkName->TabIndex = 3;
			this->groupBoxNewParkName->TabStop = false;
			// 
			// labelTitleNewParkName
			// 
			this->labelTitleNewParkName->AutoSize = true;
			this->labelTitleNewParkName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelTitleNewParkName->Location = System::Drawing::Point(8, 20);
			this->labelTitleNewParkName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleNewParkName->Name = L"labelTitleNewParkName";
			this->labelTitleNewParkName->Size = System::Drawing::Size(124, 24);
			this->labelTitleNewParkName->TabIndex = 0;
			this->labelTitleNewParkName->Text = L"Nový názov:";
			// 
			// buttonConfirmParkNameChange
			// 
			this->buttonConfirmParkNameChange->Location = System::Drawing::Point(12, 50);
			this->buttonConfirmParkNameChange->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->buttonConfirmParkNameChange->Name = L"buttonConfirmParkNameChange";
			this->buttonConfirmParkNameChange->Size = System::Drawing::Size(431, 28);
			this->buttonConfirmParkNameChange->TabIndex = 2;
			this->buttonConfirmParkNameChange->Text = L"Povrdiť";
			this->buttonConfirmParkNameChange->UseVisualStyleBackColor = true;
			this->buttonConfirmParkNameChange->Click += gcnew System::EventHandler(this, &MyForm::buttonConfirmParkNameChange_Click);
			// 
			// textBoxNewParkName
			// 
			this->textBoxNewParkName->Location = System::Drawing::Point(155, 18);
			this->textBoxNewParkName->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxNewParkName->Name = L"textBoxNewParkName";
			this->textBoxNewParkName->Size = System::Drawing::Size(287, 26);
			this->textBoxNewParkName->TabIndex = 1;
			// 
			// toolStripParkChanges
			// 
			this->toolStripParkChanges->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStripParkChanges->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
				this->toolStripButtonParkStatusChange,
					this->toolStripSeparator3, this->toolStripButtonChangeParkName, this->toolStripButtonChangeAdress, this->toolStripButtonChangeLatitude,
					this->toolStripButtonChangeLongtitude, this->toolStripSeparator4, this->toolStripButtonDeletePark, this->toolStripSeparator5,
					this->toolStripButtonLoadStalls
			});
			this->toolStripParkChanges->Location = System::Drawing::Point(4, 23);
			this->toolStripParkChanges->Name = L"toolStripParkChanges";
			this->toolStripParkChanges->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->toolStripParkChanges->Size = System::Drawing::Size(476, 27);
			this->toolStripParkChanges->TabIndex = 9;
			this->toolStripParkChanges->Text = L"toolStripParksTools";
			// 
			// toolStripButtonParkStatusChange
			// 
			this->toolStripButtonParkStatusChange->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonParkStatusChange->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonParkStatusChange.Image")));
			this->toolStripButtonParkStatusChange->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonParkStatusChange->Name = L"toolStripButtonParkStatusChange";
			this->toolStripButtonParkStatusChange->Size = System::Drawing::Size(24, 24);
			this->toolStripButtonParkStatusChange->Text = L"On/Off";
			this->toolStripButtonParkStatusChange->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonParkStatusChange_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(6, 27);
			// 
			// toolStripButtonChangeParkName
			// 
			this->toolStripButtonChangeParkName->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonChangeParkName->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonChangeParkName.Image")));
			this->toolStripButtonChangeParkName->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonChangeParkName->Name = L"toolStripButtonChangeParkName";
			this->toolStripButtonChangeParkName->Size = System::Drawing::Size(24, 24);
			this->toolStripButtonChangeParkName->Text = L"Zmena názvu";
			this->toolStripButtonChangeParkName->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonChangeParkName_Click);
			// 
			// toolStripButtonChangeAdress
			// 
			this->toolStripButtonChangeAdress->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonChangeAdress->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonChangeAdress.Image")));
			this->toolStripButtonChangeAdress->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonChangeAdress->Name = L"toolStripButtonChangeAdress";
			this->toolStripButtonChangeAdress->Size = System::Drawing::Size(24, 24);
			this->toolStripButtonChangeAdress->Text = L"Zmena adresy";
			this->toolStripButtonChangeAdress->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonChangeAdress_Click);
			// 
			// toolStripButtonChangeLatitude
			// 
			this->toolStripButtonChangeLatitude->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonChangeLatitude->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonChangeLatitude.Image")));
			this->toolStripButtonChangeLatitude->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonChangeLatitude->Name = L"toolStripButtonChangeLatitude";
			this->toolStripButtonChangeLatitude->Size = System::Drawing::Size(24, 24);
			this->toolStripButtonChangeLatitude->Text = L"toolStripButton1";
			this->toolStripButtonChangeLatitude->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonChangeLatitude_Click);
			// 
			// toolStripButtonChangeLongtitude
			// 
			this->toolStripButtonChangeLongtitude->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonChangeLongtitude->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonChangeLongtitude.Image")));
			this->toolStripButtonChangeLongtitude->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonChangeLongtitude->Name = L"toolStripButtonChangeLongtitude";
			this->toolStripButtonChangeLongtitude->Size = System::Drawing::Size(24, 24);
			this->toolStripButtonChangeLongtitude->Text = L"toolStripButton1";
			this->toolStripButtonChangeLongtitude->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonChangeLongtitude_Click);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(6, 27);
			// 
			// toolStripButtonDeletePark
			// 
			this->toolStripButtonDeletePark->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonDeletePark->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonDeletePark.Image")));
			this->toolStripButtonDeletePark->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonDeletePark->Name = L"toolStripButtonDeletePark";
			this->toolStripButtonDeletePark->Size = System::Drawing::Size(24, 24);
			this->toolStripButtonDeletePark->Text = L"Zmazať parkovisko";
			this->toolStripButtonDeletePark->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonDeletePark_Click);
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(6, 27);
			// 
			// toolStripButtonLoadStalls
			// 
			this->toolStripButtonLoadStalls->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonLoadStalls->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonLoadStalls.Image")));
			this->toolStripButtonLoadStalls->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonLoadStalls->Name = L"toolStripButtonLoadStalls";
			this->toolStripButtonLoadStalls->Size = System::Drawing::Size(24, 24);
			this->toolStripButtonLoadStalls->Text = L"Nahrat miesta";
			this->toolStripButtonLoadStalls->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonLoadStalls_Click);
			// 
			// labelParkInformationsCapacity
			// 
			this->labelParkInformationsCapacity->AutoSize = true;
			this->labelParkInformationsCapacity->Location = System::Drawing::Point(253, 164);
			this->labelParkInformationsCapacity->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelParkInformationsCapacity->Name = L"labelParkInformationsCapacity";
			this->labelParkInformationsCapacity->Size = System::Drawing::Size(74, 20);
			this->labelParkInformationsCapacity->TabIndex = 8;
			this->labelParkInformationsCapacity->Text = L"Kapacita";
			// 
			// labelTitleParkInformationsCapacity
			// 
			this->labelTitleParkInformationsCapacity->AutoSize = true;
			this->labelTitleParkInformationsCapacity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelTitleParkInformationsCapacity->Location = System::Drawing::Point(27, 164);
			this->labelTitleParkInformationsCapacity->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleParkInformationsCapacity->Name = L"labelTitleParkInformationsCapacity";
			this->labelTitleParkInformationsCapacity->Size = System::Drawing::Size(88, 20);
			this->labelTitleParkInformationsCapacity->TabIndex = 7;
			this->labelTitleParkInformationsCapacity->Text = L"Kapacita:";
			// 
			// labelParkInformationsAdress
			// 
			this->labelParkInformationsAdress->AutoSize = true;
			this->labelParkInformationsAdress->Location = System::Drawing::Point(253, 138);
			this->labelParkInformationsAdress->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelParkInformationsAdress->Name = L"labelParkInformationsAdress";
			this->labelParkInformationsAdress->Size = System::Drawing::Size(62, 20);
			this->labelParkInformationsAdress->TabIndex = 6;
			this->labelParkInformationsAdress->Text = L"Adresa";
			// 
			// labelTitleParkInformationsAdress
			// 
			this->labelTitleParkInformationsAdress->AutoSize = true;
			this->labelTitleParkInformationsAdress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelTitleParkInformationsAdress->Location = System::Drawing::Point(27, 138);
			this->labelTitleParkInformationsAdress->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleParkInformationsAdress->Name = L"labelTitleParkInformationsAdress";
			this->labelTitleParkInformationsAdress->Size = System::Drawing::Size(74, 20);
			this->labelTitleParkInformationsAdress->TabIndex = 5;
			this->labelTitleParkInformationsAdress->Text = L"Adresa:";
			// 
			// labelParkInformationsId
			// 
			this->labelParkInformationsId->AutoSize = true;
			this->labelParkInformationsId->Location = System::Drawing::Point(253, 90);
			this->labelParkInformationsId->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelParkInformationsId->Name = L"labelParkInformationsId";
			this->labelParkInformationsId->Size = System::Drawing::Size(22, 20);
			this->labelParkInformationsId->TabIndex = 4;
			this->labelParkInformationsId->Text = L"Id";
			// 
			// labelTitleParkInformationsId
			// 
			this->labelTitleParkInformationsId->AutoSize = true;
			this->labelTitleParkInformationsId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelTitleParkInformationsId->Location = System::Drawing::Point(27, 90);
			this->labelTitleParkInformationsId->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleParkInformationsId->Name = L"labelTitleParkInformationsId";
			this->labelTitleParkInformationsId->Size = System::Drawing::Size(30, 20);
			this->labelTitleParkInformationsId->TabIndex = 3;
			this->labelTitleParkInformationsId->Text = L"Id:";
			// 
			// labelParkInformationsName
			// 
			this->labelParkInformationsName->AutoSize = true;
			this->labelParkInformationsName->Location = System::Drawing::Point(253, 113);
			this->labelParkInformationsName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelParkInformationsName->Name = L"labelParkInformationsName";
			this->labelParkInformationsName->Size = System::Drawing::Size(50, 20);
			this->labelParkInformationsName->TabIndex = 2;
			this->labelParkInformationsName->Text = L"Meno";
			// 
			// labelTitleParkInformationsName
			// 
			this->labelTitleParkInformationsName->AutoSize = true;
			this->labelTitleParkInformationsName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelTitleParkInformationsName->Location = System::Drawing::Point(27, 113);
			this->labelTitleParkInformationsName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleParkInformationsName->Name = L"labelTitleParkInformationsName";
			this->labelTitleParkInformationsName->Size = System::Drawing::Size(67, 20);
			this->labelTitleParkInformationsName->TabIndex = 1;
			this->labelTitleParkInformationsName->Text = L"Názov:";
			// 
			// labelTitleInformationsAboutParking
			// 
			this->labelTitleInformationsAboutParking->AutoSize = true;
			this->labelTitleInformationsAboutParking->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelTitleInformationsAboutParking->Location = System::Drawing::Point(47, 20);
			this->labelTitleInformationsAboutParking->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleInformationsAboutParking->Name = L"labelTitleInformationsAboutParking";
			this->labelTitleInformationsAboutParking->Size = System::Drawing::Size(352, 36);
			this->labelTitleInformationsAboutParking->TabIndex = 0;
			this->labelTitleInformationsAboutParking->Text = L"Informácie o parkovisku";
			// 
			// listViewParkList
			// 
			this->listViewParkList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeaderId,
					this->columnHeaderName, this->columnHeaderStatus
			});
			this->listViewParkList->FullRowSelect = true;
			this->listViewParkList->GridLines = true;
			this->listViewParkList->HideSelection = false;
			this->listViewParkList->Location = System::Drawing::Point(9, 54);
			this->listViewParkList->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->listViewParkList->Name = L"listViewParkList";
			this->listViewParkList->Size = System::Drawing::Size(643, 648);
			this->listViewParkList->TabIndex = 0;
			this->listViewParkList->UseCompatibleStateImageBehavior = false;
			this->listViewParkList->View = System::Windows::Forms::View::Details;
			this->listViewParkList->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listViewParkList_SelectedIndexChanged);
			this->listViewParkList->DoubleClick += gcnew System::EventHandler(this, &MyForm::listViewParkList_DoubleClick);
			// 
			// columnHeaderId
			// 
			this->columnHeaderId->Text = L"Id";
			this->columnHeaderId->Width = 49;
			// 
			// columnHeaderName
			// 
			this->columnHeaderName->Text = L"Názov parkoviska";
			this->columnHeaderName->Width = 333;
			// 
			// columnHeaderStatus
			// 
			this->columnHeaderStatus->Text = L"Stav";
			this->columnHeaderStatus->Width = 96;
			// 
			// timerSync
			// 
			this->timerSync->Interval = 3000;
			this->timerSync->Tick += gcnew System::EventHandler(this, &MyForm::timerSync_Tick);
			// 
			// timerStallsSync
			// 
			this->timerStallsSync->Interval = 5000;
			this->timerStallsSync->Tick += gcnew System::EventHandler(this, &MyForm::timerStallsSync_Tick);
			// 
			// toolStripStallsConfig
			// 
			this->toolStripStallsConfig->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStripStallsConfig->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolStripButtonAddStall,
					this->toolStripSeparator2, this->toolStripButtonShowStallsInTime, this->toolStripButtonShowStallsCurrentTime
			});
			this->toolStripStallsConfig->Location = System::Drawing::Point(0, 28);
			this->toolStripStallsConfig->Name = L"toolStripStallsConfig";
			this->toolStripStallsConfig->Size = System::Drawing::Size(1561, 27);
			this->toolStripStallsConfig->TabIndex = 3;
			// 
			// toolStripButtonAddStall
			// 
			this->toolStripButtonAddStall->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonAddStall->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonAddStall.Image")));
			this->toolStripButtonAddStall->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonAddStall->Name = L"toolStripButtonAddStall";
			this->toolStripButtonAddStall->Size = System::Drawing::Size(24, 24);
			this->toolStripButtonAddStall->Text = L"Pridať miesto";
			this->toolStripButtonAddStall->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonAddStall_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 27);
			// 
			// toolStripButtonShowStallsInTime
			// 
			this->toolStripButtonShowStallsInTime->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonShowStallsInTime->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonShowStallsInTime.Image")));
			this->toolStripButtonShowStallsInTime->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonShowStallsInTime->Name = L"toolStripButtonShowStallsInTime";
			this->toolStripButtonShowStallsInTime->Size = System::Drawing::Size(24, 24);
			this->toolStripButtonShowStallsInTime->Text = L"toolStripButton1";
			this->toolStripButtonShowStallsInTime->ToolTipText = L"Zobraziť miesta v čase";
			this->toolStripButtonShowStallsInTime->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonShowStallsInTime_Click);
			// 
			// toolStripButtonShowStallsCurrentTime
			// 
			this->toolStripButtonShowStallsCurrentTime->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonShowStallsCurrentTime->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonShowStallsCurrentTime.Image")));
			this->toolStripButtonShowStallsCurrentTime->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonShowStallsCurrentTime->Name = L"toolStripButtonShowStallsCurrentTime";
			this->toolStripButtonShowStallsCurrentTime->Size = System::Drawing::Size(24, 24);
			this->toolStripButtonShowStallsCurrentTime->Text = L"Zobraziť miesta aktuálne";
			this->toolStripButtonShowStallsCurrentTime->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonShowStallsCurrentTime_Click);
			// 
			// listViewDeletedStalls
			// 
			this->listViewDeletedStalls->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->stallId,
					this->parkId, this->stallState, this->stallType, this->x, this->y
			});
			this->listViewDeletedStalls->FullRowSelect = true;
			this->listViewDeletedStalls->GridLines = true;
			this->listViewDeletedStalls->HideSelection = false;
			this->listViewDeletedStalls->Location = System::Drawing::Point(17, 57);
			this->listViewDeletedStalls->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->listViewDeletedStalls->Name = L"listViewDeletedStalls";
			this->listViewDeletedStalls->Size = System::Drawing::Size(728, 643);
			this->listViewDeletedStalls->TabIndex = 0;
			this->listViewDeletedStalls->UseCompatibleStateImageBehavior = false;
			this->listViewDeletedStalls->View = System::Windows::Forms::View::Details;
			// 
			// stallId
			// 
			this->stallId->Text = L"Id miesta";
			this->stallId->Width = 90;
			// 
			// parkId
			// 
			this->parkId->Text = L"Id parkoviska";
			this->parkId->Width = 90;
			// 
			// stallState
			// 
			this->stallState->Text = L"Stav miesta";
			this->stallState->Width = 90;
			// 
			// stallType
			// 
			this->stallType->Text = L"Typ miesta";
			this->stallType->Width = 90;
			// 
			// x
			// 
			this->x->Text = L"Súradnica X";
			this->x->Width = 90;
			// 
			// y
			// 
			this->y->Text = L"Súradnica Y";
			this->y->Width = 90;
			// 
			// toolStripDeletedStalls
			// 
			this->toolStripDeletedStalls->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStripDeletedStalls->Location = System::Drawing::Point(4, 19);
			this->toolStripDeletedStalls->Name = L"toolStripDeletedStalls";
			this->toolStripDeletedStalls->Size = System::Drawing::Size(1553, 25);
			this->toolStripDeletedStalls->TabIndex = 1;
			this->toolStripDeletedStalls->Text = L"toolStrip2";
			// 
			// groupBoxSearchingDeletedStalls
			// 
			this->groupBoxSearchingDeletedStalls->Controls->Add(this->textBoxSearchingWordDeletedStalls);
			this->groupBoxSearchingDeletedStalls->Controls->Add(this->checkBoxSearchInDeletedStallsStallY);
			this->groupBoxSearchingDeletedStalls->Controls->Add(this->checkBoxSearchInDeletedStallsStallX);
			this->groupBoxSearchingDeletedStalls->Controls->Add(this->checkBoxSearchInDeletedStallsParkId);
			this->groupBoxSearchingDeletedStalls->Controls->Add(this->checkBoxSearchInDeletedStallsStallId);
			this->groupBoxSearchingDeletedStalls->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->groupBoxSearchingDeletedStalls->Location = System::Drawing::Point(844, 62);
			this->groupBoxSearchingDeletedStalls->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxSearchingDeletedStalls->Name = L"groupBoxSearchingDeletedStalls";
			this->groupBoxSearchingDeletedStalls->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxSearchingDeletedStalls->Size = System::Drawing::Size(567, 139);
			this->groupBoxSearchingDeletedStalls->TabIndex = 2;
			this->groupBoxSearchingDeletedStalls->TabStop = false;
			this->groupBoxSearchingDeletedStalls->Text = L"Vyhladávanie";
			// 
			// textBoxSearchingWordDeletedStalls
			// 
			this->textBoxSearchingWordDeletedStalls->Location = System::Drawing::Point(12, 91);
			this->textBoxSearchingWordDeletedStalls->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBoxSearchingWordDeletedStalls->Name = L"textBoxSearchingWordDeletedStalls";
			this->textBoxSearchingWordDeletedStalls->Size = System::Drawing::Size(533, 29);
			this->textBoxSearchingWordDeletedStalls->TabIndex = 6;
			this->textBoxSearchingWordDeletedStalls->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxSearchingWordDeletedStalls_TextChanged);
			// 
			// checkBoxSearchInDeletedStallsStallY
			// 
			this->checkBoxSearchInDeletedStallsStallY->AutoSize = true;
			this->checkBoxSearchInDeletedStallsStallY->Location = System::Drawing::Point(339, 50);
			this->checkBoxSearchInDeletedStallsStallY->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBoxSearchInDeletedStallsStallY->Name = L"checkBoxSearchInDeletedStallsStallY";
			this->checkBoxSearchInDeletedStallsStallY->Size = System::Drawing::Size(134, 28);
			this->checkBoxSearchInDeletedStallsStallY->TabIndex = 5;
			this->checkBoxSearchInDeletedStallsStallY->Text = L"Súradnica Y";
			this->checkBoxSearchInDeletedStallsStallY->UseVisualStyleBackColor = true;
			this->checkBoxSearchInDeletedStallsStallY->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxSearchInDeletedStallsStallY_CheckedChanged);
			// 
			// checkBoxSearchInDeletedStallsStallX
			// 
			this->checkBoxSearchInDeletedStallsStallX->AutoSize = true;
			this->checkBoxSearchInDeletedStallsStallX->Location = System::Drawing::Point(337, 23);
			this->checkBoxSearchInDeletedStallsStallX->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBoxSearchInDeletedStallsStallX->Name = L"checkBoxSearchInDeletedStallsStallX";
			this->checkBoxSearchInDeletedStallsStallX->Size = System::Drawing::Size(136, 28);
			this->checkBoxSearchInDeletedStallsStallX->TabIndex = 4;
			this->checkBoxSearchInDeletedStallsStallX->Text = L"Súradnica X";
			this->checkBoxSearchInDeletedStallsStallX->UseVisualStyleBackColor = true;
			this->checkBoxSearchInDeletedStallsStallX->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxSearchInDeletedStallsStallX_CheckedChanged);
			// 
			// checkBoxSearchInDeletedStallsParkId
			// 
			this->checkBoxSearchInDeletedStallsParkId->AutoSize = true;
			this->checkBoxSearchInDeletedStallsParkId->Location = System::Drawing::Point(76, 50);
			this->checkBoxSearchInDeletedStallsParkId->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBoxSearchInDeletedStallsParkId->Name = L"checkBoxSearchInDeletedStallsParkId";
			this->checkBoxSearchInDeletedStallsParkId->Size = System::Drawing::Size(140, 28);
			this->checkBoxSearchInDeletedStallsParkId->TabIndex = 1;
			this->checkBoxSearchInDeletedStallsParkId->Text = L"Id parkoviska";
			this->checkBoxSearchInDeletedStallsParkId->UseVisualStyleBackColor = true;
			this->checkBoxSearchInDeletedStallsParkId->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxSearchInDeletedStallsParkId_CheckedChanged);
			// 
			// checkBoxSearchInDeletedStallsStallId
			// 
			this->checkBoxSearchInDeletedStallsStallId->AutoSize = true;
			this->checkBoxSearchInDeletedStallsStallId->Checked = true;
			this->checkBoxSearchInDeletedStallsStallId->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxSearchInDeletedStallsStallId->Location = System::Drawing::Point(76, 23);
			this->checkBoxSearchInDeletedStallsStallId->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBoxSearchInDeletedStallsStallId->Name = L"checkBoxSearchInDeletedStallsStallId";
			this->checkBoxSearchInDeletedStallsStallId->Size = System::Drawing::Size(106, 28);
			this->checkBoxSearchInDeletedStallsStallId->TabIndex = 0;
			this->checkBoxSearchInDeletedStallsStallId->Text = L"Id miesta";
			this->checkBoxSearchInDeletedStallsStallId->UseVisualStyleBackColor = true;
			this->checkBoxSearchInDeletedStallsStallId->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxSearchInDeletedStallsStallId_CheckedChanged);
			// 
			// groupBoxDeletedStalls
			// 
			this->groupBoxDeletedStalls->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxDeletedStalls->Controls->Add(this->groupBoxSearchingDeletedStalls);
			this->groupBoxDeletedStalls->Controls->Add(this->toolStripDeletedStalls);
			this->groupBoxDeletedStalls->Controls->Add(this->listViewDeletedStalls);
			this->groupBoxDeletedStalls->Location = System::Drawing::Point(0, 30);
			this->groupBoxDeletedStalls->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxDeletedStalls->Name = L"groupBoxDeletedStalls";
			this->groupBoxDeletedStalls->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBoxDeletedStalls->Size = System::Drawing::Size(1561, 719);
			this->groupBoxDeletedStalls->TabIndex = 3;
			this->groupBoxDeletedStalls->TabStop = false;
			// 
			// buttonStallsPrintPageLeft
			// 
			this->buttonStallsPrintPageLeft->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->buttonStallsPrintPageLeft->FlatAppearance->BorderSize = 0;
			this->buttonStallsPrintPageLeft->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonStallsPrintPageLeft->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->buttonStallsPrintPageLeft->Location = System::Drawing::Point(16, 368);
			this->buttonStallsPrintPageLeft->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->buttonStallsPrintPageLeft->Name = L"buttonStallsPrintPageLeft";
			this->buttonStallsPrintPageLeft->Size = System::Drawing::Size(47, 59);
			this->buttonStallsPrintPageLeft->TabIndex = 19;
			this->buttonStallsPrintPageLeft->Text = L"←";
			this->buttonStallsPrintPageLeft->UseVisualStyleBackColor = true;
			this->buttonStallsPrintPageLeft->Click += gcnew System::EventHandler(this, &MyForm::buttonStallsPrintPageLeft_Click);
			// 
			// buttonStallsPrintPageRight
			// 
			this->buttonStallsPrintPageRight->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->buttonStallsPrintPageRight->FlatAppearance->BorderSize = 0;
			this->buttonStallsPrintPageRight->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonStallsPrintPageRight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->buttonStallsPrintPageRight->Location = System::Drawing::Point(1125, 372);
			this->buttonStallsPrintPageRight->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->buttonStallsPrintPageRight->Name = L"buttonStallsPrintPageRight";
			this->buttonStallsPrintPageRight->Size = System::Drawing::Size(47, 53);
			this->buttonStallsPrintPageRight->TabIndex = 20;
			this->buttonStallsPrintPageRight->Text = L"→";
			this->buttonStallsPrintPageRight->UseVisualStyleBackColor = true;
			this->buttonStallsPrintPageRight->Click += gcnew System::EventHandler(this, &MyForm::buttonStallsPrintPageRight_Click);
			// 
			// buttonStallsPrintPageDown
			// 
			this->buttonStallsPrintPageDown->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->buttonStallsPrintPageDown->FlatAppearance->BorderSize = 0;
			this->buttonStallsPrintPageDown->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonStallsPrintPageDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->buttonStallsPrintPageDown->ForeColor = System::Drawing::SystemColors::ControlText;
			this->buttonStallsPrintPageDown->Location = System::Drawing::Point(617, 694);
			this->buttonStallsPrintPageDown->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->buttonStallsPrintPageDown->Name = L"buttonStallsPrintPageDown";
			this->buttonStallsPrintPageDown->Size = System::Drawing::Size(64, 43);
			this->buttonStallsPrintPageDown->TabIndex = 21;
			this->buttonStallsPrintPageDown->Text = L"↓";
			this->buttonStallsPrintPageDown->UseVisualStyleBackColor = true;
			this->buttonStallsPrintPageDown->Click += gcnew System::EventHandler(this, &MyForm::buttonStallsPrintPageDown_Click);
			// 
			// buttonStallsPrintPageUp
			// 
			this->buttonStallsPrintPageUp->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->buttonStallsPrintPageUp->FlatAppearance->BorderSize = 0;
			this->buttonStallsPrintPageUp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonStallsPrintPageUp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->buttonStallsPrintPageUp->ForeColor = System::Drawing::SystemColors::ControlText;
			this->buttonStallsPrintPageUp->Location = System::Drawing::Point(617, 64);
			this->buttonStallsPrintPageUp->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->buttonStallsPrintPageUp->Name = L"buttonStallsPrintPageUp";
			this->buttonStallsPrintPageUp->Size = System::Drawing::Size(64, 43);
			this->buttonStallsPrintPageUp->TabIndex = 22;
			this->buttonStallsPrintPageUp->Text = L"↑";
			this->buttonStallsPrintPageUp->UseVisualStyleBackColor = true;
			this->buttonStallsPrintPageUp->Click += gcnew System::EventHandler(this, &MyForm::buttonStallsPrintPageUp_Click);
			// 
			// labelTitleShowingStallTime
			// 
			this->labelTitleShowingStallTime->AutoSize = true;
			this->labelTitleShowingStallTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelTitleShowingStallTime->Location = System::Drawing::Point(16, 82);
			this->labelTitleShowingStallTime->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitleShowingStallTime->Name = L"labelTitleShowingStallTime";
			this->labelTitleShowingStallTime->Size = System::Drawing::Size(161, 25);
			this->labelTitleShowingStallTime->TabIndex = 23;
			this->labelTitleShowingStallTime->Text = L"Zobrazený čas:";
			// 
			// labelShowingStallTime
			// 
			this->labelShowingStallTime->AutoSize = true;
			this->labelShowingStallTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->labelShowingStallTime->Location = System::Drawing::Point(199, 82);
			this->labelShowingStallTime->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelShowingStallTime->Name = L"labelShowingStallTime";
			this->labelShowingStallTime->Size = System::Drawing::Size(89, 25);
			this->labelShowingStallTime->TabIndex = 24;
			this->labelShowingStallTime->Text = L"Aktuálne";
			// 
			// dateTimePickerShowStallsTime
			// 
			this->dateTimePickerShowStallsTime->CustomFormat = L"dd.MMMM.yyyy         hh:mm:ss";
			this->dateTimePickerShowStallsTime->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePickerShowStallsTime->Location = System::Drawing::Point(199, 82);
			this->dateTimePickerShowStallsTime->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dateTimePickerShowStallsTime->MaxDate = System::DateTime(2099, 12, 31, 0, 0, 0, 0);
			this->dateTimePickerShowStallsTime->MinDate = System::DateTime(2019, 1, 1, 0, 0, 0, 0);
			this->dateTimePickerShowStallsTime->Name = L"dateTimePickerShowStallsTime";
			this->dateTimePickerShowStallsTime->Size = System::Drawing::Size(265, 22);
			this->dateTimePickerShowStallsTime->TabIndex = 25;
			// 
			// buttonConfirmStallsShowingTime
			// 
			this->buttonConfirmStallsShowingTime->Location = System::Drawing::Point(473, 79);
			this->buttonConfirmStallsShowingTime->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->buttonConfirmStallsShowingTime->Name = L"buttonConfirmStallsShowingTime";
			this->buttonConfirmStallsShowingTime->Size = System::Drawing::Size(69, 32);
			this->buttonConfirmStallsShowingTime->TabIndex = 26;
			this->buttonConfirmStallsShowingTime->Text = L"Potvrdiť";
			this->buttonConfirmStallsShowingTime->UseVisualStyleBackColor = true;
			this->buttonConfirmStallsShowingTime->Click += gcnew System::EventHandler(this, &MyForm::buttonConfirmStallsShowingTime_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1561, 752);
			this->Controls->Add(this->buttonConfirmStallsShowingTime);
			this->Controls->Add(this->dateTimePickerShowStallsTime);
			this->Controls->Add(this->labelShowingStallTime);
			this->Controls->Add(this->labelTitleShowingStallTime);
			this->Controls->Add(this->buttonStallsPrintPageUp);
			this->Controls->Add(this->buttonStallsPrintPageDown);
			this->Controls->Add(this->buttonStallsPrintPageRight);
			this->Controls->Add(this->buttonStallsPrintPageLeft);
			this->Controls->Add(this->toolStripStallsConfig);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->groupBoxTools);
			this->Controls->Add(this->groupBoxAddStall);
			this->Controls->Add(this->groupBoxParkList);
			this->Controls->Add(this->groupBoxDeletedStalls);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Parking";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBoxTools->ResumeLayout(false);
			this->groupBoxTools->PerformLayout();
			this->groupBoxReservationInformations->ResumeLayout(false);
			this->groupBoxReservationInformations->PerformLayout();
			this->toolStripStallSetting->ResumeLayout(false);
			this->toolStripStallSetting->PerformLayout();
			this->groupBoxChangeStallType->ResumeLayout(false);
			this->groupBoxChangeStallType->PerformLayout();
			this->groupBoxAddStall->ResumeLayout(false);
			this->groupBoxAddStall->PerformLayout();
			this->groupBoxParkList->ResumeLayout(false);
			this->groupBoxParkList->PerformLayout();
			this->groupBoxSearchInParks->ResumeLayout(false);
			this->groupBoxSearchInParks->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->groupBoxInformationsAboutParking->ResumeLayout(false);
			this->groupBoxInformationsAboutParking->PerformLayout();
			this->groupBoxParkChanges->ResumeLayout(false);
			this->groupBoxNewParkLongtitude->ResumeLayout(false);
			this->groupBoxNewParkLongtitude->PerformLayout();
			this->groupBoxNewParkLatitude->ResumeLayout(false);
			this->groupBoxNewParkLatitude->PerformLayout();
			this->groupBoxChangeParkStatus->ResumeLayout(false);
			this->groupBoxChangeParkStatus->PerformLayout();
			this->groupBoxNewParkAdress->ResumeLayout(false);
			this->groupBoxNewParkAdress->PerformLayout();
			this->groupBoxNewParkName->ResumeLayout(false);
			this->groupBoxNewParkName->PerformLayout();
			this->toolStripParkChanges->ResumeLayout(false);
			this->toolStripParkChanges->PerformLayout();
			this->toolStripStallsConfig->ResumeLayout(false);
			this->toolStripStallsConfig->PerformLayout();
			this->groupBoxSearchingDeletedStalls->ResumeLayout(false);
			this->groupBoxSearchingDeletedStalls->PerformLayout();
			this->groupBoxDeletedStalls->ResumeLayout(false);
			this->groupBoxDeletedStalls->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	this->groupBoxTools->Hide();
	this->readDataFromINI();

	mainSystem = new MainSystem();

	if (mainSystem->connectToDatabase() == true) {
		MessageBox::Show("Pripojenie k databáze prebehlo úspešne.");

		//START TIMER FOR SYNCHRONIZATION
		mainSystem->setSyncVersionsInApk(mainSystem->loadCurrentSynchVersion(LOAD_CURRENT_SYNC_VER));		
		mainSystem->loadAllTimestamps();
		mainSystem->loadDataForStallSync();

		std::vector<Park*> *parks = mainSystem->loadParksFromDatabase(LOAD_PARKS_NOT_DELETED);
		this->printParks(parks);
		this->currentScreen = NOT_DELETED_PARKS_SCREEN;
		this->showedStalls = SHOW_STALLS_CURRENT_TIME;

		this->groupBoxNewParkName->Visible = false;
		this->groupBoxNewParkAdress->Visible = false;
		this->groupBoxTools->Hide();
		this->groupBoxChangeStallType->Enabled = false;
		this->groupBoxAddStall->Visible = false;
		this->groupBoxInformationsAboutParking->Visible = false;
		this->groupBoxDeletedStalls->Visible = false;
		this->groupBoxChangeParkStatus->Visible = false;
		this->groupBoxNewParkLatitude->Visible = false;
		this->groupBoxNewParkLongtitude->Visible = false;
		this->toolStripStallsConfig->Visible = false;
		this->timerSync->Enabled = true;

		this->labelTitleShowingStallTime->Visible = false;
		this->labelShowingStallTime->Visible = false;
		this->dateTimePickerShowStallsTime->Visible = false;
		this->buttonConfirmStallsShowingTime->Visible = false;
		this->toolStripButtonShowStallsCurrentTime->Enabled = false;

		this->buttonStallsPrintPageLeft->Visible = false;
		this->buttonStallsPrintPageRight->Visible = false;
		this->buttonStallsPrintPageUp->Visible = false;
		this->buttonStallsPrintPageDown->Visible = false;

		this->currentStartScreenPositionX = 0;
		this->currentStartScreenPositionY = 0;
	} else {
		MessageBox::Show("Pripojenie k databáze sa nezdarilo.");
		Application::Exit();
	}
}

private: System::Void button_Click(Object^ sender, System::EventArgs^ e) {	
	this->groupBoxTools->Show();
	this->groupBoxChangeStallType->Enabled = false;
	this->groupBoxAddStall->Visible = false;
	this->groupBoxTools->Visible = true;
	
	std::string objectText = msclr::interop::marshal_as<std::string>(sender->ToString());
	std::string idString = objectText.substr(35); // 35 is offset for text before ID
	int stallId = std::stoi(idString);
	int parkId = mainSystem->getCurrentPark()->getParkoId();
	
	this->showStallInformations(stallId, parkId);

	if (this->labelStallStatus->Text != "Obsadené"  && this->currentShowStalls != SHOW_STALLS_CHOSED_TIME) {
		this->toolStripButtonChangeStallType->Enabled = true;
		this->toolStripButtonDeleteStall->Enabled = true;
	}
	else {
		this->toolStripButtonChangeStallType->Enabled = false;
		this->toolStripButtonDeleteStall->Enabled = false;
	}
}

private: System::Void listViewParkList_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
	//CUSTOM SETTINGS
	this->labelTitleShowingStallTime->Visible = true;
	this->labelShowingStallTime->Visible = true;
	this->toolStripButtonShowStallsCurrentTime->Enabled = false;
	this->toolStripButtonShowStallsInTime->Enabled = true;
	this->currentShowStalls = SHOW_STALLS_CURRENT_TIME;

	currentStartScreenPositionX = 0;
	currentStartScreenPositionY = 0;

	if (this->showedStalls == false) {
		this->showedStalls = true;
	}
	
	this->groupBoxParkList->Hide();

	//SET WINDOW TO FULL SCREEN
	this->WindowState = FormWindowState::Maximized;
	this->MaximizeBox = false;

	//READING FROM LISTVIEW
	std::string currId = msclr::interop::marshal_as<std::string>(listViewParkList->SelectedItems[0]->SubItems[0]->Text);
	int id = std::stoi(currId);

	//LOAD SYNC DATA
	Park_StallSync *currentPark = mainSystem->getParksData()->find(id)->second; 
	int syncVersion = mainSystem->loadIntegerFromDatabase(LOAD_CURRENT_SYNC_VER_STALLS(currId));
	currentPark->setVersion(syncVersion);
	mainSystem->setCurrentPark(currentPark);

	this->printStallsFromRange(STALLS_SHIFT_DIRECTION_HERE);
	this->toolStripStallsConfig->Visible = true;

	//TIMER FOR STALLS SYNC ENABLED
	this->timerStallsSync->Enabled = true;

	this->currentScreen = STALLS_SCREEN;

	//SHOW PAGE ARROWS
	this->buttonStallsPrintPageLeft->Visible = true;
	this->buttonStallsPrintPageRight->Visible = true;
	this->buttonStallsPrintPageUp->Visible = true;
	this->buttonStallsPrintPageDown->Visible = true;
}

private: System::Void timerSync_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->timerCountValue += timerSync->Interval;

	int currentSyncVersion = mainSystem->loadCurrentSynchVersion(LOAD_CURRENT_SYNC_VER);
	if (currentSyncVersion != LOAD_VERSION_ERROR) {
		if (currentSyncVersion != mainSystem->getSynchVersionInAPK()) {
			this->synchronization();
			mainSystem->setSyncVersionsInApk(currentSyncVersion);
		}

		//AUTO STALL COORDINATION
		if (currentSyncVersion != -1) {
			if (this->coordinateStallsTime != 0) {
				double checkCoeficient = (double)timerCountValue / (double)coordinateStallsTime;
				if (checkCoeficient > 1) {
					mainSystem->automaticCoordinateStalls();
					this->timerCountValue = 0;
				}
			}
		}
	}
}

private: System::Void timerStallsSync_Tick(System::Object^  sender, System::EventArgs^  e) {
	int currentParkId = mainSystem->getCurrentPark()->getParkoId();
	std::string parkIdS = std::to_string(currentParkId);
	int currentSyncVersionApk = mainSystem->getCurrentPark()->getVersion();
	int currentSyncVersion = mainSystem->loadCurrentSynchVersion(LOAD_CURRENT_SYNC_VER_STALLS(parkIdS));
	if (currentSyncVersion != LOAD_VERSION_ERROR) {
		if (currentSyncVersion != currentSyncVersionApk) {
			this->synchronizationStalls(currentParkId);
			mainSystem->getCurrentPark()->setVersion(currentSyncVersion);
		}
	}
}

private: System::Void listViewParkList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	this->groupBoxNewParkName->Visible = false;
	this->groupBoxNewParkAdress->Visible = false;
	this->groupBoxChangeParkStatus->Visible = false;
	this->groupBoxNewParkLatitude->Visible = false;
	this->groupBoxNewParkLongtitude->Visible = false;
	if (this->currentScreen == DELETED_PARKS_SCREEN) {
		buttonParkRecover->Visible = true;
		toolStripButtonDeletePark->Enabled = false;
	}
	else {
		buttonParkRecover->Visible = false;
		toolStripButtonDeletePark->Enabled = true;
	}
	this->showParkingInformations();
}
private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {
	AddPark^ addPark = gcnew AddPark();
	addPark->ShowDialog();

	if (addPark->getParkAdded() == true) {
		std::string name = msclr::interop::marshal_as<std::string>(addPark->getNameFromTextBox());
		std::string adress = msclr::interop::marshal_as<std::string>(addPark->getAdressFromTextBox());
		int capacity = std::stoi(msclr::interop::marshal_as<std::string>(addPark->getCapacityFromTextBox()));
		std::string parkX = msclr::interop::marshal_as<std::string>(addPark->getXFromTextBox());
		std::string parkY = msclr::interop::marshal_as<std::string>(addPark->getYFromTextBox());
		std::string parkId = std::to_string(mainSystem->loadIntegerFromDatabase(LOAD_MAX_ID_FROM_PARKS) + 1);
		if (mainSystem->addPark(parkId, name, adress, capacity, parkX, parkY) == true) {
			std::vector<Stall*> *newStalls = addPark->getNewStalls();
				std::string sql = INSERT_STALL_SYNC_DATA(parkId);
				if (mainSystem->doUpdate(sql) == true) {
					//ADD data to SYNC_VERZIE_P_MIESTA for park
					System::String ^ numberOfSuccesAddedStalls = gcnew String((std::to_string(mainSystem->addStallsToPark(parkId, newStalls, 0)).c_str()));
					//UPDATE SYNC DATA FOR STALLS IN APK
					oracle::occi::Timestamp timestamp = mainSystem->loadTimestampFromDatabase(LOAD_STALLS_UPDATE_TIMESTAMP(parkId));
					oracle::occi::Timestamp timestampInsert = mainSystem->loadTimestampFromDatabase(LOAD_STALLS_INSERT_TIMESTAMP(parkId));
					Park_StallSync *newParkData = new Park_StallSync(std::stoi(parkId), timestamp, timestampInsert);
					mainSystem->getParksData()->insert(std::make_pair(std::stoi(parkId), newParkData));
					MessageBox::Show("Parkovisko bolo úspešne pridané s poctom úspesne pridaných miest: " + numberOfSuccesAddedStalls + ".");
				}
				else {
					MessageBox::Show("Synchronizačné dáta sa nepodarilo pridať.");
				}

		}
		else {
			MessageBox::Show("Pridanie parkoviska sa nezdarilo.");
		}
	}
	delete addPark;
}

private: System::Void toolStripButtonChangeParkName_Click(System::Object^  sender, System::EventArgs^  e) {
	this->groupBoxNewParkLongtitude->Visible = false;
	this->groupBoxNewParkLatitude->Visible = false;
	this->groupBoxChangeParkStatus->Visible = false;
	this->groupBoxNewParkAdress->Visible = false;
	this->groupBoxNewParkName->Visible = true;
}
private: System::Void buttonConfirmParkNameChange_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string id = msclr::interop::marshal_as<std::string>(labelParkInformationsId->Text);
	std::string newName = msclr::interop::marshal_as<std::string>(textBoxNewParkName->Text);

	std::string sql = CHANGE_PARK_NAME(newName, id);
	if (mainSystem->doUpdate(sql) == true) {
		std::string sqlSync = CHANGE_TIMESTAMP_PR_PARKOVISKO_UPDATE_NOW;
		mainSystem->doUpdateSyncData(sqlSync);

		MessageBox::Show("Názov parkoviska úspešne zmenený.");
	}
	else {
		MessageBox::Show("Zmena mena sa nezdarila.");
	}
	this->groupBoxNewParkName->Visible = false;

}
private: System::Void buttonConfirmParkAdressChange_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string id = msclr::interop::marshal_as<std::string>(labelParkInformationsId->Text);
	std::string newAdress = msclr::interop::marshal_as<std::string>(textBoxNewParkAdress->Text);

	std::string sql = CHANGE_PARK_ADRESS(newAdress, id);
	if (mainSystem->doUpdate(sql) == true) {
		MessageBox::Show("Adresa parkoviska úspšene zmenená.");
	}
	else {
		MessageBox::Show("Zmena adresy sa nezdarila");
	}
	this->showParkingInformations();

	this->groupBoxNewParkAdress->Visible = false;
}
private: System::Void toolStripButtonChangeAdress_Click(System::Object^  sender, System::EventArgs^  e) {
	this->groupBoxNewParkLongtitude->Visible = false;
	this->groupBoxNewParkLatitude->Visible = false;
	this->groupBoxChangeParkStatus->Visible = false;
	this->groupBoxNewParkName->Visible = false;
	this->groupBoxNewParkAdress->Visible = true;
}
private: System::Void toolStripMenuItemParksList_Click(System::Object^  sender, System::EventArgs^  e) {
	//SET WINDOW SIZE TO NORMAL SIZE
	this->WindowState = FormWindowState::Normal;
	this->MaximizeBox = true;
	this->labelTitleShowingStallTime->Visible = false;
	this->labelShowingStallTime->Visible = false;
	this->dateTimePickerShowStallsTime->Visible = false;
	this->buttonConfirmStallsShowingTime->Visible = false;
	this->comboBoxParkSearchStatus->Visible = true;
	this->toolStripButtonParkStatusChange->Enabled = true;

	this->groupBoxDeletedStalls->Visible = false;

	this->hideStallsArrows();

	this->deleteStallsFromScreen();

	//TIMER FOR STALLS SYNC DISABLED
	this->timerStallsSync->Enabled = false;

	std::vector<Park*> *parks = mainSystem->loadParksFromDatabase(LOAD_PARKS_NOT_DELETED);
	if (parks != nullptr) {
		this->printParks(parks);
	}
	this->toolStripButtonAddPark->Enabled = true;
	this->groupBoxInformationsAboutParking->Visible = false;
	this->groupBoxParkList->Show();
	this->groupBoxTools->Hide();
	this->currentScreen = NOT_DELETED_PARKS_SCREEN;

	this->toolStripStallsConfig->Visible = false;

	this->groupBoxAddStall->Visible = false;
}
private: System::Void zoznamZmazanýchParkovískToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//SET WINDOW SIZE TO NORMAL SIZE
	this->WindowState = FormWindowState::Normal;
	this->MaximizeBox = true;
	this->labelTitleShowingStallTime->Visible = false;
	this->labelShowingStallTime->Visible = false;
	this->dateTimePickerShowStallsTime->Visible = false;
	this->buttonConfirmStallsShowingTime->Visible = false;
	this->comboBoxParkSearchStatus->Visible = false;
	this->toolStripButtonParkStatusChange->Enabled = false;
	this->groupBoxDeletedStalls->Visible = false;

	this->hideStallsArrows();

	//TIMER FOR STALLS SYNC DISABLED
	this->timerStallsSync->Enabled = false;

	this->deleteStallsFromScreen();

	std::vector<Park*> *parks = mainSystem->loadParksFromDatabase(LOAD_PARKS_DELETED);
	if (parks != nullptr) {
		this->printParks(parks);
	} 
	this->toolStripButtonAddPark->Enabled = false;
	this->groupBoxInformationsAboutParking->Visible = false;
	this->groupBoxParkList->Show();
	this->groupBoxTools->Hide();
	this->currentScreen = DELETED_PARKS_SCREEN;

	this->toolStripStallsConfig->Visible = false;

	this->groupBoxAddStall->Visible = false;
}
private: System::Void toolStripButtonDeletePark_Click(System::Object^  sender, System::EventArgs^  e) {
	if (MessageBox::Show(
		"Naozaj chcete zmazať parkovisko?",
		"Zmazanie parkoviska", MessageBoxButtons::YesNo,
		MessageBoxIcon::Question) == ::System::Windows::Forms::DialogResult::Yes)
	{
		std::string id = msclr::interop::marshal_as<std::string>(labelParkInformationsId->Text);
		std::string sql = CHANGE_PARK_TO_DELETED(id);
		if (mainSystem->doUpdate(sql) == true) {
			std::string sqlSync = CHANGE_TIMESTAMP_PR_PARKOVISKO_DELETE_NOW;
			mainSystem->doUpdateSyncData(sqlSync);

			MessageBox::Show("Zmazanie parkoviska prebehlo úspšene.");
		}
		else {
			MessageBox::Show("Zmazanie parkoviska skončilo chybou.");
		}
	}
}
private: System::Void buttonParkRecover_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string id = msclr::interop::marshal_as<std::string>(labelParkInformationsId->Text);
	std::string sql = CHANGE_PARK_TO_NOT_DELETED(id);
	if (mainSystem->doUpdate(sql) == true) {
		std::string sqlSync = CHANGE_TIMESTAMP_PR_PARKOVISKO_DELETE_NOW;
		mainSystem->doUpdateSyncData(sqlSync);

		MessageBox::Show("Obnovenie parkoviska prebehlo úspšene.");
	}
	else {
		MessageBox::Show("Obnovenie parkoviska skončilo chybou.");
	}
}

private: System::Void checkBoxStallFree_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->checkBoxStallFree->Checked == true) {
		this->checkBoxStallReserve->Checked = false;
		this->checkBoxStallOutOfService->Checked = false;
	}	
}
private: System::Void checkBoxStallReserve_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->checkBoxStallReserve->Checked == true) {
		this->checkBoxStallFree->Checked = false;
		this->checkBoxStallOutOfService->Checked = false;
	}
}
private: System::Void checkBoxOutOfService_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->checkBoxStallOutOfService->Checked == true) {
		this->checkBoxStallFree->Checked = false;
		this->checkBoxStallReserve->Checked = false;
	}
}

private: System::Void buttonChangeTypeConfirm_Click(System::Object^  sender, System::EventArgs^  e) {
	int newType;
	if (this->checkBoxStallFree->Checked == true) {
		newType = STALL_TYPE_FREE;
	}
	if (this->checkBoxStallReserve->Checked == true) {
		newType = STALL_TYPE_RESERVE;
	}
	if (this->checkBoxStallOutOfService->Checked == true) {
		newType = STALL_TYPE_SERVICE;
	}

		std::string stallId = msclr::interop::marshal_as<std::string>(labelStallId->ToString());
		std::string stallID = stallId.substr(34);
		std::string parkId = msclr::interop::marshal_as<std::string>(labelParkId->ToString());
		std::string parkID = parkId.substr(34);

		if (mainSystem->changeStallType(parkID, stallID, newType) == true) {
			MessageBox::Show("Zmena prebehla úspešne.");
			this->groupBoxChangeStallType->Enabled = false;

			this->didUpdateThisApk = true;
		}
}
private: System::Void toolStripButtonAddStall_Click(System::Object^  sender, System::EventArgs^  e) {
	this->groupBoxAddStall->Visible = true;
	this->groupBoxTools->Visible = false;
}
private: System::Void buttonAddStallConfirm_Click(System::Object^  sender, System::EventArgs^  e) {
	this->groupBoxAddStall->Visible = false;
	this->groupBoxTools->Visible = true;

	if (textBoxAddStallHeight->Text->Length > 0 && textBoxAddStallWidth->Text->Length > 0 && textBoxAddStallX->Text->Length > 0 && textBoxAddStallY->Text->Length > 0) {
		
		std::string parkId = std::to_string(mainSystem->getCurrentPark()->getParkoId());
		std::string x = msclr::interop::marshal_as<std::string>(textBoxAddStallX->Text);
		std::string y = msclr::interop::marshal_as<std::string>(textBoxAddStallY->Text);
		std::string oldCapacity = msclr::interop::marshal_as<std::string>(labelParkInformationsCapacity->Text);
		std::string newCapacity = std::to_string(this->currParkNumberOfStalls + 1);
		std::string orientation;
		if (this->checkBoxAddStallHorizontal->Checked == true) {
			orientation = std::to_string(STALL_HORIZONTAL);
		}
		else if (this->checkBoxAddStallVertical->Checked == true) {
			orientation = std::to_string(STALL_VERTICAL);
		}
		std::string height = msclr::interop::marshal_as<std::string>(this->textBoxAddStallHeight->Text);
		std::string width = msclr::interop::marshal_as<std::string>(this->textBoxAddStallWidth->Text);

		try
		{
			std::stoi(x);
			std::stoi(y);
			std::stoi(height);
			std::stoi(width);

			if (mainSystem->checkPlaceForNewStall(parkId, orientation, x, y, height, width) == true) {
				if (mainSystem->addStall(x, y, newCapacity, orientation, height, width) == true) {
					this->currParkNumberOfStalls++;
					MessageBox::Show("Pridanie parkovacieho miesta prebehlo úspešne.");
				}
				else {
					MessageBox::Show("Pridanie sa nezdarilo.");
				}
			}
			else {
				MessageBox::Show("Pridávané parkovacie miesto sa prekrýva s iným parkovacím miestom!");
			}
		}
		catch (const std::exception&)
		{
			MessageBox::Show("Polia su celociselne!");
		}
	}
	else {
		MessageBox::Show("Vyplnte vsetky polia!");
	}
}
private: System::Void toolStripButtonDeleteStall_Click(System::Object^  sender, System::EventArgs^  e) {
	if (MessageBox::Show(
		"Naozaj chcete zmazať parkovacie miesto?",
		"Zmazanie parkovacieho miesta", MessageBoxButtons::YesNo,
		MessageBoxIcon::Question) == ::System::Windows::Forms::DialogResult::Yes)
	{
		std::string parkId = std::to_string(mainSystem->getCurrentPark()->getParkoId());
		std::string stallId = msclr::interop::marshal_as<std::string>(labelStallId->Text);
		std::string oldCapacity = msclr::interop::marshal_as<std::string>(labelParkInformationsCapacity->Text);
		std::string newCapacity = std::to_string(std::stoi(oldCapacity) - 1);

		if (mainSystem->deleteStall(parkId, stallId, newCapacity) == true) {
			this->currParkNumberOfStalls--;
			MessageBox::Show("Zmazanie parkovacieho miesta prebehlo úspešne.");
		} 
		else{
			MessageBox::Show("Zmazanie sa nezdarilo.");
		}
	}
}
private: System::Void toolStripButtonChangeStallType_Click(System::Object^  sender, System::EventArgs^  e) {
	this->groupBoxChangeStallType->Enabled = true;
}
private: System::Void zoznamZmazanýchParkovacíchMiestToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//SET WINDOW SIZE TO NORMAL SIZE
	this->WindowState = FormWindowState::Normal;
	this->MaximizeBox = true;
	this->labelTitleShowingStallTime->Visible = false;
	this->labelShowingStallTime->Visible = false;
	this->dateTimePickerShowStallsTime->Visible = false;
	this->buttonConfirmStallsShowingTime->Visible = false;

	this->deleteStallsFromScreen();

	this->hideStallsArrows();

	this->currentScreen = DELETED_STALLS_SCREEN;

	this->toolStripStallsConfig->Visible = false;
	this->groupBoxDeletedStalls->Visible = true;
	this->groupBoxParkList->Visible = false;
	this->groupBoxTools->Visible = false;

	this->printDeletedStallsToList(mainSystem->loadStalls(LOAD_DELETED_STALLS));
}
private: System::Void textBoxSearchParkFindingWord_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	this->searchingParks();
}
private: System::Void checkBoxParkSearchName_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->checkBoxParkSearchName->Checked == true) {
		this->checkBoxParkSearchId->Checked = false;
	}
	this->textBoxSearchParkFindingWord->Clear();
}
private: System::Void checkBoxParkSearchId_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->checkBoxParkSearchId->Checked == true) {
		this->checkBoxParkSearchName->Checked = false;
	}
	this->textBoxSearchParkFindingWord->Clear();
}
private: System::Void checkBoxSearchInDeletedStallsStallId_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->checkBoxSearchInDeletedStallsStallId->Checked == true) {
		this->checkBoxSearchInDeletedStallsParkId->Checked = false;
		this->checkBoxSearchInDeletedStallsStallX->Checked = false;
		this->checkBoxSearchInDeletedStallsStallY->Checked = false;
	}
}
private: System::Void checkBoxSearchInDeletedStallsParkId_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->checkBoxSearchInDeletedStallsParkId->Checked == true) {
		this->checkBoxSearchInDeletedStallsStallX->Checked = false;
		this->checkBoxSearchInDeletedStallsStallY->Checked = false;
		this->checkBoxSearchInDeletedStallsStallId->Checked = false;
	}
}

private: System::Void checkBoxSearchInDeletedStallsStallX_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->checkBoxSearchInDeletedStallsStallX->Checked == true) {
		this->checkBoxSearchInDeletedStallsStallY->Checked = false;
		this->checkBoxSearchInDeletedStallsStallId->Checked = false;
		this->checkBoxSearchInDeletedStallsParkId->Checked = false;
	}
}
private: System::Void checkBoxSearchInDeletedStallsStallY_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->checkBoxSearchInDeletedStallsStallY->Checked == true) {
		this->checkBoxSearchInDeletedStallsStallId->Checked = false;
		this->checkBoxSearchInDeletedStallsParkId->Checked = false;
		this->checkBoxSearchInDeletedStallsStallX->Checked = false;
	}
}

private: System::Void textBoxSearchingWordDeletedStalls_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	this->searchingStalls();
}
private: System::Void toolStripButtonLoadStalls_Click(System::Object^  sender, System::EventArgs^  e) {
	AddListOfStalls^ addListOfStalls = gcnew AddListOfStalls();
	int currentParkId = std::stoi(msclr::interop::marshal_as<std::string>(this->labelParkInformationsId->Text));
	int currentCapacity = std::stoi(msclr::interop::marshal_as<std::string>(this->labelParkInformationsCapacity->Text));
	std::string currentMaxStallId = std::to_string(mainSystem->loadIntegerFromDatabase(LOAD_MAX_ID_FROM_PARKS) + 1);


	addListOfStalls->setMain(this->mainSystem);
	addListOfStalls->setParkId(currentParkId);
	addListOfStalls->setCurrentCapacity(currentCapacity);
	addListOfStalls->ShowDialog();

	this->showParkingInformations();
}
private: System::Void buttonStallsPrintPageRight_Click(System::Object^  sender, System::EventArgs^  e) {
	this->printStallsFromRange(STALLS_SHIFT_DIRECTION_RIGHT);
}
private: System::Void buttonStallsPrintPageLeft_Click(System::Object^  sender, System::EventArgs^  e) {
	this->printStallsFromRange(STALLS_SHIFT_DIRECTION_LEFT);
}
private: System::Void buttonStallsPrintPageUp_Click(System::Object^  sender, System::EventArgs^  e) {
	this->printStallsFromRange(STALLS_SHIFT_DIRECTION_UP);
}
private: System::Void buttonStallsPrintPageDown_Click(System::Object^  sender, System::EventArgs^  e) {
	this->printStallsFromRange(STALLS_SHIFT_DIRECTION_DOWN);
}
private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
	if (this->currentScreen == STALLS_SCREEN) {
		this->printStallsFromRange(STALLS_SHIFT_DIRECTION_HERE);
	}
}
private: System::Void toolStripButtonShowStallsInTime_Click(System::Object^  sender, System::EventArgs^  e) {
	this->labelShowingStallTime->Visible = false;
	this->dateTimePickerShowStallsTime->Visible = true;
	this->buttonConfirmStallsShowingTime->Visible = true;
	this->toolStripButtonShowStallsCurrentTime->Enabled = true;
	this->toolStripButtonShowStallsInTime->Enabled = false;
	this->currentShowStalls = SHOW_STALLS_CHOSED_TIME;
}
private: System::Void toolStripButtonShowStallsCurrentTime_Click(System::Object^  sender, System::EventArgs^  e) {
	this->labelShowingStallTime->Visible = true;
	this->dateTimePickerShowStallsTime->Visible = false;
	this->buttonConfirmStallsShowingTime->Visible = false;
	this->toolStripButtonShowStallsInTime->Enabled = true;
	this->toolStripButtonShowStallsCurrentTime->Enabled = false;
	this->currentShowStalls = SHOW_STALLS_CURRENT_TIME;

	this->printStallsFromRange(STALLS_SHIFT_DIRECTION_HERE);
}
private: System::Void buttonConfirmStallsShowingTime_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string minX = std::to_string(this->currentStartScreenPositionX);
	std::string maxX = std::to_string(this->currentStartScreenPositionX + ((this->Width - STALLS_PRINT_RIGHT_OFFSET - STALLS_PRINT_LEFT_OFFSET) * STALL_COEFFICIENT));
	std::string minY = std::to_string(this->currentStartScreenPositionY);
	std::string maxY = std::to_string(this->currentStartScreenPositionY + ((this->Height - STALLS_PRINT_TOP_OFFSET - STALLS_PRINT_BOTTOM_OFFSET) * STALL_COEFFICIENT));
	std::string parkId = std::to_string(mainSystem->getCurrentPark()->getParkoId());
	oracle::occi::Timestamp timestamp = mainSystem->getTimestampFromDateTimePicker(this->dateTimePickerShowStallsTime);
	std::string timestampS = mainSystem->getStringFromTimeStamp(timestamp);

	std::vector<Stall*> *stalls = new std::vector<Stall*>;

	std::string sql = LOAD_STALLS_FROM_TIME_RESERVED_RESERVE(parkId, minX, maxX, minY, maxY, timestampS);
	mainSystem->loadStallsFull(sql, stalls, LOAD_RESERVED_RESERVE_STALL);

	std::string sql1 = LOAD_STALLS_FROM_TIME_RESERVED_FREE(parkId, minX, maxX, minY, maxY, timestampS);
	mainSystem->loadStallsFull(sql1, stalls, LOAD_RESERVED_FREE_STALL);

	std::string sql2 = LOAD_STALLS_FROM_TIME_FREE_FREE(parkId, minX, maxX, minY, maxY, timestampS);
	mainSystem->loadStallsFull(sql2, stalls, LOAD_FREE_FREE_STALL);
	
	
	this->deleteStallsFromScreen();
	currParkNumberOfStalls = stalls->size();
	this->printStalls(stalls);
}

private: System::Void checkBoxAddStallHorizontal_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->checkBoxAddStallHorizontal->Checked == true) {
		this->checkBoxAddStallVertical->Checked = false;
	}
}
private: System::Void checkBoxAddStallVertical_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->checkBoxAddStallVertical->Checked == true) {
		this->checkBoxAddStallHorizontal->Checked = false;
	}
}
private: System::Void toolStripButtonAddListOfStalls_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void toolStripButtonParkStatusChange_Click(System::Object^  sender, System::EventArgs^  e) {
	this->groupBoxChangeParkStatus->Visible = true;
	this->groupBoxNewParkAdress->Visible = false;
	this->groupBoxNewParkName->Visible = false;
	this->groupBoxNewParkLatitude->Visible = false;
	this->groupBoxNewParkLongtitude->Visible = false;
}
private: System::Void checkBoxParkStatusOn_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->checkBoxParkStatusOn->Checked == true) {
		this->checkBoxParkStatusOff->Checked = false;
	}
}
private: System::Void checkBoxParkStatusOff_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->checkBoxParkStatusOff->Checked == true) {
		this->checkBoxParkStatusOn->Checked = false;
	}
}
private: System::Void buttonConfirmChangeParkStatus_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string parkId = msclr::interop::marshal_as<std::string>(labelParkInformationsId->Text);
	std::string newStatus;
	if (checkBoxParkStatusOn->Checked == true) {
		newStatus = std::to_string(PARK_ACTIVE);
	}
	else if (checkBoxParkStatusOff->Checked == true) {
		newStatus = std::to_string(PARK_NOT_ACTIVE);
	}

	std::string sql = CHANGE_PARK_STATUS(parkId, newStatus);
	if (mainSystem->doUpdate(sql) == true) {
		std::string sqlSync = CHANGE_TIMESTAMP_PR_PARKOVISKO_UPDATE_NOW;
		mainSystem->doUpdateSyncData(sqlSync);

		MessageBox::Show("Stav parkoviska úspešne zmenený.");
	}
	else {
		MessageBox::Show("Zmena mena sa nezdarila.");
	}
	this->groupBoxChangeParkStatus->Visible = false;
}
private: System::Void comboBoxParkSearchStatus_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	this->searchingParks();
}
private: System::Void buttonConfirmParkLatitudeChange_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string id = msclr::interop::marshal_as<std::string>(labelParkInformationsId->Text);
	std::string newLatitude = msclr::interop::marshal_as<std::string>(textBoxNewParkLatitude->Text);

	try
	{
		std::stod(newLatitude);
		std::string sql = CHANGE_PARK_LATITUDE(id, newLatitude);
		if (mainSystem->doUpdate(sql) == true) {
			MessageBox::Show("Zemepisná šírka parkoviska úspšene zmenená.");
		}
		else {
			MessageBox::Show("Zmena zemepisnej šírky sa nezdarila");
		}
		this->showParkingInformations();

		this->groupBoxNewParkLatitude->Visible = false;
	}
	catch (const std::exception&)
	{
		MessageBox::Show("Zadajte desatinne cislo");
	}
}
private: System::Void toolStripButtonChangeLatitude_Click(System::Object^  sender, System::EventArgs^  e) {
	this->groupBoxNewParkLongtitude->Visible = false;
	this->groupBoxChangeParkStatus->Visible = false;
	this->groupBoxNewParkAdress->Visible = false;
	this->groupBoxNewParkName->Visible = false;
	this->groupBoxNewParkLatitude->Visible = true;
}
private: System::Void buttonConfirmParkLatitudeChangeLongtitude_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string id = msclr::interop::marshal_as<std::string>(labelParkInformationsId->Text);
	std::string newLongtitude = msclr::interop::marshal_as<std::string>(textBoxNewParkLongtitude->Text);

	try
	{
		std::stod(newLongtitude);
		std::string sql = CHANGE_PARK_LONGTITUDE(id, newLongtitude);
		if (mainSystem->doUpdate(sql) == true) {
			MessageBox::Show("Zemepisná dĺžka parkoviska úspšene zmenená.");
		}
		else {
			MessageBox::Show("Zmena zemepisnej dĺžky sa nezdarila");
		}
		this->showParkingInformations();

		this->groupBoxNewParkLongtitude->Visible = false;
	}
	catch (const std::exception&)
	{
		MessageBox::Show("Zadajte desatinne cislo");
	}
}
private: System::Void toolStripButtonChangeLongtitude_Click(System::Object^  sender, System::EventArgs^  e) {
	this->groupBoxNewParkLongtitude->Visible = true;
	this->groupBoxChangeParkStatus->Visible = false;
	this->groupBoxNewParkAdress->Visible = false;
	this->groupBoxNewParkName->Visible = false;
	this->groupBoxNewParkLatitude->Visible = false;
}
};
}