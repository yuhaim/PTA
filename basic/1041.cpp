#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    int N, M;
    map<int, pair<string, int> > data;

    cin >> N;
    while(N--) {
        string id;
        int try_num, exam_num;
        cin >> id >> try_num >> exam_num;
        data[try_num] = make_pair(id, exam_num);
    }
    cin >> M;
    while(M--) {
        int query;
        cin >> query;
        auto result = data[query];
        cout << result.first << ' ' << result.second << endl;
    }

    return 0;
}
