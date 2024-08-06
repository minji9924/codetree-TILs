#include <iostream>
using namespace std;

int main() {
    int n,x,loc=0,offset=1000;
    int p[10000] = {0};
    char D;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> D;
        int mov=0;
        if(D == 'L'){
            while(mov!=x){
                mov++;
                p[(loc++)+offset]++;
            }
        }
        else if(D == 'R'){
            while(mov!=x){
                mov++;
                p[(--loc)+offset]++;
            }
        }
    }
    int sum=0;
    for(int i=0;i<2000;i++){
        if(p[i]>=2)
            sum++;
    }
    cout << sum;
    return 0;
}