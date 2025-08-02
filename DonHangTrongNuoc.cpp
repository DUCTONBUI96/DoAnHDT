#include "DonHangTrongNuoc.h"
#include <iomanip>
#pragma execution_character_set( "utf-8" )

// Default constructor
DonHangTrongNuoc::DonHangTrongNuoc() : DonHang() {
    phiVanChuyen = 0.0;
}

// Parameterized constructor
DonHangTrongNuoc::DonHangTrongNuoc(const std::string& ma, const Ngay& ngay,
    const std::string& loai, double phi)
    : DonHang(ma, ngay, loai) {
    phiVanChuyen = phi;
}

// Destructor
DonHangTrongNuoc::~DonHangTrongNuoc() {}

// Getter
double DonHangTrongNuoc::getPhiVanChuyen() const {
    return phiVanChuyen;
}

// Setter
void DonHangTrongNuoc::setPhiVanChuyen(double phi) {
    phiVanChuyen = (phi >= 0) ? phi : 0.0;
}

// Override TinhTongTien 
double DonHangTrongNuoc::TinhTongTien() {
    double shippingCost = getShippingCost();
    return phiVanChuyen + shippingCost;
}

//InThongTin 
void DonHangTrongNuoc::InThongTin() {
    displayHeader();
    std::cout << "║ Loại đơn hàng      : ĐƠN HÀNG TRONG NƯỚC                     ║\n";
    std::cout << "║ Mã đơn hàng        : " << std::setw(40) << std::left << std::fixed << maDonHang << "║\n";
    std::cout << "║ Ngày đặt hàng      : " << std::setw(40) << std::left << std::fixed << ngayDatHang.toString() << "║\n";
    std::cout << "║ Loại gói vận chuyển: " << std::setw(40) << std::left << std::fixed << loaiGoiVanChuyen << "║\n";
    std::cout << "║ Phí vận chuyển     : " << std::setw(35) << std::left << std::fixed << std::setprecision(0) << phiVanChuyen << " VND" << " ║\n";
    std::cout << "║ Phí gói dịch vụ    : " << std::setw(35) << std::left << std::fixed << std::setprecision(0) << getShippingCost() << " VND" << " ║\n";
    std::cout << "╠══════════════════════════════════════════════════════════════╣\n";
    std::cout << "║ TỔNG TIỀN          : " << std::setw(35) << std::left << std::fixed << std::setprecision(0) << TinhTongTien() << " VND" << " ║\n";
    std::cout << "╚══════════════════════════════════════════════════════════════╝\n";
}


// Input operator
std::istream& operator>>(std::istream& is, DonHangTrongNuoc& dh) {
    std::cout << "Nhập mã đơn hàng: ";
    std::getline(is, dh.maDonHang);

    std::cout << "Nhập ngày đặt hàng (dd/mm/yyyy): ";
    is >> dh.ngayDatHang;
    is.ignore();

    std::cout << "Nhập loại gói vận chuyển (co ban/nhanh/hoa toc): ";
    std::getline(is, dh.loaiGoiVanChuyen);

    std::cout << "Nhập phí vận chuyển: ";
    is >> dh.phiVanChuyen;
    is.ignore();

    return is;
}

// Output operator
std::ostream& operator<<(std::ostream& os, const DonHangTrongNuoc& dh) {
    os << "Đơn hàng trong nước - Mã: " << dh.maDonHang
        << ", Ngày: " << dh.ngayDatHang
        << ", Loại: " << dh.loaiGoiVanChuyen
        << ", Phí VC: " << dh.phiVanChuyen << " VND";
    return os;
}
