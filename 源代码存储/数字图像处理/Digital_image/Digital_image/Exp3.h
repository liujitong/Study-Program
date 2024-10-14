#pragma once
#include "afxdialogex.h"
#include <vector>

// Exp3 对话框

class Exp3 : public CDialog
{
	DECLARE_DYNAMIC(Exp3)

public:
	Exp3(CWnd* pParent = nullptr);   // 标准构造函数
	std::vector<std::vector<std::vector<BYTE>>> pic;//图片数据
	std::vector<std::vector<BYTE>> pic1;//灰度图像数据
	virtual ~Exp3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = Experiment3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClicked2();
	afx_msg void OnBnClickedSy3open();
	afx_msg void OnBnClickedSy3grey();
	afx_msg void OnBnClickedSy3smooth();
	afx_msg void OnBnClickedSy3pow1();
	afx_msg void OnBnClickedSy3pow2();
	afx_msg void OnBnClickedSy3paint();
	afx_msg void OnBnClickedSy3sobel();
	afx_msg void OnBnClickedSy3prewitt();
	afx_msg void OnBnClickedSy3lapulasi8();
	afx_msg void OnBnClickedSy3jiaocha();
};
