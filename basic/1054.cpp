#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool is_valid(string input)
{
    string s;
    if(input[0] == '-')
        s = input.substr(1);
    else
        s = input;

    int count_dot = 0;
    for(auto x : s){
        if(x=='.') count_dot++;
        if(!isdigit(x) && x!='.')
            return false;
    }

    if(count_dot>1) return false;

    if(count_dot==1){
        int index = s.find('.');
        if(s.length()-1>index+2) return false;
    }

    double value = stod(s);

    if(value>1000) return false;
    
    return true;
}

int main()
{
    int N;
    cin >> N;

    double sum = 0.0;
    int count = 0;

    while(N--){
        string s;
        cin >> s;

        if(is_valid(s)){
            sum += stod(s);
            count++;
        } else {
            cout << "ERROR: " << s 
                 << " is not a legal number" << endl;
        }
    }

    string number_string;
    if(count == 1)
        number_string = " number";
    else
        number_string = " numbers";

    cout << "The average of " << count << number_string
         << " is ";

    if(count == 0)
        cout << "Undefined" << endl;
    else
        printf("%.2f\n", sum/count);

    return 0;
}
