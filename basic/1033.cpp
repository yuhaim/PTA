#include <iostream>
#include <string>
#include <set>
#include <cctype>

using namespace std;
int main()
{
    string error_key;
    string input;
    getline(cin, error_key);
    getline(cin, input);

    set<char> error_set;

    bool error_shift = false;
    for(int i=0; i<error_key.length(); i++) {
        if(error_key[i]=='+') 
            error_shift = true;
        error_set.insert(error_key[i]);
    }

    for(int i=0; i<input.length(); i++) {
        char c = input[i];
        if(error_shift && isupper(c))
            continue;
        
        auto result = error_set.find(toupper(c));
        if(result!=error_set.end())
            continue;
        else
            cout << c;
    }

    cout << endl;
    return 0;
}
