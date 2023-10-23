//
// Created by MacBook on 23/10/2023.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX 100
#include <string>
using namespace std;
class SinhVien{
private:
    int id;
    string hoTen;
    string gioiTinh;
    double diemToan;
    double diemLy;
    double diemHoa;
    double diemTrungBinh;
    string hocLuc;

public:
    SinhVien() {
        // Initialize member variables with default values or leave them uninitialized.
        id = 0;
        hoTen = "";
        gioiTinh = "";
        diemToan = 0;
        diemLy = 0;
        diemHoa = 0;
        diemTrungBinh = 0;
        hocLuc = "";
    }
    SinhVien(int id, string hoTen, string gioiTinh, double diemToan, double diemLy, double diemHoa, double diemTrungBinh, string hocLuc){
        this->id = id;
        this->hoTen = hoTen;
        this->gioiTinh = gioiTinh;
        this->diemToan = diemToan;
        this->diemLy = diemLy;
        this->diemHoa = diemHoa;
        this->diemTrungBinh = diemTrungBinh;
        this->hocLuc = hocLuc;
    }

    const int &getId() const {
        return id;
    }

    void setId(const int &id) {
        SinhVien::id = id;
    }

    const string &getHoTen() const {
        return hoTen;
    }

    void setHoTen(const string &hoTen) {
        SinhVien::hoTen = hoTen;
    }

    const string &getGioiTinh() const {
        return gioiTinh;
    }

    void setGioiTinh(const string &gioiTinh) {
        SinhVien::gioiTinh = gioiTinh;
    }

    int getDiemToan() const {
        return diemToan;
    }

    void setDiemToan(int diemToan) {
        SinhVien::diemToan = diemToan;
    }

    int getDiemLy() const {
        return diemLy;
    }

    void setDiemLy(int diemLy) {
        SinhVien::diemLy = diemLy;
    }

    int getDiemHoa() const {
        return diemHoa;
    }

    void setDiemHoa(int diemHoa) {
        SinhVien::diemHoa = diemHoa;
    }

    int getDiemTrungBinh() const {
        return diemTrungBinh;
    }

    void setDiemTrungBinh(int diemTrungBinh) {
        SinhVien::diemTrungBinh = diemTrungBinh;
    }

    const string &getHocLuc() const {
        return hocLuc;
    }

    void setHocLuc(const string &hocLuc) {
        SinhVien::hocLuc = hocLuc;
    }
};