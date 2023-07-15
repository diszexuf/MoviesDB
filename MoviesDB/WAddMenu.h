#pragma once

#include "Movie.h"

namespace MoviesDB {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для WAddMenu
	/// </summary>
	public ref class WAddMenu : public System::Windows::Forms::Form
	{
	public:
		String^ tmpTitle;
		String^ tmpGenre;
		String^ tmpPosterPath;
		String^ tmpAnnotation;
		int tmpRating;
	private: System::Windows::Forms::ComboBox^ MovGenreCB;
	public:

	public:
		DateTime tmpDate;
	public:
		WAddMenu(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~WAddMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::NumericUpDown^ MovRatingNum;
	private: System::Windows::Forms::TextBox^ MovPosterPathTB;
	private: System::Windows::Forms::TextBox^ MovNameTB;
	private: System::Windows::Forms::Label^ FillFieldsLbl;
	private: System::Windows::Forms::Label^ MovRatingLbl;
	private: System::Windows::Forms::Label^ MovPosterPathLbl;
	private: System::Windows::Forms::Label^ MovGenreLbl;
	private: System::Windows::Forms::Label^ MovNameLbl;
	private: System::Windows::Forms::DateTimePicker^ MovDatePicker;
	private: System::Windows::Forms::TextBox^ MovAnnTB;
	private: System::Windows::Forms::Label^ MovAnnotLbl;
	private: System::Windows::Forms::Label^ MovDateLbl;
	private: System::Windows::Forms::Button^ MovAddButton;
	private: System::IO::FileSystemWatcher^ fileSystemWatcher1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->MovRatingNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->MovPosterPathTB = (gcnew System::Windows::Forms::TextBox());
			this->MovNameTB = (gcnew System::Windows::Forms::TextBox());
			this->FillFieldsLbl = (gcnew System::Windows::Forms::Label());
			this->MovRatingLbl = (gcnew System::Windows::Forms::Label());
			this->MovPosterPathLbl = (gcnew System::Windows::Forms::Label());
			this->MovGenreLbl = (gcnew System::Windows::Forms::Label());
			this->MovNameLbl = (gcnew System::Windows::Forms::Label());
			this->MovDatePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->MovAnnTB = (gcnew System::Windows::Forms::TextBox());
			this->MovAnnotLbl = (gcnew System::Windows::Forms::Label());
			this->MovDateLbl = (gcnew System::Windows::Forms::Label());
			this->MovAddButton = (gcnew System::Windows::Forms::Button());
			this->fileSystemWatcher1 = (gcnew System::IO::FileSystemWatcher());
			this->MovGenreCB = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovRatingNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->BeginInit();
			this->SuspendLayout();
			// 
			// MovRatingNum
			// 
			this->MovRatingNum->Location = System::Drawing::Point(151, 151);
			this->MovRatingNum->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->MovRatingNum->Name = L"MovRatingNum";
			this->MovRatingNum->Size = System::Drawing::Size(402, 20);
			this->MovRatingNum->TabIndex = 28;
			// 
			// MovPosterPathTB
			// 
			this->MovPosterPathTB->Location = System::Drawing::Point(151, 121);
			this->MovPosterPathTB->Name = L"MovPosterPathTB";
			this->MovPosterPathTB->Size = System::Drawing::Size(402, 20);
			this->MovPosterPathTB->TabIndex = 24;
			// 
			// MovNameTB
			// 
			this->MovNameTB->Location = System::Drawing::Point(151, 60);
			this->MovNameTB->Name = L"MovNameTB";
			this->MovNameTB->Size = System::Drawing::Size(402, 20);
			this->MovNameTB->TabIndex = 26;
			// 
			// FillFieldsLbl
			// 
			this->FillFieldsLbl->AutoSize = true;
			this->FillFieldsLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->FillFieldsLbl->Location = System::Drawing::Point(206, 9);
			this->FillFieldsLbl->Name = L"FillFieldsLbl";
			this->FillFieldsLbl->Size = System::Drawing::Size(190, 26);
			this->FillFieldsLbl->TabIndex = 23;
			this->FillFieldsLbl->Text = L"Заполните поля";
			// 
			// MovRatingLbl
			// 
			this->MovRatingLbl->AutoSize = true;
			this->MovRatingLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovRatingLbl->Location = System::Drawing::Point(82, 151);
			this->MovRatingLbl->Name = L"MovRatingLbl";
			this->MovRatingLbl->Size = System::Drawing::Size(69, 20);
			this->MovRatingLbl->TabIndex = 20;
			this->MovRatingLbl->Text = L"Оценка:";
			// 
			// MovPosterPathLbl
			// 
			this->MovPosterPathLbl->AutoSize = true;
			this->MovPosterPathLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovPosterPathLbl->Location = System::Drawing::Point(25, 121);
			this->MovPosterPathLbl->Name = L"MovPosterPathLbl";
			this->MovPosterPathLbl->Size = System::Drawing::Size(126, 20);
			this->MovPosterPathLbl->TabIndex = 21;
			this->MovPosterPathLbl->Text = L"Путь к постеру:";
			// 
			// MovGenreLbl
			// 
			this->MovGenreLbl->AutoSize = true;
			this->MovGenreLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovGenreLbl->Location = System::Drawing::Point(98, 93);
			this->MovGenreLbl->Name = L"MovGenreLbl";
			this->MovGenreLbl->Size = System::Drawing::Size(53, 20);
			this->MovGenreLbl->TabIndex = 22;
			this->MovGenreLbl->Text = L"Жанр:";
			// 
			// MovNameLbl
			// 
			this->MovNameLbl->AutoSize = true;
			this->MovNameLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovNameLbl->Location = System::Drawing::Point(64, 60);
			this->MovNameLbl->Name = L"MovNameLbl";
			this->MovNameLbl->Size = System::Drawing::Size(87, 20);
			this->MovNameLbl->TabIndex = 18;
			this->MovNameLbl->Text = L"Название:";
			// 
			// MovDatePicker
			// 
			this->MovDatePicker->Location = System::Drawing::Point(151, 179);
			this->MovDatePicker->Name = L"MovDatePicker";
			this->MovDatePicker->Size = System::Drawing::Size(402, 20);
			this->MovDatePicker->TabIndex = 61;
			// 
			// MovAnnTB
			// 
			this->MovAnnTB->Location = System::Drawing::Point(151, 215);
			this->MovAnnTB->Multiline = true;
			this->MovAnnTB->Name = L"MovAnnTB";
			this->MovAnnTB->Size = System::Drawing::Size(402, 235);
			this->MovAnnTB->TabIndex = 60;
			this->MovAnnTB->TextChanged += gcnew System::EventHandler(this, &WAddMenu::MovAnnTB_TextChanged);
			// 
			// MovAnnotLbl
			// 
			this->MovAnnotLbl->AutoSize = true;
			this->MovAnnotLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovAnnotLbl->Location = System::Drawing::Point(54, 217);
			this->MovAnnotLbl->Name = L"MovAnnotLbl";
			this->MovAnnotLbl->Size = System::Drawing::Size(96, 20);
			this->MovAnnotLbl->TabIndex = 58;
			this->MovAnnotLbl->Text = L"Аннотация:";
			// 
			// MovDateLbl
			// 
			this->MovDateLbl->AutoSize = true;
			this->MovDateLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovDateLbl->Location = System::Drawing::Point(38, 179);
			this->MovDateLbl->Name = L"MovDateLbl";
			this->MovDateLbl->Size = System::Drawing::Size(112, 20);
			this->MovDateLbl->TabIndex = 59;
			this->MovDateLbl->Text = L"Дата выхода:";
			// 
			// MovAddButton
			// 
			this->MovAddButton->Enabled = false;
			this->MovAddButton->Location = System::Drawing::Point(413, 456);
			this->MovAddButton->Name = L"MovAddButton";
			this->MovAddButton->Size = System::Drawing::Size(140, 40);
			this->MovAddButton->TabIndex = 62;
			this->MovAddButton->Text = L"Добавить";
			this->MovAddButton->UseVisualStyleBackColor = true;
			this->MovAddButton->Click += gcnew System::EventHandler(this, &WAddMenu::AddMovButton_Click);
			// 
			// fileSystemWatcher1
			// 
			this->fileSystemWatcher1->EnableRaisingEvents = true;
			this->fileSystemWatcher1->SynchronizingObject = this;
			this->fileSystemWatcher1->Changed += gcnew System::IO::FileSystemEventHandler(this, &WAddMenu::fileSystemWatcher1_Changed);
			// 
			// MovGenreCB
			// 
			this->MovGenreCB->FormattingEnabled = true;
			this->MovGenreCB->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"Боевик", L"Детектив", L"Драма", L"Исторический",
					L"Комедия", L"Мелодрама", L"Приключение", L"Трагедия", L"Триллер", L"Документальный"
			});
			this->MovGenreCB->Location = System::Drawing::Point(151, 93);
			this->MovGenreCB->Name = L"MovGenreCB";
			this->MovGenreCB->Size = System::Drawing::Size(402, 21);
			this->MovGenreCB->TabIndex = 63;
			// 
			// WAddMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(586, 508);
			this->Controls->Add(this->MovGenreCB);
			this->Controls->Add(this->MovAddButton);
			this->Controls->Add(this->MovDatePicker);
			this->Controls->Add(this->MovAnnTB);
			this->Controls->Add(this->MovAnnotLbl);
			this->Controls->Add(this->MovDateLbl);
			this->Controls->Add(this->MovRatingNum);
			this->Controls->Add(this->MovPosterPathTB);
			this->Controls->Add(this->MovNameTB);
			this->Controls->Add(this->FillFieldsLbl);
			this->Controls->Add(this->MovRatingLbl);
			this->Controls->Add(this->MovPosterPathLbl);
			this->Controls->Add(this->MovGenreLbl);
			this->Controls->Add(this->MovNameLbl);
			this->Name = L"WAddMenu";
			this->Text = L"AddMovie";
			this->Load += gcnew System::EventHandler(this, &WAddMenu::WAddMenu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovRatingNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void fileSystemWatcher1_Changed(System::Object^ sender, System::IO::FileSystemEventArgs^ e) {
	
}
private: System::Void AddMovButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MovNameTB->Text->Length == 0 || MovGenreCB->SelectedIndex == -1 || MovPosterPathTB->Text->Length == 0
		|| MovAnnTB->Text->Length == 0) {
		MessageBox::Show("Введены не все данные");
		return;
	}
	
	tmpTitle = MovNameTB->Text;
	tmpGenre = MovGenreCB->SelectedText;
	tmpPosterPath = MovPosterPathTB->Text;
	tmpAnnotation = MovAnnTB->Text;
	tmpRating = (int) MovRatingNum->Value;
	tmpDate = System::DateTime(MovDatePicker->Value.Year, MovDatePicker->Value.Month, MovDatePicker->Value.Day);
	Movie^ mov = gcnew Movie(tmpTitle, tmpPosterPath, tmpGenre, tmpAnnotation, tmpDate, tmpRating);
	//WMainMenu::currentList->AddMovie(mov);
	MessageBox::Show("Фильм добавлен");
	return;
}

private: System::Void WAddMenu_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MovAnnTB_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
