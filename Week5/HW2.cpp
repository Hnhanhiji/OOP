// FLowerShop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Định nghĩa cấu trúc Flower theo yêu cầu đề bài
struct Flower {
    string name;
    double price;
    int quantity;
    string type;
};
Flower flowers[20]; // Mảng lưu trữ các loại hoa
int N; // Số lượng loại hoa
// Hàm bổ trợ: Chuyển chuỗi thành chữ thường để so sánh không phân biệt hoa thường (Case-insensitive)
string toLower(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

// Hàm bổ trợ: In tiêu đề bảng dữ liệu
void printHeader() {
    cout << left << setw(5) << "No"
        << setw(15) << "Name"
        << setw(10) << "Price"
        << setw(8) << "Qty"
        << setw(15) << "Type" << endl;
    cout << "--------------------------------------------------\n";
}

// Hàm bổ trợ: In thông tin của một bông hoa
void printFlower(int index, Flower f) {
    cout << left << setw(5) << index
        << setw(15) << f.name
        << setw(10) << fixed << setprecision(1) << f.price
        << setw(8) << f.quantity
        << setw(15) << f.type << endl;
}

// ============================================================================
// CHỨC NĂNG TỪ CÂU 1 ĐẾN CÂU 20
// ============================================================================
// Câu 1: Hiển thị tất cả các loài hoa có trong danh sách
void cau1_DisplayAllFlowers(Flower flowers[], int N) {
    cout << "--- Cau 1: All Flowers ---\n";
    printHeader();
    for (int i = 0; i < N; i++) {
        printFlower(i + 1, flowers[i]);
    }
}
// Câu 2: Tìm và hiển thị (các) loài hoa có giá đắt nhất
void cau2_FindMostExpensiveFlower(Flower flowers[], int N) {
    cout << "--- Cau 2: Most Expensive Flower(s) ---\n";
    double maxPrice = flowers[0].price;
    // Tìm giá trị lớn nhất
    for (int i = 1; i < N; i++) {
        if (flowers[i].price > maxPrice) maxPrice = flowers[i].price;
    }
    // In ra tất cả các hoa có cùng mức giá đắt nhất đó
    printHeader();
    for (int i = 0; i < N; i++) {
        if (flowers[i].price == maxPrice) printFlower(i + 1, flowers[i]);
    }
}
// Câu 3: Tìm và hiển thị (các) loài hoa có giá rẻ nhất
void cau3_FindCheapestFlower(Flower flowers[], int N) {
    cout << "--- Cau 3: Cheapest Flower(s) ---\n";
    double minPrice = flowers[0].price;
    // Tìm giá trị nhỏ nhất
    for (int i = 1; i < N; i++) {
        if (flowers[i].price < minPrice) minPrice = flowers[i].price;
    }
    // In ra tất cả các hoa có cùng mức giá rẻ nhất đó
    printHeader();
    for (int i = 0; i < N; i++) {
        if (flowers[i].price == minPrice) printFlower(i + 1, flowers[i]);
    }
}
// Câu 4: Tìm hoa có số lượng tồn kho nhiều nhất
void cau4_FindLargestQuantity(Flower flowers[], int N) {
    cout << "--- Cau 4: Flower(s) with Largest Quantity ---\n";
    int maxQty = flowers[0].quantity;
    for (int i = 1; i < N; i++) {
        if (flowers[i].quantity > maxQty) maxQty = flowers[i].quantity;
    }
    printHeader();
    for (int i = 0; i < N; i++) {
        if (flowers[i].quantity == maxQty) printFlower(i + 1, flowers[i]);
    }
}
// Câu 5: Tính tổng số lượng của tất cả các loài hoa cộng lại
void cau5_CalculateTotalQuantity(Flower flowers[], int N) {
    int totalQty = 0;
    for (int i = 0; i < N; i++) {
        totalQty += flowers[i].quantity;
    }
    cout << "--- Cau 5: Total Quantity ---\n";
    cout << "Total quantity of all flowers: " << totalQty << endl;
}
// Câu 6: Tính giá tiền trung bình của các loài hoa có trong tiệm
void cau6_CalculateAveragePrice(Flower flowers[], int N) {
    double sumPrice = 0;
    for (int i = 0; i < N; i++) {
        sumPrice += flowers[i].price;
    }
    cout << "--- Cau 6: Average Price ---\n";
    cout << "Average price of all flowers: " << fixed << setprecision(2) << (sumPrice / N) << endl;
}
// Câu 7: Đếm xem mỗi phân loại (Type) xuất hiện bao nhiêu lần trong danh sách
void cau7_CountFlowersByType(Flower flowers[], int N) {
    cout << "--- Cau 7: Count Flowers by Type ---\n";
    string visited[20]; // Mảng phụ để đánh dấu các phân loại đã được đếm
    int visitedCount = 0;
    for (int i = 0; i < N; i++) {
        bool alreadyCounted = false;
        for (int j = 0; j < visitedCount; j++) {
            if (toLower(flowers[i].type) == toLower(visited[j])) {
                alreadyCounted = true;
                break;
            }
        }
        if (!alreadyCounted) {
            int count = 0;
            for (int k = 0; k < N; k++) {
                if (toLower(flowers[k].type) == toLower(flowers[i].type)) count++;
            }
            cout << "- Type [" << flowers[i].type << "]: " << count << " flower(s)\n";
            visited[visitedCount++] = flowers[i].type; // Lưu lại để không đếm trùng lần sau
        }
    }
}
// Câu 8: Yêu cầu người dùng nhập một phân loại và hiển thị tất cả hoa thuộc phân loại đó
void cau8_FindFlowersOfGivenType(Flower flowers[], int N) {
    cin.ignore();
    string searchType;
    cout << "Enter type to find: ";
    getline(cin, searchType);

    cout << "--- Cau 8: Flowers of Type [" << searchType << "] ---\n";
    printHeader();
    bool found = false;
    for (int i = 0; i < N; i++) {
        if (toLower(flowers[i].type) == toLower(searchType)) {
            printFlower(i + 1, flowers[i]);
            found = true;
        }
    }
    if (!found) cout << "No flowers found for type: " << searchType << endl;
}
// Câu 9: Tìm kiếm hoa theo tên chính xác (Không phân biệt hoa thường)
void cau9_SearchByName(Flower flowers[], int N) {
    cin.ignore();
    string searchName;
    cout << "Enter flower name to search: ";
    getline(cin, searchName);
    
    cout << "--- Cau 9: Search Result for [" << searchName << "] ---\n";
    printHeader();
    bool found = false;
    for (int i = 0; i < N; i++) {
        if (toLower(flowers[i].name) == toLower(searchName)) {
            printFlower(i + 1, flowers[i]);
            found = true;
        }
    }
    if (!found) cout << "Flower not found.\n";
}
// Câu 10: Kiểm tra xem một loài hoa có tồn tại trong tiệm hay không (Trả về Yes/No)
void cau10_CheckIfFlowerExists(Flower flowers[], int N) {
    cin.ignore();
    string checkName;
    cout << "Enter name to check existence: ";
    getline(cin, checkName);
    
    bool exists = false;
    for (int i = 0; i < N; i++) {
        if (toLower(flowers[i].name) == toLower(checkName)) {
            exists = true;
            break;
        }
    }
    cout << "--- Cau 10: Check Existence ---\n";
    cout << "Result: " << (exists ? "Yes" : "No") << endl;
}
// Câu 11: Đếm số lượng loại hoa sắp hết hàng (số lượng tồn kho < 5)
void cau11_CountFlowersWithLowQuantity(Flower flowers[], int N) {
    int countLow = 0;
    for (int i = 0; i < N; i++) {
        if (flowers[i].quantity < 5) countLow++;
    }
    cout << "--- Cau 11: Low Quantity Count (< 5) ---\n";
    cout << "Number of flowers with quantity < 5: " << countLow << endl;
}
// Câu 12: Đếm số lượng hoa nằm trong khoảng giá [min, max] do người dùng nhập
void cau12_CountFlowersInPriceRange(Flower flowers[], int N) {
    double minP, maxP;
    cout << "Enter minimum price: "; cin >> minP;
    cout << "Enter maximum price: "; cin >> maxP;
    
    int countRange = 0;
    for (int i = 0; i < N; i++) {
        if (flowers[i].price >= minP && flowers[i].price <= maxP) countRange++;
    }
    cout << "--- Cau 12: Price Range Count ---\n";
    cout << "Result: There are " << countRange << " flower(s) in that price range.\n";
}
// Câu 13: Tính tổng giá trị vốn của toàn bộ cửa hàng (Giá tiền * Số lượng của từng loại)
void cau13_CalculateTotalValue(Flower flowers[], int N) {
    double totalValue = 0;
    for (int i = 0; i < N; i++) {
        totalValue += (flowers[i].price * flowers[i].quantity);
    }
    cout << "--- Cau 13: Total Value ---\n";
    cout << "Total inventory value: $" << fixed << setprecision(2) << totalValue << endl;
}
// Câu 14: Tìm bông hoa mang lại tổng giá trị tài sản lớn nhất (Giá tiền * Số lượng lớn nhất)
void cau14_FindMostValuableFlower(Flower flowers[], int N) {
    double maxVal = flowers[0].price * flowers[0].quantity;
    for (int i = 1; i < N; i++) {
        double val = flowers[i].price * flowers[i].quantity;
        if (val > maxVal) maxVal = val;
    }
    cout << "--- Cau 14: Most Valuable Flower(s) ---\n";
    printHeader();
    for (int i = 0; i < N; i++) {
        if ((flowers[i].price * flowers[i].quantity) == maxVal) {
            printFlower(i + 1, flowers[i]);
        }
    }
}
// Câu 15: Sắp xếp mảng theo thứ tự giá tăng dần (Sử dụng mảng sao chép tạm thời)
void cau15_SortFlowersByPrice(Flower flowers[], int N) {
    Flower temp[20];
    for (int i = 0; i < N; i++) temp[i] = flowers[i];
    
    // Bubble sort sắp xếp tăng dần theo giá
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (temp[j].price > temp[j + 1].price) swap(temp[j], temp[j + 1]);
        }
    }
    cout << "--- Cau 15: Sorted by Price (Low to High) ---\n";
    printHeader();
    for (int i = 0; i < N; i++) printFlower(i + 1, temp[i]);
}
// Câu 16: Sắp xếp danh sách hoa theo thứ tự bảng chữ cái từ A đến Z của Tên hoa
void cau16_SortFlowersByName(Flower flowers[], int N) {
    Flower temp[20];
    for (int i = 0; i < N; i++) temp[i] = flowers[i];

    // Bubble sort sắp xếp theo Alphabet
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (toLower(temp[j].name) > toLower(temp[j + 1].name)) swap(temp[j], temp[j + 1]);
        }
    }
    cout << "--- Cau 16: Sorted by Name (A to Z) ---\n";
    printHeader();
    for (int i = 0; i < N; i++) printFlower(i + 1, temp[i]);
}
// Câu 17: Tìm top 3 bông hoa đắt nhất tiệm (Sắp xếp giảm dần rồi lấy 3 phần tử đầu)
void cau17_FindTop3MostExpensive(Flower flowers[], int N) {
    Flower temp[20];
    for (int i = 0; i < N; i++) temp[i] = flowers[i];

    // Sắp xếp giảm dần theo giá
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (temp[j].price < temp[j + 1].price) swap(temp[j], temp[j + 1]);
        }
    }
    cout << "--- Cau 17: Top 3 Most Expensive Flowers ---\n";
    printHeader();
    int limit = (N < 3) ? N : 3; // Phòng trường hợp N nhỏ hơn 3
    for (int i = 0; i < limit; i++) printFlower(i + 1, temp[i]);
}
// --- CÂU 18: Tìm hoa có tên chứa từ khóa do người dùng nhập ---
// Yêu cầu: Nhập vào một từ khóa (keyword) và hiển thị tất cả các hoa có tên chứa từ khóa đó (Ví dụ: nhập "rose").
void cau18_FindFlowersByNameKeyword(Flower flowers[], int N) {
    cin.ignore(); // Xóa bộ nhớ đệm trước khi nhập chuỗi hành động tránh bị trôi dòng
    string keyword;
    cout << "Nhập từ khóa cần tìm kiếm trong tên hoa (Ví dụ: 'rose'): ";
    getline(cin, keyword);
    
    cout << "\n--- Kết quả câu 18: Các loại hoa chứa từ khóa [" << keyword << "] ---\n";
    printHeader();
    bool found = false; // Biến đánh dấu xem có tìm thấy hoa nào không
    
    for (int i = 0; i < N; i++) {
        // Sử dụng hàm .find() để kiểm tra chuỗi keyword có nằm trong tên hoa hay không.
        // Cả tên hoa và keyword đều được chuyển về chữ thường bằng hàm toLower() để tìm kiếm không phân biệt hoa thường.
        if (toLower(flowers[i].name).find(toLower(keyword)) != string::npos) {
            printFlower(i + 1, flowers[i]); // In ra hoa thỏa mãn điều kiện
            found = true;
        }
    }
    if (!found) {
        cout << "Không tìm thấy loài hoa nào có tên chứa từ khóa trên.\n";
    }
}
// --- CÂU 19: Tính số lượng (Quantity) trung bình của mỗi phân loại hoa (Type) ---
// Yêu cầu: Đối với mỗi phân loại, tính toán và hiển thị số lượng tồn kho trung bình.
void cau19_CalculateAverageQuantityByType(Flower flowers[], int N) {
    cout << "\n--- Kết quả câu 19: Số lượng tồn kho trung bình theo từng loại ---\n";
    
    string visited[20]; // Mảng phụ dùng lưu trữ các Type đã được xử lý (tránh tính trùng lặp)
    int visitedCount = 0;
    
    for (int i = 0; i < N; i++) {
        bool alreadyCounted = false;
        
        // Kiểm tra xem phân loại (Type) của hoa hiện tại đã được tính toán ở các vòng lặp trước chưa
        for (int j = 0; j < visitedCount; j++) {
            if (toLower(flowers[i].type) == toLower(visited[j])) {
                alreadyCounted = true;
                break;
            }
        }
        
        // Nếu phân loại này mới hoàn toàn và chưa được tính toán
        if (!alreadyCounted) {
            double sumQty = 0; // Biến tích lũy tổng số lượng tồn kho của phân loại này
            int count = 0;     // Biến đếm số lượng loài hoa thuộc phân loại này
            
            // Chạy vòng lặp quét qua toàn bộ danh sách để gom nhóm dữ liệu theo Type
            for (int k = 0; k < N; k++) {
                if (toLower(flowers[k].type) == toLower(flowers[i].type)) {
                    sumQty += flowers[k].quantity;
                    count++;
                }
            }
            
            // Tính trung bình bằng Tổng số lượng / Số loài hoa cùng phân loại
            double average = sumQty / count;
            cout << "- Phân loại [" << flowers[i].type << "]: Số lượng TB là " 
                 << fixed << setprecision(2) << average << " bông mỗi loài.\n";
                 
            // Lưu phân loại này vào mảng visited để bỏ qua trong các vòng lặp sau
            visited[visitedCount++] = flowers[i].type;
        }
    }
}
// --- CÂU 20: Tạo một báo cáo đơn giản (Simple Report) ---
// Yêu cầu: Hiển thị tổng số loài hoa, tổng số lượng tất cả các bông, giá trung bình và số lượng loài hoa trong từng phân loại.
void cau20_GenerateSimpleReport(Flower flowers[], int N) {
    int totalQty = 0;     // Tổng số lượng bông hoa đang có trong tiệm
    double sumPrice = 0;  // Tổng giá tiền để phục vụ việc tính giá trung bình
    
    for (int i = 0; i < N; i++) {
        totalQty += flowers[i].quantity;
        sumPrice += flowers[i].price;
    }
    
    cout << "\n--- Kết quả câu 20: BÁO CÁO TỔNG QUAN HÀNG HÓA ---\n";
    cout << "1. Tổng số loài hoa đang quản lý (Unique variants) : " << N << " loài.\n";
    cout << "2. Tổng số lượng bông hoa đang tồn kho (Total quantity): " << totalQty << " bông.\n";
    cout << "3. Giá tiền trung bình của một loài hoa (Average price) : $" << fixed << setprecision(2) << (sumPrice / N) << "\n";
    
    cout << "\n4. Số lượng loài hoa thuộc mỗi phân loại:\n";
    string visited[20];
    int visitedCount = 0;
    
    // Vòng lặp đếm số lượng loài hoa của từng nhóm phân loại (Tương tự thuật toán lọc trùng câu 19)
    for (int i = 0; i < N; i++) {
        bool alreadyCounted = false;
        for (int j = 0; j < visitedCount; j++) {
            if (toLower(flowers[i].type) == toLower(visited[j])) {
                alreadyCounted = true;
                break;
            }
        }
        if (!alreadyCounted) {
            int count = 0;
            for (int k = 0; k < N; k++) {
                if (toLower(flowers[k].type) == toLower(flowers[i].type)) {
                    count++;
                }
            }
            cout << "   + Loại [" << flowers[i].type << "]: Có " << count << " loài hoa khác nhau.\n";
            visited[visitedCount++] = flowers[i].type;
        }
    }
}
