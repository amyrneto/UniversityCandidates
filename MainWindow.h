#pragma once
#include "AddNewUrlForm.h"
#include "UniversityApi/UniversityApi.h"

namespace UniversityCandidates {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ configToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ remoteURLsToolStripMenuItem;
	private: System::Windows::Forms::Button^ btnDownloadData;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ University;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NrCandidates;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ AvgGpa;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::GroupBox^ grpBoxDataSummary;




	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->configToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->remoteURLsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnDownloadData = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->University = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NrCandidates = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AvgGpa = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->grpBoxDataSummary = (gcnew System::Windows::Forms::GroupBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->grpBoxDataSummary->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->configToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(738, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// configToolStripMenuItem
			// 
			this->configToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->remoteURLsToolStripMenuItem });
			this->configToolStripMenuItem->Name = L"configToolStripMenuItem";
			this->configToolStripMenuItem->Size = System::Drawing::Size(55, 20);
			this->configToolStripMenuItem->Text = L"Config";
			// 
			// remoteURLsToolStripMenuItem
			// 
			this->remoteURLsToolStripMenuItem->Name = L"remoteURLsToolStripMenuItem";
			this->remoteURLsToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->remoteURLsToolStripMenuItem->Text = L"Remote URLs";
			this->remoteURLsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::remoteURLsToolStripMenuItem_Click);
			// 
			// btnDownloadData
			// 
			this->btnDownloadData->Location = System::Drawing::Point(12, 43);
			this->btnDownloadData->Name = L"btnDownloadData";
			this->btnDownloadData->Size = System::Drawing::Size(122, 35);
			this->btnDownloadData->TabIndex = 4;
			this->btnDownloadData->Text = L"Download Data";
			this->btnDownloadData->UseVisualStyleBackColor = true;
			this->btnDownloadData->Click += gcnew System::EventHandler(this, &MainWindow::btnDownloadData_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->University,
					this->NrCandidates, this->AvgGpa
			});
			this->dataGridView1->Location = System::Drawing::Point(24, 19);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(343, 225);
			this->dataGridView1->TabIndex = 5;
			// 
			// University
			// 
			this->University->HeaderText = L"University";
			this->University->Name = L"University";
			// 
			// NrCandidates
			// 
			this->NrCandidates->HeaderText = L"# Candidates";
			this->NrCandidates->Name = L"NrCandidates";
			// 
			// AvgGpa
			// 
			this->AvgGpa->HeaderText = L"Avg. GPA";
			this->AvgGpa->Name = L"AvgGpa";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(374, 19);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(164, 225);
			this->listBox1->TabIndex = 6;
			// 
			// grpBoxDataSummary
			// 
			this->grpBoxDataSummary->Controls->Add(this->listBox1);
			this->grpBoxDataSummary->Controls->Add(this->dataGridView1);
			this->grpBoxDataSummary->Location = System::Drawing::Point(12, 93);
			this->grpBoxDataSummary->Name = L"grpBoxDataSummary";
			this->grpBoxDataSummary->Size = System::Drawing::Size(572, 254);
			this->grpBoxDataSummary->TabIndex = 7;
			this->grpBoxDataSummary->TabStop = false;
			this->grpBoxDataSummary->Text = L"Data Summary:";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(738, 571);
			this->Controls->Add(this->grpBoxDataSummary);
			this->Controls->Add(this->btnDownloadData);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->grpBoxDataSummary->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnAddNewUrl_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void remoteURLsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		AddNewUrlForm^ addUrlWindow = gcnew AddNewUrlForm();
		addUrlWindow->Show(this);
	}
	private: System::Void btnDownloadData_Click(System::Object^ sender, System::EventArgs^ e) {
		std::vector<std::string> urlList;
		GetUrlList(&urlList);
		for (size_t i = 0; i < urlList.size(); i++)
		{
			ReadDataFromUrl(urlList[i]);
		}
	}
};
}
