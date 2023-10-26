//
// Created by MacBook on 26/10/2023.
//

#include "Functions.h"
#include "SinhVien.cpp"
#include "iomanip"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string_view>
using namespace std;
class Functions {
public:
    static void nhapThongTinSV(vector<SinhVien>& sv) {
        string gioiTinh, hoTen;
        char id[30];
        double diemToan, diemLy, diemHoa, diemTrungBinh;
        string hocLuc;
        cout << "\nNhập id: ";
        cin >> id;
        cout << "\nNhập họ tên: ";
        cin.ignore();
        getline(cin, hoTen);
        int n;
        cout << "Nhập giới tính chọn (1) Nam, (2) Nữ, (3) Giới Tính Thứ 3: ";
        cin >> n;
        while(true) {
            if(n == 1 || n == 2 || n == 3) {
                if (n == 1){
                    gioiTinh = "Nam";
                }else if (n == 2){
                    gioiTinh = "Nữ";
                }else if (n == 3){
                    gioiTinh = "Giới Tính Thứ 3";
                }
                break;
            } else {
                cout << "Giới tính chọn không hợp lệ. Nhập giới tính chọn (1) Nam, (2) Nữ, (3) Giới Tính Thứ 3: ";
                cin >> n;
            }
        }
        cout << "Nhập điểm toán: ";
        cin >> diemToan;
        cout << "Nhập điểm lý: ";
        cin >> diemLy;
        cout << "Nhập điểm hóa: ";
        cin >> diemHoa;

        diemTrungBinh = (diemToan + diemHoa + diemLy) / 3;
        if(diemTrungBinh > 9){
            hocLuc = "Xuất sắc";
        } else if (diemTrungBinh > 8) {
            hocLuc = "Giỏi";
        } else if (diemTrungBinh > 6) {
            hocLuc = "Khá";
        } else if (diemTrungBinh > 5) {
            hocLuc = "Trung bình";
        } else {
            hocLuc = "Yếu";
        }
        SinhVien sinhVien(id, hoTen, gioiTinh, diemToan, diemLy, diemHoa, diemTrungBinh, hocLuc);
        // Tạo một đối tượng SinhVien và thêm vào vector
        sv.push_back(sinhVien);
    }
//Hiển thị danh sách sinh viên
    static void hienThiDanhSachSV(const vector<SinhVien>& sv) {
        int i = 0;
        for (const SinhVien& sinhVien : sv) {
            cout << "\nID: " << sinhVien.getId();
            cout << ", Họ tên: " << sinhVien.getHoTen();
            cout << ", Giới tính: " << sinhVien.getGioiTinh();
            cout << ", Điểm toán: " << sinhVien.getDiemToan();
            cout << ", Điểm lý: " << sinhVien.getDiemLy();
            cout << ", Điểm hóa: " << sinhVien.getDiemHoa();
            cout << ", Điểm trung bình: " << setprecision(1) << fixed << sinhVien.getDiemTrungBinh();
            cout << ", Học lực: " << sinhVien.getHocLuc() << endl;
            cout << "-------------------------------" << endl;
        }
    }
//Xoá sinh viên theo id
    void xoaSinhVienTheoID(vector<SinhVien>& sv, string idXoa) {
        sv.erase(std::remove_if(sv.begin(), sv.end(), [idXoa](const SinhVien& sv) {
            return sv.getId() == idXoa;
        }), sv.end());
    }
//Xoá hê các sinh viên trong danh sách
    void xoaCacSinhVien(vector<SinhVien>& sv){
        sv.clear();
        cout << "\nDanh sách sinh viên rỗng!!!" << endl;
    }
//Tìm kiếm sinh viên theo tên
    void timKiemSVTheoChuoiCuoiTen(const vector<SinhVien>& sv, const string& tenTimKiem) {
        bool found = false;
        for (const SinhVien& sinhVien : sv) {
            const string& hoTen = sinhVien.getHoTen();
            size_t lastWhitespacePos = hoTen.find_last_of(" \t");
            string_view ten = hoTen.substr(lastWhitespacePos + 1);
            if(tenTimKiem == ten){
                cout << "\nID: " << sinhVien.getId();
                cout << ", Họ tên: " << sinhVien.getHoTen();
                cout << ", Giới tính: " << sinhVien.getGioiTinh();
                cout << ", Điểm toán: " << sinhVien.getDiemToan();
                cout << ", Điểm lý: " << sinhVien.getDiemLy();
                cout << ", Điểm hóa: " << sinhVien.getDiemHoa();
                cout << ", Điểm trung bình: " << setprecision(1) << fixed << sinhVien.getDiemTrungBinh();
                cout << ", Học lực: " << sinhVien.getHocLuc() << endl;
                found = true;
            }
        }
        if(!found){
            cout << "\nKhông tìm thấy sinh viên với tên " << tenTimKiem << " !!!" << endl;
        }
    }
//Sắp xếp sinh viên theo điểm
    static bool comparatorDiemTB(const SinhVien& sv1, const SinhVien& sv2) {

        return sv1.getDiemTrungBinh() > sv2.getDiemTrungBinh();
    }

    void sapXepSVTheoDiem(vector<SinhVien>& sv) {

        sort(sv.begin(), sv.end(), comparatorDiemTB);
    }
//Sắp xếp sinh viên theo tên
    static bool comparatorTen(const SinhVien& sv1, const SinhVien& sv2) {
        size_t pos1 = sv1.getHoTen().find_last_of(" ");
        size_t pos2 = sv2.getHoTen().find_last_of(" ");
        std::string ten1 = sv1.getHoTen().substr(pos1 + 1);
        std::string ten2 = sv2.getHoTen().substr(pos2 + 1);

        return ten1 < ten2;
    }

    void sapXepSVTheoTen(vector<SinhVien>& sv) {

        sort(sv.begin(), sv.end(), comparatorTen);
    }
};