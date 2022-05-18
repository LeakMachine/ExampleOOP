#pragma once
#include "class.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	RailTicketOffice rto;

	void MarshalString(String^ s, std::string& outputstring)
	{
		const char* kPtoC = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		outputstring = kPtoC;
		Marshal::FreeHGlobal(IntPtr((void*)kPtoC));
	}

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox2;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->checkedListBox2 = (gcnew System::Windows::Forms::CheckedListBox());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(781, 126);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(149, 22);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(781, 158);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(149, 22);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(781, 190);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(149, 22);
			this->textBox3->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(569, 113);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(148, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"æìè";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(284, 126);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(191, 212);
			this->listBox1->TabIndex = 7;
			// 
			// checkedListBox2
			// 
			this->checkedListBox2->FormattingEnabled = true;
			this->checkedListBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Ñèäÿ÷èé", L"Ïëàöêàðò", L"Êóïå" });
			this->checkedListBox2->Location = System::Drawing::Point(781, 340);
			this->checkedListBox2->Margin = System::Windows::Forms::Padding(4);
			this->checkedListBox2->Name = L"checkedListBox2";
			this->checkedListBox2->Size = System::Drawing::Size(149, 89);
			this->checkedListBox2->TabIndex = 4;
			this->checkedListBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::checkedListBox2_SelectedIndexChanged);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Ëàñòî÷êà", L"Ñêîðûé", L"Ôèðìåííûé" });
			this->checkedListBox1->Location = System::Drawing::Point(781, 234);
			this->checkedListBox1->Margin = System::Windows::Forms::Padding(4);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(149, 89);
			this->checkedListBox1->TabIndex = 0;
			this->checkedListBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::checkedListBox1_SelectedIndexChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1252, 692);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkedListBox2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->checkedListBox1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkedListBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string test;
	test = rto.orderFormCheque(0);
	listBox1->Items->Add(gcnew System::String(test.c_str()));
}
};
}
