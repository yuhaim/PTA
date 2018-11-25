#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<long> data(N);
    for(int i=0; i<N; i++){
        long x;
        cin >> x;
        data[i] = x;
    }

    sort(data.begin(), data.end());

    bool init = true;

    for(auto x : data){
        if(init)
            init = false;
        else
            cout << ' ';
        cout << x;
    }

    cout << endl;
    return 0;
}
