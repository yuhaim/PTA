#include <iostream>
#include <map>
#include <string>
#include <stack>

using namespace std;

int main()
{
    char digit;
    int sum = 0;
    while(cin>>digit) {
        sum += digit - '0';
    }

    map<int,string> pinyin;
    pinyin[0] = "ling";
    pinyin[1] = "yi";
    pinyin[2] = "er";
    pinyin[3] = "san";
    pinyin[4] = "si";
    pinyin[5] = "wu";
    pinyin[6] = "liu";
    pinyin[7] = "qi";
    pinyin[8] = "ba";
    pinyin[9] = "jiu";

    stack<string> reading;
    while(sum) {
        reading.push(pinyin[sum%10]);
        sum/=10;
    }

    while(reading.size()) {
        cout<<reading.top();
        reading.pop();
        if(reading.size())
            cout<<" ";
        else
            cout<<endl;
    }
    return 0;
}
