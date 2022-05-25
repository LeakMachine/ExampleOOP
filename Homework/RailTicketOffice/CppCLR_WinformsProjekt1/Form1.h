#pragma once
#include "C:\Users\dimos\OneDrive\Рабочий стол\RailTicketOffice\Class\class.h"
#define LAS_SEAT_Q 100
#define PLATS_SEAT_Q 27
#define COUP_SEAT_Q 18	
#define SV_SEAT_Q 18

RailTicketOffice rto;

int wagonTypeSelected;
int trainTypeSelected;
int seatSelected;

int counter = 0;

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

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
			init();
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
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::ListBox^ listBox3;
	private: System::Windows::Forms::ListBox^ listBox4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ button3;



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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(12, 12);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(684, 260);
			this->listBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 402);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(309, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Сформировать билет";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 16;
			this->listBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Ласточка", L"Фирменный", L"Скорый" });
			this->listBox2->Location = System::Drawing::Point(702, 12);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(146, 116);
			this->listBox2->TabIndex = 5;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox2_SelectedIndexChanged);
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 16;
			this->listBox3->Location = System::Drawing::Point(702, 141);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(146, 116);
			this->listBox3->TabIndex = 6;
			this->listBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox3_SelectedIndexChanged);
			// 
			// listBox4
			// 
			this->listBox4->FormattingEnabled = true;
			this->listBox4->ItemHeight = 16;
			this->listBox4->Location = System::Drawing::Point(702, 270);
			this->listBox4->Name = L"listBox4";
			this->listBox4->Size = System::Drawing::Size(146, 116);
			this->listBox4->TabIndex = 7;
			this->listBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox4_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(974, 161);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(975, 141);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 17);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Номер вагона";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(854, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 17);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Тип поезда";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(854, 141);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(81, 17);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Тип вагона";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(857, 270);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(94, 17);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Номер места";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(975, 13);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 17);
			this->label5->TabIndex = 14;
			this->label5->Text = L"ID поезда";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(974, 33);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 13;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(12, 293);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(107, 22);
			this->textBox3->TabIndex = 15;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(12, 321);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(107, 22);
			this->textBox4->TabIndex = 16;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(12, 349);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(107, 22);
			this->textBox5->TabIndex = 17;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(214, 293);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(107, 22);
			this->textBox6->TabIndex = 18;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(214, 321);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(107, 22);
			this->textBox7->TabIndex = 19;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(214, 349);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(107, 22);
			this->textBox8->TabIndex = 20;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(430, 293);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(107, 22);
			this->textBox9->TabIndex = 22;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(430, 321);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(107, 22);
			this->textBox10->TabIndex = 21;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(373, 402);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(269, 23);
			this->button2->TabIndex = 23;
			this->button2->Text = L"Отмена билета";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(126, 297);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 17);
			this->label6->TabIndex = 24;
			this->label6->Text = L"Имя";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(126, 326);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(70, 17);
			this->label7->TabIndex = 25;
			this->label7->Text = L"Фамилия";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(126, 354);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(71, 17);
			this->label8->TabIndex = 26;
			this->label8->Text = L"Отчество";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(340, 296);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(42, 17);
			this->label9->TabIndex = 27;
			this->label9->Text = L"День";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(340, 324);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(50, 17);
			this->label10->TabIndex = 28;
			this->label10->Text = L"Месяц";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(340, 354);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(32, 17);
			this->label11->TabIndex = 29;
			this->label11->Text = L"Год";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(543, 293);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(154, 17);
			this->label12->TabIndex = 30;
			this->label12->Text = L"Станция отправления";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(543, 321);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(133, 17);
			this->label13->TabIndex = 31;
			this->label13->Text = L"Станция прибытия";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 431);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(309, 23);
			this->button3->TabIndex = 32;
			this->button3->Text = L"Следующий билет";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1115, 478);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->listBox4);
			this->Controls->Add(this->listBox3);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		listBox1->Items->Clear();
		Date date;
		FullName name;

		std::string tempStrName;
		String^ tempStrSys = textBox3->Text;
		MarshalString(tempStrSys, tempStrName);

		std::string tempStrSurname;
		tempStrSys = textBox4->Text;
		MarshalString(tempStrSys, tempStrSurname);

		std::string tempStrPatronymic;
		tempStrSys = textBox5->Text;
		MarshalString(tempStrSys, tempStrPatronymic);

		std::string tempStrArrival;
		tempStrSys = textBox9->Text;
		MarshalString(tempStrSys, tempStrArrival);

		std::string tempStrDeparting;
		tempStrSys = textBox10->Text;
		MarshalString(tempStrSys, tempStrDeparting);

		date.day = int::Parse(textBox6->Text);
		date.month = int::Parse(textBox7->Text);
		date.year = int::Parse(textBox8->Text);

		name.name = tempStrName;
		name.surname = tempStrSurname;
		name.patronymic = tempStrPatronymic;

		int trainID = int::Parse(textBox2->Text);
		int wagonID = int::Parse(textBox1->Text);

		rto.orderAccept(date, trainID, wagonID,wagonTypeSelected, name, 0, tempStrDeparting, tempStrArrival);
		if (rto.orderCheckAvailability(0, wagonTypeSelected) == false || rto.orderCheckSeatAvailability(0) == false) {
			listBox1->Items->Clear();
			std::string errorText = "wrong input";
			listBox1->Items->Add(gcnew System::String(errorText.c_str()));
			return;
		}
		rto.orderReserveSeats(0, wagonID, seatSelected);
		int price = rto.orderCountPrice(0);
		std::string priceStr = "Цена билета: "+ std::to_string(price);

		std::string string1 = rto.orderFormCheque(0, 0);
		std::string string2 = rto.orderFormCheque(0, 1);
		std::string string3 = rto.orderFormCheque(0, 2);
		std::string string4 = rto.orderFormCheque(0, 3);
		listBox1->Items->Add(gcnew System::String(string1.c_str()));
		listBox1->Items->Add(gcnew System::String(string2.c_str()));
		listBox1->Items->Add(gcnew System::String(string3.c_str()));
		listBox1->Items->Add(gcnew System::String(string4.c_str()));
		listBox1->Items->Add(gcnew System::String(priceStr.c_str()));
		button3->Visible = true;
	}
private: System::Void listBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (listBox2->SelectedIndex == 0) {
		listBox3->Items->Clear();
		std::string temp = "Вагон Ласточки 1-8";
		listBox3->Items->Add(gcnew System::String(temp.c_str()));
	}
	else if (listBox2->SelectedIndex == 1) {
		listBox3->Items->Clear();
		std::string temp1 = "Вагон СВ 1-2";
		std::string temp2 = "Вагон Купе 3-8";
		std::string temp3 = "Вагон Плацкарт 9-12";
		listBox3->Items->Add(gcnew System::String(temp1.c_str()));
		listBox3->Items->Add(gcnew System::String(temp2.c_str()));
		listBox3->Items->Add(gcnew System::String(temp3.c_str()));
	}
	else if (listBox2->SelectedIndex == 2) {
		listBox3->Items->Clear();
		std::string temp1 = "Вагон Купе 1-4";
		std::string temp2 = "Вагон Плацкарт 5-12";
		listBox3->Items->Add(gcnew System::String(temp1.c_str()));
		listBox3->Items->Add(gcnew System::String(temp2.c_str()));
	}
}
private: System::Void listBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (listBox2->SelectedIndex == 0 && listBox3->SelectedIndex == 0) {
		listBox4->Items->Clear();
		for (int i = 0; i < LAS_SEAT_Q; i++) {
			wagonTypeSelected = 0;
			std::string temp = std::to_string(i + 1);
			listBox4->Items->Add(gcnew System::String(temp.c_str()));
		}
	}
	else if (listBox2->SelectedIndex == 2 && listBox3->SelectedIndex == 0) {
		listBox4->Items->Clear();
		for (int i = 0; i < COUP_SEAT_Q * 2; i++) {
			wagonTypeSelected = 1;
			std::string temp = std::to_string(i + 1);
			listBox4->Items->Add(gcnew System::String(temp.c_str()));
		}
	}
	else if (listBox2->SelectedIndex == 2 && listBox3->SelectedIndex == 1) {
		listBox4->Items->Clear();
		for (int i = 0; i < PLATS_SEAT_Q * 2; i++) {
			wagonTypeSelected = 2;
			std::string temp = std::to_string(i + 1);
			listBox4->Items->Add(gcnew System::String(temp.c_str()));
		}
	}
	else if (listBox3->SelectedIndex == 0) {
		listBox4->Items->Clear();
		for (int i = 0; i < SV_SEAT_Q; i++) {
			wagonTypeSelected = 3;
			std::string temp = std::to_string(i + 1);
			listBox4->Items->Add(gcnew System::String(temp.c_str()));
		}
	}
	else if (listBox3->SelectedIndex == 1) {
		listBox4->Items->Clear();
		for (int i = 0; i < COUP_SEAT_Q * 2; i++) {
			wagonTypeSelected = 1;
			std::string temp = std::to_string(i + 1);
			listBox4->Items->Add(gcnew System::String(temp.c_str()));
		}
	}
	else if (listBox3->SelectedIndex == 2) {
		listBox4->Items->Clear();
		for (int i = 0; i < PLATS_SEAT_Q * 2; i++) {
			wagonTypeSelected = 2;
			std::string temp = std::to_string(i + 1);
			listBox4->Items->Add(gcnew System::String(temp.c_str()));
		}
	}
}
private: System::Void listBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	seatSelected = listBox4->SelectedIndex + 1;
}
private: System::Void init() {
	std::string temp1 = "Доступные поезда:";
	listBox1->Items->Add(gcnew System::String(temp1.c_str()));
	std::string temp2 = "ЛАСТОЧКА 1:";
	int tempID = rto.getTrainID(0, 0);
	std::string temp3 = "ID: " + std::to_string(tempID) + " " + "Вагонов: " + "8 " + "Станция прибытия: " + rto.getStation(0, 0, 0) + " Станция отправления: " + rto.getStation(0, 0, 1);
	listBox1->Items->Add(gcnew System::String(temp2.c_str()));
	listBox1->Items->Add(gcnew System::String(temp3.c_str()));
	temp2 = "ЛАСТОЧКА 2:";
	tempID = rto.getTrainID(0, 1);
	temp3 = "ID: " + std::to_string(tempID) + " " + "Вагонов: " + "8 " + "Станция прибытия: " + rto.getStation(0, 1, 0) + " Станция отправления: " + rto.getStation(0, 1, 1);
	listBox1->Items->Add(gcnew System::String(temp2.c_str()));
	listBox1->Items->Add(gcnew System::String(temp3.c_str()));
	temp2 = "ЛАСТОЧКА 3:";
	tempID = rto.getTrainID(0, 2);
	temp3 = "ID: " + std::to_string(tempID) + " " + "Вагонов: " + "8 " + "Станция прибытия: " + rto.getStation(0, 2, 0) + " Станция отправления: " + rto.getStation(0, 2, 1);
	listBox1->Items->Add(gcnew System::String(temp2.c_str()));
	listBox1->Items->Add(gcnew System::String(temp3.c_str()));
	temp2 = "ФИРМЕННЫЙ:";
	tempID = rto.getTrainID(1, 0);
	temp3 = "ID: " + std::to_string(tempID) + " " + "Вагонов: " + "12 " + "Станция прибытия: " + rto.getStation(1, 0, 0) + " Станция отправления: " + rto.getStation(1, 0, 1);
	listBox1->Items->Add(gcnew System::String(temp2.c_str()));
	listBox1->Items->Add(gcnew System::String(temp3.c_str()));
	temp2 = "СКОРЫЙ:";
	tempID = rto.getTrainID(2, 0);
	temp3 = "ID: " + std::to_string(tempID) + " " + "Вагонов: " + "12 " + "Станция прибытия: " + rto.getStation(2, 0, 0) + " Станция отправления: " + rto.getStation(2, 0, 1);
	listBox1->Items->Add(gcnew System::String(temp2.c_str()));
	listBox1->Items->Add(gcnew System::String(temp3.c_str()));
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	button3->Visible = false;
	listBox1->Items->Clear();
	init();
	rto.orderCancel(0);
	textBox1->Text = "";
	textBox2->Text = "";
	textBox3->Text = "";
	textBox4->Text = "";
	textBox5->Text = "";
	textBox6->Text = "";
	textBox7->Text = "";
	textBox8->Text = "";
	textBox9->Text = "";
	textBox10->Text = "";
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	button3->Visible = false;
	counter++;
	listBox1->Items->Clear();
	init();
}
};
}
