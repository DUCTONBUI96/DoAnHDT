#ifndef DONHANGQUOCTE_H
#define DONHANGQUOCTE_H

#include "DonHang.h"

class DonHangQuocTe : public DonHang {
private:
    double phiHaiQuan;

public:
    // Constructors
    DonHangQuocTe();
    DonHangQuocTe(const std::string& ma, const Ngay& ngay,
        const std::string& loai, double phi);

    // Destructor
    virtual ~DonHangQuocTe();

    // Getter and Setter
    double getPhiHaiQuan() const;
    void setPhiHaiQuan(double phi);

    // Override virtual 
    virtual double TinhTongTien() override;
    virtual void InThongTin() override;

    //input/output
    friend std::istream& operator>>(std::istream& is, DonHangQuocTe& dh);
    friend std::ostream& operator<<(std::ostream& os, const DonHangQuocTe& dh);
};

#endif
