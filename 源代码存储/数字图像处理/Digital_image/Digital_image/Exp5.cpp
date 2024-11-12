// Exp5.cpp: 实现文件
//

#include "pch.h"
#include "Digital_image.h"
#include "afxdialogex.h"
#include "Exp5.h"

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

// Exp5 对话框

IMPLEMENT_DYNAMIC(Exp5, CDialogEx)

Exp5::Exp5(CWnd* pParent /*=nullptr*/)
	: CDialogEx(Experiment5, pParent)
{

}

Exp5::~Exp5()
{
}

void Exp5::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Exp5, CDialogEx)
	ON_BN_CLICKED(IDC_SY5_OpenPic, &Exp5::OnBnClickedSy5Openpic)
	ON_BN_CLICKED(IDC_SY5_pinghua, &Exp5::OnBnClickedSy5pinghua)
	ON_BN_CLICKED(IDC_SY5_xiangqian, &Exp5::OnBnClickedSy5xiangqian)
	ON_BN_CLICKED(IDC_SY5_kuosan, &Exp5::OnBnClickedSy5kuosan)
	ON_BN_CLICKED(IDC_SY5_jubupinghua, &Exp5::OnBnClickedSy5jubupinghua)
	ON_BN_CLICKED(IDC_SY5_jubuxiangqian, &Exp5::OnBnClickedSy5jubuxiangqian)
	ON_BN_CLICKED(IDC_SY5_jubukuosan, &Exp5::OnBnClickedSy5jubukuosan)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// Exp5 消息处理程序
void Exp5::OnBnClickedSy5Openpic()
{
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK) // 定义打开文件对话框对象
	{
		CDC *p = GetDlgItem(IDC_SY5_1)->GetDC(); // 获取图像框句柄
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
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
}

// 1）彩色图像的平滑处理函数：在函数中输出处理图像结果（下同）。IDC_SY5_2显示处理图像结果。
// 2）彩色图像的镶嵌处理函数。IDC_SY5_3显示处理图像结果。
// 3）彩色图像的扩散处理函数。IDC_SY5_4显示处理图像结果。

void Exp5::OnBnClickedSy5pinghua()
{
	// 平滑处理
	std::vector<std::vector<std::vector<BYTE>>> smoothedPic = pic;
	int kernelSize = 3;
	int kernelSum = kernelSize * kernelSize;
	long h = pic[0].size();
	long w = pic[0][0].size();
	long t=GetDlgItemInt(IDC_SY5_mohudaxiao);

	// 根据RadioButton的选择，选择不同的平滑处理方法
	
	if (IsDlgButtonChecked(IDC_SY5_radio_shuiping))
	{
		//如果选择了水平平滑
		for (int k = 0; k < 3; k++) {
			for (int y = 0; y < h; y++)
			{
				for (int x = 0; x < w; x++)
				{
					long s = 0;
					int count = 0;
					for (int i = -t; i <= t; i++)
					{
						int newX = x + i;
						if (newX >= 0 && newX < w)
						{
							s += pic[k][y][newX];
							count++;
						}
					}
					smoothedPic[k][y][x] = static_cast<BYTE>(s / count);

				}
			}
		}
	}
	else if (IsDlgButtonChecked(IDC_SY5_radio_chuizhi))
	{
		//如果选择了垂直平滑
		for (int k = 0; k < 3; k++) {
			for (int y = 0; y < h; y++)
			{
				for (int x = 0; x < w; x++)
				{
					long s = 0;
					int count = 0;
					for (int i = -t; i <= t; i++)
					{
						int newY = y + i;
						if (newY >= 0 && newY < h)
						{
							s += pic[k][newY][x];
							count++;
						}
					}
					smoothedPic[k][y][x] = static_cast<BYTE>(s / count);

				}
			}
		}
	}
	else if (IsDlgButtonChecked(IDC_SY5_radio_sizhou))
	{
        //如果选择了四周平滑
        for (int k = 0; k < 3; k++)
        {
        for (int y = 0; y < h; y++)
        {
        for (int x = 0; x < w; x++)
        {
        long s = 0;
        int count = 0;
        for (int i = -t; i <= t; i++)
        {
        for (int j = -t; j <= t; j++)
        {
        int newY = y + i;
        int newX = x + j;
        if (newY >= 0 && newY < h && newX >= 0 && newX < w)
        {
        s += pic[k][newY][newX];
        count++;
        }
        }
        }
        smoothedPic[k][y][x] = static_cast<BYTE>(s / count);
        }
        }
        }
	}
	else {
		//弹出提示框：请选择平滑处理方法
		MessageBox(_T("请选择平滑处理方法"));
		return;
	}
	CDC *p = GetDlgItem(IDC_SY5_2)->GetDC(); // 获取图像框句柄
	DispColorImage(p, smoothedPic, h, w);			 // 显示平滑处理后的图像
	ReleaseDC(p);
	// TODO: 在此添加控件通知处理程序代码
}


void Exp5::OnBnClickedSy5xiangqian()
{
	//镶嵌处理
	std::vector<std::vector<std::vector<BYTE>>> xiangqianPic = pic;
	long h = pic[0].size();
	long w = pic[0][0].size();
	//获取镶嵌区域长度
	long xiangqianLength = GetDlgItemInt(IDC_SY5_mohudaxiao);
	float g[3];
	//处理
	for (int y = xiangqianLength; y < h - xiangqianLength; y += xiangqianLength)
	{
		for (int x = xiangqianLength; x < w - xiangqianLength; x += xiangqianLength)
		{
			g[0] = 0;
			g[1] = 0;
			g[2] = 0;
			for (int i = -xiangqianLength; i <= xiangqianLength; i++)
			{
				for (int j = -xiangqianLength; j <= xiangqianLength; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						g[k] += pic[k][y + j][x + i];
					}
				}
			}
			for (int k = 0; k < 3; k++)
			{
				g[k] /= (2 * xiangqianLength + 1) * (2 * xiangqianLength + 1);
			}
			for (int i = -xiangqianLength; i <= xiangqianLength; i++)
			{
				for (int j = -xiangqianLength; j <= xiangqianLength; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						xiangqianPic[k][y + j][x + i] = static_cast<BYTE>(g[k]);
					}
				}
			}
		}
	}
	CDC *p = GetDlgItem(IDC_SY5_3)->GetDC(); // 获取图像框句柄
	DispColorImage(p, xiangqianPic, h, w);			 // 显示镶嵌处理后的图像
	ReleaseDC(p);
	// TODO: 在此添加控件通知处理程序代码
}


void Exp5::OnBnClickedSy5kuosan()
{
	//扩散处理
	std::vector<std::vector<std::vector<BYTE>>> kuosanPic = pic;
	long h = pic[0].size();
	long w = pic[0][0].size();
	//获取扩散区域长度
	long kuosanLength = GetDlgItemInt(IDC_SY5_mohudaxiao);
	//处理
	for (int y=kuosanLength;y<h-kuosanLength;y++)
	{
		for (int x=kuosanLength;x<w-kuosanLength;x++)
		{
			int rx=rand()%(2*kuosanLength+1)-kuosanLength;
			int ry=rand()%(2*kuosanLength+1)-kuosanLength;
			for (int k=0;k<3;k++)
			{
				kuosanPic[k][y][x]=pic[k][y+ry][x+rx];
			}
		}
	}
	CDC *p = GetDlgItem(IDC_SY5_4)->GetDC(); // 获取图像框句柄
	DispColorImage(p, kuosanPic, h, w);			 // 显示扩散处理后的图像
	ReleaseDC(p);
	// TODO: 在此添加控件通知处理程序代码
}

int down = 0;
int pinghua = 0;
int xiangqian = 0;
int kuosan = 0;




void Exp5::OnBnClickedSy5jubupinghua()
{
	UpdateData(1);
	down = 1;
	pinghua = 1;
	xiangqian = 0;
	kuosan = 0;
	// TODO: 在此添加控件通知处理程序代码
}


void Exp5::OnBnClickedSy5jubuxiangqian()
{
	
	UpdateData(1);
	down = 1;
	xiangqian = 1;
	pinghua = 0;
	kuosan = 0;
	// TODO: 在此添加控件通知处理程序代码
}


void Exp5::OnBnClickedSy5jubukuosan()
{
	UpdateData(1);
	down = 1;
	kuosan = 1;
	pinghua = 0;
	xiangqian = 0;
	// TODO: 在此添加控件通知处理程序代码
}

void Exp5::OnLButtonDown(UINT nFlags, CPoint point)
{
	//鼠标左键按下的时候，根据平滑大小的数值，对图像进行局部平滑处理
	CDC* p = GetDlgItem(IDC_SY5_1)->GetDC(); // 获取图像框句柄
	long h = pic[0].size();
	long w = pic[0][0].size();
	std::vector<std::vector<std::vector<BYTE>>> smoothedPic = pic;
	int kernelSize = 3;
	int kernelSum = kernelSize * kernelSize;
	long t = GetDlgItemInt(IDC_SY5_pinghuadaxiao);
	if (down == 1)
	{
		if (pinghua == 1) {
			//局部平滑处理
			for (int k = 0; k < 3; k++) {
				for (int y = point.y - t; y <= point.y + t; y++)
				{
					for (int x = point.x - t; x <= point.x + t; x++)
					{
						if (y >= 0 && y < h && x >= 0 && x < w)
						{
							long s = 0;
							int count = 0;
							for (int i = -t; i <= t; i++)
							{
								int newY = y + i;
								for (int j = -t; j <= t; j++)
								{
									int newX = x + j;
									if (newY >= 0 && newY < h && newX >= 0 && newX < w)
									{
										s += pic[k][newY][newX];
										count++;
									}
								}
							}
							smoothedPic[k][y][x] = static_cast<BYTE>(s / count);
						}
					}
				}
			}
		}
		//局部镶嵌处理
		if (xiangqian == 1) {
			for (int y = point.y - t; y <= point.y + t; y++)
			{
				for (int x = point.x - t; x <= point.x + t; x++)
				{
					if (y >= t && y < h - t && x >= t && x < w - t)
					{
						for (int k = 0; k < 3; k++)
						{
							int sum = 0;
							for (int i = -t; i <= t; i++)
							{
								for (int j = -t; j <= t; j++)
								{
									sum += pic[k][y + i][x + j];
								}
							}
							smoothedPic[k][y][x] = sum / ((2 * t + 1) * (2 * t + 1));
						}
					}
				}
			}
		}
		//局部扩散处理
		if (kuosan == 1) {
			for (int y = point.y - t; y <= point.y + t; y++)
			{
				for (int x = point.x - t; x <= point.x + t; x++)
				{
					if (y >= t && y < h - t && x >= t && x < w - t)
					{
						int rx = rand() % (2 * t + 1) - t;
						int ry = rand() % (2 * t + 1) - t;
						for (int k = 0; k < 3; k++)
						{
							smoothedPic[k][y][x] = pic[k][y + ry][x + rx];
						}
					}
				}
			}
		}
	}
	//显示处理后的图像
	pic = smoothedPic;
	DispColorImage(p, smoothedPic, h, w);			 // 显示扩散处理后的图像
	ReleaseDC(p);
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnLButtonDown(nFlags, point);
}