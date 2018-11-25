#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> data(51);

    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        data[x]++;
    }

    for(int i=0; i<51; i++){
        if(data[i])
            cout << i << ':' << data[i] << endl;
    }

    return 0;
}
