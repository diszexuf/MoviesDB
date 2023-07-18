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
		String^ tmpGenre = "";
		String^ tmpPosterPath;
		String^ tmpAnnotation;
		int tmpRating;
	private: System::Windows::Forms::ComboBox^ MovGenreCB;
	private: System::Windows::Forms::PictureBox^ MovPoster;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ ResetBtn;

	public: System::String^ DirectoryPath;

	public:
		DateTime tmpDate; // временная переменная для формирования даты
	public:
		WAddMenu(String^ directoryPath)
		{
			DirectoryPath = directoryPath;
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
	public: static Movie^ mov; // временная переменная для хранения данных о добавляемом фильме

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(WAddMenu::typeid));
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
			this->ResetBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovRatingNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovPoster))->BeginInit();
			this->SuspendLayout();
			// 
			// MovRatingNum
			// 
			this->MovRatingNum->Location = System::Drawing::Point(229, 129);
			this->MovRatingNum->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovRatingNum->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->MovRatingNum->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->MovRatingNum->Name = L"MovRatingNum";
			this->MovRatingNum->Size = System::Drawing::Size(536, 22);
			this->MovRatingNum->TabIndex = 28;
			this->MovRatingNum->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// MovNameTB
			// 
			this->MovNameTB->Location = System::Drawing::Point(229, 55);
			this->MovNameTB->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovNameTB->Name = L"MovNameTB";
			this->MovNameTB->Size = System::Drawing::Size(535, 22);
			this->MovNameTB->TabIndex = 26;
			// 
			// FillFieldsLbl
			// 
			this->FillFieldsLbl->AutoSize = true;
			this->FillFieldsLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold));
			this->FillFieldsLbl->Location = System::Drawing::Point(275, 11);
			this->FillFieldsLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->FillFieldsLbl->Name = L"FillFieldsLbl";
			this->FillFieldsLbl->Size = System::Drawing::Size(229, 31);
			this->FillFieldsLbl->TabIndex = 23;
			this->FillFieldsLbl->Text = L"Заполните поля";
			// 
			// MovRatingLbl
			// 
			this->MovRatingLbl->AutoSize = true;
			this->MovRatingLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovRatingLbl->Location = System::Drawing::Point(137, 129);
			this->MovRatingLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MovRatingLbl->Name = L"MovRatingLbl";
			this->MovRatingLbl->Size = System::Drawing::Size(87, 25);
			this->MovRatingLbl->TabIndex = 20;
			this->MovRatingLbl->Text = L"Оценка:";
			// 
			// MovGenreLbl
			// 
			this->MovGenreLbl->AutoSize = true;
			this->MovGenreLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovGenreLbl->Location = System::Drawing::Point(159, 96);
			this->MovGenreLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MovGenreLbl->Name = L"MovGenreLbl";
			this->MovGenreLbl->Size = System::Drawing::Size(69, 25);
			this->MovGenreLbl->TabIndex = 22;
			this->MovGenreLbl->Text = L"Жанр:";
			// 
			// MovNameLbl
			// 
			this->MovNameLbl->AutoSize = true;
			this->MovNameLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovNameLbl->Location = System::Drawing::Point(113, 55);
			this->MovNameLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MovNameLbl->Name = L"MovNameLbl";
			this->MovNameLbl->Size = System::Drawing::Size(105, 25);
			this->MovNameLbl->TabIndex = 18;
			this->MovNameLbl->Text = L"Название:";
			// 
			// MovDatePicker
			// 
			this->MovDatePicker->Location = System::Drawing::Point(229, 164);
			this->MovDatePicker->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovDatePicker->Name = L"MovDatePicker";
			this->MovDatePicker->Size = System::Drawing::Size(535, 22);
			this->MovDatePicker->TabIndex = 61;
			this->MovDatePicker->ValueChanged += gcnew System::EventHandler(this, &WAddMenu::MovDatePicker_ValueChanged);
			// 
			// MovAnnTB
			// 
			this->MovAnnTB->Location = System::Drawing::Point(229, 199);
			this->MovAnnTB->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovAnnTB->Multiline = true;
			this->MovAnnTB->Name = L"MovAnnTB";
			this->MovAnnTB->Size = System::Drawing::Size(535, 326);
			this->MovAnnTB->TabIndex = 60;
			// 
			// MovAnnotLbl
			// 
			this->MovAnnotLbl->AutoSize = true;
			this->MovAnnotLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovAnnotLbl->Location = System::Drawing::Point(101, 201);
			this->MovAnnotLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MovAnnotLbl->Name = L"MovAnnotLbl";
			this->MovAnnotLbl->Size = System::Drawing::Size(120, 25);
			this->MovAnnotLbl->TabIndex = 58;
			this->MovAnnotLbl->Text = L"Аннотация:";
			// 
			// MovDateLbl
			// 
			this->MovDateLbl->AutoSize = true;
			this->MovDateLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovDateLbl->Location = System::Drawing::Point(79, 164);
			this->MovDateLbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MovDateLbl->Name = L"MovDateLbl";
			this->MovDateLbl->Size = System::Drawing::Size(139, 25);
			this->MovDateLbl->TabIndex = 59;
			this->MovDateLbl->Text = L"Дата выхода:";
			// 
			// MovAddButton
			// 
			this->MovAddButton->Location = System::Drawing::Point(579, 561);
			this->MovAddButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovAddButton->Name = L"MovAddButton";
			this->MovAddButton->Size = System::Drawing::Size(187, 49);
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
			this->MovGenreCB->Items->AddRange(gcnew cli::array< System::Object^  >(14) {
				L"", L"Боевик", L"Детектив", L"Драма", L"Исторический",
					L"Комедия", L"Мелодрама", L"Приключение", L"Трагедия", L"Триллер", L"Документальный", L"Фантастика", L"Фэнтези", L"Криминал"
			});
			this->MovGenreCB->Location = System::Drawing::Point(229, 96);
			this->MovGenreCB->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovGenreCB->Name = L"MovGenreCB";
			this->MovGenreCB->Size = System::Drawing::Size(505, 24);
			this->MovGenreCB->TabIndex = 63;
			this->MovGenreCB->Text = L"Выберите жанр";
			this->MovGenreCB->SelectedIndexChanged += gcnew System::EventHandler(this, &WAddMenu::MovGenreCB_SelectedIndexChanged);
			// 
			// MovPoster
			// 
			this->MovPoster->BackColor = System::Drawing::SystemColors::ControlDark;
			this->MovPoster->Location = System::Drawing::Point(16, 245);
			this->MovPoster->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MovPoster->Name = L"MovPoster";
			this->MovPoster->Size = System::Drawing::Size(205, 282);
			this->MovPoster->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->MovPoster->TabIndex = 64;
			this->MovPoster->TabStop = false;
			this->MovPoster->Click += gcnew System::EventHandler(this, &WAddMenu::MovPoster_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// ResetBtn
			// 
			this->ResetBtn->BackColor = System::Drawing::SystemColors::ControlDark;
			this->ResetBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ResetBtn.BackgroundImage")));
			this->ResetBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ResetBtn->Location = System::Drawing::Point(733, 96);
			this->ResetBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->ResetBtn->Name = L"ResetBtn";
			this->ResetBtn->Size = System::Drawing::Size(32, 26);
			this->ResetBtn->TabIndex = 65;
			this->ResetBtn->UseVisualStyleBackColor = false;
			this->ResetBtn->Click += gcnew System::EventHandler(this, &WAddMenu::ResetBtn_Click);
			// 
			// WAddMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(781, 625);
			this->Controls->Add(this->ResetBtn);
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
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"WAddMenu";
			this->Text = L"MoviesDB";
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

	private: System::Void AddMovButton_Click(System::Object^ sender, System::EventArgs^ e) { // обработчик кнопки добавления
		if (MovNameTB->Text->Length == 0 || MovGenreCB->SelectedIndex == -1 || MovAnnTB->Text->Length == 0) { // проверка заполненности обязательных полей
			MessageBox::Show("Введены не все данные"); // предупреждение
			return;
		}
		// сбор данных
		tmpTitle = MovNameTB->Text;
		tmpGenre = (System::String^)MovGenreCB->Items[0];
		tmpAnnotation = MovAnnTB->Text->Replace("\n", "");
		if (MovRatingNum->Enabled == true) { // если фильм не вышел, то ставим рейтинг 0
			tmpRating = (int)MovRatingNum->Value;
		}
		else
		{
			tmpRating = 0;
		}

		tmpDate = System::DateTime(MovDatePicker->Value.Year, MovDatePicker->Value.Month, MovDatePicker->Value.Day);
		mov = gcnew Movie(tmpTitle, tmpPosterPath, tmpGenre, tmpAnnotation, tmpDate, tmpRating); // создаем экзмемпляр класса Movie для добавления в список
		MessageBox::Show("Фильм добавлен"); // уведомление о добавлении
		this->Close(); // закрываем окно
		return;
	}

	private: System::Void WAddMenu_Load(System::Object^ sender, System::EventArgs^ e) { // загрузчик окна
		tmpPosterPath = "\\default.png";
		Bitmap^ defaultposter = gcnew Bitmap(DirectoryPath + tmpPosterPath);
		MovPoster->Image = defaultposter; // ставим вместо постера default изображение, чтобы в случае отсутствия постера ставилось оно
	}

	private: System::Void MovPoster_Click(System::Object^ sender, System::EventArgs^ e) { // обработчик клика по постеру
		OpenFileDialog^ PosterPathDialog = gcnew OpenFileDialog();
		PosterPathDialog->Filter = "image files (*.png)|*.png"; // проверка расширения файла
		if (PosterPathDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) { // в случае успеха считываем путь
			tmpPosterPath = "\\" + PosterPathDialog->SafeFileName;
			Bitmap^ imageFile = gcnew Bitmap(DirectoryPath + tmpPosterPath);
			MovPoster->Image = imageFile; // устанавливаем изображение в PictureBox
		}
	}

	private: System::Void MovDatePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e) { // обработчик даты
		System::DateTime date = MovDatePicker->Value;
		if (System::DateTime::Compare(date, System::DateTime::Now) > 0) { // если фильм не вышел, то блокируем форму для изменения рейтинга
			MovRatingNum->Enabled = false;
		}
		else
		{
			MovRatingNum->Enabled = true;
		}
	}

	private: System::Void MovGenreCB_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (MovGenreCB->SelectedIndex > 0) { // проверка, что выбранный элемент не нулевой
			if (MovGenreCB->Items[0] == "") { // проверка на первый выбор
				MovGenreCB->Items[0] = MovGenreCB->Items[MovGenreCB->SelectedIndex];
			}
			else if (!MovGenreCB->Items[0]->ToString()->Contains(MovGenreCB->Items[MovGenreCB->SelectedIndex]->ToString()))
			{
				MovGenreCB->Items[0] += ", " + MovGenreCB->Items[MovGenreCB->SelectedIndex];
			}
			MovGenreCB->SelectedIndex = 0; // выбор 0-го элемента для показа выбранных жанров
			return;
		}
	}

	private: System::Void ResetBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		MovGenreCB->Items[0] = "";
	}
	};
}
