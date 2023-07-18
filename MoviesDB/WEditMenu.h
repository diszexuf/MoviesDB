#pragma once

#include "Movie.h"
#include "MovieLinkedList.h"

namespace MoviesDB {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для WEditMenu
	/// </summary>
	public ref class WEditMenu : public System::Windows::Forms::Form
	{
	public:
		DateTime tmpDate; // временная переменная для формирования даты
		System::String^ MovPosterPath; // временная переменная для пути к постеру
		static Movie^ MovForEdit; // редактируемый фильм

	private: System::Windows::Forms::PictureBox^ poster;
	private: System::Windows::Forms::Button^ ResetBtn;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	public:
		WEditMenu(Movie^ movie) // конструктор формы
		{
			InitializeComponent();
			MovForEdit = movie; // принимаем переданный фильм во временную переменную
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~WEditMenu()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Label^ MovRatingLbl;
	private: System::Windows::Forms::Label^ MovGenreLbl;
	private: System::Windows::Forms::Label^ MovNameLbl;
	private: System::Windows::Forms::Label^ MovDateLbl;
	private: System::Windows::Forms::Label^ MovAnnotLbl;
	private: System::Windows::Forms::Button^ MovDelBtn;
	private: System::Windows::Forms::Button^ MovSaveBtn;
	private: System::Windows::Forms::DateTimePicker^ MovDatePrev;
	private: System::Windows::Forms::NumericUpDown^ MovRatingPrevNum;
	private: System::Windows::Forms::TextBox^ MovAnnPrevTB;
	private: System::Windows::Forms::TextBox^ MovNamePrevTB;
	private: System::Windows::Forms::Label^ MovInfoLbl;
	private: System::Windows::Forms::ComboBox^ MovGenreCB;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(WEditMenu::typeid));
			this->MovRatingLbl = (gcnew System::Windows::Forms::Label());
			this->MovGenreLbl = (gcnew System::Windows::Forms::Label());
			this->MovNameLbl = (gcnew System::Windows::Forms::Label());
			this->MovDateLbl = (gcnew System::Windows::Forms::Label());
			this->MovAnnotLbl = (gcnew System::Windows::Forms::Label());
			this->MovDelBtn = (gcnew System::Windows::Forms::Button());
			this->MovSaveBtn = (gcnew System::Windows::Forms::Button());
			this->MovDatePrev = (gcnew System::Windows::Forms::DateTimePicker());
			this->MovRatingPrevNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->MovAnnPrevTB = (gcnew System::Windows::Forms::TextBox());
			this->MovNamePrevTB = (gcnew System::Windows::Forms::TextBox());
			this->MovInfoLbl = (gcnew System::Windows::Forms::Label());
			this->MovGenreCB = (gcnew System::Windows::Forms::ComboBox());
			this->poster = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->ResetBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovRatingPrevNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->poster))->BeginInit();
			this->SuspendLayout();
			// 
			// MovRatingLbl
			// 
			this->MovRatingLbl->AutoSize = true;
			this->MovRatingLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovRatingLbl->Location = System::Drawing::Point(77, 123);
			this->MovRatingLbl->Name = L"MovRatingLbl";
			this->MovRatingLbl->Size = System::Drawing::Size(69, 20);
			this->MovRatingLbl->TabIndex = 41;
			this->MovRatingLbl->Text = L"Оценка:";
			// 
			// MovGenreLbl
			// 
			this->MovGenreLbl->AutoSize = true;
			this->MovGenreLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovGenreLbl->Location = System::Drawing::Point(93, 93);
			this->MovGenreLbl->Name = L"MovGenreLbl";
			this->MovGenreLbl->Size = System::Drawing::Size(53, 20);
			this->MovGenreLbl->TabIndex = 43;
			this->MovGenreLbl->Text = L"Жанр:";
			// 
			// MovNameLbl
			// 
			this->MovNameLbl->AutoSize = true;
			this->MovNameLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovNameLbl->Location = System::Drawing::Point(59, 60);
			this->MovNameLbl->Name = L"MovNameLbl";
			this->MovNameLbl->Size = System::Drawing::Size(87, 20);
			this->MovNameLbl->TabIndex = 40;
			this->MovNameLbl->Text = L"Название:";
			// 
			// MovDateLbl
			// 
			this->MovDateLbl->AutoSize = true;
			this->MovDateLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovDateLbl->Location = System::Drawing::Point(34, 154);
			this->MovDateLbl->Name = L"MovDateLbl";
			this->MovDateLbl->Size = System::Drawing::Size(112, 20);
			this->MovDateLbl->TabIndex = 41;
			this->MovDateLbl->Text = L"Дата выхода:";
			// 
			// MovAnnotLbl
			// 
			this->MovAnnotLbl->AutoSize = true;
			this->MovAnnotLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->MovAnnotLbl->Location = System::Drawing::Point(50, 180);
			this->MovAnnotLbl->Name = L"MovAnnotLbl";
			this->MovAnnotLbl->Size = System::Drawing::Size(96, 20);
			this->MovAnnotLbl->TabIndex = 41;
			this->MovAnnotLbl->Text = L"Аннотация:";
			// 
			// MovDelBtn
			// 
			this->MovDelBtn->Location = System::Drawing::Point(9, 423);
			this->MovDelBtn->Name = L"MovDelBtn";
			this->MovDelBtn->Size = System::Drawing::Size(137, 23);
			this->MovDelBtn->TabIndex = 58;
			this->MovDelBtn->Text = L"Удалить фильм";
			this->MovDelBtn->UseVisualStyleBackColor = true;
			this->MovDelBtn->Click += gcnew System::EventHandler(this, &WEditMenu::MovDelBtn_Click);
			// 
			// MovSaveBtn
			// 
			this->MovSaveBtn->Location = System::Drawing::Point(9, 452);
			this->MovSaveBtn->Name = L"MovSaveBtn";
			this->MovSaveBtn->Size = System::Drawing::Size(137, 23);
			this->MovSaveBtn->TabIndex = 58;
			this->MovSaveBtn->Text = L"Сохранить изменения";
			this->MovSaveBtn->UseVisualStyleBackColor = true;
			this->MovSaveBtn->Click += gcnew System::EventHandler(this, &WEditMenu::MovSaveBtn_Click);
			// 
			// MovDatePrev
			// 
			this->MovDatePrev->Location = System::Drawing::Point(176, 154);
			this->MovDatePrev->Name = L"MovDatePrev";
			this->MovDatePrev->Size = System::Drawing::Size(300, 20);
			this->MovDatePrev->TabIndex = 65;
			// 
			// MovRatingPrevNum
			// 
			this->MovRatingPrevNum->Location = System::Drawing::Point(176, 123);
			this->MovRatingPrevNum->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->MovRatingPrevNum->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->MovRatingPrevNum->Name = L"MovRatingPrevNum";
			this->MovRatingPrevNum->Size = System::Drawing::Size(300, 20);
			this->MovRatingPrevNum->TabIndex = 64;
			this->MovRatingPrevNum->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// MovAnnPrevTB
			// 
			this->MovAnnPrevTB->Location = System::Drawing::Point(176, 180);
			this->MovAnnPrevTB->Multiline = true;
			this->MovAnnPrevTB->Name = L"MovAnnPrevTB";
			this->MovAnnPrevTB->Size = System::Drawing::Size(300, 269);
			this->MovAnnPrevTB->TabIndex = 60;
			// 
			// MovNamePrevTB
			// 
			this->MovNamePrevTB->Location = System::Drawing::Point(176, 60);
			this->MovNamePrevTB->Name = L"MovNamePrevTB";
			this->MovNamePrevTB->Size = System::Drawing::Size(300, 20);
			this->MovNamePrevTB->TabIndex = 63;
			// 
			// MovInfoLbl
			// 
			this->MovInfoLbl->AutoSize = true;
			this->MovInfoLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MovInfoLbl->Location = System::Drawing::Point(250, 9);
			this->MovInfoLbl->Name = L"MovInfoLbl";
			this->MovInfoLbl->Size = System::Drawing::Size(165, 20);
			this->MovInfoLbl->TabIndex = 59;
			this->MovInfoLbl->Text = L"Данные о фильмы";
			// 
			// MovGenreCB
			// 
			this->MovGenreCB->FormattingEnabled = true;
			this->MovGenreCB->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"Боевик", L"Детектив", L"Драма", L"Исторический",
					L"Комедия", L"Мелодрама", L"Приключение", L"Трагедия", L"Триллер", L"Документальный"
			});
			this->MovGenreCB->Location = System::Drawing::Point(176, 92);
			this->MovGenreCB->Name = L"MovGenreCB";
			this->MovGenreCB->Size = System::Drawing::Size(280, 21);
			this->MovGenreCB->TabIndex = 66;
			this->MovGenreCB->SelectedIndexChanged += gcnew System::EventHandler(this, &WEditMenu::MovGenreCB_SelectedIndexChanged);
			// 
			// poster
			// 
			this->poster->BackColor = System::Drawing::SystemColors::ControlDark;
			this->poster->Location = System::Drawing::Point(12, 222);
			this->poster->Name = L"poster";
			this->poster->Size = System::Drawing::Size(134, 148);
			this->poster->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->poster->TabIndex = 67;
			this->poster->TabStop = false;
			this->poster->Click += gcnew System::EventHandler(this, &WEditMenu::poster_Click);
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
			this->ResetBtn->Location = System::Drawing::Point(452, 92);
			this->ResetBtn->Name = L"ResetBtn";
			this->ResetBtn->Size = System::Drawing::Size(24, 21);
			this->ResetBtn->TabIndex = 68;
			this->ResetBtn->UseVisualStyleBackColor = false;
			this->ResetBtn->Click += gcnew System::EventHandler(this, &WEditMenu::ResetBtn_Click);
			// 
			// WEditMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(501, 498);
			this->Controls->Add(this->ResetBtn);
			this->Controls->Add(this->poster);
			this->Controls->Add(this->MovGenreCB);
			this->Controls->Add(this->MovDatePrev);
			this->Controls->Add(this->MovRatingPrevNum);
			this->Controls->Add(this->MovAnnPrevTB);
			this->Controls->Add(this->MovNamePrevTB);
			this->Controls->Add(this->MovInfoLbl);
			this->Controls->Add(this->MovSaveBtn);
			this->Controls->Add(this->MovDelBtn);
			this->Controls->Add(this->MovAnnotLbl);
			this->Controls->Add(this->MovDateLbl);
			this->Controls->Add(this->MovRatingLbl);
			this->Controls->Add(this->MovGenreLbl);
			this->Controls->Add(this->MovNameLbl);
			this->Name = L"WEditMenu";
			this->Text = L"MoviesDB";
			this->Load += gcnew System::EventHandler(this, &WEditMenu::WEditMenu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MovRatingPrevNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->poster))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void WEditMenu_Load(System::Object^ sender, System::EventArgs^ e) {
		// выставляем в поля данные о фильме для редактирования 
		MovNamePrevTB->Text = MovForEdit->Title;
		MovGenreCB->Text = MovForEdit->Genre;
		MovAnnPrevTB->Text = MovForEdit->Annotation;
		MovDatePrev->Value = MovForEdit->RealeaseDate;
		MovPosterPath = MovForEdit->PosterPath;
		if (System::IO::File::Exists(MovForEdit->PosterPath) == true) { // проверяем существование файла, в ином случае убираем изображение
			Bitmap^ img = gcnew Bitmap(MovForEdit->PosterPath);
			poster->Image = img;
		}
		else
		{
			poster->Image = nullptr;
		}
	}

	private: System::Void MovDelBtn_Click(System::Object^ sender, System::EventArgs^ e) { // обработчик кнопки удаления
		MovForEdit->Title = ""; // флаг для удаления фильма 
		MessageBox::Show("Фильм удален"); // информирование об удалении (операция удаления в главном окне)
		this->Close(); // закрываем окно
	}

	private: System::Void MovSaveBtn_Click(System::Object^ sender, System::EventArgs^ e) { // обработчик кнопки сохранения
		tmpDate = DateTime(MovDatePrev->Value.Year, MovDatePrev->Value.Month, MovDatePrev->Value.Day); // формирование новой даты
		MovForEdit = gcnew Movie(MovNamePrevTB->Text, MovPosterPath, (System::String^)MovGenreCB->Items[0], MovAnnPrevTB->Text, tmpDate, (int)MovRatingPrevNum->Value); // редактируем данные
		MessageBox::Show("Изменения сохранены"); // информировани о сохранении (операция сохранения в главном окне)
		this->Close(); // закрываем окно
	}

	private: System::Void poster_Click(System::Object^ sender, System::EventArgs^ e) { // обработка клику по постеру
		OpenFileDialog^ PosterPathDialog = gcnew OpenFileDialog();
		PosterPathDialog->Filter = "image files (*.png)|*.png"; // проверка расширения
		// считываем и устанавливаем новое изображение
		if (PosterPathDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			MovPosterPath = PosterPathDialog->FileName;
			Bitmap^ imageFile = gcnew Bitmap(PosterPathDialog->FileName);
			poster->Image = imageFile;
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
