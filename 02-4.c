#include <stdio.h>

int main()
{
    int M, N, K;
    int buf[1005];
    int state[1005];
    int stack[1005];
    int top = 0;
    int i, j, number;
    int possible;

    scanf("%d%d%d", &M, &N, &K);
    
    while(K--){
        possile = 1;
        for(i=0; i<N; i++) {
            scanf("%d", &buf[i]);
            state[buf[i]] = 0;
        }

        top = 0;
        for(i=0; i<N; i++) {
            number = buf[i];

            if(number<buf[i-1] && number!=stack[top-1]) {
                possible = 0; break;
            }

            for(j=number; j>0 && !state[number-j+1]; j--) {
                stack[top++] = number-j+1;
                state[number] = 1;

                if(top>M) {
                    possile = 0;
                }
            }
            top--;
        }

        if(possible) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}
