// BIJDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BIJ.h"
#include "Reg.h"
#include "BIJDlg.h"
#include "DataFile.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



static UINT BASED_CODE indicators[] =
{
    ID_INDICATOR_NISH,
    ID_INDICATOR_TIME
};


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBIJDlg dialog

CBIJDlg::CBIJDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBIJDlg::IDD, pParent), m_cListCtrl(COLUMNS_m_cListCtrl)
{
	//{{AFX_DATA_INIT(CBIJDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBIJDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBIJDlg)
	DDX_Control(pDX, IDC_BUTTON15, m_btn_update);
	DDX_Control(pDX, IDC_EDIT3, m_edt_PlayerCards);
	DDX_Control(pDX, IDC_EDIT2, m_edt_DealerCards);
	DDX_Control(pDX, IDC_EDIT1, m_edt_LostHand);
	DDX_Control(pDX, IDC_CHECK1, m_chk_push);
	DDX_Control(pDX, IDC_COMBO1, m_cbo_CasinoName);
	DDX_Control(pDX, IDC_CANCELREC, m_CancelRec);
	DDX_Control(pDX, IDC_PUSH, m_Push);
	DDX_Control(pDX, IDC_PLAYERWINS, m_PlayerWins);
	DDX_Control(pDX, IDC_PLAYERBJ, m_PlayerBJ);
	DDX_Control(pDX, IDC_DEALERWINS, m_DealerWins);
	DDX_Control(pDX, IDC_DEALERBJ, m_DealerBJ);
	DDX_Control(pDX, IDC_LIST_CTRL, m_cListCtrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBIJDlg, CDialog)
	//{{AFX_MSG_MAP(CBIJDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()
	ON_WM_PAINT()
    ON_NOTIFY_EX( TTN_NEEDTEXT, 0, OnToolTipText )
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DEALERBJ, OnDealerbj)
	ON_BN_CLICKED(IDC_DEALERWINS, OnDealerwins)
	ON_BN_CLICKED(IDC_PLAYERWINS, OnPlayerwins)
	ON_BN_CLICKED(IDC_PLAYERBJ, OnPlayerbj)
	ON_BN_CLICKED(IDC_PUSH, OnPush)
	ON_BN_CLICKED(IDC_CANCELREC, OnCancelrec)
	ON_BN_CLICKED(IDC_SAVEAS, OnSaveas)
	ON_BN_CLICKED(IDC_OPENREC, OnOpenrec)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_WM_TIMER()
	ON_COMMAND(ID_MENU_NEW, OnMenuNew)
	ON_COMMAND(ID_MENU_OPEN, OnMenuOpen)
	ON_COMMAND(ID_MENU_SAVE, OnMenuSave)
	ON_COMMAND(ID_MENU_SAVEAS, OnMenuSaveas)
	ON_COMMAND(ID_MENU_EXIT, OnMenuExit)
	ON_COMMAND(ID_MENU_ABOUT, OnMenuAbout)
	ON_COMMAND(ID_MENU_HELP, OnMenuHelp)
	ON_WM_SIZE()
	ON_COMMAND(ID_BUTTON32779, OnButton32779)
	ON_COMMAND(ID_BUTTON32780, OnButton32780)
	ON_COMMAND(ID_BUTTON32781, OnButton32781)
	ON_COMMAND(ID_BUTTON32782, OnButton32782)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_EN_SETFOCUS(IDC_EDIT2, OnSetfocusEdit2)
	ON_EN_SETFOCUS(IDC_EDIT3, OnSetfocusEdit3)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	ON_BN_CLICKED(IDC_BUTTON14, OnButton14)
	ON_EN_SETFOCUS(IDC_EDIT1, OnSetfocusEdit1)
	ON_CBN_SETFOCUS(IDC_COMBO1, OnSetfocusCombo1)
	ON_BN_CLICKED(IDC_BUTTON15, OnButton15)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CTRL, OnClickListCtrl)
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_MENU_REG, OnMenuReg)
	//}}AFX_MSG_MAP


END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBIJDlg message handlers

BOOL CBIJDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	m_menu.LoadMenu(IDR_MENUBJ);
	SetMenu(&m_menu);


	if (!m_wndtoolbar.CreateEx( this,TBSTYLE_FLAT ,  WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS,
		CRect(4,4,0,0)) || !m_wndtoolbar.LoadToolBar(IDR_TOOLBARBJ) )
	{
		TRACE0("failed to create toolbar\n");
		return FALSE;
	}
	m_wndtoolbar.ShowWindow(SW_SHOW);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);






	m_bar.Create(this); //We create the status bar

	m_bar.SetIndicators(indicators,6); //Set the number of panes 

	CRect rect;
	GetClientRect(&rect);
	//Size the 6 panes
	m_bar.SetPaneInfo(0,ID_INDICATOR_NISH, SBPS_STRETCH, rect.Width()-450);      
	//m_bar.SetPaneInfo(0,ID_INDICATOR_NISH, SBPS_STRETCH, rect.Width()-355);      
	m_bar.SetPaneInfo(1,ID_INDICATOR_TOTALHANDS, SBPS_STRETCH, 0);
	m_bar.SetPaneInfo(2,ID_INDICATOR_PLAYERWINS, SBPS_STRETCH, 0);
	m_bar.SetPaneInfo(3,ID_INDICATOR_PLAYERRBJ, SBPS_STRETCH, 0);
	m_bar.SetPaneInfo(4,ID_INDICATOR_PUSHHANDS, SBPS_STRETCH, 0);
	m_bar.SetPaneInfo(5,ID_INDICATOR_TIME, SBPS_STRETCH, 0);

	//This is where we actually draw it on the screen
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST, ID_INDICATOR_TOTALHANDS);

    m_bar.SetPaneText(1, "TH: ");
    m_bar.SetPaneText(2, "PW: ");
    m_bar.SetPaneText(3, "DW: ");
    m_bar.SetPaneText(4, "PU: ");

	SetTimer(100,1000,NULL);


	//lance resize the dialog using CDlgAnchro and CDlgMan, but need to set the dialog style to "resizing"

	HWND hwndDlg;
	hwndDlg= this->m_hWnd;

    dlgAnchor.Init(hwndDlg);

	dlgAnchor.Add(IDOK, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDCANCEL, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_OPENREC, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_SAVE, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_SAVEAS, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDCANCEL, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(ID_HELP, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_DEALERWINS, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_DEALERBJ, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_PLAYERWINS, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_PLAYERBJ, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_PUSH, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_CANCELREC, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(m_bar, ANCHOR_BOTTOMLEFT | ANCHOR_RIGHT);
	dlgAnchor.Add(IDC_LIST_CTRL, ANCHOR_TOPLEFT | ANCHOR_BOTTOMRIGHT);
	dlgAnchor.Add(IDC_STATIC1, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_STATIC2, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_STATIC3, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_STATIC4, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_STATIC5, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_STATIC6, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_STATIC7, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_EDIT1, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_EDIT2, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_EDIT3, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_COMBO1, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_CHECK1, ANCHOR_TOPRIGHT);

	dlgAnchor.Add(IDC_BUTTON1, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_BUTTON2, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_BUTTON3, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_BUTTON4, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_BUTTON5, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_BUTTON6, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_BUTTON7, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_BUTTON8, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_BUTTON9, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_BUTTON10, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_BUTTON11, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_BUTTON12, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_BUTTON13, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_BUTTON14, ANCHOR_TOPRIGHT);
	dlgAnchor.Add(IDC_BUTTON15, ANCHOR_TOPRIGHT);


	dlgMan.Load(hwndDlg, "");
	dlgAnchor.OnSize();


	IsDirty=FALSE;




	//set color
	DealerWinColor=10;
	PlayerWinColor=8;
	PushColor=12;
	NonBJColor=13;

	//color button not allow color selection page come out after the click
	m_CancelRec.SetAllowChange(FALSE);
	m_Push.SetAllowChange(FALSE);
	m_PlayerWins.SetAllowChange(FALSE);
	m_PlayerBJ.SetAllowChange(FALSE);
	m_DealerWins.SetAllowChange(FALSE);
	m_DealerBJ.SetAllowChange(FALSE);
	
	//set the color button's color
	m_CancelRec.SetColor(GetColorRef(ITEM_COLOR(DEF_BACKGROUND)));
	m_Push.SetColor(GetColorRef(ITEM_COLOR(PushColor)));
	m_PlayerWins.SetColor(GetColorRef(ITEM_COLOR(PlayerWinColor)));
	m_PlayerBJ.SetColor(GetColorRef(ITEM_COLOR(PlayerWinColor)));
	m_DealerWins.SetColor(GetColorRef(ITEM_COLOR(DealerWinColor)));
	m_DealerBJ.SetColor(GetColorRef(ITEM_COLOR(DealerWinColor)));


	mCurrentFile = ""; // there is no data file loaded or saved, 
	//when the file is loaded, then the save button is valid

	/*
    CStringArray Head;
    CByteArray   Cols;
    Head.Add("WINNER");
    Cols.Add(25);       //40%
    Head.Add("BLACKJACK");
    Cols.Add(25);       //70%
    Head.Add("TIME");
    Cols.Add(50);       //100%
    m_cListCtrl.InitCtrl(&Head, &Cols);
	*/

	//remember to change the COLUMNS_m_cListCtrl if want to change the cols number
    CStringArray Head;
    CByteArray   Cols;
    Head.Add("WINNER");
    Cols.Add(18);       //40%
    Head.Add("BLACKJACK");
    Cols.Add(18);       //70%
	Head.Add("D CARDS");
    Cols.Add(22);       //100%
    Head.Add("P CARDS");
    Cols.Add(22);       //100%
    Head.Add("No.");
    Cols.Add(12);       //100%
    Head.Add("TIME");
    Cols.Add(8);       //100%
	m_cListCtrl.InitCtrl(&Head, &Cols);



    m_cListCtrl.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, (LPARAM)LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_FLATSB); 

//	CKillProcess mKillProcess;
//	mKillProcess.KillProcess("Casino.exe");

	//init the controls for the killing a casino software
	m_chk_push.SetCheck(1);
    m_cbo_CasinoName.AddString ( "Casino.exe" );
    m_cbo_CasinoName.AddString ( "CasinoOnNet.exe" );
    m_cbo_CasinoName.AddString ( "reef.exe" );
    m_cbo_CasinoName.AddString ( "PlanetluckCasin" );
    m_cbo_CasinoName.AddString ( "StarluckCasino." );
	m_cbo_CasinoName.SetCurSel (0);


	m_edt_LostHand.SetLimitText(3);
	m_edt_LostHand.SetWindowText("999");
	m_KillCounter = 0;

	CString strBuffer;
	strBuffer = "AKQJT98765432akqjt";
	m_edt_DealerCards.SetLegal(strBuffer);
	m_edt_PlayerCards.SetLegal(strBuffer);
	m_Focus = NoFocus;

	m_nSelected = 0; //which row of the listcontrol is selected after been clicked

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBIJDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal(); 
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CBIJDlg::OnDestroy()
{

	dlgMan.Save();
	WinHelp(0L, HELP_QUIT);
	CDialog::OnDestroy();
	


}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBIJDlg::OnPaint() 
{

	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBIJDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



void CBIJDlg::OnDealerbj() 
{
	// TODO: Add your control notification handler code here
	    //insert new item

	CString strTime;
	strTime.Format(_T("%s"), COleDateTime::GetCurrentTime().Format(_T("%H:%M:%S %m/%d/%Y")));
	InsertVector(DealerBJ, strTime);
	InsertListCtrl(DealerBJ, strTime);
	CalcWinRate();
	m_KillCounter = m_KillCounter + 1;
	KillGameProcess();
	m_edt_PlayerCards.SetFocus();

}



void CBIJDlg::OnDealerwins() 
{
	// TODO: Add your control notification handler code here

	CString strTime;
	strTime.Format(_T("%s"), COleDateTime::GetCurrentTime().Format(_T("%H:%M:%S %m/%d/%Y")));
	InsertVector(DealerWins, strTime);
	InsertListCtrl(DealerWins, strTime);
	CalcWinRate();
	m_KillCounter = m_KillCounter + 1;
	KillGameProcess();
	m_edt_PlayerCards.SetFocus();

}


void CBIJDlg::OnPlayerwins() 
{
	// TODO: Add your control notification handler code here
	CString strTime;
	strTime.Format(_T("%s"), COleDateTime::GetCurrentTime().Format(_T("%H:%M:%S %m/%d/%Y")));
	InsertVector(PlayerWins, strTime);
	InsertListCtrl(PlayerWins, strTime);
	CalcWinRate();
	m_KillCounter = 0;
	m_edt_PlayerCards.SetFocus();

}

void CBIJDlg::OnPlayerbj() 
{
	// TODO: Add your control notification handler code here
	CString strTime;
	strTime.Format(_T("%s"), COleDateTime::GetCurrentTime().Format(_T("%H:%M:%S %m/%d/%Y")));
	InsertVector(PlayerBJ, strTime);
	InsertListCtrl(PlayerBJ, strTime);
	CalcWinRate();
	m_KillCounter = 0;
	m_edt_PlayerCards.SetFocus();

}

void CBIJDlg::OnPush() 
{
	// TODO: Add your control notification handler code here
	CString strTime;
	strTime.Format(_T("%s"), COleDateTime::GetCurrentTime().Format(_T("%H:%M:%S %m/%d/%Y")));
	InsertVector(PushWins, strTime);
	InsertListCtrl(PushWins, strTime);
	CalcWinRate();
	if (m_chk_push.GetCheck())
	{	
		m_KillCounter = m_KillCounter + 1;
		KillGameProcess();
	}
	else
	{
	
	}
	m_edt_PlayerCards.SetFocus();

}

void CBIJDlg::OnCancelrec() 
{
	// TODO: Add your control notification handler code here
	InvalidateLastInsert();
	CalcWinRate();
	m_edt_PlayerCards.SetFocus();

}






void CBIJDlg::InsertVector(int mWhoWins, CString strTime)
{

	CBJData tmp_bj_data;
	CString strDealerCards;
	CString strPlayerCards;

	m_edt_DealerCards.GetWindowText( strDealerCards );
	m_edt_PlayerCards.GetWindowText( strPlayerCards );

	tmp_bj_data.m_winner=mWhoWins;
	tmp_bj_data.m_dealer_cards = strDealerCards;
	tmp_bj_data.m_player_cards = strPlayerCards;
	tmp_bj_data.m_time=strTime;
	m_bj_data.push_back (tmp_bj_data);
	IsDirty=TRUE;
//	CalcWinRate();



}

void CBIJDlg::InsertListCtrl(int mWhoWins, CString strTime)
{
	UpdateData(TRUE);
    CStringArray line;
	CString strDealerCards;
	CString strPlayerCards;
	CString strNo;
	char chrNo[10];
	int m_no;

	m_edt_DealerCards.GetWindowText( strDealerCards );
	m_edt_PlayerCards.GetWindowText( strPlayerCards );
	m_edt_DealerCards.SetWindowText( "" );
	m_edt_PlayerCards.SetWindowText( "" );

	m_no = m_cListCtrl.GetItemCount() + 1;
	_itoa(m_no, chrNo, 10 );
	strNo = chrNo;


    line.Add("");
    line.Add("");
    line.Add( strDealerCards );
    line.Add( strPlayerCards );
	line.Add( strNo );
	line.Add( strTime );
    m_cListCtrl.AddItem( &line, 0 );

	//lance
	//need set the owner data fixed checked or the color can not be painted
	switch (mWhoWins)
	{
	case DealerBJ:
			m_cListCtrl.SetItemBackgndColor(ITEM_COLOR(DealerWinColor),0,0); //change the first cell color
			m_cListCtrl.SetItemBackgndColor(ITEM_COLOR(DealerWinColor),0,1); //change the second cell color
			break;
	case DealerWins:
			m_cListCtrl.SetItemBackgndColor(ITEM_COLOR(DealerWinColor),0,0); //change the first cell color
			m_cListCtrl.SetItemBackgndColor(ITEM_COLOR(NonBJColor),0,1); //change the second cell color
			break;
	case PushWins:
			m_cListCtrl.SetItemBackgndColor(ITEM_COLOR(PushColor),0,0); //change the first cell color
			m_cListCtrl.SetItemBackgndColor(ITEM_COLOR(NonBJColor),0,1); //change the second cell color
			break;
	case PlayerWins:
			m_cListCtrl.SetItemBackgndColor(ITEM_COLOR(PlayerWinColor),0,0); //change the first cell color
			m_cListCtrl.SetItemBackgndColor(ITEM_COLOR(NonBJColor),0,1); //change the second cell color
			break;
	case PlayerBJ:
			m_cListCtrl.SetItemBackgndColor(ITEM_COLOR(PlayerWinColor),0,0); //change the first cell color
			m_cListCtrl.SetItemBackgndColor(ITEM_COLOR(PlayerWinColor),0,1); //change the second cell color
			break;
	}

}


void CBIJDlg::InvalidateLastInsert()
{
	int m_item_count;
	m_item_count=m_cListCtrl.GetItemCount();
	if (m_item_count > 0) 
	{
		m_bj_data.pop_back ();
		m_cListCtrl.DeleteItem(0);
		CalcWinRate();
		IsDirty=TRUE;
	}
}


//lance asdfgp
/*
void CBIJDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	//AfxMessageBox(CString(nChar));

	char m_key_char;
	m_key_char=char(nChar);

	CString strTime;
	strTime.Format(_T("%s"), COleDateTime::GetCurrentTime().Format(_T("%H:%M:%S %m/%d/%Y")));

	//m_hwndDlg->sendMessage(lpMsg,0,0);

	switch ( m_key_char)
	{
		case 'A':
			//AfxMessageBox("A");
			
			InsertVector(DealerWins, strTime);
			InsertListCtrl(DealerWins, strTime);
			CalcWinRate();
			break;
		case 'S':
			//AfxMessageBox("S");
			
			InsertVector(DealerBJ, strTime);
			InsertListCtrl(DealerBJ, strTime);
			CalcWinRate();
			break;
		case 'D':
			//AfxMessageBox("D");
			
			InsertVector(PlayerWins, strTime);
			InsertListCtrl(PlayerWins, strTime);
			CalcWinRate();
			break;
		case 'F':
			//AfxMessageBox("F");
			
			InsertVector(PlayerBJ, strTime);
			InsertListCtrl(PlayerBJ, strTime);
			CalcWinRate();
			break;
		case 'G':
			//AfxMessageBox("P");
			
			InsertVector(PushWins, strTime);
			InsertListCtrl(PushWins, strTime);
			CalcWinRate();
			break;
		case 'P':
			//AfxMessageBox("P");
			InvalidateLastInsert();
			CalcWinRate();
			break;
	}





	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}
*/


//lance asdfgp
/*
//get the keydown message for us in dialog
BOOL CBIJDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
    if( pMsg->message>=WM_KEYDOWN && pMsg->message<=WM_KEYUP)
	{
		this->SendMessage(pMsg->message,pMsg->wParam,pMsg->lParam);
		return TRUE;
	}
	else
        return CDialog::PreTranslateMessage(pMsg);
}
*/


//create a new bj data
void CBIJDlg::OnOK() 
{
	// TODO: Add extra validation here

	if ((m_bj_data.size() != 0) && IsDirty == TRUE)
	{
		int ret = MessageBox("Your Current BJ Data Will Be Erased, Do You Still Want To Go On?", "BIJ: BlackJack Data Recording System", 
			MB_ICONQUESTION | MB_YESNO | MB_APPLMODAL);
		
		if (ret == IDYES)
		{
			mCurrentFile="";
			m_bj_data.clear();
			m_cListCtrl.DeleteAllItems();
		}
		else
		{
		
		}

	}
	else
	{
		mCurrentFile="";
		m_bj_data.clear();
		m_cListCtrl.DeleteAllItems();
	}
	//CDialog::OnOK();
}



void CBIJDlg::OnOpenrec() 
{
	// TODO: Add your control notification handler code here
	if ((m_bj_data.size() != 0) && IsDirty == TRUE)
	{
		int ret = MessageBox("Your Current BJ Data Will Be Erased, Do You Still Want To Go On?", "BIJ: BlackJack Data Recording System", 
			MB_ICONQUESTION | MB_YESNO | MB_APPLMODAL);
		
		if (ret == IDNO)
		{
			return;						
		}
	}


	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER | OFN_PATHMUSTEXIST, "BIJ Data|*.bij|All files|*.*||"); 

	dlg.m_ofn.lpstrTitle = "User BlackJack Data - Open File";


     
     if (dlg.DoModal()==IDOK)
	 {
		CString mFilePath;
		CString mFileName;
		CString mFileExt;
		mFilePath = dlg.GetPathName();
		mFileName = dlg.GetFileName();
		mFileExt = dlg.GetFileExt();
		//MessageBox(mFilePath);
		//MessageBox(mFileName);
		//MessageBox(mFileExt);
		
		OnReadFile(mFilePath);
		mCurrentFile = mFilePath;  //set the mCurrentFile
		WriteStatusBar(mFilePath);
	 }
}


void CBIJDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	if (mCurrentFile.IsEmpty())
	{
		OnSaveas();  //empty then call save as to designate a file name
	}
	else
	{
		OnSerialize(mCurrentFile);	 // not empty then use the current file
		WriteStatusBar("Data Saved to " + mCurrentFile);

	}
}



void CBIJDlg::OnSaveas() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(FALSE, NULL, NULL, OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "BIJ Data|*.bij|All files|*.*||"); 

	dlg.m_ofn.lpstrTitle = "User BlackJack Data - Save File As";


     
     if (dlg.DoModal()==IDOK)
	 {
		CString mFilePath;
		CString mFileName;
		CString mFileExt;
		mFilePath = dlg.GetPathName();
		mFileName = dlg.GetFileName();
		mFileExt = dlg.GetFileExt();
		//MessageBox(mFilePath);
		//MessageBox(mFileName);
		//MessageBox(mFileExt);
		
		if (mFileExt == "") 
		{
			OnSerialize(mFilePath + ".bij");
			mCurrentFile = mFilePath + ".bij" ;  //set the mCurrentFile
		}
		else
		{
			OnSerialize(mFilePath);
			mCurrentFile = mFilePath; //set the mCurrentFile
		}

		WriteStatusBar("Data Saved to " + mCurrentFile);

	 }



}


//write  BJ record to file
void CBIJDlg::OnSerialize(CString mFilePathName)
{

	CDataFile df(DF::RF_READ_AS_STRING | DF::RF_APPEND_DATA);

	df.CreateVariable("WINNER", "");
	df.CreateVariable("TIME", "");
	df.CreateVariable("DEALER CARDS", "");
	df.CreateVariable("PLAYER CARDS", "");


	//vector <string> v1;
	//vector <string> v2;

	char  chrWinner[10];
	string  strTime;
	string  strDealerCards;
	string  strPlayercards;
	const char * chrTime;
	const char * chrDealerCards;
	const char * chrPlayercards;
	

	long mBJSize;
	mBJSize = m_bj_data.size();

	for (long i = 0; i < mBJSize; i++)
	{
		
		_itoa(m_bj_data[i].m_winner, chrWinner, 10 );

		strTime=CStringTostring(m_bj_data[i].m_time);
		strDealerCards=CStringTostring(m_bj_data[i].m_dealer_cards);
		strPlayercards=CStringTostring(m_bj_data[i].m_player_cards);

		chrTime=strTime.c_str();
		chrDealerCards=strDealerCards.c_str();
		chrPlayercards=strPlayercards.c_str();
		

		df.AppendData(0, chrWinner);
		df.AppendData(1, chrTime);
		df.AppendData(2, chrDealerCards);
		df.AppendData(3, chrPlayercards);
	}

	df.WriteFile(mFilePathName, ",");
	IsDirty=FALSE;

}


//load BJ record from BIJ file
void CBIJDlg::OnReadFile(CString mFilePathName)
{

	string strPath;
	const char * chrPath;
	strPath = CStringTostring(mFilePathName);
	chrPath = strPath.c_str();
	

	CDataFile df(DF::RF_READ_AS_STRING);
	if(df.ReadFile(chrPath))
	{
		long mBJSize;
		mBJSize=df.GetNumberOfSamples(0);

		m_bj_data.clear();
		m_cListCtrl.DeleteAllItems();

		char  strWinner[10];
		string  strTime;
		string  strDealerCards;
		string  strPlayercards;

		int mWhoWins;
		CString cstrTime;
		CString cstrDealerCards;
		CString cstrPlayerCards;
		
		for (long i = 0; i < mBJSize; i++)
		{
			
			if (df.GetData (0, i, strWinner) && df.GetData (1, i, strTime))
			{
				mWhoWins = atoi(strWinner);
				df.GetData (2, i, strDealerCards);
				df.GetData (3, i, strPlayercards);

				cstrTime = stringToCString(strTime);
				cstrDealerCards = stringToCString(strDealerCards);
				cstrPlayerCards = stringToCString(strPlayercards);
				
				m_edt_DealerCards.SetWindowText( cstrDealerCards );
				m_edt_PlayerCards.SetWindowText( cstrPlayerCards );


				InsertVector(mWhoWins, cstrTime);
				InsertListCtrl(mWhoWins, cstrTime);
			
			}
		
		}
		CalcWinRate();
	}
	IsDirty=FALSE;
	
}



//Transfer CString to string
string CBIJDlg::CStringTostring(CString str)
{
	string s;
	s.append(str.GetBuffer(str.GetLength()));
	str.ReleaseBuffer();
	return s;
}

//Transfer string to CString
CString CBIJDlg::stringToCString(string str)
{
	CString s(str.c_str());
	return s;
}
 



//write date to status bar
void CBIJDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
    if(nIDEvent==100) 
    {
        CTime t1;
        t1=CTime::GetCurrentTime();
        m_bar.SetPaneText(5,t1.Format("%H:%M:%S %m/%d/%Y"));


    }
    CDialog::OnTimer(nIDEvent);	
}


void CBIJDlg::WriteStatusBar(CString cstrItem)
{

    m_bar.SetPaneText(0,cstrItem);



}


/*
void CBIJDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    CString s;
    s.Format("X=%d Y=%d",point.x,point.y);
    m_bar.SetPaneText(0,s);
    CDialog::OnMouseMove(nFlags, point);

}
*/




void CBIJDlg::OnMenuNew() 
{
	// TODO: Add your command handler code here

	OnOK(); //create new record
}

void CBIJDlg::OnMenuOpen() 
{
	// TODO: Add your command handler code here
	OnOpenrec();
	
}

void CBIJDlg::OnMenuSave() 
{
	// TODO: Add your command handler code here
	OnSave();
	
}

void CBIJDlg::OnMenuSaveas() 
{
	// TODO: Add your command handler code here
	OnSaveas();
}

void CBIJDlg::OnMenuExit() 
{
	// TODO: Add your command handler code here
	OnCancel();
	
}

void CBIJDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	if (!(m_bj_data.size()==0) && IsDirty == TRUE)
	{
		int ret = MessageBox("If You Exit Program Now, Your Current BJ Data Will Be Lost, Do You Still Want To Exit?", "BIJ: BlackJack Data Recording System", 
			MB_ICONQUESTION | MB_YESNO | MB_APPLMODAL);
		
		if (ret == IDYES)
		{
			CDialog::OnCancel();		
		}
	}
	else
	{
		CDialog::OnCancel();	
	}
	
}

void CBIJDlg::OnMenuAbout() 
{
	// TODO: Add your command handler code here

	CAboutDlg dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}


	
}

void CBIJDlg::OnMenuHelp() 
{
	// TODO: Add your command handler code here
	OnHelp();
}

void CBIJDlg::OnSize(UINT nType, int cx, int cy) 
{


	dlgAnchor.OnSize();
	
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	
}



// toolbar tooltiptext
BOOL CBIJDlg::OnToolTipText(UINT, NMHDR* pNMHDR, LRESULT* pResult)
{
    ASSERT(pNMHDR->code == TTN_NEEDTEXTA || pNMHDR->code == TTN_NEEDTEXTW);
    
    // UNICODE消息
    TOOLTIPTEXTA* pTTTA = (TOOLTIPTEXTA*)pNMHDR;
    TOOLTIPTEXTW* pTTTW = (TOOLTIPTEXTW*)pNMHDR;
    //TCHAR szFullText[512];
    CString strTipText;
    UINT nID = pNMHDR->idFrom;
    
    if (pNMHDR->code == TTN_NEEDTEXTA && (pTTTA->uFlags & TTF_IDISHWND) ||
        pNMHDR->code == TTN_NEEDTEXTW && (pTTTW->uFlags & TTF_IDISHWND))
    {
        // idFrom为工具条的HWND 
        nID = ::GetDlgCtrlID((HWND)nID);
    }
    
	
    if (nID != 0) //不为分隔符
    {
        strTipText.LoadString(nID);
        strTipText = strTipText.Mid(strTipText.Find('\n',0)+1);
        
#ifndef _UNICODE
        if (pNMHDR->code == TTN_NEEDTEXTA)
        {
            lstrcpyn(pTTTA->szText, strTipText, sizeof(pTTTA->szText));
        }
        else
        {
            _mbstowcsz(pTTTW->szText, strTipText, sizeof(pTTTW->szText));
        }
#else
        if (pNMHDR->code == TTN_NEEDTEXTA)
        {
            _wcstombsz(pTTTA->szText, strTipText,sizeof(pTTTA->szText));
        }
        else
        {
            lstrcpyn(pTTTW->szText, strTipText, sizeof(pTTTW->szText));
        }
#endif
        
        *pResult = 0;
        
        // 使工具条提示窗口在最上面
        ::SetWindowPos(pNMHDR->hwndFrom, HWND_TOP, 0, 0, 0, 0,SWP_NOACTIVATE|
            SWP_NOSIZE|SWP_NOMOVE|SWP_NOOWNERZORDER); 
        return TRUE;
    }
    return TRUE;
}



void CBIJDlg::CalcWinRate()
{
	long i, mPlayerWins, mPlayerBJ, mDealerWins, mDealerBJ, mPush, mBJSize;
	int mWhoWins;

	mDealerBJ = 0;
	mDealerWins = 0;
	mPlayerWins = 0;
	mPlayerBJ = 0;
	mPush = 0;
	
    


	mBJSize = m_bj_data.size();

	if (mBJSize == 0 )
	{
		
		m_bar.SetPaneText(1, "TH: ");
		m_bar.SetPaneText(2, "PW: ");
		m_bar.SetPaneText(3, "DW: ");
		m_bar.SetPaneText(4, "PU: ");
		return;	

	}


	for ( i = 0; i < mBJSize; i++)
	{
		
		mWhoWins = m_bj_data[i].m_winner;

		switch (mWhoWins)
		{
		case DealerBJ:
				mDealerBJ = mDealerBJ + 1;
				break;
		case DealerWins:
				mDealerWins = mDealerWins + 1;
				break;
		case PushWins:
				mPush = mPush + 1;
				break;
		case PlayerWins:
				mPlayerWins = mPlayerWins + 1;
				break;
		case PlayerBJ:
				mPlayerBJ = mPlayerBJ + 1;
				break;
		}
	}
	
//	double mRate;
	LPCTSTR lp;
	CString str, str1;
	CString mRate;

	str.Format("%d", mBJSize);
	str1 = "TH: " + str;
	lp = str1;
	m_bar.SetPaneText(1, lp);

	str.Format("%d", (mPlayerWins + mPlayerBJ));
	mRate.Format("%4.2f", 100.0*((double)(mPlayerWins + mPlayerBJ) / (double)mBJSize));
	//str1 = "PW: " + str + " (" + mRate + "%)";
	str1 = "PW: " + mRate + "% (" + str + ")";
	lp = str1;
    m_bar.SetPaneText(2, lp);

	str.Format("%d", (mDealerWins + mDealerBJ));
	mRate.Format("%4.2f", 100.0*((double)(mDealerWins + mDealerBJ) / (double)mBJSize));
	str1 = "DW: " + mRate + "% (" + str + ")";
	lp = str1;
    m_bar.SetPaneText(3, lp);

	str.Format("%d", mPush);
	mRate.Format("%4.2f", 100.0*((double)mPush / (double)mBJSize));
	str1 = "PU: " + mRate + "% (" + str + ")";
	lp = str1;
	m_bar.SetPaneText(4, lp);


  
}





void CBIJDlg::OnButton32779() 
{
	// TODO: Add your command handler code here
	//MessageBox ("open");
	OnOpenrec();
	
}

void CBIJDlg::OnButton32780() 
{
	// TODO: Add your command handler code here
	//MessageBox ("save");
	OnSave();

}

void CBIJDlg::OnButton32781() 
{
	// TODO: Add your command handler code here
	//MessageBox ("new");
	OnOK(); //create new record

}

void CBIJDlg::OnButton32782() 
{
	// TODO: Add your command handler code here
//	OnHelp();

}


void CBIJDlg::KillGameProcess() 
{
	
	CString strPreset;
	CString strCasinoName;

	m_edt_LostHand.GetWindowText( strPreset );
	m_cbo_CasinoName.GetWindowText( strCasinoName );

	if (!strPreset.IsEmpty() && !strCasinoName.IsEmpty())
	{
		int mPreset;
		mPreset = atoi(strPreset);

		if (m_KillCounter >= mPreset) 
		{
			
			m_KillProcess.KillProcess(strCasinoName);
			m_KillProcess.KillProcess("casino.exe");
			m_KillCounter = 0;

		}
		else
		{}

	
	}
	

}



void CBIJDlg::WriteEditCards(int mBtnName) 
{
	
	CString strInput;

		switch (mBtnName)
		{
		case 1:
				strInput = "A";
				break;
		case 2:
				strInput = "2";
				break;
		case 3:
				strInput = "3";
				break;
		case 4:
				strInput = "4";
				break;
		case 5:
				strInput = "5";
				break;
		case 6:
				strInput = "6";
				break;
		case 7:
				strInput = "7";
				break;
		case 8:
				strInput = "8";
				break;
		case 9:
				strInput = "9";
				break;
		case 10:
				strInput = "T";
				break;
		case 11:
				strInput = "J";
				break;
		case 12:
				strInput = "Q";
				break;
		case 13:
				strInput = "K";
				break;
		case 14:
				strInput = "BACKSPACE";
				break;
		}

	
	CString strWndTxt;
	int strLen, strStart, strEnd;
	
	if (m_Focus == DealerFocus) 
	{

		if (strInput == "BACKSPACE")
		{
			m_edt_DealerCards.GetWindowText( strWndTxt );
			strLen = strWndTxt.GetLength();
			if (strLen >= 1)
			{
				m_edt_DealerCards.GetSel( strStart, strEnd );
				if (strStart != strEnd) //there are some characters in the current selection 
				{
					m_edt_DealerCards.ReplaceSel( "", true );
				}
				else  ////there are no characters in the current selection 
				{
					if (strStart >= 1)  //only delete the one character when the cursor is not on the first place
					{
						m_edt_DealerCards.SetSel(strStart-1, strStart);
						m_edt_DealerCards.ReplaceSel( "", true );
					}
				}

				//strWndTxt = strWndTxt.Left(strLen-1);
				//m_edt_DealerCards.SetWindowText(strWndTxt);
			}
		}
		else
		{
			//m_edt_DealerCards.GetWindowText( strWndTxt );
			//strWndTxt = strWndTxt + strInput;
			//m_edt_DealerCards.SetWindowText(strWndTxt);
			m_edt_DealerCards.ReplaceSel( strInput, true );
		}
	}
	else if (m_Focus == PlayerFocus) 
	{
		if (strInput == "BACKSPACE")
		{
			m_edt_PlayerCards.GetWindowText( strWndTxt );
			strLen = strWndTxt.GetLength();
			if (strLen >= 1)
			{
				m_edt_PlayerCards.GetSel( strStart, strEnd );
				if (strStart != strEnd) //there are some characters in the current selection 
				{
					m_edt_PlayerCards.ReplaceSel( "", true );
				}
				else  ////there are no characters in the current selection 
				{
					if (strStart >= 1)  //only delete the one character when the cursor is not on the first place
					{
						m_edt_PlayerCards.SetSel(strStart-1, strStart);
						m_edt_PlayerCards.ReplaceSel( "", true );
					}
				}

				//strWndTxt = strWndTxt.Left(strLen-1);
				//m_edt_PlayerCards.SetWindowText(strWndTxt);
			}
		}
		else
		{
			//m_edt_PlayerCards.GetWindowText( strWndTxt );
			//strWndTxt = strWndTxt + strInput;
			//m_edt_PlayerCards.SetWindowText(strWndTxt);
			m_edt_PlayerCards.ReplaceSel( strInput, true );
		}
	}
}



void CBIJDlg::OnSetfocusEdit2() 
{
	// TODO: Add your control notification handler code here
	m_Focus = DealerFocus;
}

void CBIJDlg::OnSetfocusEdit3() 
{
	// TODO: Add your control notification handler code here
	m_Focus = PlayerFocus;
	
}


void CBIJDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	
	WriteEditCards(1);
	
}


void CBIJDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	WriteEditCards(2);

}

void CBIJDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	WriteEditCards(3);

}

void CBIJDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	WriteEditCards(4);
	
}

void CBIJDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	WriteEditCards(5);
}

void CBIJDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	WriteEditCards(6);
}

void CBIJDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	WriteEditCards(7);
}

void CBIJDlg::OnButton8() 
{
	// TODO: Add your control notification handler code here
	WriteEditCards(8);
}

void CBIJDlg::OnButton9() 
{
	// TODO: Add your control notification handler code here
	WriteEditCards(9);
}

void CBIJDlg::OnButton10() 
{
	// TODO: Add your control notification handler code here
	WriteEditCards(10);
}

void CBIJDlg::OnButton11() 
{
	// TODO: Add your control notification handler code here
	WriteEditCards(11);
}

void CBIJDlg::OnButton12() 
{
	// TODO: Add your control notification handler code here
	WriteEditCards(12);
}

void CBIJDlg::OnButton13() 
{
	// TODO: Add your control notification handler code here
	WriteEditCards(13);
}

void CBIJDlg::OnButton14() 
{
	// TODO: Add your control notification handler code here
	WriteEditCards(14);  //remove the last input
}

void CBIJDlg::OnSetfocusEdit1() 
{
	// TODO: Add your control notification handler code here
	m_Focus = NoFocus;
	
}

void CBIJDlg::OnSetfocusCombo1() 
{
	// TODO: Add your control notification handler code here
	m_Focus = NoFocus;
}

void CBIJDlg::OnButton15() 
{
	// TODO: Add your control notification handler code here

	//update the cards value in the selected row of listctrl 
	CString str;
	m_edt_DealerCards.GetWindowText(str);
	m_cListCtrl.SetItemText(m_nSelected, 2, str);

	m_edt_PlayerCards.GetWindowText(str);
	m_cListCtrl.SetItemText(m_nSelected, 3, str);

	IsDirty = true;


	
}


void CBIJDlg::OnClickListCtrl(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	//AfxMessageBox("D");

	POSITION p = m_cListCtrl.GetFirstSelectedItemPosition();
	CString msg = _T("");
	while (p)
	{


		long nSelected = m_cListCtrl.GetNextSelectedItem(p);
		if (msg.IsEmpty())
			msg = _T("The following items are selected: ");

		m_nSelected = nSelected;

		CString str;
		str.Format(_T("%s"), m_cListCtrl.GetItemText(nSelected, 2));
		m_edt_DealerCards.SetWindowText(str);

		str.Format(_T("%s"), m_cListCtrl.GetItemText(nSelected, 3));
		m_edt_PlayerCards.SetWindowText(str);



		if (p)
			str += _T(", ");
		msg += str;

	}
	if (msg.IsEmpty())
		msg = _T("There are no selected items");

	//m_Log.AppendString(msg);

	//AfxMessageBox(msg) ;
	




	*pResult = 0;
}

void CBIJDlg::OnMenuReg() 
{
	// TODO: Add your command handler code here
	OnReg();
}


void CBIJDlg::OnReg()
{

	CReg dlg;

	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}



}