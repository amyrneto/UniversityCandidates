#pragma once
#include "UniversityApi/ExportedTypes.h"
#include "UniversityApi/UniversityApi.h"

namespace UniversityCandidates {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ReportForm
	/// </summary>
	public ref class ReportForm : public System::Windows::Forms::Form
	{
	public:
		ReportForm(void)
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
		~ReportForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dtGrdMainReport;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ University;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ GPA;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SkillSet;
	private: System::Windows::Forms::ComboBox^ cmbBoxSkillList;
	private: System::Windows::Forms::Label^ lblSkillFilter;

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
			this->dtGrdMainReport = (gcnew System::Windows::Forms::DataGridView());
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->University = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->GPA = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SkillSet = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cmbBoxSkillList = (gcnew System::Windows::Forms::ComboBox());
			this->lblSkillFilter = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtGrdMainReport))->BeginInit();
			this->SuspendLayout();
			// 
			// dtGrdMainReport
			// 
			this->dtGrdMainReport->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dtGrdMainReport->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Name,
					this->University, this->GPA, this->SkillSet
			});
			this->dtGrdMainReport->Location = System::Drawing::Point(12, 141);
			this->dtGrdMainReport->Name = L"dtGrdMainReport";
			this->dtGrdMainReport->Size = System::Drawing::Size(795, 323);
			this->dtGrdMainReport->TabIndex = 0;
			// 
			// Name
			// 
			this->Name->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::ColumnHeader;
			this->Name->HeaderText = L"Name";
			this->Name->MinimumWidth = 250;
			this->Name->Name = L"Name";
			this->Name->Width = 250;
			// 
			// University
			// 
			this->University->HeaderText = L"University";
			this->University->MinimumWidth = 200;
			this->University->Name = L"University";
			this->University->Width = 200;
			// 
			// GPA
			// 
			this->GPA->HeaderText = L"GPA";
			this->GPA->MinimumWidth = 100;
			this->GPA->Name = L"GPA";
			// 
			// SkillSet
			// 
			this->SkillSet->HeaderText = L"Skill Set";
			this->SkillSet->MinimumWidth = 200;
			this->SkillSet->Name = L"SkillSet";
			this->SkillSet->Width = 200;
			// 
			// cmbBoxSkillList
			// 
			this->cmbBoxSkillList->FormattingEnabled = true;
			this->cmbBoxSkillList->Location = System::Drawing::Point(12, 44);
			this->cmbBoxSkillList->Name = L"cmbBoxSkillList";
			this->cmbBoxSkillList->Size = System::Drawing::Size(159, 21);
			this->cmbBoxSkillList->TabIndex = 1;
			// 
			// lblSkillFilter
			// 
			this->lblSkillFilter->AutoSize = true;
			this->lblSkillFilter->Location = System::Drawing::Point(12, 28);
			this->lblSkillFilter->Name = L"lblSkillFilter";
			this->lblSkillFilter->Size = System::Drawing::Size(51, 13);
			this->lblSkillFilter->TabIndex = 2;
			this->lblSkillFilter->Text = L"Skill filter:";
			// 
			// ReportForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(817, 476);
			this->Controls->Add(this->lblSkillFilter);
			this->Controls->Add(this->cmbBoxSkillList);
			this->Controls->Add(this->dtGrdMainReport);
			//this->Name = L"ReportForm"
			this->Text = L"ReportForm";
			this->Load += gcnew System::EventHandler(this, &ReportForm::ReportForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtGrdMainReport))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ReportForm_Load(System::Object^ sender, System::EventArgs^ e) {
		std::vector<std::string> skillList;
		GetSkillList(&skillList);
		for (auto it = skillList.begin(); it != skillList.end(); ++it)
		{
			cmbBoxSkillList->Items->Add(gcnew String(it->c_str()));
		}
		UpdateMainGrid();
	}

	private: System::Void UpdateMainGrid() {
		RootData data;
		GetData(data);
		dtGrdMainReport->Rows->Clear();
		for (size_t i = 0; i < data.candidates.size(); i++)
		{
			std::string skillSet;
			for (size_t j = 0; j < data.candidates[i].skills.size(); j++)
			{
				skillSet += data.candidates[i].skills[j];
				if (j != data.candidates[i].skills.size() - 1)
				{
					skillSet += " | ";
				}
			}
			dtGrdMainReport->Rows->Add(gcnew array<String^> {
				gcnew String(data.candidates[i].name.c_str()),
					gcnew String(data.candidates[i].university.c_str()),
					gcnew String(std::to_string(data.candidates[i].gpa).c_str()),
					gcnew String(skillSet.c_str())
			});
		}
	}
};
}
