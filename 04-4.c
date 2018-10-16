#include <stdio.h>
#define MAX_SIZE 1024

struct Node{
    int x;
    int visited;
};

struct Node tree[MAX_SIZE];

void clear(int i)
{
    if(tree[i].x) {
        tree[i].visited = 0;
        clear(i*2);
        clear(i*2+1);
    }

    return;
}

void reset(int i)
{
    if(tree[i].x) {
        tree[i].x = 0;
        tree[i].visited = 0;
        clear(i*2);
        clear(i*2+1);
    }

    return;
}

void insert(int x)
{
    int i = 1;

    while(tree[i].x) {
        if(x<tree[i].x) {
            i = 2*i;
        } else if(x>tree[i].x) {
            i = 2*i + 1;
        } else {
            return;
        }
    }

    tree[i].x = x;
    return;
}

int compare(int x, int i)
{
    int result = 0;
    if(tree[i].visited) {
        if(x>tree[i].x) {
            result = compare(x, i*2 + 1);
        } else if(x<tree[i].x) {
            result = compare(x, i*2);
        } else {
            tree[i].visited = 1;
            result = 1;
        }
    }
    return result;
}

int main()
{
    int N, L;
    int i, j, x;
    int result;

    while(scanf("%d", &N) && N) {
        scanf("%d", &L);

        for(i=0; i<N; i++) {
            scanf("%d", &x);
            insert(x);
        }

        for(i=0; i<L; i++) {
            result = 0;
            scanf("%d", &x);
            if(x!=tree[1].x) {
                result = 0;
                for(j=1; j<N; j++) {
                    scanf("%d", &x);
                }
            } else {
                result = 1;
                tree[1].visited = 1;
                for(j=1; j<N; j++) {
                    scanf("%d", &x);
                    result = compare(x, 1);
                }
            }

            if(result) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }

            clear(1);
        }
        
        reset(1);
    }

    return 0;
}
