// Exp6.cpp: 实现文件
//

#include "pch.h"
#include "Digital_image.h"
#include "afxdialogex.h"
#include "Exp6.h"

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
// Exp6 对话框

IMPLEMENT_DYNAMIC(Exp6, CDialogEx)

Exp6::Exp6(CWnd* pParent /*=nullptr*/)
	: CDialogEx(Experiment6, pParent)
{

}

Exp6::~Exp6()
{
}

void Exp6::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Exp6, CDialogEx)
	ON_BN_CLICKED(IDC_SY6_open, &Exp6::OnBnClickedSy6open)
	ON_BN_CLICKED(IDC_SY6_jingxiang, &Exp6::OnBnClickedSy6jingxiang)
	ON_BN_CLICKED(IDC_SY6_xuanzhuan, &Exp6::OnBnClickedSy6xuanzhuan)
	ON_BN_CLICKED(IDC_SY6_bili, &Exp6::OnBnClickedSy6bili)
END_MESSAGE_MAP()


// Exp6 消息处理程序
void Exp6::OnBnClickedSy6open()
{	
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK) //定义打开文件对话框对象
	{
		CDC* p = GetDlgItem(IDC_SY6_1)->GetDC(); //获取图像框句柄
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
//水平镜像
void shuipingjingxiang(std::vector<std::vector<std::vector<BYTE>>>& pic, long h, long w)
{
	std::vector<std::vector<std::vector<BYTE>> > temp(3, std::vector<std::vector<BYTE>>(h, std::vector<BYTE>(w)));
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			temp[0][y][x] = pic[0][y][w - 1 - x];
			temp[1][y][x] = pic[1][y][w - 1 - x];
			temp[2][y][x] = pic[2][y][w - 1 - x];
		}
	}
	pic = temp;

}
//垂直镜像
void chuizhijingxiang(std::vector<std::vector<std::vector<BYTE>>>& pic, long h, long w)
{
	std::vector<std::vector<std::vector<BYTE>> > temp(3, std::vector<std::vector<BYTE>>(h, std::vector<BYTE>(w)));
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			temp[0][y][x] = pic[0][h - 1 - y][x];
			temp[1][y][x] = pic[1][h - 1 - y][x];
			temp[2][y][x] = pic[2][h - 1 - y][x];
		}
	}
	pic = temp;
}
//水平和垂直镜像
void shuipinghechuizhijingxiang(std::vector<std::vector<std::vector<BYTE>>>& pic, long h, long w) 
{
	std::vector<std::vector<std::vector<BYTE>> > temp(3, std::vector<std::vector<BYTE>>(h, std::vector<BYTE>(w)));
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			temp[0][y][x] = pic[0][h - 1 - y][w - 1 - x];
			temp[1][y][x] = pic[1][h - 1 - y][w - 1 - x];
			temp[2][y][x] = pic[2][h - 1 - y][w - 1 - x];
		}
	}
	pic = temp;
}

void Exp6::OnBnClickedSy6jingxiang()
{
	
	std::vector<std::vector<std::vector<BYTE>>> pic1 = pic;
	//判断IDC_SY6_check_shuiping是否选中
	if (IsDlgButtonChecked(IDC_SY6_check_shuiping))
	{
		shuipingjingxiang(pic1, pic[0].size(), pic[0][0].size());
	}
	//判断IDC_SY6_check_chuizhi是否选中IDC_SY6_check_chuizhi
	if (IsDlgButtonChecked(IDC_SY6_check_chuizhi))
	{
		chuizhijingxiang(pic1, pic[0].size(), pic[0][0].size());
	}
	//判断IDC_SY6_check_shuipinghechuizhi是否选中
	if (IsDlgButtonChecked(IDC_SY6_check_shuipinghechuizhi))
	{
		shuipinghechuizhijingxiang(pic1, pic[0].size(), pic[0][0].size());
	}
	CDC* p = GetDlgItem(IDC_SY6_2)->GetDC();
	DispColorImage(p, pic1, pic1[0].size(), pic1[0][0].size());
	ReleaseDC(p);
	// TODO: 在此添加控件通知处理程序代码
}


void rotation(CDC *p ,std::vector<std::vector<std::vector<BYTE>>>& pic, long h, long w, int angle)
{
	// 计算旋转后的图像尺寸
	double radian = angle * 3.1415926 / 180;
	double sinA = sin(radian);
	double cosA = cos(radian);
	long newW = static_cast<long>(abs(w * cosA) + abs(h * sinA));
	long newH = static_cast<long>(abs(w * sinA) + abs(h * cosA));

	// 创建一个新的背景图像，大小为旋转后的图像尺寸
	std::vector<std::vector<std::vector<BYTE>>> temp(3, std::vector<std::vector<BYTE>>(newH, std::vector<BYTE>(newW, 255))); // 背景为白色

	long x0 = w / 2;
	long y0 = h / 2;
	long newX0 = newW / 2;
	long newY0 = newH / 2;

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			long x1 = static_cast<long>((x - x0) * cosA - (y - y0) * sinA + newX0);
			long y1 = static_cast<long>((x - x0) * sinA + (y - y0) * cosA + newY0);
			if (x1 >= 0 && x1 < newW && y1 >= 0 && y1 < newH)
			{
				temp[0][y1][x1] = pic[0][y][x];
				temp[1][y1][x1] = pic[1][y][x];
				temp[2][y1][x1] = pic[2][y][x];
			}
		}
	}

	// 显示旋转后的图像
	DispColorImage(p, temp, newH, newW);
}

void Exp6::OnBnClickedSy6xuanzhuan()
{
	//获取旋转角度
	int angle = GetDlgItemInt(IDC_SY6_xuanzhuanjiaodu, NULL, FALSE);
	//图像旋转
	CDC* p = GetDlgItem(IDC_SY6_1)->GetDC();
	rotation(p, pic, pic[0].size(), pic[0][0].size(), angle);
	ReleaseDC(p);
	// TODO: 在此添加控件通知处理程序代码
}

//近邻法比例变化
void jinlin(std::vector<std::vector<std::vector<BYTE>>>& pic, long h, long w, double scale,CDC *p)
{
	// 计算变换后的图像尺寸
	long newW = static_cast<long>(w * scale);
	long newH = static_cast<long>(h * scale);

	// 创建一个新的背景图像，大小为变换后的图像尺寸
	std::vector<std::vector<std::vector<BYTE>>> temp(3, std::vector<std::vector<BYTE>>(newH, std::vector<BYTE>(newW, 255))); // 背景为白色

	for (int y = 0; y < newH; y++)
	{
		for (int x = 0; x < newW; x++)
		{
			long oldX = static_cast<long>(x / scale);
			long oldY = static_cast<long>(y / scale);
			if (oldX >= 0 && oldX < w && oldY >= 0 && oldY < h)
			{
				temp[0][y][x] = pic[0][oldY][oldX];
				temp[1][y][x] = pic[1][oldY][oldX];
				temp[2][y][x] = pic[2][oldY][oldX];
			}
		}
	}

	// 显示变换后的图像
	DispColorImage(p, temp, newH, newW);
}
//插值法比例变化
void chazhi(std::vector<std::vector<std::vector<BYTE>>>& pic, long h, long w, double scale,CDC *p)
{
	// 计算变换后的图像尺寸
	long newW = static_cast<long>(w * scale);
	long newH = static_cast<long>(h * scale);

	// 创建一个新的背景图像，大小为变换后的图像尺寸
	std::vector<std::vector<std::vector<BYTE>>> temp(3, std::vector<std::vector<BYTE>>(newH, std::vector<BYTE>(newW, 255))); // 背景为白色

	for (int y = 0; y < newH; y++)
	{
		for (int x = 0; x < newW; x++)
		{
			double oldX = x / scale;
			double oldY = y / scale;
			long x1 = static_cast<long>(oldX);
			long y1 = static_cast<long>(oldY);
			long x2 = x1 + 1;
			long y2 = y1 + 1;
			if (x2 >= w)
				x2 = w - 1;
			if (y2 >= h)
				y2 = h - 1;
			double dx = oldX - x1;
			double dy = oldY - y1;
			for (int k = 0; k < 3; k++)
			{
				double v1 = (1 - dx) * pic[k][y1][x1] + dx * pic[k][y1][x2];
				double v2 = (1 - dx) * pic[k][y2][x1] + dx * pic[k][y2][x2];
				double v = (1 - dy) * v1 + dy * v2;
				temp[k][y][x] = static_cast<BYTE>(v);
			}
		}
	}

	// 显示变换后的图像
	DispColorImage(p, temp, newH, newW);
}

void Exp6::OnBnClickedSy6bili()
{
	//获取缩放比例
	double scale = GetDlgItemInt(IDC_SY6_bilixishu, NULL, FALSE) /100.0;
	//图像缩放
	CDC* p = GetDlgItem(IDC_SY6_3)->GetDC();
	//判断IDC_SY6_radio_jinlin是否选中
	if (IsDlgButtonChecked(IDC_SY6_radio_jinlin))
	{
		jinlin(pic, pic[0].size(), pic[0][0].size(), scale,p);
	}
	//判断IDC_SY6_radio_chazhi是否选中
	if (IsDlgButtonChecked(IDC_SY6_radio_chahzi))
	{
		chazhi(pic, pic[0].size(), pic[0][0].size(), scale,p);
	}
	ReleaseDC(p);

	// TODO: 在此添加控件通知处理程序代码
}

