#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    map<int, int> score;
    while(N--) {
        int id, s;
        cin >> id >> s;
        score[id] += s;
    }

    int max_score = 0;
    int max_id;
    for(auto x:score) {
        if(x.second > max_score) {
            max_score = x.second;
            max_id = x.first;
        }
    }

    cout << max_id << ' ' << max_score << endl;
    return 0;
}
