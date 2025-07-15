#ifndef QUANLYDONHANG_H
#define QUANLYDONHANG_H

#include <string>
#include <ctime>
#include <iostream>

class QuanLyDonHang {
private:
    std::string maDonHang;
    std::time_t ngayDatHang;
    std::string loaiGoiVanChuyen;

public:
    // Constructors
    QuanLyDonHang();
    QuanLyDonHang(const std::string& ma, std::time_t ngay, const std::string& loai);

    // Destructor
    ~QuanLyDonHang();

    // Getter methods
    std::string getMaDonHang() const;
    std::time_t getNgayDatHang() const;
    std::string getLoaiGoiVanChuyen() const;

    // Setter methods
    void setMaDonHang(const std::string& ma);
    void setNgayDatHang(std::time_t ngay);
    void setLoaiGoiVanChuyen(const std::string& loai);

    // Utility methods
    void hienThiThongTin() const;
    std::string formatNgay() const;
};

#endif
#pragma once
