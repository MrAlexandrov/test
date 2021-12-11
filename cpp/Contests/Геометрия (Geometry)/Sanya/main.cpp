#include <bits/stdc++.h>
using namespace std;
/*
struct PT {
    double x, y;
    PT() { x = 0, y = 0; }
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &a) const { return PT(x + a.x, y + a.y); }
    PT operator - (const PT &a) const { return PT(x - a.x, y - a.y); }
    PT operator * (const double a) const { return PT(x * a, y * a); }
    friend PT operator * (const double &a, const PT &b) { return PT(a * b.x, a * b.y); }
    PT operator / (const double a) const { return PT(x / a, y / a); }
    bool operator == (PT a) const { return sign(a.x - x) == 0 && sign(a.y - y) == 0; }
    bool operator != (PT a) const { return !(*this == a); }
    bool operator < (PT a) const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
    bool operator > (PT a) const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
    double norm() { return sqrt(x * x + y * y); }
    double norm2() { return x * x + y * y; }
    PT perp() { return PT(-y, x); }
    double arg() { return atan2(y, x); }
    PT truncate(double r) { // returns a vector with norm r and having same direction
        double k = norm();
        if (!sign(k)) return *this;
        r /= k;
        return PT(x * r, y * r);
    }
    friend ostream& operator << (ostream& out, PT &p) {
        return out << p.x << ' ' << p.y;
    }
    friend istream& operator >> (istream& in, PT& p) {
        in >> p.x >> p.y;
        return in;
    }
};
*/
class Drob {
private:
    int chis, znam;
public:
    int get_chis() { return this -> chis; };
    int get_znam() { return this -> znam; };
    Drob() {chis = 0, znam = 1;};                                    /// конструктор по умолчанию
    Drob(int _chis, int _znam) : chis(_chis), znam(_znam) {};       /// конструктор
    Drob(const Drob &x) : chis(x.chis), znam(x.znam) {};

    void norm();

    friend ostream& operator << (ostream&, const Drob&);
    friend istream& operator >> (istream&, const Drob&);
    Drob operator + (Drob&);
    Drob operator - (Drob&);
    Drob operator * (Drob&);
    Drob operator / (Drob&);
    friend Drob operator + (int, Drob&);
    friend Drob operator - (int, Drob&);
    friend Drob operator * (int, Drob&);
    friend Drob operator / (int, Drob&);
    Drob& operator = (const Drob &x) {chis = x.chis, znam = x.znam;};
};

int gcd(int a, int b) {
    int t;
    while (b != 0) {
        t = a;
        a = b;
        b = t % b;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void Drob::norm() {
    int g = gcd(this -> chis, this -> znam);
    this -> chis /= g;
    this -> znam /= g;
}

ostream& operator << (ostream& out, const Drob& x) {
    out << x.chis << '/' << x.znam;
    return out;
}

istream& operator >> (istream& in, Drob& x) {
    string t;
    in >> t;
    if (t.empty()) {
        x = Drob();
        return in;
    }
    bool otr = false;
    int i = 0;
    if (!('0' <= t[0] && t[0] <= '9')) {
        i++;
        if (t[0] == '-') {
            otr = true;
        }
    }
    int a = 0;
    while (t[i] != '/') {
        a *= 10;
        a += (t[i] - '0');
        i++;
    }
    i++;
    int b = 0;
    while (i < t.size()) {
        b *= 10;
        b += (t[i] - '0');
        i++;
    }
    x = Drob(a, b);
    x.norm();
    return in;
}

Drob Drob::operator + (Drob& x) {
    int l = lcm(znam, x.znam);
    *this -> chis *= l;
    *this -> znam *= l;
    x = x * l;
    this.chis += x.chis;
    this.norm();
    return this;
}

Drob Drob::operator - (Drob& x) {
    int l = lcm(znam, x.znam);
    this = this * l;
    x = x * l;
    this.chis -= x.chis;
    this.norm();
    return this;
}

Drob Drob::operator * (Drob& x) {
    this.chis *= x.chis;
    this.znam *= x.znam;
    this.norm();
    return this;
}

Drob Drob::operator * (int x) {
    this.chis *= x;
    this.norm();
    return this;
}

Drob operator * (ll x, Drob& A) {
    this.chis *= x;
    this.norm();
    return this;
}

Drob operator - (Drob& x) {
    return Drob(-x.chis, x.znam);
}

Drob operator + (Drob& x) {
    return x;
}

int main() {
    ///
    return 0;
}

/**


**/
