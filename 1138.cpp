#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
vector<int> pre_order;
vector<int> in_order;

bool flag = false;
void print_post(int pre_L, int in_L, int in_R)
{
    if(in_L>in_R || flag)
        return;

    int i= in_L;
    while(in_order[i] != pre_order[pre_L])
        i++;
    print_post(pre_L+1, in_L, i-1);
    print_post(pre_L+1+i-in_L, i+1, in_R);

    if(!flag){
        cout << in_order[i] << endl;
        flag = true;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\PTA\\1138.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int N;
    cin >> N;
    pre_order.resize(N);
    in_order.resize(N);

    for(int i=0; i<N; i++)
        cin >> pre_order[i];

    for(int i=0; i<N; i++)
        cin >> in_order[i];

    print_post(0, 0, N-1);

    return 0;
}
