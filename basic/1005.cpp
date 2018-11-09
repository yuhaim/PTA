#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> Callatz(int x)
{
    vector<int> series;

    while(x!=1) {
        x = (x%2) ? (3*x+1)/2 : x/2;
        series.push_back(x);
    }

    return series;
}

struct Rule {
    bool operator()(int x, int y){
        return x>y;
    }
};

int main()
{
    int K;
    cin>>K;

    set<int, Rule> nums;
    set<int> covered;

    while(K--) {
        int x;
        cin>>x;
        if(covered.find(x)==covered.end()) {
            nums.insert(x);
            covered.insert(x);
        }

        vector<int> series = Callatz(x);

        for(auto x:series) {
            nums.erase(x);
            covered.insert(x);
        }
    }
    
    bool init = true;
    for(auto x:nums) {
        if(init)
            init = false;
        else
            cout<<' ';
        cout<<x;
    }

    cout<<endl;

    return 0;
}
