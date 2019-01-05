#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
const int max_v = 201;
int graph[max_v][max_v];
int Nv, Ne;

int is_clique(const vector<int> &v)
{
    vector<bool> visited(Nv+1, false);
    vector<int> included;
    for(auto x : v){
        for(auto y : included){
            if(graph[x][y]!=1)
                return -1;
        }
        included.push_back(x);
        visited[x] = true;
    }

    for(int i=1; i<=Nv; i++){
        if(visited[i]==false){
            int j;
            for(j=0; j<included.size(); j++){
                if(graph[i][included[j]]!=1)
                    break;
            }
            if(j==included.size())
                return 1;
        }
    }

    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\PTA\\1142.txt", "r", stdin);
#endif
    cin >> Nv >> Ne;

    for(int i=0; i<Ne; i++){
        int p, q;
        cin >> p >> q;
        graph[p][q] = 1;
        graph[q][p] = 1;
    }

    int M;
    cin >> M;

    for(int i=0; i<M; i++){
        int K;
        cin >> K;
        vector<int> v(K);
        for(int j=0; j<K; j++){
            cin >> v[j];
        }

        switch(is_clique(v)){
        case 0:
            cout << "Yes" << endl;
            break;
        case 1:
            cout << "Not Maximal" << endl;
            break;
        case -1:
            cout << "Not a Clique" << endl;
            break;
        default:
            break;
        }
    }

    return 0;
}
