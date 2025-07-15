#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <ctime>
#include <iomanip>
#include "QuanLyDonHang.h"

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
};

void QuanLyDonHangApp::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void QuanLyDonHangApp::waitForEnter() {
    std::cout << "\nNh?n Enter d? ti?p t?c...";
    std::cin.ignore();
    std::cin.get();
}

void QuanLyDonHangApp::hienThiMenu() {
    std::cout << "+-----------------------------------------------------------+\n";
    std::cout << "�                  H? TH?NG QU?N L� �ON H�NG               �\n";
    std::cout << "�-----------------------------------------------------------�\n";
    std::cout << "�  1. Th�m don h�ng m?i                                     �\n";
    std::cout << "�  2. Hi?n th? t?t c? don h�ng                              �\n";
    std::cout << "�  3. T�m ki?m don h�ng                                     �\n";
    std::cout << "�  4. C?p nh?t don h�ng                                     �\n";
    std::cout << "�  5. X�a don h�ng                                          �\n";
    std::cout << "�  6. Th?ng k� don h�ng                                     �\n";
    std::cout << "�  0. Tho�t chuong tr�nh                                    �\n";
    std::cout << "+-----------------------------------------------------------+\n";
    std::cout << "Nh?p l?a ch?n c?a b?n: ";
}

std::string QuanLyDonHangApp::chonLoaiVanChuyen() {
    int choice;
    std::cout << "\n+-------------------------------------+\n";
    std::cout << "�        LO?I G�I V?N CHUY?N          �\n";
    std::cout << "+-------------------------------------�\n";
    std::cout << "� 1. Giao h�ng ti�u chu?n             �\n";
    std::cout << "� 2. Giao h�ng nhanh                  �\n";
    std::cout << "� 3. Giao h�ng si�u t?c               �\n";
    std::cout << "� 4. Giao h�ng trong ng�y             �\n";
    std::cout << "+-------------------------------------+\n";
    std::cout << "Ch?n lo?i v?n chuy?n (1-4): ";

    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
    case 1: return "Giao h�ng ti�u chu?n";
    case 2: return "Giao h�ng nhanh";
    case 3: return "Giao h�ng si�u t?c";
    case 4: return "Giao h�ng trong ng�y";
    default: return "Giao h�ng ti�u chu?n";
    }
}

std::time_t QuanLyDonHangApp::nhapNgay() {
    int ngay, thang, nam, gio, phut;
    std::cout << "Nh?p ng�y (dd mm yyyy hh mm): ";
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
    std::cout << "+---------------------------------------+\n";
    std::cout << "�           TH�M �ON H�NG M?I          �\n";
    std::cout << "+---------------------------------------+\n\n";

    std::string maDonHang;
    std::cout << "Nh?p m� don h�ng: ";
    std::getline(std::cin, maDonHang);

    // Check if order ID already exists
    for (const auto& donHang : danhSachDonHang) {
        if (donHang.getMaDonHang() == maDonHang) {
            std::cout << "? M� don h�ng d� t?n t?i!\n";
            waitForEnter();
            return;
        }
    }

    std::time_t ngayDatHang = nhapNgay();
    std::string loaiVanChuyen = chonLoaiVanChuyen();

    QuanLyDonHang donHangMoi(maDonHang, ngayDatHang, loaiVanChuyen);
    danhSachDonHang.push_back(donHangMoi);

    std::cout << "\n? �� th�m don h�ng th�nh c�ng!\n";
    donHangMoi.hienThiThongTin();
    waitForEnter();
}

void QuanLyDonHangApp::hienThiTatCaDonHang() {
    clearScreen();
    std::cout << "+---------------------------------------+\n";
    std::cout << "�        DANH S�CH T?T C? �ON H�NG     �\n";
    std::cout << "+---------------------------------------+\n\n";

    if (danhSachDonHang.empty()) {
        std::cout << "? Kh�ng c� don h�ng n�o trong h? th?ng.\n";
        waitForEnter();
        return;
    }

    std::cout << "T?ng s? don h�ng: " << danhSachDonHang.size() << "\n\n";

    for (size_t i = 0; i < danhSachDonHang.size(); ++i) {
        std::cout << "?? �on h�ng #" << (i + 1) << ":\n";
        danhSachDonHang[i].hienThiThongTin();
        std::cout << "\n";
    }

    waitForEnter();
}

void QuanLyDonHangApp::timKiemDonHang() {
    clearScreen();
    std::cout << "+---------------------------------------+\n";
    std::cout << "�           T�M KI?M �ON H�NG          �\n";
    std::cout << "+---------------------------------------+\n\n";

    std::string maTim;
    std::cout << "Nh?p m� don h�ng c?n t�m: ";
    std::getline(std::cin, maTim);

    bool timThay = false;
    for (const auto& donHang : danhSachDonHang) {
        if (donHang.getMaDonHang() == maTim) {
            std::cout << "\n? T�m th?y don h�ng:\n";
            donHang.hienThiThongTin();
            timThay = true;
            break;
        }
    }

    if (!timThay) {
        std::cout << "\n? Kh�ng t�m th?y don h�ng v?i m�: " << maTim << "\n";
    }

    waitForEnter();
}

void QuanLyDonHangApp::capNhatDonHang() {
    clearScreen();
    std::cout << "+---------------------------------------+\n";
    std::cout << "�          C?P NH?T �ON H�NG           �\n";
    std::cout << "+---------------------------------------+\n\n";

    std::string maTim;
    std::cout << "Nh?p m� don h�ng c?n c?p nh?t: ";
    std::getline(std::cin, maTim);

    for (auto& donHang : danhSachDonHang) {
        if (donHang.getMaDonHang() == maTim) {
            std::cout << "\n?? Th�ng tin hi?n t?i:\n";
            donHang.hienThiThongTin();

            int choice;
            std::cout << "\nCh?n th�ng tin c?n c?p nh?t:\n";
            std::cout << "1. M� don h�ng\n";
            std::cout << "2. Ng�y d?t h�ng\n";
            std::cout << "3. Lo?i g�i v?n chuy?n\n";
            std::cout << "Nh?p l?a ch?n: ";
            std::cin >> choice;
            std::cin.ignore();

            switch (choice) {
            case 1: {
                std::string maMoi;
                std::cout << "Nh?p m� don h�ng m?i: ";
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
                std::cout << "? L?a ch?n kh�ng h?p l?!\n";
                waitForEnter();
                return;
            }

            std::cout << "\n? C?p nh?t th�nh c�ng!\n";
            std::cout << "?? Th�ng tin sau khi c?p nh?t:\n";
            donHang.hienThiThongTin();
            waitForEnter();
            return;
        }
    }

    std::cout << "\n? Kh�ng t�m th?y don h�ng v?i m�: " << maTim << "\n";
    waitForEnter();
}

void QuanLyDonHangApp::xoaDonHang() {
    clearScreen();
    std::cout << "+---------------------------------------+\n";
    std::cout << "�            X�A �ON H�NG              �\n";
    std::cout << "+---------------------------------------+\n\n";

    std::string maTim;
    std::cout << "Nh?p m� don h�ng c?n x�a: ";
    std::getline(std::cin, maTim);

    auto it = std::find_if(danhSachDonHang.begin(), danhSachDonHang.end(),
        [&maTim](const QuanLyDonHang& donHang) {
            return donHang.getMaDonHang() == maTim;
        });

    if (it != danhSachDonHang.end()) {
        std::cout << "\n?? Th�ng tin don h�ng s? b? x�a:\n";
        it->hienThiThongTin();

        char xacNhan;
        std::cout << "\nB?n c� ch?c ch?n mu?n x�a? (y/n): ";
        std::cin >> xacNhan;
        std::cin.ignore();

        if (xacNhan == 'y' || xacNhan == 'Y') {
            danhSachDonHang.erase(it);
            std::cout << "\n? �� x�a don h�ng th�nh c�ng!\n";
        }
        else {
            std::cout << "\n? H?y thao t�c x�a.\n";
        }
    }
    else {
        std::cout << "\n? Kh�ng t�m th?y don h�ng v?i m�: " << maTim << "\n";
    }

    waitForEnter();
}

void QuanLyDonHangApp::thongKeDonHang() {
    clearScreen();
    std::cout << "+---------------------------------------+\n";
    std::cout << "�           TH?NG K� �ON H�NG          �\n";
    std::cout << "+---------------------------------------+\n\n";

    if (danhSachDonHang.empty()) {
        std::cout << "? Kh�ng c� don h�ng n�o d? th?ng k�.\n";
        waitForEnter();
        return;
    }

    // Count shipping types
    int tieuChuan = 0, nhanh = 0, sieuToc = 0, trongNgay = 0;

    for (const auto& donHang : danhSachDonHang) {
        std::string loai = donHang.getLoaiGoiVanChuyen();
        if (loai == "Giao h�ng ti�u chu?n") tieuChuan++;
        else if (loai == "Giao h�ng nhanh") nhanh++;
        else if (loai == "Giao h�ng si�u t?c") sieuToc++;
        else if (loai == "Giao h�ng trong ng�y") trongNgay++;
    }

    std::cout << "+---------------------------------------------------------+\n";
    std::cout << "�                    TH?NG K� T?NG QUAN                   �\n";
    std::cout << "+---------------------------------------------------------�\n";
    std::cout << "� T?ng s? don h�ng        : " << std::setw(25) << danhSachDonHang.size() << "�\n";
    std::cout << "� Giao h�ng ti�u chu?n    : " << std::setw(25) << tieuChuan << "�\n";
    std::cout << "� Giao h�ng nhanh         : " << std::setw(25) << nhanh << "�\n";
    std::cout << "� Giao h�ng si�u t?c      : " << std::setw(25) << sieuToc << "�\n";
    std::cout << "� Giao h�ng trong ng�y    : " << std::setw(25) << trongNgay << "�\n";
    std::cout << "+---------------------------------------------------------+\n";

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
            std::cout << "\n?? C?m on b?n d� s? d?ng h? th?ng!\n";
            break;
        default:
            std::cout << "\n? L?a ch?n kh�ng h?p l?! Vui l�ng th? l?i.\n";
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
