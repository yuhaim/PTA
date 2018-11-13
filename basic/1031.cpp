#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int weight[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
string M = "10X98765432";
bool valid(string id)
{
    int sum = 0;
    for(int i=0; i<17; i++) {
        if(!isdigit(id[i])) return false;
        sum += weight[i]*(id[i] - '0');
    }
    
    if(id[17]==M[sum%11])
        return true;
    else
        return false;
}

int main()
{
    
    int N;
    cin >> N;

    int error = 0;
    while(N--) {
        string id;
        cin >> id;
        if(!valid(id)) {
            cout << id << endl;
            error++;
        }
    }

    if(!error) cout<<"All passed"<<endl;
    return 0;
}

