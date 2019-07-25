// mfcxmlDlg.h : header file
//

#if !defined(AFX_MFCXMLDLG_H__6269C9C2_AA81_4C5D_97BE_508F10C9ACB5__INCLUDED_)
#define AFX_MFCXMLDLG_H__6269C9C2_AA81_4C5D_97BE_508F10C9ACB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMfcxmlDlg dialog

class CMfcxmlDlg : public CDialog
{
// Construction
public:
	CMfcxmlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMfcxmlDlg)
	enum { IDD = IDD_MFCXML_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfcxmlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMfcxmlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCXMLDLG_H__6269C9C2_AA81_4C5D_97BE_508F10C9ACB5__INCLUDED_)
