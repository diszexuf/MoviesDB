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
	private: System::Windows::Forms::PictureBox^ MovPoster;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
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
	private: System::String^ MovPosterPath;
	public: static Movie^ mov;

	private: System::Windows::Forms::NumericUpDown^ MovRatingNum;
	private: System::Windows::Forms::TextBox^ MovNameTB;
	private: System::Windows::Forms::Label^ FillFieldsLbl;
	private: System::Windows::Forms::Label^ MovRatingLbl;
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
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->MovRatingNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->MovNameTB = (gcnew System::Windows::Forms::TextBox());
			this->FillFieldsLbl = (gcnew System::Windows::Forms::Label());
			this->MovRatingLbl = (gcnew System::Windows::Forms::Label());
			this->MovGenreLbl = (gcnew System::Windows::Forms::Label());
			this->MovNameLbl = (gcnew System::Windows::Forms::Label());
			this->MovDatePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->MovAnnTB = (gcnew System::Windows::Forms::TextBox());
			this->MovAnnotLbl = (gcnew System::Windows::Forms::Label());
			this->MovDateLbl = (gcnew System::Windows::Forms::Label());
			this->MovAddButton = (gcnew System::Windows::Forms::Button());
			this->fileSystemWatcher1 = (gcnew System::IO::FileSystemWatcher());
			this->MovGenreCB = (gcnew System::Windows::Forms::ComboBox());
			this->MovPoster = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovRatingNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovPoster))->BeginInit();
			this->SuspendLayout();
			// 
			// MovRatingNum
			// 
			this->MovRatingNum->Location = System::Drawing::Point(172, 105);
			this->MovRatingNum->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->MovRatingNum->Name = L"MovRatingNum";
			this->MovRatingNum->Size = System::Drawing::Size(402, 20);
			this->MovRatingNum->TabIndex = 28;
			// 
			// MovNameTB
			// 
			this->MovNameTB->Location = System::Drawing::Point(172, 45);
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
			this->MovRatingLbl->Location = System::Drawing::Point(103, 105);
			this->MovRatingLbl->Name = L"MovRatingLbl";
			this->MovRatingLbl->Size = System::Drawing::Size(69, 20);
			this->MovRatingLbl->TabIndex = 20;
			this->MovRatingLbl->Text = L"Оценка:";
			// 
			// MovGenreLbl
			// 
			this->MovGenreLbl->AutoSize = true;
			this->MovGenreLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovGenreLbl->Location = System::Drawing::Point(119, 78);
			this->MovGenreLbl->Name = L"MovGenreLbl";
			this->MovGenreLbl->Size = System::Drawing::Size(53, 20);
			this->MovGenreLbl->TabIndex = 22;
			this->MovGenreLbl->Text = L"Жанр:";
			// 
			// MovNameLbl
			// 
			this->MovNameLbl->AutoSize = true;
			this->MovNameLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovNameLbl->Location = System::Drawing::Point(85, 45);
			this->MovNameLbl->Name = L"MovNameLbl";
			this->MovNameLbl->Size = System::Drawing::Size(87, 20);
			this->MovNameLbl->TabIndex = 18;
			this->MovNameLbl->Text = L"Название:";
			// 
			// MovDatePicker
			// 
			this->MovDatePicker->Location = System::Drawing::Point(172, 133);
			this->MovDatePicker->Name = L"MovDatePicker";
			this->MovDatePicker->Size = System::Drawing::Size(402, 20);
			this->MovDatePicker->TabIndex = 61;
			this->MovDatePicker->ValueChanged += gcnew System::EventHandler(this, &WAddMenu::MovDatePicker_ValueChanged);
			// 
			// MovAnnTB
			// 
			this->MovAnnTB->Location = System::Drawing::Point(172, 162);
			this->MovAnnTB->Multiline = true;
			this->MovAnnTB->Name = L"MovAnnTB";
			this->MovAnnTB->Size = System::Drawing::Size(402, 266);
			this->MovAnnTB->TabIndex = 60;
			this->MovAnnTB->TextChanged += gcnew System::EventHandler(this, &WAddMenu::MovAnnTB_TextChanged);
			// 
			// MovAnnotLbl
			// 
			this->MovAnnotLbl->AutoSize = true;
			this->MovAnnotLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovAnnotLbl->Location = System::Drawing::Point(76, 163);
			this->MovAnnotLbl->Name = L"MovAnnotLbl";
			this->MovAnnotLbl->Size = System::Drawing::Size(96, 20);
			this->MovAnnotLbl->TabIndex = 58;
			this->MovAnnotLbl->Text = L"Аннотация:";
			// 
			// MovDateLbl
			// 
			this->MovDateLbl->AutoSize = true;
			this->MovDateLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovDateLbl->Location = System::Drawing::Point(59, 133);
			this->MovDateLbl->Name = L"MovDateLbl";
			this->MovDateLbl->Size = System::Drawing::Size(112, 20);
			this->MovDateLbl->TabIndex = 59;
			this->MovDateLbl->Text = L"Дата выхода:";
			// 
			// MovAddButton
			// 
			this->MovAddButton->Location = System::Drawing::Point(434, 456);
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
			this->MovGenreCB->Location = System::Drawing::Point(172, 78);
			this->MovGenreCB->Name = L"MovGenreCB";
			this->MovGenreCB->Size = System::Drawing::Size(402, 21);
			this->MovGenreCB->TabIndex = 63;
			this->MovGenreCB->Text = L"Выберите жанр";
			// 
			// MovPoster
			// 
			this->MovPoster->BackColor = System::Drawing::SystemColors::ControlDark;
			this->MovPoster->Location = System::Drawing::Point(12, 199);
			this->MovPoster->Name = L"MovPoster";
			this->MovPoster->Size = System::Drawing::Size(154, 229);
			this->MovPoster->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->MovPoster->TabIndex = 64;
			this->MovPoster->TabStop = false;
			this->MovPoster->Click += gcnew System::EventHandler(this, &WAddMenu::MovPoster_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// WAddMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(586, 508);
			this->Controls->Add(this->MovPoster);
			this->Controls->Add(this->MovGenreCB);
			this->Controls->Add(this->MovAddButton);
			this->Controls->Add(this->MovDatePicker);
			this->Controls->Add(this->MovAnnTB);
			this->Controls->Add(this->MovAnnotLbl);
			this->Controls->Add(this->MovDateLbl);
			this->Controls->Add(this->MovRatingNum);
			this->Controls->Add(this->MovNameTB);
			this->Controls->Add(this->FillFieldsLbl);
			this->Controls->Add(this->MovRatingLbl);
			this->Controls->Add(this->MovGenreLbl);
			this->Controls->Add(this->MovNameLbl);
			this->Name = L"WAddMenu";
			this->Text = L"AddMovie";
			this->Load += gcnew System::EventHandler(this, &WAddMenu::WAddMenu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovRatingNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovPoster))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void fileSystemWatcher1_Changed(System::Object^ sender, System::IO::FileSystemEventArgs^ e) {

	}
	private: System::Void AddMovButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MovNameTB->Text->Length == 0 || MovGenreCB->SelectedIndex == -1 || MovAnnTB->Text->Length == 0) {
			MessageBox::Show("Введены не все данные");
			return;
		}

		tmpTitle = MovNameTB->Text;
		tmpGenre = MovGenreCB->SelectedText;
		tmpPosterPath = MovPosterPath;
		tmpAnnotation = MovAnnTB->Text;
		tmpRating = (int)MovRatingNum->Value;
		tmpDate = System::DateTime(MovDatePicker->Value.Year, MovDatePicker->Value.Month, MovDatePicker->Value.Day);
		mov = gcnew Movie(tmpTitle, tmpPosterPath, tmpGenre, tmpAnnotation, tmpDate, tmpRating);
		MessageBox::Show("Фильм добавлен");
		this->Close();
		return;
	}

	private: System::Void WAddMenu_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void MovAnnTB_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void MovPoster_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ PosterPathDialog = gcnew OpenFileDialog();
		PosterPathDialog->Filter = "image files (*.png)|*.png";
		//Bitmap^ imageFile;
		if (PosterPathDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			MovPosterPath = PosterPathDialog->FileName;
			Bitmap^ imageFile = gcnew Bitmap(PosterPathDialog->FileName);
			MovPoster->Image = imageFile;
		}
	}

	private: System::Void MovDatePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		System::DateTime date = MovDatePicker->Value;
		if (System::DateTime::Compare(date, System::DateTime::Now) > 0) {
			MovRatingNum->Enabled = false;
		}
		else
		{
			MovRatingNum->Enabled = true;
		}
	}
	};
}
