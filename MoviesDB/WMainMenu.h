#pragma once

#include "MovieLinkedList.h"
#include "WEditMenu.h"
#include "WAddMenu.h"
#include "WGreeting.h"
#include "filesystem"

namespace MoviesDB {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for WMainMenu
	/// </summary>
	public ref class WMainMenu : public System::Windows::Forms::Form
	{
	public:
		WMainMenu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WMainMenu()
		{
			if (components)
			{
				delete components;
			}
		}

	public:
		System::String^ filePath = ""; // ��������� ���������� ��� ���� � �������
		MovieLinkedList^ moviesList = gcnew MovieLinkedList(); // ���� �� ���� ��
		List<Movie^>^ moviesListBox = gcnew List<Movie^>; // ���� �� ����� � ListBox
		static String^ dirPath = Path::GetDirectoryName(Path::GetFullPath("MoviesDB.exe"))->Replace("\\", "\\\\");

	private:
		System::Windows::Forms::ListBox^ MovieList;
		System::Windows::Forms::SaveFileDialog^ saveBase;
		System::Windows::Forms::OpenFileDialog^ openBase;
		System::Windows::Forms::Button^ FindMovBtn;
		System::Windows::Forms::Label^ MovRatingTo;
		System::Windows::Forms::Label^ MovRatingFromLbl;
		System::Windows::Forms::Label^ MovRatingLbl;
		System::Windows::Forms::Label^ MovGenreLbl;
		System::Windows::Forms::Label^ MovNameLbl;
		System::Windows::Forms::Label^ SearchParamsLbl;
		System::Windows::Forms::Button^ ReadBDBtn;
		System::Windows::Forms::Button^ SaveBDBtn;
		System::Windows::Forms::TextBox^ MovNameTB;
		System::Windows::Forms::Label^ BDActionsLbl;
		System::Windows::Forms::Panel^ panel1;
		System::Windows::Forms::Button^ MovAddBtn;
		System::Windows::Forms::ComboBox^ MovGenreCB;
		System::Windows::Forms::NumericUpDown^ MovRatingNumTo;
		System::Windows::Forms::NumericUpDown^ MovRatingNumFrom;
		System::Windows::Forms::OpenFileDialog^ openFileDialog1;
		System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
		System::Windows::Forms::PictureBox^ MovPosterShow;
		System::Windows::Forms::TextBox^ MovAnnotShow;
		System::Windows::Forms::TextBox^ MovNameShow;
		System::Windows::Forms::TextBox^ MovGenreShow;
		System::Windows::Forms::TextBox^ MovDateShow;
		System::Windows::Forms::TextBox^ MovRatingShow;
		System::Windows::Forms::Button^ AllListBtn;
		System::Windows::Forms::Button^ UnrealesMovBtn;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->MovieList = (gcnew System::Windows::Forms::ListBox());
			this->FindMovBtn = (gcnew System::Windows::Forms::Button());
			this->MovRatingTo = (gcnew System::Windows::Forms::Label());
			this->MovRatingFromLbl = (gcnew System::Windows::Forms::Label());
			this->MovRatingLbl = (gcnew System::Windows::Forms::Label());
			this->MovGenreLbl = (gcnew System::Windows::Forms::Label());
			this->MovNameLbl = (gcnew System::Windows::Forms::Label());
			this->SearchParamsLbl = (gcnew System::Windows::Forms::Label());
			this->ReadBDBtn = (gcnew System::Windows::Forms::Button());
			this->SaveBDBtn = (gcnew System::Windows::Forms::Button());
			this->MovNameTB = (gcnew System::Windows::Forms::TextBox());
			this->BDActionsLbl = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->MovRatingNumTo = (gcnew System::Windows::Forms::NumericUpDown());
			this->MovRatingNumFrom = (gcnew System::Windows::Forms::NumericUpDown());
			this->MovGenreCB = (gcnew System::Windows::Forms::ComboBox());
			this->MovAddBtn = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->MovPosterShow = (gcnew System::Windows::Forms::PictureBox());
			this->MovAnnotShow = (gcnew System::Windows::Forms::TextBox());
			this->MovNameShow = (gcnew System::Windows::Forms::TextBox());
			this->MovGenreShow = (gcnew System::Windows::Forms::TextBox());
			this->MovDateShow = (gcnew System::Windows::Forms::TextBox());
			this->MovRatingShow = (gcnew System::Windows::Forms::TextBox());
			this->AllListBtn = (gcnew System::Windows::Forms::Button());
			this->UnrealesMovBtn = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovRatingNumTo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovRatingNumFrom))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovPosterShow))->BeginInit();
			this->SuspendLayout();
			// 
			// MovieList
			// 
			this->MovieList->FormattingEnabled = true;
			this->MovieList->ItemHeight = 16;
			this->MovieList->Location = System::Drawing::Point(309, 17);
			this->MovieList->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovieList->Name = L"MovieList";
			this->MovieList->Size = System::Drawing::Size(169, 564);
			this->MovieList->TabIndex = 13;
			this->MovieList->Click += gcnew System::EventHandler(this, &WMainMenu::MovieList_Click);
			this->MovieList->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &WMainMenu::MovieList_MouseDoubleClick);
			// 
			// FindMovBtn
			// 
			this->FindMovBtn->Enabled = false;
			this->FindMovBtn->Location = System::Drawing::Point(8, 242);
			this->FindMovBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->FindMovBtn->Name = L"FindMovBtn";
			this->FindMovBtn->Size = System::Drawing::Size(279, 48);
			this->FindMovBtn->TabIndex = 12;
			this->FindMovBtn->Text = L"����� ������";
			this->FindMovBtn->UseVisualStyleBackColor = true;
			this->FindMovBtn->Click += gcnew System::EventHandler(this, &WMainMenu::FindMovBtn_Click);
			// 
			// MovRatingTo
			// 
			this->MovRatingTo->AutoSize = true;
			this->MovRatingTo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->MovRatingTo->Location = System::Drawing::Point(145, 185);
			this->MovRatingTo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MovRatingTo->Name = L"MovRatingTo";
			this->MovRatingTo->Size = System::Drawing::Size(31, 20);
			this->MovRatingTo->TabIndex = 6;
			this->MovRatingTo->Text = L"��";
			// 
			// MovRatingFromLbl
			// 
			this->MovRatingFromLbl->AutoSize = true;
			this->MovRatingFromLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->MovRatingFromLbl->Location = System::Drawing::Point(40, 185);
			this->MovRatingFromLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MovRatingFromLbl->Name = L"MovRatingFromLbl";
			this->MovRatingFromLbl->Size = System::Drawing::Size(29, 20);
			this->MovRatingFromLbl->TabIndex = 7;
			this->MovRatingFromLbl->Text = L"��";
			// 
			// MovRatingLbl
			// 
			this->MovRatingLbl->AutoSize = true;
			this->MovRatingLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MovRatingLbl->Location = System::Drawing::Point(104, 145);
			this->MovRatingLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MovRatingLbl->Name = L"MovRatingLbl";
			this->MovRatingLbl->Size = System::Drawing::Size(71, 20);
			this->MovRatingLbl->TabIndex = 8;
			this->MovRatingLbl->Text = L"������";
			// 
			// MovGenreLbl
			// 
			this->MovGenreLbl->AutoSize = true;
			this->MovGenreLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->MovGenreLbl->Location = System::Drawing::Point(72, 103);
			this->MovGenreLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MovGenreLbl->Name = L"MovGenreLbl";
			this->MovGenreLbl->Size = System::Drawing::Size(58, 20);
			this->MovGenreLbl->TabIndex = 9;
			this->MovGenreLbl->Text = L"����:";
			// 
			// MovNameLbl
			// 
			this->MovNameLbl->AutoSize = true;
			this->MovNameLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->MovNameLbl->Location = System::Drawing::Point(36, 65);
			this->MovNameLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MovNameLbl->Name = L"MovNameLbl";
			this->MovNameLbl->Size = System::Drawing::Size(96, 20);
			this->MovNameLbl->TabIndex = 5;
			this->MovNameLbl->Text = L"��������:";
			// 
			// SearchParamsLbl
			// 
			this->SearchParamsLbl->AutoSize = true;
			this->SearchParamsLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SearchParamsLbl->Location = System::Drawing::Point(45, 15);
			this->SearchParamsLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->SearchParamsLbl->Name = L"SearchParamsLbl";
			this->SearchParamsLbl->Size = System::Drawing::Size(190, 25);
			this->SearchParamsLbl->TabIndex = 14;
			this->SearchParamsLbl->Text = L"��������� ������";
			// 
			// ReadBDBtn
			// 
			this->ReadBDBtn->Location = System::Drawing::Point(8, 32);
			this->ReadBDBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->ReadBDBtn->Name = L"ReadBDBtn";
			this->ReadBDBtn->Size = System::Drawing::Size(293, 48);
			this->ReadBDBtn->TabIndex = 10;
			this->ReadBDBtn->Text = L"��������� ���� �������";
			this->ReadBDBtn->UseVisualStyleBackColor = true;
			this->ReadBDBtn->Click += gcnew System::EventHandler(this, &WMainMenu::ReadBDBtn_Click);
			// 
			// SaveBDBtn
			// 
			this->SaveBDBtn->Location = System::Drawing::Point(8, 87);
			this->SaveBDBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->SaveBDBtn->Name = L"SaveBDBtn";
			this->SaveBDBtn->Size = System::Drawing::Size(293, 48);
			this->SaveBDBtn->TabIndex = 10;
			this->SaveBDBtn->Text = L"��������� ���� �������";
			this->SaveBDBtn->UseVisualStyleBackColor = true;
			this->SaveBDBtn->Click += gcnew System::EventHandler(this, &WMainMenu::SaveBDBtn_Click);
			// 
			// MovNameTB
			// 
			this->MovNameTB->Location = System::Drawing::Point(140, 64);
			this->MovNameTB->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovNameTB->Name = L"MovNameTB";
			this->MovNameTB->Size = System::Drawing::Size(132, 22);
			this->MovNameTB->TabIndex = 16;
			this->MovNameTB->TextChanged += gcnew System::EventHandler(this, &WMainMenu::MovNameTB_TextChanged);
			// 
			// BDActionsLbl
			// 
			this->BDActionsLbl->AutoSize = true;
			this->BDActionsLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline));
			this->BDActionsLbl->Location = System::Drawing::Point(75, 4);
			this->BDActionsLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->BDActionsLbl->Name = L"BDActionsLbl";
			this->BDActionsLbl->Size = System::Drawing::Size(154, 25);
			this->BDActionsLbl->TabIndex = 18;
			this->BDActionsLbl->Text = L"�������� � ��";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->MovRatingNumTo);
			this->panel1->Controls->Add(this->MovRatingNumFrom);
			this->panel1->Controls->Add(this->MovGenreCB);
			this->panel1->Controls->Add(this->SearchParamsLbl);
			this->panel1->Controls->Add(this->MovNameLbl);
			this->panel1->Controls->Add(this->MovGenreLbl);
			this->panel1->Controls->Add(this->MovRatingLbl);
			this->panel1->Controls->Add(this->FindMovBtn);
			this->panel1->Controls->Add(this->MovRatingFromLbl);
			this->panel1->Controls->Add(this->MovNameTB);
			this->panel1->Controls->Add(this->MovRatingTo);
			this->panel1->Location = System::Drawing::Point(8, 293);
			this->panel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(293, 294);
			this->panel1->TabIndex = 19;
			// 
			// MovRatingNumTo
			// 
			this->MovRatingNumTo->Location = System::Drawing::Point(185, 185);
			this->MovRatingNumTo->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovRatingNumTo->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->MovRatingNumTo->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->MovRatingNumTo->Name = L"MovRatingNumTo";
			this->MovRatingNumTo->Size = System::Drawing::Size(59, 22);
			this->MovRatingNumTo->TabIndex = 18;
			this->MovRatingNumTo->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->MovRatingNumTo->ValueChanged += gcnew System::EventHandler(this, &WMainMenu::MovRatingNum_ValueChanged);
			// 
			// MovRatingNumFrom
			// 
			this->MovRatingNumFrom->Location = System::Drawing::Point(79, 185);
			this->MovRatingNumFrom->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovRatingNumFrom->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->MovRatingNumFrom->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->MovRatingNumFrom->Name = L"MovRatingNumFrom";
			this->MovRatingNumFrom->Size = System::Drawing::Size(59, 22);
			this->MovRatingNumFrom->TabIndex = 18;
			this->MovRatingNumFrom->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->MovRatingNumFrom->ValueChanged += gcnew System::EventHandler(this, &WMainMenu::MovRatingNum_ValueChanged);
			// 
			// MovGenreCB
			// 
			this->MovGenreCB->FormattingEnabled = true;
			this->MovGenreCB->Items->AddRange(gcnew cli::array< System::Object^  >(14) {
				L"", L"������", L"��������", L"�����", L"������������",
					L"�������", L"���������", L"�����������", L"��������", L"�������", L"��������������", L"����������", L"�������", L"��������"
			});
			this->MovGenreCB->Location = System::Drawing::Point(140, 103);
			this->MovGenreCB->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovGenreCB->Name = L"MovGenreCB";
			this->MovGenreCB->Size = System::Drawing::Size(132, 24);
			this->MovGenreCB->TabIndex = 17;
			this->MovGenreCB->SelectedIndexChanged += gcnew System::EventHandler(this, &WMainMenu::MovGenreCB_SelectedIndexChanged);
			// 
			// MovAddBtn
			// 
			this->MovAddBtn->Location = System::Drawing::Point(8, 143);
			this->MovAddBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovAddBtn->Name = L"MovAddBtn";
			this->MovAddBtn->Size = System::Drawing::Size(293, 48);
			this->MovAddBtn->TabIndex = 10;
			this->MovAddBtn->Text = L"�������� ����� � ����";
			this->MovAddBtn->UseVisualStyleBackColor = true;
			this->MovAddBtn->Click += gcnew System::EventHandler(this, &WMainMenu::MovAddBtn_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MovPosterShow
			// 
			this->MovPosterShow->BackColor = System::Drawing::SystemColors::ControlDark;
			this->MovPosterShow->Enabled = false;
			this->MovPosterShow->Location = System::Drawing::Point(919, 16);
			this->MovPosterShow->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovPosterShow->Name = L"MovPosterShow";
			this->MovPosterShow->Size = System::Drawing::Size(265, 305);
			this->MovPosterShow->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->MovPosterShow->TabIndex = 70;
			this->MovPosterShow->TabStop = false;
			// 
			// MovAnnotShow
			// 
			this->MovAnnotShow->Enabled = false;
			this->MovAnnotShow->Location = System::Drawing::Point(488, 16);
			this->MovAnnotShow->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovAnnotShow->Multiline = true;
			this->MovAnnotShow->Name = L"MovAnnotShow";
			this->MovAnnotShow->Size = System::Drawing::Size(417, 566);
			this->MovAnnotShow->TabIndex = 67;
			// 
			// MovNameShow
			// 
			this->MovNameShow->Enabled = false;
			this->MovNameShow->Location = System::Drawing::Point(919, 352);
			this->MovNameShow->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovNameShow->Name = L"MovNameShow";
			this->MovNameShow->Size = System::Drawing::Size(264, 22);
			this->MovNameShow->TabIndex = 65;
			// 
			// MovGenreShow
			// 
			this->MovGenreShow->Enabled = false;
			this->MovGenreShow->Location = System::Drawing::Point(919, 384);
			this->MovGenreShow->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovGenreShow->Name = L"MovGenreShow";
			this->MovGenreShow->Size = System::Drawing::Size(264, 22);
			this->MovGenreShow->TabIndex = 65;
			// 
			// MovDateShow
			// 
			this->MovDateShow->Enabled = false;
			this->MovDateShow->Location = System::Drawing::Point(919, 416);
			this->MovDateShow->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovDateShow->Name = L"MovDateShow";
			this->MovDateShow->Size = System::Drawing::Size(264, 22);
			this->MovDateShow->TabIndex = 65;
			// 
			// MovRatingShow
			// 
			this->MovRatingShow->Enabled = false;
			this->MovRatingShow->Location = System::Drawing::Point(919, 448);
			this->MovRatingShow->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovRatingShow->Name = L"MovRatingShow";
			this->MovRatingShow->Size = System::Drawing::Size(264, 22);
			this->MovRatingShow->TabIndex = 65;
			// 
			// AllListBtn
			// 
			this->AllListBtn->Location = System::Drawing::Point(239, 258);
			this->AllListBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->AllListBtn->Name = L"AllListBtn";
			this->AllListBtn->Size = System::Drawing::Size(63, 27);
			this->AllListBtn->TabIndex = 71;
			this->AllListBtn->Text = L"�����";
			this->AllListBtn->UseVisualStyleBackColor = true;
			this->AllListBtn->Click += gcnew System::EventHandler(this, &WMainMenu::AllListBtn_Click);
			// 
			// UnrealesMovBtn
			// 
			this->UnrealesMovBtn->Location = System::Drawing::Point(8, 198);
			this->UnrealesMovBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->UnrealesMovBtn->Name = L"UnrealesMovBtn";
			this->UnrealesMovBtn->Size = System::Drawing::Size(293, 48);
			this->UnrealesMovBtn->TabIndex = 10;
			this->UnrealesMovBtn->Text = L"�� �������� ������";
			this->UnrealesMovBtn->UseVisualStyleBackColor = true;
			this->UnrealesMovBtn->Click += gcnew System::EventHandler(this, &WMainMenu::UnrealesMovBtn_Click);
			// 
			// WMainMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1197, 594);
			this->Controls->Add(this->AllListBtn);
			this->Controls->Add(this->MovPosterShow);
			this->Controls->Add(this->MovAnnotShow);
			this->Controls->Add(this->MovRatingShow);
			this->Controls->Add(this->MovDateShow);
			this->Controls->Add(this->MovGenreShow);
			this->Controls->Add(this->MovNameShow);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->BDActionsLbl);
			this->Controls->Add(this->MovieList);
			this->Controls->Add(this->UnrealesMovBtn);
			this->Controls->Add(this->MovAddBtn);
			this->Controls->Add(this->SaveBDBtn);
			this->Controls->Add(this->ReadBDBtn);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"WMainMenu";
			this->Text = L"MoviesDB";
			this->Load += gcnew System::EventHandler(this, &WMainMenu::WMainMenu_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovRatingNumTo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovRatingNumFrom))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovPosterShow))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void WMainMenu_Load(System::Object^ sender, System::EventArgs^ e) { // ��������� �������� ����
		WGreeting^ Greeting = gcnew WGreeting;
		Greeting->ShowDialog(); // ��������� �������������� ���� 
	}

	private: System::Void ReadBDBtn_Click(System::Object^ sender, System::EventArgs^ e) { // ���������� ������ ������ ��
		OpenFileDialog^ folderDialog = gcnew OpenFileDialog();
		folderDialog->Filter = "CSV File (.csv)|*.csv"; // �������� ���������� ����� ��

		if (folderDialog->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		{
			return;
		}

		filePath = folderDialog->FileName; // ��������� ���� � �����

		bool isReaded = moviesList->ReadBase(filePath); // ��������� ���������� � ���� � ����������� ������
		if (!isReaded)
			MessageBox::Show("�� ������� ������� ����!"); // � ������ ������ ������� ��������������

		moviesListBox = moviesList->GetMovies(); // ��������� � ������� ������ �������� �� ����� � listBox
		// ��������� ������ �� ����� � ListBox � ������� ������
		MovieList->Items->Clear();
		for each (Movie ^ m in moviesListBox)
		{
			MovieList->Items->Add(m->Title);
		}
		// ������� ����� ���������� ��������
		MovNameShow->Text = nullptr;
		MovGenreShow->Text = nullptr;
		MovAnnotShow->Text = nullptr;
		MovDateShow->Text = nullptr;
		MovRatingShow->Text = nullptr;
		MovPosterShow->Image = nullptr;
	}

	private: System::Void SaveBDBtn_Click(System::Object^ sender, System::EventArgs^ e) { // ���������� ������ ���������� ��
		SaveFileDialog^ saveFile = gcnew SaveFileDialog();
		saveFile->Filter = "CSV File (.csv)|*.csv"; // �������� ���������� �����

		if (saveFile->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		{
			return;
		}
		filePath = saveFile->FileName; // ��������� ���� � ����������

		bool SaveStatement = moviesList->SaveBase(filePath); // ��������� ��

		if (!SaveStatement)
		{
			MessageBox::Show("�� ������� ��������� ����"); // �������������� ��� �������
		}
		// ������� ����� ���������� ��������
		MovNameShow->Text = nullptr;
		MovGenreShow->Text = nullptr;
		MovAnnotShow->Text = nullptr;
		MovDateShow->Text = nullptr;
		MovRatingShow->Text = nullptr;
		MovPosterShow->Image = nullptr;
	}

	private: System::Void MovieList_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) { // ���������� �������� ����� �� ������� ������
		if (MovieList->SelectedIndex != -1) { // ���������, ����� ������� ���� �� ��� ����������� �� ������� ������������
			WEditMenu^ EditMenu = gcnew WEditMenu(moviesListBox[MovieList->SelectedIndex]); // �������� � EditMenu ������� ����
			moviesList->DeleteMovie(MovieList->SelectedIndex); // ������� ������� �� ��
			moviesListBox->RemoveAt(MovieList->SelectedIndex); // ������� ������� �� ������ �� �����
			EditMenu->ShowDialog(); // �������� EditMenu
			//���� �������� �� ������ � ������ ��� � ��, �� ����� �� ��������������; 
			if (WEditMenu::MovForEdit->Title->Equals("") != true && 
				moviesList->IsMovExist(WEditMenu::MovForEdit) == false) {
				moviesList->AddMovie(WEditMenu::MovForEdit); // ��������� ����� ����� ��������������
			} // ������ �� �������� �� ������������ � ��

			moviesListBox = moviesList->GetMovies(); // ��������� ������ �� �����
			MovieList->Items->Clear(); // ������� ���������� ��������
			// ����� ������ �������
			for each (Movie ^ m in moviesListBox)
			{
				MovieList->Items->Add(m->Title);
			}
			MovieList->Update();
		}
		// ������� ����� ���������� ��������
		MovNameShow->Text = nullptr;
		MovGenreShow->Text = nullptr;
		MovAnnotShow->Text = nullptr;
		MovDateShow->Text = nullptr;
		MovRatingShow->Text = nullptr;
		MovPosterShow->Image = nullptr;
	}

	private: System::Void FindMovBtn_Click(System::Object^ sender, System::EventArgs^ e) { // ���������� ������ ������
		// ���������� ������ � ��������� ������
		MovNameTB->Enabled = true;
		MovGenreCB->Enabled = true;
		MovRatingNumFrom->Enabled = true;
		MovRatingNumTo->Enabled = true;
		// ���������, �� ������ �������� ����� ����������� ����� � ��������� ������ �� �����
		if (MovNameTB->Text->Length != 0) {
			moviesListBox = moviesList->Find(MovNameTB->Text);
		}
		else if (MovGenreCB->SelectedIndex > 0) {
			moviesListBox = moviesList->FindbyGenre((System::String^)MovGenreCB->Items[MovGenreCB->SelectedIndex]);
		}
		else {
			moviesListBox = moviesList->Find((int)MovRatingNumFrom->Value, (int)MovRatingNumTo->Value);
		}
		// ���� �������� �������, �� ������� ��������� ������
		if (moviesListBox->Count != -1) {
			MovieList->Items->Clear();
			for (int i = 0; i < moviesListBox->Count; i++) {
				MovieList->Items->Add(moviesListBox[i]->Title);
			}
		}
		else // ���� �� �������, �� ��������������
		{
			MessageBox::Show("������ �� ������� �������� �� �������");  // ������ ������� �������� ��� ��, ��� � ����� �������
		}

		// ������ ��������� �������� ��� ��������� ������ � ��������� ������ ������
		MovNameTB->Text = "";
		MovGenreCB->SelectedIndex = -1;
		MovRatingNumFrom->Value = 1;
		MovRatingNumTo->Value = 10;
		FindMovBtn->Enabled = false;
		// ������� ����� ���������� ��������
		MovNameShow->Text = nullptr;
		MovGenreShow->Text = nullptr;
		MovAnnotShow->Text = nullptr;
		MovDateShow->Text = nullptr;
		MovRatingShow->Text = nullptr;
		MovPosterShow->Image = nullptr;
	}

	private: System::Void MovNameTB_TextChanged(System::Object^ sender, System::EventArgs^ e) { // ���������� ���� ��� ��������
		// ���\���� ������ ������
		if (MovNameTB->Text->Length == 0 && (MovGenreCB->SelectedIndex != -1 || MovGenreCB->SelectedIndex != 0) && (int)MovRatingNumFrom->Value == 0 && (int)MovRatingNumTo->Value == 10) {
			FindMovBtn->Enabled = false;
		}
		else
		{
			FindMovBtn->Enabled = true;
		}

		// ���� ��������� �����
		if (MovNameTB->Text->Length != 0) {
			MovNameTB->Enabled = true;
			MovGenreCB->Enabled = false;
			MovRatingNumFrom->Enabled = false;
			MovRatingNumTo->Enabled = false;
		}
		else
		{
			MovNameTB->Enabled = true;
			MovGenreCB->Enabled = true;
			MovRatingNumFrom->Enabled = true;
			MovRatingNumTo->Enabled = true;
		}
	}

	private: System::Void MovGenreCB_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) { // ���������� ���� ��� �����
		// ���\���� ������ ������
		if (MovNameTB->Text->Length == 0 && ((int)MovGenreCB->SelectedIndex == -1 || (int)MovGenreCB->SelectedIndex == 0) && (int)MovRatingNumFrom->Value == 0 && (int)MovRatingNumTo->Value == 10) {
			FindMovBtn->Enabled = false;
		}
		else
		{
			FindMovBtn->Enabled = true;
		}

		// ���� ��������� �����
		if ((int)MovGenreCB->SelectedIndex > 0) {
			MovNameTB->Enabled = false;
			MovGenreCB->Enabled = true;
			MovRatingNumFrom->Enabled = false;
			MovRatingNumTo->Enabled = false;
		}
		else
		{
			MovNameTB->Enabled = true;
			MovGenreCB->Enabled = true;
			MovRatingNumFrom->Enabled = true;
			MovRatingNumTo->Enabled = true;
		}
	}

	private: System::Void MovRatingNum_ValueChanged(System::Object^ sender, System::EventArgs^ e) { // ���������� ����� ��������
		// ���\���� ������ ������
		if (MovNameTB->Text->Length == 0 && (MovGenreCB->SelectedIndex != -1 || MovGenreCB->SelectedIndex != 0) && (int)MovRatingNumFrom->Value == 0 && (int)MovRatingNumTo->Value == 10) {
			FindMovBtn->Enabled = false;
		}
		else
		{
			FindMovBtn->Enabled = true;
		}

		// ���\���� ��������� �����
		if ((int)MovRatingNumFrom->Value != 0 || (int)MovRatingNumTo->Value != 10) {
			MovNameTB->Enabled = false;
			MovGenreCB->Enabled = false;
			MovRatingNumFrom->Enabled = true;
			MovRatingNumTo->Enabled = true;
		}
		else
		{
			MovNameTB->Enabled = true;
			MovGenreCB->Enabled = true;
			MovRatingNumFrom->Enabled = true;
			MovRatingNumTo->Enabled = true;
		}

		// ����������� ������������� ��������
		MovRatingNumFrom->Maximum = MovRatingNumTo->Value; // ������������ �������� ������ ������� = �������� ������� �������
		MovRatingNumTo->Minimum = MovRatingNumFrom->Value; // ����������� �������� ������� ������� = �������� ������ �������
	}

	private: System::Void MovAddBtn_Click(System::Object^ sender, System::EventArgs^ e) { // ���������� ������ ����������
		WAddMenu^ AddMenu = gcnew WAddMenu(WMainMenu::dirPath);
		AddMenu->ShowDialog(); // ��������� ���� AddMenu
		if (WAddMenu::mov != nullptr && moviesList->IsMovExist(WAddMenu::mov) == false) { // ����� ���������� ���������, ����� ������ ������������
			moviesList->AddMovie(WAddMenu::mov); // ��������� ����� � ������
			moviesListBox = moviesList->GetMovies(); // ��������� ������ �� �����
			MovieList->Items->Clear();
			for each (Movie ^ m in moviesListBox) // ������� ������
			{
				MovieList->Items->Add(m->Title);
			}
		}
		MovNameShow->Text = nullptr;
		MovGenreShow->Text = nullptr;
		MovAnnotShow->Text = nullptr;
		MovDateShow->Text = nullptr;
		MovRatingShow->Text = nullptr;
		MovPosterShow->Image = nullptr;
	}

	private: System::Void MovieList_Click(System::Object^ sender, System::EventArgs^ e) { // ���������� ����� �� ����� (����� ���������� � ��������� ������)
		if (MovieList->SelectedIndex != -1) { // ��������, ��� ���� �� ������
			Movie^ MovShow = moviesListBox[MovieList->SelectedIndex]; // ��������� ��������� �����
			// ����� � ���� ������ ���� ������ � ������
			MovNameShow->Text = MovShow->Title;
			MovGenreShow->Text = MovShow->Genre;
			MovAnnotShow->Text = MovShow->Annotation;
			MovDateShow->Text = (MovShow->RealeaseDate.ToString())->Substring(0, 11); // ����, ����� �������� ������ ����
			MovRatingShow->Text = MovShow->Rating.ToString();

			if (System::IO::File::Exists(MovShow->PosterPath) == true) { // �������� ������������� �����
				Bitmap^ poster = gcnew Bitmap(MovShow->PosterPath);
				MovPosterShow->Image = poster; // ����� �������
			}
			else
			{
				MovPosterShow->Image = nullptr; // � ���� ������ ������������ default ����������� ��� ������
			}
		}
	}

	private: System::Void AllListBtn_Click(System::Object^ sender, System::EventArgs^ e) { // ���������� ������ "�����" (����� ����� ������ �������)
		moviesListBox = moviesList->GetMovies(); // ��������� ������ �� ����� ������ ��
		MovieList->Items->Clear();
		for each (Movie ^ m in moviesListBox)
		{
			MovieList->Items->Add(m->Title);
		}
		MovNameShow->Text = nullptr;
		MovGenreShow->Text = nullptr;
		MovAnnotShow->Text = nullptr;
		MovDateShow->Text = nullptr;
		MovRatingShow->Text = nullptr;
		MovPosterShow->Image = nullptr;
	}

	private: System::Void UnrealesMovBtn_Click(System::Object^ sender, System::EventArgs^ e) { // ���������� ������ "�� �������� ������" (����� �� �������� �������)
		moviesListBox = moviesList->Find(0, 0); // ����� ������� � ��������� 0 (� �� �������� ������� = 0)
		MovieList->Items->Clear();
		for each (Movie ^ m in moviesListBox) // ����� � ListBox
		{
			MovieList->Items->Add(m->Title);
		}
		MovNameShow->Text = nullptr;
		MovGenreShow->Text = nullptr;
		MovAnnotShow->Text = nullptr;
		MovDateShow->Text = nullptr;
		MovRatingShow->Text = nullptr;
		MovPosterShow->Image = nullptr;
	}
};
}
