#pragma once

namespace MoviesDB {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для WGreeting
	/// </summary>
	public ref class WGreeting : public System::Windows::Forms::Form
	{
	public:
		WGreeting(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~WGreeting()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::ImageList^ imageList1;
	private: System::Windows::Forms::Button^ OkBtn;
	private: System::Windows::Forms::Label^ GreetLbl;

	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(WGreeting::typeid));
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->OkBtn = (gcnew System::Windows::Forms::Button());
			this->GreetLbl = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"wallpaperflare.com_wallpaper.jpg");
			// 
			// OkBtn
			// 
			this->OkBtn->AutoSize = true;
			this->OkBtn->Location = System::Drawing::Point(110, 50);
			this->OkBtn->Margin = System::Windows::Forms::Padding(2);
			this->OkBtn->Name = L"OkBtn";
			this->OkBtn->Size = System::Drawing::Size(96, 23);
			this->OkBtn->TabIndex = 3;
			this->OkBtn->Text = L"Продолжить";
			this->OkBtn->UseVisualStyleBackColor = true;
			this->OkBtn->Click += gcnew System::EventHandler(this, &WGreeting::OkButton_Click);
			// 
			// GreetLbl
			// 
			this->GreetLbl->AutoEllipsis = true;
			this->GreetLbl->Location = System::Drawing::Point(11, 9);
			this->GreetLbl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GreetLbl->Name = L"GreetLbl";
			this->GreetLbl->Size = System::Drawing::Size(285, 39);
			this->GreetLbl->TabIndex = 2;
			this->GreetLbl->Text = L"Вас приветствует MoviesDB! Приложение для работы с базой данных фильмов.";
			this->GreetLbl->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// WGreeting
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(315, 86);
			this->Controls->Add(this->OkBtn);
			this->Controls->Add(this->GreetLbl);
			this->Name = L"WGreeting";
			this->Text = L"MoviesDB";
			this->Load += gcnew System::EventHandler(this, &WGreeting::WGreeting_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}


private: System::Void WGreeting_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void OkButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
	
};
}
