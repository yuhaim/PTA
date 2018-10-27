#include <iostream>
#include <string>

using namespace std;

int main()
{
    string A;
    int B;
    string Q;
    int R = 0;

    cin>>A>>B;

    int i = 0;
    while(i<A.length()) {
        int current = R*10 + A[i] - '0';
        int j = 0;
        while(j*B<=current) j++;
        j--;
        Q += j + '0';
        R = current - j*B;

        i++;
    }

    i=0;
    if(Q.length()>1) {
        while(Q[i]=='0') i++;
    }

    cout<<Q.substr(i)<<' '<<R<<endl;

    return 0;
}
