#include <fstream>
#include <vector>
#include "SinhVien.cpp"
#include <string>
#include "Functions.cpp"
using namespace std;

int main() {
//    Khai báo lớp Functions
    Functions functions = *new Functions();
//    Khai báo địa chỉ file
    const std::string filePath = "/Users/macbook/Documents/1.C:C++/Lập trình C++/C++ OOP/Student Manager/FileData.txt";
//    Lưu danh sách vào file và đọc
    std::vector<SinhVien> sv = functions.readObjectsFromFile(filePath);
    bool display = true;
    while (display) {
        cout << "\nChương trình Quản Lý Sinh Viên!!!!";
        cout << "\n*************MENU****************";
        cout << "\n1. Thêm Sinh Viên.";
        cout << "\n2. Hiển thị danh sách Sinh viên.";
        cout << "\n3. Xoá Sinh Viên bằng id.";
        cout << "\n4. Tìm kiếm Sinh Viên theo tên.";
        cout << "\n5. Sắp xếp sinh viên theo điểm.";
        cout << "\n6. Sắp xếp sinh viên theo tên.";
        cout << "\n7. Làm rỗng danh sách sinh viên.";
        cout << "\n0. Thoát chương trình"
             << "\n";
        cout << "Chọn chương trình: ";
        int luaChon;
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                cout << "----------------------------------" << endl;
                cout << "Thêm Sinh Viên";
                functions.nhapThongTinSV(sv);
                functions.writeObjectsToFile(sv,filePath);
                break;
            case 2:
                cout << "\n======Danh sách Sinh Viên=====" << endl;
                functions.hienThiDanhSachSV(sv);
                break;
            case 3:
                char id[30];
                cout << "\nNhập id để xoá: ";
                cin >> id;
                functions.xoaSinhVienTheoID(sv, id);
                functions.writeObjectsToFile(sv,filePath);
                break;
            case 4:
                cout << "Tìm kiếm Sinh Viên theo tên";
                char strTen[30];
                cout << "\nNhập tên để tìm kiếm: ";
                cin >> strTen;
                functions.timKiemSVTheoChuoiCuoiTen(sv, strTen);
                break;
            case 5:
                cout << "Sắp xếp sinh viên theo điểm";
                functions.sapXepSVTheoDiem(sv);
                cout << "\nĐã sắp xếp xong, mời bạn nhấn số 2 để kiểm tra!" << endl;
                functions.writeObjectsToFile(sv,filePath);
                break;
            case 6:
                cout << "Sắp xếp sinh viên theo tên";
                functions.sapXepSVTheoTen(sv);
                cout << "\nĐã sắp xếp xong, mời bạn nhấn số 2 để kiểm tra!" << endl;
                functions.writeObjectsToFile(sv,filePath);
                break;
            case 7:
                cout << "Làm rỗng danh sách sinh viên";
                functions.xoaCacSinhVien(sv);
                functions.writeObjectsToFile(sv,filePath);
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
