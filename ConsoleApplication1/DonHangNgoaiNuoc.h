#pragma once  
#include "QuanLyDonHang.h"   
class DonHangNgoaiNuoc : public QuanLyDonHang {

private:
	double PhiHaiQuan;
public:
	DonHangNgoaiNuoc();

	double getPhiHaiQuan() const;

	void setPhiHaiQuan(double phi);

	double tinhTongTien() const;

	void InThongTin() const;

	friend std::istream& operator >> (std::istream& is, DonHangNgoaiNuoc& dh);

	friend std::ostream& operator << (std::ostream& os, const DonHangNgoaiNuoc& dh);



};