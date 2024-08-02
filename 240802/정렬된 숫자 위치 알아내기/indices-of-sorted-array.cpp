#include <iostream>
#include <algorithm>
using namespace std;

class Seq{
    public:
        int k,t;
    Seq(int k,int t){
        this->k=k;
        this->t=t;
    }
    Seq(){}
};

Seq seq1[1001];
Seq seq2[1001];
int cnt[1001];
bool cmp(Seq sq1, Seq sq2){
    if(sq1.k != sq2.k)
        return sq1.k < sq2.k;
    return sq1.t < sq2.t;
}

int main() {
    int n,k;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> k;
        seq1[i] = Seq(k,0);
        seq2[i] = Seq(k,0);
        cnt[i]=0;
    }
    sort(seq2,seq2+n,cmp);
    for(int i=0;i<n;i++){
        seq2[i].t = i+1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((seq1[i].k == seq2[j].k) && !cnt[seq2[j].t]){
                seq1[i].t = seq2[j].t;
                cnt[seq2[j].t]=1;
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << seq1[i].t << ' ';
    }

    return 0;
}