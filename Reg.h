#if !defined(AFX_REG_H__D5D566EA_2E88_4722_A686_F55255B7E9A6__INCLUDED_)
#define AFX_REG_H__D5D566EA_2E88_4722_A686_F55255B7E9A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Reg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReg dialog

class CReg : public CDialog
{
// Construction
public:
	CReg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReg)
	enum { IDD = IDD_REGISTER };
	CEdit	m_edtRegName;
	CEdit	m_edtRegCode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	void CheckReg();


	// Generated message map functions
	//{{AFX_MSG(CReg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REG_H__D5D566EA_2E88_4722_A686_F55255B7E9A6__INCLUDED_)
