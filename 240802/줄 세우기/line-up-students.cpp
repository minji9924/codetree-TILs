#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class St{
    public:
        int ht,wt,nm;

        St(int ht,int wt,int nm){
            this->ht = ht;
            this->wt = wt;
            this->nm = nm;
        }
        St(){
        }
};
St st[1000];
bool cmp(St st1, St st2){
    if(st1.ht > st2.ht)
        return true;
    if(st1.wt > st2.wt)
        return true;
    if((st1.ht == st2.ht) && (st1.wt == st2.wt))
        return st1.nm < st2.nm;
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
        cout << st[i].ht << ' ' << st[i].wt << ' ' << st[i].nm << '\n';
    }
    return 0;
}