#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int A, B;
    int D;

    cin>>A>>B>>D;

    int sum = A+B;
    if(sum==0) {
        cout<<0<<endl;
        return 0;
    }
    vector<int> digits;
    while(sum) {
        digits.push_back(sum%D);
        sum /= D;
    }

    for(int i=digits.size()-1; i>=0; i--)
        cout<<digits[i];

    cout<<endl;

    return 0;
}
