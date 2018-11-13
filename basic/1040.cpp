#include <iostream>
#include <string>

using namespace std;

int main()
{
    int m = 1000000007;
    int sum = 0;
    string s;
    cin >> s;

    for(int i=0; i<s.length()-2; i++) {
        while(s[i]!='P') i++;

        for(int j=i+1; j<s.length()-1; j++) {
            while(s[j]!='A') j++;

            for(int k=j+1; k<s.length(); k++) {
                while(s[k]!='T' && k<s.length()) k++;
                if(s[k]=='T') sum++;
                continue;
            }
            sum %= m;
        }
    }

    cout << sum <<endl;
    return 0;
}
