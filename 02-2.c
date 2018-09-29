#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int order;
    struct Node *next;
};

typedef struct Node *Term;
typedef Term Poly;

Poly createPoly()
{
    Poly p = (Poly)malloc(sizeof(struct Node));
    p->coeff = 0;
    p->order = 0;
    p->next = NULL;
    return p;
}

void destroyPoly(Poly p)
{
    Term term;
    while(p) {
        term = p->next;
        free(p);
        p = term;
    }
}

void appendTerm(Poly p, int coeff, int order)
{
    Term term = p;

    if(term) {
        while(term->next){
            term = term->next;
        }
        term->next = (Term)malloc(sizeof(struct Node));
        term->next->coeff = coeff;
        term->next->order = order;
        term->next->next = NULL;
    }
}

void addPoly(Poly p1, Poly p2, Poly pSum)
{
    Term temp;

    if(!p1 || !p2) { 
        return;
    }

    while(p1->next && p2->next){
        if(p1->next->order > p2->next->order) {
            appendTerm(pSum, p1->next->coeff, p1->next->order); 
            p1 = p1->next;
        } else if (p1->next->order < p2->next->order) {
            appendTerm(pSum, p2->next->coeff, p2->next->order);
            p2 = p2->next;
        } else {
            appendTerm(pSum, p1->next->coeff + p2->next->coeff, p1->next->order);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    temp = p1->next ? p1->next : p2->next;

    while(temp) {
        appendTerm(pSum, temp->coeff, temp->order);
        temp = temp->next;
    }
}

void multiPoly(Poly p1, Poly p2, Poly pMulti)
{
    Poly term, poly, multi, sum;
    if(!(p1&&p2)) {
        return;
    }
    
    while(p1->next) {
        term = p1->next;
        poly = p2;
        //sum = pMulti;
        multi = createPoly();
        while(poly->next) {
            appendPoly(multi, poly->next->coeff*term.coeff, poly->next->order*term.order);
            poly = ploy->next;
        }
        addPoly(pMulti, multi, )
    }

    if(temp)
}

void printPoly(Poly p)
{
    int entry = 1;
    if(!p) {
        return;
    }

    while(p->next) {
        if(!entry) {
            printf(" ");
        }
        entry = 0;
        printf("%d %d", p->next->coeff, p->next->order);
        p = p->next;
    }

    printf("\n");
}

int main()
{
    int N1, N2;
    int currCoeff, currOrder;
    
    Poly p1, p2, pSum, pMulti;
    p1 = createPoly();
    p2 = createPoly();
    pSum = createPoly();
    pMulti = createPoly();

    scanf("%d", &N1);
    while(N1){
        scanf("%d %d", &currCoeff, &currOrder);
        appendTerm(p1, currCoeff, currOrder);            
        N1--;
    }
    printPoly(p1);//
    scanf("%d", &N2);
    while(N2){
        scanf("%d %d", &currCoeff, &currOrder);
        appendTerm(p2, currCoeff, currOrder);            
        N2--;
    }
    printPoly(p2);//
    addPoly(p1, p2, pSum);
    printPoly(pSum);

    return 0;
}
