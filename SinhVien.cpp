//
// Created by MacBook on 23/10/2023.
//
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX 100
#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <string>
using namespace std;
class SinhVien {
private:
    char id[30];
    string hoTen;
    string gioiTinh;
    double diemToan;
    double diemLy;
    double diemHoa;
    double diemTrungBinh;
    string hocLuc;

public:
    SinhVien() {
        // Initialize member variables with default values
        strcpy(id, "0");
        hoTen = "";
        gioiTinh = "";
        diemToan = 0;
        diemLy = 0;
        diemHoa = 0;
        diemTrungBinh = 0;
        hocLuc = "";
    }

    SinhVien(const char id[30], string hoTen, string gioiTinh, double diemToan, double diemLy, double diemHoa, double diemTrungBinh, string hocLuc) {
        strcpy(this->id, id);
        this->hoTen = hoTen;
        this->gioiTinh = gioiTinh;
        this->diemToan = diemToan;
        this->diemLy = diemLy;
        this->diemHoa = diemHoa;
        this->diemTrungBinh = diemTrungBinh;
        this->hocLuc = hocLuc;
    }

    const char* getId() const {
        return id;
    }

    void setId(const char id[30]) {
        strcpy(this->id, id);
    }

    const string& getHoTen() const {
        return hoTen;
    }

    void setHoTen(const string& hoTen) {
        this->hoTen = hoTen;
    }

    const string& getGioiTinh() const {
        return gioiTinh;
    }

    void setGioiTinh(const string& gioiTinh) {
        this->gioiTinh = gioiTinh;
    }

    double getDiemToan() const {
        return diemToan;
    }

    void setDiemToan(double diemToan) {
        this->diemToan = diemToan;
    }

    double getDiemLy() const {
        return diemLy;
    }

    void setDiemLy(double diemLy) {
        this->diemLy = diemLy;
    }

    double getDiemHoa() const {
        return diemHoa;
    }

    void setDiemHoa(double diemHoa) {
        this->diemHoa = diemHoa;
    }

    double getDiemTrungBinh() const {
        return diemTrungBinh;
    }

    void setDiemTrungBinh(double diemTrungBinh) {
        this->diemTrungBinh = diemTrungBinh;
    }

    const string& getHocLuc() const {
        return hocLuc;
    }

    void setHocLuc(const string& hocLuc) {
        this->hocLuc = hocLuc;
    }
};

#endif // SINHVIEN_H