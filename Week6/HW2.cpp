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
