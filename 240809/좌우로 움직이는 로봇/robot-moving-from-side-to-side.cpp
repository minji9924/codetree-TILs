#include <iostream>
using namespace std;

int main() {
    int n,m,t,time_a=0,time_b=0,ofst=1000000,loc=0;
    char d;
    int pos_a[2000002]={0},pos_b[2000002]={0};
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> t >> d;
        if(d=='L'){
            while(t--){
                pos_a[++(time_a)] = --loc;
            }
        }
        else if(d=='R'){
            while(t--){
                pos_a[ ++(time_a)] = ++loc;
            }
        }
    }
    loc=0;
    for(int i=0;i<m;i++){
        cin >> t >> d;
        if(d=='L'){
            while(t--){
                pos_b[++(time_b)] = --loc;
            }
        }
        else if(d=='R'){
            while(t--){
                pos_b[++(time_b)] = ++loc;
            }
        }
    }
    int time=max(time_a,time_b);
    int tmp=0;
    //cout << "time: " << time_a << ' ' << time_b << ' ' << time << '\n';
    //cout << time << '\n';
    if(time_a>time_b){
        tmp = time-time_b;
        while(tmp--){
            time_b++;
            pos_b[(time_b)] = pos_b[(time_b)-1];
        }
    }
    else if(time_a<time_b){
        tmp = time-time_a;
        while(tmp--){
            time_a++;
            pos_a[(time_a)] = pos_a[(time_a)-1];
        }
    }
    int cnt=0;

    for(int i=1;i<time;i++){
        //cout << "pos_a[" << i << "]: " << pos_a[i] << ' ' << "pos_b[" << i << "]: " << pos_b[i] << '\n';
        if((pos_a[i]==pos_b[i]) && (pos_a[i-1] != pos_b[i-1])){
            //cout << "pos_a[" << i << "]: " << pos_a[i] << ' ' << "pos_b[" << i << "]: " << pos_b[i] << '\n';
            //cout << i << '\n';
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}