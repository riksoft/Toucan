/////////////////////////////////////////////////////////////////////////////////
// Author:      Steven Lamerton
// Copyright:   Copyright (C) 2007 - 2010 Steven Lamerton
// License:     GNU GPL 2 http://www.gnu.org/licenses/gpl-2.0.html
/////////////////////////////////////////////////////////////////////////////////

#ifndef H_SYNCDATA
#define H_SYNCDATA

class frmMain;

#include "jobdata.h"
#include <wx/string.h>

struct SyncChecks{
	bool Size;
	bool Time;
	bool Short;
	bool Full;

	SyncChecks() : Size(true), Time(false), Short(true), Full(false)
	{}
};

struct SyncOptions{
	bool TimeStamps;
	bool Attributes;
	bool IgnoreRO;
	bool Recycle;
	bool PreviewChanges;
	bool NoSkipped;

	SyncOptions() : TimeStamps(true), Attributes(true), IgnoreRO(false), 
					Recycle(false), PreviewChanges(false), NoSkipped(false)
	{}
};

class SyncData : public JobData{

public:
	SyncData(const wxString &name) : JobData(name){
		;
	}

	void TransferToFile();
	void TransferFromFile();
	bool TransferToForm(frmMain *window);
	bool TransferFromForm(frmMain *window);

	void SetSource(const wxFileName& source) {this->source = source;}
	void SetDest(const wxFileName& dest) {this->dest = dest;}
	void SetFunction(const wxString& Function) {this->m_Function = Function;}
	void SetCheckSize(const bool& CheckSize) {this->m_Checks.Size = CheckSize;}
	void SetCheckTime(const bool& CheckTime) {this->m_Checks.Time = CheckTime;}
	void SetCheckShort(const bool& CheckShort) {this->m_Checks.Short = CheckShort;}
	void SetCheckFull(const bool& CheckFull) {this->m_Checks.Full = CheckFull;}
	void SetIgnoreRO(const bool& IgnoreRO) {this->m_Options.IgnoreRO = IgnoreRO;}
	void SetTimeStamps(const bool& TimeStamps) {this->m_Options.TimeStamps = TimeStamps;}
	void SetAttributes(const bool& Attributes) {this->m_Options.Attributes = Attributes;}
	void SetRecycle(const bool& Recycle) {this->m_Options.Recycle = Recycle;}
	void SetPreviewChanges(const bool& Changes) {this->m_Options.PreviewChanges = Changes;}
	void SetNoSkipped(const bool& NoSkipped) {this->m_Options.NoSkipped = NoSkipped;}

	const wxFileName& GetSource() const {return source;}
	const wxFileName& GetDest() const {return dest;}
	const wxString& GetFunction() const {return m_Function;}
	const bool& GetCheckSize() const {return m_Checks.Size;}
	const bool& GetCheckTime() const {return m_Checks.Time;}
	const bool& GetCheckShort() const {return m_Checks.Short;}
	const bool& GetCheckFull() const {return m_Checks.Full;}
	const bool& GetIgnoreRO() const {return m_Options.IgnoreRO;}
	const bool& GetTimeStamps() const {return m_Options.TimeStamps;}
	const bool& GetAttributes() const {return m_Options.Attributes;}
	const bool& GetRecycle() const {return m_Options.Recycle;}
	const bool& GetPreviewChanges() const {return m_Options.PreviewChanges;}
	const bool& GetNoSkipped() const {return m_Options.NoSkipped;}

private:
	wxFileName source;
	wxFileName dest;
	wxString m_Function;
	wxString m_PreText;
	SyncChecks m_Checks;
	SyncOptions m_Options;
};

#endif
