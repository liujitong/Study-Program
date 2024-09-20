#pragma once
#include "afxdialogex.h"


// Exp1 对话框

class Exp1 : public CDialogEx
{
	DECLARE_DYNAMIC(Exp1)

public:
	Exp1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Exp1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = Experiment1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpen();
};
