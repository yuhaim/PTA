#include <stdio.h>

char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
                 'A', 'B', 'C'};
void convert(int color, char *str)
{
    int i = 1;
    while(color){
        str[i--] = digits[color%13];
        color /= 13;
    }
}

int main()
{
    int r, g ,b;
    char rs[] = "00";
    char gs[] = "00";
    char bs[] = "00";
    scanf("%d %d %d", &r, &g, &b);
    
    convert(r, rs);
    convert(g, gs);
    convert(b, bs);

    printf("#%s%s%s\n", rs, gs, bs);
    
    return 0;
}

