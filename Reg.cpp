// Reg.cpp : implementation file
//

#include "stdafx.h"
#include "BIJ.h"
#include "Reg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReg dialog


CReg::CReg(CWnd* pParent /*=NULL*/)
	: CDialog(CReg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CReg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReg)
	DDX_Control(pDX, IDC_EDIT1, m_edtRegName);
	DDX_Control(pDX, IDC_EDIT2, m_edtRegCode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReg, CDialog)
	//{{AFX_MSG_MAP(CReg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReg message handlers

void CReg::OnOK() 
{
	// TODO: Add extra validation here
	

    CheckReg();
	CDialog::OnOK();
}




//lance 20090108 check reg code valid or not
void CReg::CheckReg()

{
		CString strTmp;
		CString strCode;

		strCode = "7QVT6-T2738-WRKJB-YKRFQ-XVK98";


		m_edtRegCode.GetWindowText(strTmp);
		
		strTmp.TrimLeft();
		strTmp.TrimRight();

		
		if (strTmp.IsEmpty()) 
			return;
		
		strTmp.MakeUpper();

		if (strTmp == strCode)
		{
			//AfxMessageBox ("good");
		        DWORD   dwData   =   15; 
				DWORD dwDisposition;
				HKEY  hKey=NULL;
				if (RegOpenKeyEx(HKEY_CURRENT_USER, _T("Software\\VBAA"), 0, KEY_ALL_ACCESS, &hKey)!=ERROR_SUCCESS) 
				{
				  if (RegCreateKeyEx(HKEY_CURRENT_USER, _T("Software\\VBAA"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, &dwDisposition)!=ERROR_SUCCESS) 
				  {
					return;
				  }
				}
				if (RegSetValueEx(hKey, _T("SERVICEID"), 0, REG_BINARY, (LPBYTE)&dwData, sizeof(dwData))!=ERROR_SUCCESS) {
				  RegCloseKey(hKey);
				  return;
				}
				RegCloseKey(hKey);
				return;
		}
		else
		{
			AfxMessageBox("Wrong registraion code, pls contaxt support@21sys.org for further help!");
			return;
		}
		
			
}


