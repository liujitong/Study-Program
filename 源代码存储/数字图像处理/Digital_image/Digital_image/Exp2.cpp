// Exp2.cpp: 实现文件
//

#include "pch.h"
#include "Digital_image.h"
#include "afxdialogex.h"
#include "Exp2.h"

//读取BMP格式图片
static BOOL ReadBmpImage(CString FileName, std::vector<std::vector<std::vector<BYTE>>>& pic, long& h, long& w)
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
	ON_BN_CLICKED(IDC_OPEN, &Exp2::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_Grey, &Exp2::OnBnClickedGrey)
	ON_BN_CLICKED(IDC_Reserve, &Exp2::OnBnClickedReserve)
	ON_BN_CLICKED(IDC_Power_Change, &Exp2::OnBnClickedPowerChange)
	ON_BN_CLICKED(IDC_SLi, &Exp2::OnBnClickedSli)
	ON_BN_CLICKED(IDC_up, &Exp2::OnBnClickedup)
	ON_BN_CLICKED(IDC_down, &Exp2::OnBnClickeddown)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_Power_No, &Exp2::OnNMCustomdrawPowerNo)
END_MESSAGE_MAP()

BOOL Exp2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 滑动框初始化
//设置滑动范围(0.05-25)
	CSliderCtrl* pSlider = (CSliderCtrl*)GetDlgItem(IDC_Power_No);
	pSlider->SetRange(4, 2500);
	//设置初始值
	pSlider->SetPos(150);
	//设置滑动条的刻度
	pSlider->SetTicFreq(1);
	//设置步长
	pSlider->SetLineSize(1);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

// Exp2 消息处理程序


void Exp2::OnBnClickedOpen()
{
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK) //定义打开文件对话框对象
	{
		CDC* p = GetDlgItem(IDC_image2)->GetDC(); //获取图像框句柄
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


void Exp2::OnBnClickedGrey()
{
	//如果pic没有数据，返回，并弹窗：请先打开图片
	if (pic.size() == 0)
	{
		MessageBox(_T("请先打开图片"));
		return;
	}
	//将图片转化为灰度图
	CDC* p = GetDlgItem(IDC_image2)->GetDC(); //获取图像框句柄
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


void Exp2::OnBnClickedReserve()
{
	//如果pic1没有数据，返回，并弹窗：请先转化为灰度图
	if (pic1.size() == 0)
	{
		MessageBox(_T("请先转化为灰度图"));
		return;
	}
	//获取图像框句柄
	CDC* p = GetDlgItem(IDC_image2)->GetDC();
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

}


void Exp2::OnBnClickedPowerChange()
{
	//如果pic1没有数据，返回，并弹窗：请先转化为灰度图
	if (pic1.size() == 0)
	{
		MessageBox(_T("请先转化为灰度图"));
		return;
	}
	//获取图像框句柄
	CDC* p = GetDlgItem(IDC_image2)->GetDC();
	long h = pic1.size(), w = pic1[0].size();
	std::vector<std::vector<BYTE>> pic2 = pic1;
	//对图像进行幂次变换
	//幂次选择文本框中的值
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
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
}


void Exp2::OnBnClickedSli()
{
	//如果pic1没有数据，返回，并弹窗：请先转化为灰度图
	if (pic1.size() == 0)
	{
		MessageBox(_T("请先转化为灰度图"));
		return;
	}
	//获取图像框句柄
	CDC* p = GetDlgItem(IDC_image2)->GetDC();
	long h = pic1.size(), w = pic1[0].size();
	std::vector<std::vector<BYTE>> pic2 = pic1;
	//对图像进行分段线性变换
	if (up_clicked) {
		double a = 80.0;
		double b = 160.0;
		double c = 40.0;
		double d = 200.0;
		//分段线性变换
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
	}
	else if (down_clicked) {
		double a = 40.0;
		double b = 200.0;
		double c = 80.0;
		double d = 160.0;
		//分段线性变换
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
	}
	else {
		//弹窗提示你未选择上升或下降
		MessageBox(_T("请选择上升或下降"));

	}
	//显示灰度图像
	DispGreyImage(p, pic2, h, w);
	ReleaseDC(p);
}


void Exp2::OnBnClickedup()
{
	//设置up_clicked和down_clicked
	up_clicked = true;
	down_clicked = false;
}


void Exp2::OnBnClickeddown()
{
	//设置up_clicked和down_clicked
	up_clicked = false;
	down_clicked = true;
}


void Exp2::OnNMCustomdrawPowerNo(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	//将滑动条的值显示在编辑框中，并保留两位小数
	CSliderCtrl* pSlider = (CSliderCtrl*)GetDlgItem(IDC_Power_No);
	double value = pSlider->GetPos() / 100.0;
	CString str;
	str.Format(_T("%.2f"), value);
	SetDlgItemText(IDC_EDIT1, str);
}



