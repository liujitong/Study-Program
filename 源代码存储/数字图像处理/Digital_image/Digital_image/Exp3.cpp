// Exp3.cpp: 实现文件
//

#include "pch.h"
#include "Digital_image.h"
#include "afxdialogex.h"
#include "Exp3.h"


// Exp3 对话框

IMPLEMENT_DYNAMIC(Exp3, CDialog)

Exp3::Exp3(CWnd* pParent /*=nullptr*/)
	: CDialog(Experiment3, pParent)
{

}

Exp3::~Exp3()
{
}

void Exp3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}
static BOOL ReadBmpImage(CString FileName, std::vector<std::vector<std::vector<BYTE>>>& pic, long& h, long& w)
{
	//先重新将pic置空
	pic.clear();
	//读取BMP文件
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
	pic.resize(3, std::vector<std::vector<BYTE>>(h, std::vector<BYTE>(w)));
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
//显示图片
static void DispColorImage(CDC* pDC, const std::vector<std::vector<std::vector<BYTE>>>& pic, long h, long w)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			pDC->SetPixel(x, y, RGB(pic[0][y][x], pic[1][y][x], pic[2][y][x]));
		}
	}
}
//显示灰度图片
static void DispGreyImage(CDC* pDC, const std::vector<std::vector<BYTE>>& pic, long h, long w)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			pDC->SetPixel(x, y, RGB(pic[y][x], pic[y][x], pic[y][x]));
		}
	}
}

BEGIN_MESSAGE_MAP(Exp3, CDialog)
	ON_BN_CLICKED(IDC_SY3_open, &Exp3::OnBnClickedSy3open)
	ON_BN_CLICKED(IDC_SY3_grey, &Exp3::OnBnClickedSy3grey)
	ON_BN_CLICKED(IDC_SY3_smooth, &Exp3::OnBnClickedSy3smooth)
	ON_BN_CLICKED(IDC_SY3_pow1, &Exp3::OnBnClickedSy3pow1)
	ON_BN_CLICKED(IDC_SY3_pow2, &Exp3::OnBnClickedSy3pow2)
	ON_BN_CLICKED(IDC_SY3_paint, &Exp3::OnBnClickedSy3paint)
	ON_BN_CLICKED(IDC_SY3_sobel, &Exp3::OnBnClickedSy3sobel)
	ON_BN_CLICKED(IDC_SY3_prewitt, &Exp3::OnBnClickedSy3prewitt)
	ON_BN_CLICKED(IDC_SY3_lapulasi8, &Exp3::OnBnClickedSy3lapulasi8)
	ON_BN_CLICKED(IDC_SY3_jiaocha, &Exp3::OnBnClickedSy3jiaocha)
END_MESSAGE_MAP()


// Exp3 消息处理程序


void Exp3::OnBnClickedSy3open()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK) //定义打开文件对话框对象
	{
		CDC* p = GetDlgItem(IDC_SY3_1)->GetDC(); //获取图像框句柄
		long h, w;
		//获取图像路径和文件名
		CString fileN = dlg.GetPathName();
		//读取图像文件
		if (!ReadBmpImage(fileN, pic, h, w))
		{
			MessageBox(_T("不是24位真彩图"));
			return;
		}
		DispColorImage(p, pic, h, w); //定义CDC类指针指向图像框
		ReleaseDC(p);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void Exp3::OnBnClickedSy3grey()
{
	if (pic.size() == 0)
	{
		MessageBox(_T("请先打开图片"));
		return;
	}
	pic1.clear();
	//将图片转化为灰度图
	CDC* p = GetDlgItem(IDC_SY3_1)->GetDC(); //获取图像框句柄
	long h = pic[0].size(), w = pic[0][0].size();
	//初始化pic1
	pic1.resize(h, std::vector<BYTE>(w));
	//这里的灰度处理采用基于视觉的方法
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
	DispGreyImage(p, pic1, h, w); //定义CDC类指针指向图像框
	ReleaseDC(p);
	// TODO: 在此添加控件通知处理程序代码
}


void Exp3::OnBnClickedSy3smooth()
{
	// TODO: 在此添加控件通知处理程序代码
//平滑处理
	if (pic1.size() == 0)
	{
		MessageBox(_T("请先灰度化图片"));
		return;
	}
	std::vector<std::vector<BYTE>> pic2;
	pic2.clear();
	CDC* p = GetDlgItem(IDC_SY3_2)->GetDC(); //获取图像框句柄
	long h = pic1.size(), w = pic1[0].size();
	//初始化pic2
	pic2.resize(h, std::vector<BYTE>(w));
	//平滑处理(3*3均值滤波)
	for (int y = 1; y < h - 1; y++)
	{
		for (int x = 1; x < w - 1; x++)
		{
			pic2[y][x] = (pic1[y - 1][x - 1] + pic1[y - 1][x] + pic1[y - 1][x + 1] + pic1[y][x - 1] + pic1[y][x] + pic1[y][x + 1] + pic1[y + 1][x - 1] + pic1[y + 1][x] + pic1[y + 1][x + 1]) / 9;
		}
	}
	//将平滑后的图片显示在图像框中
	DispGreyImage(p, pic2, h, w); //定义CDC类指针指向图像框
	ReleaseDC(p);
	// TODO: 在此添加控件通知处理程序代码
}


void Exp3::OnBnClickedSy3pow1()
{
	//一阶锐化处理
	if (pic1.size() == 0)
	{
		MessageBox(_T("请sss"));
		return;
	}
	std::vector<std::vector<BYTE>> pic2;
	pic2.clear();
	CDC* p = GetDlgItem(IDC_SY3_3)->GetDC(); //获取图像框句柄
	long h = pic1.size(), w = pic1[0].size();
	//初始化pic2
	pic2.resize(h, std::vector<BYTE>(w));
	//一阶锐化处理
	//获取IDC_SY3_EDIT1-9的值作为滤波器参数1
	CString str;
	GetDlgItem(IDC_SY3_EDIT1)->GetWindowText(str);
	double a = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT2)->GetWindowText(str);
	double b = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT3)->GetWindowText(str);
	double c = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT4)->GetWindowText(str);
	double d = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT5)->GetWindowText(str);
	double e = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT6)->GetWindowText(str);
	double f = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT7)->GetWindowText(str);
	double g = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT8)->GetWindowText(str);
	double h1 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT9)->GetWindowText(str);
	double i = _ttof(str);
	//获取IDC_SY3_EDIT10-18的值作为滤波器参数2
	GetDlgItem(IDC_SY3_EDIT10)->GetWindowText(str);
	double a1 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT11)->GetWindowText(str);
	double b1 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT12)->GetWindowText(str);
	double c1 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT13)->GetWindowText(str);
	double d1 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT14)->GetWindowText(str);
	double e1 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT15)->GetWindowText(str);
	double f1 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT16)->GetWindowText(str);
	double g1 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT17)->GetWindowText(str);
	double h2 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT18)->GetWindowText(str);
	double i1 = _ttof(str);
	//将两个滤波器转为数组
	double filter1[9] = { a,b,c,d,e,f,g,h1,i };
	double filter2[9] = { a1,b1,c1,d1,e1,f1,g1,h2,i1 };

	//一阶锐化处理
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (y < 1 || y >= h - 1 || x < 1 || x >= w - 1)
			{
				pic2[y][x] = pic1[y][x];
				continue;
			}
			float s1 = 0, s2 = 0;
			for (int i = -1; i <= 1; i++)
				for (int j = -1; j <= 1; j++)
				{
					s1 += pic1[y + i][x + j] * filter1[(i + 1) * 3 + j + 1];
					s2 += pic1[y + i][x + j] * filter2[(i + 1) * 3 + j + 1];
				}
			float s = fabs(s1) + fabs(s2);
			if (s > 255)
				s = 255;
			if (s < 0)
				s = 0;
			pic2[y][x] = s;
		}
	}

	//展示
	//将图片显示在图像框中
	DispGreyImage(p, pic2, h, w); //定义CDC类指针指向图像框
	ReleaseDC(p);
	// TODO: 在此添加控件通知处理程序代码
}


void Exp3::OnBnClickedSy3pow2()
{
	//二阶锐化处理
	if (pic1.size() == 0)
	{
		MessageBox(_T("请先灰度化图片"));
		return;
	}
	std::vector<std::vector<BYTE>> pic2;
	pic2.clear();
	CDC* p = GetDlgItem(IDC_SY3_3)->GetDC(); //获取图像框句柄
	long h = pic1.size(), w = pic1[0].size();
	//初始化pic2
	pic2.resize(h, std::vector<BYTE>(w));
	//二阶锐化处理
	//获取IDC_SY3_EDIT1-9的值作为滤波器参数
	CString str;
	GetDlgItem(IDC_SY3_EDIT1)->GetWindowText(str);
	double a = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT2)->GetWindowText(str);
	double b = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT3)->GetWindowText(str);
	double c = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT4)->GetWindowText(str);
	double d = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT5)->GetWindowText(str);
	double e = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT6)->GetWindowText(str);
	double f = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT7)->GetWindowText(str);
	double g = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT8)->GetWindowText(str);
	double h1 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT9)->GetWindowText(str);
	double i = _ttof(str);
	//将滤波器转为数组
	double filter[9] = { a,b,c,d,e,f,g,h1,i };
	//二阶锐化处理
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (y < 1 || y >= h - 1 || x < 1 || x >= w - 1)
			{
				pic2[y][x] = pic1[y][x];
				continue;
			}
			float s = 0;
			for (int i = -1; i <= 1; i++)
				for (int j = -1; j <= 1; j++)
				{
					s += pic1[y + i][x + j] * filter[(i + 1) * 3 + j + 1];
				}
			if (s > 255)
				s = 255;
			if (s < 0)
				s = 0;
			pic2[y][x] = s;
		}
	}
	//展示
//将图片显示在图像框中
	DispGreyImage(p, pic2, h, w); //定义CDC类指针指向图像框
	ReleaseDC(p);
	// TODO: 在此添加控件通知处理程序代码
}


void Exp3::OnBnClickedSy3paint()
{
		//转换成像素画,通过灰度变换，滤波变换，反转变换变成像素画
	if (pic1.size() == 0)
	{
		MessageBox(_T("请先灰度化图片"));
		return;
	}

	std::vector<std::vector<BYTE>> pic2;
	pic2.clear();
	CDC* p = GetDlgItem(IDC_SY3_4)->GetDC(); //获取图像框句柄
	long h = pic1.size(), w = pic1[0].size();
	//初始化pic2
	pic2.resize(h, std::vector<BYTE>(w));
	//交叉梯度滤波
	//获取IDC_SY3_EDIT1-9的值作为滤波器参数1
	CString str;
	GetDlgItem(IDC_SY3_EDIT1)->GetWindowText(str);
	double a = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT2)->GetWindowText(str);
	double b = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT3)->GetWindowText(str);
	double c = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT4)->GetWindowText(str);
	double d = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT5)->GetWindowText(str);
	double e = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT6)->GetWindowText(str);
	double f = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT7)->GetWindowText(str);
	double g = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT8)->GetWindowText(str);
	double h1 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT9)->GetWindowText(str);
	double i = _ttof(str);
	//获取IDC_SY3_EDIT10-18的值作为滤波器参数2
	GetDlgItem(IDC_SY3_EDIT10)->GetWindowText(str);
	double a1 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT11)->GetWindowText(str);
	double b1 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT12)->GetWindowText(str);
	double c1 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT13)->GetWindowText(str);
	double d1 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT14)->GetWindowText(str);
	double e1 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT15)->GetWindowText(str);
	double f1 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT16)->GetWindowText(str);
	double g1 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT17)->GetWindowText(str);
	double h2 = _ttof(str);
	GetDlgItem(IDC_SY3_EDIT18)->GetWindowText(str);
	double i1 = _ttof(str);
	//将两个滤波器转为数组
	double filter1[9] = { a,b,c,d,e,f,g,h1,i };
	double filter2[9] = { a1,b1,c1,d1,e1,f1,g1,h2,i1 };
	//一阶锐化处理
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (y < 1 || y >= h - 1 || x < 1 || x >= w - 1)
			{
				pic2[y][x] = pic1[y][x];
				continue;
			}
			float s1 = 0, s2 = 0;
			for (int i = -1; i <= 1; i++)
				for (int j = -1; j <= 1; j++)
				{
					s1 += pic1[y + i][x + j] * filter1[(i + 1) * 3 + j + 1];
					s2 += pic1[y + i][x + j] * filter2[(i + 1) * 3 + j + 1];
				}
			float s = fabs(s1) + fabs(s2);
			if (s > 255)
				s = 255;
			if (s < 0)
				s = 0;
			pic2[y][x] = s;
		}
	}

	//反转
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			pic2[y][x] = 255 - pic2[y][x];
		}
	}
	//分段线性变换
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (pic2[y][x] < 64)
				pic2[y][x] = 0;
			else if (pic2[y][x] < 128)
				pic2[y][x] = 85;
			else if (pic2[y][x] < 192)
				pic2[y][x] = 170;
			else
				pic2[y][x] = 255;
		}
	}
	//展示
	//将图片显示在图像框中
	DispGreyImage(p, pic2, h, w); //定义CDC类指针指向图像框
	ReleaseDC(p);
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
}

void Exp3::OnBnClickedSy3jiaocha()
{
	//载入交叉梯度滤波器数据给IDC_SY3_EDIT1-9和IDC_SY3_EDIT10-18
//1-9 0 0 0 0 1 0 0 0 -1
	SetDlgItemText(IDC_SY3_EDIT1, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT2, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT3, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT4, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT5, _T("1"));
	SetDlgItemText(IDC_SY3_EDIT6, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT7, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT8, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT9, _T("-1"));
	//10-18 0 0 0 0 1 0 0 -1 0
	SetDlgItemText(IDC_SY3_EDIT10, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT11, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT12, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT13, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT14, _T("1"));
	SetDlgItemText(IDC_SY3_EDIT15, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT16, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT17, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT18, _T("0"));

	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
}


void Exp3::OnBnClickedSy3sobel()
{
	//载入sobel算子
// 1-9 -1 0 1 -2 0 2 -1 0 1
	SetDlgItemText(IDC_SY3_EDIT1, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT2, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT3, _T("1"));
	SetDlgItemText(IDC_SY3_EDIT4, _T("-2"));
	SetDlgItemText(IDC_SY3_EDIT5, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT6, _T("2"));
	SetDlgItemText(IDC_SY3_EDIT7, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT8, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT9, _T("1"));
	//10-18 -1 -2 -1 0 0 0 1 2 1
	SetDlgItemText(IDC_SY3_EDIT10, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT11, _T("-2"));
	SetDlgItemText(IDC_SY3_EDIT12, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT13, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT14, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT15, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT16, _T("1"));
	SetDlgItemText(IDC_SY3_EDIT17, _T("2"));
	SetDlgItemText(IDC_SY3_EDIT18, _T("1"));

	// TODO: 在此添加控件通知处理程序代码
}


void Exp3::OnBnClickedSy3prewitt()
{
	//载入prewitt算子
	// 1-9 -1 -1 -1 0 0 0 1 1 1
	SetDlgItemText(IDC_SY3_EDIT1, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT2, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT3, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT4, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT5, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT6, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT7, _T("1"));
	SetDlgItemText(IDC_SY3_EDIT8, _T("1"));
	SetDlgItemText(IDC_SY3_EDIT9, _T("1"));
	//10-18 -1 0 1 -1 0 1 -1 0 1
	SetDlgItemText(IDC_SY3_EDIT10, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT11, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT12, _T("1"));
	SetDlgItemText(IDC_SY3_EDIT13, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT14, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT15, _T("1"));
	SetDlgItemText(IDC_SY3_EDIT16, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT17, _T("0"));
	SetDlgItemText(IDC_SY3_EDIT18, _T("1"));
	// TODO: 在此添加控件通知处理程序代码
}


void Exp3::OnBnClickedSy3lapulasi8()
{
	//载入2阶拉普拉斯算子
// 1-9 -1 -1 -1 -1 9 -1 -1 -1 -1
	SetDlgItemText(IDC_SY3_EDIT1, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT2, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT3, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT4, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT5, _T("9"));
	SetDlgItemText(IDC_SY3_EDIT6, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT7, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT8, _T("-1"));
	SetDlgItemText(IDC_SY3_EDIT9, _T("-1"));
	// TODO: 在此添加控件通知处理程序代码
}


