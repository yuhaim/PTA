#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v(N), w(N), u;

    for(int i=0; i<N; i++) {
        int x;
        scanf("%d", &x);
        w[i] = v[i] = x;
    }

    sort(v.begin(), v.end());

    int max_value = 0;
    for(int i=0; i<N; i++) {
        if(v[i]==w[i] && v[i]>max_value){
            u.push_back(v[i]);
        }
        if(w[i]>max_value)
            max_value = w[i];
    }

    cout << u.size() << endl;
    bool init = true;
    for(auto x:u) {
        if(init)
            init = false;
        else
            cout << ' ';
        cout << x;
    }

    cout << endl;
    return 0;
}

