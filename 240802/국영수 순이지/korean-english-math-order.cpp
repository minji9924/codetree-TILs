#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Student{
    public:
        string nm;
        int kor,eng,mt;
    Student(string nm, int kor, int eng, int mt){
        this->nm = nm;
        this->kor = kor;
        this->eng = eng;
        this->mt = mt;
    }
    Student(){}
};

Student students[10];
bool cmp1(Student st1, Student st2){
    if(st1.kor > st2.kor) // 국어
        return true;
    return false;
}
bool cmp2(Student st1, Student st2){
    if(st1.eng > st2.eng) // 영어
        return true;
    return false;
}

bool cmp3(Student st1, Student st2){
    if(st1.mt > st2.mt)// 수학
        return true;
    return false;
}

int main() {
    int n,skor,seng,smt;
    string snm;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> snm >> skor >> seng >> smt;
        students[i] = Student(snm,skor,seng,smt);
        
    }
    sort(students, students+n,cmp3);
    sort(students, students+n,cmp2);
    sort(students, students+n,cmp1);
    for(int i=0;i<n;i++){
        cout << students[i].nm << ' ' << students[i].kor << ' ' << students[i].eng << ' '<< students[i].mt << '\n';
    }
    return 0;
}