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
