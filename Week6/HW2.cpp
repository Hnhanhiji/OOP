    // Task 4: Tim bong hoa co so luong lon nhat
    void task4_findLargestQuantity(Flower flowers[], int N) {
        cout << "\n--- Task 4: Hoa co so luong nhieu nhat ---\n";
        if (N == 0) return;
        int maxIdx = 0;
        for (int i = 1; i < N; i++) {
            if (flowers[i].quantity > flowers[maxIdx].quantity) {
                maxIdx = i;
            }
        }
        printHeader();
        printFlower(flowers[maxIdx]);
    }
// Task 5: Tinh tong so luong hoa
void task5_calculateTotalQuantity(Flower flowers[], int N) {
    cout << "\n--- Task 5: Tong so luong hoa ---\n";
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += flowers[i].quantity;
    }
    cout << "Tong so luong tat ca cac bong hoa: " << total << endl;
}
// Task 6: Tinh gia trung binh cua cac loai hoa
void task6_calculateAveragePrice(Flower flowers[], int N) {
    cout << "\n--- Task 6: Gia trung binh ---\n";
    if (N == 0) {
        cout << "Gia trung binh: 0\n";
        return;
    }
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += flowers[i].price;
    }
    cout << "Gia trung binh cua cac loai hoa: " << fixed << setprecision(2) << (sum / N) << endl;
}
// Task 7: Dem so luong hoa theo tung loai (Type)
void task7_countFlowersByType(Flower flowers[], int N) {
    cout << "\n--- Task 7: Dem hoa theo loai ---\n";
    string uniqueTypes[20];
    int typeCounts[20] = {0};
    int typeCount = 0;

    for (int i = 0; i < N; i++) {
        bool found = false;
        for (int j = 0; j < typeCount; j++) {
            if (toLower(flowers[i].type) == toLower(uniqueTypes[j])) {
                typeCounts[j]++;
                found = true;
                break;
            }
        }
        if (!found) {
            uniqueTypes[typeCount] = flowers[i].type;
            typeCounts[typeCount] = 1;
            typeCount++;
        }
    }

    for (int i = 0; i < typeCount; i++) {
        cout << "Loai \"" << uniqueTypes[i] << "\": " << typeCounts[i] << " dong\n";
    }
}
// Task 8: Tim tat ca cac bong hoa thuoc loai duoc nhap vao
void task8_findAllFlowersOfGivenType(Flower flowers[], int N) {
    cout << "\n--- Task 8: Tim hoa theo loai nhap vao ---\n";
    string targetType;
    cout << "Nhap loai hoa can tim: ";
    cin.ignore();
    getline(cin, targetType);

    printHeader();
    bool found = false;
    for (int i = 0; i < N; i++) {
        if (toLower(flowers[i].type) == toLower(targetType)) {
            printFlower(flowers[i]);
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay hoa nao thuoc loai nay.\n";
}
// Task 9: Tim kiem hoa theo ten va hien thi thong tin
void task9_searchByName(Flower flowers[], int N) {
    cout << "\n--- Task 9: Tim kiem hoa theo ten ---\n";
    string targetName;
    cout << "Nhap ten hoa can tim thong tin: ";
    getline(cin, targetName);

    bool found = false;
    for (int i = 0; i < N; i++) {
        if (toLower(flowers[i].name) == toLower(targetName)) {
            if (!found) printHeader();
            printFlower(flowers[i]);
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay thong tin cho hoa nay.\n";
}
// Task 10: Kiem tra xem hoa co ton tai hay khong (Tra ve Yes/No)
void task10_checkIfFlowerExists(Flower flowers[], int N) {
    cout << "\n--- Task 10: Kiem tra hoa ton tai (Yes/No) ---\n";
    string targetName;
    cout << "Nhap ten hoa can kiem tra: ";
    getline(cin, targetName);

    bool exists = false;
    for (int i = 0; i < N; i++) {
        if (toLower(flowers[i].name) == toLower(targetName)) {
            exists = true;
            break;
        }
    }
    if (exists) cout << "Ket qua: Yes\n";
    else cout << "Ket qua: No\n";
}
// Task 11: Dem cac bong hoa co so luong thap (< 5)
void task11_countLowQuantity(Flower flowers[], int N) {
    cout << "\n--- Task 11: Dem hoa co so luong thap (< 5) ---\n";
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (flowers[i].quantity < 5) {
            count++;
        }
    }
    cout << "So luong hoa co so luong ton kho < 5 la: " << count << endl;
}
// Task 12: Dem so hoa trong mot khoang gia nhat dinh
void task12_countFlowersInPriceRange(Flower flowers[], int N) {
    cout << "\n--- Task 12: Dem hoa trong khoang gia ---\n";
    double minPrice, maxPrice;
    cout << "Nhap gia thap nhat: "; cin >> minPrice;
    cout << "Nhap gia cao nhat: "; cin >> maxPrice;

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (flowers[i].price >= minPrice && flowers[i].price <= maxPrice) {
            count++;
        }
    }
    cout << "So luong hoa trong khoang gia [" << minPrice << ", " << maxPrice << "] la: " << count << endl;
}
// Task 13: Tinh tong gia tri tat ca cac loai hoa (Gia * So luong)
void task13_calculateTotalValue(Flower flowers[], int N) {
    cout << "\n--- Task 13: Tong gia tri kho hoa ---\n";
    double totalValue = 0;
    for (int i = 0; i < N; i++) {
        totalValue += (flowers[i].price * flowers[i].quantity);
    }
    cout << "Tong gia tri (price * quantity) cua kho hoa: " << totalValue << endl;
}
// Task 14: Tim bong hoa co gia tri lon nhat
void task14_findMostValuable(Flower flowers[], int N) {
    cout << "\n--- Task 14: Hoa co gia tri lon nhat ---\n";
    if (N == 0) return;
    int maxIdx = 0;
    double maxValue = flowers[0].price * flowers[0].quantity;

    for (int i = 1; i < N; i++) {
        double currentValue = flowers[i].price * flowers[i].quantity;
        if (currentValue > maxValue) {
            maxValue = currentValue;
            maxIdx = i;
        }
    }
    printHeader();
    printFlower(flowers[maxIdx]);
    cout << "-> Tong gia tri lon nhat: " << maxValue << endl;
}
// Task 15: Sap xep hoa theo gia tang dan
void task15_sortFlowersByPriceAscending(Flower flowers[], int N) {
    cout << "\n--- Task 15: Sap xep hoa theo gia tang dan ---\n";
    // Tao mot mang sao chep de tranh thay doi mang goc
    Flower temp[20];
    for(int i=0; i<N; i++) temp[i] = flowers[i];

    // Thuc hien Bubble Sort
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (temp[j].price > temp[j + 1].price) {
                swap(temp[j], temp[j + 1]);
            }
        }
    }
    printHeader();
    for (int i = 0; i < N; i++) printFlower(temp[i]);
}
// Task 16: Sap xep hoa theo ten alphabet (A -> Z)
void task16_sortFlowersByNameAZ(Flower flowers[], int N) {
    cout << "\n--- Task 16: Sap xep hoa theo ten (A -> Z) ---\n";
    Flower temp[20];
    for(int i=0; i<N; i++) temp[i] = flowers[i];

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (toLower(temp[j].name) > toLower(temp[j + 1].name)) {
                swap(temp[j], temp[j + 1]);
            }
        }
    }
    printHeader();
    for (int i = 0; i < N; i++) printFlower(temp[i]);
}
 // Task 17: Tim top 3 bong hoa co gia dat nhat
 void task17_findTop3MostExpensive(Flower flowers[], int N) {
     cout << "\n--- Task 17: Top 3 hoa dat nhat ---\n";
     Flower temp[20];
     for (int i = 0; i < N; i++) temp[i] = flowers[i];

     // Sap xep gia giam dan
     for (int i = 0; i < N - 1; i++) {
         for (int j = 0; j < N - i - 1; j++) {
           if (temp[j].price < temp[j + 1].price) { swap(temp[j], temp[j + 1]); }
         }
     }printHeader();int limit = min(3, N);for (int i = 0; i < limit; i++) { printFlower(temp[i]); }
 }
// Task 18: Find flowers with name containing a keyword
// Yêu cầu người dùng nhập từ khóa và hiển thị tất cả các bông hoa có tên chứa từ khóa đó
void task18_findFlowersContainingKeyword(Flower flowers[], int N) {
    cout << "\n--- Task 18: Tim hoa chua tu khoa ---\n";
    string keyword;
    cout << "Nhap tu khoa can tim (vi du: 'rose'): ";
    cin.ignore(); // Xóa bộ nhớ đệm trước khi dùng getline
    getline(cin, keyword);

    // Chuyển từ khóa về chữ thường để so sánh không phân biệt hoa thường
    string lowerKeyword = toLower(keyword);
    bool found = false;

    printHeader();
    for (int i = 0; i < N; i++) {
        // Nếu tìm thấy từ khóa xuất hiện trong tên bông hoa
        if (toLower(flowers[i].name).find(lowerKeyword) != string::npos) {
            printFlower(flowers[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "Khong co hoa nao chua tu khoa: \"" << keyword << "\"\n";
    }
}
// Task 19: Calculate average quantity by type
// Tính và hiển thị số lượng tồn kho trung bình cho từng loại (type) hoa
void task19_calculateAverageQuantityByType(Flower flowers[], int N) {
    cout << "\n--- Task 19: So luong hoa trung binh theo loai ---\n";
    if (N == 0) return;

    string uniqueTypes[20]; // Lưu danh sách các loại hoa không trùng nhau
    int totalQty[20] = {0};   // Tổng số lượng hoa của từng loại
    int typeCounts[20] = {0}; // Số lượng dòng dữ liệu thuộc loại đó để tính trung bình
    int typeCount = 0;        // Số lượng loại hoa độc nhất tìm được

    // Thuật toán gom nhóm dữ liệu sử dụng mảng tĩnh
    for (int i = 0; i < N; i++) {
        bool isExisted = false;
        for (int j = 0; j < typeCount; j++) {
            if (toLower(flowers[i].type) == toLower(uniqueTypes[j])) {
                totalQty[j] += flowers[i].quantity;
                typeCounts[j]++;
                isExisted = true;
                break;
            }
        }
        // Nếu loại hoa chưa có trong danh sách uniqueTypes thì thêm mới vào
        if (!isExisted) {
            uniqueTypes[typeCount] = flowers[i].type;
            totalQty[typeCount] = flowers[i].quantity;
            typeCounts[typeCount] = 1;
            typeCount++;
        }
    }

    // Tính toán và hiển thị kết quả trung bình
    for (int i = 0; i < typeCount; i++) {
        double avg = (double)totalQty[i] / typeCounts[i];
        cout << "+ Loai \"" << uniqueTypes[i] << "\" co so luong trung binh: " 
             << fixed << setprecision(2) << avg << endl;
    }
}
// Task 20: Generate a simple report
// Xuất báo cáo tổng hợp: tổng số loại hoa, tổng số lượng trong kho, giá trung bình và thống kê số lượng theo loại
void task20_generateSimpleReport(Flower flowers[], int N) {
    cout << "\n--- Task 20: Bao cao don gian ---\n";
    int totalFlowers = N;
    int totalQuantity = 0;
    double sumPrice = 0;

    for (int i = 0; i < N; i++) {
        totalQuantity += flowers[i].quantity;
        sumPrice += flowers[i].price;
    }
    double avgPrice = (N > 0) ? (sumPrice / N) : 0;

    cout << "====================================\n";
    cout << "        BAO CAO CUA HANG HOA        \n";
    cout << "====================================\n";
    cout << "- Tong so dong du lieu hoa: " << totalFlowers << endl;
    cout << "- Tong so luong hoa trong kho: " << totalQuantity << endl;
    cout << "- Gia trung binh cua cac loai hoa: " << fixed << setprecision(2) << avgPrice << endl;
    cout << "------------------------------------\n";
    cout << "Chi tiet so luong theo tung loai:\n";
    
    // Sử dụng lại logic đếm loại tương tự Task 19 để in thống kê
    string uniqueTypes[20];
    int typeCounts[20] = {0};
    int typeCount = 0;

    for (int i = 0; i < N; i++) {
        bool isExisted = false;
        for (int j = 0; j < typeCount; j++) {
            if (toLower(flowers[i].type) == toLower(uniqueTypes[j])) {
                typeCounts[j] += flowers[i].quantity; // Cộng dồn số lượng tồn kho
                isExisted = true;
                break;
            }
        }
        if (!isExisted) {
            uniqueTypes[typeCount] = flowers[i].type;
            typeCounts[typeCount] = flowers[i].quantity;
            typeCount++;
        }
    }

    for (int i = 0; i < typeCount; i++) {
        cout << "  + Loai \"" << uniqueTypes[i] << "\" co tong so luong: " << typeCounts[i] << " bong\n";
    }
    cout << "====================================\n";
}

