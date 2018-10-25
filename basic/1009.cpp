#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<string> sentence;
    string s;
    while(cin>>s){
        sentence.push(s);
    }

    bool init = true;
    while(!sentence.empty()){
        if(init)
            init = false;
        else
            cout << ' ';

        cout << sentence.top();
        sentence.pop();
    }

    cout << endl;
    
    return 0;
}
