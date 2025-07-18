#pragma once
#include "QuanLyDonHang.h"
#include <iostream>
#include <iomanip>
#include <ctime>
class DonHangTrongNuoc : public QuanLyDonHang {

private:
	double PhiVanChuyen;
public:
	DonHangTrongNuoc();

	double getPhiHaiQuan() const;

	void setPhiHaiQuan(double phi);

	double tinhTongTien() const;

	void InThongTin() const;

	friend std::istream& operator >> (std::istream& is, DonHangTrongNuoc& dh);

	friend std::ostream& operator << (std::ostream& os, const DonHangTrongNuoc& dh);

};