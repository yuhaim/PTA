#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    double sum = 0.0;
    for(int i=0; i<N; i++) {
        float x;
        scanf("%f", &x);
        sum += x*(i+1)*(N-i);
    }

    printf("%.2f\n", sum);

    return 0;
}
