#include <iostream>
#include <string>
using namespace std;

class Bomb{
    public:
        string code;
        char line;
        int time;
    Bomb(string code, char line, int time){
        this->code = code;
        this->line = line;
        this->time = time;
    }
};

int main() {
    string s;
    char c;
    int t;
    cin >> s >> c >> t;
    Bomb bomb1 = Bomb(s,c,t);
    cout << "code : " << bomb1.code << "\n";
    cout << "color : " << bomb1.line << "\n";
    cout << "second : " << bomb1.time;
    return 0;
}