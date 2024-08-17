#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
    int dist;
    int X;
    int Y;

    point(int d, int x, int y) : dist(d), X(x), Y(y) {}
};

struct cmp {
  bool operator()(point a, point b) {
    if (a.dist == b.dist) {
        if (a.X == b.X) return a.Y > b.Y;
        else return a.X > b.X;
    }

    return a.dist > b.dist;
  }
};

int N, M;
priority_queue<point, vector<point>, cmp> pq;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        pq.push(point(x+y, x, y));
    }

    for (int i = 0; i < M; i++) {
        point p = pq.top();
        pq.pop();
        pq.push(point(p.dist + 4, p.X + 2, p.Y + 2));
    }
    
    cout << pq.top().X << ' ' << pq.top().Y;
    
    return 0;
}