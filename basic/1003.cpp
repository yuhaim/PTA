#include <iostream>
#include <string>
using namespace std;

bool valid(string s)
{
    for(size_t i=0; i<s.length(); i++)
        if(s[i]!='P' && s[i]!='A' && s[i]!='T')
            return false;
    string prefix;
    string postfix;

    size_t i = 0;
    for(; i<s.length() && s[i]=='A'; i++)
        prefix+=s[i];

    if(i<=s.length()-1 && s[i]=='P')
        i++;
    else
        return false;

    int i_prev = i;
    while(i<=s.length()-1 && s[i]=='A')
        i++;

    if(i<=i_prev)
        return false;

    int central_count = i - i_prev - 1;

    if(i<=s.length()-1 && s[i]=='T')
        i++;
    else
        return false;

    for(; i<s.length() && s[i]=='A'; i++)
        postfix+=s[i];

    if(prefix.length()==0 && postfix.length()==0)
        return true;
    else {
        int post_count = postfix.length()/prefix.length()-1;
        if(central_count == post_count)
        return true;
    }

    return false;
}

int main()
{
    int n;
    cin>>n;

    while(n--) {
        string s;
        cin>>s;
        if(valid(s))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
