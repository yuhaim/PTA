#include <stdio.h>
#include <stdlib.h>

int spaceCtrl = 0;

void DFS(int *graph, int N, int v, int *visited)
{
    int i;
    if(!visited[v]) {
        visited[v] = 1;
        if(!spaceCtrl){
            spaceCtrl = 1;
        } else {
            printf(" ");
        }
        printf("%d", v);
        for(i=0; i<N; i++) {
            if(graph[v*N+i]) {
                DFS(graph, N, i, visited);
            }
        }
    }
}

void BFS(int *graph, int N, int v, int *visited)
{
    int *queue;
    int front = 0, rear = 0;
    int w;
    int i;

    queue = (int *)calloc(N+1, sizeof(int));
    queue[(++rear)%(N+1)] = v;

    while(front!=rear) {
        front = (1+front)%(N+1);
        w = queue[front];
        visited[w] = 1;

        if(!spaceCtrl){
            spaceCtrl = 1;
        } else {
            printf(" ");
        }
        printf("%d", w);
        for(i=0; i<N; i++) {
            if(graph[w*N+i]) {
                rear = (1+rear)%(N+1);
                queue[rear] = w;
            }
        }
    }

    free(queue);
}

int main()
{
    int N, E;
    int i;
    int v, w;
    int *graph, *visited;
    int flag = 0, flagPre = 0;

    scanf("%d %d", &N, &E);
    
    graph = (int *)calloc(N*N, sizeof(int));
    visited = (int *)calloc(N, sizeof(int));

    for(i=0; i<E; i++) {
        scanf("%d %d", &v, &w);
        graph[v*N + w] = 1;
        graph[w*N + v] = 1;
    }
    
    for(i=0; i<N; i++) {
        if(!flagPre && flag) {
            printf("}\n");
            spaceCtrl = 0;
        }
        flagPre = flag;
        if(!visited[i]) {
            flag = 1;
            printf("{");
            DFS(graph, N, i, visited);
        } else {
            flag = 0;
        }
    }
    
    if(flag == 1)
        printf("}\n");

    flag = flagPre = 0;
    spaceCtrl = 0;
    for(i=0; i<N; i++) {
        visited[i] = 0;
    }
    
    for(i=0; i<N; i++) {
        if(!flagPre && flag) {
            printf("}\n");
            spaceCtrl = 0;
        }
        flagPre = flag;
        if(!visited[i]) {
            flag = 1;
            printf("{");
            BFS(graph, N, i, visited);
        } else {
            flag = 0;
        }
    }
    
    if(flag == 1)
        printf("}\n");

    free(visited);
    free(graph);
    return 0;
}
