#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;

    map<string, int> count;
    for(int i=0; i<2*N; i++) {
        string number;
        cin >> number;
        count[number]++;
    }

    int max_count = 0;
    string max_number;
    for(auto x:count){
        if(x.second > max_count) {
            max_count = x.second;
            max_number = x.first;
        }
    }

    int equal_num = 0;
    for(auto x:count) {
        if(x.second==max_count)
            equal_num++;
    }

    cout << max_number << ' ' << max_count;
    if(equal_num>1) cout << ' ' << equal_num;

    cout << endl;

    return 0;
}
