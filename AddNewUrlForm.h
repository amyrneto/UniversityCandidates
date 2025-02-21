#pragma once
namespace UniversityCandidates {

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
            //MainWindow^ mainWindow = dynamic_cast<MainWindow^>(this->Owner);
            //if (mainWindow != nullptr) {
            //    mainWindow->AddUrl(lstBoxUrlCollection->Items);
            //}
            if (components)
            {
                delete components;
            }
        }
	private: System::Windows::Forms::TextBox^ txtBoxNewUrl;
	protected:
	private: System::Windows::Forms::Label^ lblNewUrl;
	private: System::Windows::Forms::Button^ btnAddNewUrl;
	private: System::Windows::Forms::ListBox^ lstBoxUrlCollection;

	private: System::Windows::Forms::Button^ btnRemove;
	private: System::Windows::Forms::Button^ btnClose;

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
			this->txtBoxNewUrl = (gcnew System::Windows::Forms::TextBox());
			this->lblNewUrl = (gcnew System::Windows::Forms::Label());
			this->btnAddNewUrl = (gcnew System::Windows::Forms::Button());
			this->lstBoxUrlCollection = (gcnew System::Windows::Forms::ListBox());
			this->btnRemove = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtBoxNewUrl
			// 
			this->txtBoxNewUrl->Location = System::Drawing::Point(12, 25);
			this->txtBoxNewUrl->Name = L"txtBoxNewUrl";
			this->txtBoxNewUrl->Size = System::Drawing::Size(485, 20);
			this->txtBoxNewUrl->TabIndex = 5;
			this->txtBoxNewUrl->Text = L"Enter Url";
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
			this->btnAddNewUrl->Location = System::Drawing::Point(503, 24);
			this->btnAddNewUrl->Name = L"btnAddNewUrl";
			this->btnAddNewUrl->Size = System::Drawing::Size(84, 20);
			this->btnAddNewUrl->TabIndex = 3;
			this->btnAddNewUrl->Text = L"Add";
			this->btnAddNewUrl->UseVisualStyleBackColor = true;
			this->btnAddNewUrl->Click += gcnew System::EventHandler(this, &AddNewUrlForm::btnAddNewUrl_Click);
			// 
			// lstBoxUrlCollection
			// 
			this->lstBoxUrlCollection->FormattingEnabled = true;
			this->lstBoxUrlCollection->Items->AddRange(gcnew cli::array< System::Object^  >(1) {
				L"https://chromium-case-study.s3.us-east-1.amazonaws.com/candidate+feeds/University"
					L"-of-Havana.json"
			});
			this->lstBoxUrlCollection->Location = System::Drawing::Point(12, 51);
			this->lstBoxUrlCollection->Name = L"lstBoxUrlCollection";
			this->lstBoxUrlCollection->Size = System::Drawing::Size(575, 225);
			this->lstBoxUrlCollection->TabIndex = 6;
			// 
			// btnRemove
			// 
			this->btnRemove->Location = System::Drawing::Point(413, 302);
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
			this->btnClose->Location = System::Drawing::Point(503, 302);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(84, 20);
			this->btnClose->TabIndex = 8;
			this->btnClose->Text = L"Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &AddNewUrlForm::btnClose_Click);
			// 
			// AddNewUrlForm
			// 
			this->AcceptButton = this->btnAddNewUrl;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btnClose;
			this->ClientSize = System::Drawing::Size(599, 334);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnRemove);
			this->Controls->Add(this->lstBoxUrlCollection);
			this->Controls->Add(this->txtBoxNewUrl);
			this->Controls->Add(this->lblNewUrl);
			this->Controls->Add(this->btnAddNewUrl);
			this->Name = L"AddNewUrlForm";
			this->Text = L"AddNewUrlForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnAddNewUrl_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ newUrl = txtBoxNewUrl->Text;
			if (newUrl->Length == 0) {
				MessageBox::Show("Please enter a valid URL", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			lstBoxUrlCollection->Items->Add(newUrl);
			txtBoxNewUrl->Text = "";
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
private: System::Void btnRemove_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		if (lstBoxUrlCollection->SelectedIndex == -1) {
			MessageBox::Show("Please select an item to remove", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		lstBoxUrlCollection->Items->RemoveAt(lstBoxUrlCollection->SelectedIndex);
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
