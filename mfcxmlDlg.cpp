// mfcxmlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mfcxml.h"
#include "mfcxmlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#import "C:\\WINDOWS\\system32\\msxml6.dll"   
using namespace MSXML2;  
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
// CMfcxmlDlg dialog

CMfcxmlDlg::CMfcxmlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMfcxmlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMfcxmlDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfcxmlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMfcxmlDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMfcxmlDlg, CDialog)
	//{{AFX_MSG_MAP(CMfcxmlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMfcxmlDlg message handlers

BOOL CMfcxmlDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMfcxmlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMfcxmlDlg::OnPaint() 
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
HCURSOR CMfcxmlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMfcxmlDlg::OnOK() 
{
	MessageBox("start");
	::CoInitialize(NULL);
	 MSXML2::IXMLDOMDocumentPtr XMLDOC;
	 MSXML2::IXMLDOMElementPtr XMLROOT;
	 MSXML2::IXMLDOMElementPtr XMLELEMENT;
	 MSXML2::IXMLDOMNodeListPtr XMLNODES; //某个节点的所以字节点
	 MSXML2::IXMLDOMNamedNodeMapPtr XMLNODEATTS;//某个节点的所有属性;
	 MSXML2::IXMLDOMNodePtr XMLNODE;
	 HRESULT HR = XMLDOC.CreateInstance(_uuidof(MSXML2::DOMDocument30));
	 if(!SUCCEEDED(HR))
	 {
	  MessageBox("faild!!");
	  return;
	 }
	 if (!XMLDOC->load("XMLTEST.XML"))
	 {
		MessageBox("xml file not found");
		return;
	 }
	 XMLROOT = XMLDOC->GetdocumentElement();//获得根节点;
	 XMLROOT->get_childNodes(&XMLNODES);//获得根节点的所有子节点;
	 long XMLNODESNUM,ATTSNUM;
	 XMLNODES->get_length(&XMLNODESNUM);//获得所有子节点的个数;
	 CString TMP;
	 TMP.Format("%d",XMLNODESNUM);
	 MessageBox(TMP);
	 int I=0;
	 int J=0;
	for( ;I<XMLNODESNUM;I++)
	 {
	  XMLNODES->get_item(I,&XMLNODE);//获得某个子节点;
	  XMLNODE->get_attributes(&XMLNODEATTS);//获得某个节点的所有属性;
	  XMLNODEATTS->get_length(&ATTSNUM);//获得所有属性的个数;
	  for(;J<ATTSNUM;J++)
	  {
	   XMLNODEATTS->get_item(J,&XMLNODE);//获得某个属性;
	   CString T1 = (char*)(_bstr_t)XMLNODE->nodeName;
	   CString T2 = (char*)(_bstr_t)XMLNODE->text;
	   MessageBox(T1+" = "+T2);
	  }
	  //MessageBox((_bstr_t)XMLNODE->nodeName+": "+(_bstr_t)XMLNODE->text);
	 }
	 return;
	 //XMLDOC->save("XMLTEST.XML");
	 XMLNODES.Release();
	 XMLNODE.Release();
	 XMLROOT.Release();
	 XMLDOC.Release();
	 ::CoUninitialize();
	CDialog::OnOK();
}
