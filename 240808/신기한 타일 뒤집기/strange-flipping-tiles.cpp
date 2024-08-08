#include <iostream>
using namespace std;

int main() {
    int n,x,loc=100000,sum_w=0,sum_b=0;
    int t[1000000]={0};
    cin >> n;
    char d;
    for(int i=0;i<n;i++){
        cin >> x >> d;
        int mov=0;
        if(d=='R'){
            while(mov!=x){
                t[loc++]=2;
                mov++;
            }
            loc--;
        }
        else if(d=='L'){
            loc++;
            while(mov!=x){
                t[--loc]=1;
                mov++;
            }
        }
    }
    int i=0;
    while(i<1000000){
        if(t[i]==1)
            sum_w++;
        else if(t[i]==2)
            sum_b++;
        i++;
    }
    cout << sum_w <<' '<< sum_b;

    return 0;
}