#include "QuanLyDonHang.h"
#include <iostream>
#include <iomanip>
#include <ctime>
class DonHangNgoaiNuoc : public QuanLyDonHang {

private:
	double PhiHaiQuan;
public:
	DonHangNgoaiNuoc();

	double getPhiHaiQuan() const { return PhiHaiQuan;}

	void setPhiHaiQuan(double phi) { PhiHaiQuan = phi; }

	double tinhTongTien() const {return PhiHaiQuan;}

	void InThongTin() const {
		QuanLyDonHang::hienThiThongTin();
		std::cout << "Phi Hai Quan: " << PhiHaiQuan << "\n";
	}

	friend std::istream& operator >> (std::istream& is, DonHangNgoaiNuoc& dh) {
		is >> dh.PhiHaiQuan;
		return is;
	}

	friend std::ostream& operator << (std::ostream& os, const DonHangNgoaiNuoc& dh) {
		dh.QuanLyDonHang::hienThiThongTin();
		os << "Phi Hai Quan: " << dh.PhiHaiQuan;
		return os;
	}



};