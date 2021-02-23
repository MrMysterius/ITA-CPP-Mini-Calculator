
// CalculatorDlg.cpp: Implementierungsdatei
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg-Dialogfeld



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, V_Operator(_T(""))
	, V_Zahl1(0)
	, V_Zahl2(0)
	, V_Output(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, T_Output, V_Output);
	//  DDX_Text(pDX, B_Zahl1, V_Zahl1);
	//  DDX_Text(pDX, B_Zahl1, V_Zahl1);
	//  DDX_Text(pDX, B_Zahl2, V_Zahl2);
	DDX_Text(pDX, T_Operator, V_Operator);
	DDX_Text(pDX, B_Zahl2, V_Zahl2);
	DDX_Text(pDX, B_Zahl1, V_Zahl1);
	//  DDX_Text(pDX, B_Zahl2, V_Zahl1);
	DDX_Text(pDX, B_Zahl2, V_Zahl2);
	DDX_Text(pDX, B_Zahl1, V_Zahl1);
	DDX_Text(pDX, T_Operator, V_Operator);
	DDX_Text(pDX, T_Output, V_Output);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(B_OPlus, &CCalculatorDlg::OnBnClickedOplus)
	ON_BN_CLICKED(B_OPlus, &CCalculatorDlg::OnBnClickedOplus)
	ON_BN_CLICKED(B_OMinus, &CCalculatorDlg::OnBnClickedOminus)
	ON_BN_CLICKED(B_OMal, &CCalculatorDlg::OnBnClickedOmal)
	ON_BN_CLICKED(B_OGeteilt, &CCalculatorDlg::OnBnClickedOgeteilt)
END_MESSAGE_MAP()


// CCalculatorDlg-Meldungshandler

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol für dieses Dialogfeld festlegen.  Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// TODO: Hier zusätzliche Initialisierung einfügen

	return TRUE;  // TRUE zurückgeben, wenn der Fokus nicht auf ein Steuerelement gesetzt wird
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Wenn Sie dem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie
//  den nachstehenden Code, um das Symbol zu zeichnen.  Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch ausgeführt.

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext zum Zeichnen

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Die System ruft diese Funktion auf, um den Cursor abzufragen, der angezeigt wird, während der Benutzer
//  das minimierte Fenster mit der Maus zieht.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnBnClickedOplus()
{
	UpdateData(1);
	float out = V_Zahl1 + V_Zahl2;
	V_Operator = "+";
	V_Output = out;
	UpdateData(0);
}


void CCalculatorDlg::OnBnClickedOminus()
{
	UpdateData(1);
	float out = V_Zahl1 - V_Zahl2;
	V_Operator = "-";
	V_Output = out;
	UpdateData(0);
}


void CCalculatorDlg::OnBnClickedOmal()
{
	UpdateData(1);
	float out = V_Zahl1 * V_Zahl2;
	V_Operator = "*";
	V_Output = out;
	UpdateData(0);
}


void CCalculatorDlg::OnBnClickedOgeteilt()
{
	UpdateData(1);
	float out = V_Zahl1 / V_Zahl2;
	V_Operator = "/";
	V_Output = out;
	UpdateData(0);
}
