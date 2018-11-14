#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string bits[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int mar2int(string x)
{
    int i = 0;
    while(bits[i]!=x) i++;
    return i;
}

string int2mar(int x, int bit)
{
    if(bit)
        return bits[x+12];
    else
        return bits[x];
}

int trans_int(string s)
{
    int index = s.find(' ');
    if(index==string::npos) {
        return mar2int(s);
    } else {
        int result = 0;
        result += 13*(mar2int(s.substr(0,index)) - 12);
        result += mar2int(s.substr(index+1));
        return result;
    }
}

string trans_mar(string s)
{
    int value = stoi(s);
    int high = value/13;
    int low = value%13;
    string result;
    if(high) {
        result += int2mar(high, 1);
        if(!low)
            return result;
        result += ' ';
    }

    result += int2mar(low, 0);
    return result;
}

int main()
{
    int N;
    cin >> N;
    string s;
    getline(cin, s);

    while(N--) {
        getline(cin, s);
        if(isdigit(s[0])){
            string mar = trans_mar(s);
            cout << mar << endl;
        } else {
            int integer = trans_int(s);
            cout << integer << endl;
        }
    }
    return 0;
}
