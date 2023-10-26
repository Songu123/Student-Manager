//
// Created by MacBook on 26/10/2023.
//

#include "File.h"
#include "SinhVien.cpp"
#include <fstream>
using namespace std;
class File{
public:
// Ghi File
    void writeObjectsToFile(const std::vector<SinhVien>& objects, const std::string& filename) {
        std::ofstream file(filename, std::ios::binary);
        if (file.is_open()) {
            for (const auto& obj : objects) {
                file.write(reinterpret_cast<const char*>(&obj), sizeof(SinhVien));
            }
            file.close();
            std::cout << "Objects written to file successfully." << std::endl;
        } else {
            std::cerr << "Failed to open file for writing." << std::endl;
        }
    }
// Đọc File
    vector<SinhVien> readObjectsFromFile(const std::string& filename) {
        std::vector<SinhVien> objects;
        std::ifstream file(filename, std::ios::binary);
        if (file.is_open()) {
            SinhVien obj;
            while (file.read(reinterpret_cast<char*>(&obj), sizeof(SinhVien))) {
                objects.push_back(obj);
            }
            file.close();
            std::cout << "Objects read from file successfully." << std::endl;
        } else {
            std::cerr << "Failed to open file for reading." << std::endl;
        }
        return objects;
    }
};
