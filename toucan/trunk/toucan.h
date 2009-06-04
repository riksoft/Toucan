/////////////////////////////////////////////////////////////////////////////////
// Author:      Steven Lamerton
// Copyright:   Copyright (C) 2006-2009 Steven Lamerton
// License:     GNU GPL 2 (See readme for more info)
/////////////////////////////////////////////////////////////////////////////////

#ifndef _TOUCAN_H_
#define _TOUCAN_H_

#include <wx/wx.h>

class frmMain;
class frmProgress;
class Settings;
class ScriptManager;
class wxFileConfig;
class wxHtmlHelpController;

class Toucan: public wxApp{    

public:
	//Start and end
	virtual bool OnInit();
	virtual int OnExit();

	void SetLanguage(wxString langcode);

	void SetAbort(const bool& Abort) {this->m_Abort = Abort;}
	void SetUsesGUI(const bool& UsesGUI) {this->m_UsesGUI = UsesGUI;}
	const bool& GetAbort() const {return m_Abort;}
	const wxString& GetSettingsPath() const {return m_SettingsPath;}
	const wxString& GetResourcesPath() const {return m_ResourcesPath;}
	const bool& GetUsesGUI() const {return m_UsesGUI;}

	//The two persistant forms
	frmMain* MainWindow;
	frmProgress* ProgressWindow;
	//Settings
	Settings* m_Settings;
	//Locale
	wxLocale* m_Locale;	
	//Script manager
	ScriptManager* m_Script;

	//Config
	wxFileConfig* m_Jobs_Config;
	wxFileConfig* m_Rules_Config;
	wxFileConfig* m_Scripts_Config;
	wxFileConfig* m_Variables_Config;

	//Help Controller
	wxHtmlHelpController* m_Help;

private:
	//Clean up the temporary files that might be in the data folder
	void CleanTemp();
	//Setup the directories
	bool SetPaths();

	bool m_Abort;
	wxString m_SettingsPath;
	wxString m_ResourcesPath;
	bool m_UsesGUI;
};

DECLARE_APP(Toucan)

#endif
