#include <iostream>

using namespace std;

struct Money {
    long long yuan;
    long long jiao;
    long long fen;
};

long long Money2Int(Money m) {
    return m.fen + (m.yuan*17 + m.jiao)*29;
}

Money Int2Money(long long x) {
    Money m;
    if(x<0) {
        m.fen = -(x%29);
        m.jiao = -(x/29)%17;
    } else {
        m.fen = x%29;
        m.jiao = (x/29)%17;
    }
    m.yuan = x/29/17;
    return m;
}

int main()
{
    Money P, A;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", 
            &P.yuan, &P.jiao, &P.fen,
            &A.yuan, &A.jiao, &A.fen);

    long long R_int = Money2Int(A) - Money2Int(P);
    Money R = Int2Money(R_int);
    cout << R.yuan <<'.'<< R.jiao <<'.'<< R.fen << endl;
    return 0;
}
