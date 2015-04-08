#pragma once


#include <msclr\marshal_cppstd.h>
#include "CMLogic.h"
#include "Output.h"
#include <vector>
#include <sstream>

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
	public:
		CMGUI(void)
		{
			InitializeComponent();
			testSample = new CMLogic();
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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  inputBox;
	private: System::Windows::Forms::TextBox^  outputBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->inputBox = (gcnew System::Windows::Forms::TextBox());
			this->outputBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(10, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter command below";
			// 
			// inputBox
			// 
			this->inputBox->Location = System::Drawing::Point(13, 34);
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(779, 20);
			this->inputBox->TabIndex = 1;
			this->inputBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &CMGUI::inputBox_KeyPress);
			// 
			// outputBox
			// 
			this->outputBox->Location = System::Drawing::Point(13, 105);
			this->outputBox->Multiline = true;
			this->outputBox->Name = L"outputBox";
			this->outputBox->Size = System::Drawing::Size(779, 152);
			this->outputBox->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 89);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Description";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(113, 89);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 16);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Start Date";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(207, 89);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(68, 16);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Start Time";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(304, 89);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(62, 16);
			this->label5->TabIndex = 6;
			this->label5->Text = L"End Date";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(398, 89);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(63, 16);
			this->label6->TabIndex = 7;
			this->label6->Text = L"End Time";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(502, 89);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(60, 16);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Category";
			// 
			// CMGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(804, 269);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->inputBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->outputBox);
			this->Name = L"CMGUI";
			this->Text = L"CMGUI";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void inputBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
				 if(e->KeyChar == (char)13) {
					acceptInput();
					displayOutput();
					inputBox->Clear();
					e->Handled = true;
				}
			 }
	void acceptInput()	{
			System::String ^ Input = inputBox->Text;
			//AddInput newInput(Input);
			
			std::string actualInput = msclr::interop::marshal_as<std::string>(Input);
			if(actualInput == "exit")	{
				Application::Exit();
			}
			else
			{
			testSample->ExecuteCommand(actualInput);
			}
		 }

		std::string getData()	{
			Output* obj = testSample->getDisplay();
			std::string Feedback = obj->getFeedback();  //displayFeedback
			std::vector<std::string> Logic = obj->getDisplay();			//displayTask
			std::string s1 = Feedback;
			std::string s2 = "";
			/*if(Feedback.size() > 0)	{
				for(size_t i=0;i<Feedback.size();i++)	{
					s1 = s1+ Feedback[i] + "\r\n";
				}
			}*/
			if(Logic.size() > 0)	{
				for(size_t i=0;i<Logic.size();i++)	{
					s2 = s2 + Logic[i] + "\r\n";
				}
			}
			
			std::ostringstream oss;
			MessageBox::Show(gcnew System::String(s1.c_str()));
			oss << s2;
			std::string output = oss.str();
			return output;
			
		 }
			
	 void displayOutput()	{
			std::string output = getData();
			outputBox->Text = gcnew System::String(output.c_str());
		}

	};
}
