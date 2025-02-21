#pragma once
#include "AddNewUrlForm.h"

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
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->configToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(823, 24);
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
			this->remoteURLsToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->remoteURLsToolStripMenuItem->Text = L"Remote URLs";
			this->remoteURLsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::remoteURLsToolStripMenuItem_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(823, 571);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
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
    public: System::Void AddUrl(System::Windows::Forms::ListBox::ObjectCollection^ items) {
        auto str = items[0]; // Example usage, modify as needed
    }
	};
}
