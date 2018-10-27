#include <iostream>
#include <set>

using namespace std;

int trans(int x)
{
    multiset<int, greater<int> > large;
    multiset<int> small;

    int count = 0;
    while(x) {
        large.insert(x%10);
        small.insert(x%10);
        x /= 10;
        count++;
    }

    for(;count<4;count++) {
        large.insert(0);
        small.insert(0);
    }

    int large_value = 0;
    for(auto y : large) {
        large_value *= 10;
        large_value += y;
    }

    int small_value = 0;
    for(auto y : small) {
        small_value *= 10;
        small_value += y;
    }

    printf("%04d - %04d = %04d\n", 
            large_value, 
            small_value, 
            large_value - small_value);

    return large_value - small_value;
}

int main()
{
    int N;
    cin>>N;
    int Kaprekar = 6174;

    int result;
    while((result = trans(N)) && result!=Kaprekar)
        N = result;

    return 0;
}
