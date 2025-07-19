#include "DonHangNgoaiNuoc.h"
#include <iostream>
#include <iomanip>
#include <ctime>

// Constructor có tham số
DonHangNgoaiNuoc::DonHangNgoaiNuoc(const std::string& ma, std::time_t ngay, const std::string& loai, double phi)
    : QuanLyDonHang(ma, ngay, loai), PhiHaiQuan(phi) {
}

// Constructor mặc định
DonHangNgoaiNuoc::DonHangNgoaiNuoc() : PhiHaiQuan(0.0) {}

// Getter
double DonHangNgoaiNuoc::getPhiHaiQuan() const {
    return PhiHaiQuan;
}

// Setter
void DonHangNgoaiNuoc::setPhiHaiQuan(double phi) {
    PhiHaiQuan = phi;
}

// Tính tổng tiền
double DonHangNgoaiNuoc::tinhTongTien() const {
    return PhiHaiQuan;
}

// Hiển thị thông tin
void DonHangNgoaiNuoc::hienThiThongTin() const {
    QuanLyDonHang::hienThiThongTin();
    std::cout << "Phi Hai Quan: " << PhiHaiQuan << "\n";
}

// Operator nhập
std::istream& operator>>(std::istream& is, DonHangNgoaiNuoc& dh) {
    std::cout << "Nhap phi hai quan: ";
    is >> dh.PhiHaiQuan;
    return is;
}

// Operator xuất
std::ostream& operator<<(std::ostream& os, const DonHangNgoaiNuoc& dh) {
    dh.hienThiThongTin();
    return os;
}
