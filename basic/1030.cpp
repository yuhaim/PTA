#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int data[100001];
int main()
{
    int N, p;
    cin>>N>>p;

    for(int i=0; i<N; i++){
        int x;
        scanf("%d", &x);
        data[i] = x;
    }

    sort(data, data+N);
    int max_count = 0;
    for(int i=0; i<N; i++) {
        int index;
        for(index=N-1; index>=i; index--) {
            if(data[index]<=data[i]*p)
                break;
        }

        int count = index - i + 1;
        if(count>max_count)
            max_count = count;
    }

    cout<<max_count<<endl;
    return 0;
}

