#include <iostream>
using namespace std;

int main() {
    int n,x,loc=0,ofst=100000;
    int t[1000000]={0};
    int ckw[1000000]={0};
    int ckb[1000000]={0};
    int sum_w=0,sum_b=0,sum_g=0;
    char d;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> d;
        int mov=0;
        if(d=='R'){
            while(mov!= x){
                ckb[loc+ofst]++;
                t[(loc++)+ofst]=1;
                mov++;
            }
        }
        else if(d=='L'){
            while(mov!=x){
                ckw[(--loc)+ofst]++;
                t[(loc)+ofst]=2;
                mov++;
            }
        }
    }
    int i=0;
    while(i<200020){
        if(ckb[i]>=2 && ckw[i]>=2){
            sum_g++;
            //cout << "ckb[i]: "<< ckb[i] << "  ckw[i]: "<< ckw[i] <<"  sum_g: "<<sum_g <<'\n';
            i++;
            continue;
        }
        if(t[i]==1){
            sum_b++;          
        }
        else if(t[i]==2){
            sum_w++;          
        }
        i++;
    }
    cout <<sum_w << ' ' << sum_b <<' '<< sum_g;

    return 0;
}