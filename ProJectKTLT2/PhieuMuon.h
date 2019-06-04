#ifndef PhieuMuon_h
#define PhieuMuon_h

#include <time.h>
#include "BanDoc.h"
#include "Date.h"
#include "Sach.h"
class BanDoc;
class Date;
class Sach;
class PhieuMuon
{
	BanDoc xBanDoc;
	Sach xSach;
	Date xNgayMuon, xNgayTra;
	static int nTongPM;
	int nMaPM;
	int nTrangThai;
public:
	int getTPM();
	friend Date;
	friend BanDoc;
	friend Sach;
	BanDoc getBanDoc();
	Sach getSach();
	Date getNgayMuon();
	Date getNgayTra();
	int getMaPM();
	int getTrangThai();
	void setTrangThai(int a);
	void setSach(Sach s);
	void setBanDoc(BanDoc xBD);

	void xuat();
	PhieuMuon(int nMaPM = 0, string sMaBD = "", string sMaSach = "", int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0, int nTrangThai = 0) : xBanDoc(sMaBD), xSach(sMaSach), xNgayMuon(a, b, c), xNgayTra(d, e, f)
	{

		this->nTongPM++;
		this->nMaPM = nTongPM;
		this->nTrangThai = nTrangThai;
	}
	PhieuMuon(string sMaBD = "", string sMaSach = "") : xBanDoc(sMaBD), xSach(sMaSach)
	{
		this->nTongPM++;
		this->nMaPM = nTongPM;
		this->nTrangThai = 1;
	}
	~PhieuMuon(void) {};
};
#endif // !1