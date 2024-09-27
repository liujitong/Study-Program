// Exp2.cpp: 实现文件
//

#include "pch.h"
#include "resource.h"
#include "Digital_image.h"
#include "afxdialogex.h"
#include "Exp2.h"

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


// Exp2 对话框

IMPLEMENT_DYNAMIC(Exp2, CDialogEx)

Exp2::Exp2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(Experiment2, pParent)
{

}

Exp2::~Exp2()
{
}

void Exp2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Exp2, CDialogEx)
	ON_BN_CLICKED(IDC_SY2_OPEN, &Exp2::OnBnClickedSy2Open)
	ON_BN_CLICKED(IDC_SY2_Grey, &Exp2::OnBnClickedSy2Grey)
	ON_BN_CLICKED(IDC_SY2_Reserve, &Exp2::OnBnClickedSy2Reserve)
	ON_BN_CLICKED(IDC_SY2_Power_Change, &Exp2::OnBnClickedSy2PowerChange)
	ON_BN_CLICKED(IDC_SY2_SLi, &Exp2::OnBnClickedSy2Sli)
	ON_BN_CLICKED(IDC_SY2_Balance, &Exp2::OnBnClickedSy2Balance)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SY2_Power_No, &Exp2::OnNMCustomdrawSy2PowerNo)
END_MESSAGE_MAP()

void Exp2::OnBnClickedSy2Open() {
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK) //定义打开文件对话框对象
	{
		CDC* p = GetDlgItem(IDC_SY2_image2)->GetDC(); //获取图像框句柄
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

}

void Exp2::OnBnClickedSy2Grey()
{
	if (pic.size() == 0)
	{
		MessageBox(_T("请先打开图片"));
		return;
	}
	pic1.clear();
	//将图片转化为灰度图
	CDC* p = GetDlgItem(IDC_SY2_image2)->GetDC(); //获取图像框句柄
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

void Exp2::OnBnClickedSy2Reserve()
{
	if (pic1.size() == 0)
	{
		MessageBox(_T("请先转化为灰度图"));
		return;
	}
	//获取图像框句柄
	CDC* p = GetDlgItem(IDC_SY2_image3)->GetDC();
	long h = pic1.size(), w = pic1[0].size();
	std::vector<std::vector<BYTE>> pic2 = pic1;
	//反转变化
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			pic2[y][x] = 255 - pic1[y][x];
		}
	}
	DispGreyImage(p, pic2, h, w);
	ReleaseDC(p);

	// TODO: 在此添加控件通知处理程序代码
}

void Exp2::OnBnClickedSy2PowerChange()
{
	if (pic1.size() == 0)
	{
		MessageBox(_T("请先转化为灰度图"));
		return;
	}
	//获取图像框句柄
	CDC* p = GetDlgItem(IDC_SY2_image1)->GetDC();
	long h = pic1.size(), w = pic1[0].size();
	std::vector<std::vector<BYTE>> pic2 = pic1;
	//对图像进行幂次变换
	//幂次选择文本框中的值
	CString str;
	GetDlgItemText(IDC_SY2_EDIT1, str);
	double power = _ttof(str);
	//幂次变换
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			pic2[y][x] = 255 * pow(pic1[y][x] / 255.0, power);
		}
	}
	//显示图像
	DispGreyImage(p, pic2, h, w);
	ReleaseDC(p);
	// TODO: 在此添加控件通知处理程序代码
}

void Exp2::OnBnClickedSy2Sli()
{
	if (pic1.size() == 0)
	{
		MessageBox(_T("请先转化为灰度图"));
		return;
	}
	//获取图像框句柄
	CDC* p = GetDlgItem(IDC_SY2_image4)->GetDC();
	long h = pic1.size(), w = pic1[0].size();
	std::vector<std::vector<BYTE>> pic2 = pic1;
	double a;
	double b;
	double c;
	double d;
	//获取IDC_EDIT_A的值
	a = GetDlgItemInt(IDC_SY2_EDIT_A);
	//获取IDC_SY2EDIT_B的值
	b = GetDlgItemInt(IDC_SY2_EDIT_B);
	//获取IDC_SY2EDIT_C的值
	c = GetDlgItemInt(IDC_SY2_EDIT_C);
	//获取IDC_SY2EDIT_D的值
	d = GetDlgItemInt(IDC_SY2_EDIT_D);
	//对图像进行分段线性变换
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (pic1[y][x] >= 0 && pic1[y][x] < a)
			{
				pic2[y][x] = pic1[y][x] * b / a;
			}
			else if (pic1[y][x] >= a && pic1[y][x] < b)
			{
				pic2[y][x] = (d - c) / (b - a) * (pic1[y][x] - a) + c;
			}
			else if (pic1[y][x] >= b && pic1[y][x] <= 255)
			{
				pic2[y][x] = (255 - d) / (255 - b) * (pic1[y][x] - b) + d;
			}
		}
	}
	//显示灰度图像
	DispGreyImage(p, pic2, h, w);
	ReleaseDC(p);

	// TODO: 在此添加控件通知处理程序代码
}

//灰度直方图计算
static void GetHist(std::vector<std::vector<BYTE>>& pic, int hd[256])
{
	//获取直方图
	for (int i = 0; i < 256; i++)
	{
		hd[i] = 0;
	}
	for (int y = 0; y < pic.size(); y++)
	{
		for (int x = 0; x < pic[0].size(); x++)
		{
			hd[pic[y][x]]++;
		}
	}
}

void Exp2::OnBnClickedSy2Balance()
{
	if (pic1.size() == 0)
	{
		MessageBox(_T("请先转化为灰度图"));
		return;
	}
	//统计每个灰度级的像素个数
	int hd[256];
	GetHist(pic1, hd);
	//统计每个灰度出现的概率
	double p[256];
	for (int i = 0; i < 256; i++)
	{
		p[i] = hd[i] / (pic1.size() * pic1[0].size() * 1.0);
	}
	//计算累积概率
	double c[256];
	c[0] = p[0];
	for (int i = 1; i < 256; i++)
	{
		c[i] = c[i - 1] + p[i];
	}
	//计算均衡化后的灰度值
	int h[256];
	for (int i = 0; i < 256; i++)
	{
		h[i] = 255 * c[i] + 0.5;
	}
	std::vector<std::vector<BYTE>> pic2 = pic1;
	//直方图均衡化, 更新原图每个点的像素值
	for (int y = 0; y < pic1.size(); y++)
	{
		for (int x = 0; x < pic1[0].size(); x++)
		{
			pic2[y][x] = h[pic1[y][x]];
		}
	}
	//显示均衡化后的图像
	CDC* pd = GetDlgItem(IDC_SY2_image1)->GetDC();
	DispGreyImage(pd, pic2, pic1.size(), pic1[0].size());

	//获取均衡化后的直方图
	int hd2[256];
	GetHist(pic2, hd2);

	//绘制直方图
	CDC* p_pre = GetDlgItem(IDC_SY2_image3)->GetDC();//获取图像框句柄，这是绘制的是之前的灰度图
	CDC* p_aft = GetDlgItem(IDC_SY2_image4)->GetDC();//获取图像框句柄，这里绘制的是均衡化后的灰度图
	//绘制直方图
	CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
	CPen pen2(PS_SOLID, 1, RGB(255, 0, 0));
	p_pre->SelectObject(&pen);
	p_aft->SelectObject(&pen2);
	for (int i = 0; i < 256; i++)
	{
		p_pre->MoveTo(i, 255);
		p_pre->LineTo(i, 255 - hd[i]);
		p_aft->MoveTo(i, 255);
		p_aft->LineTo(i, 255 - hd2[i]);
	}
	ReleaseDC(p_pre);
	ReleaseDC(p_aft);
	ReleaseDC(pd);
	// TODO: 在此添加控件通知处理程序代码
}


void Exp2::OnNMCustomdrawSy2PowerNo(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	//将滑动条的值显示在编辑框中，并保留两位小数
	CSliderCtrl* pSlider = (CSliderCtrl*)GetDlgItem(IDC_SY2_Power_No);
	double value = pSlider->GetPos() / 100.0;
	CString str;
	str.Format(_T("%.2f"), value);
	SetDlgItemText(IDC_SY2_EDIT1, str);
}


BOOL Exp2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化
	// 滑动框初始化
	//设置滑动范围(0.05-25)
	CSliderCtrl* pSlider = (CSliderCtrl*)GetDlgItem(IDC_SY2_Power_No);
	pSlider->SetRange(4, 2500);
	//设置初始值
	pSlider->SetPos(150);
	//设置滑动条的刻度
	pSlider->SetTicFreq(1);
	//设置步长
	pSlider->SetLineSize(1);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
