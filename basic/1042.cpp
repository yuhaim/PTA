#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main()
{
    string input;
    getline(cin, input);

    map<char, int> count;
    for(auto x:input){
        count[tolower(x)]++;
    }

    char max_char;
    int max_count = 0;
    for(auto x:count){
        if(islower(x.first) && x.second>max_count){
            max_char = x.first;
            max_count = x.second;
        }
    }

    cout << max_char << ' ' << max_count << endl;

    return 0;
}

