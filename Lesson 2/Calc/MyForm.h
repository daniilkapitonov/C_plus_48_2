#pragma once
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;
namespace Calc {

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
	private: System::Windows::Forms::TextBox^ num_1;
	protected:
	private: System::Windows::Forms::TextBox^ num_2;
	private: System::Windows::Forms::Label^ res;
	private: System::Windows::Forms::Button^ plus;

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
			this->num_1 = (gcnew System::Windows::Forms::TextBox());
			this->num_2 = (gcnew System::Windows::Forms::TextBox());
			this->res = (gcnew System::Windows::Forms::Label());
			this->plus = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// num_1
			// 
			this->num_1->Location = System::Drawing::Point(100, 80);
			this->num_1->Name = L"num_1";
			this->num_1->Size = System::Drawing::Size(47, 31);
			this->num_1->TabIndex = 0;
			this->num_1->TextChanged += gcnew System::EventHandler(this, &MyForm::num_1_TextChanged);
			// 
			// num_2
			// 
			this->num_2->Location = System::Drawing::Point(217, 80);
			this->num_2->Name = L"num_2";
			this->num_2->Size = System::Drawing::Size(47, 31);
			this->num_2->TabIndex = 1;
			this->num_2->TextChanged += gcnew System::EventHandler(this, &MyForm::num_2_TextChanged);
			// 
			// res
			// 
			this->res->AutoSize = true;
			this->res->Location = System::Drawing::Point(344, 80);
			this->res->Name = L"res";
			this->res->Size = System::Drawing::Size(0, 25);
			this->res->TabIndex = 2;
			// 
			// plus
			// 
			this->plus->Location = System::Drawing::Point(179, 225);
			this->plus->Name = L"plus";
			this->plus->Size = System::Drawing::Size(94, 44);
			this->plus->TabIndex = 3;
			this->plus->Text = L"+";
			this->plus->UseVisualStyleBackColor = true;
			this->plus->Click += gcnew System::EventHandler(this, &MyForm::plus_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(464, 375);
			this->Controls->Add(this->plus);
			this->Controls->Add(this->res);
			this->Controls->Add(this->num_2);
			this->Controls->Add(this->num_1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void plus_Click(System::Object^ sender, System::EventArgs^ e) {
		if (num_1->Text != "" && num_2->Text != "") {
			res->Text = Convert::ToString(Convert::ToInt32(num_1->Text) + Convert::ToInt32(num_2->Text));
		}
		else {
			res->Text = "Error.";
		}
	}
	private: System::Void num_1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		Calculate();
	}
	private: System::Void num_2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		Calculate();
	}
	private: void Calculate() {
		if (num_1->Text != "" && num_2->Text != "") {
			res->Text = Convert::ToString(Convert::ToInt32(num_1->Text) + Convert::ToInt32(num_2->Text));
		}
		else {
			res->Text = "Error.";
		}
	}
};
}
