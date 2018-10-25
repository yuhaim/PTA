#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> primes(N+1, 1);

    for(int i=2; i*i<=N; i++) {
        for(int j=i; j*i<=N; j++) {
            primes[j*i] = 0;
        }
    }

    int count = 0;
    for(int i=2; i<N+1; i++) {
        if(primes[i] && primes[i+2])
            count++;
    }

    cout << count << endl;

    return 0;
}

