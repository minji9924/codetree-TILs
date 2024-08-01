#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Rain{
    public:
        string yr,dy,wt;
    Rain(string yr,string dy, string wt){
        this->yr = yr;
        this->dy = dy;
        this->wt = wt;
    }
    Rain(){}
};
bool cmp1(Rain rain1,Rain rain2){
    if(rain1.wt < rain2.wt)
        return true;
    return false;
}
bool cmp2(Rain rain1,Rain rain2){
    if(rain1.yr < rain2.yr)
        return true;
    return false;
}

Rain rains[100];

int main() {
    int n,cnt=0;
    string year,day,weather;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> year >> day >> weather;
        rains[i] = Rain(year,day,weather);
        if(rains[i].wt == "Rain")
            cnt++;
    }
    sort(rains,rains+n,cmp1);
    sort(rains,rains+cnt,cmp2);
    cout << rains[0].yr << ' ' << rains[0].dy << ' ' <<rains[0].wt;
    return 0;
}