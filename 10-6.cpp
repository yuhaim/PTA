#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> seq(N);
    for(int i=0; i<N; i++){
        cin >> seq[i];
    }

    int count = 0;
    for(int i=0; i<N; i++){
        if(seq[i]!=i)
            count++;
    }

    cout << count << endl;
    return 0;
}
