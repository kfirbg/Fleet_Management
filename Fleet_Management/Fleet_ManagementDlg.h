
// Fleet_ManagementDlg.h : header file
//

#pragma once
#include <vector>
#include "Car.h"
#include "Jeep.h"
#include "truck.h"

// CFleetManagementDlg dialog
class CFleetManagementDlg : public CDialogEx {
// Construction
public:

	vector<Car>arrcar;
	vector<Jeep>arrJeep;
	vector<truck>arrTruck;

	CFleetManagementDlg(CWnd* pParent = nullptr);	// standard constructor
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FLEET_MANAGEMENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int _Platform;
	int _Chacic;
	int _EngineVolume;
	int _Km;
	CString _LicensType;
	CString _EngineType;
	int _BattaryPower;
	BOOL _Truck;
	BOOL _Jeep;
	BOOL _SUV;
	BOOL _PrivateCar;
	BOOL _Hybrid;
	BOOL _OwnershipJeep;
	BOOL _OwnershipPrivateCar;
	afx_msg void OnBnClickedEdit();
	void ShowTruck();
	void ShowJeep();
	void ShowCar();
	CListBox _ListBox;
	int countTruck = 0;
	int countJeep = 0;
	int countCar = 0;
	afx_msg void OnBnClickedTrucks();
	afx_msg void OnBnClickedCars();
	afx_msg void OnBnClickedJeeps();
	afx_msg void OnBnClickeddelet();
	afx_msg void OnBnClickedShowpla();
	int ShowInfo;
	int DeleteSys;
	afx_msg void OnBnClickedTotallists();
	void Reset();
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedLoad();
	afx_msg void OnEnChangeEdit1();
	bool ferstText = false;
};
