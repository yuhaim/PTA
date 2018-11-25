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
    if(*(index-1) == x) 
        return x;
    else 
        return *index;
}

int main()
{
    InitPrimes();
    int MSize, N;
    cin >> MSize >> N;

    MSize = NextPrime(MSize);

    vector<int> hashTable(MSize);
    vector<int> indexInput(N);
    
    for(int i=0; i<N; i++){
        int x;
        cin >> x;

        int index = x%MSize;
        int numProbe = 0;
        int j;
        for(j=0; j<MSize; j++){
            if(hashTable[index]!=0){
                numProbe++;
                index = (x + numProbe*numProbe)%MSize;
            }else{
                hashTable[index] = x;
                indexInput[i] = index;
                break;
            }
        }

        if(j==MSize){
            indexInput[i] = -1;
        }
    }

    bool init = true;
    for(int i=0; i<N; i++){
        if(init)
            init = false;
        else
            cout << ' ';
        
        if(indexInput[i]>=0)
            cout << indexInput[i];
        else
            cout << '-';
    }

    return 0;
}
