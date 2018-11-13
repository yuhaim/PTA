#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int data[100001];
int main()
{
    int N;
    long long p;
    cin>>N>>p;

    for(int i=0; i<N; i++){
        int x;
        scanf("%d", &x);
        data[i] = x;
    }

    sort(data, data+N);
    int max_count = 0;
    for(int i=0; i+max_count<N; i++) {
        int index;
        for(index=i+max_count; index<N; index++) {
            if(data[index]>data[i]*p)
                break;
        }

        int count = index - i;
        if(count>max_count)
            max_count = count;
    }

    cout<<max_count<<endl;
    return 0;
}

