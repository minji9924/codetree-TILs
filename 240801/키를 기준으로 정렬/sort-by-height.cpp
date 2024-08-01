#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Score{
    public:
        string nm;
        int ht,wt;
    Score(string nm,int ht, int wt){
        this->nm = nm;
        this->ht = ht;
        this-> wt = wt;
    }
    Score(){}
};
Score scores[10];
bool cmp1(Score score1, Score score2){
    if(score1.ht < score2.ht)
        return true;
    return false;
}
int main() {
    int n,height,weight;
    string name;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> name >> height >> weight;
        scores[i] = Score(name,height,weight);
    }
    sort(scores, scores+n,cmp1);
    for(int i=0;i<n;i++){
        cout << scores[i].nm << ' ' << scores[i].ht << ' ' << scores[i].wt << '\n';
    }
    return 0;
}