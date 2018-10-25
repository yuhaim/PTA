#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> digits;
    while(n) {
        digits.push_back(n%10);
        n /= 10;
    }

    for(int i=digits.size()-1; i<3; i++) {
        digits.push_back(0);
    }

    int b = digits[2];
    int s = digits[1];
    int g = digits[0];

    for(int i=0; i<b; i++) {
        cout << 'B';
    }

    for(int i=0; i<s; i++) {
        cout << 'S';
    }

    for(int i=0; i<g; i++) {
        cout << i+1;
    }

    cout << endl;

    return 0;
}
