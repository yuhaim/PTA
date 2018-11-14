#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    char c;
    map<char, int> count;
    int num = 0;
    while(scanf("%c", &c) != EOF) {
        switch(c){
            case 'P':
                count['P']++; num++;
                break;
            case 'A':
                count['A']++; num++;
                break;
            case 'T':
                count['T']++; num++;
                break;
            case 'e':
                count['e']++; num++;
                break;
            case 's':
                count['s']++; num++;
                break;
            case 't':
                count['t']++; num++;
                break;
            default:
                break;
        }
    }

    string pat = "PATest";
    while(num) {
        for(auto x:pat){
            if(count[x]) {
                cout << x;
                count[x]--; num--;
            }
        }
    }
    cout << endl;
    return 0;
}

