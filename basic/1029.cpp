#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <cctype>

using namespace std;

char trans(char c)
{
    if(islower(c))
        return c + 'A' - 'a';
    else
        return c;
}

int main()
{
    string right, wrong;
    cin>>right>>wrong;

    int i = 0, j = 0;
    unordered_set<char> s;
    vector<char> v;
    while(i<right.length()){
        if(right[i]==wrong[j]) {
            i++;
            j++;
        } else {
            char ch = trans(right[i]);
            auto result = s.insert(ch);
            if(result.second) 
                v.push_back(*result.first);
            i++;
        }
    }

    for(auto x:v)
        cout<<x;

    cout<<endl;

    return 0;
}
