#include <iostream>
#include <string>

using namespace std;

struct Mobile
{
    int id;
    string brand;
    string version;
    string serial;
    int year;
    double price;
};


struct Order
{
    int idOrder;
    int idCustomer;
    string address;

    int mobileItems[10];
    int mobileCount;

    int day;
    int month;
    int year;

    bool payment;
};

struct Shop
{
    string name;
    string address;
    string phone;

    Mobile mobiles[100];
    int mobileCount;

    Order orders[100];
    int orderCount;
};

// TÌM MOBILE THEO ID
int findMobile(Shop& shop, int id)
{
    for (int i = 0; i < shop.mobileCount; i++)
    {
        if (shop.mobiles[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

// TÌM ORDER THEO ID
int findOrder(Shop& shop, int id)
{
    for (int i = 0; i < shop.orderCount; i++)
    {
        if (shop.orders[i].idOrder == id)
        {
            return i;
        }
    }

    return -1;
}


// 1. THÊM MỚI ĐIỆN THOẠI
void addMobile(Shop& shop)
{
    if (shop.mobileCount >= 100)
    {
        cout << "Danh sach dien thoai da day!\n";
        return;
    }

    Mobile m;

    cout << "\n===== THEM DIEN THOAI =====\n";

    cout << "ID: ";
    cin >> m.id;

    // Kiem tra ID da ton tai
    if (findMobile(shop, m.id) != -1)
    {
        cout << "ID dien thoai da ton tai!\n";
        return;
    }

    cin.ignore();

    cout << "Brand: ";
    getline(cin, m.brand);

    cout << "Version: ";
    getline(cin, m.version);

    cout << "Serial: ";
    getline(cin, m.serial);

    cout << "Year: ";
    cin >> m.year;

    cout << "Price: ";
    cin >> m.price;

    shop.mobiles[shop.mobileCount] = m;
    shop.mobileCount++;

    cout << "Them dien thoai thanh cong!\n";
}


// 2. XÓA ĐIỆN THOẠI
void deleteMobile(Shop& shop)
{
    int id;

    cout << "\n===== XOA DIEN THOAI =====\n";

    cout << "Nhap ID dien thoai can xoa: ";
    cin >> id;

    int position = findMobile(shop, id);

    if (position == -1)
    {
        cout << "Khong tim thay dien thoai!\n";
        return;
    }

    // Dich cac phan tu phia sau len 1 vi tri
    for (int i = position; i < shop.mobileCount - 1; i++)
    {
        shop.mobiles[i] = shop.mobiles[i + 1];
    }

    shop.mobileCount--;

    cout << "Xoa dien thoai thanh cong!\n";
}

// 3. TẠO MỚI ORDER
void addOrder(Shop& shop)
{
    if (shop.orderCount >= 100)
    {
        cout << "Danh sach order da day!\n";
        return;
    }

    Order o;

    cout << "\n===== TAO ORDER MOI =====\n";

    cout << "ID Order: ";
    cin >> o.idOrder;

    // Kiem tra ID Order
    if (findOrder(shop, o.idOrder) != -1)
    {
        cout << "ID Order da ton tai!\n";
        return;
    }

    cout << "ID Customer: ";
    cin >> o.idCustomer;

    cin.ignore();

    cout << "Dia chi: ";
    getline(cin, o.address);

    cout << "\nNgay dat hang:\n";

    cout << "Ngay: ";
    cin >> o.day;

    cout << "Thang: ";
    cin >> o.month;

    cout << "Nam: ";
    cin >> o.year;

    cout << "\nThanh toan (1: Da thanh toan, 0: Chua thanh toan): ";
    int temp;
    cin >> temp;

    o.payment = (temp == 1);

    // Nhap danh sach dien thoai
    cout << "\nSo luong dien thoai mua: ";
    cin >> o.mobileCount;

    if (o.mobileCount > 10)
    {
        o.mobileCount = 10;
    }

    for (int i = 0; i < o.mobileCount; i++)
    {
        int mobileID;

        cout << "Nhap ID dien thoai thu "
             << i + 1 << ": ";

        cin >> mobileID;

        // Kiem tra dien thoai co ton tai khong
        if (findMobile(shop, mobileID) == -1)
        {
            cout << "Dien thoai khong ton tai!\n";
            i--;
        }
        else
        {
            o.mobileItems[i] = mobileID;
        }
    }

    shop.orders[shop.orderCount] = o;
    shop.orderCount++;

    cout << "\nTao order thanh cong!\n";
}

// 4. CHỈNH SỬA THÔNG TIN ORDER
void editOrder(Shop& shop)
{
    int id;

    cout << "\n===== CHINH SUA ORDER =====\n";

    cout << "Nhap ID Order can sua: ";
    cin >> id;

    int position = findOrder(shop, id);

    if (position == -1)
    {
        cout << "Khong tim thay Order!\n";
        return;
    }

    // Lay order can sua
    Order& o = shop.orders[position];

    cout << "\nNhap thong tin moi:\n";

    cout << "ID Customer moi: ";
    cin >> o.idCustomer;

    cin.ignore();

    cout << "Dia chi moi: ";
    getline(cin, o.address);

    cout << "\nNgay dat hang moi:\n";

    cout << "Ngay: ";
    cin >> o.day;

    cout << "Thang: ";
    cin >> o.month;

    cout << "Nam: ";
    cin >> o.year;

    cout << "\nTrang thai thanh toan\n";
    cout << "1. Da thanh toan\n";
    cout << "0. Chua thanh toan\n";

    int temp;
    cin >> temp;

    o.payment = (temp == 1);

    // Sua danh sach dien thoai
    cout << "\nSo luong dien thoai moi: ";
    cin >> o.mobileCount;

    if (o.mobileCount > 10)
    {
        o.mobileCount = 10;
    }

    for (int i = 0; i < o.mobileCount; i++)
    {
        int mobileID;

        cout << "Nhap ID dien thoai thu "
             << i + 1 << ": ";

        cin >> mobileID;

        if (findMobile(shop, mobileID) == -1)
        {
            cout << "Dien thoai khong ton tai!\n";
            i--;
        }
        else
        {
            o.mobileItems[i] = mobileID;
        }
    }

    cout << "\nChinh sua Order thanh cong!\n";
}

// 5. THỐNG KÊ ORDER THEO THÁNG
void statisticOrder(Shop& shop)
{
    int month;
    int year;

    cout << "\n===== THONG KE ORDER THEO THANG =====\n";

    cout << "Nhap thang: ";
    cin >> month;

    cout << "Nhap nam: ";
    cin >> year;

    int count = 0;
    double totalMoney = 0;

    for (int i = 0; i < shop.orderCount; i++)
    {
        Order& o = shop.orders[i];

        if (o.month == month && o.year == year)
        {
            count++;

            // Tinh tien cua order
            for (int j = 0; j < o.mobileCount; j++)
            {
                int mobileID = o.mobileItems[j];

                int position =
                    findMobile(shop, mobileID);

                if (position != -1)
                {
                    totalMoney +=
                        shop.mobiles[position].price;
                }
            }
        }
    }

    cout << "\n===== KET QUA =====\n";

    cout << "Thang: "
         << month << "/" << year << endl;

    cout << "So luong Order: "
         << count << endl;

    cout << "Tong tien: "
         << totalMoney << endl;
}

// MENU
void menu()
{
    cout << "\n";
    cout << "====================================\n";
    cout << "       QUAN LY SHOP DIEN THOAI\n";
    cout << "====================================\n";

    cout << "1. Them moi dien thoai\n";
    cout << "2. Xoa dien thoai\n";
    cout << "3. Tao moi Order\n";
    cout << "4. Chinh sua thong tin Order\n";
    cout << "5. Thong ke Order theo thang\n";
    cout << "0. Thoat\n";

    cout << "====================================\n";
    cout << "Nhap lua chon: ";
}

int main()
{
    Shop shop;

    // Khoi tao so luong
    shop.mobileCount = 0;
    shop.orderCount = 0;

    int choice;

    do
    {
        menu();

        cin >> choice;

        switch (choice)
        {
        case 1:
            addMobile(shop);
            break;

        case 2:
            deleteMobile(shop);
            break;

        case 3:
            addOrder(shop);
            break;

        case 4:
            editOrder(shop);
            break;

        case 5:
            statisticOrder(shop);
            break;

        case 0:
            cout << "Ket thuc chuong trinh!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}
