#include <iostream>
#include <map>
#include <string>
using namespace std;
istream &operator>>(istream &in, map<int, pair<string, string> > &record)
{
    string name;
    string id;
    int score;

    in>>name>>id>>score;
    pair<string, string> info;
    info.first = name;
    info.second = id;
    record[score] = info;
    return in;
}

ostream &operator<<(ostream &out, map<int, pair<string, string> >::iterator iter_record)
{
    out<<iter_record->second.first<<" "
        <<iter_record->second.second<<endl;
    return out;
}

int main()
{
    map<int, pair<string, string> > record;
    int n;
    cin>>n;

    while(n--) {
        cin>>record;
    }

    cout<<--record.end();
    cout<<record.begin();

    return 0;
}
