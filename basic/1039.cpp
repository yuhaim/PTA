#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char, int> offer;
    map<char, int> want;

    string offer_str, want_str;
    cin >> offer_str >> want_str;

    for(int i=0; i<offer_str.length(); i++) {
        offer[offer_str[i]]++;
    }

    for(int i=0; i<want_str.length(); i++) {
        want[want_str[i]]++;
    }

    int more = 0;
    int lack = 0;
    bool satisfied = true;
    for(auto x:want) {
        int query = offer[x.first];
        if(query>x.second) {
            more += query - x.second;
        }
        else if(query<x.second){
            satisfied = false;
            lack += x.second - query;
        }
        offer.erase(x.first);
    }

    if(satisfied) {
        for(auto x:offer){
            more += x.second;
        }
        cout << "Yes " << more << endl;
    }
    else
        cout << "No " << lack << endl;

    return 0;
}

