// BIJDlg.h : header file
//

#if !defined(AFX_BIJDLG_H__10AC6978_4DDF_4E9D_92AB_2BE37D48D433__INCLUDED_)
#define AFX_BIJDLG_H__10AC6978_4DDF_4E9D_92AB_2BE37D48D433__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define COLUMNS_m_cListCtrl 6
#define	DealerBJ -2
#define DealerWins -1
#define	PlayerWins 1
#define	PlayerBJ 2 
#define	PushWins 0

#define	NoFocus 1
#define	DealerFocus 2
#define	PlayerFocus 3

#pragma warning (disable : 4786) //remove warnings from using stl //lance


#include <vector>
using namespace std;

#include "ColorListCtrl.h"
#include "ColorBox.h"
#include "anchor.h"
#include "dlgman.h"
#include "KillProcess.h"
#include "StringEdit.h"


class CBJData
{
public:

	CBJData()
	{
		m_winner = '2';
		m_time = "";
		m_dealer_cards = "";
		m_player_cards = "";

	}

	CString m_time;
	CString m_dealer_cards;
	CString m_player_cards;
	int m_winner;
};


/////////////////////////////////////////////////////////////////////////////
// CBIJDlg dialog

class CBIJDlg : public CDialog
{
// Construction
public:

	CBIJDlg(CWnd* pParent = NULL);	// standard constructor
	
    vector<CBJData> m_bj_data; //lance must put here, or classwizard will go error

	CMenu m_menu;
	CToolBar m_wndtoolbar;
	CStatusBar m_bar;


	//resize dialog
	CDlgAnchor dlgAnchor;
	CDlgMan dlgMan;     


// Dialog Data
	//{{AFX_DATA(CBIJDlg)
	enum { IDD = IDD_BIJ_DIALOG };
	CButton	m_btn_update;
	CStringEdit	m_edt_PlayerCards;
	CStringEdit	m_edt_DealerCards;
	CEdit	m_edt_LostHand;		//edit1
	CComboBox	m_cbo_LostHand;
	CButton	m_chk_push;
	CComboBox	m_cbo_CasinoName;
	CColorBox	m_CancelRec;
	CColorBox	m_Push;
	CColorBox	m_PlayerWins;
	CColorBox	m_PlayerBJ;
	CColorBox	m_DealerWins;
	CColorBox	m_DealerBJ;
	CColorListCtrl	m_cListCtrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBIJDlg)
	public:
//lance asdfgp	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	
	void InsertVector(int mWhoWins, CString strTime);
	void InsertListCtrl(int mWhoWins, CString strTime);
	void InvalidateLastInsert();
	void CalcWinRate();
	void KillGameProcess();
	CKillProcess m_KillProcess;

	void OnSerialize(CString mFilePathName);
	void OnReadFile(CString mFilePathName);
	string CStringTostring(CString str);
	CString stringToCString(string str);


	
	
	//lance write anything(saved/opended file name to status bar 0)
	void WriteStatusBar(CString cstrItem);

	 //GREEN 8 RED 10 YELLOW 12 white 13
	int DealerWinColor;
	int PlayerWinColor;
	int PushColor;
	int NonBJColor;

	long m_nSelected; //which row of the listcontrol is selected after been clicked
	
	void WriteEditCards(int mBtnName);
	int m_Focus;

	CString mCurrentFile;
	BOOL IsDirty;
	int m_KillCounter;
	HICON m_hIcon;


	//lance 20090108
	void OnReg();

	// Generated message map functions
	//{{AFX_MSG(CBIJDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
    afx_msg BOOL OnToolTipText(UINT, NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDealerbj();
	afx_msg void OnDealerwins();
	afx_msg void OnPlayerwins();
	afx_msg void OnPlayerbj();
	afx_msg void OnPush();
	afx_msg void OnCancelrec();
	afx_msg void OnSaveas();
	afx_msg void OnOpenrec();
	afx_msg void OnSave();
	virtual void OnOK();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMenuNew();
	afx_msg void OnMenuOpen();
	afx_msg void OnMenuSave();
	afx_msg void OnMenuSaveas();
	afx_msg void OnMenuExit();
	virtual void OnCancel();
	afx_msg void OnMenuAbout();
	afx_msg void OnMenuHelp();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnButton32779();
	afx_msg void OnButton32780();
	afx_msg void OnButton32781();
	afx_msg void OnButton32782();
	afx_msg void OnButton1();
	afx_msg void OnSetfocusEdit2();
	afx_msg void OnSetfocusEdit3();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton9();
	afx_msg void OnButton10();
	afx_msg void OnButton11();
	afx_msg void OnButton12();
	afx_msg void OnButton13();
	afx_msg void OnButton14();
	afx_msg void OnSetfocusEdit1();
	afx_msg void OnSetfocusCombo1();
	afx_msg void OnButton15();
	afx_msg void OnClickListCtrl(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuReg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BIJDLG_H__10AC6978_4DDF_4E9D_92AB_2BE37D48D433__INCLUDED_)
