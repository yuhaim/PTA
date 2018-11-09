#include <iostream>
#include <vector>

using namespace std;

istream &operator>>(istream &in, vector<pair<int, int> > &poly)
{
    int coeff, expon;
    if(in>>coeff>>expon)
        poly.push_back(make_pair(coeff, expon));
    return in;
}

ostream &operator<<(ostream &out, pair<int, int> &item)
{
    int coeff = item.first*item.second;
    if(coeff) {
        out<<coeff<<' '<<item.second-1;
    }
    return out;
}

int main()
{
    vector<pair<int, int> > poly;
    while(cin>>poly);
    
    bool init = true;
    bool output = false;
    for(auto item : poly) {
        if(init)
            init = false;
        else if(item.second)
            cout<<' ';
        else
            ;

        if(item.second)
            output = true;
        cout<<item;
    }

    if(!output)
        cout<<"0 0";
    cout<<endl;
    return 0;
}
