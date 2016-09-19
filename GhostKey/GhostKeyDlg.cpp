// GhostKeyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GhostKey.h"
#include "GhostKeyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CGhostKeyDlg dialog

CGhostKeyDlg::CGhostKeyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGhostKeyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGhostKeyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGhostKeyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGhostKeyDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGhostKeyDlg, CDialog)
	//{{AFX_MSG_MAP(CGhostKeyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGhostKeyDlg message handlers

BOOL CGhostKeyDlg::OnInitDialog()
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
	CheckDlgButton(IDC_RADIO_DEMO,1);
	CheckDlgButton(IDC_RADIO_MACHINE,1);
	GetDlgItem(IDC_EDIT_YEAR)->SetWindowText("0");
	GetDlgItem(IDC_EDIT_MONTH)->SetWindowText("0");
	GetDlgItem(IDC_EDIT_DAY)->SetWindowText("30");
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGhostKeyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGhostKeyDlg::OnPaint() 
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
HCURSOR CGhostKeyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGhostKeyDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	if(IsDlgButtonChecked(IDC_RADIO_MACHINE))
	{
		FILE *f;
		BYTE preSN[16],SN[16];
		BYTE powerKey [16]= {'I','L','O','V','E','Y','O','U','i','l','o','v','e','y','o','u'};
		f = fopen("License.preKey","r");
		if (f==NULL)
		{
			AfxMessageBox("未找到License.prekey文件");
			return;
		}
		fread(preSN,sizeof(preSN),1,f);
		fclose(f);
		memcpy(SN,preSN,sizeof(preSN));
		//////
		//加密授权码,密匙为computer SN
		BYTE publicKey[12] = {'g','h','o','s','t','p','h','o','e','n','i','x'};
		/*126图谱*/
		BYTE key126[126] = {'x','o','n','a','j','o','n','e',//1
							'h','z','x','i','n','p','h','o',//2
							'e','n','i','x','d','e','m','o',//3
							'2','0','1','4','1','7','t','h',//4
							'i','s','a','v','e','r','y','~',//5
							'k','r','d','w','2','s','k','w',//6
							'a','2','3','d','3','b','q','P',//7
							'b','r','d','w','5','r','f','w',//8
							'd','x','1','|','o','@','s','L',//9
							'c','r','^','w','6','r','D','w',//10
							'e','z','d','h','8','A','k','K',//11
							'a','r','s','w','o','"','V','t',//12
							'h','l','j','%','M','r','k','w',//13
							'X','r','d','w','.',':','a','D',//14
							'r','O','m','A','&','t','@','_',//15
							'a','n','w','o',']','[',//16
							};
		for (int i = 0; i<16; i++)
		{
			powerKey[i] = powerKey[i]^SN[i];
		}
		//取得授权时间
		/*record time*/
		BYTE currentTime[9];

		CTime time = CTime::GetCurrentTime(); 
		currentTime[0] = time.GetYear()-2000;
		currentTime[1] = time.GetMonth();
		currentTime[2] = time.GetDay();
		currentTime[3] = time.GetHour();
		currentTime[4] = time.GetMinute();
		currentTime[5] = time.GetSecond();
		currentTime[6] = GetDlgItemInt(IDC_EDIT_YEAR);
		currentTime[7] = GetDlgItemInt(IDC_EDIT_MONTH);
		currentTime[8] = GetDlgItemInt(IDC_EDIT_DAY);
		//加密126KEY 授权时
		for(i= 0; i<14; i++)
		{
			for(int j =0 ; j < 9; j++)
			{
				key126[i*9 +j] = key126[i*9 +j]^currentTime[j];
			}
	
		}

		//加密computer SN 密匙为 publickey
		for (i =0 ;i< 12; i++)
		{
			SN[i]= preSN[i]^publicKey[i];
		}

		/*release 授权文件*/
		f = fopen("License.ghostkey","w");
		if (f==NULL)
		{
			return;
		}
		fwrite(SN,sizeof(SN),1,f);
		if(IsDlgButtonChecked(IDC_RADIO_COM))
		{
			fwrite(powerKey,sizeof(powerKey),1,f);
		}
		else
		{
			for (i = 0; i<16 ; i++)
			{
				powerKey[i] = 0;
			}
			fwrite(powerKey,sizeof(powerKey),1,f);
		}
		fwrite(key126,sizeof(key126),1,f);/*time*/
		fclose(f);
		AfxMessageBox("生成License.ghostkey文件成功");
	}

}
