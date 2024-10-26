#pragma once
#include "afxdialogex.h"
#include <vector>

// Exp7 对话框

class Exp7 : public CDialogEx
{
	DECLARE_DYNAMIC(Exp7)

public:
	Exp7(CWnd* pParent = nullptr);   // 标准构造函数
	std::vector<std::vector<std::vector<BYTE>>> pic; // 图片数据
	std::vector<std::vector<BYTE>> pic1;						 // 灰度图像数据
	std::vector<std::vector<BYTE>> pic2;						 // 二值图像数据
	int jiegouyuansu[7][7];
	virtual ~Exp7();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = Experiment7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSy7opengrey();
	afx_msg void OnBnClickedSy7erzhi();
	afx_msg void OnBnClickedSy7fushi();
	afx_msg void OnBnClickedSy7pengzhang();
};
