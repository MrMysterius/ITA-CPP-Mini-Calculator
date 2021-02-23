
// CalculatorDlg.h: Headerdatei
//

#pragma once


// CCalculatorDlg-Dialogfeld
class CCalculatorDlg : public CDialogEx
{
// Konstruktion
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// Standardkonstruktor

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung


// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	float V_Zahl1;
//	flaot V_Zahl1;
	float V_Zahl2;
	float V_Zahl1;
	CString V_Operator;
//	CString V_Output;
	afx_msg void OnBnClickedOplus();
	float V_Output;
	afx_msg void OnBnClickedOminus();
	afx_msg void OnBnClickedOmal();
	afx_msg void OnBnClickedOgeteilt();
};
