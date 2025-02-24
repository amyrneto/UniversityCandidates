#pragma once
#include "UniversityApi/UniversityApi.h"
#include <msclr/marshal_cppstd.h>

namespace UniversityCandidates
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddNewUrlForm
	/// </summary>
	public ref class AddNewUrlForm : public System::Windows::Forms::Form
	{
	public:
		AddNewUrlForm(void)
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
		~AddNewUrlForm()
		{
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtBoxNewUrl;
	protected:
	private: System::Windows::Forms::Label^ lblNewUrl;
	private: System::Windows::Forms::Button^ btnAddNewUrl;


	private: System::Windows::Forms::Button^ btnRemove;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::TextBox^ txtBoxWeight;
	private: System::Windows::Forms::Label^ lblWeight;
	private: System::Windows::Forms::DataGridView^ dtGrdUrlCollection;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ URL;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Weight;



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
			this->txtBoxNewUrl = (gcnew System::Windows::Forms::TextBox());
			this->lblNewUrl = (gcnew System::Windows::Forms::Label());
			this->btnAddNewUrl = (gcnew System::Windows::Forms::Button());
			this->btnRemove = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->txtBoxWeight = (gcnew System::Windows::Forms::TextBox());
			this->lblWeight = (gcnew System::Windows::Forms::Label());
			this->dtGrdUrlCollection = (gcnew System::Windows::Forms::DataGridView());
			this->URL = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Weight = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtGrdUrlCollection))->BeginInit();
			this->SuspendLayout();
			// 
			// txtBoxNewUrl
			// 
			this->txtBoxNewUrl->Location = System::Drawing::Point(12, 25);
			this->txtBoxNewUrl->Name = L"txtBoxNewUrl";
			this->txtBoxNewUrl->Size = System::Drawing::Size(402, 20);
			this->txtBoxNewUrl->TabIndex = 5;
			// 
			// lblNewUrl
			// 
			this->lblNewUrl->AutoSize = true;
			this->lblNewUrl->Location = System::Drawing::Point(12, 9);
			this->lblNewUrl->Name = L"lblNewUrl";
			this->lblNewUrl->Size = System::Drawing::Size(83, 13);
			this->lblNewUrl->TabIndex = 4;
			this->lblNewUrl->Text = L"Enter new URL:";
			// 
			// btnAddNewUrl
			// 
			this->btnAddNewUrl->Location = System::Drawing::Point(498, 24);
			this->btnAddNewUrl->Name = L"btnAddNewUrl";
			this->btnAddNewUrl->Size = System::Drawing::Size(84, 22);
			this->btnAddNewUrl->TabIndex = 3;
			this->btnAddNewUrl->Text = L"Add";
			this->btnAddNewUrl->UseVisualStyleBackColor = true;
			this->btnAddNewUrl->Click += gcnew System::EventHandler(this, &AddNewUrlForm::btnAddNewUrl_Click);
			// 
			// btnRemove
			// 
			this->btnRemove->Location = System::Drawing::Point(413, 344);
			this->btnRemove->Name = L"btnRemove";
			this->btnRemove->Size = System::Drawing::Size(84, 20);
			this->btnRemove->TabIndex = 7;
			this->btnRemove->Text = L"Remove";
			this->btnRemove->UseVisualStyleBackColor = true;
			this->btnRemove->Click += gcnew System::EventHandler(this, &AddNewUrlForm::btnRemove_Click);
			// 
			// btnClose
			// 
			this->btnClose->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnClose->Location = System::Drawing::Point(503, 344);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(84, 20);
			this->btnClose->TabIndex = 8;
			this->btnClose->Text = L"Ok";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &AddNewUrlForm::btnClose_Click);
			// 
			// txtBoxWeight
			// 
			this->txtBoxWeight->Location = System::Drawing::Point(420, 25);
			this->txtBoxWeight->Name = L"txtBoxWeight";
			this->txtBoxWeight->Size = System::Drawing::Size(72, 20);
			this->txtBoxWeight->TabIndex = 9;
			// 
			// lblWeight
			// 
			this->lblWeight->AutoSize = true;
			this->lblWeight->Location = System::Drawing::Point(417, 9);
			this->lblWeight->Name = L"lblWeight";
			this->lblWeight->Size = System::Drawing::Size(44, 13);
			this->lblWeight->TabIndex = 10;
			this->lblWeight->Text = L"Weight:";
			// 
			// dtGrdUrlCollection
			// 
			this->dtGrdUrlCollection->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dtGrdUrlCollection->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2)
			{
				this->URL,
					this->Weight
			});
			this->dtGrdUrlCollection->Location = System::Drawing::Point(12, 71);
			this->dtGrdUrlCollection->Name = L"dtGrdUrlCollection";
			this->dtGrdUrlCollection->Size = System::Drawing::Size(549, 267);
			this->dtGrdUrlCollection->TabIndex = 11;
			// 
			// URL
			// 
			this->URL->HeaderText = L"URL";
			this->URL->MinimumWidth = 450;
			this->URL->Name = L"URL";
			this->URL->Width = 450;
			// 
			// Weight
			// 
			this->Weight->HeaderText = L"Weight";
			this->Weight->MinimumWidth = 50;
			this->Weight->Name = L"Weight";
			this->Weight->Width = 50;
			// 
			// AddNewUrlForm
			// 
			this->AcceptButton = this->btnAddNewUrl;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btnClose;
			this->ClientSize = System::Drawing::Size(599, 376);
			this->Controls->Add(this->dtGrdUrlCollection);
			this->Controls->Add(this->lblWeight);
			this->Controls->Add(this->txtBoxWeight);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnRemove);
			this->Controls->Add(this->txtBoxNewUrl);
			this->Controls->Add(this->lblNewUrl);
			this->Controls->Add(this->btnAddNewUrl);
			this->Name = L"AddNewUrlForm";
			this->Text = L"AddNewUrlForm";
			this->Load += gcnew System::EventHandler(this, &AddNewUrlForm::AddNewUrlForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dtGrdUrlCollection))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
    private: System::Void btnAddNewUrl_Click(System::Object^ sender, System::EventArgs^ e)
    {
					try {
						String^ newUrl = txtBoxNewUrl->Text;
						float weight;
						if (!float::TryParse(txtBoxWeight->Text, weight)) {
							MessageBox::Show("Please enter a valid weight", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
							return;
						}
						if (newUrl->Length == 0) {
							MessageBox::Show("Please enter a valid URL", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
							return;
						}
						dtGrdUrlCollection->Rows->Add(newUrl, weight);
						txtBoxNewUrl->Text = "";
						txtBoxWeight->Text = "";
						AddUrl(msclr::interop::marshal_as<std::string>(newUrl), weight);
					}
					catch (Exception^ ex) {
						MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
    }
	private: System::Void btnRemove_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try {
			if (dtGrdUrlCollection->SelectedRows->Count == 0) {
				MessageBox::Show("Please select an item to remove", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			std::string url = msclr::interop::marshal_as<std::string>(dtGrdUrlCollection->SelectedRows[0]->Cells[0]->Value->ToString());
			RemoveUrl(url);
			dtGrdUrlCollection->Rows->Remove(dtGrdUrlCollection->SelectedRows[0]);
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}

	private: System::Void AddNewUrlForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		std::vector<std::string> urlList;
		std::vector<float> weightList;
		GetUrlList(&urlList);
		GetWeightList(&weightList);
		dtGrdUrlCollection->Rows->Clear();
		for (size_t i = 0; i < urlList.size(); i++) {
			dtGrdUrlCollection->Rows->Add(gcnew String(urlList[i].c_str()), weightList[i].ToString());
		}
	}
	};
}
