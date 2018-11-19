#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string error_string = "Are you kidding me? @\\/@";
    string char_set[3];
    vector<string> symbols[3];

    for(int i=0; i<3; i++){
        getline(cin, char_set[i]);
        
        for(int j=0; j<char_set[i].length(); j++){
            if(char_set[i][j] == '['){
                string s;
                while(++j < char_set[i].length() && char_set[i][j] != ']'){
                    s += char_set[i][j];
                }
                if(!s.empty())
                    symbols[i].push_back(s);
            }
        }
    }

    int K;
    cin >> K;

    while(K--) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;

        if(a-1>=symbols[0].size() || 
           b-1>=symbols[1].size() ||
           c-1>=symbols[2].size() ||
           d-1>=symbols[1].size() ||
           e-1>=symbols[0].size())
            cout << error_string << endl;
        else{
            cout << symbols[0][a-1] << '('
                 << symbols[1][b-1]
                 << symbols[2][c-1]
                 << symbols[1][d-1] << ')'
                 << symbols[0][e-1] << endl;
        }
    }

    return 0;
}

