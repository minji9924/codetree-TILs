#include <iostream>
using namespace std;

int main() {
    int r,c,str_r=0,str_c=0,sum=0,cnt=0;
    char chr[20][20];
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> chr[i][j];
        }
    }
    // for(int i=1;i<r-1;i++){
    //     for(int j=1;j<c-1;j++){
    //         if(chr[str_r][str_c] != chr[i][j] && i >= str_r+1 && j >= str_c+1)
    //     }
    // }
    for(int i=1;i<r-2;i++){
        for(int j=1;j<c-2;j++){
            if(chr[str_r][str_c] != chr[i][j]){
                    for(int p=i+1;p<r-1;p++){
                        for(int q=j+1;q<c-1;q++){
                            if(chr[i][j]!=chr[p][q]){
                                sum++;
                            }
                        }
                }
            }
        }
    }
    cout << sum;
    return 0;
}