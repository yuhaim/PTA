#include <stdio.h>
#include <stdlib.h>

void DFS(int *graph, int v)
{
    char buf[50];
    int top = 0;
    
    if(graph[v*N+0]) {
        return;
    } else {
    buf[top++] = '{';
    
    
    buf[top++] = graph[0];
    

    buf[top++] = '}';
    buf[top] = '\0';

    printf("%s\n", buf);
        
    }
}

void BFS(int *graph, int N)

int main()
{
    int N, E;
    int i;
    int v, w;
    int *graph;

    scanf("%d %d", &N, &E);
    
    graph = (int *)calloc(N*N, sizeof(int));

    for(i=0; i<E; i++) {
        scanf("%d %d", &v, &w);
        graph[v*N + w] = 1;
    }
    
    for(i=0; i<N; i++) {
        ;
    }
    
    free(graph);
    return 0;
}
