#ifndef DONHANG_H
#define DONHANG_H

#include "Ngay.h"
#include <string>
#include <iostream>

class DonHang {
protected:
    std::string maDonHang;
    Ngay ngayDatHang;
    std::string loaiGoiVanChuyen;

public:
    // Constructors
    DonHang();
    DonHang(const std::string& ma, const Ngay& ngay, const std::string& loai);

    // Virtual destructor
    virtual ~DonHang();

    // Getter
    std::string getMaDonHang() const;
    Ngay getNgayDatHang() const;
    std::string getLoaiGoiVanChuyen() const;

    // Setter
    void setMaDonHang(const std::string& ma);
    void setNgayDatHang(const Ngay& ngay);
    void setLoaiGoiVanChuyen(const std::string& loai);

    // Virtual
    virtual double TinhTongTien() = 0;  // Pure virtual function
    virtual void InThongTin() = 0;      // Pure virtual function

    // Utility
    double getShippingCost() const;
    void displayHeader() const;
};

#endif
