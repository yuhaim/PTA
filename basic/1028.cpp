#include <iostream>
#include <string>

using namespace std;

bool valid(const pair<string, string> &x)
{
    string today = "2014/09/06";
    string impossible = "1814/09/06";
    return x.second>=impossible && x.second<=today;
}

int main()
{
    int N;
    cin >> N;
    pair<string, string> young, old, temp;
    bool init = true;
    int count = 0;
    while(N--) {
        string name, birth;
        cin>>name>>birth;

        temp = make_pair(name, birth);
        if(!valid(temp))
            continue;

        if(init){
            young = temp;
            old = temp;
            init = false;
        } else {
            if(temp.second > young.second)
                young = temp;
            else if (temp.second < old.second)
                old = temp;
        }
        count++;
    }

    cout<<count;
    if(count!=0) {
        cout<<' '<<old.first <<' '<<young.first <<endl;
    }
    return 0;
}
