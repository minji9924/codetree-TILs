#include <iostream>
using namespace std;

int main() {
    int n,m,t,a[2000002]={0},b[2000002]={0},loc=0,flag=0,ans=-1,tmp_a=0,tmp_b=0;
    char d;
    cin >> n >> m;
    int time=0;
    for(int i=0;i<n;i++){
        cin >> d >> t;
        int tmp=0;
        if(d=='L'){
            while(tmp!=t){
                tmp++;
                //a[--loc]=(time++);
                a[++time]=(--loc);
                //cout <<"time: " << time <<  " a[loc]: " << loc << '\n';
            }
        }
        else if(d=='R'){
            while(tmp!=t){
                tmp++;
                a[++time]=(++loc);
                //cout <<"time: " << time <<  " a[loc]: " << loc << '\n';
            }
        }
        
    }
    time=0;
    loc=0;
    for(int i=0;i<m;i++){
        cin >> d >> t;
        int tmp=0;
        if(d=='L'){
            while(tmp!=t){
                tmp++;
                b[++time]=(--loc);
                //cout << "time: " << time << " b[loc]: " <<loc << '\n';
                if(b[time]==a[time]){
                    flag=1;
                    ans=time;
                    break;
                }
            }
        }
        else if(d=='R'){
            while(tmp!=t){
                tmp++;
                b[++time]=(++loc);
                //cout << "time: " << time << " b[loc]: " <<loc << '\n';
                if(b[time]==a[time]){
                    flag=1;
                    ans=time;
                    break;
                }
            }
        }
        if(flag)
            break;
        
    }
    cout << ans;
    return 0;
}