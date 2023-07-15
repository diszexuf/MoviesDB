#pragma once

#include "MovieLinkedList.h"
#include "WEditMenu.h"
#include "WAddMenu.h"
#include "WGreeting.h"

//using namespace System;

namespace MoviesDB {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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

	private: System::String^ filePath = "";
	public: MovieLinkedList^ moviesList = gcnew MovieLinkedList();
	public: List<Movie^>^ moviesListBox = gcnew List<Movie^>;
	private: Movie^ test1 = gcnew Movie("Test", "F:\\torrents", "Боевик", "аннтоация какой-то текст", DateTime(2003, 12, 23), 8);
	private: Movie^ test2 = gcnew Movie("Testik", "F:\\torrents\\23asda", "Драма", "аннтоация какой-то текст", DateTime(2001, 11, 12), 10);

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

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::TextBox^ textBox1;


	private:
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovRatingNumTo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovRatingNumFrom))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// MovieList
			// 
			this->MovieList->FormattingEnabled = true;
			this->MovieList->Location = System::Drawing::Point(232, 14);
			this->MovieList->Name = L"MovieList";
			this->MovieList->Size = System::Drawing::Size(128, 459);
			this->MovieList->TabIndex = 13;
			this->MovieList->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &WMainMenu::MovieList_MouseDoubleClick);
			// 
			// FindMovBtn
			// 
			this->FindMovBtn->Enabled = false;
			this->FindMovBtn->Location = System::Drawing::Point(6, 197);
			this->FindMovBtn->Name = L"FindMovBtn";
			this->FindMovBtn->Size = System::Drawing::Size(209, 39);
			this->FindMovBtn->TabIndex = 12;
			this->FindMovBtn->Text = L"Найти фильмы";
			this->FindMovBtn->UseVisualStyleBackColor = true;
			this->FindMovBtn->Click += gcnew System::EventHandler(this, &WMainMenu::FindMovBtn_Click);
			// 
			// MovRatingTo
			// 
			this->MovRatingTo->AutoSize = true;
			this->MovRatingTo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->MovRatingTo->Location = System::Drawing::Point(109, 150);
			this->MovRatingTo->Name = L"MovRatingTo";
			this->MovRatingTo->Size = System::Drawing::Size(24, 17);
			this->MovRatingTo->TabIndex = 6;
			this->MovRatingTo->Text = L"до";
			// 
			// MovRatingFromLbl
			// 
			this->MovRatingFromLbl->AutoSize = true;
			this->MovRatingFromLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->MovRatingFromLbl->Location = System::Drawing::Point(30, 150);
			this->MovRatingFromLbl->Name = L"MovRatingFromLbl";
			this->MovRatingFromLbl->Size = System::Drawing::Size(23, 17);
			this->MovRatingFromLbl->TabIndex = 7;
			this->MovRatingFromLbl->Text = L"от";
			// 
			// MovRatingLbl
			// 
			this->MovRatingLbl->AutoSize = true;
			this->MovRatingLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MovRatingLbl->Location = System::Drawing::Point(78, 118);
			this->MovRatingLbl->Name = L"MovRatingLbl";
			this->MovRatingLbl->Size = System::Drawing::Size(56, 16);
			this->MovRatingLbl->TabIndex = 8;
			this->MovRatingLbl->Text = L"Оценка";
			// 
			// MovGenreLbl
			// 
			this->MovGenreLbl->AutoSize = true;
			this->MovGenreLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->MovGenreLbl->Location = System::Drawing::Point(54, 84);
			this->MovGenreLbl->Name = L"MovGenreLbl";
			this->MovGenreLbl->Size = System::Drawing::Size(49, 17);
			this->MovGenreLbl->TabIndex = 9;
			this->MovGenreLbl->Text = L"Жанр:";
			// 
			// MovNameLbl
			// 
			this->MovNameLbl->AutoSize = true;
			this->MovNameLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->MovNameLbl->Location = System::Drawing::Point(27, 53);
			this->MovNameLbl->Name = L"MovNameLbl";
			this->MovNameLbl->Size = System::Drawing::Size(76, 17);
			this->MovNameLbl->TabIndex = 5;
			this->MovNameLbl->Text = L"Название:";
			// 
			// SearchParamsLbl
			// 
			this->SearchParamsLbl->AutoSize = true;
			this->SearchParamsLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SearchParamsLbl->Location = System::Drawing::Point(34, 12);
			this->SearchParamsLbl->Name = L"SearchParamsLbl";
			this->SearchParamsLbl->Size = System::Drawing::Size(153, 20);
			this->SearchParamsLbl->TabIndex = 14;
			this->SearchParamsLbl->Text = L"Параметры поиска";
			// 
			// ReadBDBtn
			// 
			this->ReadBDBtn->Location = System::Drawing::Point(6, 36);
			this->ReadBDBtn->Name = L"ReadBDBtn";
			this->ReadBDBtn->Size = System::Drawing::Size(220, 39);
			this->ReadBDBtn->TabIndex = 10;
			this->ReadBDBtn->Text = L"Прочитать базу фильмов";
			this->ReadBDBtn->UseVisualStyleBackColor = true;
			this->ReadBDBtn->Click += gcnew System::EventHandler(this, &WMainMenu::ReadBDBtn_Click);
			// 
			// SaveBDBtn
			// 
			this->SaveBDBtn->Location = System::Drawing::Point(6, 81);
			this->SaveBDBtn->Name = L"SaveBDBtn";
			this->SaveBDBtn->Size = System::Drawing::Size(220, 39);
			this->SaveBDBtn->TabIndex = 10;
			this->SaveBDBtn->Text = L"Сохранить базу фильмов";
			this->SaveBDBtn->UseVisualStyleBackColor = true;
			this->SaveBDBtn->Click += gcnew System::EventHandler(this, &WMainMenu::SaveBDBtn_Click);
			// 
			// MovNameTB
			// 
			this->MovNameTB->Location = System::Drawing::Point(105, 52);
			this->MovNameTB->Name = L"MovNameTB";
			this->MovNameTB->Size = System::Drawing::Size(100, 20);
			this->MovNameTB->TabIndex = 16;
			this->MovNameTB->TextChanged += gcnew System::EventHandler(this, &WMainMenu::MovNameTB_TextChanged);
			// 
			// BDActionsLbl
			// 
			this->BDActionsLbl->AutoSize = true;
			this->BDActionsLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline));
			this->BDActionsLbl->Location = System::Drawing::Point(56, 13);
			this->BDActionsLbl->Name = L"BDActionsLbl";
			this->BDActionsLbl->Size = System::Drawing::Size(122, 20);
			this->BDActionsLbl->TabIndex = 18;
			this->BDActionsLbl->Text = L"Действия с БД";
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
			this->panel1->Location = System::Drawing::Point(6, 238);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(220, 239);
			this->panel1->TabIndex = 19;
			// 
			// MovRatingNumTo
			// 
			this->MovRatingNumTo->Location = System::Drawing::Point(139, 150);
			this->MovRatingNumTo->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->MovRatingNumTo->Name = L"MovRatingNumTo";
			this->MovRatingNumTo->Size = System::Drawing::Size(44, 20);
			this->MovRatingNumTo->TabIndex = 18;
			this->MovRatingNumTo->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->MovRatingNumTo->ValueChanged += gcnew System::EventHandler(this, &WMainMenu::MovRatingNum_ValueChanged);
			// 
			// MovRatingNumFrom
			// 
			this->MovRatingNumFrom->Location = System::Drawing::Point(59, 150);
			this->MovRatingNumFrom->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->MovRatingNumFrom->Name = L"MovRatingNumFrom";
			this->MovRatingNumFrom->Size = System::Drawing::Size(44, 20);
			this->MovRatingNumFrom->TabIndex = 18;
			this->MovRatingNumFrom->ValueChanged += gcnew System::EventHandler(this, &WMainMenu::MovRatingNum_ValueChanged);
			// 
			// MovGenreCB
			// 
			this->MovGenreCB->FormattingEnabled = true;
			this->MovGenreCB->Items->AddRange(gcnew cli::array< System::Object^  >(11) {
				L"", L"Боевик", L"Детектив", L"Драма", L"Исторический",
					L"Комедия", L"Мелодрама", L"Приключение", L"Трагедия", L"Триллер", L"Документальный"
			});
			this->MovGenreCB->Location = System::Drawing::Point(105, 84);
			this->MovGenreCB->Name = L"MovGenreCB";
			this->MovGenreCB->Size = System::Drawing::Size(100, 21);
			this->MovGenreCB->TabIndex = 17;
			this->MovGenreCB->SelectedIndexChanged += gcnew System::EventHandler(this, &WMainMenu::MovGenreCB_SelectedIndexChanged);
			// 
			// MovAddBtn
			// 
			this->MovAddBtn->Location = System::Drawing::Point(6, 126);
			this->MovAddBtn->Name = L"MovAddBtn";
			this->MovAddBtn->Size = System::Drawing::Size(220, 39);
			this->MovAddBtn->TabIndex = 10;
			this->MovAddBtn->Text = L"Добавить фильм в базу";
			this->MovAddBtn->UseVisualStyleBackColor = true;
			this->MovAddBtn->Click += gcnew System::EventHandler(this, &WMainMenu::MovAddBtn_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBox1->Location = System::Drawing::Point(689, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(199, 248);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 70;
			this->pictureBox1->TabStop = false;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"Боевик", L"Детектив", L"Драма", L"Исторический",
					L"Комедия", L"Мелодрама", L"Приключение", L"Трагедия", L"Триллер", L"Документальный"
			});
			this->comboBox1->Location = System::Drawing::Point(689, 319);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(199, 21);
			this->comboBox1->TabIndex = 69;
			this->comboBox1->Text = L"Выберите жанр";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(689, 374);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(199, 20);
			this->dateTimePicker1->TabIndex = 68;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(366, 13);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(314, 461);
			this->textBox2->TabIndex = 67;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(689, 346);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(199, 20);
			this->numericUpDown1->TabIndex = 66;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(689, 286);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(199, 20);
			this->textBox1->TabIndex = 65;
			// 
			// WMainMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(898, 483);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->BDActionsLbl);
			this->Controls->Add(this->MovieList);
			this->Controls->Add(this->MovAddBtn);
			this->Controls->Add(this->SaveBDBtn);
			this->Controls->Add(this->ReadBDBtn);
			this->Name = L"WMainMenu";
			this->Text = L"MovList";
			this->Load += gcnew System::EventHandler(this, &WMainMenu::WMainMenu_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovRatingNumTo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovRatingNumFrom))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void WMainMenu_Load(System::Object^ sender, System::EventArgs^ e) {
	WGreeting^ Greeting = gcnew WGreeting;
	Greeting->ShowDialog();
	moviesList->AddMovie(test1);
	moviesList->AddMovie(test2);
	MovieList->Items->Add(test1);
	MovieList->Items->Add(test2);

}

private: System::Void ReadBDBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ folderDialog = gcnew OpenFileDialog();
	folderDialog->Filter = "CSV File (.csv)|*.csv";

	if (folderDialog->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
	{
		return;
	}

	filePath = folderDialog->FileName;

	bool isReaded = moviesList->ReadBase(filePath); // Считываем информацию с базы в односвязный список
	if (!isReaded)
		MessageBox::Show("Не удалось открыть файл!");

	moviesListBox = moviesList->GetMovies(); // Добавляем в обычный список элементы на вывод в listBox
	for each (Movie^ m in moviesListBox)
	{
		MovieList->Items->Add(m);
	}
	MovieList->Update();
}

private: System::Void SaveBDBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	SaveFileDialog^ saveFile = gcnew SaveFileDialog();
	saveFile->Filter = "CSV File (.csv)|*.csv";

	if (saveFile->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
	{
		return;
	}
	filePath = saveFile->FileName;

	bool SaveStatement = moviesList->SaveBase(filePath);

	if (!SaveStatement)
	{
		MessageBox::Show("Не удалось сохранить файл");
	}
}

private: System::Void MovieList_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	WEditMenu^ EditMenu = gcnew WEditMenu;
	EditMenu->ShowDialog();
}

private: System::Void FindMovBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	MovNameTB->Enabled = true;
	MovGenreCB->Enabled = true;
	MovRatingNumFrom->Enabled = true;
	MovRatingNumTo->Enabled = true;



	List<Movie^>^ FoundMovies;
	if (MovNameTB->Text->Length != 0) {
		FoundMovies = moviesList->Find(MovNameTB->Text);
	}
	else if (MovGenreCB->SelectedIndex != -1 && MovGenreCB->SelectedIndex != 0) {
		FoundMovies = moviesList->FindbyGenre(MovGenreCB->SelectedText);
	}
	else {
		FoundMovies = moviesList->Find((int)MovRatingNumFrom->Value, (int)MovRatingNumTo->Value);
	}

	for (int i = 0; i < FoundMovies->Count; i++) {
		MovieList->Items->Add(FoundMovies[i]);
	}
	MovieList->Update();
}

private: System::Void MovNameTB_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	// вкл\выкл кнопки поиска
	if (MovNameTB->Text->Length == 0 && (MovGenreCB->SelectedIndex != -1 || MovGenreCB->SelectedIndex != 0) && (int) MovRatingNumFrom->Value == 0 && (int) MovRatingNumTo->Value == 10) {
		FindMovBtn->Enabled = false;
	}
	else
	{
		FindMovBtn->Enabled = true;
	}
	
	// выкл остальных полей
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

private: System::Void MovGenreCB_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	// вкл\выкл кнопки поиска
	if (MovNameTB->Text->Length == 0 && ((int) MovGenreCB->SelectedIndex == -1 || (int) MovGenreCB->SelectedIndex == 0) && (int)MovRatingNumFrom->Value == 0 && (int)MovRatingNumTo->Value == 10) {
		FindMovBtn->Enabled = false;
	}
	else
	{
		FindMovBtn->Enabled = true;
	}

	// выкл остальных полей
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

private: System::Void MovRatingNum_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	// вкл\выкл кнопки поиска
	if (MovNameTB->Text->Length == 0 && (MovGenreCB->SelectedIndex != -1 || MovGenreCB->SelectedIndex != 0) && (int)MovRatingNumFrom->Value == 0 && (int)MovRatingNumTo->Value == 10) {
		FindMovBtn->Enabled = false;
	}
	else
	{
		FindMovBtn->Enabled = true;
	}

	// выкл остальных полей
	if ((int) MovRatingNumFrom->Value != 0 || (int)MovRatingNumTo->Value != 10) {
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
}

private: System::Void MovAddBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	WAddMenu^ AddMenu = gcnew WAddMenu;
	AddMenu->ShowDialog();
	moviesList->AddMovie(WAddMenu::mov);
}
};
}
