﻿//@author A0118918W
#pragma once


#include <msclr\marshal_cppstd.h>
#include "CMLogic.h"
#include "Output.h"
#include "Task.h"
#include <vector>
#include <sstream>
//#using <mscorlib.dll>
#include "GUIConstants.h"



namespace CMGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CMGUI
	/// </summary>
	public ref class CMGUI : public System::Windows::Forms::Form
	{
	private:
		CMLogic* testSample;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
			 GUIConstants* constants;
	public:
		CMGUI(void)
		{
			InitializeComponent();
			testSample = new CMLogic();
			testSample->startUp();
			displayOutput(0,0);
			inputBox->Clear();

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CMGUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private: static int _countDown = 0;
	private: static int _countUp = 0;
			 static int _countRight =0;
			 static int _countLeft = 0;
	private: static int _numOfPages = 0;
			 static int _numOfFloatPages = 0;
	private: static int _counter=0;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  inputBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private:  System::Windows::Forms::TextBox^  textBox2;
	private:  System::Windows::Forms::TextBox^  textBox26;
	private:  System::Windows::Forms::TextBox^  textBox25;
	private:  System::Windows::Forms::TextBox^  textBox27;
	private:  System::Windows::Forms::TextBox^  textBox28;
	private:  System::Windows::Forms::TextBox^  textBox29;
	private:  System::Windows::Forms::TextBox^  textBox30;
	private:  System::Windows::Forms::TextBox^  textBox1;
	private:  System::Windows::Forms::TextBox^  textBox3;
	private:  System::Windows::Forms::TextBox^  textBox4;
	private:  System::Windows::Forms::TextBox^  textBox5;
	private:  System::Windows::Forms::TextBox^  textBox6;
	private:  System::Windows::Forms::TextBox^  textBox7;
	private:  System::Windows::Forms::TextBox^  textBox8;
	private:  System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox11;
	private:  System::Windows::Forms::TextBox^  textBox12;
	private:  System::Windows::Forms::TextBox^  textBox13;
	private:  System::Windows::Forms::TextBox^  textBox14;
	private:  System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::TextBox^  textBox17;
	private:   System::Windows::Forms::TextBox^  textBox18;
	private: System::Windows::Forms::TextBox^  textBox19;
	private: System::Windows::Forms::TextBox^  textBox20;
	private: System::Windows::Forms::TextBox^  textBox21;
	private:  System::Windows::Forms::TextBox^  textBox22;
	private: System::Windows::Forms::TextBox^  textBox23;
	private:  System::Windows::Forms::TextBox^  textBox24;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private:  System::Windows::Forms::TextBox^  textBox31;
	private:  System::Windows::Forms::TextBox^  textBox32;
	private:  System::Windows::Forms::TextBox^  textBox33;
	private:  System::Windows::Forms::TextBox^  textBox34;
	private:  System::Windows::Forms::TextBox^  textBox35;
	private:  System::Windows::Forms::TextBox^  textBox36;
	private:  System::Windows::Forms::TextBox^  textBox37;
	private:  System::Windows::Forms::TextBox^  textBox38;
	private:  System::Windows::Forms::TextBox^  textBox39;
	private:  System::Windows::Forms::TextBox^  textBox40;
	private:  System::Windows::Forms::TextBox^  textBox41;
	private:  System::Windows::Forms::TextBox^  textBox42;
	private:  System::Windows::Forms::TextBox^  textBox43;
	private:  System::Windows::Forms::TextBox^  textBox44;
	private: System::Windows::Forms::TextBox^  textBox45;
	private: System::Windows::Forms::TextBox^  textBox46;
	private:  System::Windows::Forms::TextBox^  textBox47;
	private:  System::Windows::Forms::TextBox^  textBox48;
	private:  System::Windows::Forms::TextBox^  textBox49;
	private:  System::Windows::Forms::TextBox^  textBox50;
	private:  System::Windows::Forms::TextBox^  textBox51;
	private:  System::Windows::Forms::TextBox^  textBox52;
	private:  System::Windows::Forms::TextBox^  textBox53;
	private:  System::Windows::Forms::TextBox^  textBox54;
	private:  System::Windows::Forms::TextBox^  textBox55;
	private: System::Windows::Forms::TextBox^  textBox56;
	private: System::Windows::Forms::TextBox^  textBox57;
	private: System::Windows::Forms::TextBox^  textBox58;
	private: System::Windows::Forms::TextBox^  textBox59;
	private: System::Windows::Forms::TextBox^  textBox60;
	private: System::Windows::Forms::TextBox^  textBox61;
	private:  System::Windows::Forms::TextBox^  textBox62;
	private:  System::Windows::Forms::TextBox^  textBox63;
	private:  System::Windows::Forms::TextBox^  textBox64;
	private: System::Windows::Forms::TextBox^  textBox65;
	private:  System::Windows::Forms::TextBox^  textBox66;
	private: System::Windows::Forms::TextBox^  textBox67;
	private: System::Windows::Forms::TextBox^  textBox68;
	private:  System::Windows::Forms::TextBox^  textBox69;
	private:  System::Windows::Forms::TextBox^  textBox70;
	private:  System::Windows::Forms::TextBox^  textBox71;
	private:  System::Windows::Forms::TextBox^  textBox72;
	private:  System::Windows::Forms::TextBox^  textBox73;
	private:  System::Windows::Forms::TextBox^  textBox74;
	private:  System::Windows::Forms::TextBox^  textBox75;
	private:  System::Windows::Forms::TextBox^  textBox76;
	private:  System::Windows::Forms::TextBox^  textBox77;
	private: System::Windows::Forms::TextBox^  textBox78;
	private:  System::Windows::Forms::TextBox^  textBox79;
	private:  System::Windows::Forms::TextBox^  textBox80;
	private:  System::Windows::Forms::TextBox^  textBox81;
	private:  System::Windows::Forms::TextBox^  textBox82;
	private:  System::Windows::Forms::TextBox^  textBox83;
	private: System::Windows::Forms::TextBox^  textBox84;
	private:  System::Windows::Forms::TextBox^  textBox85;
	private:  System::Windows::Forms::TextBox^  textBox86;
	private:  System::Windows::Forms::TextBox^  textBox87;
	private:  System::Windows::Forms::TextBox^  textBox88;
	private:  System::Windows::Forms::TextBox^  textBox89;
	private:  System::Windows::Forms::TextBox^  textBox90;
	private:  System::Windows::Forms::TextBox^  textBox91;
	private:  System::Windows::Forms::TextBox^  textBox92;
	private:  System::Windows::Forms::TextBox^  textBox93;
	private:  System::Windows::Forms::TextBox^  textBox94;
	private:  System::Windows::Forms::TextBox^  textBox95;
	private:  System::Windows::Forms::TextBox^  textBox96;
	private:  System::Windows::Forms::TextBox^  textBox97;
	private:  System::Windows::Forms::TextBox^  textBox98;
	private:  System::Windows::Forms::TextBox^  textBox99;
	private:  System::Windows::Forms::TextBox^  textBox100;
	private: System::Windows::Forms::TextBox^  textBox101;
	private:  System::Windows::Forms::TextBox^  textBox102;
	private:  System::Windows::Forms::TextBox^  textBox103;
	private:  System::Windows::Forms::TextBox^  textBox104;
	private:  System::Windows::Forms::TextBox^  textBox105;
	private:  System::Windows::Forms::TextBox^  textBox106;
	private:  System::Windows::Forms::TextBox^  textBox107;
	private:  System::Windows::Forms::TextBox^  textBox108;
	private:  System::Windows::Forms::TextBox^  textBox109;
	private:  System::Windows::Forms::TextBox^  textBox110;
	private: System::Windows::Forms::TextBox^  textBox111;
	private:  System::Windows::Forms::TextBox^  textBox112;
	private:  System::Windows::Forms::TextBox^  textBox113;
	private:  System::Windows::Forms::TextBox^  textBox114;
	private:  System::Windows::Forms::TextBox^  textBox115;
	private: System::Windows::Forms::TextBox^  textBox116;
	private: System::Windows::Forms::TextBox^  textBox117;
	private: System::Windows::Forms::TextBox^  textBox118;
	private: System::Windows::Forms::TextBox^  textBox119;
	private: System::Windows::Forms::TextBox^  textBox120;
	private: System::Windows::Forms::Label^  label7;

	private: System::Windows::Forms::TextBox^  promptBox;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox121;
	private: System::Windows::Forms::TextBox^  textBox122;
	private: System::Windows::Forms::TextBox^  textBox123;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox124;
	private: System::Windows::Forms::TextBox^  textBox125;
	private: System::Windows::Forms::TextBox^  textBox126;
	private: System::Windows::Forms::TextBox^  textBox127;
	private: System::Windows::Forms::TextBox^  textBox128;
	private: System::Windows::Forms::TextBox^  textBox129;
	private: System::Windows::Forms::TextBox^  textBox130;
	private: System::Windows::Forms::TextBox^  textBox131;
	private: System::Windows::Forms::TextBox^  textBox132;
	private: System::Windows::Forms::TextBox^  textBox133;
	private: System::Windows::Forms::TextBox^  textBox134;
	private: System::Windows::Forms::TextBox^  textBox135;
	private: System::Windows::Forms::TextBox^  textBox136;
	private: System::Windows::Forms::TextBox^  textBox137;
	private: System::Windows::Forms::TextBox^  textBox138;
	private: System::Windows::Forms::TextBox^  textBox139;
	private: System::Windows::Forms::TextBox^  textBox140;
	private: System::Windows::Forms::TextBox^  textBox141;
	private: System::Windows::Forms::TextBox^  textBox142;
	private: System::Windows::Forms::RichTextBox^  helpBox;
	private: System::Windows::Forms::MonthCalendar^  monthCalendar1;
	private: System::Windows::Forms::TextBox^  textBox143;
	private: System::Windows::Forms::TextBox^  textBox144;



	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		//@author A0118918W generated

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(CMGUI::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->inputBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox26 = (gcnew System::Windows::Forms::TextBox());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->textBox27 = (gcnew System::Windows::Forms::TextBox());
			this->textBox28 = (gcnew System::Windows::Forms::TextBox());
			this->textBox29 = (gcnew System::Windows::Forms::TextBox());
			this->textBox30 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox31 = (gcnew System::Windows::Forms::TextBox());
			this->textBox32 = (gcnew System::Windows::Forms::TextBox());
			this->textBox33 = (gcnew System::Windows::Forms::TextBox());
			this->textBox34 = (gcnew System::Windows::Forms::TextBox());
			this->textBox35 = (gcnew System::Windows::Forms::TextBox());
			this->textBox36 = (gcnew System::Windows::Forms::TextBox());
			this->textBox37 = (gcnew System::Windows::Forms::TextBox());
			this->textBox38 = (gcnew System::Windows::Forms::TextBox());
			this->textBox39 = (gcnew System::Windows::Forms::TextBox());
			this->textBox40 = (gcnew System::Windows::Forms::TextBox());
			this->textBox41 = (gcnew System::Windows::Forms::TextBox());
			this->textBox42 = (gcnew System::Windows::Forms::TextBox());
			this->textBox43 = (gcnew System::Windows::Forms::TextBox());
			this->textBox44 = (gcnew System::Windows::Forms::TextBox());
			this->textBox45 = (gcnew System::Windows::Forms::TextBox());
			this->textBox46 = (gcnew System::Windows::Forms::TextBox());
			this->textBox47 = (gcnew System::Windows::Forms::TextBox());
			this->textBox48 = (gcnew System::Windows::Forms::TextBox());
			this->textBox49 = (gcnew System::Windows::Forms::TextBox());
			this->textBox50 = (gcnew System::Windows::Forms::TextBox());
			this->textBox51 = (gcnew System::Windows::Forms::TextBox());
			this->textBox52 = (gcnew System::Windows::Forms::TextBox());
			this->textBox53 = (gcnew System::Windows::Forms::TextBox());
			this->textBox54 = (gcnew System::Windows::Forms::TextBox());
			this->textBox55 = (gcnew System::Windows::Forms::TextBox());
			this->textBox56 = (gcnew System::Windows::Forms::TextBox());
			this->textBox57 = (gcnew System::Windows::Forms::TextBox());
			this->textBox58 = (gcnew System::Windows::Forms::TextBox());
			this->textBox59 = (gcnew System::Windows::Forms::TextBox());
			this->textBox60 = (gcnew System::Windows::Forms::TextBox());
			this->textBox61 = (gcnew System::Windows::Forms::TextBox());
			this->textBox62 = (gcnew System::Windows::Forms::TextBox());
			this->textBox63 = (gcnew System::Windows::Forms::TextBox());
			this->textBox64 = (gcnew System::Windows::Forms::TextBox());
			this->textBox65 = (gcnew System::Windows::Forms::TextBox());
			this->textBox66 = (gcnew System::Windows::Forms::TextBox());
			this->textBox67 = (gcnew System::Windows::Forms::TextBox());
			this->textBox68 = (gcnew System::Windows::Forms::TextBox());
			this->textBox69 = (gcnew System::Windows::Forms::TextBox());
			this->textBox70 = (gcnew System::Windows::Forms::TextBox());
			this->textBox71 = (gcnew System::Windows::Forms::TextBox());
			this->textBox72 = (gcnew System::Windows::Forms::TextBox());
			this->textBox73 = (gcnew System::Windows::Forms::TextBox());
			this->textBox74 = (gcnew System::Windows::Forms::TextBox());
			this->textBox75 = (gcnew System::Windows::Forms::TextBox());
			this->textBox76 = (gcnew System::Windows::Forms::TextBox());
			this->textBox77 = (gcnew System::Windows::Forms::TextBox());
			this->textBox78 = (gcnew System::Windows::Forms::TextBox());
			this->textBox79 = (gcnew System::Windows::Forms::TextBox());
			this->textBox80 = (gcnew System::Windows::Forms::TextBox());
			this->textBox81 = (gcnew System::Windows::Forms::TextBox());
			this->textBox82 = (gcnew System::Windows::Forms::TextBox());
			this->textBox83 = (gcnew System::Windows::Forms::TextBox());
			this->textBox84 = (gcnew System::Windows::Forms::TextBox());
			this->textBox85 = (gcnew System::Windows::Forms::TextBox());
			this->textBox86 = (gcnew System::Windows::Forms::TextBox());
			this->textBox87 = (gcnew System::Windows::Forms::TextBox());
			this->textBox88 = (gcnew System::Windows::Forms::TextBox());
			this->textBox89 = (gcnew System::Windows::Forms::TextBox());
			this->textBox90 = (gcnew System::Windows::Forms::TextBox());
			this->textBox91 = (gcnew System::Windows::Forms::TextBox());
			this->textBox92 = (gcnew System::Windows::Forms::TextBox());
			this->textBox93 = (gcnew System::Windows::Forms::TextBox());
			this->textBox94 = (gcnew System::Windows::Forms::TextBox());
			this->textBox95 = (gcnew System::Windows::Forms::TextBox());
			this->textBox96 = (gcnew System::Windows::Forms::TextBox());
			this->textBox97 = (gcnew System::Windows::Forms::TextBox());
			this->textBox98 = (gcnew System::Windows::Forms::TextBox());
			this->textBox99 = (gcnew System::Windows::Forms::TextBox());
			this->textBox100 = (gcnew System::Windows::Forms::TextBox());
			this->textBox101 = (gcnew System::Windows::Forms::TextBox());
			this->textBox102 = (gcnew System::Windows::Forms::TextBox());
			this->textBox103 = (gcnew System::Windows::Forms::TextBox());
			this->textBox104 = (gcnew System::Windows::Forms::TextBox());
			this->textBox105 = (gcnew System::Windows::Forms::TextBox());
			this->textBox106 = (gcnew System::Windows::Forms::TextBox());
			this->textBox107 = (gcnew System::Windows::Forms::TextBox());
			this->textBox108 = (gcnew System::Windows::Forms::TextBox());
			this->textBox109 = (gcnew System::Windows::Forms::TextBox());
			this->textBox110 = (gcnew System::Windows::Forms::TextBox());
			this->textBox111 = (gcnew System::Windows::Forms::TextBox());
			this->textBox112 = (gcnew System::Windows::Forms::TextBox());
			this->textBox113 = (gcnew System::Windows::Forms::TextBox());
			this->textBox114 = (gcnew System::Windows::Forms::TextBox());
			this->textBox115 = (gcnew System::Windows::Forms::TextBox());
			this->textBox116 = (gcnew System::Windows::Forms::TextBox());
			this->textBox117 = (gcnew System::Windows::Forms::TextBox());
			this->textBox118 = (gcnew System::Windows::Forms::TextBox());
			this->textBox119 = (gcnew System::Windows::Forms::TextBox());
			this->textBox120 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->promptBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox121 = (gcnew System::Windows::Forms::TextBox());
			this->textBox122 = (gcnew System::Windows::Forms::TextBox());
			this->textBox123 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox124 = (gcnew System::Windows::Forms::TextBox());
			this->textBox125 = (gcnew System::Windows::Forms::TextBox());
			this->textBox126 = (gcnew System::Windows::Forms::TextBox());
			this->textBox127 = (gcnew System::Windows::Forms::TextBox());
			this->textBox128 = (gcnew System::Windows::Forms::TextBox());
			this->textBox129 = (gcnew System::Windows::Forms::TextBox());
			this->textBox130 = (gcnew System::Windows::Forms::TextBox());
			this->textBox131 = (gcnew System::Windows::Forms::TextBox());
			this->textBox132 = (gcnew System::Windows::Forms::TextBox());
			this->textBox133 = (gcnew System::Windows::Forms::TextBox());
			this->textBox134 = (gcnew System::Windows::Forms::TextBox());
			this->textBox135 = (gcnew System::Windows::Forms::TextBox());
			this->textBox136 = (gcnew System::Windows::Forms::TextBox());
			this->textBox137 = (gcnew System::Windows::Forms::TextBox());
			this->textBox138 = (gcnew System::Windows::Forms::TextBox());
			this->textBox139 = (gcnew System::Windows::Forms::TextBox());
			this->textBox140 = (gcnew System::Windows::Forms::TextBox());
			this->textBox141 = (gcnew System::Windows::Forms::TextBox());
			this->textBox142 = (gcnew System::Windows::Forms::TextBox());
			this->textBox143 = (gcnew System::Windows::Forms::TextBox());
			this->textBox144 = (gcnew System::Windows::Forms::TextBox());
			this->helpBox = (gcnew System::Windows::Forms::RichTextBox());
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::AliceBlue;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(146, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter command below";
			// 
			// inputBox
			// 
			this->inputBox->BackColor = System::Drawing::Color::AliceBlue;
			this->inputBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->inputBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->inputBox->Location = System::Drawing::Point(146, 38);
			this->inputBox->Multiline = true;
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(690, 20);
			this->inputBox->TabIndex = 1;
			this->inputBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &CMGUI::inputBox_KeyDown);
			this->inputBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &CMGUI::inputBox_KeyPress);
			this->inputBox->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &CMGUI::inputBox_KeyUp);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::AliceBlue;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(50, 2);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 15);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Description";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::AliceBlue;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(347, 2);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 15);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Start Date";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::AliceBlue;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(592, 2);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(68, 15);
			this->label6->TabIndex = 7;
			this->label6->Text = L"End Time";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::AliceBlue;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(511, 2);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 15);
			this->label5->TabIndex = 6;
			this->label5->Text = L"End Date";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::AliceBlue;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(428, 2);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(73, 15);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Start Time";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(50, 28);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(288, 13);
			this->textBox2->TabIndex = 7;
			// 
			// textBox26
			// 
			this->textBox26->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox26->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox26->Location = System::Drawing::Point(50, 118);
			this->textBox26->Multiline = true;
			this->textBox26->Name = L"textBox26";
			this->textBox26->Size = System::Drawing::Size(286, 15);
			this->textBox26->TabIndex = 0;
			// 
			// textBox25
			// 
			this->textBox25->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox25->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox25->Location = System::Drawing::Point(5, 118);
			this->textBox25->Multiline = true;
			this->textBox25->Name = L"textBox25";
			this->textBox25->Size = System::Drawing::Size(31, 15);
			this->textBox25->TabIndex = 1;
			// 
			// textBox27
			// 
			this->textBox27->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox27->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox27->Location = System::Drawing::Point(347, 118);
			this->textBox27->Multiline = true;
			this->textBox27->Name = L"textBox27";
			this->textBox27->Size = System::Drawing::Size(70, 15);
			this->textBox27->TabIndex = 2;
			// 
			// textBox28
			// 
			this->textBox28->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox28->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox28->Location = System::Drawing::Point(428, 118);
			this->textBox28->Multiline = true;
			this->textBox28->Name = L"textBox28";
			this->textBox28->Size = System::Drawing::Size(66, 15);
			this->textBox28->TabIndex = 3;
			// 
			// textBox29
			// 
			this->textBox29->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox29->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox29->Location = System::Drawing::Point(511, 118);
			this->textBox29->Multiline = true;
			this->textBox29->Name = L"textBox29";
			this->textBox29->Size = System::Drawing::Size(73, 15);
			this->textBox29->TabIndex = 4;
			// 
			// textBox30
			// 
			this->textBox30->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox30->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox30->Location = System::Drawing::Point(592, 118);
			this->textBox30->Multiline = true;
			this->textBox30->Name = L"textBox30";
			this->textBox30->Size = System::Drawing::Size(64, 15);
			this->textBox30->TabIndex = 5;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(5, 28);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(37, 13);
			this->textBox1->TabIndex = 6;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(347, 28);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(73, 13);
			this->textBox3->TabIndex = 8;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(428, 28);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(74, 13);
			this->textBox4->TabIndex = 9;
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(511, 28);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(73, 13);
			this->textBox5->TabIndex = 10;
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox6->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(592, 28);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(76, 13);
			this->textBox6->TabIndex = 11;
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox7->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox7->Location = System::Drawing::Point(5, 49);
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(37, 15);
			this->textBox7->TabIndex = 12;
			// 
			// textBox8
			// 
			this->textBox8->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox8->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox8->Location = System::Drawing::Point(50, 49);
			this->textBox8->Multiline = true;
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(288, 15);
			this->textBox8->TabIndex = 13;
			// 
			// textBox9
			// 
			this->textBox9->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox9->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox9->Location = System::Drawing::Point(347, 49);
			this->textBox9->Multiline = true;
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(73, 15);
			this->textBox9->TabIndex = 14;
			// 
			// textBox10
			// 
			this->textBox10->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox10->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox10->Location = System::Drawing::Point(428, 49);
			this->textBox10->Multiline = true;
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(74, 15);
			this->textBox10->TabIndex = 15;
			// 
			// textBox11
			// 
			this->textBox11->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox11->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox11->Location = System::Drawing::Point(511, 49);
			this->textBox11->Multiline = true;
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(73, 15);
			this->textBox11->TabIndex = 16;
			// 
			// textBox12
			// 
			this->textBox12->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox12->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox12->Location = System::Drawing::Point(592, 49);
			this->textBox12->Multiline = true;
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(76, 15);
			this->textBox12->TabIndex = 17;
			// 
			// textBox13
			// 
			this->textBox13->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox13->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox13->Location = System::Drawing::Point(5, 72);
			this->textBox13->Multiline = true;
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(37, 15);
			this->textBox13->TabIndex = 18;
			// 
			// textBox14
			// 
			this->textBox14->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox14->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox14->Location = System::Drawing::Point(50, 72);
			this->textBox14->Multiline = true;
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(288, 15);
			this->textBox14->TabIndex = 19;
			// 
			// textBox15
			// 
			this->textBox15->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox15->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox15->Location = System::Drawing::Point(347, 72);
			this->textBox15->Multiline = true;
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(73, 15);
			this->textBox15->TabIndex = 20;
			// 
			// textBox16
			// 
			this->textBox16->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox16->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox16->Location = System::Drawing::Point(428, 72);
			this->textBox16->Multiline = true;
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(74, 15);
			this->textBox16->TabIndex = 21;
			// 
			// textBox17
			// 
			this->textBox17->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox17->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox17->Location = System::Drawing::Point(511, 72);
			this->textBox17->Multiline = true;
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(73, 15);
			this->textBox17->TabIndex = 22;
			// 
			// textBox18
			// 
			this->textBox18->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox18->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox18->Location = System::Drawing::Point(592, 72);
			this->textBox18->Multiline = true;
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(76, 15);
			this->textBox18->TabIndex = 23;
			// 
			// textBox19
			// 
			this->textBox19->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox19->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox19->Location = System::Drawing::Point(5, 95);
			this->textBox19->Multiline = true;
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(31, 15);
			this->textBox19->TabIndex = 24;
			// 
			// textBox20
			// 
			this->textBox20->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox20->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox20->Location = System::Drawing::Point(50, 95);
			this->textBox20->Multiline = true;
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(286, 15);
			this->textBox20->TabIndex = 25;
			// 
			// textBox21
			// 
			this->textBox21->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox21->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox21->Location = System::Drawing::Point(347, 95);
			this->textBox21->Multiline = true;
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(70, 15);
			this->textBox21->TabIndex = 26;
			// 
			// textBox22
			// 
			this->textBox22->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox22->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox22->Location = System::Drawing::Point(428, 95);
			this->textBox22->Multiline = true;
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(66, 15);
			this->textBox22->TabIndex = 27;
			// 
			// textBox23
			// 
			this->textBox23->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox23->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox23->Location = System::Drawing::Point(511, 95);
			this->textBox23->Multiline = true;
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(73, 15);
			this->textBox23->TabIndex = 28;
			// 
			// textBox24
			// 
			this->textBox24->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox24->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox24->Location = System::Drawing::Point(592, 95);
			this->textBox24->Multiline = true;
			this->textBox24->Name = L"textBox24";
			this->textBox24->Size = System::Drawing::Size(64, 15);
			this->textBox24->TabIndex = 29;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoScroll = true;
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::AliceBlue;
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Inset;
			this->tableLayoutPanel1->ColumnCount = 6;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				6.6F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				44.8F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				12.1F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				12.3F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				12.1F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				12.1F)));
			this->tableLayoutPanel1->Controls->Add(this->textBox24, 5, 4);
			this->tableLayoutPanel1->Controls->Add(this->label6, 5, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox23, 4, 4);
			this->tableLayoutPanel1->Controls->Add(this->textBox22, 3, 4);
			this->tableLayoutPanel1->Controls->Add(this->label4, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox21, 2, 4);
			this->tableLayoutPanel1->Controls->Add(this->textBox20, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->label2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox19, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->textBox18, 5, 3);
			this->tableLayoutPanel1->Controls->Add(this->textBox17, 4, 3);
			this->tableLayoutPanel1->Controls->Add(this->textBox16, 3, 3);
			this->tableLayoutPanel1->Controls->Add(this->textBox15, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->textBox14, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->textBox13, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->textBox12, 5, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox11, 4, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox10, 3, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox9, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox8, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox7, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox6, 5, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox5, 4, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox4, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox3, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox25, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->textBox26, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->textBox27, 2, 5);
			this->tableLayoutPanel1->Controls->Add(this->textBox28, 3, 5);
			this->tableLayoutPanel1->Controls->Add(this->textBox29, 4, 5);
			this->tableLayoutPanel1->Controls->Add(this->textBox30, 5, 5);
			this->tableLayoutPanel1->Controls->Add(this->label5, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->label3, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox31, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->textBox32, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->textBox33, 2, 6);
			this->tableLayoutPanel1->Controls->Add(this->textBox34, 3, 6);
			this->tableLayoutPanel1->Controls->Add(this->textBox35, 4, 6);
			this->tableLayoutPanel1->Controls->Add(this->textBox36, 5, 6);
			this->tableLayoutPanel1->Controls->Add(this->textBox37, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->textBox38, 1, 7);
			this->tableLayoutPanel1->Controls->Add(this->textBox39, 2, 7);
			this->tableLayoutPanel1->Controls->Add(this->textBox40, 3, 7);
			this->tableLayoutPanel1->Controls->Add(this->textBox41, 4, 7);
			this->tableLayoutPanel1->Controls->Add(this->textBox42, 5, 7);
			this->tableLayoutPanel1->Controls->Add(this->textBox43, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->textBox44, 1, 8);
			this->tableLayoutPanel1->Controls->Add(this->textBox45, 2, 8);
			this->tableLayoutPanel1->Controls->Add(this->textBox46, 3, 8);
			this->tableLayoutPanel1->Controls->Add(this->textBox47, 4, 8);
			this->tableLayoutPanel1->Controls->Add(this->textBox48, 5, 8);
			this->tableLayoutPanel1->Controls->Add(this->textBox49, 0, 9);
			this->tableLayoutPanel1->Controls->Add(this->textBox50, 1, 9);
			this->tableLayoutPanel1->Controls->Add(this->textBox51, 2, 9);
			this->tableLayoutPanel1->Controls->Add(this->textBox52, 3, 9);
			this->tableLayoutPanel1->Controls->Add(this->textBox53, 4, 9);
			this->tableLayoutPanel1->Controls->Add(this->textBox54, 5, 9);
			this->tableLayoutPanel1->Controls->Add(this->textBox55, 0, 10);
			this->tableLayoutPanel1->Controls->Add(this->textBox56, 1, 10);
			this->tableLayoutPanel1->Controls->Add(this->textBox57, 2, 10);
			this->tableLayoutPanel1->Controls->Add(this->textBox58, 3, 10);
			this->tableLayoutPanel1->Controls->Add(this->textBox59, 4, 10);
			this->tableLayoutPanel1->Controls->Add(this->textBox60, 5, 10);
			this->tableLayoutPanel1->Controls->Add(this->textBox61, 0, 11);
			this->tableLayoutPanel1->Controls->Add(this->textBox62, 1, 11);
			this->tableLayoutPanel1->Controls->Add(this->textBox63, 2, 11);
			this->tableLayoutPanel1->Controls->Add(this->textBox64, 3, 11);
			this->tableLayoutPanel1->Controls->Add(this->textBox65, 4, 11);
			this->tableLayoutPanel1->Controls->Add(this->textBox66, 5, 11);
			this->tableLayoutPanel1->Controls->Add(this->textBox67, 0, 12);
			this->tableLayoutPanel1->Controls->Add(this->textBox68, 1, 12);
			this->tableLayoutPanel1->Controls->Add(this->textBox69, 2, 12);
			this->tableLayoutPanel1->Controls->Add(this->textBox70, 3, 12);
			this->tableLayoutPanel1->Controls->Add(this->textBox71, 4, 12);
			this->tableLayoutPanel1->Controls->Add(this->textBox72, 5, 12);
			this->tableLayoutPanel1->Controls->Add(this->textBox73, 0, 13);
			this->tableLayoutPanel1->Controls->Add(this->textBox74, 1, 13);
			this->tableLayoutPanel1->Controls->Add(this->textBox75, 2, 13);
			this->tableLayoutPanel1->Controls->Add(this->textBox76, 3, 13);
			this->tableLayoutPanel1->Controls->Add(this->textBox77, 4, 13);
			this->tableLayoutPanel1->Controls->Add(this->textBox78, 5, 13);
			this->tableLayoutPanel1->Controls->Add(this->textBox79, 0, 14);
			this->tableLayoutPanel1->Controls->Add(this->textBox80, 1, 14);
			this->tableLayoutPanel1->Controls->Add(this->textBox81, 2, 14);
			this->tableLayoutPanel1->Controls->Add(this->textBox82, 3, 14);
			this->tableLayoutPanel1->Controls->Add(this->textBox83, 4, 14);
			this->tableLayoutPanel1->Controls->Add(this->textBox84, 5, 14);
			this->tableLayoutPanel1->Controls->Add(this->textBox85, 0, 15);
			this->tableLayoutPanel1->Controls->Add(this->textBox86, 1, 15);
			this->tableLayoutPanel1->Controls->Add(this->textBox87, 2, 15);
			this->tableLayoutPanel1->Controls->Add(this->textBox88, 3, 15);
			this->tableLayoutPanel1->Controls->Add(this->textBox89, 4, 15);
			this->tableLayoutPanel1->Controls->Add(this->textBox90, 5, 15);
			this->tableLayoutPanel1->Controls->Add(this->textBox91, 0, 16);
			this->tableLayoutPanel1->Controls->Add(this->textBox92, 1, 16);
			this->tableLayoutPanel1->Controls->Add(this->textBox93, 2, 16);
			this->tableLayoutPanel1->Controls->Add(this->textBox94, 3, 16);
			this->tableLayoutPanel1->Controls->Add(this->textBox95, 4, 16);
			this->tableLayoutPanel1->Controls->Add(this->textBox96, 5, 16);
			this->tableLayoutPanel1->Controls->Add(this->textBox97, 0, 17);
			this->tableLayoutPanel1->Controls->Add(this->textBox98, 1, 17);
			this->tableLayoutPanel1->Controls->Add(this->textBox99, 2, 17);
			this->tableLayoutPanel1->Controls->Add(this->textBox100, 3, 17);
			this->tableLayoutPanel1->Controls->Add(this->textBox101, 4, 17);
			this->tableLayoutPanel1->Controls->Add(this->textBox102, 5, 17);
			this->tableLayoutPanel1->Controls->Add(this->textBox103, 0, 18);
			this->tableLayoutPanel1->Controls->Add(this->textBox104, 1, 18);
			this->tableLayoutPanel1->Controls->Add(this->textBox105, 2, 18);
			this->tableLayoutPanel1->Controls->Add(this->textBox106, 3, 18);
			this->tableLayoutPanel1->Controls->Add(this->textBox107, 4, 18);
			this->tableLayoutPanel1->Controls->Add(this->textBox108, 5, 18);
			this->tableLayoutPanel1->Controls->Add(this->textBox109, 0, 19);
			this->tableLayoutPanel1->Controls->Add(this->textBox110, 1, 19);
			this->tableLayoutPanel1->Controls->Add(this->textBox111, 2, 19);
			this->tableLayoutPanel1->Controls->Add(this->textBox112, 3, 19);
			this->tableLayoutPanel1->Controls->Add(this->textBox113, 4, 19);
			this->tableLayoutPanel1->Controls->Add(this->textBox114, 5, 19);
			this->tableLayoutPanel1->Controls->Add(this->textBox115, 0, 20);
			this->tableLayoutPanel1->Controls->Add(this->textBox116, 1, 20);
			this->tableLayoutPanel1->Controls->Add(this->textBox117, 2, 20);
			this->tableLayoutPanel1->Controls->Add(this->textBox118, 3, 20);
			this->tableLayoutPanel1->Controls->Add(this->textBox119, 4, 20);
			this->tableLayoutPanel1->Controls->Add(this->textBox120, 5, 20);
			this->tableLayoutPanel1->Controls->Add(this->label7, 0, 0);
			this->tableLayoutPanel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(46, 94);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 21;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.938272F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.320988F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 4.761972F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(673, 488);
			this->tableLayoutPanel1->TabIndex = 8;
			// 
			// textBox31
			// 
			this->textBox31->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox31->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox31->Location = System::Drawing::Point(5, 141);
			this->textBox31->Multiline = true;
			this->textBox31->Name = L"textBox31";
			this->textBox31->Size = System::Drawing::Size(31, 15);
			this->textBox31->TabIndex = 30;
			// 
			// textBox32
			// 
			this->textBox32->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox32->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox32->Location = System::Drawing::Point(50, 141);
			this->textBox32->Multiline = true;
			this->textBox32->Name = L"textBox32";
			this->textBox32->Size = System::Drawing::Size(286, 15);
			this->textBox32->TabIndex = 31;
			// 
			// textBox33
			// 
			this->textBox33->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox33->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox33->Location = System::Drawing::Point(347, 141);
			this->textBox33->Multiline = true;
			this->textBox33->Name = L"textBox33";
			this->textBox33->Size = System::Drawing::Size(70, 15);
			this->textBox33->TabIndex = 32;
			// 
			// textBox34
			// 
			this->textBox34->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox34->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox34->Location = System::Drawing::Point(428, 141);
			this->textBox34->Multiline = true;
			this->textBox34->Name = L"textBox34";
			this->textBox34->Size = System::Drawing::Size(66, 15);
			this->textBox34->TabIndex = 33;
			// 
			// textBox35
			// 
			this->textBox35->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox35->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox35->Location = System::Drawing::Point(511, 141);
			this->textBox35->Multiline = true;
			this->textBox35->Name = L"textBox35";
			this->textBox35->Size = System::Drawing::Size(73, 15);
			this->textBox35->TabIndex = 34;
			// 
			// textBox36
			// 
			this->textBox36->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox36->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox36->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox36->Location = System::Drawing::Point(592, 141);
			this->textBox36->Multiline = true;
			this->textBox36->Name = L"textBox36";
			this->textBox36->Size = System::Drawing::Size(64, 15);
			this->textBox36->TabIndex = 35;
			// 
			// textBox37
			// 
			this->textBox37->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox37->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox37->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox37->Location = System::Drawing::Point(5, 164);
			this->textBox37->Multiline = true;
			this->textBox37->Name = L"textBox37";
			this->textBox37->Size = System::Drawing::Size(31, 15);
			this->textBox37->TabIndex = 36;
			// 
			// textBox38
			// 
			this->textBox38->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox38->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox38->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox38->Location = System::Drawing::Point(50, 164);
			this->textBox38->Multiline = true;
			this->textBox38->Name = L"textBox38";
			this->textBox38->Size = System::Drawing::Size(286, 15);
			this->textBox38->TabIndex = 37;
			// 
			// textBox39
			// 
			this->textBox39->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox39->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox39->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox39->Location = System::Drawing::Point(347, 164);
			this->textBox39->Multiline = true;
			this->textBox39->Name = L"textBox39";
			this->textBox39->Size = System::Drawing::Size(70, 15);
			this->textBox39->TabIndex = 38;
			// 
			// textBox40
			// 
			this->textBox40->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox40->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox40->Location = System::Drawing::Point(428, 164);
			this->textBox40->Multiline = true;
			this->textBox40->Name = L"textBox40";
			this->textBox40->Size = System::Drawing::Size(66, 15);
			this->textBox40->TabIndex = 39;
			// 
			// textBox41
			// 
			this->textBox41->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox41->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox41->Location = System::Drawing::Point(511, 164);
			this->textBox41->Multiline = true;
			this->textBox41->Name = L"textBox41";
			this->textBox41->Size = System::Drawing::Size(73, 15);
			this->textBox41->TabIndex = 40;
			// 
			// textBox42
			// 
			this->textBox42->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox42->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox42->Location = System::Drawing::Point(592, 164);
			this->textBox42->Multiline = true;
			this->textBox42->Name = L"textBox42";
			this->textBox42->Size = System::Drawing::Size(64, 15);
			this->textBox42->TabIndex = 41;
			// 
			// textBox43
			// 
			this->textBox43->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox43->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox43->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox43->Location = System::Drawing::Point(5, 187);
			this->textBox43->Multiline = true;
			this->textBox43->Name = L"textBox43";
			this->textBox43->Size = System::Drawing::Size(31, 15);
			this->textBox43->TabIndex = 42;
			// 
			// textBox44
			// 
			this->textBox44->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox44->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox44->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox44->Location = System::Drawing::Point(50, 187);
			this->textBox44->Multiline = true;
			this->textBox44->Name = L"textBox44";
			this->textBox44->Size = System::Drawing::Size(286, 15);
			this->textBox44->TabIndex = 43;
			// 
			// textBox45
			// 
			this->textBox45->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox45->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox45->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox45->Location = System::Drawing::Point(347, 187);
			this->textBox45->Multiline = true;
			this->textBox45->Name = L"textBox45";
			this->textBox45->Size = System::Drawing::Size(70, 15);
			this->textBox45->TabIndex = 44;
			// 
			// textBox46
			// 
			this->textBox46->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox46->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox46->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox46->Location = System::Drawing::Point(428, 187);
			this->textBox46->Multiline = true;
			this->textBox46->Name = L"textBox46";
			this->textBox46->Size = System::Drawing::Size(66, 15);
			this->textBox46->TabIndex = 45;
			// 
			// textBox47
			// 
			this->textBox47->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox47->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox47->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox47->Location = System::Drawing::Point(511, 187);
			this->textBox47->Multiline = true;
			this->textBox47->Name = L"textBox47";
			this->textBox47->Size = System::Drawing::Size(73, 15);
			this->textBox47->TabIndex = 46;
			// 
			// textBox48
			// 
			this->textBox48->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox48->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox48->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox48->Location = System::Drawing::Point(592, 187);
			this->textBox48->Multiline = true;
			this->textBox48->Name = L"textBox48";
			this->textBox48->Size = System::Drawing::Size(64, 15);
			this->textBox48->TabIndex = 47;
			// 
			// textBox49
			// 
			this->textBox49->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox49->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox49->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox49->Location = System::Drawing::Point(5, 210);
			this->textBox49->Multiline = true;
			this->textBox49->Name = L"textBox49";
			this->textBox49->Size = System::Drawing::Size(31, 15);
			this->textBox49->TabIndex = 48;
			// 
			// textBox50
			// 
			this->textBox50->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox50->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox50->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox50->Location = System::Drawing::Point(50, 210);
			this->textBox50->Multiline = true;
			this->textBox50->Name = L"textBox50";
			this->textBox50->Size = System::Drawing::Size(286, 15);
			this->textBox50->TabIndex = 49;
			// 
			// textBox51
			// 
			this->textBox51->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox51->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox51->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox51->Location = System::Drawing::Point(347, 210);
			this->textBox51->Multiline = true;
			this->textBox51->Name = L"textBox51";
			this->textBox51->Size = System::Drawing::Size(70, 15);
			this->textBox51->TabIndex = 50;
			// 
			// textBox52
			// 
			this->textBox52->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox52->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox52->Location = System::Drawing::Point(428, 210);
			this->textBox52->Multiline = true;
			this->textBox52->Name = L"textBox52";
			this->textBox52->Size = System::Drawing::Size(66, 15);
			this->textBox52->TabIndex = 51;
			// 
			// textBox53
			// 
			this->textBox53->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox53->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox53->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox53->Location = System::Drawing::Point(511, 210);
			this->textBox53->Multiline = true;
			this->textBox53->Name = L"textBox53";
			this->textBox53->Size = System::Drawing::Size(73, 15);
			this->textBox53->TabIndex = 52;
			// 
			// textBox54
			// 
			this->textBox54->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox54->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox54->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox54->Location = System::Drawing::Point(592, 210);
			this->textBox54->Multiline = true;
			this->textBox54->Name = L"textBox54";
			this->textBox54->Size = System::Drawing::Size(64, 15);
			this->textBox54->TabIndex = 53;
			// 
			// textBox55
			// 
			this->textBox55->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox55->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox55->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox55->Location = System::Drawing::Point(5, 233);
			this->textBox55->Name = L"textBox55";
			this->textBox55->Size = System::Drawing::Size(31, 14);
			this->textBox55->TabIndex = 54;
			// 
			// textBox56
			// 
			this->textBox56->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox56->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox56->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox56->Location = System::Drawing::Point(50, 233);
			this->textBox56->Name = L"textBox56";
			this->textBox56->Size = System::Drawing::Size(286, 14);
			this->textBox56->TabIndex = 55;
			// 
			// textBox57
			// 
			this->textBox57->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox57->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox57->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox57->Location = System::Drawing::Point(347, 233);
			this->textBox57->Name = L"textBox57";
			this->textBox57->Size = System::Drawing::Size(70, 14);
			this->textBox57->TabIndex = 56;
			// 
			// textBox58
			// 
			this->textBox58->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox58->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox58->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox58->Location = System::Drawing::Point(428, 233);
			this->textBox58->Name = L"textBox58";
			this->textBox58->Size = System::Drawing::Size(66, 14);
			this->textBox58->TabIndex = 57;
			// 
			// textBox59
			// 
			this->textBox59->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox59->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox59->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox59->Location = System::Drawing::Point(511, 233);
			this->textBox59->Name = L"textBox59";
			this->textBox59->Size = System::Drawing::Size(73, 14);
			this->textBox59->TabIndex = 58;
			// 
			// textBox60
			// 
			this->textBox60->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox60->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox60->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox60->Location = System::Drawing::Point(592, 233);
			this->textBox60->Name = L"textBox60";
			this->textBox60->Size = System::Drawing::Size(64, 14);
			this->textBox60->TabIndex = 59;
			// 
			// textBox61
			// 
			this->textBox61->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox61->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox61->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox61->Location = System::Drawing::Point(5, 256);
			this->textBox61->Name = L"textBox61";
			this->textBox61->Size = System::Drawing::Size(36, 14);
			this->textBox61->TabIndex = 60;
			// 
			// textBox62
			// 
			this->textBox62->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox62->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox62->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox62->Location = System::Drawing::Point(50, 256);
			this->textBox62->Name = L"textBox62";
			this->textBox62->Size = System::Drawing::Size(286, 14);
			this->textBox62->TabIndex = 61;
			// 
			// textBox63
			// 
			this->textBox63->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox63->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox63->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox63->Location = System::Drawing::Point(347, 256);
			this->textBox63->Name = L"textBox63";
			this->textBox63->Size = System::Drawing::Size(70, 14);
			this->textBox63->TabIndex = 62;
			// 
			// textBox64
			// 
			this->textBox64->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox64->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox64->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox64->Location = System::Drawing::Point(428, 256);
			this->textBox64->Name = L"textBox64";
			this->textBox64->Size = System::Drawing::Size(66, 14);
			this->textBox64->TabIndex = 63;
			// 
			// textBox65
			// 
			this->textBox65->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox65->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox65->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox65->Location = System::Drawing::Point(511, 256);
			this->textBox65->Name = L"textBox65";
			this->textBox65->Size = System::Drawing::Size(73, 14);
			this->textBox65->TabIndex = 64;
			// 
			// textBox66
			// 
			this->textBox66->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox66->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox66->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox66->Location = System::Drawing::Point(592, 256);
			this->textBox66->Name = L"textBox66";
			this->textBox66->Size = System::Drawing::Size(64, 14);
			this->textBox66->TabIndex = 65;
			// 
			// textBox67
			// 
			this->textBox67->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox67->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox67->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox67->Location = System::Drawing::Point(5, 279);
			this->textBox67->Name = L"textBox67";
			this->textBox67->Size = System::Drawing::Size(36, 14);
			this->textBox67->TabIndex = 66;
			// 
			// textBox68
			// 
			this->textBox68->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox68->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox68->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox68->Location = System::Drawing::Point(50, 279);
			this->textBox68->Name = L"textBox68";
			this->textBox68->Size = System::Drawing::Size(286, 14);
			this->textBox68->TabIndex = 67;
			// 
			// textBox69
			// 
			this->textBox69->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox69->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox69->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox69->Location = System::Drawing::Point(347, 279);
			this->textBox69->Name = L"textBox69";
			this->textBox69->Size = System::Drawing::Size(70, 14);
			this->textBox69->TabIndex = 68;
			// 
			// textBox70
			// 
			this->textBox70->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox70->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox70->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox70->Location = System::Drawing::Point(428, 279);
			this->textBox70->Name = L"textBox70";
			this->textBox70->Size = System::Drawing::Size(66, 14);
			this->textBox70->TabIndex = 69;
			// 
			// textBox71
			// 
			this->textBox71->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox71->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox71->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox71->Location = System::Drawing::Point(511, 279);
			this->textBox71->Name = L"textBox71";
			this->textBox71->Size = System::Drawing::Size(73, 14);
			this->textBox71->TabIndex = 70;
			// 
			// textBox72
			// 
			this->textBox72->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox72->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox72->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox72->Location = System::Drawing::Point(592, 279);
			this->textBox72->Name = L"textBox72";
			this->textBox72->Size = System::Drawing::Size(64, 14);
			this->textBox72->TabIndex = 71;
			// 
			// textBox73
			// 
			this->textBox73->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox73->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox73->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox73->Location = System::Drawing::Point(5, 302);
			this->textBox73->Name = L"textBox73";
			this->textBox73->Size = System::Drawing::Size(36, 14);
			this->textBox73->TabIndex = 72;
			// 
			// textBox74
			// 
			this->textBox74->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox74->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox74->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox74->Location = System::Drawing::Point(50, 302);
			this->textBox74->Name = L"textBox74";
			this->textBox74->Size = System::Drawing::Size(286, 14);
			this->textBox74->TabIndex = 73;
			// 
			// textBox75
			// 
			this->textBox75->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox75->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox75->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox75->Location = System::Drawing::Point(347, 302);
			this->textBox75->Name = L"textBox75";
			this->textBox75->Size = System::Drawing::Size(70, 14);
			this->textBox75->TabIndex = 74;
			// 
			// textBox76
			// 
			this->textBox76->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox76->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox76->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox76->Location = System::Drawing::Point(428, 302);
			this->textBox76->Name = L"textBox76";
			this->textBox76->Size = System::Drawing::Size(66, 14);
			this->textBox76->TabIndex = 75;
			// 
			// textBox77
			// 
			this->textBox77->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox77->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox77->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox77->Location = System::Drawing::Point(511, 302);
			this->textBox77->Name = L"textBox77";
			this->textBox77->Size = System::Drawing::Size(73, 14);
			this->textBox77->TabIndex = 76;
			// 
			// textBox78
			// 
			this->textBox78->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox78->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox78->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox78->Location = System::Drawing::Point(592, 302);
			this->textBox78->Name = L"textBox78";
			this->textBox78->Size = System::Drawing::Size(64, 14);
			this->textBox78->TabIndex = 77;
			// 
			// textBox79
			// 
			this->textBox79->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox79->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox79->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox79->Location = System::Drawing::Point(5, 325);
			this->textBox79->Name = L"textBox79";
			this->textBox79->Size = System::Drawing::Size(36, 14);
			this->textBox79->TabIndex = 78;
			// 
			// textBox80
			// 
			this->textBox80->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox80->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox80->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox80->Location = System::Drawing::Point(50, 325);
			this->textBox80->Name = L"textBox80";
			this->textBox80->Size = System::Drawing::Size(286, 14);
			this->textBox80->TabIndex = 79;
			// 
			// textBox81
			// 
			this->textBox81->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox81->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox81->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox81->Location = System::Drawing::Point(347, 325);
			this->textBox81->Name = L"textBox81";
			this->textBox81->Size = System::Drawing::Size(70, 14);
			this->textBox81->TabIndex = 80;
			// 
			// textBox82
			// 
			this->textBox82->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox82->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox82->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox82->Location = System::Drawing::Point(428, 325);
			this->textBox82->Name = L"textBox82";
			this->textBox82->Size = System::Drawing::Size(66, 14);
			this->textBox82->TabIndex = 81;
			// 
			// textBox83
			// 
			this->textBox83->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox83->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox83->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox83->Location = System::Drawing::Point(511, 325);
			this->textBox83->Name = L"textBox83";
			this->textBox83->Size = System::Drawing::Size(73, 14);
			this->textBox83->TabIndex = 82;
			// 
			// textBox84
			// 
			this->textBox84->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox84->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox84->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox84->Location = System::Drawing::Point(592, 325);
			this->textBox84->Name = L"textBox84";
			this->textBox84->Size = System::Drawing::Size(64, 14);
			this->textBox84->TabIndex = 83;
			// 
			// textBox85
			// 
			this->textBox85->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox85->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox85->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox85->Location = System::Drawing::Point(5, 348);
			this->textBox85->Name = L"textBox85";
			this->textBox85->Size = System::Drawing::Size(31, 14);
			this->textBox85->TabIndex = 84;
			// 
			// textBox86
			// 
			this->textBox86->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox86->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox86->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox86->Location = System::Drawing::Point(50, 348);
			this->textBox86->Name = L"textBox86";
			this->textBox86->Size = System::Drawing::Size(286, 14);
			this->textBox86->TabIndex = 85;
			// 
			// textBox87
			// 
			this->textBox87->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox87->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox87->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox87->Location = System::Drawing::Point(347, 348);
			this->textBox87->Name = L"textBox87";
			this->textBox87->Size = System::Drawing::Size(70, 14);
			this->textBox87->TabIndex = 86;
			// 
			// textBox88
			// 
			this->textBox88->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox88->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox88->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox88->Location = System::Drawing::Point(428, 348);
			this->textBox88->Name = L"textBox88";
			this->textBox88->Size = System::Drawing::Size(66, 14);
			this->textBox88->TabIndex = 87;
			// 
			// textBox89
			// 
			this->textBox89->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox89->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox89->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox89->Location = System::Drawing::Point(511, 348);
			this->textBox89->Name = L"textBox89";
			this->textBox89->Size = System::Drawing::Size(73, 14);
			this->textBox89->TabIndex = 88;
			// 
			// textBox90
			// 
			this->textBox90->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox90->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox90->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox90->Location = System::Drawing::Point(592, 348);
			this->textBox90->Name = L"textBox90";
			this->textBox90->Size = System::Drawing::Size(64, 14);
			this->textBox90->TabIndex = 89;
			// 
			// textBox91
			// 
			this->textBox91->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox91->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox91->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox91->Location = System::Drawing::Point(5, 371);
			this->textBox91->Name = L"textBox91";
			this->textBox91->Size = System::Drawing::Size(36, 14);
			this->textBox91->TabIndex = 90;
			// 
			// textBox92
			// 
			this->textBox92->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox92->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox92->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox92->Location = System::Drawing::Point(50, 371);
			this->textBox92->Name = L"textBox92";
			this->textBox92->Size = System::Drawing::Size(286, 14);
			this->textBox92->TabIndex = 91;
			// 
			// textBox93
			// 
			this->textBox93->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox93->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox93->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox93->Location = System::Drawing::Point(347, 371);
			this->textBox93->Name = L"textBox93";
			this->textBox93->Size = System::Drawing::Size(70, 14);
			this->textBox93->TabIndex = 92;
			// 
			// textBox94
			// 
			this->textBox94->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox94->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox94->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox94->Location = System::Drawing::Point(428, 371);
			this->textBox94->Name = L"textBox94";
			this->textBox94->Size = System::Drawing::Size(66, 14);
			this->textBox94->TabIndex = 93;
			// 
			// textBox95
			// 
			this->textBox95->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox95->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox95->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox95->Location = System::Drawing::Point(511, 371);
			this->textBox95->Name = L"textBox95";
			this->textBox95->Size = System::Drawing::Size(73, 14);
			this->textBox95->TabIndex = 94;
			// 
			// textBox96
			// 
			this->textBox96->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox96->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox96->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox96->Location = System::Drawing::Point(592, 371);
			this->textBox96->Name = L"textBox96";
			this->textBox96->Size = System::Drawing::Size(64, 14);
			this->textBox96->TabIndex = 95;
			// 
			// textBox97
			// 
			this->textBox97->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox97->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox97->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox97->Location = System::Drawing::Point(5, 394);
			this->textBox97->Name = L"textBox97";
			this->textBox97->Size = System::Drawing::Size(36, 14);
			this->textBox97->TabIndex = 96;
			// 
			// textBox98
			// 
			this->textBox98->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox98->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox98->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox98->Location = System::Drawing::Point(50, 394);
			this->textBox98->Name = L"textBox98";
			this->textBox98->Size = System::Drawing::Size(286, 14);
			this->textBox98->TabIndex = 97;
			// 
			// textBox99
			// 
			this->textBox99->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox99->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox99->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox99->Location = System::Drawing::Point(347, 394);
			this->textBox99->Name = L"textBox99";
			this->textBox99->Size = System::Drawing::Size(70, 14);
			this->textBox99->TabIndex = 98;
			// 
			// textBox100
			// 
			this->textBox100->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox100->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox100->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox100->Location = System::Drawing::Point(428, 394);
			this->textBox100->Name = L"textBox100";
			this->textBox100->Size = System::Drawing::Size(66, 14);
			this->textBox100->TabIndex = 99;
			// 
			// textBox101
			// 
			this->textBox101->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox101->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox101->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox101->Location = System::Drawing::Point(511, 394);
			this->textBox101->Name = L"textBox101";
			this->textBox101->Size = System::Drawing::Size(73, 14);
			this->textBox101->TabIndex = 100;
			// 
			// textBox102
			// 
			this->textBox102->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox102->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox102->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox102->Location = System::Drawing::Point(592, 394);
			this->textBox102->Name = L"textBox102";
			this->textBox102->Size = System::Drawing::Size(64, 14);
			this->textBox102->TabIndex = 101;
			// 
			// textBox103
			// 
			this->textBox103->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox103->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox103->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox103->Location = System::Drawing::Point(5, 417);
			this->textBox103->Name = L"textBox103";
			this->textBox103->Size = System::Drawing::Size(36, 14);
			this->textBox103->TabIndex = 102;
			// 
			// textBox104
			// 
			this->textBox104->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox104->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox104->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox104->Location = System::Drawing::Point(50, 417);
			this->textBox104->Name = L"textBox104";
			this->textBox104->Size = System::Drawing::Size(286, 14);
			this->textBox104->TabIndex = 103;
			// 
			// textBox105
			// 
			this->textBox105->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox105->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox105->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox105->Location = System::Drawing::Point(347, 417);
			this->textBox105->Name = L"textBox105";
			this->textBox105->Size = System::Drawing::Size(70, 14);
			this->textBox105->TabIndex = 104;
			// 
			// textBox106
			// 
			this->textBox106->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox106->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox106->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox106->Location = System::Drawing::Point(428, 417);
			this->textBox106->Name = L"textBox106";
			this->textBox106->Size = System::Drawing::Size(66, 14);
			this->textBox106->TabIndex = 105;
			// 
			// textBox107
			// 
			this->textBox107->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox107->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox107->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox107->Location = System::Drawing::Point(511, 417);
			this->textBox107->Name = L"textBox107";
			this->textBox107->Size = System::Drawing::Size(73, 14);
			this->textBox107->TabIndex = 106;
			// 
			// textBox108
			// 
			this->textBox108->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox108->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox108->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox108->Location = System::Drawing::Point(592, 417);
			this->textBox108->Name = L"textBox108";
			this->textBox108->Size = System::Drawing::Size(64, 14);
			this->textBox108->TabIndex = 107;
			// 
			// textBox109
			// 
			this->textBox109->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox109->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox109->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox109->Location = System::Drawing::Point(5, 440);
			this->textBox109->Name = L"textBox109";
			this->textBox109->Size = System::Drawing::Size(36, 14);
			this->textBox109->TabIndex = 108;
			// 
			// textBox110
			// 
			this->textBox110->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox110->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox110->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox110->Location = System::Drawing::Point(50, 440);
			this->textBox110->Name = L"textBox110";
			this->textBox110->Size = System::Drawing::Size(286, 14);
			this->textBox110->TabIndex = 109;
			// 
			// textBox111
			// 
			this->textBox111->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox111->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox111->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox111->Location = System::Drawing::Point(347, 440);
			this->textBox111->Name = L"textBox111";
			this->textBox111->Size = System::Drawing::Size(70, 14);
			this->textBox111->TabIndex = 110;
			// 
			// textBox112
			// 
			this->textBox112->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox112->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox112->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox112->Location = System::Drawing::Point(428, 440);
			this->textBox112->Name = L"textBox112";
			this->textBox112->Size = System::Drawing::Size(66, 14);
			this->textBox112->TabIndex = 111;
			// 
			// textBox113
			// 
			this->textBox113->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox113->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox113->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox113->Location = System::Drawing::Point(511, 440);
			this->textBox113->Name = L"textBox113";
			this->textBox113->Size = System::Drawing::Size(73, 14);
			this->textBox113->TabIndex = 112;
			// 
			// textBox114
			// 
			this->textBox114->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox114->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox114->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox114->Location = System::Drawing::Point(592, 440);
			this->textBox114->Name = L"textBox114";
			this->textBox114->Size = System::Drawing::Size(64, 14);
			this->textBox114->TabIndex = 113;
			// 
			// textBox115
			// 
			this->textBox115->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox115->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox115->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox115->Location = System::Drawing::Point(5, 463);
			this->textBox115->Name = L"textBox115";
			this->textBox115->Size = System::Drawing::Size(36, 14);
			this->textBox115->TabIndex = 114;
			// 
			// textBox116
			// 
			this->textBox116->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox116->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox116->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox116->Location = System::Drawing::Point(50, 463);
			this->textBox116->Name = L"textBox116";
			this->textBox116->Size = System::Drawing::Size(286, 14);
			this->textBox116->TabIndex = 115;
			// 
			// textBox117
			// 
			this->textBox117->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox117->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox117->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox117->Location = System::Drawing::Point(347, 463);
			this->textBox117->Name = L"textBox117";
			this->textBox117->Size = System::Drawing::Size(70, 14);
			this->textBox117->TabIndex = 116;
			// 
			// textBox118
			// 
			this->textBox118->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox118->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox118->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox118->Location = System::Drawing::Point(428, 463);
			this->textBox118->Name = L"textBox118";
			this->textBox118->Size = System::Drawing::Size(66, 14);
			this->textBox118->TabIndex = 117;
			// 
			// textBox119
			// 
			this->textBox119->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox119->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox119->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox119->Location = System::Drawing::Point(511, 463);
			this->textBox119->Name = L"textBox119";
			this->textBox119->Size = System::Drawing::Size(73, 14);
			this->textBox119->TabIndex = 118;
			// 
			// textBox120
			// 
			this->textBox120->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox120->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox120->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox120->Location = System::Drawing::Point(592, 463);
			this->textBox120->Name = L"textBox120";
			this->textBox120->Size = System::Drawing::Size(64, 14);
			this->textBox120->TabIndex = 119;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::AliceBlue;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(5, 2);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(25, 15);
			this->label7->TabIndex = 120;
			this->label7->Text = L"No";
			// 
			// promptBox
			// 
			this->promptBox->BackColor = System::Drawing::Color::AliceBlue;
			this->promptBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->promptBox->Location = System::Drawing::Point(146, 80);
			this->promptBox->Name = L"promptBox";
			this->promptBox->Size = System::Drawing::Size(692, 13);
			this->promptBox->TabIndex = 11;
			this->promptBox->Visible = false;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->BackColor = System::Drawing::Color::AliceBlue;
			this->tableLayoutPanel2->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				14.95049F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				85.04951F)));
			this->tableLayoutPanel2->Controls->Add(this->label8, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->textBox121, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->textBox122, 1, 2);
			this->tableLayoutPanel2->Controls->Add(this->textBox123, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->label9, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->textBox124, 1, 3);
			this->tableLayoutPanel2->Controls->Add(this->textBox125, 0, 4);
			this->tableLayoutPanel2->Controls->Add(this->textBox126, 1, 4);
			this->tableLayoutPanel2->Controls->Add(this->textBox127, 0, 5);
			this->tableLayoutPanel2->Controls->Add(this->textBox128, 1, 5);
			this->tableLayoutPanel2->Controls->Add(this->textBox129, 0, 6);
			this->tableLayoutPanel2->Controls->Add(this->textBox130, 1, 6);
			this->tableLayoutPanel2->Controls->Add(this->textBox131, 0, 7);
			this->tableLayoutPanel2->Controls->Add(this->textBox132, 1, 7);
			this->tableLayoutPanel2->Controls->Add(this->textBox133, 0, 8);
			this->tableLayoutPanel2->Controls->Add(this->textBox134, 1, 8);
			this->tableLayoutPanel2->Controls->Add(this->textBox135, 0, 9);
			this->tableLayoutPanel2->Controls->Add(this->textBox136, 1, 9);
			this->tableLayoutPanel2->Controls->Add(this->textBox137, 0, 10);
			this->tableLayoutPanel2->Controls->Add(this->textBox138, 1, 10);
			this->tableLayoutPanel2->Controls->Add(this->textBox139, 0, 11);
			this->tableLayoutPanel2->Controls->Add(this->textBox140, 1, 11);
			this->tableLayoutPanel2->Controls->Add(this->textBox141, 0, 12);
			this->tableLayoutPanel2->Controls->Add(this->textBox142, 1, 12);
			this->tableLayoutPanel2->Controls->Add(this->textBox143, 0, 13);
			this->tableLayoutPanel2->Controls->Add(this->textBox144, 1, 13);
			this->tableLayoutPanel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tableLayoutPanel2->Location = System::Drawing::Point(748, 94);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 14;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 0)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.799891F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.169597F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.852417F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.511007F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 8.193826F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.852417F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.511007F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.852417F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 8.193826F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.852417F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.511007F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.511007F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.18916F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(227, 298);
			this->tableLayoutPanel2->TabIndex = 10;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(38, 2);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(141, 15);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Miscellaneous Tasks";
			// 
			// textBox121
			// 
			this->textBox121->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox121->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox121->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox121->Location = System::Drawing::Point(4, 28);
			this->textBox121->Multiline = true;
			this->textBox121->Name = L"textBox121";
			this->textBox121->Size = System::Drawing::Size(24, 14);
			this->textBox121->TabIndex = 1;
			// 
			// textBox122
			// 
			this->textBox122->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox122->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox122->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox122->Location = System::Drawing::Point(38, 28);
			this->textBox122->Multiline = true;
			this->textBox122->Name = L"textBox122";
			this->textBox122->Size = System::Drawing::Size(175, 14);
			this->textBox122->TabIndex = 2;
			// 
			// textBox123
			// 
			this->textBox123->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox123->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox123->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox123->Location = System::Drawing::Point(4, 49);
			this->textBox123->Multiline = true;
			this->textBox123->Name = L"textBox123";
			this->textBox123->Size = System::Drawing::Size(24, 16);
			this->textBox123->TabIndex = 3;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(4, 2);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(25, 15);
			this->label9->TabIndex = 4;
			this->label9->Text = L"No";
			// 
			// textBox124
			// 
			this->textBox124->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox124->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox124->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox124->Location = System::Drawing::Point(38, 49);
			this->textBox124->Multiline = true;
			this->textBox124->Name = L"textBox124";
			this->textBox124->Size = System::Drawing::Size(174, 16);
			this->textBox124->TabIndex = 5;
			// 
			// textBox125
			// 
			this->textBox125->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox125->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox125->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox125->Location = System::Drawing::Point(4, 72);
			this->textBox125->Multiline = true;
			this->textBox125->Name = L"textBox125";
			this->textBox125->Size = System::Drawing::Size(24, 13);
			this->textBox125->TabIndex = 6;
			// 
			// textBox126
			// 
			this->textBox126->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox126->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox126->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox126->Location = System::Drawing::Point(38, 72);
			this->textBox126->Multiline = true;
			this->textBox126->Name = L"textBox126";
			this->textBox126->Size = System::Drawing::Size(174, 13);
			this->textBox126->TabIndex = 7;
			// 
			// textBox127
			// 
			this->textBox127->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox127->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox127->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox127->Location = System::Drawing::Point(4, 94);
			this->textBox127->Multiline = true;
			this->textBox127->Name = L"textBox127";
			this->textBox127->Size = System::Drawing::Size(24, 16);
			this->textBox127->TabIndex = 8;
			// 
			// textBox128
			// 
			this->textBox128->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox128->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox128->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox128->Location = System::Drawing::Point(38, 94);
			this->textBox128->Multiline = true;
			this->textBox128->Name = L"textBox128";
			this->textBox128->Size = System::Drawing::Size(174, 16);
			this->textBox128->TabIndex = 9;
			// 
			// textBox129
			// 
			this->textBox129->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox129->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox129->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox129->Location = System::Drawing::Point(4, 118);
			this->textBox129->Multiline = true;
			this->textBox129->Name = L"textBox129";
			this->textBox129->Size = System::Drawing::Size(24, 14);
			this->textBox129->TabIndex = 10;
			// 
			// textBox130
			// 
			this->textBox130->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox130->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox130->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox130->Location = System::Drawing::Point(38, 118);
			this->textBox130->Multiline = true;
			this->textBox130->Name = L"textBox130";
			this->textBox130->Size = System::Drawing::Size(174, 14);
			this->textBox130->TabIndex = 11;
			// 
			// textBox131
			// 
			this->textBox131->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox131->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox131->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox131->Location = System::Drawing::Point(4, 141);
			this->textBox131->Multiline = true;
			this->textBox131->Name = L"textBox131";
			this->textBox131->Size = System::Drawing::Size(24, 15);
			this->textBox131->TabIndex = 12;
			// 
			// textBox132
			// 
			this->textBox132->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox132->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox132->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox132->Location = System::Drawing::Point(38, 141);
			this->textBox132->Multiline = true;
			this->textBox132->Name = L"textBox132";
			this->textBox132->Size = System::Drawing::Size(174, 15);
			this->textBox132->TabIndex = 13;
			// 
			// textBox133
			// 
			this->textBox133->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox133->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox133->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox133->Location = System::Drawing::Point(4, 163);
			this->textBox133->Multiline = true;
			this->textBox133->Name = L"textBox133";
			this->textBox133->Size = System::Drawing::Size(24, 16);
			this->textBox133->TabIndex = 14;
			// 
			// textBox134
			// 
			this->textBox134->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox134->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox134->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox134->Location = System::Drawing::Point(38, 163);
			this->textBox134->Multiline = true;
			this->textBox134->Name = L"textBox134";
			this->textBox134->Size = System::Drawing::Size(174, 16);
			this->textBox134->TabIndex = 15;
			// 
			// textBox135
			// 
			this->textBox135->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox135->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox135->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox135->Location = System::Drawing::Point(4, 186);
			this->textBox135->Multiline = true;
			this->textBox135->Name = L"textBox135";
			this->textBox135->Size = System::Drawing::Size(24, 16);
			this->textBox135->TabIndex = 16;
			// 
			// textBox136
			// 
			this->textBox136->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox136->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox136->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox136->Location = System::Drawing::Point(38, 186);
			this->textBox136->Multiline = true;
			this->textBox136->Name = L"textBox136";
			this->textBox136->Size = System::Drawing::Size(174, 16);
			this->textBox136->TabIndex = 17;
			// 
			// textBox137
			// 
			this->textBox137->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox137->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox137->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox137->Location = System::Drawing::Point(4, 210);
			this->textBox137->Multiline = true;
			this->textBox137->Name = L"textBox137";
			this->textBox137->Size = System::Drawing::Size(24, 15);
			this->textBox137->TabIndex = 18;
			// 
			// textBox138
			// 
			this->textBox138->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox138->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox138->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox138->Location = System::Drawing::Point(38, 210);
			this->textBox138->Multiline = true;
			this->textBox138->Name = L"textBox138";
			this->textBox138->Size = System::Drawing::Size(174, 15);
			this->textBox138->TabIndex = 19;
			// 
			// textBox139
			// 
			this->textBox139->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox139->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox139->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox139->Location = System::Drawing::Point(4, 233);
			this->textBox139->Multiline = true;
			this->textBox139->Name = L"textBox139";
			this->textBox139->Size = System::Drawing::Size(24, 15);
			this->textBox139->TabIndex = 20;
			// 
			// textBox140
			// 
			this->textBox140->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox140->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox140->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox140->Location = System::Drawing::Point(38, 233);
			this->textBox140->Multiline = true;
			this->textBox140->Name = L"textBox140";
			this->textBox140->Size = System::Drawing::Size(174, 15);
			this->textBox140->TabIndex = 21;
			// 
			// textBox141
			// 
			this->textBox141->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox141->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox141->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox141->Location = System::Drawing::Point(4, 255);
			this->textBox141->Multiline = true;
			this->textBox141->Name = L"textBox141";
			this->textBox141->Size = System::Drawing::Size(24, 15);
			this->textBox141->TabIndex = 22;
			// 
			// textBox142
			// 
			this->textBox142->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox142->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox142->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox142->Location = System::Drawing::Point(38, 255);
			this->textBox142->Multiline = true;
			this->textBox142->Name = L"textBox142";
			this->textBox142->Size = System::Drawing::Size(174, 15);
			this->textBox142->TabIndex = 23;
			// 
			// textBox143
			// 
			this->textBox143->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox143->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox143->Location = System::Drawing::Point(4, 277);
			this->textBox143->Name = L"textBox143";
			this->textBox143->Size = System::Drawing::Size(24, 14);
			this->textBox143->TabIndex = 12;
			// 
			// textBox144
			// 
			this->textBox144->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox144->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox144->Location = System::Drawing::Point(38, 277);
			this->textBox144->Name = L"textBox144";
			this->textBox144->Size = System::Drawing::Size(174, 14);
			this->textBox144->TabIndex = 24;
			// 
			// helpBox
			// 
			this->helpBox->BackColor = System::Drawing::Color::LavenderBlush;
			this->helpBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpBox->Location = System::Drawing::Point(46, 94);
			this->helpBox->Name = L"helpBox";
			this->helpBox->Size = System::Drawing::Size(672, 488);
			this->helpBox->TabIndex = 11;
			this->helpBox->Text = L"";
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->BackColor = System::Drawing::Color::AliceBlue;
			this->monthCalendar1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->monthCalendar1->Location = System::Drawing::Point(748, 416);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 11;
			this->monthCalendar1->TitleBackColor = System::Drawing::Color::AliceBlue;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::AliceBlue;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(45, 588);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(63, 15);
			this->label10->TabIndex = 12;
			this->label10->Text = L"↑ Previous";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::AliceBlue;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(677, 588);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(41, 15);
			this->label11->TabIndex = 13;
			this->label11->Text = L"Next ↓";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::AliceBlue;
			this->label12->Location = System::Drawing::Point(749, 395);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(60, 13);
			this->label12->TabIndex = 14;
			this->label12->Text = L"<--Previous";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::AliceBlue;
			this->label13->Location = System::Drawing::Point(934, 396);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(41, 13);
			this->label13->TabIndex = 15;
			this->label13->Text = L"Next-->";
			// 
			// CMGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(1006, 614);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->monthCalendar1);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->inputBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"CMGUI";
			this->Text = L"CheckMate";
			this->TransparencyKey = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//@author A0118918W
	//Accept User Input when the user types enter key
	private: System::Void inputBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
				 if(e->KeyChar == (char)13) {
					 promptBox->Visible = false;
					 std::string input = acceptInput();
					 std::string inputCopy = input;
					// boost::algorithm::to_lower(inputCopy);
					 if(input == "exit")	{
						 Application::Exit();
					 } else if(inputCopy == "help")	{
						 activateHelp();
					 }	else {
						 initializeCounts();
				 helpBox->Visible = false;
				 tableLayoutPanel1->Visible = true;				
				 testSample->executeCommand(input);
				 displayOutput(0,0);
				 inputBox->Clear();
				 _counter = 0;
					 }
					 e->Handled = true;
				 }
			 }


			 void initializeCounts()	{
				 _countDown =0;
				 _countUp = 0;
				 _countLeft =0;
				 _countRight =0;
			 }



			 void activateHelp()	{
				 helpBox->Visible =true;
				 Controls->Add(helpBox);
				 helpBoxText();
				 helpBox->BringToFront();
				 tableLayoutPanel1->Visible = true;
				 inputBox->Clear();
			 }


			 std::string acceptInput()	{
				 System::String ^ Input = inputBox->Text;
				 std::string actualInput = msclr::interop::marshal_as<std::string>(Input);
				 return actualInput;
			 }


			 void setNumOfPages(int floatTaskIndex)	{
				 _numOfPages = (floatTaskIndex/20);
				 int remainder = floatTaskIndex%20;
				 if(remainder > 0)	{
					 _numOfPages++;
				 }
			 }

			 void setNumOfFloatPages(int sizeOfList, int floatTaskIndex)	{
				 _numOfFloatPages = (sizeOfList-floatTaskIndex)/12;
				 int floatremainder = (sizeOfList-floatTaskIndex)%12;
				 if(floatremainder > 0)	{
					 _numOfFloatPages++;
				 }
			 }



	public : void displayOutput(int start, int startFloat)	{
				 Output* obj = testSample->getDisplay();
				 std::vector<Task*> TaskList = obj->getDisplay();
				 int sizeOfList = TaskList.size();
				 int floatTaskIndex = obj->getFirstFloat();
				 setNumOfPages(floatTaskIndex);
				 setNumOfFloatPages(sizeOfList, floatTaskIndex);
				 feedback(obj);
				 array<TextBox ^, 1> ^ mainTask = initializeMainArray();
				 array<TextBox ^, 1> ^ floatTask = initializeFloatArray();
				 clearMainArray(mainTask);
				 clearFloatArray(floatTask);
				 int end = endValue(floatTaskIndex, start);
				 int tempCounter=0;
				 for(int i=start;i<end;i++)	{
					 boost::posix_time::ptime buffer = (*TaskList[i]).getStart();
					 std::ostringstream oss1 = getDate(buffer);
					 std::ostringstream oss2 = getTime(buffer);
					 buffer = (*TaskList[i]).getEnd();
					 std::ostringstream oss3 = getDate(buffer);
					 std::ostringstream oss4 = getTime(buffer);
					 std::string Description = TaskList[i]->getDescription();
					 setFont(i, tempCounter, mainTask, obj); 
					 mainTask[6*tempCounter]->Text = gcnew System::String((std::to_string(i+1)).c_str());
					 mainTask[(6*tempCounter)+1]->Text = gcnew System::String(Description.c_str());
					 mainTask[(6*tempCounter)+2]->Text = gcnew System::String((oss1.str()).c_str());
					 mainTask[(6*tempCounter)+3]->Text = gcnew System::String((oss2.str()).c_str());
					 mainTask[(6*tempCounter)+4]->Text = gcnew System::String((oss3.str()).c_str());
					 mainTask[(6*tempCounter)+5]->Text = gcnew System::String((oss4.str()).c_str());
					 tempCounter++;
				 }
				 displayFloatTask(startFloat, floatTaskIndex, floatTask, TaskList, obj );
			 }

			 void feedback(Output* obj)	{
				 std::string feedback = obj->getFeedback();
				 int feedbackIndex = obj->getLastAction();
				 promptBox->Text = gcnew System::String(feedback.c_str());
				 feedbackTest(feedback);
			 }

			 void setFont(int i,  int j, array<TextBox ^, 1> ^ &mainTask, Output* obj)	{
				 int feedbackIndex = obj->getLastAction();
				 if(i==feedbackIndex) {
					 setFontGreen(mainTask, j);	
				 }	else {
					 if(obj->getListType() == true)	{
						 setFontGrey(mainTask, j);
					 } else {
						 setFontBlack(mainTask, j);
					 }
				 }	  
			 }


			 std::ostringstream getDate(boost::posix_time::ptime buffer)	{
				 std::ostringstream oss1;
				 boost::posix_time::time_facet* date_output_facet = new boost::posix_time::time_facet ("%d %b %Y");
				 oss1.imbue(std::locale(oss1.getloc(), date_output_facet));
				 if (buffer!=boost::posix_time::ptime()){
					 oss1 << buffer;
				 }
				 else {
					 oss1 << constants->HYPHEN;
				 }
				 return oss1;
			 }

			 std::ostringstream getTime(boost::posix_time::ptime buffer)	{
				 std::ostringstream oss2;
				 boost::posix_time::time_facet* time_output_facet = new boost::posix_time::time_facet ("%I:%M %p");
				 oss2.imbue(std::locale(oss2.getloc(), time_output_facet));
				 if (buffer!=boost::posix_time::ptime()){
					 oss2 << buffer;
				 }
				 else {
					 oss2 << constants->HYPHEN;
				 }
				 return oss2;
			 }

			 void displayFloatTask(int startFloat, int floatTaskIndex, array<TextBox ^, 1> ^ &floatTask, std::vector<Task*> &TaskList, Output* obj)	{
				int feedbackIndex = obj->getLastAction();
				 int tempCounter = 0;
				 int sizeOfList = TaskList.size();
				 startFloat = floatTaskIndex + startFloat;
				 int endFloat = endFloatValue(sizeOfList, startFloat);

				 for(int i=startFloat;i<endFloat; i++)	
				 {
					 setfeedbackFont(i, feedbackIndex, tempCounter, floatTask);
					 std::string Description = TaskList[i]->getDescription();
					 floatTask[tempCounter]->Text = gcnew System::String((std::to_string(i+1)).c_str());
					 floatTask[tempCounter+1]->Text = gcnew System::String(Description.c_str());
					 tempCounter = tempCounter + 2;
				 }
			 }


			 void setfeedbackFont(int i, int feedbackIndex, int tempCounter, array<TextBox ^, 1> ^ &floatTask)	{
				 if(i==feedbackIndex) {
					 setFeedbackFontGreen(floatTask, tempCounter);
				 }else	{
					 setFeedbackFontBlack(floatTask, tempCounter);
				 }
			 }

			 void setFeedbackFontGreen(array<TextBox ^, 1> ^ &floatTask, int index)	{
				 floatTask[index]->ForeColor = System::Drawing::Color::Green;
				 floatTask[index+1]->ForeColor = System::Drawing::Color::Green;
			 }

			 void setFeedbackFontBlack(array<TextBox ^, 1> ^ &floatTask, int index)	{
				 floatTask[index]->ForeColor = System::Drawing::Color::Black;
				 floatTask[index+1]->ForeColor = System::Drawing::Color::Black;
			 }

			 int endValue(int floatTaskIndex, int start)	{
				 int end;
				 if((floatTaskIndex-start)<20)	{
					 end = floatTaskIndex;
				 }
				 else {
					 end = start + 20;
				 }
				 return end;
			 }


			 int endFloatValue(int sizeOfList, int startFloat)	{
				 int endFloat;
				 if((sizeOfList-startFloat)<12)	{
					 endFloat = sizeOfList;
				 }
				 else
					 endFloat = startFloat + 12;
				 return endFloat;
			 }


			 void feedbackTest(std::string feedback)	{
				 if(feedback != constants->COMPLETED_TASK_MSG)	{
					 label2->Text = gcnew System::String(constants->DESCRIPTION1.c_str());
					 promptBox->Visible = true;
					 promptBox->Font = (gcnew System::Drawing::Font(gcnew System::String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
					 promptBox->Location = System::Drawing::Point(146, 58);
					 promptBox->Multiline = true;
					 promptBox->Size = System::Drawing::Size(690, 20);
				 }	else	{
					 label2->Text = gcnew System::String(constants->DESCRIPTION2.c_str());
				 }
			 }


			 array<TextBox ^, 1> ^ initializeMainArray()	{
				 array<TextBox ^, 1> ^ mainTask = {textBox1, textBox2, textBox3, textBox4, textBox5, textBox6, textBox7, textBox8, textBox9, textBox10, 
					 textBox11, textBox12, textBox13, textBox14, textBox15, textBox16, textBox17, textBox18, textBox19, textBox20,
					 textBox21, textBox22, textBox23, textBox24, textBox25, textBox26, textBox27, textBox28, textBox29, textBox30,
					 textBox31, textBox32, textBox33, textBox34, textBox35, textBox36, textBox37, textBox38, textBox39, textBox40,
					 textBox41, textBox42, textBox43, textBox44, textBox45, textBox46, textBox47, textBox48, textBox49, textBox50,
					 textBox51, textBox52, textBox53, textBox54, textBox55, textBox56, textBox57, textBox58, textBox59, textBox60,
					 textBox61, textBox62, textBox63, textBox64, textBox65, textBox66, textBox67, textBox68, textBox69, textBox70,
					 textBox71, textBox72, textBox73, textBox74, textBox75, textBox76, textBox77, textBox78, textBox79, textBox80, 
					 textBox81, textBox82, textBox83, textBox84, textBox85, textBox86, textBox87, textBox88, textBox89, textBox90,
					 textBox91, textBox92, textBox93, textBox94, textBox95, textBox96, textBox97, textBox98, textBox99, textBox100,
					 textBox101, textBox102, textBox103, textBox104, textBox105, textBox106, textBox107, textBox108, textBox109, textBox110, 
					 textBox111, textBox112, textBox113, textBox114, textBox115, textBox116, textBox117, textBox118, textBox119, textBox120 };
				 return mainTask;
			 }

			 array<TextBox ^,1>^ initializeFloatArray()	{
				 array<TextBox ^,1>^ floatTask = { textBox121, textBox122, textBox123, textBox124, textBox125, textBox126, textBox127, textBox128, textBox129,textBox130,
					 textBox131, textBox132, textBox133, textBox134, textBox135, textBox136, textBox137, textBox138, textBox139, textBox140, 
					 textBox141, textBox142, textBox143, textBox144};
				 return floatTask;
			 }

			 void clearMainArray(array<TextBox ^, 1> ^ &mainTask)	{
				 for(int i=0;i<120;i++)	{
					 mainTask[i]->Clear();
				 }
			 }

			 void clearFloatArray(array<TextBox ^, 1> ^ &floatTask)	{
				 for(int i=0;i<24;i++)	{
					 floatTask[i]->Clear();
				 }
			 }


			 void setFontGreen(array<TextBox ^, 1> ^ &tempArray, int index)	{
				 tempArray[6*index]->ForeColor = System::Drawing::Color::Green;
				 tempArray[(6*index)+1]->ForeColor = System::Drawing::Color::Green;
				 tempArray[(6*index)+2]->ForeColor = System::Drawing::Color::Green;
				 tempArray[(6*index)+3]->ForeColor = System::Drawing::Color::Green;
				 tempArray[(6*index)+4]->ForeColor = System::Drawing::Color::Green;
				 tempArray[(6*index)+5]->ForeColor = System::Drawing::Color::Green;
			 }

			 void setFontGrey(array<TextBox ^, 1> ^ &tempArray, int index)	{
				 tempArray[6*index]->ForeColor = System::Drawing::Color::Gray;
				 tempArray[(6*index)+1]->ForeColor = System::Drawing::Color::Gray;
				 tempArray[(6*index)+2]->ForeColor = System::Drawing::Color::Gray;
				 tempArray[(6*index)+3]->ForeColor = System::Drawing::Color::Gray;
				 tempArray[(6*index)+4]->ForeColor = System::Drawing::Color::Gray;
				 tempArray[(6*index)+5]->ForeColor = System::Drawing::Color::Gray;
			 }

			 void setFontBlack(array<TextBox ^, 1> ^ &tempArray, int index)	{
				 tempArray[6*index]->ForeColor = System::Drawing::Color::Black;
				 tempArray[(6*index)+1]->ForeColor = System::Drawing::Color::Black;
				 tempArray[(6*index)+2]->ForeColor = System::Drawing::Color::Black;
				 tempArray[(6*index)+3]->ForeColor = System::Drawing::Color::Black;
				 tempArray[(6*index)+4]->ForeColor = System::Drawing::Color::Black;
				 tempArray[(6*index)+5]->ForeColor = System::Drawing::Color::Black;
			 }


			 //Directs toggling between pages
			 System::Void inputBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if(e->KeyData == Keys::Down)	 {
					 downArrowKey();
				 }
				 if(e->KeyData == Keys::Up)		 {
					 upArrowKey();
				 }
				 if(e->KeyData == Keys::Right)	 {
					 rightArrowKey();
				 }
				 if(e->KeyData == Keys::Left)	 {
					 leftArrowKey();
				 }
			 }

			 void downArrowKey()	{
				 _countDown++;
				 if(_countDown<_numOfPages) {
					 displayOutput(_countDown*20,0);
					 _countUp++;
				 } else {
					 displayOutput((_numOfPages-1)*20,0);
					 _countDown = _numOfPages-1;
					 _countUp = _numOfPages-1;
				 }
			 }

			 void upArrowKey()	{
				 _countUp--;
				 if(_countUp>=0)	{
					 displayOutput(_countUp*20,0);
					 _countDown--;
				 } else  {
					 displayOutput(0,0);
					 _countUp=-2;
					 _countDown=0;
				 }
			 }

			 void rightArrowKey()	{
				 _countRight++;
				 if(_countRight<_numOfFloatPages) {
					 displayOutput(0,_countRight*12);
					 _countLeft++;
				 } else {
					 displayOutput(0,(_numOfFloatPages-1)*12);
					 _countRight = _numOfFloatPages-1;
					 _countLeft = _numOfFloatPages-1;
				 }
			 }

			 void leftArrowKey()	{
				 _countLeft--;
				 if(_countLeft>=0)	{
					 displayOutput(0,_countLeft*12);
					 _countRight--;
				 }  else {
					 displayOutput(0,0);
					 _countLeft=-2;
					 _countRight=0;
				 }
			 }
	//Directs output to prompt and help box
	private: System::Void inputBox_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if((e->KeyData == Keys::Space) && (_counter==0))	{
					 if(inputBox->Text->Length != 0)	{
						 System::String ^ Input = inputBox->Text;	
						 std::string actualInput = msclr::interop::marshal_as<std::string>(Input);
						 boost::algorithm::to_lower(actualInput);
						 if(actualInput == constants->INPUT_ADD)	{
							 promptAdd();
						 }	else if (actualInput == constants->INPUT_EDIT)	{
							 promptEdit();
						 }	else if (actualInput == constants->INPUT_DELETE)	{
							 promptDelete();
						 }	else if (actualInput == constants->INPUT_SEARCH)	{
							 promptSearch();
						 }	else if (actualInput == constants->INPUT_CHECK)	{
							 promptCheck();
						 }	else if(actualInput == constants->INPUT_UNCHECK)	{
							 promptUncheck();
						 }	else if(actualInput == constants->INPUT_CLEAR)	{
							 promptClear();
						 }	else if(actualInput == constants->INPUT_COMPLETED)	{
							 promptCompleted();
						 }	else if(actualInput == constants->INPUT_UNDO)	{
							 promptUndo();
						 }	else if(actualInput == constants->INPUT_REDO) {
							 promptRedo();
						 }	else if(actualInput == constants->INPUT_HOME)	{
							 promptHome();
						 }	else if(actualInput == constants->INPUT_TODAY) {
							 promptToday();
						 }	else if(actualInput == constants->INPUT_TOMORROW)	{
							 promptTomorrow();
						 }	else {
							 removePrompt();
						 }
					 }
					 Controls->Add(promptBox);
					 _counter++; 
				 }

				 if(e->KeyData == Keys::Back)	{
					 promptBox->Clear();
					 promptBox->Visible = false;
					 _counter = 0;		
				 }

			 }

			 void promptAdd()	{
				 promptBox->Text = gcnew String(constants->PROMPT_ADD.c_str());
				 promptBox->Visible = true;
			 }

			 void promptEdit()	{
				 promptBox->Text = gcnew String(constants->PROMPT_EDIT.c_str());
				 promptBox->Visible = true;
			 }

			 void promptDelete()	{
				 promptBox->Text = gcnew String(constants->PROMPT_DELETE.c_str());
				 promptBox->Visible = true;
			 }

			 void promptSearch()	{
				 promptBox->Text = gcnew String(constants->PROMPT_SEARCH.c_str());
				 promptBox->Visible = true;
			 }

			 void promptCheck()	{
				 promptBox->Text = gcnew String(constants->PROMPT_CHECK.c_str());
				 promptBox->Visible = true;
			 }

			 void promptUncheck()	{
				 promptBox->Text = gcnew String(constants->PROMPT_UNCHECK.c_str());
				 promptBox->Visible = true;
			 }

			 void promptClear()	{
				 promptBox->Text = gcnew String(constants->PROMPT_CLEAR.c_str());
				 promptBox->Visible = true;
			 }

			 void promptCompleted()	{
				 promptBox->Text = gcnew String(constants->PROMPT_COMPLETED.c_str());
				 promptBox->Visible = true;
			 }

			 void promptUndo()	{
				 promptBox->Text = gcnew String(constants->PROMPT_UNDO.c_str());
				 promptBox->Visible = true;
			 }

			 void promptRedo()	{
				 promptBox->Text = gcnew String(constants->PROMPT_REDO.c_str());
				 promptBox->Visible = true;
			 }

			 void promptHome()	{
				 promptBox->Text = gcnew String(constants->PROMPT_HOME.c_str());
				 promptBox->Visible = true;
			 }

			 void promptToday()	{
				 promptBox->Text = gcnew String(constants->PROMPT_TODAY.c_str());
				 promptBox->Visible = true;
			 }

			 void promptTomorrow()	{
				 promptBox->Text = gcnew String(constants->PROMPT_TOMORROW.c_str());
				 promptBox->Visible = true;
			 }

			 void removePrompt()	{
				 promptBox->Clear();	
				 promptBox->Visible = false;
			 }

			 void helpBoxText()	{
				 helpBox->Clear();
				 helpBoxAdd();
				 helpBoxEdit();
				 helpBoxDelete(); 
				 helpBoxSearch();
				 helpBoxStorage();
				 helpBoxCheckUncheck();
				 helpBoxCompleted();
				 helpBoxUndoRedo();
				 helpBoxTdyTmr();		  
			 }

			 void helpBoxAdd()	{
				 helpBox->SelectionFont = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->SelectedText= gcnew String(constants->HELP_MAIN.c_str());
				 helpBox->Font = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->AppendText(gcnew String(constants->HELP_ADD1.c_str()));
				 helpBox->AppendText(gcnew String(constants->HELP_ADD2.c_str()));
				 helpBox->AppendText(gcnew String(constants->HELP_ADD3.c_str()));
			 }

			 void helpBoxEdit()	{
				 helpBox->SelectionFont = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->AppendText(gcnew String(constants->HELP_EDIT1.c_str()));
				 helpBox->Font = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->AppendText(gcnew String(constants->HELP_EDIT2.c_str()));
			 }

			 void helpBoxDelete()	{
				 helpBox->SelectionFont = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->AppendText(gcnew String(constants->HELP_DELETE1.c_str()));
				 helpBox->Font = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->AppendText(gcnew String(constants->HELP_DELETE2.c_str()));
			 }

			 void helpBoxSearch()	{
				 helpBox->SelectionFont = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->AppendText(gcnew String(constants->HELP_SEARCH1.c_str()));
				 helpBox->Font = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->AppendText(gcnew String(constants->HELP_SEARCH2.c_str()));
			 }

			 void helpBoxStorage()	{
				 helpBox->SelectionFont = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->AppendText(gcnew String(constants->HELP_STORAGE1.c_str()));
				 helpBox->Font = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->AppendText(gcnew String(constants->HELP_STORAGE2.c_str()));
				 helpBox->AppendText(gcnew String(constants->HELP_STORAGE3.c_str()));
			 }

			 void helpBoxCheckUncheck()	{
				 helpBox->SelectionFont = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->AppendText(gcnew String(constants->HELP_CHECK1.c_str()));
				 helpBox->Font = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->AppendText(gcnew String(constants->HELP_CHECK2.c_str()));
			 }

			 void helpBoxCompleted()	{
				 helpBox->SelectionFont = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->AppendText(gcnew String(constants->HELP_COMPLETED1.c_str()));
				 helpBox->Font = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->AppendText(gcnew String(constants->HELP_COMPLETED2.c_str()));
			 }

			 void helpBoxUndoRedo()	{
				 helpBox->SelectionFont = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->AppendText(gcnew String(constants->HELP_UNRE1.c_str()));
				 helpBox->Font = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->AppendText(gcnew String(constants->HELP_UNRE2.c_str()));
			 }

			 void helpBoxTdyTmr()	{
				 helpBox->SelectionFont = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->AppendText(gcnew String(constants->HELP_TDYTMR1.c_str()));
				 helpBox->Font = (gcnew System::Drawing::Font(gcnew String(constants->FONT.c_str()), 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 helpBox->AppendText(gcnew String(constants->HELP_TDYTMR2.c_str()));
			 }
};
}