#include "DonHangQuocTe.h"
#include <iomanip>
#pragma execution_character_set( "utf-8" )

//constructor
DonHangQuocTe::DonHangQuocTe() : DonHang() {
    phiHaiQuan = 0.0;
}

// Parameterized constructor
DonHangQuocTe::DonHangQuocTe(const std::string& ma, const Ngay& ngay,
    const std::string& loai, double phi)
    : DonHang(ma, ngay, loai) {
    phiHaiQuan = phi;
}

// Destructor
DonHangQuocTe::~DonHangQuocTe() {}

// Getter and Setter
double DonHangQuocTe::getPhiHaiQuan() const {
    return phiHaiQuan;
}

void DonHangQuocTe::setPhiHaiQuan(double phi) {
    phiHaiQuan = (phi >= 0) ? phi : 0.0;
}

// Override TinhTongTien 
double DonHangQuocTe::TinhTongTien() {
    double shippingCost = getShippingCost();
    // International shipping has 50% surcharge
    double internationalSurcharge = shippingCost * 0.5;
    return phiHaiQuan + shippingCost + internationalSurcharge;
}

// Override InThongTin 
void DonHangQuocTe::InThongTin() {
    displayHeader();
    std::cout << "║ Loại đơn hàng      : ĐƠN HÀNG QUỐC TẾ                        ║\n";
    std::cout << "║ Mã đơn hàng        : " << std::setw(40) << std::left << std::fixed << maDonHang << "║\n";
    std::cout << "║ Ngày đặt hàng      : " << std::setw(40) << std::left << std::fixed << ngayDatHang.toString() << "║\n";
    std::cout << "║ Loại gói vận chuyển: " << std::setw(40) << std::left << std::fixed << loaiGoiVanChuyen << "║\n";
    std::cout << "║ Phí hải quan       : " << std::setw(35) << std::left << std::fixed << std::setprecision(0) << phiHaiQuan << " VND" << " ║\n";
    std::cout << "║ Phí gói dịch vụ    : " << std::setw(35) << std::left << std::fixed << std::setprecision(0) << getShippingCost() << " VND" << " ║\n";
    std::cout << "║ Phí quốc tế (+50%) : " << std::setw(35) << std::left << std::fixed << std::setprecision(0) << (getShippingCost() * 0.5) << " VND" << " ║\n";
    std::cout << "╠══════════════════════════════════════════════════════════════╣\n";
    std::cout << "║ TỔNG TIỀN          : " << std::setw(35) << std::left << std::fixed << std::setprecision(0) << TinhTongTien() << " VND" << " ║\n";
    std::cout << "╚══════════════════════════════════════════════════════════════╝\n";
}

// Input operator
std::istream& operator>>(std::istream& is, DonHangQuocTe& dh) {
    std::cout << "Nhập mã đơn hàng: ";
    std::getline(is, dh.maDonHang);

    std::cout << "Nhập ngày đặt hàng (dd/mm/yyyy): ";
    is >> dh.ngayDatHang;
    is.ignore();

    std::cout << "Nhập loại gói vận chuyển (co ban/nhanh/hoa toc): ";
    std::getline(is, dh.loaiGoiVanChuyen);

    std::cout << "Nhập phí hải quan: ";
    is >> dh.phiHaiQuan;
    is.ignore();

    return is;
}

// Output operator
std::ostream& operator<<(std::ostream& os, const DonHangQuocTe& dh) {
    os << "Đơn hàng quốc tế - Mã: " << dh.maDonHang
        << ", Ngày: " << dh.ngayDatHang
        << ", Loại: " << dh.loaiGoiVanChuyen
        << ", Phí HQ: " << dh.phiHaiQuan << " VND";
    return os;
}
