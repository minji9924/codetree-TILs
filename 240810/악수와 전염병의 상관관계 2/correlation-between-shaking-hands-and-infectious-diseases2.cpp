#include <iostream>
using namespace std;

// N: N명의 개발자
// K: K번 악수 동안 전염
// P: 처음 전염병에 걸려 있는 개발자 번호
// T: T번에 걸쳐 t초에 x,y개발자가 악수 나눔
int main() {
    int N,K,T,P;
    int t,X,Y;
    int per[300]={0},cnt[300]={0},x[300]={0},y[300]={0},ck[300]={0};
    int dis=0;
    cin >> N >> K >> P >> T;
    per[P]=1;
    cnt[P]=K;
    for(int i=1;i<=T;i++){
        cin >> t >> X >> Y;
        x[t]=X;
        y[t]=Y;
    }
    for(int i=1;i<=250;i++){
        if(per[x[i]] && cnt[x[i]]>0){
            cnt[x[i]]--;
            if(!cnt[y[i]] && !per[y[i]])
                cnt[y[i]]=K;
            else
                cnt[y[i]]--;
            per[y[i]]=1;
        }
        else if(per[y[i]] && cnt[y[i]]>0){
            cnt[y[i]]--;
            if(!cnt[x[i]] && !per[x[i]])
                cnt[x[i]]=K;
            else
                cnt[x[i]]--;
            per[x[i]]=1;               
        }
    }
    for(int i=1;i<=N;i++){
        cout << per[i];
    }

    return 0;
}