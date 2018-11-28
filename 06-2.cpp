#include <iostream>
#include <cmath>

using namespace std;

struct Point{
    double x;
    double y;
};

int N;
double D;
double r = 15.0;
Point data[105];
int visited[105];

double distance(Point p1, Point p2)
{
    if(p1.x==0 && p1.y==0)
        return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y)) - r;
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

bool in_range(Point p)
{
    return (abs(p.x) >= 50-D) || (abs(p.y) >= 50-D);
}

bool DFS(Point p)
{
    if(in_range(p))
        return true;
    bool possible;
    for(int i=0; i<N; i++){
        if(!visited[i] && distance(p, data[i])<=D){
            visited[i] = 1;
            possible = DFS(data[i]);
            if(possible) return true;
        }
    }

    return false;
}

int main()
{
    cin >> N >> D;

    for(int i=0; i<N; i++){
        Point p;
        cin >> p.x >> p.y;
        data[i] = p;
    }

    Point origin;
    origin.x = 0;
    origin.y = 0;
    bool possible = DFS(origin);

    if(possible)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
