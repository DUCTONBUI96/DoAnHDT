#include "DonHang.h"
#include <iomanip>
#pragma execution_character_set( "utf-8" )

// Default constructor
DonHang::DonHang() {
    maDonHang = "";
    ngayDatHang = Ngay();
    loaiGoiVanChuyen = "co ban";
}

//constructor
DonHang::DonHang(const std::string& ma, const Ngay& ngay, const std::string& loai) {
    maDonHang = ma;
    ngayDatHang = ngay;
    loaiGoiVanChuyen = loai;
}

//destructor
DonHang::~DonHang() {}

// Getter
std::string DonHang::getMaDonHang() const {
    return maDonHang;
}

Ngay DonHang::getNgayDatHang() const {
    return ngayDatHang;
}

std::string DonHang::getLoaiGoiVanChuyen() const {
    return loaiGoiVanChuyen;
}

// Setter
void DonHang::setMaDonHang(const std::string& ma) {
    maDonHang = ma;
}

void DonHang::setNgayDatHang(const Ngay& ngay) {
    ngayDatHang = ngay;
}

void DonHang::setLoaiGoiVanChuyen(const std::string& loai) {
    loaiGoiVanChuyen = loai;
}

// Calculate shipping cost based on package type
double DonHang::getShippingCost() const {
    if (loaiGoiVanChuyen == "co ban") {
        return 20000.0;  
    }
    else if (loaiGoiVanChuyen == "nhanh") {
        return 35000.0;  
    }
    else if (loaiGoiVanChuyen == "hoa toc") {
        return 50000.0; 
    }
    return 20000.0;  // Default
}

// Display header
void DonHang::displayHeader() const {
    std::cout << "╔══════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                      THÔNG TIN ĐƠN HÀNG                      ║\n";
    std::cout << "╠══════════════════════════════════════════════════════════════╣\n";
}
