#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<char, int> stat;
    
    char c;
    while(cin>>c) {
        stat[c]++;
    }

    for(auto x : stat) {
        cout<<x.first<<':'<<x.second<<endl;
    }

    return 0;
}

