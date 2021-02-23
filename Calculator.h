
// Calculator.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'pch.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CCalculatorApp:
// Siehe Calculator.cpp für die Implementierung dieser Klasse
//

class CCalculatorApp : public CWinApp
{
public:
	CCalculatorApp();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CCalculatorApp theApp;
