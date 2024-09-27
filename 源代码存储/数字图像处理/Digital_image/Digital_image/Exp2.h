#pragma once
#include "afxdialogex.h"
#include <vector>

// Exp2 对话框

class Exp2 : public CDialogEx
{
	DECLARE_DYNAMIC(Exp2)

public:
	Exp2(CWnd* pParent = nullptr);   // 标准构造函数
	std::vector<std::vector<std::vector<BYTE>>> pic;//图片数据
	std::vector<std::vector<BYTE>> pic1;//灰度图像数据
	virtual ~Exp2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = Experiment2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSy2Open();
	afx_msg void OnBnClickedSy2Grey();
	afx_msg void OnBnClickedSy2Reserve();
	afx_msg void OnBnClickedSy2PowerChange();
	afx_msg void OnBnClickedSy2Sli();
	afx_msg void OnBnClickedSy2Balance();
	afx_msg void OnNMCustomdrawSy2PowerNo(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
};
