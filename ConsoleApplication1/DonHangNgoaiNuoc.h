#pragma once
#include "QuanLyDonHang.h"
#include <iostream>

class DonHangNgoaiNuoc : public QuanLyDonHang {
private:
    double PhiHaiQuan;

public:
    // Constructor mặc định
    DonHangNgoaiNuoc();

    // Constructor có tham số
    DonHangNgoaiNuoc(const std::string& ma, std::time_t ngay, const std::string& loai, double phi);

    // Getter & Setter
    double getPhiHaiQuan() const;
    void setPhiHaiQuan(double phi);

    // Ghi đè hàm ảo từ lớp cha
    double tinhTongTien() const override;
    void hienThiThongTin() const override;

    // Toán tử nhập/xuất
    friend std::istream& operator >> (std::istream& is, DonHangNgoaiNuoc& dh);
    friend std::ostream& operator << (std::ostream& os, const DonHangNgoaiNuoc& dh);
};
