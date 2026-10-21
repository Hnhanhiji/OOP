#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


//  PhuongTrinh

class PhuongTrinh {
protected:
    string tenPhuongTrinh;

public:
    PhuongTrinh(string ten) : tenPhuongTrinh(ten) {}
    virtual ~PhuongTrinh() = default;

    // Getter & Setter cho thuộc tính chung
    string getTenPhuongTrinh() const { return tenPhuongTrinh; }
    void setTenPhuongTrinh(string ten) { tenPhuongTrinh = ten; }

    // Phương thức ảo thuần túy, bắt buộc các lớp con phải ghi đè
    virtual void solve() const = 0;
};

// ==========================================
// LỚP CON: Phương trình Bậc 1 (ax + b = 0)
// ==========================================
class PhuongTrinhBac1 : public PhuongTrinh {
private:
    double a, b; // Tính đóng gói: Thuộc tính private

public:
    // Constructor
    PhuongTrinhBac1(double a = 0, double b = 0) 
        : PhuongTrinh("Phuong trinh bac 1"), a(a), b(b) {}

    // Getters
    double getA() const { return a; }
    double getB() const { return b; }

    // Setters
    void setA(double a) { this->a = a; }
    void setB(double b) { this->b = b; }


    void solve() const override {
        cout << "\n--- Giai " << tenPhuongTrinh << " (" << a << "x + " << b << " = 0) ---\n";
        if (a == 0) {
            if (b == 0) cout << "Phuong trinh vo so nghiem." << endl;
            else cout << "Phuong trinh vo nghiem." << endl;
        } else {
            cout << "Nghiem x = " << -b / a << endl;
        }
    }
};

// ==========================================
// LỚP CON: Phương trình Bậc 2 (ax^2 + bx + c = 0)

class PhuongTrinhBac2 : public PhuongTrinh {
private:
    double a, b, c;

public:
    PhuongTrinhBac2(double a = 0, double b = 0, double c = 0) 
        : PhuongTrinh("Phuong trinh bac 2"), a(a), b(b), c(c) {}

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    void setA(double a) { this->a = a; }
    void setB(double b) { this->b = b; }
    void setC(double c) { this->c = c; }

    void solve() const override {
        cout << "\n--- Giai " << tenPhuongTrinh << " (" << a << "x^2 + " << b << "x + " << c << " = 0) ---\n";
        if (a == 0) {
            // Quay về phương trình bậc 1
            PhuongTrinhBac1 pt1(b, c);
            pt1.solve();
            return;
        }

        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem (Delta < 0)." << endl;
        } else if (delta == 0) {
            cout << "Phuong trinh co nghiem kep x1 = x2 = " << -b / (2 * a) << endl;
        } else {
            cout << "Phuong trinh co 2 nghiem phan biet:" << endl;
            cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
            cout << "x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
        }
    }
};

// ==========================================
// LỚP CON: Phương trình Bậc 3 (ax^3 + bx^2 + cx + d = 0)
=
class PhuongTrinhBac3 : public PhuongTrinh {
private:
    double a, b, c, d;

public:
    PhuongTrinhBac3(double a = 0, double b = 0, double c = 0, double d = 0) 
        : PhuongTrinh("Phuong trinh bac 3"), a(a), b(b), c(c), d(d) {}

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }
    double getD() const { return d; }

    void setA(double a) { this->a = a; }
    void setB(double b) { this->b = b; }
    void setC(double c) { this->c = c; }
    void setD(double d) { this->d = d; }

    void solve() const override {
        cout << "\n--- Giai " << tenPhuongTrinh << " (" << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << " = 0) ---\n";
        if (a == 0) {
            // Quay về phương trình bậc 2
            PhuongTrinhBac2 pt2(b, c, d);
            pt2.solve();
            return;
        }

        // Sử dụng phương pháp Cardano cơ bản để tìm 1 nghiệm thực
        double p = (3 * a * c - b * b) / (3 * a * a);
        double q = (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / (27 * a * a * a);
        double delta = (q * q / 4) + (p * p * p / 27);

        if (delta > 0) {
            double u = cbrt(-q / 2 + sqrt(delta));
            double v = cbrt(-q / 2 - sqrt(delta));
            double x = u + v - b / (3 * a);
            cout << "Phuong trinh co 1 nghiem thuc: x = " << x << endl;
        } else if (delta == 0) {
            double x1 = 3 * q / p - b / (3 * a);
            double x2 = -3 * q / (2 * p) - b / (3 * a);
            cout << "Phuong trinh co nghiem boi: x1 = " << x1 << ", x2 = x3 = " << x2 << endl;
        } else {
            // delta < 0: 3 nghiệm thực phân biệt
            double r = sqrt(-(p * p * p) / 27);
            double phi = acos(-q / (2 * r));
            double r_cbrt = 2 * cbrt(r);
            cout << "Phuong trinh co 3 nghiem thuc:" << endl;
            cout << "x1 = " << r_cbrt * cos(phi / 3) - b / (3 * a) << endl;
            cout << "x2 = " << r_cbrt * cos((phi + 2 * M_PI) / 3) - b / (3 * a) << endl;
            cout << "x3 = " << r_cbrt * cos((phi + 4 * M_PI) / 3) - b / (3 * a) << endl;
        }
    }
};

// ==========================================
// MAIN: Khởi chạy và kiểm thử Đa hình

int main() {
    // Thể hiện tính đa hình thông qua con trỏ lớp cha
    PhuongTrinh* pt1 = new PhuongTrinhBac1(2, -4);
    PhuongTrinh* pt2 = new PhuongTrinhBac2(1, -3, 2);
    PhuongTrinh* pt3 = new PhuongTrinhBac3(1, -6, 11, -6);

    pt1->solve();
    pt2->solve();
    pt3->solve();

    // Dọn dẹp bộ nhớ
    delete pt1;
    delete pt2;
    delete pt3;

    return 0;
}
