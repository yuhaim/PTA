#include <iostream>
#include <string>
#include <vector>

using namespace std;


void BuildMatch(string &pattern, vector<int> &match)
{
    match[0] = -1;
    for(int i=1; i<pattern.length(); i++){
        int prev_match = match[i-1];
        while(prev_match>=0 && pattern[prev_match+1]!=pattern[i])
            prev_match=match[prev_match];
        if(pattern[prev_match+1]==pattern[i])
            match[i] = prev_match+1;
        else
            match[i] = -1;
    }
}

int KMP(string &input, string &pattern)
{
    vector<int> match(pattern.length());
    BuildMatch(pattern, match);

    if(pattern.length()>input.length()) 
        return string::npos;

    int s=0, p=0;
    while(s<input.length() && p<pattern.length()){
        if(input[s]==pattern[p]){
            s++;
            p++;
        } else if(p>0){
            p = match[p-1] + 1;
        } else {
            s++;
        }
    }

    return p==pattern.length() ? (s-p) : string::npos;
}

int main()
{
    string input;
    int N;

    cin >> input;
    cin >> N;

    while(N--){
        string pattern;
        cin >> pattern;
        int position = KMP(input, pattern);
        if(position!=string::npos)
            cout << input.substr(position) << endl;
        else
            cout << "Not Found" <<endl;
    }

    return 0;
 }
