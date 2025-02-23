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
	private: System::Windows::Forms::Label^ lblUniversityFilter;
	private: System::Windows::Forms::ComboBox^ cmbBoxUniversityList;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ lblMinGpa;
	private: System::Windows::Forms::Label^ lblMaxGpa;
	private: System::Windows::Forms::GroupBox^ grpBoxGpaRange;
	private: System::Windows::Forms::GroupBox^ grpBoxFilters;
	private: System::Windows::Forms::Button^ btnApplyFilters;




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
			this->lblUniversityFilter = (gcnew System::Windows::Forms::Label());
			this->cmbBoxUniversityList = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->lblMinGpa = (gcnew System::Windows::Forms::Label());
			this->lblMaxGpa = (gcnew System::Windows::Forms::Label());
			this->grpBoxGpaRange = (gcnew System::Windows::Forms::GroupBox());
			this->grpBoxFilters = (gcnew System::Windows::Forms::GroupBox());
			this->btnApplyFilters = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtGrdMainReport))->BeginInit();
			this->grpBoxGpaRange->SuspendLayout();
			this->grpBoxFilters->SuspendLayout();
			this->SuspendLayout();
			// 
			// dtGrdMainReport
			// 
			this->dtGrdMainReport->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dtGrdMainReport->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Name,
					this->University, this->GPA, this->SkillSet
			});
			this->dtGrdMainReport->Location = System::Drawing::Point(9, 193);
			this->dtGrdMainReport->Name = L"dtGrdMainReport";
			this->dtGrdMainReport->Size = System::Drawing::Size(795, 457);
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
			this->cmbBoxSkillList->Location = System::Drawing::Point(11, 125);
			this->cmbBoxSkillList->Name = L"cmbBoxSkillList";
			this->cmbBoxSkillList->Size = System::Drawing::Size(160, 21);
			this->cmbBoxSkillList->TabIndex = 1;
			// 
			// lblSkillFilter
			// 
			this->lblSkillFilter->AutoSize = true;
			this->lblSkillFilter->Location = System::Drawing::Point(11, 109);
			this->lblSkillFilter->Name = L"lblSkillFilter";
			this->lblSkillFilter->Size = System::Drawing::Size(51, 13);
			this->lblSkillFilter->TabIndex = 2;
			this->lblSkillFilter->Text = L"Skill filter:";
			// 
			// lblUniversityFilter
			// 
			this->lblUniversityFilter->AutoSize = true;
			this->lblUniversityFilter->Location = System::Drawing::Point(176, 109);
			this->lblUniversityFilter->Name = L"lblUniversityFilter";
			this->lblUniversityFilter->Size = System::Drawing::Size(81, 13);
			this->lblUniversityFilter->TabIndex = 4;
			this->lblUniversityFilter->Text = L"University Filter:";
			// 
			// cmbBoxUniversityList
			// 
			this->cmbBoxUniversityList->FormattingEnabled = true;
			this->cmbBoxUniversityList->Location = System::Drawing::Point(176, 125);
			this->cmbBoxUniversityList->Name = L"cmbBoxUniversityList";
			this->cmbBoxUniversityList->Size = System::Drawing::Size(160, 21);
			this->cmbBoxUniversityList->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(205, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(110, 20);
			this->textBox1->TabIndex = 5;
			this->textBox1->Text = L"4";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(39, 19);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(110, 20);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"-4";
			// 
			// lblMinGpa
			// 
			this->lblMinGpa->AutoSize = true;
			this->lblMinGpa->Location = System::Drawing::Point(10, 22);
			this->lblMinGpa->Name = L"lblMinGpa";
			this->lblMinGpa->Size = System::Drawing::Size(27, 13);
			this->lblMinGpa->TabIndex = 7;
			this->lblMinGpa->Text = L"Min:";
			// 
			// lblMaxGpa
			// 
			this->lblMaxGpa->AutoSize = true;
			this->lblMaxGpa->Location = System::Drawing::Point(169, 22);
			this->lblMaxGpa->Name = L"lblMaxGpa";
			this->lblMaxGpa->Size = System::Drawing::Size(30, 13);
			this->lblMaxGpa->TabIndex = 8;
			this->lblMaxGpa->Text = L"Max:";
			// 
			// grpBoxGpaRange
			// 
			this->grpBoxGpaRange->Controls->Add(this->lblMaxGpa);
			this->grpBoxGpaRange->Controls->Add(this->lblMinGpa);
			this->grpBoxGpaRange->Controls->Add(this->textBox2);
			this->grpBoxGpaRange->Controls->Add(this->textBox1);
			this->grpBoxGpaRange->Location = System::Drawing::Point(11, 30);
			this->grpBoxGpaRange->Name = L"grpBoxGpaRange";
			this->grpBoxGpaRange->Size = System::Drawing::Size(322, 59);
			this->grpBoxGpaRange->TabIndex = 10;
			this->grpBoxGpaRange->TabStop = false;
			this->grpBoxGpaRange->Text = L"GPA Range:";
			// 
			// grpBoxFilters
			// 
			this->grpBoxFilters->Controls->Add(this->btnApplyFilters);
			this->grpBoxFilters->Controls->Add(this->grpBoxGpaRange);
			this->grpBoxFilters->Controls->Add(this->lblUniversityFilter);
			this->grpBoxFilters->Controls->Add(this->cmbBoxUniversityList);
			this->grpBoxFilters->Controls->Add(this->lblSkillFilter);
			this->grpBoxFilters->Controls->Add(this->cmbBoxSkillList);
			this->grpBoxFilters->Location = System::Drawing::Point(9, 12);
			this->grpBoxFilters->Name = L"grpBoxFilters";
			this->grpBoxFilters->Size = System::Drawing::Size(516, 175);
			this->grpBoxFilters->TabIndex = 11;
			this->grpBoxFilters->TabStop = false;
			this->grpBoxFilters->Text = L"Filters:";
			// 
			// btnApplyFilters
			// 
			this->btnApplyFilters->Location = System::Drawing::Point(387, 116);
			this->btnApplyFilters->Name = L"btnApplyFilters";
			this->btnApplyFilters->Size = System::Drawing::Size(104, 37);
			this->btnApplyFilters->TabIndex = 11;
			this->btnApplyFilters->Text = L"Apply Filters";
			this->btnApplyFilters->UseVisualStyleBackColor = true;
			// 
			// ReportForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(817, 662);
			this->Controls->Add(this->grpBoxFilters);
			this->Controls->Add(this->dtGrdMainReport);
			this->Name = L"ReportForm";
			this->Text = L"ReportForm";
			this->Load += gcnew System::EventHandler(this, &ReportForm::ReportForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtGrdMainReport))->EndInit();
			this->grpBoxGpaRange->ResumeLayout(false);
			this->grpBoxGpaRange->PerformLayout();
			this->grpBoxFilters->ResumeLayout(false);
			this->grpBoxFilters->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ReportForm_Load(System::Object^ sender, System::EventArgs^ e) {
		std::vector<std::string> skillList;
		GetSkillList(&skillList);
		for (auto it = skillList.begin(); it != skillList.end(); ++it){
			cmbBoxSkillList->Items->Add(gcnew String(it->c_str()));
		}
		std::vector<std::string> universityList;
		GetUniversityList(&universityList);
		for (auto it = universityList.begin(); it != universityList.end(); ++it) {
			cmbBoxUniversityList->Items->Add(gcnew String(it->c_str()));
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
