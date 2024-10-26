#pragma once
#include "afxdialogex.h"
#include<vector>

// Exp6 对话框

class Exp6 : public CDialogEx
{
	DECLARE_DYNAMIC(Exp6)

public:
	Exp6(CWnd* pParent = nullptr);   // 标准构造函数
	std::vector<std::vector<std::vector<BYTE>>> pic;//图片数据
	virtual ~Exp6();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = Experiment6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSy6open();
	afx_msg void OnBnClickedSy6jingxiang();
	afx_msg void OnBnClickedSy6xuanzhuan();
	afx_msg void OnBnClickedSy6bili();
};
