// Exp7.cpp: 实现文件
//

#include "pch.h"
#include "Digital_image.h"
#include "afxdialogex.h"
#include "Exp7.h"

static BOOL ReadBmpImage(CString FileName, std::vector<std::vector<std::vector<BYTE>>> &pic, long &h, long &w)
{
	// 先重新将pic置空
	pic.clear();
	// 读取BMP文件
	char bm[2];
	short bit;
	CFile file;
	int c;
	file.Open(FileName, CFile::modeRead);
	// 打开文件
	file.Read(bm, 2);
	// 读文件信息头
	if (bm[0] != 'B' || bm[1] != 'M')
		return FALSE;
	// 不是BMP文件
	file.Seek(16, CFile::current);
	file.Read(&w, 4);
	// 读图像信息头
	file.Read(&h, 4);
	// 读图像信息头
	file.Seek(2, CFile::current);
	file.Read(&bit, 2);
	// 读图像信息头
	if (bit != 24)
		return FALSE;
	// 不是24位真彩图
	file.Seek(24, CFile::current);
	c = w * 3 % 4;
	pic.resize(3, std::vector<std::vector<BYTE>>(h, std::vector<BYTE>(w)));
	for (int y = h - 1; y >= 0; y--)
	{
		for (int x = 0; x < w; x++)
		{
			for (int k = 2; k >= 0; k--)
			{
				file.Read(&pic[k][y][x], 1); // 读(x,y)处像素RGB存入pic中
			}
		}
		if (c != 0)
			file.Seek(4 - c, CFile::current); // 跳过多余字节
	}
	file.Close(); // 关闭文件
	return TRUE;
}
// 显示图片
static void DispColorImage(CDC *pDC, const std::vector<std::vector<std::vector<BYTE>>> &pic, long h, long w)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			pDC->SetPixel(x, y, RGB(pic[0][y][x], pic[1][y][x], pic[2][y][x]));
		}
	}
}
// 显示灰度图片
static void DispGreyImage(CDC *pDC, const std::vector<std::vector<BYTE>> &pic, long h, long w)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			pDC->SetPixel(x, y, RGB(pic[y][x], pic[y][x], pic[y][x]));
		}
	}
}
// Exp7 对话框

IMPLEMENT_DYNAMIC(Exp7, CDialogEx)

Exp7::Exp7(CWnd* pParent /*=nullptr*/)
	: CDialogEx(Experiment7, pParent)
{
	//初始化jiegouyuansu
	for(int i=0;i<7;i++)
		for(int j=0;j<7;j++)
			jiegouyuansu[i][j] = 1;
}

Exp7::~Exp7()
{
}

void Exp7::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//将IDC_SY7_jiegouyuansu_1到IDC_SY7_jiegouyuansu_7的值与jiegouyuansu对应
	for(int i=0;i<7;i++)
		DDX_CBIndex(pDX, IDC_SY7_jiegouyuansu_1 + i, jiegouyuansu[0][i]);
	//将IDC_SY7_jiegouyuansu_8到IDC_SY7_jiegouyuansu_14的值与jiegouyuansu对应
	for (int i = 0; i < 7; i++)
		DDX_CBIndex(pDX, IDC_SY7_jiegouyuansu_8 + i, jiegouyuansu[1][i]);
	//将IDC_SY7_jiegouyuansu_15到IDC_SY7_jiegouyuansu_21的值与jiegouyuansu对应
	for (int i = 0; i < 7; i++)
		DDX_CBIndex(pDX, IDC_SY7_jiegouyuansu_15 + i, jiegouyuansu[2][i]);
	//将IDC_SY7_jiegouyuansu_22到IDC_SY7_jiegouyuansu_28的值与jiegouyuansu对应
	for (int i = 0; i < 7; i++)
		DDX_CBIndex(pDX, IDC_SY7_jiegouyuansu_22 + i, jiegouyuansu[3][i]);
	//将IDC_SY7_jiegouyuansu_29到IDC_SY7_jiegouyuansu_35的值与jiegouyuansu对应
	for (int i = 0; i < 7; i++)
		DDX_CBIndex(pDX, IDC_SY7_jiegouyuansu_29 + i, jiegouyuansu[4][i]);
	//将IDC_SY7_jiegouyuansu_36到IDC_SY7_jiegouyuansu_42的值与jiegouyuansu对应
	for (int i = 0; i < 7; i++)
		DDX_CBIndex(pDX, IDC_SY7_jiegouyuansu_36 + i, jiegouyuansu[5][i]);
	//将IDC_SY7_jiegouyuansu_43到IDC_SY7_jiegouyuansu_49的值与jiegouyuansu对应
	for (int i = 0; i < 7; i++)
		DDX_CBIndex(pDX, IDC_SY7_jiegouyuansu_43 + i, jiegouyuansu[6][i]);
}


BEGIN_MESSAGE_MAP(Exp7, CDialogEx)
	ON_BN_CLICKED(IDC_SY7_open_grey, &Exp7::OnBnClickedSy7opengrey)
	ON_BN_CLICKED(IDC_SY7_erzhi, &Exp7::OnBnClickedSy7erzhi)
	ON_BN_CLICKED(IDC_SY7_fushi, &Exp7::OnBnClickedSy7fushi)
	ON_BN_CLICKED(IDC_SY7_pengzhang, &Exp7::OnBnClickedSy7pengzhang)
END_MESSAGE_MAP()


// Exp7 消息处理程序
void Exp7::OnBnClickedSy7opengrey()
{
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK) // 定义打开文件对话框对象
	{
		CDC *p = GetDlgItem(IDC_SY7_1)->GetDC(); // 获取图像框句柄
		long h, w;
		// 获取图像路径和文件名
		CString fileN = dlg.GetPathName();
		// 读取图像文件
		if (!ReadBmpImage(fileN, pic, h, w))
		{
			MessageBox(_T("不是24位真彩图"));
			return;
		}
		DispColorImage(p, pic, h, w); // 定义CDC类指针指向图像框
		ReleaseDC(p);
	}
	pic1.clear();
	// 将图片转化为灰度图
	CDC *p = GetDlgItem(IDC_SY7_1)->GetDC(); // 获取图像框句柄
	long h = pic[0].size(), w = pic[0][0].size();
	// 初始化pic1
	pic1.resize(h, std::vector<BYTE>(w));
	// 这里的灰度处理采用基于视觉的方法
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			pic1[y][x] = 0.299 * pic[0][y][x] + 0.587 * pic[1][y][x] + 0.114 * pic[2][y][x];
			pic[0][y][x] = pic1[y][x];
			pic[1][y][x] = pic1[y][x];
			pic[2][y][x] = pic1[y][x];
		}
	}
	DispGreyImage(p, pic1, h, w); // 定义CDC类指针指向图像框
	ReleaseDC(p);
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
}

void Exp7::OnBnClickedSy7erzhi()
{
	//二值化灰度图
	CDC *p = GetDlgItem(IDC_SY7_2)->GetDC(); // 获取图像框句柄
	long h = pic1.size(), w = pic1[0].size();
	// 初始化pic2
	pic2.resize(h, std::vector<BYTE>(w));
	//选择目标灰度IDC_SY7_radio_black
	if(((CButton*)GetDlgItem(IDC_SY7_radio_black))->GetCheck())
	{
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				if (pic1[y][x] > 128)
				{
					pic2[y][x] = 255;
				}
				else
				{
					pic2[y][x] = 0;
				}
				pic[0][y][x] = pic2[y][x];
				pic[1][y][x] = pic2[y][x];
				pic[2][y][x] = pic2[y][x];
			}
		}
	}
	else
	{
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				if (pic1[y][x] > 128)
				{
					pic2[y][x] = 0;
				}
				else
				{
					pic2[y][x] = 255;
				}
				pic[0][y][x] = pic2[y][x];
				pic[1][y][x] = pic2[y][x];
				pic[2][y][x] = pic2[y][x];
			}
		}
	}
	
	DispGreyImage(p, pic2, h, w); // Display the binarized image
	ReleaseDC(p);
	// TODO: 在此添加控件通知处理程序代码
}


void Exp7::OnBnClickedSy7fushi()
{
	//腐蚀二值图
	CDC* p = GetDlgItem(IDC_SY7_2)->GetDC(); // 获取图像框句柄
	long h = pic2.size(), w = pic2[0].size();
	// 初始化pic2
	std::vector<std::vector<BYTE>> pic3 = pic2;
	//腐蚀
	float sum = 0;
	int num = 0;
	//获取结构元素的大小
	int size = 0;
	size = GetDlgItemInt(IDC_SY7_jiegouyuansu_daxiao);
	//结构元素已经在DoDataExchange中初始化
	for (int y = size / 2; y < h - size / 2; y++)
	{
		for (int x = size / 2; x < w - size / 2; x++)
		{
			sum = 0;
			num = 0;
			for (int i = -size / 2; i <= size / 2; i++)
			{
				for (int j = -size / 2; j <= size / 2; j++)
				{
					if (jiegouyuansu[i + size / 2][j + size / 2] == 1)
					{
						sum += pic2[y + i][x + j];
						num++;
					}
				}
			}
			if (sum == 0)
			{
				pic3[y][x] = 0;
			}
			else
			{
				pic3[y][x] = 255;
			}
		}
	}
	//将pic2更新为腐蚀后的图像
	pic2 = pic3;
	DispGreyImage(p, pic2, h, w); // Display the binarized image
	ReleaseDC(p);
	// TODO: 在此添加控件通知处理程序代码
}


void Exp7::OnBnClickedSy7pengzhang()
{
	//膨胀二值图
	CDC* p = GetDlgItem(IDC_SY7_2)->GetDC(); // 获取图像框句柄
	long h = pic2.size(), w = pic2[0].size();
	// 初始化pic2
	std::vector<std::vector<BYTE>> pic3 = pic2;
	//膨胀
	float sum = 0;
	int num = 0;
	//获取结构元素的大小
	int size = 0;
	size = GetDlgItemInt(IDC_SY7_jiegouyuansu_daxiao);
	//结构元素已经在DoDataExchange中初始化
	for (int y = size / 2; y < h - size / 2; y++)
	{
		for (int x = size / 2; x < w - size / 2; x++)
		{
			sum = 0;
			num = 0;
			for (int i = -size / 2; i <= size / 2; i++)
			{
				for (int j = -size / 2; j <= size / 2; j++)
				{
					if (jiegouyuansu[i + size / 2][j + size / 2] == 1)
					{
						sum += pic2[y + i][x + j];
						num++;
					}
				}
			}
			if (sum == num * 255)
			{
				pic3[y][x] = 255;
			}
			else
			{
				pic3[y][x] = 0;
			}
		}
	}
	//将pic2更新为膨胀后的图像
	pic2 = pic3;
	DispGreyImage(p, pic2, h, w); // Display the binarized image
	ReleaseDC(p);
	// TODO: 在此添加控件通知处理程序代码
}

