// BIJ.h : main header file for the BIJ application
//

#if !defined(AFX_BIJ_H__A3DC5B87_8D15_4A15_8E98_1F72475A640F__INCLUDED_)
#define AFX_BIJ_H__A3DC5B87_8D15_4A15_8E98_1F72475A640F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBIJApp:
// See BIJ.cpp for the implementation of this class
//

class CBIJApp : public CWinApp
{
public:

	CBIJApp();

	int FindLic();
	int FindTime();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBIJApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBIJApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BIJ_H__A3DC5B87_8D15_4A15_8E98_1F72475A640F__INCLUDED_)
