#include <iostream>
#include <cstdio>

using namespace std;

int score[101];
int main()
{
    int N;
    cin >> N;

    int s;
    while(N--) {
        scanf("%d", &s);
        score[s]++;
    }

    int K;
    cin >> K;
    bool init = true;
    while(K--) {
        if(init)
            init = false;
        else
            printf(" ");
        scanf("%d", &s);
        printf("%d", score[s]);
    }

    cout << endl;
    return 0;
}
