// GhostKey.h : main header file for the GHOSTKEY application
//

#if !defined(AFX_GHOSTKEY_H__8E719276_F50D_4DBF_95A5_00D5EE9700CD__INCLUDED_)
#define AFX_GHOSTKEY_H__8E719276_F50D_4DBF_95A5_00D5EE9700CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGhostKeyApp:
// See GhostKey.cpp for the implementation of this class
//

class CGhostKeyApp : public CWinApp
{
public:
	CGhostKeyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGhostKeyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGhostKeyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GHOSTKEY_H__8E719276_F50D_4DBF_95A5_00D5EE9700CD__INCLUDED_)
