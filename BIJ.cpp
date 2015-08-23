// BIJ.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "BIJ.h"
#include "BIJDlg.h"
#include "reg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBIJApp

BEGIN_MESSAGE_MAP(CBIJApp, CWinApp)
	//{{AFX_MSG_MAP(CBIJApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBIJApp construction

CBIJApp::CBIJApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CBIJApp object

CBIJApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CBIJApp initialization

BOOL CBIJApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif


	//lance 20090108 check if license there.
    int rtn = 0;
	int rtnTime=0;
	rtn = FindLic();



	//lance unregistered version
    if (rtn == 0)
	{
		CReg mDlg;
		int mResponse = mDlg.DoModal();
			if (mResponse == IDOK)
			{
				// TODO: Place code here to handle when the dialog is
				//  dismissed with OK
			}
			else if (mResponse == IDCANCEL)
			{
				// TODO: Place code here to handle when the dialog is
				//  dismissed with Cancel
			}
	}


	//lance if ungistered, then check time line 
	rtn = FindLic();
	if (rtn == 0)
	{
		rtnTime = FindTime();
		if (rtnTime == 0) //time expired
			return FALSE;
	  	
	}


	
	
	
	
	
	CBIJDlg dlg;
	m_pMainWnd = &dlg;

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

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.


	return FALSE;
}


int CBIJApp::FindLic()
{

	HKEY  hKey=NULL;
	DWORD dwData, dwType;  

	int rtn=0;

	if (RegOpenKeyEx(HKEY_CURRENT_USER, _T("Software\\VBAA"), 0, KEY_ALL_ACCESS, &hKey)==ERROR_SUCCESS) 
	{
	  if (RegQueryValueEx(hKey, _T("SERVICEID"), NULL, &dwType, (LPBYTE)&dwData, &dwData)==ERROR_SUCCESS) 
	  {
		if (dwData== 4)
			rtn = 1;

		RegCloseKey(hKey);
	  }		
	  
	}

	return rtn;

}



//lance if unregister, check time if longer than 15 days
int CBIJApp::FindTime()
{

	int rtnTime=0;
	HKEY  hKey=NULL;
	DWORD dwType; 



	COleDateTime mtime;
    mtime = COleDateTime::GetCurrentTime();

    long iTime = 0 ; 
	CString recTime;  
	CString curTime;

	char data[200]="";
	DWORD bread=200;


	if (RegOpenKeyEx(HKEY_CURRENT_USER, _T("Software\\VBAA"), 0, KEY_ALL_ACCESS, &hKey)==ERROR_SUCCESS) 
	{
	  if (RegQueryValueEx(hKey, _T("TTT"), NULL, &dwType, (BYTE*)&data, &bread)!=ERROR_SUCCESS) 
	  {
		  //lance 20090109 no start time, let's set start timer

		  //change curent to a string like int, 01/09/2009 -> 20090109
		  iTime = mtime.GetYear();
		  iTime = (iTime * 100) + mtime.GetMonth();
		  iTime = (iTime * 100) + mtime.GetDay();

		  curTime.Format("%d", iTime);

		  //dwData = strTime;

		  if (RegSetValueEx(hKey, _T("TTT"), 0, REG_SZ, (LPBYTE)((LPCTSTR)curTime), curTime.GetLength())!=ERROR_SUCCESS) 
				  {
					RegCloseKey(hKey);
					rtnTime = 1;
					return  rtnTime;
				  }


		RegCloseKey(hKey);
	  }		
	  else  //start time already recorded
	  {
		//20090109 already set time, check if longer than 15 days	
		  
		  //change curent to a string like int, 01/09/2009 -> 20090109
		  iTime = mtime.GetYear();
		  iTime = (iTime * 100) + mtime.GetMonth();
		  iTime = (iTime * 100) + mtime.GetDay();

		  curTime.Format("%d", iTime);

		  recTime = data;

		  long ct, rt;

		  ct = atol(curTime);
		  rt = atol(recTime);

		  if ((ct-rt) > 15)
		  {
		    //lance demo expire
			  rtnTime = 1;
		  }
		  else
		  {
		    //lance demo still working
		  }


			RegCloseKey(hKey);





	  }
	 
	}

  return rtnTime;


}