#ifndef QUANLYDONHANG_H
#define QUANLYDONHANG_H

#include <string>
#include <ctime>
#include <iostream>

class QuanLyDonHang {
protected:  // nên là protected để lớp con truy cập được
    std::string maDonHang;
    std::time_t ngayDatHang;
    std::string loaiGoiVanChuyen;

public:
    // Constructors
    QuanLyDonHang();
    QuanLyDonHang(const std::string& ma, std::time_t ngay, const std::string& loai);

    // Destructor: virtual để xóa đúng lớp con khi delete qua con trỏ lớp cha
    virtual ~QuanLyDonHang();

    // Getter methods
    std::string getMaDonHang() const;
    std::time_t getNgayDatHang() const;
    std::string getLoaiGoiVanChuyen() const;

    // Setter methods
    void setMaDonHang(const std::string& ma);
    void setNgayDatHang(std::time_t ngay);
    void setLoaiGoiVanChuyen(const std::string& loai);

    // Hàm ảo dùng đa hình
    virtual void hienThiThongTin() const;      // override được ở lớp con
    virtual double tinhTongTien() const = 0;   // pure virtual: bắt buộc lớp con cài đặt
};

#endif
