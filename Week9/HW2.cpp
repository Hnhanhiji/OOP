#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Cấu trúc lưu trữ dữ liệu Đơn Hàng dùng chung cho các bài sau
struct DonHang {
    string maDon;
    string tenKhach;
    string sdt;
    string monAn;
    string trangThai;
    string diaChi;
};

// ================= CÁC HÀM HỖ TRỢ =================

// Hàm hỗ trợ Bài 2: Chuẩn hóa chuỗi (Viết hoa chữ đầu, bỏ khoảng trắng thừa)
string chuanHoaTenMon(string s) {
    stringstream ss(s);
    string word;
    string result = "";
    
    // Đọc từng từ (tự động bỏ qua nhiều khoảng trắng)
    while (ss >> word) {
        // Viết hoa chữ cái đầu
        word[0] = toupper(word[0]);
        // Viết thường các chữ cái sau
        for (int i = 1; i < word.length(); i++) {
            word[i] = tolower(word[i]);
        }
        result += word + " ";
    }
    
    // Xóa khoảng trắng cuối cùng nếu có
    if (!result.empty()) {
        result.pop_back(); 
    }
    return result;
}

// Hàm hỗ trợ Bài 7: Chuyển chuỗi thành in thường để tìm kiếm không phân biệt hoa/thường
string toLowerCase(string s) {
    string res = s;
    for (char &c : res) {
        c = tolower(c);
    }
    return res;
}

// ================= HÀM MAIN =================

int main() {
    // Dữ liệu mẫu để test các bài tập
    vector<string> menuQuan = {"Pizza Hai San", "Burger Bo", "My Y", "Tra Sua"};
    vector<DonHang> danhSachDon = {
        {"DH01", "Nguyen Van An", "0901234567", "Pizza Hai San", "Dang chuan bi", "Quan 1"},
        {"DH02", "Tran Thi Binh", "0987654321", "My Y", "Dang giao", "Quan 3"},
        {"DH03", "Le Van An", "0911111111", "Pizza Hai San", "Hoan thanh", "Quan 5"}
    };

    cout << "========== CHUONG TRINH QUAN LY GIAO DO AN ==========\n\n";

    // ---------------------------------------------------------
    // Bài 1: Nhập và hiển thị tên cửa hàng
    // ---------------------------------------------------------
    cout << "--- Bai 1: ---" << endl;
    string tenCuaHang = "Good Food"; 
    // Nếu muốn nhập từ bàn phím: getline(cin, tenCuaHang);
    cout << "Chao mung den voi [" << tenCuaHang << "]!\n\n";


    // ---------------------------------------------------------
    // Bài 2: Chuẩn hóa tên món ăn
    // ---------------------------------------------------------
    cout << "--- Bai 2: ---" << endl;
    string monAnChuaChuan = "   piZZa   hAi   San   ";
    string monAnDaChuan = chuanHoaTenMon(monAnChuaChuan);
    cout << "Ten ban dau : '" << monAnChuaChuan << "'" << endl;
    cout << "Da chuan hoa: '" << monAnDaChuan << "'\n\n";


    // ---------------------------------------------------------
    // Bài 3: Tạo mã đơn hàng (VD: DH + 4 số cuối sdt)
    // ---------------------------------------------------------
    cout << "--- Bai 3: ---" << endl;
    string tenKhach = "An";
    string sdt = "0901234567";
    // Lấy 4 số cuối của SĐT
    string maMoi = "DH_" + tenKhach + "_" + sdt.substr(sdt.length() - 4); 
    cout << "Khach: " << tenKhach << " | SDT: " << sdt << endl;
    cout << "Ma don hang duoc tao: " << maMoi << "\n\n";


    // ---------------------------------------------------------
    // Bài 4: Kiểm tra món ăn
    // ---------------------------------------------------------
    cout << "--- Bai 4: ---" << endl;
    string monKiemTra = "Burger Bo";
    bool coTrongMenu = false;
    for (string mon : menuQuan) {
        if (mon == monKiemTra) {
            coTrongMenu = true;
            break;
        }
    }
    if (coTrongMenu) {
        cout << "Mon '" << monKiemTra << "' co san trong thuc don.\n\n";
    } else {
        cout << "Mon '" << monKiemTra << "' khong ton tai.\n\n";
    }

   
    // ---------------------------------------------------------
    // Bài 6: Thay đổi trạng thái đơn hàng
    // ---------------------------------------------------------
    cout << "--- Bai 6: ---" << endl;
    string maCanDoi = "DH01";
    string trangThaiMoi = "Dang giao";
    bool timThay = false;
    
    for (DonHang &don : danhSachDon) {
        if (don.maDon == maCanDoi) {
            don.trangThai = trangThaiMoi;
            timThay = true;
            cout << "Da cap nhat don " << maCanDoi << " thanh trang thai: " << don.trangThai << "\n\n";
            break;
        }
    }
    if (!timThay) cout << "Khong tim thay ma don hang!\n\n";


    // ---------------------------------------------------------
    // Bài 7: Tìm các đơn hàng theo tên khách
    // ---------------------------------------------------------
    cout << "--- Bai 7: ---" << endl;
    string tuKhoa = "an"; // Tìm chữ "an" không phân biệt hoa thường
    cout << "Ket qua tim kiem cho tu khoá '" << tuKhoa << "':\n";
    
    for (DonHang don : danhSachDon) {
        // Chuyển cả tên khách và từ khóa về chữ thường để so sánh
        string tenKhachThuong = toLowerCase(don.tenKhach);
        string tuKhoaThuong = toLowerCase(tuKhoa);
        
        // Hàm find() trả về string::npos nếu không tìm thấy
        if (tenKhachThuong.find(tuKhoaThuong) != string::npos) {
            cout << "- " << don.maDon << " | " << don.tenKhach << " | " << don.monAn << endl;
        }
    }
    cout << "\n";

   
    // ---------------------------------------------------------
    // Bài 9: Thống kê món ăn bán chạy
    // ---------------------------------------------------------
    cout << "--- Bai 9: ---" << endl;
    string monThongKe = "Pizza Hai San";
    int soLuongBan = 0;
    
    for (DonHang don : danhSachDon) {
        if (don.monAn == monThongKe) {
            soLuongBan++;
        }
    }
    cout << "Mon '" << monThongKe << "' da xuat hien trong " << soLuongBan << " don hang.\n\n";


  
    // Bài 10: Tạo thông báo giao hàng
    // ---------------------------------------------------------
    cout << "--- Bai 10: ---" << endl;
    // Lấy đại đơn hàng đầu tiên làm ví dụ
    DonHang donViDu = danhSachDon[1]; 
    string thongBao = "Don hang [" + donViDu.maDon + "] cua [" + donViDu.tenKhach + 
                      "] dang duoc giao den [" + donViDu.diaChi + "]. Cam on ban!";
    cout << thongBao << "\n";

    return 0;
}
