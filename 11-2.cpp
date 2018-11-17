#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_LIMIT = 100001;
int numbers[MAX_LIMIT];
vector<int> primeList;

void InitPrimes()
{
    for(int i=2; i*i<=MAX_LIMIT; i++)
        for(int j=i; j*i<=MAX_LIMIT; j++)
            if(!numbers[j*i]) numbers[j*i] = 1;

    for(int i=2; i<MAX_LIMIT; i++)
        if(!numbers[i]) primeList.push_back(i);
}

int NextPrime(int x)
{
    auto index = upper_bound(primeList.begin(), primeList.end(), x);
    if(*(--index)==x) 
        return x;
    else 
        return *(++index);
}

int main()
{
    int MSize, N;
    cin >> MSize >> N;

    vector<int> hashTable(MSize);
    vector<int> indexInput(N);
    
    for(int i=0; i<N; i++){
        int numProbe = 0;
        while
    }


    InitPrimes();
    int x;
    cin >> x;
    cout << NextPrime(x) << endl;

    return 0;
}
