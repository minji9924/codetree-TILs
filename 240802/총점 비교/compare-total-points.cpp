#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class St{
    public:
        string nm;
        int k,e,m;

        St(string nm, int k, int e, int m){
            this->nm = nm;
            this->k = k;
            this->e = e;
            this->m = m;
        }
        St(){
        }
};
St st[10];
bool cmp(St st1, St st2){
    if((st1.k+st1.e+st1.m) > (st2.k+st2.e+st2.m))
        return false;
    return true;
}
int main() {
    int n,k,e,m;
    string nm;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> nm >> k >> e >> m;
        st[i] = St(nm,k,e,m);
    }
    sort(st,st+n,cmp);
    for(int i=0;i<n;i++){
        cout << st[i].nm << ' ' << st[i].k << ' ' << st[i].e << ' ' << st[i].m << '\n';
    }
    return 0;
}