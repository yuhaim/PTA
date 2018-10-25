#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int A1 = 0;
    int A2 = 0;
    int A2_sign = 1;
    int A3 = 0;
    int A4_sum = 0;
    int A4_count = 0;
    int A5 = 0;

    while(N--) {
        int x;
        cin>>x;

        if(!(x%5) && !(x%2))
            A1 += x;

        if(x%5==1) {
            A2 += A2_sign*x;
            A2_sign *= -1;
        }

        if(x%5==2)
            A3++;

        if(x%5==3) {
            A4_sum += x;
            A4_count++;
        }
        
        if(x%5==4) {
            if(x>A5)
                A5 = x;
        }
    }

    if(A1)
        cout<<A1;
    else
        cout<<'N';

    if(A2)
        cout<<' '<<A2;
    else
        cout<<" N";

    if(A3)
        cout<<' '<<A3;
    else
        cout<<" N";

    if(A4_count) {
        double A4 = (double)A4_sum/A4_count;
        printf(" %.1f", A4);
    } else {
        cout<<" N";
    }
    
    if(A5)
        cout<<' '<<A5;
    else
        cout<<" N";

    cout<<endl;

    return 0;
}
