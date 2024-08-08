#include <iostream>
using namespace std;

int main() {
    int n,x1,x2,y1,y2,s[300][300]={0},of=100;
    int sum=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int p=x1+of;p<x2+of;p++){
            for(int q=y1+of;q<y2+of;q++){
                if(i%2==0){
                    s[p][q]=1;
                }
                else{
                    s[p][q]=2;
                } 
            }
        }
    }
    for(int p=x1+of;p<x2+of;p++){
        for(int q=y1+of;q<y2+of;q++){
            if(s[p][q]==2)
                sum++;
        }
    }
    cout << sum;
    return 0;
}