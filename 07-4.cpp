#include <iostream>
#include <vector>

using namespace std;
int graph[101][101];
const int INF = 100000;

int main()
{
    int N, M;
    cin >> N >> M;

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            if(i!=j){
                graph[i][j]=INF;
            }

    for(int i=0; i<M; i++){
        int x, y, len;
        cin >> x >> y >> len;
        graph[x][y] = len;
        graph[y][x] = len;
    }

    for(int k=1; k<=N; k++)
       for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++){
                if(graph[i][j]>graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }

    int min_key;
    int min_value = INF;

    bool connected = false;
    for(int i=1; i<=N; i++){
        int max_value = 0;
        bool full = true;
        for(int j=1; j<=N; j++){
            if(graph[i][j] == INF) full = false;
            if(graph[i][j] != INF && graph[i][j]>max_value)
                max_value = graph[i][j];
        }

        connected = connected || full;

        if(max_value<min_value){
            min_value = max_value;
            min_key = i;
        }
    }

    if(connected)
        cout << min_key << ' ' << min_value << endl;
    else
        cout << 0 << endl;
}
