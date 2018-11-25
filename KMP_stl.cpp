#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    int N;

    cin >> input;
    cin >> N;

    while(N--){
        string pattern;
        cin >> pattern;
        int position = input.find(pattern);
        if(position!=string::npos)
            cout << input.substr(position) << endl;
        else
            cout << "Not Found" <<endl;
    }

    return 0;
}
