#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N;
    cin>>N;

    set<int> record;
    while(N--) {
        int x;
        cin>>x;
        if(x>0)
            record.insert(x);
    }

    int i=1;
    while(record.find(i)!=record.end())
        i++;

    cout<<i<<endl;

    return 0;
}
