#include <stdio.h>

int main()
{
    int sumTime = 0;
    int currFloor = 0;
    int prevFloor = 0;
    int N;
    int i = 0;

    scanf("%d", &N);
    while(i<N) {
        scanf("%d", &currFloor);
        if(currFloor>prevFloor) {
            sumTime += (currFloor - prevFloor)*6;
        } else {
            sumTime += (prevFloor - currFloor)*4;
        }
        sumTime += 5;
        prevFloor = currFloor;
        i++;
    }

    printf("%d", sumTime);
    return 0;
}

