#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class St{
    public:
        int ht;
        double wt;
        string nm;
        St(string nm,int ht,double wt){
            this->nm = nm;
            this->ht = ht;
            this->wt = wt;
        }
        St(){
        }
};
St st[5];
bool cmp1(St st1, St st2){
    if(st1.nm != st2.nm)
        return st1.nm < st2.nm;
}
bool cmp2(St st1, St st2){
    if(st1.ht != st2.ht)
        return st1.ht > st2.ht;
}
int main() {
    int ht;
    double wt;
    string nm;
    for(int i=0;i<5;i++){
        cin >> nm >> ht >> wt;
        st[i] = St(nm,ht,wt);
    }
    sort(st,st+5,cmp1);
    cout << "name" << "\n";
    for(int i=0;i<5;i++){
        cout << st[i].nm << ' '<< st[i].ht << ' ' << st[i].wt << ' ' << '\n';
    }
    cout << "\n";
    sort(st,st+5,cmp2);
    cout << "height" << "\n";
    for(int i=0;i<5;i++){
        cout << st[i].nm << ' '<< st[i].ht << ' ' << st[i].wt << ' ' << '\n';
    }
    return 0;
}