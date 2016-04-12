// controlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "control.h"
#include "end.h"
#include "controlDlg.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
	int i=0;//黑名单数，全局变量



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
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
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

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyDlg::OnPaint() 
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
		//CDialog::OnPaint();
		CPaintDC   dc(this);   
CRect   rect;   
GetClientRect(&rect);   
CDC   dcMem;   
dcMem.CreateCompatibleDC(&dc);   
CBitmap   bmpBackground;   
bmpBackground.LoadBitmap(IDB_BITMAP1);   
BITMAP   bitmap;   
bmpBackground.GetBitmap(&bitmap);   
CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);   
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnButton2() //设置黑名单
{
	// TODO: Add your control notification handler code here
    BROWSEINFO bi;                     //BROWSEINFO结构有很多成员参数可以自己设置  
    ZeroMemory(&bi,sizeof(BROWSEINFO));     //将以&bi为起始地址，大小为sizeof(BRuiOWSEINFO)的内存区域用0填充  
    //bi.ulFlags=BIF_BROWSEINCLUDEFILES;        //设置弹出的对话框属性。此处意思为包含文件。如果不设这个值，默认的是只有文件夹。ulFlags还可以定义很多别的属性  
    //bi.ulFlags=BIF_NEWDIALOGSTYLE;            //窗口可以调整大小，有新建文件夹按钮
	LPCTSTR lps="指定黑名单";
    bi.lpszTitle=lps;			    //在窗口内显示提示用户的语
	bi.ulFlags=BIF_BROWSEINCLUDEFILES;		//显示的不只是文件夹
    LPITEMIDLIST pidl=SHBrowseForFolder(&bi);   //Displays a dialog box enabling the user to select a Shell folder.  
    TCHAR*path =new TCHAR[MAX_PATH];  
    if(pidl!=NULL)  
    {  
		i+=1;
       SHGetPathFromIDList(pidl,path);      //Converts an item identifier list to a file system path  
       //MessageBox(path);  
		//ifstream infile;
	   ofstream outfile("path.txt",ios::in|ios::app);//把黑名单的路径记入path.txt
		outfile<<path<<endl;
		outfile.close();
		/*infile.open("path.txt",ios::in);//错的，不要管它
		infile>>path;
		infile.close();*/
    }  
}




//开始的play函数
/*char* hmd[100];
int hmd_num = 0;
int ds = 2700;
char c[1000];
void play(){
	time_t st = time(NULL);
	int i,j;
	int mark = ds;
	while(1){
		time_t tmpt = time(NULL);
		if(abs(difftime(tmpt,st)) >= ds)
			return ;
		for(i = 0; i < hmd_num;++i){
			int tmpn = 0;
			for(j = 0;j < strlen(hmd[i]);++j){
				if(hmd[i][j]=='\\'){
					tmpn = j;
				}
			}
			for(j = tmpn + 1;j < strlen(hmd[i]);++j)
				c[j - tmpn - 1] = hmd[i][j];
			c[strlen(hmd[i]) - tmpn - 1] = '\0';
			CString tmps(c);
			CloseProgram(tmps);
		}
		Sleep(1000);
	}
}
*/
string hmd[100];//出现“未响应”之后修改了play函数和button
int hmd_num = 0;
int ds = 2700;
time_t st;
int play()
{
	while(1)
	{
		time_t tmpt = time(NULL);
	//	MessageBox(NULL,"OK","ok",0);
		if(abs(difftime(tmpt,st)) >= ds)
			return -1;
		char tc[2];
		tc[0]='0'+hmd_num;
		//MessageBox(NULL,tc,"ok",0);
		for(int i = 0; i < hmd_num;++i)
		{
		//	MessageBox(NULL,"OK1","ok1",0);
			char c[1000];
			int tmpn = 0,len = hmd[i].length();
			for(int j = 0;j < len;++j)
			{
				if(hmd[i][j]=='\\')
				{
					tmpn = j;
				}
			}
			for(int jj = tmpn + 1;jj < len;++jj)
				c[jj - tmpn - 1] = hmd[i][jj];
			c[len - tmpn - 1] = '\0';
		//	MessageBox(NULL,c,c,0);
			CString tmps(c);
			CloseProgram(tmps);
		}
		Sleep(1000);
	}
	return 0;
}
static UINT myfunc(LPVOID lpParam)
{
	int a = play();
//	AfxEndThread();
	return a;
}



void CMyDlg::OnButton1() //"开始码代码"的按钮代码
{
	st = time(NULL);
	ifstream infile("path.txt");
	//infile.open("path.txt",ios::in);
	hmd_num=0;
//	infile>>hmd[0];
	while(infile >> hmd[hmd_num++]);
	infile.close();
//play();														这是之前没改的时候
	//	char tc[2];
	//	tc[0]='0'+hmd_num;
		//MessageBox(tc,"ok",0);
	CWinThread* mythread = AfxBeginThread(myfunc,NULL,0,0,0);	//改了之后
    mythread->Run();
}






void CMyDlg::OnButton3() //清空黑名单，就是清空path.txt
{
	// TODO: Add your control notification handler code here
	ofstream outfile("path.txt",ios::trunc);
	hmd_num=0;
}

