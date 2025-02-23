#pragma once
#include "AddNewUrlForm.h"
#include "UniversityApi/UniversityApi.h"
#include "UniversityApi/ExportedTypes.h"
#include <map>
#include "ReportForm.h"

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
	private: System::Windows::Forms::DataGridView^ dtGrdDataSummary;





	private: System::Windows::Forms::GroupBox^ grpBoxDataSummary;
	private: System::Windows::Forms::DataGridView^ dtGrdSkillSummary;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ University;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NrCandidates;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ AvgGpa;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Skill;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Count;
	private: System::Windows::Forms::Button^ btnFullReport;








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
			this->dtGrdDataSummary = (gcnew System::Windows::Forms::DataGridView());
			this->University = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NrCandidates = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AvgGpa = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->grpBoxDataSummary = (gcnew System::Windows::Forms::GroupBox());
			this->dtGrdSkillSummary = (gcnew System::Windows::Forms::DataGridView());
			this->Skill = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Count = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnFullReport = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtGrdDataSummary))->BeginInit();
			this->grpBoxDataSummary->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtGrdSkillSummary))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->configToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(703, 24);
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
			// dtGrdDataSummary
			// 
			this->dtGrdDataSummary->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dtGrdDataSummary->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->University,
					this->NrCandidates, this->AvgGpa
			});
			this->dtGrdDataSummary->Location = System::Drawing::Point(24, 19);
			this->dtGrdDataSummary->Name = L"dtGrdDataSummary";
			this->dtGrdDataSummary->Size = System::Drawing::Size(398, 225);
			this->dtGrdDataSummary->TabIndex = 5;
			// 
			// University
			// 
			this->University->HeaderText = L"University";
			this->University->MinimumWidth = 200;
			this->University->Name = L"University";
			this->University->Width = 200;
			// 
			// NrCandidates
			// 
			this->NrCandidates->HeaderText = L"# Candidates";
			this->NrCandidates->MinimumWidth = 50;
			this->NrCandidates->Name = L"NrCandidates";
			this->NrCandidates->Width = 50;
			// 
			// AvgGpa
			// 
			this->AvgGpa->HeaderText = L"Avg. GPA";
			this->AvgGpa->MinimumWidth = 100;
			this->AvgGpa->Name = L"AvgGpa";
			// 
			// grpBoxDataSummary
			// 
			this->grpBoxDataSummary->Controls->Add(this->dtGrdSkillSummary);
			this->grpBoxDataSummary->Controls->Add(this->dtGrdDataSummary);
			this->grpBoxDataSummary->Location = System::Drawing::Point(12, 93);
			this->grpBoxDataSummary->Name = L"grpBoxDataSummary";
			this->grpBoxDataSummary->Size = System::Drawing::Size(654, 412);
			this->grpBoxDataSummary->TabIndex = 7;
			this->grpBoxDataSummary->TabStop = false;
			this->grpBoxDataSummary->Text = L"Data Summary:";
			// 
			// dtGrdSkillSummary
			// 
			this->dtGrdSkillSummary->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dtGrdSkillSummary->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Skill,
					this->Count
			});
			this->dtGrdSkillSummary->Location = System::Drawing::Point(428, 19);
			this->dtGrdSkillSummary->Name = L"dtGrdSkillSummary";
			this->dtGrdSkillSummary->Size = System::Drawing::Size(215, 386);
			this->dtGrdSkillSummary->TabIndex = 6;
			// 
			// Skill
			// 
			this->Skill->HeaderText = L"Skill";
			this->Skill->MinimumWidth = 120;
			this->Skill->Name = L"Skill";
			this->Skill->Width = 120;
			// 
			// Count
			// 
			this->Count->HeaderText = L"Popularity";
			this->Count->MinimumWidth = 50;
			this->Count->Name = L"Count";
			this->Count->Width = 50;
			// 
			// btnFullReport
			// 
			this->btnFullReport->Location = System::Drawing::Point(141, 43);
			this->btnFullReport->Name = L"btnFullReport";
			this->btnFullReport->Size = System::Drawing::Size(134, 35);
			this->btnFullReport->TabIndex = 8;
			this->btnFullReport->Text = L"Full Report";
			this->btnFullReport->UseVisualStyleBackColor = true;
			this->btnFullReport->Click += gcnew System::EventHandler(this, &MainWindow::btnFullReport_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(703, 510);
			this->Controls->Add(this->btnFullReport);
			this->Controls->Add(this->grpBoxDataSummary);
			this->Controls->Add(this->btnDownloadData);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtGrdDataSummary))->EndInit();
			this->grpBoxDataSummary->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtGrdSkillSummary))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {
		// Attach the SortCompare event handler to the DataGridViews
		this->dtGrdDataSummary->SortCompare += gcnew System::Windows::Forms::DataGridViewSortCompareEventHandler(this, &MainWindow::dtGrdDataSummary_SortCompare);
		this->dtGrdSkillSummary->SortCompare += gcnew System::Windows::Forms::DataGridViewSortCompareEventHandler(this, &MainWindow::dtGrdSkillSummary_SortCompare);
	}
	private: System::Void btnAddNewUrl_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void remoteURLsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		AddNewUrlForm^ addUrlWindow = gcnew AddNewUrlForm();
		addUrlWindow->Show(this);
	}
	private: System::Void btnDownloadData_Click(System::Object^ sender, System::EventArgs^ e) {

		try {
			bool error = false;

			std::vector<std::string> urlList;
			GetUrlList(&urlList);
			RootData data;
			for (size_t i = 0; i < urlList.size(); i++)
			{
				if (!ReadDataFromUrl(urlList[i])) {
					error = true;
				}
			}
			UpdateSummaryTables();
			if (error) {
				MessageBox::Show("Some URLs could not be read", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message + "\nFile Corruption error!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void UpdateSummaryTables() {
		RootData data;
		GetData(data);
		dtGrdDataSummary->Rows->Clear();
		auto university = gcnew String(data.candidates[0].university.c_str());
		String^ currentUniversity = nullptr;
		double sumGpa = 0;
		int count = 0;
		std::map<std::string, int> skillPopularity;
		for (size_t i = 0; i < data.candidates.size(); i++)
		{
			currentUniversity = gcnew String(data.candidates[i].university.c_str());
			if (currentUniversity != university) {
				dtGrdDataSummary->Rows->Add(gcnew array<String^> {
					university,
						gcnew String(std::to_string(count).c_str()),
						gcnew String(std::to_string(sumGpa / count).c_str())
				});
				sumGpa = 0;
				count = 0;
				university = currentUniversity;
			}
			count++;
			sumGpa += data.candidates[i].gpa;

			for (size_t j = 0; j < data.candidates[i].skills.size(); j++)
			{
				auto skill = data.candidates[i].skills[j];
				if (skillPopularity.find(skill) == skillPopularity.end()) {
					skillPopularity[skill] = 1;
				}
				else {
					skillPopularity[skill]++;
				}
			}
		}
		dtGrdDataSummary->Rows->Add(gcnew array<String^> {
			university,
				gcnew String(std::to_string(data.candidates.size()).c_str()),
				gcnew String(std::to_string(sumGpa / count).c_str())
		});

		dtGrdSkillSummary->Rows->Clear();
		for (auto it = skillPopularity.begin(); it != skillPopularity.end(); it++)
		{
			dtGrdSkillSummary->Rows->Add(gcnew array<String^> {
				gcnew String(it->first.c_str()),
					gcnew String(std::to_string(it->second).c_str())
			});
		}
		dtGrdSkillSummary->Sort(dtGrdSkillSummary->Columns[1], System::ComponentModel::ListSortDirection::Descending);
	}

	private: System::Void dtGrdDataSummary_SortCompare(System::Object ^ sender, System::Windows::Forms::DataGridViewSortCompareEventArgs ^ e) {
		// Check if the column being sorted is the one with integer values
		if (e->Column->Name == "NrCandidates") {
			int intValue1 = Int32::Parse(e->CellValue1->ToString());
			int intValue2 = Int32::Parse(e->CellValue2->ToString());

			// Compare the integer values
			e->SortResult = intValue1.CompareTo(intValue2);

			// If the values are equal, use the row index to maintain the order
			if (e->SortResult == 0) {
				e->SortResult = e->RowIndex1.CompareTo(e->RowIndex2);
			}

			e->Handled = true; // Indicate that the event is handled
		}
		else if (e->Column->Name == "AvgGpa") {
			float floatValue1 = float::Parse(e->CellValue1->ToString());
			float floatValue2 = float::Parse(e->CellValue2->ToString());

			// Compare the float values
			e->SortResult = floatValue1.CompareTo(floatValue2);

			// If the values are equal, use the row index to maintain the order
			if (e->SortResult == 0) {
				e->SortResult = e->RowIndex1.CompareTo(e->RowIndex2);
			}

			e->Handled = true; // Indicate that the event is handled
		}

	}
	private: System::Void dtGrdSkillSummary_SortCompare(System::Object ^ sender, System::Windows::Forms::DataGridViewSortCompareEventArgs ^ e) {
		// Check if the column being sorted is the one with integer values
		if (e->Column->Name == "Count") {
			int intValue1 = Int32::Parse(e->CellValue1->ToString());
			int intValue2 = Int32::Parse(e->CellValue2->ToString());

			// Compare the integer values
			e->SortResult = intValue1.CompareTo(intValue2);

			// If the values are equal, use the row index to maintain the order
			if (e->SortResult == 0) {
				e->SortResult = e->RowIndex1.CompareTo(e->RowIndex2);
			}

			e->Handled = true; // Indicate that the event is handled
		}
	}
	private: System::Void btnFullReport_Click(System::Object ^ sender, System::EventArgs ^ e) {
		ReportForm^ reportFormWindow = gcnew ReportForm();
		reportFormWindow->Show(this);
	}
	};
	}
