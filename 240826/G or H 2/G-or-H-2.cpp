#include <iostream>
using namespace std;
#define MAX_L 100

int main() {
    int n,mx=0,x,gcnt=0,hcnt=0;
    char person[MAX_L+1]={'0'},c;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> c;
        person[x]=c;
    }
    for(int i=0;i<MAX_L;i++){
        if(person[i]=='G')
            gcnt++;
        else if(person[i]=='H')
            hcnt++;
        for(int j=i+1;j<=MAX_L;j++){
            if((person[j]=='G' || person[j]=='H') && (person[i]=='G' || person[i]=='H')){
                if(person[j]=='G')
                    gcnt++;
                else if(person[j]=='H')
                    hcnt++;
                if(gcnt==hcnt && gcnt>=1)
                    mx=max(mx,j-i);
                if(person[i]==person[j] && (gcnt==0 || hcnt==0))
                    mx=max(mx,j-i);
                }
            }
        gcnt=0;
        hcnt=0;
    }

    cout << mx;
    return 0;
}