#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <ctime>
#include <iomanip>
#include "QuanLyDonHang.h"
#pragma execution_character_set( "utf-8" )


class QuanLyDonHangApp {
private:
    std::vector<QuanLyDonHang> danhSachDonHang;

public:
    void chayUngDung();
    void hienThiMenu();
    void themDonHang();
    void hienThiTatCaDonHang();
    void timKiemDonHang();
    void capNhatDonHang();
    void xoaDonHang();
    void thongKeDonHang();
    void clearScreen();
    void waitForEnter();
    std::time_t nhapNgay();
    std::string chonLoaiVanChuyen();
    std::string chonLoaiDonHang();
};

void QuanLyDonHangApp::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void QuanLyDonHangApp::waitForEnter() {
    std::cout << "\nNhấn Enter để tiếp tục...";
    std::cin.ignore();
    std::cin.get();
}

void QuanLyDonHangApp::hienThiMenu() {
    std::cout << "╔═══════════════════════════════════════════════════════════╗\n";
    std::cout << "║                  HỆ THỐNG QUẢN LÝ ĐƠN HÀNG                ║\n";
    std::cout << "╠═══════════════════════════════════════════════════════════╣\n";
    std::cout << "║  1. Thêm đơn hàng mới                                     ║\n";
    std::cout << "║  2. Hiển thị tất cả đơn hàng                              ║\n";
    std::cout << "║  3. Tìm kiếm đơn hàng                                     ║\n";
    std::cout << "║  4. Cập nhật đơn hàng                                     ║\n";
    std::cout << "║  5. Xóa đơn hàng                                          ║\n";
    std::cout << "║  6. Thống kê đơn hàng                                     ║\n";
    std::cout << "║  0. Thoát chương trình                                    ║\n";
    std::cout << "╚═══════════════════════════════════════════════════════════╝\n";
    std::cout << "Nhập lựa chọn của bạn: ";
}

std::string QuanLyDonHangApp::chonLoaiVanChuyen() {
    int choice;
    std::cout << "\n┌─────────────────────────────────────┐\n";
    std::cout << "│        LOẠI GÓI VẬN CHUYỂN          │\n";
    std::cout << "├─────────────────────────────────────┤\n";
    std::cout << "│ 1. Giao hàng tiêu chuẩn             │\n";
    std::cout << "│ 2. Giao hàng nhanh                  │\n";
    std::cout << "│ 3. Giao hàng siêu tốc               │\n";
    std::cout << "│ 4. Giao hàng trong ngày             │\n";
    std::cout << "└─────────────────────────────────────┘\n";
    std::cout << "Chọn loại vận chuyển (1-4): ";

    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
    case 1: return "Giao hàng tiêu chuẩn";
    case 2: return "Giao hàng nhanh";
    case 3: return "Giao hàng siêu tốc";
    case 4: return "Giao hàng trong ngày";
    default: return "Giao hàng tiêu chuẩn";
    }
}

std::string QuanLyDonHangApp::chonLoaiDonHang() {
    int choice;
    std::cout << "\n┌─────────────────────────────────────┐\n";
    std::cout << "│        LOẠI ĐƠN HÀNG                │\n";
    std::cout << "├─────────────────────────────────────┤\n";
    std::cout << "│ 1. Đơn hàng trong nước              │\n";
    std::cout << "│ 2. Đơn hàng ngoài nước              │\n";
    std::cout << "└─────────────────────────────────────┘\n";
    std::cout << "Chọn loại vận chuyển : ";

    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
    case 1: return "Đơn hàng trong nước";
    case 2: return "Đơn hàng ngoài nước ";
    default: return "Đơn hàng trong nước";
    }
}

std::time_t QuanLyDonHangApp::nhapNgay() {
    int ngay, thang, nam, gio, phut;
    std::cout << "Nhập ngày (dd mm yyyy hh mm): ";
    std::cin >> ngay >> thang >> nam >> gio >> phut;

    std::tm tm = {};
    tm.tm_mday = ngay;
    tm.tm_mon = thang - 1;  // months since January
    tm.tm_year = nam - 1900; // years since 1900
    tm.tm_hour = gio;
    tm.tm_min = phut;
    tm.tm_sec = 0;

    return std::mktime(&tm);
}

void QuanLyDonHangApp::themDonHang() {
    clearScreen();
    std::cout << "╔═══════════════════════════════════════╗\n";
    std::cout << "║           THÊM ĐƠN HÀNG MỚI           ║\n";
    std::cout << "╚═══════════════════════════════════════╝\n\n";

    std::string maDonHang;
    std::cout << "Nhập mã đơn hàng: ";
    std::getline(std::cin, maDonHang);

    // Check if order ID already exists
    for (const auto& donHang : danhSachDonHang) {
        if (donHang.getMaDonHang() == maDonHang) {
            std::cout << "❌ Mã đơn hàng đã tồn tại!\n";
            waitForEnter();
            return;
        }
    }

    std::time_t ngayDatHang = nhapNgay();
    std::string loaiVanChuyen = chonLoaiVanChuyen();

    QuanLyDonHang donHangMoi(maDonHang, ngayDatHang, loaiVanChuyen);
    danhSachDonHang.push_back(donHangMoi);

    std::cout << "\n✅ Đã thêm đơn hàng thành công!\n";
    donHangMoi.hienThiThongTin();
    waitForEnter();
}

void QuanLyDonHangApp::hienThiTatCaDonHang() {
    clearScreen();
    std::cout << "╔═══════════════════════════════════════╗\n";
    std::cout << "║        DANH SÁCH TẤT CẢ ĐƠN HÀNG      ║\n";
    std::cout << "╚═══════════════════════════════════════╝\n\n";

    if (danhSachDonHang.empty()) {
        std::cout << "❌ Không có đơn hàng nào trong hệ thống.\n";
        waitForEnter();
        return;
    }

    std::cout << "Tổng số đơn hàng: " << danhSachDonHang.size() << "\n\n";

    for (size_t i = 0; i < danhSachDonHang.size(); ++i) {
        std::cout << "📦 Đơn hàng #" << (i + 1) << ":\n";
        danhSachDonHang[i].hienThiThongTin();
        std::cout << "\n";
    }

    waitForEnter();
}

void QuanLyDonHangApp::timKiemDonHang() {
    clearScreen();
    std::cout << "╔═══════════════════════════════════════╗\n";
    std::cout << "║           TÌM KIẾM ĐƠN HÀNG           ║\n";
    std::cout << "╚═══════════════════════════════════════╝\n\n";

    std::string maTim;
    std::cout << "Nhập mã đơn hàng cần tìm: ";
    std::getline(std::cin, maTim);

    bool timThay = false;
    for (const auto& donHang : danhSachDonHang) {
        if (donHang.getMaDonHang() == maTim) {
            std::cout << "\n✅ Tìm thấy đơn hàng:\n";
            donHang.hienThiThongTin();
            timThay = true;
            break;
        }
    }

    if (!timThay) {
        std::cout << "\n❌ Không tìm thấy đơn hàng với mã: " << maTim << "\n";
    }

    waitForEnter();
}

void QuanLyDonHangApp::capNhatDonHang() {
    clearScreen();
    std::cout << "╔═══════════════════════════════════════╗\n";
    std::cout << "║          CẬP NHẬT ĐƠN HÀNG            ║\n";
    std::cout << "╚═══════════════════════════════════════╝\n\n";

    std::string maTim;
    std::cout << "Nhập mã đơn hàng cần cập nhật: ";
    std::getline(std::cin, maTim);

    for (auto& donHang : danhSachDonHang) {
        if (donHang.getMaDonHang() == maTim) {
            std::cout << "\n📋 Thông tin hiện tại:\n";
            donHang.hienThiThongTin();

            int choice;
            std::cout << "\nChọn thông tin cần cập nhật:\n";
            std::cout << "1. Mã đơn hàng\n";
            std::cout << "2. Ngày đặt hàng\n";
            std::cout << "3. Loại gói vận chuyển\n";
            std::cout << "Nhập lựa chọn: ";
            std::cin >> choice;
            std::cin.ignore();

            switch (choice) {
            case 1: {
                std::string maMoi;
                std::cout << "Nhập mã đơn hàng mới: ";
                std::getline(std::cin, maMoi);
                donHang.setMaDonHang(maMoi);
                break;
            }
            case 2: {
                std::time_t ngayMoi = nhapNgay();
                donHang.setNgayDatHang(ngayMoi);
                break;
            }
            case 3: {
                std::string loaiMoi = chonLoaiVanChuyen();
                donHang.setLoaiGoiVanChuyen(loaiMoi);
                break;
            }
            default:
                std::cout << "❌ Lựa chọn không hợp lệ!\n";
                waitForEnter();
                return;
            }

            std::cout << "\n✅ Cập nhật thành công!\n";
            std::cout << "📋 Thông tin sau khi cập nhật:\n";
            donHang.hienThiThongTin();
            waitForEnter();
            return;
        }
    }

    std::cout << "\n❌ Không tìm thấy đơn hàng với mã: " << maTim << "\n";
    waitForEnter();
}

void QuanLyDonHangApp::xoaDonHang() {
    clearScreen();
    std::cout << "╔═══════════════════════════════════════╗\n";
    std::cout << "║            XÓA ĐƠN HÀNG               ║\n";
    std::cout << "╚═══════════════════════════════════════╝\n\n";

    std::string maTim;
    std::cout << "Nhập mã đơn hàng cần xóa: ";
    std::getline(std::cin, maTim);

    auto it = std::find_if(danhSachDonHang.begin(), danhSachDonHang.end(),
        [&maTim](const QuanLyDonHang& donHang) {
            return donHang.getMaDonHang() == maTim;
        });

    if (it != danhSachDonHang.end()) {
        std::cout << "\n📋 Thông tin đơn hàng sẽ bị xóa:\n";
        it->hienThiThongTin();

        char xacNhan;
        std::cout << "\nBạn có chắc chắn muốn xóa? (y/n): ";
        std::cin >> xacNhan;
        std::cin.ignore();

        if (xacNhan == 'y' || xacNhan == 'Y') {
            danhSachDonHang.erase(it);
            std::cout << "\n✅ Đã xóa đơn hàng thành công!\n";
        }
        else {
            std::cout << "\n❌ Hủy thao tác xóa.\n";
        }
    }
    else {
        std::cout << "\n❌ Không tìm thấy đơn hàng với mã: " << maTim << "\n";
    }

    waitForEnter();
}

void QuanLyDonHangApp::thongKeDonHang() {
    clearScreen();
    std::cout << "╔═══════════════════════════════════════╗\n";
    std::cout << "║           THỐNG KÊ ĐƠN HÀNG           ║\n";
    std::cout << "╚═══════════════════════════════════════╝\n\n";

    if (danhSachDonHang.empty()) {
        std::cout << "❌ Không có đơn hàng nào để thống kê.\n";
        waitForEnter();
        return;
    }

    // Count shipping types
    int tieuChuan = 0, nhanh = 0, sieuToc = 0, trongNgay = 0;

    for (const auto& donHang : danhSachDonHang) {
        std::string loai = donHang.getLoaiGoiVanChuyen();
        if (loai == "Giao hàng tiêu chuẩn") tieuChuan++;
        else if (loai == "Giao hàng nhanh") nhanh++;
        else if (loai == "Giao hàng siêu tốc") sieuToc++;
        else if (loai == "Giao hàng trong ngày") trongNgay++;
    }

    std::cout << "┌─────────────────────────────────────────────────────────┐\n";
    std::cout << "│                    THỐNG KÊ TỔNG QUAN                   │\n";
    std::cout << "├─────────────────────────────────────────────────────────┤\n";
    std::cout << "│ Tổng số đơn hàng        : " << std::setw(25) << danhSachDonHang.size() << "│\n";
    std::cout << "│ Giao hàng tiêu chuẩn    : " << std::setw(25) << tieuChuan << "│\n";
    std::cout << "│ Giao hàng nhanh         : " << std::setw(25) << nhanh << "│\n";
    std::cout << "│ Giao hàng siêu tốc      : " << std::setw(25) << sieuToc << "│\n";
    std::cout << "│ Giao hàng trong ngày    : " << std::setw(25) << trongNgay << "│\n";
    std::cout << "└─────────────────────────────────────────────────────────┘\n";

    waitForEnter();
}

void QuanLyDonHangApp::chayUngDung() {
    int luaChon;

    do {
        clearScreen();
        hienThiMenu();

        std::cin >> luaChon;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (luaChon) {
        case 1:
            themDonHang();
            break;
        case 2:
            hienThiTatCaDonHang();
            break;
        case 3:
            timKiemDonHang();
            break;
        case 4:
            capNhatDonHang();
            break;
        case 5:
            xoaDonHang();
            break;
        case 6:
            thongKeDonHang();
            break;
        case 0:
            std::cout << "\n👋 Cảm ơn bạn đã sử dụng hệ thống!\n";
            break;
        default:
            std::cout << "\n❌ Lựa chọn không hợp lệ! Vui lòng thử lại.\n";
            waitForEnter();
            break;
        }
    } while (luaChon != 0);
}

int main() {
    // Set console to support UTF-8 (for Windows)
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    QuanLyDonHangApp app;
    app.chayUngDung();

    return 0;
}
