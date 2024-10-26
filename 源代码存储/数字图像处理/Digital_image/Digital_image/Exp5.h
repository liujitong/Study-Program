#pragma once
#include "afxdialogex.h"
#include<vector>

// Exp5 对话框

class Exp5 : public CDialogEx
{
	DECLARE_DYNAMIC(Exp5)

public:
	Exp5(CWnd* pParent = nullptr);   // 标准构造函数
	std::vector<std::vector<std::vector<BYTE>>> pic;//图片数据
	virtual ~Exp5();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = Experiment5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSy5Openpic();
	afx_msg void OnBnClickedSy5pinghua();
	afx_msg void OnBnClickedSy5xiangqian();
	afx_msg void OnBnClickedSy5kuosan();
	afx_msg void OnBnClickedSy5jubupinghua();
	afx_msg void OnBnClickedSy5jubuxiangqian();
	afx_msg void OnBnClickedSy5jubukuosan();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
