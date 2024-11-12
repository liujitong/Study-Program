// Exp4.cpp: 实现文件
//

#include "pch.h"
#include "Digital_image.h"
#include "afxdialogex.h"
#include "Exp4.h"

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
// Exp4 对话框

IMPLEMENT_DYNAMIC(Exp4, CDialogEx)

Exp4::Exp4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(Experiment4, pParent)
{

}

Exp4::~Exp4()
{
}

void Exp4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Exp4, CDialogEx)
	ON_BN_CLICKED(IDC_SY4_OpenGrey, &Exp4::OnBnClickedSy4Opengrey)
	ON_BN_CLICKED(IDC_SY4_shuipingjifen, &Exp4::OnBnClickedSy4shuipingjifen)
	ON_BN_CLICKED(IDC_SY4_shuipongweifen, &Exp4::OnBnClickedSy4shuipongweifen)
	ON_BN_CLICKED(IDC_SY4_chuizhijifen, &Exp4::OnBnClickedSy4chuizhijifen)
	ON_BN_CLICKED(IDC_SY4_chuizhiweifen, &Exp4::OnBnClickedSy4chuizhiweifen)
	ON_BN_CLICKED(IDC_SY4_tuchu, &Exp4::OnBnClickedSy4tuchu)
END_MESSAGE_MAP()

//水平灰度积分投影
void HIntergralProjection(std::vector<std::vector<BYTE>>& f, RECT r, std::vector<int>& p)
{
    int k = 0;
    for (int y = r.top; y <= r.bottom; y++)
    {
        float s = 0;
        for (int x = r.left; x <= r.right; x++)
        {
            s = s + f[y][x];
        }
        p.push_back(s / (r.right - r.left + 1));
    }
}

//绘制水平灰度投影折线
void DispHProjectuionCurve(CDC* pDC, RECT r, std::vector<int>& p)
{
    pDC->MoveTo(p[0], r.top);
    for (int y = r.top + 1; y <= r.bottom; y++)
        pDC->LineTo(p[y - r.top], y);
}

//垂直积分投影
void VIntergralProjection(std::vector<std::vector<BYTE>>& f, RECT r, std::vector<int>& p)
{
    int k = 0;
    for (int x = r.left; x <= r.right; x++)
    {
        float s = 0;
        for (int y = r.top; y <= r.bottom; y++)
        {
            s = s + f[y][x];
        }
        p.push_back(s / (r.bottom - r.top + 1));
    }
}

//绘制垂直灰度投影折线
void DispVProjectuionCurve(CDC* pDC, RECT r, std::vector<int>& p)
{
    pDC->MoveTo(r.left, p[0]);
    for (int x = r.left + 1; x <= r.right; x++)
        pDC->LineTo(x, p[x - r.left]);
}

//水平微分投影
void HDifferentialProjection(std::vector<std::vector<BYTE>>& f, RECT r, std::vector<int>& p)
{
    int k = 0;
    for (int y = r.top; y <= r.bottom; y++)
    {
        float s = 0;
        for (int x = r.left + 1; x <= r.right; x++)
        {
            if (x - 1 >= 0 && x - 1 < f[y].size())
            {
                s = s + fabs(f[y][x] - f[y][x - 1]);
            }
        }
        p.push_back(static_cast<float>(s) / (r.right - r.left));
    }
}

//垂直微分投影
void VDifferentialProjection(std::vector<std::vector<BYTE>>& f, RECT r, std::vector<int>& p)
{
    //将数组p
    p.resize(r.right - r.left + 1);
    int k = 0;
    for (int x = r.left + 1; x <= r.right; x++)
    {
        float s = 0;
        for (int y = r.top + 1; y <= r.bottom; y++)
            s = s + fabs(f[y][x] - f[y - 1][x]);
        p[k++] = s / (r.bottom - r.top);
    }
}
// Exp4 消息处理程序


void Exp4::OnBnClickedSy4Opengrey()
{
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK) //定义打开文件对话框对象
	{
		CDC* p = GetDlgItem(IDC_SY4_1)->GetDC(); //获取图像框句柄
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
	pic1.clear();
	//将图片转化为灰度图
	CDC* p = GetDlgItem(IDC_SY4_1)->GetDC(); //获取图像框句柄
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


void Exp4::OnBnClickedSy4shuipingjifen()
{
	//获取图像句柄
	CDC* pDC = GetDlgItem(IDC_SY4_2)->GetDC();
	//水平灰度积分投影
	RECT r;
	r.left = 0;
	r.right = pic1[0].size() - 1;
	r.top = 0;
	r.bottom = pic1.size() - 1;
	std::vector<int> p;
	HIntergralProjection(pic1, r, p);
	DispHProjectuionCurve(pDC, r, p);
	ReleaseDC(pDC);
	// TODO: 在此添加控件通知处理程序代码
}


void Exp4::OnBnClickedSy4shuipongweifen()
{
	//水平微分
	CDC* pDC = GetDlgItem(IDC_SY4_3)->GetDC();
	RECT r;
	r.left = 0;
	r.right = pic1[0].size() - 1;
	r.top = 0;
	r.bottom = pic1.size() - 1;
	std::vector<int> p;
	HDifferentialProjection(pic1, r, p);
	DispHProjectuionCurve(pDC, r, p);
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
}


void Exp4::OnBnClickedSy4chuizhijifen()
{
	//垂直积分
	CDC* pDC = GetDlgItem(IDC_SY4_4)->GetDC();
	RECT r;
	r.left = 0;
	r.right = pic1[0].size() - 1;
	r.top = 0;
	r.bottom = pic1.size() - 1;
	std::vector<int> p;
	VIntergralProjection(pic1, r, p);
	DispVProjectuionCurve(pDC, r, p);
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
}


void Exp4::OnBnClickedSy4chuizhiweifen()
{
	//垂直微分
	CDC* pDC = GetDlgItem(IDC_SY4_5)->GetDC();
	RECT r;
	r.left = 0;
	r.right = static_cast<LONG>(pic1[0].size()) - 1;
	r.top = 0;
	r.bottom = static_cast<LONG>(pic1.size()) - 1;

	// 检查pic1是否为空
	if (!pic1.empty() && !pic1[0].empty()) {
		std::vector<int> p;
		VDifferentialProjection(pic1, r, p);
		DispVProjectuionCurve(pDC, r, p);
	}
	// TODO: 在此添加控件通知处理程序代码
}

// 计算曲线最大值函数
int Max(const std::vector<int>& p) {
	int pmax = p[0], max = 0;
	for (size_t k = 1; k < p.size(); k++) {
		if (pmax < p[k]) {
			pmax = p[k];
			max = k;
		}
	}
	return max;
}
// 定位图像显示函数
void DispGrayImage1(CDC* pDC, const std::vector<std::vector<BYTE>>& f, long k, long w) {
	for (int y = k - 15; y < k + 15; y++) {
		for (int x = 0; x < w; x++) {
			pDC->SetPixel(x, y, RGB(f[y][x], f[y][x], f[y][x]));
		}
	}
}
void Exp4::OnBnClickedSy4tuchu()
{
    // TODO: 在此添加控件通知处理程序代码
    CDC* pDC1 = GetDlgItem(IDC_SY4_6)->GetDC();
    CDC* pDC2 = GetDlgItem(IDC_SY4_7)->GetDC();
    RECT r;
    std::vector<int> p2;
    //初始化r
    r.left = 0;
    r.right = pic1[0].size() - 1;
    r.top = 0;
    r.bottom = pic1.size() - 1;
    //水平微分
    HDifferentialProjection(pic1, r, p2);
    int max_value = Max(p2);
    r.left = 0;
    r.right = pic1[0].size() - 1;
    r.top = max_value - 2;
    r.bottom = max_value + 2;
    DispGrayImage1(pDC1, pic1, max_value, pic1[0].size());
    std::vector<int> q2;
    VDifferentialProjection(pic1, r, q2);
    DispVProjectuionCurve(pDC2, r, q2);
    ReleaseDC(pDC1);
    ReleaseDC(pDC2);
	// TODO: 在此添加控件通知处理程序代码
}
