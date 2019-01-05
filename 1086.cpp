#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;
vector<int> pre_order;
vector<int> in_order;

bool init = true;
void post_print(int pre_L, int in_L, int in_R)
{
    if(in_L > in_R)
        return;

    int i = in_L;
    while(pre_order[pre_L] != in_order[i])
        i++;

    post_print(pre_L+1, in_L, i-1);
    post_print(pre_L+1+i-in_L, i+1, in_R);

    if(init)
        init = false;
    else
        cout << ' ';
    cout << in_order[i];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\PTA\\1086.txt", "r", stdin);
#endif // ONLINE_JUDGE

    int N;
    cin >> N;
    stack<int> s;

    for(int i=0; i<2*N; i++){
        string cmd;
        int value;
        cin >> cmd;
        if(cmd == "Push"){
            cin >> value;
            pre_order.push_back(value);
            s.push(value);
        } else {
            in_order.push_back(s.top());
            s.pop();
        }
    }

    post_print(0, 0, N-1);
	return 0;
}
