#include <iostream>
#include <algorithm>
using namespace std;

class P{
    public:
        int x,y,n;
    P(int x,int y,int n){
        this->x = x;
        this->y=y;
        this->n=n;
    }
    P(){}
};

P p[1000];

bool cmp(P p1, P p2){
    if(p1.x+p1.y != p2.x+p2.y)
        return p1.x+p1.y < p2.x+p2.y;
}

int main() {
    int n,x,y;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        p[i] = P(x,y,i+1);
    }
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++){
        cout << p[i].n << '\n';
    }
    return 0;
}