#pragma once
#include "afxdialogex.h"
#include<vector>

// Exp4 对话框

class Exp4 : public CDialogEx
{
	DECLARE_DYNAMIC(Exp4)

public:
	Exp4(CWnd* pParent = nullptr);   // 标准构造函数
	std::vector<std::vector<std::vector<BYTE>>> pic;//图片数据
	std::vector<std::vector<BYTE>> pic1;//灰度图像数据s
	virtual ~Exp4();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = Experiment4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSy4Opengrey();
	afx_msg void OnBnClickedSy4shuipingjifen();
	afx_msg void OnBnClickedSy4shuipongweifen();
	afx_msg void OnBnClickedSy4chuizhijifen();
	afx_msg void OnBnClickedSy4chuizhiweifen();
	afx_msg void OnBnClickedSy4tuchu();
};
