#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include "DonHangTrongNuoc.h"
#include "DonHangQuocTe.h"
#pragma execution_character_set( "utf-8" )

class QuanLyDonHangApp {
private:
    std::vector<std::unique_ptr<DonHang>> danhSachDonHang;

public:
    void chayUngDung();
    void hienThiMenu();
    void themDonHangTrongNuoc();
    void themDonHangQuocTe();
    void hienThiTatCaDonHang();
    void timKiemDonHang();
    void tinhTongDoanhThu();
    void thongKeDonHang();
    void clearScreen();
    void waitForEnter();
    void demonstratePolymorphism();
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
    std::cout << "╔═══════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                 HỆ THỐNG QUẢN LÝ ĐƠN HÀNG                     ║\n";
    std::cout << "╠═══════════════════════════════════════════════════════════════╣\n";
    std::cout << "║  1. Thêm đơn hàng trong nước                                  ║\n";
    std::cout << "║  2. Thêm đơn hàng quốc tế                                     ║\n";
    std::cout << "║  3. Hiển thị tất cả đơn hàng                                  ║\n";
    std::cout << "║  4. Tìm kiếm đơn hàng                                         ║\n";
    std::cout << "║  5. Tính tổng doanh thu                                       ║\n";
    std::cout << "║  6. Thống kê đơn hàng                                         ║\n";
    std::cout << "║  7. Demo đa hình                                              ║\n";
    std::cout << "║  0. Thoát chương trình                                        ║\n";
    std::cout << "╚═══════════════════════════════════════════════════════════════╝\n";
    std::cout << "Nhập lựa chọn của bạn: ";
}

void QuanLyDonHangApp::themDonHangTrongNuoc() {
    clearScreen();
    std::cout << "╔═══════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                  THÊM ĐƠN HÀNG TRONG NƯỚC                     ║\n";
    std::cout << "╚═══════════════════════════════════════════════════════════════╝\n\n";

    auto donHang = std::make_unique<DonHangTrongNuoc>();
    std::cin >> *donHang;

    danhSachDonHang.push_back(std::move(donHang));

    std::cout << "\n✅ Đã thêm đơn hàng trong nước thành công!\n";
    waitForEnter();
}

void QuanLyDonHangApp::themDonHangQuocTe() {
    clearScreen();
    std::cout << "╔═══════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                    THÊM ĐƠN HÀNG QUỐC TẾ                      ║\n";
    std::cout << "╚═══════════════════════════════════════════════════════════════╝\n\n";

    auto donHang = std::make_unique<DonHangQuocTe>();
    std::cin >> *donHang;

    danhSachDonHang.push_back(std::move(donHang));

    std::cout << "\n✅ Đã thêm đơn hàng quốc tế thành công!\n";
    waitForEnter();
}

void QuanLyDonHangApp::hienThiTatCaDonHang() {
    clearScreen();
    std::cout << "╔═══════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                   DANH SÁCH TẤT CẢ ĐƠN HÀNG                   ║\n";
    std::cout << "╚═══════════════════════════════════════════════════════════════╝\n\n";

    if (danhSachDonHang.empty()) {
        std::cout << "❌ Không có đơn hàng nào trong hệ thống.\n";
        waitForEnter();
        return;
    }

    std::cout << "Tổng số đơn hàng: " << danhSachDonHang.size() << "\n\n";

    for (size_t i = 0; i < danhSachDonHang.size(); ++i) {
        std::cout << "📦 Đơn hàng #" << (i + 1) << ":\n";
        danhSachDonHang[i]->InThongTin();  // Polymorphism in action!
        std::cout << "\n";
    }

    waitForEnter();
}

void QuanLyDonHangApp::timKiemDonHang() {
    clearScreen();
    std::cout << "╔═══════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                      TÌM KIẾM ĐƠN HÀNG                        ║\n";
    std::cout << "╚═══════════════════════════════════════════════════════════════╝\n\n";

    std::string maTim;
    std::cout << "Nhập mã đơn hàng cần tìm: ";
    std::getline(std::cin, maTim);

    bool timThay = false;
    for (const auto& donHang : danhSachDonHang) {
        if (donHang->getMaDonHang() == maTim) {
            std::cout << "\n✅ Tìm thấy đơn hàng:\n";
            donHang->InThongTin();  // Polymorphism
            timThay = true;
            break;
        }
    }

    if (!timThay) {
        std::cout << "\n❌ Không tìm thấy đơn hàng với mã: " << maTim << "\n";
    }

    waitForEnter();
}

void QuanLyDonHangApp::tinhTongDoanhThu() {
    clearScreen();
    std::cout << "╔═══════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                     TỔNG DOANH THU                            ║\n";
    std::cout << "╚═══════════════════════════════════════════════════════════════╝\n\n";

    if (danhSachDonHang.empty()) {
        std::cout << "❌ Không có đơn hàng nào để tính doanh thu.\n";
        waitForEnter();
        return;
    }

    double tongDoanhThu = 0.0;
    double doanhThuTrongNuoc = 0.0;
    double doanhThuQuocTe = 0.0;

    for (const auto& donHang : danhSachDonHang) {
        double tien = donHang->TinhTongTien();  // Polymorphism
        tongDoanhThu += tien;

        // Check type using dynamic_cast
        if (dynamic_cast<DonHangTrongNuoc*>(donHang.get())) {
            doanhThuTrongNuoc += tien;
        }
        else if (dynamic_cast<DonHangQuocTe*>(donHang.get())) {
            doanhThuQuocTe += tien;
        }
    }

    std::cout << "┌─────────────────────────────────────────────────────────────┐\n";
    std::cout << "│                      BÁO CÁO DOANH THU                      │\n";
    std::cout << "├─────────────────────────────────────────────────────────────┤\n";
    std::cout << "│ Doanh thu trong nước   : " << std::setw(30) << std::right << std::fixed << std::setprecision(0) << doanhThuTrongNuoc << " VND │\n";
    std::cout << "│ Doanh thu quốc tế      : " << std::setw(30) << std::right << std::fixed << std::setprecision(0) << doanhThuQuocTe << " VND │\n";
    std::cout << "├─────────────────────────────────────────────────────────────┤\n";
    std::cout << "│ TỔNG DOANH THU         : " << std::setw(30) << std::right << std::fixed << std::setprecision(0) << tongDoanhThu << " VND │\n";
    std::cout << "└─────────────────────────────────────────────────────────────┘\n";

    waitForEnter();
}

void QuanLyDonHangApp::thongKeDonHang() {
    clearScreen();
    std::cout << "╔═══════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                      THỐNG KÊ ĐƠN HÀNG                        ║\n";
    std::cout << "╚═══════════════════════════════════════════════════════════════╝\n\n";

    if (danhSachDonHang.empty()) {
        std::cout << "❌ Không có đơn hàng nào để thống kê.\n";
        waitForEnter();
        return;
    }

    int soTrongNuoc = 0, soQuocTe = 0;
    int coBan = 0, nhanh = 0, hoaToc = 0;

    for (const auto& donHang : danhSachDonHang) {
        // Count by type
        if (dynamic_cast<DonHangTrongNuoc*>(donHang.get())) {
            soTrongNuoc++;
        }
        else if (dynamic_cast<DonHangQuocTe*>(donHang.get())) {
            soQuocTe++;
        }

        // Count by shipping type
        std::string loai = donHang->getLoaiGoiVanChuyen();
        if (loai == "co ban") coBan++;
        else if (loai == "nhanh") nhanh++;
        else if (loai == "hoa toc") hoaToc++;
    }

    std::cout << "┌─────────────────────────────────────────────────────────────┐\n";
    std::cout << "│                    THỐNG KÊ TỔNG QUAN                       │\n";
    std::cout << "├─────────────────────────────────────────────────────────────┤\n";
    std::cout << "│ Tổng số đơn hàng       : " << std::setw(35) << danhSachDonHang.size() << "│\n";
    std::cout << "│ Đơn hàng trong nước    : " << std::setw(35) << soTrongNuoc << "│\n";
    std::cout << "│ Đơn hàng quốc tế       : " << std::setw(35) << soQuocTe << "│\n";
    std::cout << "├─────────────────────────────────────────────────────────────┤\n";
    std::cout << "│ Gói cơ bản             : " << std::setw(35) << coBan << "│\n";
    std::cout << "│ Gói nhanh              : " << std::setw(35) << nhanh << "│\n";
    std::cout << "│ Gói hỏa tốc            : " << std::setw(35) << hoaToc << "│\n";
    std::cout << "└─────────────────────────────────────────────────────────────┘\n";

    waitForEnter();
}

void QuanLyDonHangApp::demonstratePolymorphism() {
    clearScreen();
    std::cout << "╔═══════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                    DEMO ĐA HÌNH (POLYMORPHISM)                ║\n";
    std::cout << "╚═══════════════════════════════════════════════════════════════╝\n\n";

    // Create sample orders
    std::vector<std::unique_ptr<DonHang>> demoOrders;

    // Create domestic order
    auto donHangTN = std::make_unique<DonHangTrongNuoc>("DH001", Ngay(15, 1, 2024), "nhanh", 100000);
    demoOrders.push_back(std::move(donHangTN));

    // Create international order
    auto donHangQT = std::make_unique<DonHangQuocTe>("DH002", Ngay(16, 1, 2024), "hoa toc", 200000);
    demoOrders.push_back(std::move(donHangQT));

    std::cout << "🎯 Demonstrating Polymorphism:\n";
    std::cout << "Cùng một con trỏ DonHang* nhưng gọi các phương thức khác nhau!\n\n";

    for (size_t i = 0; i < demoOrders.size(); ++i) {
        std::cout << "📦 Demo Order #" << (i + 1) << ":\n";

        // Polymorphic method calls
        demoOrders[i]->InThongTin();  // Calls appropriate derived class method

        std::cout << "\n💰 Tổng tiền (polymorphic call): "
            << demoOrders[i]->TinhTongTien() << " VND\n\n";  // Calls appropriate derived class method
    }

    std::cout << "✨ Đây chính là đa hình! Cùng một interface nhưng hành vi khác nhau!\n";
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
            themDonHangTrongNuoc();
            break;
        case 2:
            themDonHangQuocTe();
            break;
        case 3:
            hienThiTatCaDonHang();
            break;
        case 4:
            timKiemDonHang();
            break;
        case 5:
            tinhTongDoanhThu();
            break;
        case 6:
            thongKeDonHang();
            break;
        case 7:
            demonstratePolymorphism();
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
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    std::cout << "🚀 Khởi động hệ thống quản lý đơn hàng với kế thừa và đa hình...\n\n";

    QuanLyDonHangApp app;
    app.chayUngDung();

    return 0;
}
