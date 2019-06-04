/*
	Danh sách thành viên:
	1. Nguyễn Cao Quốc Hùng_18211TT2359
	2.Nguyễn Phúc Bích_18211TT3761
	3. Nguyễn Đăng Khôi_ 18211TT1015
	4.Trần Diệp Vũ _ 18211TT
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <Windows.h>
#include <list>
#include "Admin.h"
#include "GiaoVien.h"
#include "SinhVien.h"
#include "PhieuMuon.h"
#include "Sach.h"
using namespace std;
int PhieuMuon::nTongPM = 0; // khai báo biến tĩnh tổng phiếu mượn
void textColor(WORD color); // hàm chỉnh màu 
string passwordInput(unsigned maxLength); // hàm mã hóa mật khẩu 
//ADMIN
void docFile_ADMIN(list <Admin> &L); // đọc từ file admin 
void login_Admin(list <Admin> L, list <Sach> L3, list <BanDoc*> L2, list <PhieuMuon> L4); /
//BẠN ĐỌC
void docFile_BANDOC(list <BanDoc*> &L2); // đọc từ file bạn đọc 
void output_BANDOC(list <BanDoc*> L2); // xuất ra màn hình 
void timKiemBanDoc(list <BanDoc*> L2); // hàm tìm kiếm bạn đọc 
void themBanDoc(list <BanDoc*> &L2);// hàm thêm bạn đọc 
//SÁCH
void docFile_SACH(list <Sach> &L3); // đọc từ file sách 
void output_SACH(list <Sach> L3); // xuất ra màn hình 
void outputFile(list <Sach> L3); // xuất ra file 
void themSach(list <Sach> &L3); // thêm sách
int dem_Tong_So_Sach_Hien_Co(list <Sach> L3); // đếm tổng sách hiện có 
void timKiem(list <Sach> L3); // tìm kiếm sách 
//PHIẾU MƯỢN
void docFile_PHIEUMUON(list <PhieuMuon> &L4); // đọc từ file phiếu mượn
void output_PHIEUMUON(list <PhieuMuon> L4); // xuất ra màn hình phiếu mượn 
//Chương trình chính
void main()
{ 
	list <Admin> L1;         // cho List Admin L1
	list <BanDoc*> L2;       // cho List Bandoc L1
	list <Sach> L3;          // cho List Sach L1
	list <PhieuMuon> L4;     // cho List PhieuMuon L1
	
	docFile_ADMIN(L1);       // truyền hàm đọc file admin
	docFile_BANDOC(L2);		// truyền hàm đọc file bạn đọc
	docFile_SACH(L3);		// truyền hàm đọc file sách
	docFile_PHIEUMUON(L4);	// truyền hàm đọc file phiếu mượn
	int nChucNangMenu = 0;
	textColor(4);
	while (true)
	{
		system("cls");
		textColor(8);
		cout << "\t\t\t_______________QUAN LI THU VIEN____________\n";
		cout << "\t\t\t*******************************************\n";
		cout << "\t\t\t  1. Hien thi thong tin sach.              \n";
		cout << "\t\t\t  2. Hien thi thong tin ban doc.           \n";
		cout << "\t\t\t  3. Tim kiem thong tin.                   \n";
		cout << "\t\t\t  4. Quan ly.                              \n";
		cout << "\t\t\t  0. Thoat!                                \n";
		cout << "\t\t\t*******************************************\n";
		textColor(6);
		cout << "\t\t   Nhap Lua Chon: ";
		cin >> nChucNangMenu;
		if (nChucNangMenu != 1 && nChucNangMenu != 2 && nChucNangMenu != 3 && nChucNangMenu != 4 && nChucNangMenu != 0)
		{
			cout << "Nhap sai vui long lua chon lai.\n";
			system("pause");
		}
		else if (nChucNangMenu == 1)
		{
			cout << "\n\t\t*Hien thi thong tin sach. *\n";
			output_SACH(L3);  // xuất ra màn hình 
			system("pause");
		}
		else if (nChucNangMenu == 2)
		{
			cout << "\n\t\t*Hien thi thong tin ban doc.*\n";
			output_BANDOC(L2);
			system("pause");
		}
		else if (nChucNangMenu == 3)
		{
			cout << "\n\t\t*Tim kiem thong tin.*\n";
			while (true)
			{
				system("cls");
				cout << "\t\t*******************************************\n";
				cout << "\t\t  1. Tim sach theo ma sach.                \n";
				cout << "\t\t  2. Tim ban doc theo ma ban doc.          \n";
				cout << "\t\t  0. Thoat!                                \n";
				cout << "\t\t*******************************************\n";
				cout << "\t\t   Nhap Lua Chon: ";
				cin >> nChucNangMenu;
				if (nChucNangMenu != 1 && nChucNangMenu != 2 && nChucNangMenu != 0)
				{
					cout << "Nhap sai vui long lua chon lai.\n";
					system("pause");
				}
				else if (nChucNangMenu == 1)
				{
					cout << "\t\t*Tim sach theo ma sach*\n";
					timKiem(L3); // tìm kiếm sách 
					system("pause");
				}
				else if (nChucNangMenu == 2)
				{
					cout << "\t\t*Tim ban doc theo ma ban doc*\n";
					timKiemBanDoc(L2); // hàm tìm kiếm bạn đọc 
					system("pause");
				}
				else if (nChucNangMenu == 0)
				{
					break;
				}
			}
			system("pause");
		}
		else if (nChucNangMenu == 4)
		{
			login_Admin(L1, L3, L2, L4); 
			system("pause");
		}
		else if (nChucNangMenu == 0)
		{
			break;
		}
	}
	system("pause");
}
string passwordInput(unsigned maxLength) // hàm mã hóa mật khẩu 
{
	string pw = "";
	for (char c; (c = _getch()); )
	{
		if (c == '\n' || c == '\r') { // \n là phím phím enter + \r là Nhảy về đầu hàng, không xuống hàng
			cout << "\n";
			break;
		}
		else if (c == '\b') { //phím backspace
			cout << "\b \b";
			if (!pw.empty()) pw.erase(pw.size() - 1);
		}
		else if (c == -32)//phím mũi tên
		{
			_getch();//bỏ qua kí tự tiếp theo (hướng mũi tên)
		}
		else if (isprint(c) && pw.size() < maxLength) { //isprint tức là chỉ nhận những ký tự in ra được (có tính khoảng trắng)
			cout << '*'; 
			pw += c;
		}
	}
	return pw;
}
void textColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
} // màu
//ADMIN
void login_Admin(list <Admin> L, list <Sach> L3, list <BanDoc*> L2, list <PhieuMuon> L4) // đăng nhập 
{
	int nChucNangMenu = 0;
	string sUserName = "";
	string sPassWord = "";
	int flag = 0;
	while (true)
	{
		system("cls");
		cout << "\t\t************************************\n";
		textColor(10);
		cout << "\t\t*              Login               *\n";
		textColor(7);
		cout << "\t\t************************************\n";
		textColor(4);
		cout << "\t\t Nhap \"ESC\" de thoat!\n";
		textColor(7);
		cout << "\n\t\tNhap Username: ";
		rewind(stdin);
		getline(cin, sUserName);
		cout << "\n\t\tNhap PassWord: ";
		sPassWord = passwordInput(6); // hàm mã hóa mật khẩu 
		
		if (sUserName == "ESC" || sUserName == "esc")
		{
			flag = 1;
			break;
		}
		list <Admin>::iterator p = L.begin();
		while (p != L.end())
		{
			if (sUserName == p->getUser() && sPassWord == p->getPass())
			{
				flag = 1;
				cout << "Dang nhap thanh cong !\n";
				while (true)
				{
					system("cls");
					cout << "\t\t******************* ADMIN *****************\n";
					cout << "\t\t  1. Quan ly phieu muon.                   \n";
					cout << "\t\t  2. Quan ly sach.                         \n";
					cout << "\t\t  3. Them ban doc.                         \n";
					cout << "\t\t  0. Thoat!                                \n";
					cout << "\t\t*******************************************\n";
					cout << "\t   Nhap Lua Chon: ";
					cin >> nChucNangMenu;
					if (nChucNangMenu != 1 && nChucNangMenu != 2 && nChucNangMenu != 3 && nChucNangMenu != 0)
					{
						cout << "Nhap sai !!! .\n";
						system("pause");
					}
					else if (nChucNangMenu == 1)
					{
						cout << "\t\t*Quan ly phieu muon*\n";
						while (true)
						{
							system("cls");
							cout << "\t\t******************************************\n";
							cout << "\t\t											 \n";
							cout << "\t\t  1. Xuat danh dach phieu muon            \n";
							cout << "\t\t  0. Thoat!                               \n";
							cout << "\t\t******************************************\n";
							cout << "\t\t   Nhap Lua Chon: ";
							cin >> nChucNangMenu;

							if (nChucNangMenu == 1)
							{
								output_PHIEUMUON(L4);
								system("pause");
							}
							else if (nChucNangMenu == 0)
							{
								break;
							}
							else
							{
								cout << "\t\tNhap sai vui long lua chon lai.\n";
								system("pause");
							}
						}
					}
					else if (nChucNangMenu == 2)
					{
						cout << "2. Quan ly sach.\n";
						while (true)
						{
							system("cls");
							cout << "\t\t********Quan Ly Sach********\n";
							cout << "\t\t      1. Them sach moi.     \n";
							cout << "\t\t      0. Thoat!             \n";
							cout << "\t\t****************************\n";
							cout << "\t\tNhap chuc nang can chon: ";
							cin >> nChucNangMenu;
							if (nChucNangMenu != 1 && nChucNangMenu != 2 && nChucNangMenu != 0)
							{
								cout << "\t\tNhap sai vui long lua chon lai.\n";
								system("pause");
							}
							else if (nChucNangMenu == 1)
							{
								themSach(L3);  // thêm sách 
								outputFile(L3); //xuất ra file 
								system("pause");
							}

							else if (nChucNangMenu == 0)
							{
								break;
							}
						}

						system("pause");
					}
					else if (nChucNangMenu == 3)
					{
						cout << "\t\t******Them ban doc*********\n";
						themBanDoc(L2); // hàm thêm bạn đọc 
					}

					else if (nChucNangMenu == 0)
					{
						break;
					}
				}
				system("pause");
			}
			p++;
		}
		if (flag == 0)
		{
			cout << "Nhap sai! Vui Long nhap lai.";
			system("pause");
		}
	}

}
void docFile_ADMIN(list <Admin> &L) //đọc từ file admin
{
	ifstream fcin;
	fcin.open("Admin.txt");
	while (!fcin.eof()) //end of file
	{
		Admin Admin;
		string u = "";
		string p = "";
		getline(fcin, u, ',');
		Admin.setUser(u);
		getline(fcin, p);
		Admin.setPass(p);
		L.push_back(Admin);
		fcin.ignore(0, '\n');
	}
	fcin.close();

}
//BẠN ĐỌC
void themBanDoc(list <BanDoc*> &L2) // hàm thêm bạn đọc 
{
	int nLoaiBD = 0;
	string sMaBD = "";
	string sHoTen = "";
	string sKhoa = "";
	int nNgay = 0;        
	int nThang = 0;    
	int nNam = 0;  
	string sDC = "";
	string sSDT = "";
	int nKhoaHoc = 0;
	while (true)
	{
		system("cls");
		cout << "\t\t\t*************************************\n";
		cout << "\t\t\t  1. Them ban doc Giao Vien          \n";
		cout << "\t\t\t  2. Them ban doc Sinh Vien          \n";
		cout << "\t\t\t  0. Thoat!                          \n";
		cout << "\t\t\t*************************************\n";
		cout << "\t\t\t Nhap chuc nang: ";
		cin >> nLoaiBD;
		if (nLoaiBD == 1) // thêm bạn đọc là giáo viên
		{
			
			nLoaiBD = 1;
			string str = "";
			cout << "\t\tnhap ma ban doc:"; rewind(stdin); getline(cin, str);
			sMaBD = "GV" + str;
			cout << "\t\tNhap ho va ten: "; rewind(stdin); getline(cin, sHoTen);
			cout << "\t\tNhap Khoa: "; rewind(stdin); getline(cin, sKhoa);
			cout << "\t\tNhap dia chi: "; rewind(stdin); getline(cin, sDC);
			cout << "\t\tNhap so dien thoai: "; rewind(stdin); getline(cin, sSDT);
			cout << "\t\tnhap ngay:"; cin >> nNgay;
			cout << "\t\tnhap thang:"; cin >> nThang;
			cout << "\t\tnhap nam:"; cin >> nNam;
			BanDoc * gv = new GiaoVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, sDC, sSDT);
			L2.push_back(gv);
			ofstream File;
			File.open("BanDoc.txt", ios::app);
			File << "\n" << nLoaiBD << "," << sMaBD << "," << sHoTen << "," << sKhoa << ","<<nNgay<<","<<nThang<<"," << nNam << "," << sDC << "," << sSDT;
			File.close();
			textColor(10);
			cout << "\t\tThem ban doc thanh cong!\n ";
			textColor(7);
			system("pause");
			break;
		}
		else if (nLoaiBD == 2)
		{
			nLoaiBD = 2;
			string str;
			cout << "\t\tnhap ma ban doc:"; rewind(stdin); getline(cin, str);
			sMaBD = "SV" + str;
			cout << "\t\tNhap ho va ten: "; rewind(stdin); getline(cin, sHoTen);
			cout << "\t\tNhap Khoa: "; rewind(stdin); getline(cin, sKhoa);
			cout << "\t\tNhap Khoa Hoc: "; cin >> nKhoaHoc;
			cout << "\t\tnhap ngay:"; cin >> nNgay;
			cout << "\t\tnhap thang:"; cin >> nThang;
			cout << "\t\tnhap nam:"; cin >> nNam;
			BanDoc *  sv = new SinhVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, nKhoaHoc);
			L2.push_back(sv);
			ofstream File;
			File.open("BanDoc.txt", ios::app);
			File << "\n" << nLoaiBD << "," << sMaBD << "," << sHoTen << "," << sKhoa << "," << nNgay << "," << nThang << "," << nNam << "," << nKhoaHoc;
			File.close();
			textColor(10);
			cout << "\t\tThem ban doc thanh cong!\n ";
			textColor(7);
			system("pause");
			break;
		}
		else if (nLoaiBD == 0)
		{
			break;
		}
		else
		{
			cout << "Nhap sai! Vui long nhap lai. \n";
		}
	}
}
void timKiemBanDoc(list <BanDoc*> L2) // hàm tìm kiếm bạn đọc 
{
	string sMBD = "";
	textColor(4);
	cout << "\t\t\tNhap N de thoat!\n";
	textColor(7);
dd:
	list <BanDoc*>::iterator p = L2.begin();
	cout << "\t\tNhap ma ban doc can tim thong tin: ";
	cin >> sMBD;
	if (sMBD == "N")
	{
		textColor(10);
		cout << "\t\t\tBan da chon thoat!\n";
		textColor(7);
		return;
	}
	while (p != L2.end())
	{
		if (sMBD == (*p)->getMBD())
		{
			(*p)->output();
			return;
		}
		p++;
	}
	textColor(4);
	cout << "\t\t\tMa ban doc khong ton tai!\n";
	textColor(7);
	goto dd;
}
void output_BANDOC(list <BanDoc*> L2) // xuất ra màn hình
{
	list <BanDoc*> ::iterator p = L2.begin();
	while (p != L2.end())
	{
		(*p)->output();
		p++;
	}
}
void docFile_BANDOC(list <BanDoc*> &L2)
{
	int nLoai = 0;
	string sMaBD = "";
	string sHoTen = "";
	string sKhoa = "";
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	string sDC = "";
	string sSDT = "";
	int nKhoaHoc = 0;
	ifstream File;
	File.open("BanDoc.txt");
	while (!File.eof())
	{
		File >> nLoai;
		File.ignore(1, ',');
		if (nLoai == 1)
		{
			getline(File, sMaBD, ',');
			getline(File, sHoTen, ',');
			getline(File, sKhoa, ',');
			File >> nNgay;
			File.ignore(1, ',');
			File >> nThang;
			File.ignore(1, ',');
			File >> nNam;
			File.ignore(1, ',');
			getline(File, sDC, ',');
			getline(File, sSDT, '\n');
			BanDoc * gv = new GiaoVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, sDC, sSDT);
			L2.push_back(gv);
		}
		else if (nLoai == 2)
		{
			getline(File, sMaBD, ',');
			getline(File, sHoTen, ',');
			getline(File, sKhoa, ',');
			File >> nNgay;
			File.ignore(1, ',');
			File >> nThang;
			File.ignore(1, ',');
			File >> nNam;
			File.ignore(1, ',');
			File >> nKhoaHoc;
			File.ignore(1, '\n');
			BanDoc * sv = new SinhVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, nKhoaHoc);
			L2.push_back(sv);
		}
	}
	File.close();
}
//SÁCH
void timKiem(list <Sach> L3) // tìm kiếm sách 
{
	int flag = 0;
	textColor(4);

	cout << "\t\tNhap N de thoat!\n";
	textColor(7);
	string sTimKiem = "";
dd:
	cout << "\t\tNhap ma sach can tim: ";
	rewind(stdin);
	getline(cin, sTimKiem);
	if (sTimKiem == "N")
	{
		textColor(10);
		cout << "\t\tBan da chon thoat! \n";
		textColor(7);
	}
	else
	{
		list <Sach>::iterator p = L3.begin();
		while (p != L3.end())
		{
			if (sTimKiem == p->getMS())
			{
				cout << "\n\t\tTHONG TIN SACH\n";
				p->outputSach();
				cout << "*********************************************\n";
				break;
			}
			p++; // cộng dồn 
		}
		if (flag == 0)
		{
			textColor(4);
			rewind(stdin);
			cout << "\t\tMa sach khong ton tai !\n";
			textColor(7);
			goto dd;
		}
	}

}
void themSach(list <Sach> &L3)  // thêm sách
{
	string sMaSo = "";
	string sTD = "";
	string sTG = "";
	string sNXB = "";
	float fTriGia = NULL;
	int nNamPhatHanh = 0;
	int nST = 0;
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	int nTinhTrang = 0;
dd:
	cout << "\t\tNhap ma so sach: ";
	rewind(stdin);
	getline(cin, sMaSo);
	list <Sach>::iterator p = L3.begin();
	while (p != L3.end())
	{
		if (sMaSo == p->getMS() || sMaSo == "")
		{
			textColor(4);
			cout << "\t\t\tMa so sach da ton tai hoac chua nhap ma so sach !!!\n";
			system("pause");
			goto dd;
		}
		p++;
	}
td:
	cout << "\t\tNhap tua de sach: ";
	fflush(stdin);
	getline(cin, sTD);
	if (sTD == "")
	{
		textColor(4);
		cout << "\t\t\tKhong duoc de trong !\n";
		textColor(7);
		goto td;
	}
tg:
	cout << "\t\tNhap ten tac gia: ";
	fflush(stdin);
	getline(cin, sTG);
	if (sTG == "")
	{
		textColor(4);
		cout << "\t\t\tKhong duoc de trong !\n";
		textColor(7);
		goto tg;
	}
nxb:
	cout << "\t\tNhap nha xuat ban: ";
	fflush(stdin);
	getline(cin, sNXB);
	if (sNXB == "")
	{
		textColor(4);
		cout << "\t\t\tKhong duoc de trong !\n";
		textColor(7);
		goto nxb;
	}
	cout << "\t\tNhap gia cuon sach: ";
	cin >> fTriGia;
	cout << "\t\tNhap nam phat hanh: ";
	cin >> nNamPhatHanh;
	cout << "\t\tNhap so trang: ";
	cin >> nST;
	cout << "\t\tNgay nhap kho: ";
	cout << "\n\t\t\t\tNhap ngay: ";
	cin >> nNgay;
	cout << "\t\t\t\tNhap thang: ";
	cin >> nThang;
	cout << "\t\t\t\tNhap nam: ";
	cin >> nNam;
	cout << "Tinh trang: ";
	cin >> nTinhTrang;
	Sach s(sMaSo, sTD, sTG, sNXB, fTriGia, nNamPhatHanh, nST, nNgay, nThang, nNam, nTinhTrang);
	L3.push_back(s);
	textColor(10);
	cout << "\t\tthem sach thanh cong !\n";
	textColor(7);
}
void outputFile(list <Sach> L3) // xuất ra file 
{
	ofstream File;
	File.open("Sach.txt");
	int nDem = 1;
	int nTongSoSach = dem_Tong_So_Sach_Hien_Co(L3); // đếm tổng sách hiện có 
	list <Sach>::iterator p = L3.begin();
	while (p != L3.end())
	{
		File << p->getMS() << "," << p->getTD() << "," << p->getTG() << "," << p->getNXB() << "," << p->getGia() << "," << p->getNPH() << "," << p->getST() << "," << p->getNgayNK() << "," << p->getThangNK() << "," << p->getNamNK() << "," << p->getTinhTrang();
		if (nDem < nTongSoSach)
		{
			File << endl;
			nDem++;
		}
		p++;
	}
	File.close();
}
void output_SACH(list <Sach> L3)  // xuất ra màn hình 
{
	list <Sach>::iterator p = L3.begin();
	while (p != L3.end())
	{
		p->outputSach();
		p++;
	}
}
void docFile_SACH(list <Sach> &L3) 
{
	string sMS = "";
	string sTD = "";
	string sTG = "";
	string sNXB = "";
	float fTriGia = 0.0;
	int nNPH = 0;
	int nST = 0;
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	int nTT = 0;
	ifstream File;
	File.open("Sach.txt");
	while (!File.eof()) // end of file
	{
		getline(File, sMS, ',');
		getline(File, sTD, ',');
		getline(File, sTG, ',');
		getline(File, sNXB, ',');
		File >> fTriGia;
		File.ignore(1, ',');
		File >> nNPH;
		File.ignore(1, ',');
		File >> nST;
		File.ignore(1, ',');
		File >> nNgay;
		File.ignore(1, ',');
		File >> nThang;
		File.ignore(1, ',');
		File >> nNam;
		File.ignore(1, ',');
		File >> nTT;
		File.ignore(1, '\n');
		rewind(stdin);
		Sach s(sMS, sTD, sTG, sNXB, fTriGia, nNPH, nST, nNgay, nThang, nNam, nTT);
		L3.push_back(s);
	}
	File.close();
}
int dem_Tong_So_Sach_Hien_Co(list <Sach> L3) // đếm tổng sách hiện có 
{
	int nDem = 0;
	list <Sach>::iterator p = L3.begin();
	while (p != L3.end())
	{
		nDem++;
		p++;
	}
	return nDem;
}

//PHIẾU MƯỢN
void output_PHIEUMUON(list <PhieuMuon> L4) // xuất ra màn hình phiếu mượn
{
	list <PhieuMuon> ::iterator p = L4.begin();
	while (p != L4.end())
	{
		p->xuat();
		p++;
	}
}
void docFile_PHIEUMUON(list <PhieuMuon> &L4) // đọc từ file phiếu mượn
{
	int nSPM = 0;
	string sMBD = "";
	string sMS = "";
	int nNgayMuon = 0;
	int nThangMuon = 0;
	int nNamMuon = 0;
	int nNgayTra = 0;
	int nThangTra = 0;
	int nNamTra = 0;
	int nTrangThai = 0;
	ifstream File;
	File.open("PhieuMuon.txt");
	while (!File.eof())
	{
		File >> nSPM;
		File.ignore(1, ',');
		getline(File, sMBD, ',');
		getline(File, sMS, ',');
		File >> nNgayMuon;
		File.ignore(1, ',');
		File >> nThangMuon;
		File.ignore(1, ',');
		File >> nNamMuon;
		File.ignore(1, ',');
		File >> nNgayTra;
		File.ignore(1, ',');
		File >> nThangTra;
		File.ignore(1, ',');
		File >> nNamTra;
		File.ignore(1, ',');
		File >> nTrangThai;
		File.ignore(1, '\n');
		PhieuMuon pm(nSPM, sMBD, sMS, nNgayMuon, nThangMuon, nNamMuon, nNgayTra, nThangTra, nNamTra, nTrangThai);
		L4.push_back(pm);
	}
	File.close();
}

