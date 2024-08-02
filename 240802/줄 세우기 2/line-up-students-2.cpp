#include <iostream>
#include <algorithm>
using namespace std;

class St{
    public:
        int ht,wt,idx;
    St(int ht,int wt,int idx){
        this->ht = ht;
        this->wt = wt;
        this->idx = idx;
    }
    St(){}
};
St st[1000];
bool cmp(St st1, St st2){
    if(st1.ht != st2.ht)
        return st1.ht < st2.ht;
    return st1.wt > st2.wt;
}
int main() {
    int n,ht,wt;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> ht >> wt;
        st[i] = St(ht,wt,i+1);
    }
    sort(st,st+n,cmp);
    for(int i=0;i<n;i++){
        cout << st[i].ht << ' ' << st[i].wt << ' ' << st[i].idx << '\n';
    }

    return 0;
}