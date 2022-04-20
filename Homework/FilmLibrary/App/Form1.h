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

	filmLibrary films[10];

	void MarshalString(String^ s, std::string& outputstring)
	{
		const char* kPtoC = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		outputstring = kPtoC;
		Marshal::FreeHGlobal(IntPtr((void*)kPtoC));
	}

	/// <summary>
	/// Zusammenfassung fьr Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufьgen.
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
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;

	protected:


















	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode fьr die Designerunterstьtzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geдndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(482, 251);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(12, 27);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(434, 276);
			this->listBox1->TabIndex = 3;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox1_SelectedIndexChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(482, 309);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Удалить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(482, 139);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(482, 167);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 6;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(482, 195);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 8;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(482, 223);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 7;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(482, 27);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 22);
			this->textBox5->TabIndex = 10;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(482, 55);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 22);
			this->textBox6->TabIndex = 9;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(482, 83);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 22);
			this->textBox7->TabIndex = 12;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(482, 111);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 22);
			this->textBox8->TabIndex = 11;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(482, 280);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 23);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Изменить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(13, 366);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(158, 23);
			this->button4->TabIndex = 14;
			this->button4->Text = L"button4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(13, 338);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(158, 22);
			this->textBox9->TabIndex = 15;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(479, 3);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 17);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Ввод данных";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(602, 144);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 17);
			this->label1->TabIndex = 19;
			this->label1->Text = L"День выхода";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(602, 173);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(101, 17);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Месяц выхода";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(602, 200);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(83, 17);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Год выхода";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(602, 228);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 17);
			this->label5->TabIndex = 22;
			this->label5->Text = L"Сборы";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(602, 116);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(88, 17);
			this->label6->TabIndex = 26;
			this->label6->Text = L"Композитор";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(602, 88);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(79, 17);
			this->label7->TabIndex = 25;
			this->label7->Text = L"Сценарист";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(602, 61);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(72, 17);
			this->label8->TabIndex = 24;
			this->label8->Text = L"Режиссёр";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(602, 32);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(127, 17);
			this->label9->TabIndex = 23;
			this->label9->Text = L"Название фильма";
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Найти по названию", L"Найти по году", L"Все фильмы заданного режиссёра",
					L"Число фильмов с наибольшими сборами", L"Число фильмов с наибольшими сборами в выбранном году", L"Текущее число фильмов"
			});
			this->checkedListBox1->Location = System::Drawing::Point(192, 338);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(423, 106);
			this->checkedListBox1->TabIndex = 27;
			this->checkedListBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::checkedListBox1_SelectedIndexChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(950, 477);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->Text = L"memes";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		int i = 0;

		private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (i == 10)
		{
			return;
		}
		else {
			std::string nameTemp;
			String^ nameStrTemp = textBox5->Text;
			MarshalString(nameStrTemp, nameTemp);

			std::string producerTemp;
			String^ producerStrTemp = textBox7->Text;
			MarshalString(producerStrTemp, producerTemp);

			std::string screenwriterTemp;
			String^ screenwriterStrTemp = textBox8->Text;
			MarshalString(screenwriterStrTemp, screenwriterTemp);

			std::string composerTemp;
			String^ composerStrTemp = textBox6->Text;
			MarshalString(composerStrTemp, composerTemp);

			films[i].setDay(int::Parse(textBox1->Text));
			films[i].setMonth(int::Parse(textBox2->Text));
			films[i].setYear(int::Parse(textBox3->Text));
			films[i].setProfit(int::Parse(textBox4->Text));
			films[i].setName(nameTemp);
			films[i].setProducer(producerTemp);
			films[i].setScreenwriter(screenwriterTemp);
			films[i].setComposer(composerTemp);

			listBox1->Items->Add(gcnew System::String(films[i].filmStr().c_str()));

			std::string ass = std::to_string(i);
			label1->Text = gcnew System::String(ass.c_str());
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string ass = std::to_string(i);
		label1->Text = gcnew System::String(ass.c_str());
		listBox1->Items->Remove(listBox1->SelectedItem);
	}
private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	i = listBox1->SelectedIndex;
	std::string ass = std::to_string(i);
	label1->Text = gcnew System::String(ass.c_str());
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	std::string nameTemp;
	String^ nameStrTemp = textBox5->Text;
	MarshalString(nameStrTemp, nameTemp);

	std::string producerTemp;
	String^ producerStrTemp = textBox7->Text;
	MarshalString(producerStrTemp, producerTemp);

	std::string screenwriterTemp;
	String^ screenwriterStrTemp = textBox8->Text;
	MarshalString(screenwriterStrTemp, screenwriterTemp);

	std::string composerTemp;
	String^ composerStrTemp = textBox6->Text;
	MarshalString(composerStrTemp, composerTemp);

	films[i].setDay(int::Parse(textBox1->Text));
	films[i].setMonth(int::Parse(textBox2->Text));
	films[i].setYear(int::Parse(textBox3->Text));
	films[i].setProfit(int::Parse(textBox4->Text));
	films[i].setName(nameTemp);
	films[i].setProducer(producerTemp);
	films[i].setScreenwriter(screenwriterTemp);
	films[i].setComposer(composerTemp);

	listBox1->Items->Insert(listBox1->SelectedIndex, gcnew System::String(films[i].filmStr().c_str()));
	listBox1->Items->RemoveAt(listBox1->SelectedIndex);
}

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string producerTemp;
	String^ producerStrTemp = textBox9->Text;
	MarshalString(producerStrTemp, producerTemp);
	listBox1->Items->Clear();
	
}
private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
