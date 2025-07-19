#ifndef DONHANGTRONGNUOC_H
#define DONHANGTRONGNUOC_H

#include "DonHang.h"

class DonHangTrongNuoc : public DonHang {
private:
    double phiVanChuyen;

public:
    // Constructors
    DonHangTrongNuoc();
    DonHangTrongNuoc(const std::string& ma, const Ngay& ngay,
        const std::string& loai, double phi);

    // Destructor
    virtual ~DonHangTrongNuoc();

    // Getter and Setter
    double getPhiVanChuyen() const;
    void setPhiVanChuyen(double phi);

    // Override virtual 
    virtual double TinhTongTien() override;
    virtual void InThongTin() override;

    //input/output
    friend std::istream& operator>>(std::istream& is, DonHangTrongNuoc& dh);
    friend std::ostream& operator<<(std::ostream& os, const DonHangTrongNuoc& dh);
};

#endif
