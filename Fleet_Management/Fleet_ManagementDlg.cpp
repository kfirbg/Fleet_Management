
// Fleet_ManagementDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Fleet_Management.h"
#include "Fleet_ManagementDlg.h"
#include "afxdialogex.h"
#include "truck.h"
#include "Jeep.h"
#include "Car.h"
#include <vector>
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CFleetManagementDlg dialog

CFleetManagementDlg::CFleetManagementDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FLEET_MANAGEMENT_DIALOG, pParent)
	, _Platform()
	, _Chacic(0)
	, _EngineVolume(0)
	, _Km(0)
	, _LicensType(_T(""))
	, _EngineType(_T(""))
	, _BattaryPower(0)
	, _Truck(FALSE)
	, _Jeep(FALSE)
	, _SUV(FALSE)
	, _PrivateCar(FALSE)
	, _Hybrid(FALSE)
	, _OwnershipJeep(FALSE)
	, _OwnershipPrivateCar(FALSE)
	, ShowInfo(0)
	, DeleteSys(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFleetManagementDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, _Platform);
	DDX_Text(pDX, IDC_EDIT3, _Chacic);
	DDX_Text(pDX, IDC_EDIT2, _EngineVolume);
	DDX_Text(pDX, IDC_EDIT4, _Km);
	DDX_Text(pDX, IDC_EDIT5, _LicensType);
	DDX_Text(pDX, IDC_EDIT7, _EngineType);
	DDX_Text(pDX, IDC_EDIT6, _BattaryPower);
	DDX_Check(pDX, IDC_CHECK1, _Truck);
	DDX_Check(pDX, IDC_CHECK2, _Jeep);
	DDX_Check(pDX, IDC_CHECK3, _SUV);
	DDX_Check(pDX, IDC_CHECK4, _PrivateCar);
	DDX_Check(pDX, IDC_CHECK5, _Hybrid);
	DDX_Check(pDX, IDC_CHECK6, _OwnershipJeep);
	DDX_Check(pDX, IDC_CHECK8, _OwnershipPrivateCar);
	DDX_Control(pDX, IDC_LIST1, _ListBox);
	DDX_Text(pDX, IDC_EDIT10, ShowInfo);
	DDX_Text(pDX, IDC_EDIT9, DeleteSys);
	if (ferstText == false) {
		CString strText;
		strText.Format(_T("Kfir Bagdadi and Erez Dahan."));
		_ListBox.InsertString(0, strText);
		strText.Format(_T("We wish you enjoy the experience of using the system."));
		_ListBox.InsertString(0, strText);
		strText.Format(_T(""));
		_ListBox.InsertString(0, strText);
		strText.Format(_T("The data can be saved/saved as a file in the project folder."));
		_ListBox.InsertString(0, strText);
		strText.Format(_T("license number."));
		_ListBox.InsertString(0, strText);
		strText.Format(_T("An existing vehicle can be displayed/deleted by a"));
		_ListBox.InsertString(0, strText);
		strText.Format(_T("Add/Edit button."));
		_ListBox.InsertString(0, strText);
		strText.Format(_T("To add/update a new vehicle click on the"));
		_ListBox.InsertString(0, strText);
		strText.Format(_T("the three options: Private, SUV or Truck."));
		_ListBox.InsertString(0, strText);
		strText.Format(_T("license number and select the vehicle type according to "));
		_ListBox.InsertString(0, strText);
		strText.Format(_T("In order to add a vehicle you must enter a VIN number, "));
		_ListBox.InsertString(0, strText);
		strText.Format(_T("an existing vehicleand more."));
		_ListBox.InsertString(0, strText);
		strText.Format(_T("adding a vehicle, deleting an existing vehicle, updating "));
		_ListBox.InsertString(0, strText);
		strText.Format(_T("The actions that can be performed in the system are "));
		_ListBox.InsertString(0, strText);
		strText.Format(_T("The system is designed for vehicle fleet management."));
		_ListBox.InsertString(0, strText);
		ferstText = true;
	}
}

BEGIN_MESSAGE_MAP(CFleetManagementDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CFleetManagementDlg::OnBnClickedOk)
	ON_BN_CLICKED(Add_Edit, &CFleetManagementDlg::OnBnClickedEdit)
	ON_BN_CLICKED(TruckS, &CFleetManagementDlg::OnBnClickedTrucks)
	ON_BN_CLICKED(CarS, &CFleetManagementDlg::OnBnClickedCars)
	ON_BN_CLICKED(JeepS, &CFleetManagementDlg::OnBnClickedJeeps)
	ON_BN_CLICKED(delet, &CFleetManagementDlg::OnBnClickeddelet)
	ON_BN_CLICKED(ShowPla, &CFleetManagementDlg::OnBnClickedShowpla)
	ON_BN_CLICKED(Totallists, &CFleetManagementDlg::OnBnClickedTotallists)
	ON_EN_CHANGE(IDC_EDIT7, &CFleetManagementDlg::OnEnChangeEdit7)
	ON_BN_CLICKED(IDC_CHECK3, &CFleetManagementDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(Save, &CFleetManagementDlg::OnBnClickedSave)
	ON_BN_CLICKED(Load, &CFleetManagementDlg::OnBnClickedLoad)
	ON_EN_CHANGE(IDC_EDIT1, &CFleetManagementDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CFleetManagementDlg message handlers

BOOL CFleetManagementDlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFleetManagementDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}

}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFleetManagementDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFleetManagementDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFleetManagementDlg::OnBnClickedOk()
{
	CFleetManagementDlg::OnBnClickedEdit();
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
}

void CFleetManagementDlg::OnBnClickedEdit()
{
	UpdateData(true);
	int count_plat = 0, count_Cha = 0,tmp = _Platform;
	
	if (_EngineType == "") {
		_EngineType = "Petrol";
	}

	if (_LicensType == "") {
		if (_Truck == true && _Jeep == false && _PrivateCar == false) {
			_LicensType = _T("C");
		}
		else if (_Truck == false && _Jeep == true && _PrivateCar == false) {
			_LicensType = _T("B");
		}
		else if (_Truck == false && _Jeep == false && _PrivateCar == true) {
			_LicensType = _T("B");
		}
	}

	for (int i = _Platform; i > 0; i /= 10) {
		count_plat++;
	}
	for (int i = _Chacic; i > 0; i /= 10) {
		count_Cha++;
	}

	if (count_Cha > 9) {
		AfxMessageBox(_T("The VIN number should be up to 9 digits!"), MB_OK | MB_ICONSTOP);
	}
	else if (count_plat < 6 || count_plat > 8) {
		AfxMessageBox(_T("The license number should be between 6-8 numbers!"), MB_OK | MB_ICONSTOP);
	}
	else if (_Chacic == 0) {
		AfxMessageBox(_T("VIN must have a number!"), MB_OK | MB_ICONSTOP);
	}
	else if (_Truck == true && _Jeep == false && _PrivateCar == false) {
		int flag = 0, count = 0;
		bool exists = false;
		truck tmp1(_Platform, _Chacic, _EngineVolume, _Km, _LicensType, _EngineType, _BattaryPower);

		for (auto i = arrcar.begin(); i < arrcar.end(); i++, count++) {
			if (arrcar[count].getPlatform() == _Platform) {
				AfxMessageBox(_T("The License number already exists in car list!"), MB_OK | MB_ICONSTOP);
				exists = TRUE;
			}
		}
		count = 0;
		if (exists == false) {
			for (auto i = arrJeep.begin(); i < arrJeep.end(); i++, count++) {
				if (arrJeep[count].getPlatform() == _Platform) {
					AfxMessageBox(_T("The License number already exists in jeep list!"), MB_OK | MB_ICONSTOP);
					exists = TRUE;
				}
			}
		}
		if (exists == false) {
			if (countTruck == 0) {
				arrTruck.push_back(tmp1);
				countTruck++;
			}
			else {
				for (auto i = countTruck - 1; i > -1; i--) {
					if (arrTruck[i].getPlatform() == _Platform) {
						arrTruck[i] = tmp1;
						flag++;
						i = -1;
					}
				}
				if (flag == 0) {
					arrTruck.push_back(tmp1);
					countTruck++;
				}
			}
			AfxMessageBox(_T("Truck details updated"), MB_OK | MB_ICONASTERISK);
		}
		ShowTruck();
		Reset();
	}
	else if(_Truck == false && _Jeep == true && _PrivateCar == false) {
		int flag = 0, count = 0;
		bool exists = false;
		Jeep tmp2(_Platform, _Chacic, _EngineVolume, _Km, _LicensType, _OwnershipJeep, _SUV);

		for (auto i = arrcar.begin(); i < arrcar.end(); i++, count++) {
			if (arrcar[count].getPlatform() == _Platform) {
				AfxMessageBox(_T("The License number already exists in car list!"), MB_OK | MB_ICONSTOP);
				exists = TRUE;
			}
		}
		count = 0;
		if (exists == false) {
			for (auto i = arrTruck.begin(); i < arrTruck.end(); i++, count++) {
				if (arrTruck[count].getPlatform() == _Platform) {
					AfxMessageBox(_T("The License number already exists in truck list!"), MB_OK | MB_ICONSTOP);
					exists = TRUE;
				}
			}
		}
		if (exists == false) {
			if (countJeep == 0) {
				arrJeep.push_back(tmp2);
				countJeep++;
			}
			else {
				for (auto i = countJeep - 1; i > -1; i--) {
					if (arrJeep[i].getPlatform() == _Platform) {
						arrJeep[i] = tmp2;
						flag++;
						i = -1;
					}
				}
				if (flag == 0) {
					arrJeep.push_back(tmp2);
					countJeep++;
				}
			}
			AfxMessageBox(_T("SUV details updated"), MB_OK | MB_ICONASTERISK);
		}
		ShowJeep();
		Reset();
	}
	else if(_Truck == false && _Jeep == false && _PrivateCar == true) {
		Car tmp3(_Platform, _Chacic, _EngineVolume, _Km, _LicensType, _OwnershipPrivateCar, _Hybrid);
		int flag = 0, count = 0;
		bool exists = false;

		for (auto i = arrJeep.begin(); i < arrJeep.end(); i++, count++) {
			if (arrJeep[count].getPlatform() == _Platform) {
				AfxMessageBox(_T("The License number already exists in SUV list!"), MB_OK | MB_ICONSTOP);
				exists = TRUE;
			}
		}
		count = 0;
		if (exists == false) {
			for (auto i = arrTruck.begin(); i < arrTruck.end(); i++, count++) {
				if (arrTruck[count].getPlatform() == _Platform) {
					AfxMessageBox(_T("The License number already exists in truck list!"), MB_OK | MB_ICONSTOP);
					exists = TRUE;
				}
			}
		}
		if (exists == false) {
			if (countCar == 0) {
				arrcar.push_back(tmp3);
				countCar++;
			}
			else {
				for (auto i = countCar - 1; i > -1; i--) {
					if (arrcar[i].getPlatform() == _Platform) {
						arrcar[i] = tmp3;
						flag++;
						i = -1;
					}
				}
				if (flag == 0) {
					arrcar.push_back(tmp3);
					countCar++;
				}
			}
			AfxMessageBox(_T("Private Car Updated details"), MB_OK | MB_ICONASTERISK);
		}
		ShowCar();
		Reset();
	}
	else {
		AfxMessageBox(_T("Choose one type of vehicle please!"), MB_OK | MB_ICONSTOP);
	}
	// TODO: Add your control notification handler code here
}

void CFleetManagementDlg::ShowTruck() {
	CString strText;
	int count = 0;
	_ListBox.ResetContent();
	for (auto i = arrTruck.begin(); i < arrTruck.end(); i++,count++) {
		strText.Format(_T("License Number: %d"), arrTruck[count].getPlatform());
		_ListBox.AddString(strText);
	}
}

void CFleetManagementDlg::ShowJeep() {
	CString strText;
	int count = 0;
	_ListBox.ResetContent();
	for (auto i = arrJeep.begin(); i < arrJeep.end(); i++, count++) {
		strText.Format(_T("License Number: %d"), arrJeep[count].getPlatform());
		_ListBox.AddString(strText);
	}
}

void CFleetManagementDlg::ShowCar() {
	CString strText;
	int count = 0;
	_ListBox.ResetContent();
	for (auto i = arrcar.begin(); i < arrcar.end(); i++, count++) {
		strText.Format(_T("License Number: %d"), arrcar[count].getPlatform());
		_ListBox.AddString(strText);
	}
}

void CFleetManagementDlg::OnBnClickedTrucks() {
	ShowTruck();
	// TODO: Add your control notification handler code here
}


void CFleetManagementDlg::OnBnClickedCars() {
	ShowCar();
	// TODO: Add your control notification handler code here
}

void CFleetManagementDlg::OnBnClickedJeeps() { 
	ShowJeep();
	// TODO: Add your control notification handler code here
}

void CFleetManagementDlg::OnBnClickeddelet() {
	UpdateData(true);
	int count = 0;
	bool exists = false;
	bool l = false;
	if (DeleteSys != 0) {
		if (arrTruck.size() != 0) {
			while (l == false) {
				auto i = arrTruck.begin();
				if (arrTruck[count].getPlatform() == DeleteSys) {
					arrTruck.erase(i);
					AfxMessageBox(_T("Removed Truck!"), MB_OK | MB_ICONEXCLAMATION);
					exists = TRUE;
					l = true;
				}
				else {
					i++;
					count++;
					if (arrTruck.size() == count) {
						l = true;
					}
				}
			}
		ShowTruck();
		}
		count = 0;
		l = false;
		if (arrJeep.size() != 0) {
			if (exists == false) {
				while (l == false) {
					auto i = arrJeep.begin();
					if (arrJeep[count].getPlatform() == DeleteSys) {
						arrJeep.erase(i);
						AfxMessageBox(_T("Removed SUV!"), MB_OK | MB_ICONEXCLAMATION);
						exists = TRUE;
						l = true;
					}
					else {
						i++;
						count++;
						if (arrJeep.size() == count) {
							l = true;
						}
					}
				}
			}
		ShowJeep();
		}
		count = 0;
		l = false;
		if (arrcar.size() != 0) {
			if (exists == false) {
				while (l == false) {
					auto i = arrcar.begin();
					if (arrcar[count].getPlatform() == DeleteSys) {
						arrcar.erase(i);
						AfxMessageBox(_T("Removed Car!"), MB_OK | MB_ICONEXCLAMATION);
						exists = TRUE;
						l = true;
					}
					else {
						i++;
						count++;
						if (arrcar.size() == count) {
							l = true;
						}
					}
				}
			}
			ShowCar();
		}
		if (exists == false) {
			AfxMessageBox(_T("License not found!"), MB_OK | MB_ICONSTOP);
		}
	}
	else {
		AfxMessageBox(_T("Error!"), MB_OK | MB_ICONSTOP);
	}
	Reset();
	// TODO: Add your control notification handler code here
}

void CFleetManagementDlg::OnBnClickedShowpla() {
	UpdateData(true);
	int count = 0;
	CString strText;
	bool exists = false;
	_ListBox.ResetContent();
	for (auto i = arrTruck.begin(); i < arrTruck.end(); i++, count++) {
		if (arrTruck[count].getPlatform() == ShowInfo) {
			strText.Format(_T("License number: %d"), arrTruck[count].getPlatform());
			_ListBox.AddString(strText);
			strText.Format(_T("VIN: %d"), arrTruck[count].getChassis());
			_ListBox.AddString(strText);
			strText.Format(_T("Engine Volume: %d"), arrTruck[count].getEngine_Volume());
			_ListBox.AddString(strText);
			strText.Format(_T("Km: %d"), arrTruck[count].getKm());
			_ListBox.AddString(strText);
			strText = _T("License Type: ");
			strText += arrTruck[count].getLicense_Type();
			_ListBox.AddString(strText);
			strText.Format(_T("battery power: %d"), arrTruck[count].getBattery_power());
			_ListBox.AddString(strText);
			strText = _T("Engine_Type: ");
			strText += arrTruck[count].getEngine_Type();
			_ListBox.AddString(strText);
			exists = TRUE;
		}
	}
	count = 0;
	if (exists == false) {
		for (auto i = arrJeep.begin(); i < arrJeep.end(); i++, count++) {
			if (arrJeep[count].getPlatform() == ShowInfo) {
				strText.Format(_T("License number: %d"), arrJeep[count].getPlatform());
				_ListBox.AddString(strText);
				strText.Format(_T("VIN: %d"), arrJeep[count].getChassis());
				_ListBox.AddString(strText);
				strText.Format(_T("Engine Volume: %d"), arrJeep[count].getEngine_Volume());
				_ListBox.AddString(strText);
				strText.Format(_T("Km: %d"), arrJeep[count].getKm());
				_ListBox.AddString(strText);
				strText = _T("License Type: ");
				strText += arrJeep[count].getLicense_Type();
				_ListBox.AddString(strText);
				if (arrJeep[count].getownership() == false) {
					strText= _T("Ownership: private");
					_ListBox.AddString(strText);
				}
				else {
					strText = _T("Ownership: leasing");
					_ListBox.AddString(strText);
				}
				if (arrJeep[count].getFoF() == false) {
					strText = _T("SUV: 2X4");
					_ListBox.AddString(strText);
				}
				else {
					strText = _T("SUV: 4X4");
					_ListBox.AddString(strText);
				}
				exists = TRUE;
			}
		}
	}
	count = 0;
	if (exists == false) {
		for (auto i = arrcar.begin(); i < arrcar.end(); i++, count++) {
			if (arrcar[count].getPlatform() == ShowInfo) {
				strText.Format(_T("License number: %d"), arrcar[count].getPlatform());
				_ListBox.AddString(strText);
				strText.Format(_T("VIN: %d"), arrcar[count].getChassis());
				_ListBox.AddString(strText);
				strText.Format(_T("Engine Volume: %d"), arrcar[count].getEngine_Volume());
				_ListBox.AddString(strText);
				strText.Format(_T("Km: %d"), arrcar[count].getKm());
				_ListBox.AddString(strText);
				strText = _T("License Type: ");
				strText += arrcar[count].getLicense_Type();
				_ListBox.AddString(strText);
				if (arrcar[count].getownership() == false) {
					strText = _T("Ownership: private");
					_ListBox.AddString(strText);
				}
				else {
					strText = _T("Ownership: leasing");
					_ListBox.AddString(strText);
				}
				if (arrcar[count].getHybrid() == false) {
					strText = _T("The car is not Hybrid ");
					_ListBox.AddString(strText);
				}
				else {
					strText = _T("The car is Hybrid");
					_ListBox.AddString(strText);
				}
				exists = TRUE;
			}
		}
	}
	Reset();
	// TODO: Add your control notification handler code here
}


void CFleetManagementDlg::OnBnClickedTotallists()
{
	CString strText;
	_ListBox.ResetContent();
	strText.Format(_T("The list of Trucks has: %d Trucks"), arrTruck.size());
	_ListBox.AddString(strText);
	strText.Format(_T("The list of SUVs has: %d SUVs"), arrJeep.size());
	_ListBox.AddString(strText);
	strText.Format(_T("The list of Cars has: %d Cars"), arrcar.size());
	_ListBox.AddString(strText);
	// TODO: Add your control notification handler code here
}

void CFleetManagementDlg::Reset() {
	_Platform = 0;
	_Chacic = 0;
	_EngineVolume = 0;
	_Km = 0;
	_LicensType = _T("");
	_EngineType = (_T(""));
	_BattaryPower = 0;
	_Truck = false;
	_Jeep = false;
	_SUV = false;
	_PrivateCar = false;
	_Hybrid = false;
	_OwnershipJeep = false;
	_OwnershipPrivateCar = false;
	ShowInfo = 0;
	DeleteSys = 0;
	UpdateData(false);
}

void CFleetManagementDlg::OnEnChangeEdit7()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CFleetManagementDlg::OnBnClickedCheck3()
{
	// TODO: Add your control notification handler code here
}

void CFleetManagementDlg::OnBnClickedSave() {
	ofstream inFileTruck("Truck.txt", ios::trunc);
	ofstream inFileCar("Car.txt", ios::trunc);
	ofstream inFilePrivare("Private.txt", ios::trunc);

	if (arrTruck.size() == 0 && arrJeep.size() == 0 && arrcar.size() == 0) {
		AfxMessageBox(_T("You can not save an empty file!"), MB_OK | MB_ICONERROR);
	}
	else {
		int count = 0;
		inFileTruck << arrTruck.size();
		for (auto i = arrTruck.begin(); i < arrTruck.end(); i++, count++) {
			inFileTruck << "_" << arrTruck[count].getPlatform() << "_" << arrTruck[count].getKm() << "_" << arrTruck[count].getEngine_Volume() << "_" << arrTruck[count].getChassis() << "_" << arrTruck[count].getBattery_power() << "_";
			CString CStemp = arrTruck[count].getLicense_Type();
			CT2CA pszConvertedAnsiString(CStemp);
			std::string strStd(pszConvertedAnsiString);
			inFileTruck << strStd << "_";
			CString CStemp2 = arrTruck[count].getEngine_Type();
			CT2CA pszConvertedAnsiString2(CStemp2);
			std::string strStd2(pszConvertedAnsiString2);
			inFileTruck << strStd2 << endl;
		}
		inFileTruck.close();

		count = 0;
		inFileCar << arrcar.size();
		for (auto i = arrcar.begin(); i < arrcar.end(); i++, count++) {
			inFileCar << "_" << arrcar[count].getPlatform() << "_" << arrcar[count].getKm() << "_" << arrcar[count].getEngine_Volume() << "_" << arrcar[count].getChassis() << "_" << arrcar[count].getHybrid() << "_" << arrcar[count].getownership() << "_";
			CString CStemp = arrcar[count].getLicense_Type();
			CT2CA pszConvertedAnsiString(CStemp);
			std::string strStd(pszConvertedAnsiString);
			inFileCar << strStd << endl;
		}
		inFileCar.close();

		count = 0;
		inFilePrivare << arrJeep.size();
		for (auto i = arrJeep.begin(); i < arrJeep.end(); i++, count++) {
			inFilePrivare << "_" << arrJeep[count].getPlatform() << "_" << arrJeep[count].getKm() << "_" << arrJeep[count].getEngine_Volume() << "_" << arrJeep[count].getChassis() << "_" << arrJeep[count].getFoF() << "_" << arrJeep[count].getownership() << "_";
			CString CStemp = arrJeep[count].getLicense_Type();
			CT2CA pszConvertedAnsiString(CStemp);
			std::string strStd(pszConvertedAnsiString);
			inFilePrivare << strStd << endl;
		}
		inFilePrivare.close();

		AfxMessageBox(_T("The data has been saved"), MB_OK | MB_ICONASTERISK);
	}
	// TODO: Add your control notification handler code here
}

void CFleetManagementDlg::OnBnClickedLoad(){
	ifstream outFileTruck("Truck.txt");
	ifstream outFileCar("Car.txt");
	ifstream outFilePrivare("Private.txt");
	int tempInt ,i = 0 ,size = 0, count = 0;
	char k;
	bool l;
	string tempString;

	outFileTruck >> size;
	while (size > i) {
		truck tmp1(_Platform, _Chacic, _EngineVolume, _Km, _LicensType, _EngineType, _BattaryPower);

		outFileTruck.get(k);
		outFileTruck >> tempInt;
		tmp1.setPlatform(tempInt);

		outFileTruck.get(k);
		outFileTruck >> tempInt;
		tmp1.setKm(tempInt);

		outFileTruck.get(k);
		outFileTruck >> tempInt;
		tmp1.setEngine_Volume(tempInt);

		outFileTruck.get(k);
		outFileTruck >> tempInt;
		tmp1.setChassis(tempInt);

		outFileTruck.get(k);
		outFileTruck >> tempInt;
		tmp1.setBattery_power(tempInt);

		outFileTruck.get(k);
		outFileTruck >> k;
		CString tempCString1(k);
		tmp1.setLicense_Type(tempCString1);

		outFileTruck.get(k);
		outFileTruck >> tempString;
		CString tempCString2(tempString.c_str());
		tmp1.setEngine_Type(tempCString2);
	
		arrTruck.push_back(tmp1);
		i++;
		outFileTruck.get(k);
	}
	if (size != 0) {
		outFileTruck.get(k);
		outFileTruck.close();
		ShowTruck();
		count++;
	}

	i = 0;
	outFileCar >> size;
	while (size > i) {
		Car tmp2(_Platform, _Chacic, _EngineVolume, _Km, _LicensType, _EngineType, _BattaryPower);

		outFileCar.get(k);
		outFileCar >> tempInt;
		tmp2.setPlatform(tempInt);

		outFileCar.get(k);
		outFileCar >> tempInt;
		tmp2.setKm(tempInt);

		outFileCar.get(k);
		outFileCar >> tempInt;
		tmp2.setEngine_Volume(tempInt);

		outFileCar.get(k);
		outFileCar >> tempInt;
		tmp2.setChassis(tempInt);

		outFileCar.get(k);
		outFileCar >> l;
		tmp2.setHybrid(l);

		outFileCar.get(k);
		outFileCar >> l;
		tmp2.setownership(l);

		outFileCar.get(k);
		outFileCar >> k;
		CString tempCString1(k);
		tmp2.setLicense_Type(tempCString1);

		arrcar.push_back(tmp2);
		i++;
		outFileCar.get(k);
	}
	if (size != 0) {
		outFileCar.get(k);
		outFileCar.close();
		ShowCar();
		count++;
	}

	i = 0;
	outFilePrivare >> size;
	while (size > i) {
		Jeep tmp3(_Platform, _Chacic, _EngineVolume, _Km, _LicensType, _EngineType, _BattaryPower);

		outFilePrivare.get(k);
		outFilePrivare >> tempInt;
		tmp3.setPlatform(tempInt);

		outFilePrivare.get(k);
		outFilePrivare >> tempInt;
		tmp3.setKm(tempInt);

		outFilePrivare.get(k);
		outFilePrivare >> tempInt;
		tmp3.setEngine_Volume(tempInt);

		outFilePrivare.get(k);
		outFilePrivare >> tempInt;
		tmp3.setChassis(tempInt);

		outFilePrivare.get(k);
		outFilePrivare >> l;
		tmp3.setFoF(l);

		outFilePrivare.get(k);
		outFilePrivare >> l;
		tmp3.setownership(l);

		outFilePrivare.get(k);
		outFilePrivare >> k;
		CString tempCString1(k);
		tmp3.setLicense_Type(tempCString1);

		arrJeep.push_back(tmp3);
		i++;
		outFilePrivare.get(k);
	}
	if (size != 0) {
		outFilePrivare.get(k);
		outFilePrivare.close();
		ShowJeep();
		count++;
	}
	if (count != 0) {
		AfxMessageBox(_T("The data has been load"), MB_OK | MB_ICONASTERISK);
	}
	else {
		AfxMessageBox(_T("There is no save that exists!"), MB_OK | MB_ICONEXCLAMATION);
	}
	// TODO: Add your control notification handler code here
}

void CFleetManagementDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}