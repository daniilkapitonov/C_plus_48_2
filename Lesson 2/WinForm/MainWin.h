#pragma once

namespace WinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainWin
	/// </summary>
	public ref class MainWin : public System::Windows::Forms::Form
	{
	public:
		MainWin(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainWin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ text_zone;
	private: System::Windows::Forms::TextBox^ textBox1;

	protected:







	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->text_zone = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(365, 296);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(152, 62);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainWin::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(120, 296);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(136, 62);
			this->button2->TabIndex = 1;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainWin::button2_Click);
			// 
			// text_zone
			// 
			this->text_zone->AutoSize = true;
			this->text_zone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->text_zone->Location = System::Drawing::Point(49, 80);
			this->text_zone->Name = L"text_zone";
			this->text_zone->Size = System::Drawing::Size(90, 44);
			this->text_zone->TabIndex = 3;
			this->text_zone->Text = L"TXT";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(276, 52);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(302, 199);
			this->textBox1->TabIndex = 4;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MainWin::textBox1_TextChanged);
			// 
			// MainWin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(767, 520);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->text_zone);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MainWin";
			this->Text = L"MainWin";
			this->Load += gcnew System::EventHandler(this, &MainWin::MainWin_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainWin_Load(System::Object^ sender, System::EventArgs^ e) {
		text_zone->Text = "Hello!";
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		text_zone->Hide();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		text_zone->Show();
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		text_zone->Text = textBox1->Text;
	}	

};
}
