#include "QuanLyDonHang.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#pragma execution_character_set( "utf-8" )

QuanLyDonHang::QuanLyDonHang() : maDonHang(""), ngayDatHang(0), loaiGoiVanChuyen("") {}
QuanLyDonHang::QuanLyDonHang(const std::string& ma, std::time_t ngay, const std::string& loai)
    : maDonHang(ma), ngayDatHang(ngay), loaiGoiVanChuyen(loai) {
}
QuanLyDonHang::~QuanLyDonHang() {}

std::string QuanLyDonHang::getMaDonHang() const { return maDonHang; }

std::time_t QuanLyDonHang::getNgayDatHang() const { return ngayDatHang; }

std::string QuanLyDonHang::getLoaiGoiVanChuyen() const { return loaiGoiVanChuyen; }

void QuanLyDonHang::setMaDonHang(const std::string& ma) { maDonHang = ma; }

void QuanLyDonHang::setNgayDatHang(std::time_t ngay) { ngayDatHang = ngay; }

void QuanLyDonHang::setLoaiGoiVanChuyen(const std::string& loai) { loaiGoiVanChuyen = loai; }

void QuanLyDonHang::hienThiThongTin() const {
    std::cout << "Ma don hang: " << maDonHang << "\n";
    std::cout << "Loai van chuyen: " << loaiGoiVanChuyen << "\n";
}