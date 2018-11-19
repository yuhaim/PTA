#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int N;
    cin >> N;

    double e;
    int D;
    cin >> e >> D;

    int possible_void = 0, surely_void = 0;
    for(int i=0; i<N; i++){
        int K;
        cin >> K;
        int count = 0;
        for(int j=0; j<K; j++){
            double E;
            cin >> E;
            if(E<e) count++;
        }

        if(2*count>K && K>D)
            surely_void++;
        else if(2*count>K && K<=D)
            possible_void++;
        else{}
    }

    printf("%.1f%% %.1f%%\n", 100.0*possible_void/N, 100.0*surely_void/N);
    return 0;
}
