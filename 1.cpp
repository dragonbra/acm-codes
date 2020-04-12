/*
    124232018029 李奕岐
*/
#include <bits/stdc++.h>
using namespace std;

class Time{
    private:
        int hour, minute, sec;
    public:
        Time(int h, int m, int s) : hour(h), minute(m), sec(s) {}
        void output(){
            cout<<setw(4)<<hour<<':'<<minute<<':'<<sec<<endl;
        }
};

class Data{
    private:
        int year, month, day;
    public:
        Data(int y, int m, int d) : year(y), month(m), day(d) {}
        void output(Time &t){
            cout<<year<<'/'<<month<<'/'<<day<<endl;
            t.output();
        }
};

int main() {

    Data d(2020,4,12);
    Time t(15,30,59);
    d.output(t);

    return 0;
}
