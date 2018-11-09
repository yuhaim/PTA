#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> array;
    for(int i=0; i<N; i++) {
        int value;
        cin >> value;
        array.push_back(value);
    }

    bool init = true;
    M = M%N;
    for(int i=N-M; i<2*N-M; i++) {
        if(init)
            init = false;
        else
            cout << ' ';

        cout << array[i%N];
    }
    cout << endl;

    return 0;
}
