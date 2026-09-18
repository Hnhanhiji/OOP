#include <iostream>
using namespace std;

// Hàm nhận mảng (bản chất là con trỏ) và thay đổi phần tử đầu tiên
void setFirstToZero(int arr[]) {
    arr[0] = 0; // modifies the original array
}

// Hàm nhận tham chiếu đến toàn bộ mảng có kích thước cố định là 4
void incrementAll(int (&arr)[4]) {
    for (int i = 0; i < 4; ++i) {
        arr[i] += 1; // use reference to array
    }
}

int main() {
    int nums[4] = {1, 2, 3, 4};
    
    setFirstToZero(nums);
    incrementAll(nums);
    
    // In kết quả các phần tử của mảng
    cout << nums[0] << " " << nums[1] << " " << nums[2] << " " << nums[3] << endl;
    
    return 0;
}

