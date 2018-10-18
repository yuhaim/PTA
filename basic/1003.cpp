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

    if(i+2<=s.length()-1 && s.substr(i,3)=="PAT")
        i+=3;
    else if(i+3<=s.length()-1 && s.substr(i,4)=="PAAT")
        i+=4;
    else
        return false;

    for(; i<s.length() && s[i]=='A'; i++)
        postfix+=s[i];

    if((postfix.length() == prefix.length()) || 
       (postfix.length() == 2*prefix.length()))
        return true;

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
