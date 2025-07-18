#include "QuanLyDonHang.h"
#include <iostream>
#include <iomanip>
#include <ctime>
class DonHangTrongNuoc : public QuanLyDonHang {

private:
	double PhiVanChuyen;
public:
	DonHangTrongNuoc();

	double getPhiHaiQuan() const { return PhiVanChuyen; }

	void setPhiHaiQuan(double phi) { PhiVanChuyen = phi; }

	double tinhTongTien() const { return PhiVanChuyen; }

	void InThongTin() const {
		QuanLyDonHang::hienThiThongTin();
		std::cout << "Phi Van Chuyen: " << PhiVanChuyen << "\n";
	}

	friend std::istream& operator >> (std::istream& is, DonHangTrongNuoc& dh) {
		is >> dh.PhiVanChuyen;
		return is;
	}

	friend std::ostream& operator << (std::ostream& os, const DonHangTrongNuoc& dh) {
		dh.QuanLyDonHang::hienThiThongTin();
		os << "Phi Hai Quan: " << dh.PhiVanChuyen;
		return os;
	}



};