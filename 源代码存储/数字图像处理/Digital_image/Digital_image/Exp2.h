#pragma once
#include "afxdialogex.h"
#include <vector>

// Exp2 对话框

class Exp2 : public CDialogEx
{
	DECLARE_DYNAMIC(Exp2)

public:
	bool up_clicked = false;//是否点击了增加按钮
	bool down_clicked = false;//是否点击了减少按钮
	Exp2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Exp2();
	std::vector<std::vector<std::vector<BYTE>>> pic;//图片数据
	std::vector<std::vector<BYTE>> pic1;//灰度图像数据

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = Experiment2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpen();
	afx_msg void OnBnClickedGrey();
	afx_msg void OnBnClickedReserve();
	afx_msg void OnBnClickedPowerChange();
	afx_msg void OnBnClickedSli();
	afx_msg void OnBnClickedup();
	afx_msg void OnBnClickeddown();
	afx_msg void OnNMCustomdrawPowerNo(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
};
