// BIJSettings.cpp : implementation file
//

#include "stdafx.h"
#include "BIJ.h"
#include "BIJSettings.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBIJSettings dialog


CBIJSettings::CBIJSettings(CWnd* pParent /*=NULL*/)
	: CDialog(CBIJSettings::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBIJSettings)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBIJSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBIJSettings)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBIJSettings, CDialog)
	//{{AFX_MSG_MAP(CBIJSettings)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBIJSettings message handlers

void CBIJSettings::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CBIJSettings::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
