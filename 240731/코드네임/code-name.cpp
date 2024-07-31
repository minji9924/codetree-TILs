#include <iostream>
#include <string>
using namespace std;

class Codename{
    public:
        char code;
        int score;

    Codename(char code, int score){
        this->code = code;
        this->score = score;
    }
    Codename(){
    }
};

Codename codenames[5];

int main() {
    char c,tmp_c;
    int s,tmp_s=101;
    for(int i=0;i<5;i++){
        cin >> c >> s;
        codenames[i] = Codename(c,s);
        if(tmp_s > codenames[i].score){
            tmp_c = codenames[i].code;
            tmp_s = codenames[i].score;
        }
    }    
    cout << tmp_c << ' ' << tmp_s;

    return 0;
}