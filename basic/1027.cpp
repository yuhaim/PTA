#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n;
    char c;
    scanf("%d %c", &n, &c);
    int layer = 1;
        
    while(2*layer*layer-1<=n) {
        layer++;
    }

    layer--;
    int r = n - (2*layer*layer-1);

    int j = 0;
    for(int i=1; i<2*layer; i++) {
        for(int k=0; k<j; k++)
            cout<<' ';
        for(int k=0; k<2*layer-1-2*j; k++)
            cout<<c;
        cout<<endl;
        if(i<layer)
            j++;
        else
            j--;
    }

    cout<<r<<endl;
    return 0;
}
