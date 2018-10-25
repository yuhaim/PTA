#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cctype>

using namespace std;

bool isday(char ch)
{
    return ch>='A' && ch<='G';
}

bool ishour(char ch)
{
    return (ch>='0'&&ch<='9') || (ch>='A'&&ch<='N');
}

int main()
{
    vector<string> week;
    week.push_back("MON");
    week.push_back("TUE");
    week.push_back("WED");
    week.push_back("THU");
    week.push_back("FRI");
    week.push_back("SAT");
    week.push_back("SUN");

    string s1, s2, s3, s4;
    cin>>s1>>s2>>s3>>s4;
    
    char day;
    char hour;

    set<char> day_set;
    set<char> hour_set;
    for(auto ch : s1) {
        if(isday(ch))
            day_set.insert(ch);
        if(ishour(ch))
            hour_set.insert(ch);
    }

    int i;
    for(i=0; i<s2.length(); i++) {
        while(!isday(s2[i])) i++;

        if(day_set.find(s2[i])!=day_set.end()){
            day = s2[i];
            break;
        }
    }
    
    for(i++; i<s2.length(); i++) {
        while(!ishour(s2[i])) i++;

        if(hour_set.find(s2[i])!=hour_set.end())
            hour = s2[i];
    }

    cout<<week[day-'A']<<" ";
    int hour_digit;
    if(hour>='0'&&hour<='9')
        hour_digit = hour-'0';
    else
        hour_digit = hour-'A'+10;

    cout<<hour_digit<<":";

    int len = s3.length()>s4.length() ? s4.length() : s3.length();
    for(int i=0; i<len; i++) {
        if(isalpha(s3[i]) && s3[i]==s4[i]) {
            printf("%02d", i);
            break;
        }
    }
    
    cout<<endl;
    return 0;
}

