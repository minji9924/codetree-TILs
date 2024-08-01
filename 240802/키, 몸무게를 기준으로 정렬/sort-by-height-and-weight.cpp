#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class St{
    public:
        int ht;
        int wt;
        string nm;
        St(string nm,int ht,int wt){
            this->nm = nm;
            this->ht = ht;
            this->wt = wt;
        }
        St(){
        }
};
St st[10];
bool cmp(St st1, St st2){
    if(st1.ht != st2.ht)
        return st1.ht < st2.ht;
    return st1.wt > st2.wt;
}
int main() {
    int n,ht,wt;
    string nm;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> nm >> ht >> wt;
        st[i] = St(nm,ht,wt);
    }
    sort(st,st+n,cmp);
    for(int i=0;i<n;i++){
        cout << st[i].nm << ' '<< st[i].ht << ' ' << st[i].wt << '\n';
    }
    return 0;
}