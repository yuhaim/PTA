#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int C1, C2;
    cin>>C1>>C2;

    double t = 0.01*(C2 - C1);
    int t_int = (t - (int)(t)) + 0.0001 > 0.5 ? (int)t + 1 : (int)t;

    int s, m, h;
    s = t_int%60; t_int /= 60;
    m = t_int%60;
    h = t_int/60;
    printf("%02d:%02d:%02d\n", h, m, s);

    return 0;
}
