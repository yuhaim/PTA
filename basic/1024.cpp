#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string A, sn, n, d, se, e; // [sn]n.dE[se]e
    cin >> A;
    sn = A[0];
    n = A[1];
    int pos = A.find('E');
    d = A.substr(3, pos-3);
    se = A[pos+1];
    e = A.substr(pos+2);

    if(sn[0]=='-')
        cout<<sn;

    int e_int = stoi(e);

    if(e_int==0) {
        cout<<n<<'.'<<d<<endl;
        return 0;
    }

    size_t i=0;
    if(se[0]=='+') {
        cout<<n;
        while(e_int) {
            if(i<d.length()) {
                cout<<d[i];
            } else {
                cout<<0;
            }
            i++;
            e_int--;
        }

        if(i<d.length()) {
            cout<<'.';
            for(;i<d.length(); i++) {
                cout<<d[i];
            }
        }
    } else {
        cout<<"0.";
        e_int--;
        while(e_int) {
            cout<<'0';
            e_int--;
        }

        cout<<n<<d;
    }

    cout<<endl;
    return 0;
}
