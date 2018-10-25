#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int M, N;
    cin>>M>>N;
    
    int max = 120000;
    vector<int> index(max+1, 1);

    for(int i=2; i*i<=max; i++)
        for(int j=i; j*i<=max; j++)
            index[j*i] = 0;

    int count = 0;
    int count_pre = 0;
    bool init = true;
    for(int i=2; i<=max && count<N; i++){
        if(index[i]) count++;
        if(count!=count_pre && count>=M) {
            if(init)
                init = false;
            else if((count-M)%10)
                cout<<' ';
            else
                cout<<endl;

            cout<<i;

            count_pre = count;
        }
    }

    cout<<endl;

    return 0;
}
