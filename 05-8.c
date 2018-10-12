#include <stdio.h>
#define MAX_SIZE 10000
int set[MAX_SIZE+1];

int setFind(int x)
{
    if(set[x]<0)
        return x;
    else
        set[x] = setFind(set[x]);

    return set[x]; 
}

void unionSet()
{
    int c1, c2;
    int root1, root2;
    scanf("%d%d\n", &c1, &c2);
    root1 = setFind(c1);
    root2 = setFind(c2);

    if(root1!=root2){
        if(set[root1] == set[root2]) {
            set[root1]--;
            set[root2] = root1;
        } else if(set[root1] < set[root2]) {
            set[root2] = root1;
        } else {
            set[root1] = root2;
        }
    }
}

void checkSet()
{
    int c1, c2;
    int root1, root2;
    scanf("%d%d\n", &c1, &c2);
    root1 = setFind(c1);
    root2 = setFind(c2);

    if(root1!=root2){
        printf("no\n");
    } else {
        printf("yes\n");
    }
}

void printSet(int N)
{
    int count = 0;
    while(N--) {
        if(set[N+1]<0) count++;
    }

    if(count>1) {
        printf("There are %d components.\n", count);
    } else {
        printf("The network is connected.\n");
    }
}


int main()
{
    int N, i;
    char ins = '0';

    scanf("%d\n", &N);
    
    for(i=1; i<=N; i++)
        set[i] = -1;

    while(ins!='S') {
        scanf("%c", &ins);
        switch(ins) {
            case 'C':
                checkSet();
                break;
            case 'I':
                unionSet();
                break;
            case 'S':
                printSet(N);
                break;
        }
    }

    return 0;
}

