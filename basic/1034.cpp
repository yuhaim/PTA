#include <iostream>
#include <cmath>

using namespace std;

int gcd(long long a, long long b)
{
    long long t;
    while(b) {
        t = a;
        a = b;
        b = t%b;
    }

    return (int)a;
}

struct Rational {
    int s;
    int k;
    int a;
    int b;
};

Rational ration(int s, long long a, long long b)
{
    Rational ra;
    ra.s = ra.k = ra.a = ra.b = 0;
    if(!b) return ra;
    ra.s = s;
    ra.k = a/b;
    a = a%b;

    int g = gcd(a, b);
    ra.a = a/g;
    ra.b = b/g;
    return ra;
}

ostream &operator<<(ostream &out, Rational r)
{
    if(r.b == 0) {
        out << "Inf";
        return out;
    }

    if(r.k == 0 && r.a == 0) {
        out << '0';
        return out;
    }

    if(r.s<0)
        out << "(-";
    if(r.k){
        out << r.k;
        if(r.b!=1)
            out << ' ';
    }
    if(r.b!=1)
        out << r.a << '/' << r.b;
    if(r.s<0)
        out << ')';

    return out;
}

Rational rational_plus(Rational r1, Rational r2)
{
    long long a1 = r1.b*r1.k + r1.a;
    long long a2 = r2.b*r2.k + r2.a;

    long long a = r1.s*a1*r2.b + r2.s*a2*r1.b;
    long long b = r1.b*r2.b;

    int s = a < 0 ? -1 : 1;
    a = abs(a);

    return ration(s, a, b);
}

Rational rational_minus(Rational r1, Rational r2)
{
    r2.s = -r2.s;
    return rational_plus(r1, r2);
}

Rational rational_mul(Rational r1, Rational r2)
{
    int s = r1.s*r2.s;

    long long a1 = r1.b*r1.k + r1.a;
    long long a2 = r2.b*r2.k + r2.a;

    long long a = a1*a2;
    long long b = r1.b*r2.b;

    return ration(s, a, b);
}

Rational rational_divide(Rational r1, Rational r2)
{
    int s = r1.s*r2.s;

    long long a1 = r1.b*r1.k + r1.a;
    long long a2 = r2.b*r2.k + r2.a;

    long long a = a1*r2.b;
    long long b = r1.b*a2;

    return ration(s, a, b);
}

int main()
{
    int s1, a1, b1;
    int s2, a2, b2;

    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);

    if(a1<0){
        s1 = -1;
        a1 = abs(a1);
    } else {
        s1 = 1;
    }

    if(a2<0){
        s2 = -1;
        a2 = abs(a2);
    } else {
        s2 = 1;
    }

    Rational r1 = ration(s1, a1, b1);
    Rational r2 = ration(s2, a2, b2);

    Rational r_s = rational_plus(r1, r2);
    Rational r_m = rational_minus(r1, r2);
    Rational r_mul = rational_mul(r1, r2);
    Rational r_d = rational_divide(r1, r2);

    cout << r1 << " + " << r2 << " = " << r_s << endl;
    cout << r1 << " - " << r2 << " = " << r_m << endl;
    cout << r1 << " * " << r2 << " = " << r_mul << endl;
    cout << r1 << " / " << r2 << " = " << r_d << endl;

    return 0;
}
