#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> count;

    int c;
    while(cin>>c) {
        count.push_back(c);
    }

    int i=1;
    while(count[i]==0) i++;
    cout<<i;
    count[i]--;

    for(i=0; i<10; i++) {
        while(count[i]) {
            cout<<i;
            count[i]--;
        }
    }

    cout<<endl;
    return 0;
}
