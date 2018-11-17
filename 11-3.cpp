#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;

    unordered_map<string, string> db;
    while(N--){
        char cmd;
        cin >> cmd;
        string id, pwd;
        cin >> id >> pwd;

        switch(cmd){
            case 'N':{
                auto result = db.insert(make_pair(id, pwd));
                if(result.second)
                    cout << "New: OK" << endl;
                else
                    cout << "ERROR: Exist" << endl;
                break;
                     }
            case 'L':{
                auto result = db.find(id);
                if(result == db.end())
                    cout << "ERROR: Not Exist" << endl;
                else if((*result).second == pwd)
                    cout << "Login: OK" << endl;
                else 
                    cout << "ERROR: Wrong PW" << endl;
                break;
                     }
            default:
                break;
        }
    }

    return 0;
}
