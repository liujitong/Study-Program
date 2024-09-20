// Exp1.cpp: 实现文件
//

#include "pch.h"
#include "Digital_image.h"
#include "afxdialogex.h"
#include "Exp1.h"
static BOOL ReadBmpImage(CString FileName, BYTE pic[3][500][500], long& h, long& w)
{
	char bm[2];
	short bit;
	CFile file;
	int c;
	file.Open(FileName, CFile::modeRead);
	//打开文件
	file.Read(bm, 2);
	//读文件信息头
	if (bm[0] != 'B' || bm[1] != 'M')
		return FALSE;
	//不是BMP文件
	file.Seek(16, CFile::current);
	file.Read(&w, 4);
	//读图像信息头
	file.Read(&h, 4);
	//读图像信息头
	file.Seek(2, CFile::current);
	file.Read(&bit, 2);
	//读图像信息头
	if (bit != 24)
		return FALSE;
	//不是24位真彩图
	file.Seek(24, CFile::current);
	c = w * 3 % 4;
	for (int y = h - 1; y >= 0; y--)
	{
		for (int x = 0; x < w; x++)
		{
			for (int k = 2; k >= 0; k--)
			{
				file.Read(&pic[k][y][x], 1); //读(x,y)处像素RGB存入pic中
			}
		}
		if (c != 0)
			file.Seek(4 - c, CFile::current); //跳过多余字节
	}
	file.Close(); //关闭文件
	return TRUE;
}

static void DispColorImage(CDC* pDC, BYTE pic[3][500][500], long h, long w)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			pDC->SetPixel(x, y, RGB(pic[0][y][x], pic[1][y][x], pic[2][y][x]));
		}
	}
}

// Exp1 对话框

IMPLEMENT_DYNAMIC(Exp1, CDialogEx)

Exp1::Exp1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(Experiment1, pParent)
{

}

Exp1::~Exp1()
{
}

void Exp1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Exp1, CDialogEx)
	ON_BN_CLICKED(IDC_OPEN, &Exp1::OnBnClickedOpen)
END_MESSAGE_MAP()


// Exp1 消息处理程序


void Exp1::OnBnClickedOpen()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK) //定义打开文件对话框对象
	{
		CDC* p = GetDlgItem(IDC_image)->GetDC(); //获取图像框句柄
		BYTE pic[3][500][500];
		long h, w;
		//获取图像路径和文件名
		CString fileN = dlg.GetPathName();
		//读取图像文件
		ReadBmpImage(fileN, pic, h, w);
		if (!ReadBmpImage(fileN, pic, h, w))
		{
			MessageBox(_T("不是24位真彩图"));
			return;
		}
		DispColorImage(p, pic, h, w); //定义CDC类指针指向图像框
		ReleaseDC(p);
	}
}
