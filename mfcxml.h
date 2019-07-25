// mfcxml.h : main header file for the MFCXML application
//

#if !defined(AFX_MFCXML_H__CFBB77A5_199B_4A3F_83AF_ACF600D5978D__INCLUDED_)
#define AFX_MFCXML_H__CFBB77A5_199B_4A3F_83AF_ACF600D5978D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMfcxmlApp:
// See mfcxml.cpp for the implementation of this class
//

class CMfcxmlApp : public CWinApp
{
public:
	CMfcxmlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfcxmlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMfcxmlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCXML_H__CFBB77A5_199B_4A3F_83AF_ACF600D5978D__INCLUDED_)
