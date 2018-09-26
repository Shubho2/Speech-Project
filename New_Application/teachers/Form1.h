#pragma once
#include "hmm.h"
#include "stdAfx.h"
#include "teacher.h"
#include "addFaculty.h"

namespace teachers {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Diagnostics;
	using namespace System::Threading;
	

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		static int i = 3;
		public:
			Form1(void)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ToolStripMenuItem^  addNewFacultyMemberToolStripMenuItem;
	public: 
	private:
			int done;

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~Form1()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Button^  recordingmodule;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
		private: System::Windows::Forms::MenuStrip^  menuStrip1;
		private: System::Windows::Forms::ToolStripMenuItem^  menuToolStripMenuItem;

		private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;

		private: System::Windows::Forms::Timer^  timer;

		private: System::ComponentModel::IContainer^  components;


		protected: 

		private:
					/// <summary>
		/// Required designer variable.
		/// </summary>



																																																																															#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->recordingmodule = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addNewFacultyMemberToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// recordingmodule
			// 
			this->recordingmodule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->recordingmodule->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->recordingmodule->Location = System::Drawing::Point(193, 261);
			this->recordingmodule->Name = L"recordingmodule";
			this->recordingmodule->Size = System::Drawing::Size(167, 50);
			this->recordingmodule->TabIndex = 0;
			this->recordingmodule->Text = L"Start recording";
			this->recordingmodule->UseVisualStyleBackColor = true;
			this->recordingmodule->Click += gcnew System::EventHandler(this, &Form1::recordingmodule_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->Location = System::Drawing::Point(95, 71);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(393, 31);
			this->label1->TabIndex = 1;
			this->label1->Text = L"CSE Department Faculty Portal";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->menuToolStripMenuItem, 
				this->helpToolStripMenuItem, this->exitToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->menuStrip1->Size = System::Drawing::Size(598, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->addNewFacultyMemberToolStripMenuItem});
			this->menuToolStripMenuItem->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->menuToolStripMenuItem->Text = L"Edit";
			this->menuToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::menuToolStripMenuItem_Click);
			// 
			// addNewFacultyMemberToolStripMenuItem
			// 
			this->addNewFacultyMemberToolStripMenuItem->Name = L"addNewFacultyMemberToolStripMenuItem";
			this->addNewFacultyMemberToolStripMenuItem->Size = System::Drawing::Size(212, 22);
			this->addNewFacultyMemberToolStripMenuItem->Text = L"Add New Faculty member";
			this->addNewFacultyMemberToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::addNewFacultyMemberToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// timer
			// 
			this->timer->Interval = 500;
			this->timer->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(133, 148);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(147, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Say any of these area";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(195, 332);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(165, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Click on start recording to choose";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(297, 151);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(152, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"SYSTEM / THEORY / A.I";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(218, 224);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(112, 17);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Recording starts";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label6->Location = System::Drawing::Point(227, 186);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(94, 17);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Try Again :(";
			this->label6->Visible = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(598, 459);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->recordingmodule);
			this->ForeColor = System::Drawing::Color::White;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(614, 498);
			this->MinimumSize = System::Drawing::Size(614, 498);
			this->Name = L"Form1";
			this->Text = L"CSE FACULTIES";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion

		
		private: System::Void recordingmodule_Click(System::Object^  sender, System::EventArgs^  e) {
			//label1->Text="Start speaking at the end of progress bar";
			timer->Start();
			label5->Visible=true;
		}
		
		private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
					 label5->Visible=false;
				 }
		private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			
		}
		private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void menuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void addToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			
			label5->Text = "Recording starts in : " + i ;
			if(i == -1){

				recordingmodule->Text = "Started...";
				Process^ myProcess = gcnew Process;
				//myProcess->StartInfo->UseShellExecute = false;
				myProcess->StartInfo->FileName = "Recording_Module.exe";
				myProcess->StartInfo->Arguments = "3 test1.wav test1.txt";
				myProcess->StartInfo->CreateNoWindow = true;
			
				myProcess->Start();
				Thread::Sleep(4000);
				myProcess->Kill();
				//label2->Text = "Recording done";
				timer->Stop();
				label5->Visible=false;
				i = 4;
				// calling hmm and detect uttered word
				int para=testing(1);
				// show the detected word and 
				//label1->Text= Convert::ToString(para);
				recordingmodule->Text = "Start Recording";
				comfirmMessage(para);
			}
			i--;
		}

		private:
			void comfirmMessage(int para){
				String^ type;
				if(para==1)
				{
					type="Theory";
				}
				else if(para==2)
				{
					type="System";
				}
				else
				{
					type="A.I";
				}
				if(MessageBox::Show("Are you sure - "+type+" ? ","Confirming",MessageBoxButtons::YesNo,
				 MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes){
					//this->Hide();
					teacher^ f2 = gcnew teacher(para);
					f2->ShowDialog();
				 }
				 else{
					 label6->Visible=true;
				 }
			}

			private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				if(MessageBox::Show("Are you sure ? ","Confirming",MessageBoxButtons::YesNo,
					MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes){
					//Application::Exit();
				}
				else{
					e->Cancel = true;
				}
		 }

private: System::Void addNewFacultyMemberToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 addFaculty^ af = gcnew addFaculty();
			 af->ShowDialog();
		 }
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
		 }
};
}

