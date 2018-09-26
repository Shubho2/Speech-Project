#pragma once


#include "profile.h"
#include "string"
namespace teachers {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Diagnostics;
	using namespace System::Threading;
	using namespace System::IO;


	/// <summary>
	/// Summary for teacher
	/// </summary>
	public ref class teacher : public System::Windows::Forms::Form {

	
	static int pageCount = 0;
	static int profCount = 0;
	// global data array declaration
	static array<String^>^ prof_names = gcnew array<String^>(50);

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;


	private:
		int domain;

	public:
		teacher(void){
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		teacher(int data){
			domain = data;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~teacher(){
			if (components){
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;





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
		void InitializeComponent(void){
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(232, 60);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(116, 40);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Start Recording";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &teacher::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->Location = System::Drawing::Point(96, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 20);
			this->label1->TabIndex = 6;
			this->label1->Text = L"label1";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(97, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"label2";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label3->Location = System::Drawing::Point(96, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 20);
			this->label3->TabIndex = 8;
			this->label3->Text = L"label3";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label4->Location = System::Drawing::Point(96, 170);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 20);
			this->label4->TabIndex = 9;
			this->label4->Text = L"label4";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label5->Location = System::Drawing::Point(96, 215);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 20);
			this->label5->TabIndex = 10;
			this->label5->Text = L"label5";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(446, 60);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 40);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Next";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &teacher::button2_Click);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(58, 60);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 40);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Back";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &teacher::button3_Click);
			// 
			// panel1
			// 
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->panel1->Location = System::Drawing::Point(106, 143);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(381, 257);
			this->panel1->TabIndex = 13;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(290, 415);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(13, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"1";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label7->Location = System::Drawing::Point(116, 114);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(357, 17);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Say Index to choose professor or Back/Next to navigate";
			// 
			// teacher
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(598, 459);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->MaximumSize = System::Drawing::Size(614, 498);
			this->MinimumSize = System::Drawing::Size(614, 498);
			this->Name = L"teacher";
			this->Text = L"Professsors";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &teacher::teacher_FormClosing);
			this->Load += gcnew System::EventHandler(this, &teacher::teacher_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void teacher_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {}
		 
		private: System::Void teacher_Load(System::Object^  sender, System::EventArgs^  e) {
			String^ path;
			if(domain == 1){
				path = "theory.txt";		 
			}
			else if(domain == 2){
				path = "system.txt";			
			}
			else{
				path = "ai.txt";
			}
	
			StreamReader^ sr = gcnew StreamReader( path );
			int i = 0;
			 while( sr->Peek() >= 0 )
			{

				prof_names[i++] = ( sr->ReadLine() );
				profCount ++;
			}
			 if(profCount <= 5){
				button2->Enabled = false;
			 }
			 if(pageCount == 0){
				button3->Enabled = false;
			 }
			 sr->Close();
			 // call to modify labels
			 profLoad(pageCount,profCount);
   		}
		
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 Process^ myProcess = gcnew Process;
				//myProcess->StartInfo->UseShellExecute = false;
				myProcess->StartInfo->FileName = "Recording_Module.exe";
				myProcess->StartInfo->Arguments = "3 test2.wav test2.txt";
				myProcess->StartInfo->CreateNoWindow = true;
			
				myProcess->Start();
				Thread::Sleep(4000);
				myProcess->Kill();
				//button1->Text = Convert::ToString(domain);
				// show the detected word and
				int para = testing(2);
				comfirmMessage(para);
			 }


		private:
			void comfirmMessage(int para){
				String^ type; 
				
				if(para==6)
				{
				type="Do you want to go Back";
				}
				else if(para==7)
				{
				 type="Do you want to go Next";
				}
				else if(para==8)
				{
				type="Do you want to Exit";
				}
				else
				{
					if(profCount>=pageCount*5+para)
					{
						switch(para)
					{
					case 1: type="Have you said "+prof_names[pageCount*5 + para-1]+" ?";
						break;
					case 2: type="Have you said "+prof_names[pageCount*5 + para-1]+" ?";
						break;
					case 3: type="Have you said "+prof_names[pageCount*5 + para-1]+" ?";
						break;
					case 4: type="Have you said "+prof_names[pageCount*5 + para-1]+" ?";
						break;
					case 5: type="Have you said "+prof_names[pageCount*5 + para-1]+" ?";
						break;
					}
					}
					else
						type="You have said something Wrong";
				}
				
				if(MessageBox::Show(type+" ","Confirming",MessageBoxButtons::YesNo,
				 MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes){
					if(para==7)
					{
						if(profCount >= (pageCount + 1)*5){ // if next clickable check
							pageCount ++;
							label6->Text = Convert::ToString(pageCount+1);
							profLoad(pageCount,profCount);
							if(pageCount > 0){
								button3->Enabled = true;
							}
						}
					}
					else if(para==8)
					{
							Application::Exit();
					}
					else if(para==6)
					{
						if(pageCount > 0){
							pageCount --;
							label6->Text = Convert::ToString(pageCount+1);
							profLoad(pageCount,profCount);
						 }
					}
					else
						{
							if(para+pageCount*5<=profCount){
								//this->Hide();
								para = pageCount*5 + para;
								profile^ pf = gcnew profile(domain,para); // domain and which teacher 
								pf->ShowDialog();
							}
				 
					}
				}
				 else{
					button1->Text = "Try Again !!";
				 }
			}
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(profCount >= (pageCount + 1)*5){ // if next clickable check
					 pageCount ++;
					 label6->Text = Convert::ToString(pageCount+1);
					 profLoad(pageCount,profCount);
					 if(pageCount > 0){
						button3->Enabled = true;
					 }
				 }
				 
			 }
		private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(pageCount > 0){
				pageCount --;
				label6->Text = Convert::ToString(pageCount+1);
				profLoad(pageCount,profCount);
			 }
		 }


		 private:

			void profLoad(int pg, int pr){
				int temp = pr - pg*5;
				if(temp >= 5){
					label1->Text = Convert::ToString("[1]   " + prof_names[pg*5]);
					label2->Text = Convert::ToString("[2]   " + prof_names[pg*5 + 1]);
					label3->Text = Convert::ToString("[3]   " + prof_names[pg*5 + 2]);
					label4->Text = Convert::ToString("[4]   " + prof_names[pg*5 + 3]);
					label5->Text = Convert::ToString("[5]   " + prof_names[pg*5 + 4]);
				}
				else if(temp == 4){
					label1->Text = Convert::ToString("[1]   " + prof_names[pg*5]);
					label2->Text = Convert::ToString("[2]   " + prof_names[pg*5 + 1]);
					label3->Text = Convert::ToString("[3]   " + prof_names[pg*5 + 2]);
					label4->Text = Convert::ToString("[4]   " + prof_names[pg*5 + 3]);
					
					label5->Text = "";
				}
				else if(temp == 3){
					label1->Text = Convert::ToString("[1]   " + prof_names[pg*5]);
					label2->Text = Convert::ToString("[2]   " + prof_names[pg*5 + 1]);
					label3->Text = Convert::ToString("[3]   " + prof_names[pg*5 + 2]);

					label4->Text = "";
					label5->Text = "";
				}
				else if(temp == 2){
				
					label1->Text = Convert::ToString("[1]   " + prof_names[pg*5]);
					label2->Text = Convert::ToString("[2]   " + prof_names[pg*5 + 1]);

					label3->Text = "";
					label4->Text = "";
					label5->Text = "";
				}
				else{
					label1->Text = Convert::ToString("[1]   " + prof_names[pg*5]);
					
					label2->Text = "";
					label3->Text = "";
					label4->Text = "";
					label5->Text = "";
				}							
			}
	};
}
