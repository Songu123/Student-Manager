#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX 100
#include <string_view>
#include "SinhVien.cpp"
#include <fstream>
using namespace std;
//Nhập thông tin Sinh Viên
void nhapThongTinSV(vector<SinhVien>& sv, int& idCount) {
    string id, gioiTinh, hoTen;
    double diemToan, diemLy, diemHoa, diemTrungBinh;
    string hocLuc;
    id = idCount;
    cout << "\nNhập họ tên: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "Nhập giới tính: ";
    cin >> gioiTinh;
    cout << "Nhập điểm toán: ";
    cin >> diemToan;
    cout << "Nhập điểm lý: ";
    cin >> diemLy;
    cout << "Nhập điểm hóa: ";
    cin >> diemHoa;

    diemTrungBinh = (diemToan + diemHoa + diemLy) / 3;
    if (diemTrungBinh > 8) {
        hocLuc = "Giỏi";
    } else if (diemTrungBinh > 6) {
        hocLuc = "Khá";
    } else if (diemTrungBinh > 5) {
        hocLuc = "Trung bình";
    } else {
        hocLuc = "Yếu";
    }
    SinhVien sinhVien(idCount, hoTen, gioiTinh, diemToan, diemLy, diemHoa, diemTrungBinh, hocLuc);
    // Tạo một đối tượng SinhVien và thêm vào vector
    sv.push_back(sinhVien);
    idCount ++;

}
//Hiển thị danh sách sinh viên
void hienThiDanhSachSV(const vector<SinhVien>& sv) {
    int i = 0;
    for (const SinhVien& sinhVien : sv) {

//        cout << "\nID: " << sinhVien.getId() << endl;
//        cout << "Họ tên: " << sinhVien.getHoTen() << endl;
//        cout << "Giới tính: " << sinhVien.getGioiTinh() << endl;
//        cout << "Điểm toán: " << sinhVien.getDiemToan() << endl;
//        cout << "Điểm lý: " << sinhVien.getDiemLy() << endl;
//        cout << "Điểm hóa: " << sinhVien.getDiemHoa() << endl;
//        cout << "Điểm trung bình: " << sinhVien.getDiemTrungBinh() << endl;
//        cout << "Học lực: " << sinhVien.getHocLuc() << endl;
//        cout << "-------------------------------" << endl;

        cout << "\nID: " << sinhVien.getId();
        cout << ", Họ tên: " << sinhVien.getHoTen();
        cout << ", Giới tính: " << sinhVien.getGioiTinh();
        cout << ", Điểm toán: " << sinhVien.getDiemToan();
        cout << ", Điểm lý: " << sinhVien.getDiemLy();
        cout << ", Điểm hóa: " << sinhVien.getDiemHoa();
        cout << ", Điểm trung bình: " << sinhVien.getDiemTrungBinh();
        cout << ", Học lực: " << sinhVien.getHocLuc() << endl;
        cout << "-------------------------------" << endl;
    }
}
//Xoá sinh viên theo id
void xoaSinhVienTheoID(vector<SinhVien>& sv, int idXoa) {
        for (int i = 0; i < sv.size(); i++) {
            if (sv[i].getId() == idXoa) {
                sv.erase(sv.begin() + i);
                break;
            }
        }
}

//Tìm kiếm sinh viên theo tên
void timKiemSVTheoChuoiCuoiTen(const vector<SinhVien>& sv, const string& tenXoa) {
    bool found = false;
    for (const SinhVien& sinhVien : sv) {
        string hoTen = sinhVien.getHoTen();
        size_t lastWhitespacePos = hoTen.find_last_of(" \t");
        string_view ten = hoTen.substr(lastWhitespacePos + 1);
        if(tenXoa == ten){
            cout << "\nID: " << sinhVien.getId();
            cout << ", Họ tên: " << sinhVien.getHoTen();
            cout << ", Giới tính: " << sinhVien.getGioiTinh();
            cout << ", Điểm toán: " << sinhVien.getDiemToan();
            cout << ", Điểm lý: " << sinhVien.getDiemLy();
            cout << ", Điểm hóa: " << sinhVien.getDiemHoa();
            cout << ", Điểm trung bình: " << sinhVien.getDiemTrungBinh();
            cout << ", Học lực: " << sinhVien.getHocLuc() << endl;
            found = true;
        }
    }
    if(found == false){
        cout << "\nKhông tìm thấy sinh viên với tên " << tenXoa << " !!!" << endl;
    }
}
//Sắp xếp sinh viên theo điểm
bool comparatorDiemTB(const SinhVien& sv1, const SinhVien& sv2) {

    return sv1.getDiemTrungBinh() > sv2.getDiemTrungBinh();
}

void sapXepSVTheoDiem(vector<SinhVien>& sv) {

    sort(sv.begin(), sv.end(), comparatorDiemTB);
}
//Sắp xếp sinh viên theo tên
bool comparatorTen(const SinhVien& sv1, const SinhVien& sv2) {
    size_t pos1 = sv1.getHoTen().find_last_of(" ");
    size_t pos2 = sv2.getHoTen().find_last_of(" ");
    std::string ten1 = sv1.getHoTen().substr(pos1 + 1);
    std::string ten2 = sv2.getHoTen().substr(pos2 + 1);

    return ten1 < ten2;
}

void sapXepSVTheoTen(vector<SinhVien>& sv) {

    sort(sv.begin(), sv.end(), comparatorTen);
}
int main() {
    vector<SinhVien> sv;
    bool display = true;
    int idCount = 0; // Khởi tạo biến idCount

    while (display) {
        cout << "\nChương trình Quản Lý Sinh Viên!!!!";
        cout << "\n*************MENU****************";
        cout << "\n1. Thêm Sinh Viên.";
        cout << "\n2. Hiển thị danh sách Sinh viên.";
        cout << "\n3. Xoá Sinh Viên bằng id.";
        cout << "\n4. Tìm kiếm Sinh Viên theo tên.";
        cout << "\n5. Sắp xếp sinh viên theo điểm.";
        cout << "\n6. Sắp xếp sinh viên theo tên.";
        cout << "\n0. Thoát chương trình"
             << "\n";
        cout << "Chọn chương trình: ";
        int luaChon;
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                cout << "----------------------------------" << endl;
                cout << "Thêm Sinh Viên";
                nhapThongTinSV(sv, idCount);
                break;
            case 2:
                cout << "\n======Danh sách Sinh Viên=====" << endl;
                hienThiDanhSachSV(sv);
                break;
            case 3:
                cout << "Xoá Sinh Viên bằng id";
                int id;
                cout << "\nNhập ID: ";
                cin >> id;
                xoaSinhVienTheoID(sv, id);
                break;
            case 4:
                cout << "Tìm kiếm Sinh Viên theo tên";
                char strTen[30];
                cout << "\nNhập tên để tìm kiếm: ";
                cin >> strTen;
                timKiemSVTheoChuoiCuoiTen(sv, strTen);
                break;
            case 5:
                cout << "Sắp xếp sinh viên theo điểm";
                sapXepSVTheoDiem(sv);
                cout << "\nĐã sắp xếp xong, mời bạn nhấn số 2 để kiểm tra!" << endl;
                break;
            case 6:
                cout << "Sắp xếp sinh viên theo tên";
                sapXepSVTheoTen(sv);
                cout << "\nĐã sắp xếp xong, mời bạn nhấn số 2 để kiểm tra!" << endl;
                break;
            case 0:
                cout << "Đã thoát chương trình!!!";
                display = false;
                break;
            default:
                cout << "Chưa nhập đúng chương trình. Vui lòng nhập lại." << endl;
                break;
        }
    }
    return 0;
}
