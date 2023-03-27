#pragma once

namespace CarChoose {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ Car_box;
	protected:
	private: System::Windows::Forms::ListBox^ Model_box;

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
			this->Car_box = (gcnew System::Windows::Forms::ListBox());
			this->Model_box = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// Car_box
			// 
			this->Car_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Car_box->FormattingEnabled = true;
			this->Car_box->ItemHeight = 37;
			this->Car_box->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"BMW", L"Toyota", L"WAG", L"Lada" });
			this->Car_box->Location = System::Drawing::Point(63, 60);
			this->Car_box->Name = L"Car_box";
			this->Car_box->Size = System::Drawing::Size(270, 300);
			this->Car_box->TabIndex = 0;
			this->Car_box->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::Car_box_SelectedIndexChanged);
			// 
			// Model_box
			// 
			this->Model_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Model_box->FormattingEnabled = true;
			this->Model_box->ItemHeight = 37;
			this->Model_box->Location = System::Drawing::Point(465, 60);
			this->Model_box->Name = L"Model_box";
			this->Model_box->Size = System::Drawing::Size(226, 300);
			this->Model_box->TabIndex = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(812, 600);
			this->Controls->Add(this->Model_box);
			this->Controls->Add(this->Car_box);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Car_box_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Model_box->Items->Clear();
		String^ res = Car_box->Text;
		
		if (res == "BMW") {
			Model_box->Items->AddRange(gcnew cli::array<System::Object^>(6) {
				"X1", "X2",
					"X3",
					"X4",
					"X5",
					"X6"
			});
		}
		else if (res == "Lada") {
			Model_box->Items->AddRange(gcnew cli::array<System::Object^>(6) {
				"Xray", 
					"Vesta",
					"Granta",
					"Largus",
					"Niva",
					"4x4"
			});
		}

		
	}
	};
}
