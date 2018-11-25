#include <iostream>

using namespace std;

struct Node{
    int x;
    struct Node* Next;
};

typedef struct Node* List;
typedef struct Node* Position;

void InsertNode(List L, int x)
{
    List node = (List)malloc(sizeof(Node));
    node->Next = L->Next;
    L->Next = node;
    node->x = x;
}

void FreeList(List L)
{
    List temp;
    while(L){
        temp = L;
        L = L->Next;
        free(temp);
    }
}

void PrintList(List L)
{
    L = L->Next;
    while(L){;
        cout << L->x << '\t';
        L = L->Next;
    }
    cout << endl;
}

List ReverseList(List L)
{
    Position pCurr, pPrev, temp;
    pPrev = NULL;
    pCurr = L->Next;

    while(pCurr){
        temp = pCurr->Next;
        pCurr->Next = pPrev;
        pPrev = pCurr;
        pCurr = temp;
    }

    L->Next = pPrev;
    return L;
}

int main()
{
    List L = (List)malloc(sizeof(Node));
    
    for(int i=1; i<6; i++){
        InsertNode(L, i);
    }

    PrintList(L);
    ReverseList(L);
    PrintList(L);

    FreeList(L);
    return 0;
}
