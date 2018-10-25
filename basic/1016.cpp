#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long calc_value(int nd, char ch)
{
    long long sum = 0;
    long long w = 1;
    for(int i=0; i<nd; i++) {
        sum += w*(ch - '0');
        w *= 10;
    }

    return sum;
}

int main()
{
    char ch, DA, DB;
    vector<char> A, B;
    
    while(scanf("%c", &ch) && ch!=' ') {
        A.push_back(ch);
    }

    scanf("%c ", &DA);

    while(scanf("%c", &ch) && ch!=' ') {
        B.push_back(ch);
    }

    scanf("%c", &DB);

    int PA = 0, PB = 0;
    for(auto ch : A) {
        if(ch==DA) PA++;
    }

    for(auto ch : B) {
        if(ch==DB) PB++;
    }

    cout<<calc_value(PA, DA) + calc_value(PB, DB)<<endl;

    return 0;
}
