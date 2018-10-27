#include <iostream>
#include <map>

using namespace std;

int count(map<char, int> &record)
{
    return record['C'] + record['J'] + record['B'];
}

char max_count(map<char, int> &record)
{
    string key = "BCJ";
    int m = 0;
    char m_ch = 'B';
    for(int i=0; i<3; i++) {
        if(record[key[i]]>m) {
            m = record[key[i]];
            m_ch = key[i];
        }
    }
    
    return m_ch;
}

int main()
{
    int N;
    cin>>N;

    map<string, int> table;
    table["CC"] = 0;
    table["CJ"] = 1;
    table["CB"] = -1;
    table["JC"] = -1;
    table["JJ"] = 0;
    table["JB"] = 1;
    table["BC"] = 1;
    table["BJ"] = -1;
    table["BB"] = 0;

    map<char, int> win[2], fair[2], lose[2];

    while(N--) {
        char x, y;
        cin>>x>>y;
        string check;
        check+=x;
        check+=y;

        int result = table[check];
        if(result>0){
            win[0][x]++;
            lose[1][y]++;
        } else if(result<0) {
            lose[0][x]++;
            win[1][y]++;
        } else {
            fair[0][x]++;
            fair[1][y]++;
        }
    }

    for(int i=0; i<2; i++) {
        cout << count(win[i]) << ' '
             << count(fair[i]) << ' '
             << count(lose[i]) << endl;
    }

    cout << max_count(win[0]) << ' ' << max_count(win[1]) << endl;

    return 0;
}

