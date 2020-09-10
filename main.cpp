#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
using namespace std;
const int maxn=100000;
struct book{
    string id;//书号
    string name;//书名
    string author;//作者
    int remain;//现存
    int stock;//库存
};

struct student{
    string id;//借书证号
    int num=0;//借书数量
};

struct info{
    string id;//书号
    int year,month,day;//归还日期
};

vector<book>BookSystem;//按书号排序
vector<student>StudentSystem;//按借书证号排序
vector<string>NameToId[maxn],AuthorToId[maxn];
vector<info>StudentToId[maxn];
int id1=1,id2=1,id3=1;
map<string,int>Name,Author,Student;
int BinSearch(string s,int *ans){//二分查找
    int l=0,r=BookSystem.size()-1;
    *ans=-1;
    while(l<=r){
        int mid=l+r>>1;
        if(s>BookSystem[mid].id) l=mid+1;
        else if(s<BookSystem[mid].id) r=mid-1;
        else *ans=mid,r=mid-1;
    }
    return l;
}

int BinSearchStudent(string s,int *ans){//二分查找
    int l=0,r=StudentSystem.size()-1;
    *ans=-1;
    while(l<=r){
        int mid=l+r>>1;
        if(s>StudentSystem[mid].id) l=mid+1;
        else if(s<StudentSystem[mid].id) r=mid-1;
        else *ans=mid,r=mid-1;
    }
    return l;
}

void SearchId(string s){//按书号查找
    int pos;
    BinSearch(s,&pos);
    if(pos==-1){
        cout<<"未找到！\n";
        return;
    }
    book Book=BookSystem[pos];
    cout<<"----------书籍信息----------"<<"\n"
        <<"查找的书号为："<<Book.id<<"\n"<<"查找的书名为："<<Book.name<<"\n"<<"查找的书的作者为："<<Book.author<<"\n"<<
        "查找的书的现存为："<<Book.remain<<"\n"<<"查找的书的库存为："<<Book.stock<<"\n";
}


void SearchName(string s){//按书名查找
    if(NameToId[Name[s]].size()==0){
        cout<<"未找到！\n";
        return;
    }
    for(auto i:NameToId[Name[s]]){
        int pos;
        BinSearch(i,&pos);
        book Book = BookSystem[pos];
        cout<<"----------书籍信息----------"<<"\n"
            <<"查找的书号为："<<Book.id<<"\n"<<"查找的书名为："<<Book.name<<"\n"<<"查找的书的作者为："<<Book.author<<"\n"<<
            "查找的书的现存为："<<Book.remain<<"\n"<<"查找的书的库存为："<<Book.stock<<"\n";
    }
}

void SearchAuthor(string s){//按作者查找
    if(AuthorToId[Author[s]].size()==0){
        cout<<"未找到！\n";
        return;
    }
    for(auto i:AuthorToId[Author[s]]){
        int pos;
        BinSearch(i,&pos);
        book Book = BookSystem[pos];
        cout<<"----------书籍信息----------"<<"\n"
            <<"查找的书号为："<<Book.id<<"\n"<<"查找的书名为："<<Book.name<<"\n"<<"查找的书的作者为："<<Book.author<<"\n"<<
            "查找的书的现存为："<<Book.remain<<"\n"<<"查找的书的库存为："<<Book.stock<<"\n";
    }
}

void Push(book Book){//入库
    if(Book.remain != Book.stock){
        cout<<"输入有误，现存应该与库存相同！\n";
        return;
    }
    if(Book.remain<0||Book.stock<0){
        cout<<"输入有误，现存或库存数量应大于0！\n";
    }
    int pos,ans;
    pos=BinSearch(Book.id,&ans);
    if(ans!=-1){
        BookSystem[pos].stock+=Book.stock;
        BookSystem[pos].remain+=Book.remain;
    }else{
        BookSystem.insert(BookSystem.begin()+pos,Book);
    }
}


int Borrow(string id){//借阅
    int pos;
    BinSearch(id,&pos);
    if(pos==-1){
        cout<<"查找失败，书库无此书！\n";
        return 0;
    }
    if(BookSystem[pos].remain==0){
        cout<<"此书无库存！\n";
        return 0;
    }
    BookSystem[pos].remain--;
    return 1;
}

bool judgeYear(int y){//判断是否为闰年
    if(y%400 == 0||(y%4==0&&y%100)){
        return 1;
    }
    return 0;
}

bool judgeDate(int y,int m,int d){//判断日期格式是否正确
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
        if(d>=1&&d<=31){
            return 1;
        }else{
            return 0;
        }
    }
    else if(m==4||m==6||m==9||m==11){
        if(d>=1&&d<=30){
            return 1;
        }else{
            return 0;
        }
    }
    else if(m==2){
        if(judgeYear(y)&&(d>=1&&d<=29)){
            return 1;
        }else if(!judgeYear(y)&&(d>=1&&d<=28)){
            return 1;
        }else {
            return 0;
        }
    }
    return 0;
}

void Return(string id,string ss,int y,int m,int d){//归还
    int pos,p,flag=0;
    BinSearch(id,&pos);
    student stu;
    BinSearchStudent(ss,&p);
    if(pos==-1){
        cout<<"查找失败，书库无此书！\n";
        return;
    }
    if(BookSystem[pos].remain == BookSystem[pos].stock){
        cout<<"库存已满，无法还书！\n";
        return;
    }
    if(p == -1){
        cout<<"无借阅记录，还书失败！\n";
        return;
    }
    if(!judgeDate(y,m,d)){
        cout<<"您输入的日期有误！\n";
        return;
    }
    for(int i=0;i<StudentToId[Student[StudentSystem[p].id]].size();i++){
        if(id == StudentToId[Student[StudentSystem[p].id]][i].id){
            if(StudentToId[Student[StudentSystem[p].id]][i].day<d||StudentToId[Student[StudentSystem[p].id]][i].month<m
               ||StudentToId[Student[StudentSystem[p].id]][i].year<y){
                cout<<"您已超出归还日期，请与前台联系！\n";
                return;
            }
            StudentToId[Student[StudentSystem[p].id]].erase(StudentToId[Student[StudentSystem[pos].id]].begin()+1);
            flag = 1;
            break;
        }
    }

    if(flag){
        BookSystem[pos].remain++;
        cout<<"归还成功！\n";
        StudentSystem[p].num--;
        if(StudentSystem[p].num == 0){
            StudentSystem.erase(StudentSystem.begin()+p);
        }
    }else{
        cout<<"无借此书的记录！\n";
    }
    return;
}


void InsertStudent(string s,string id,int y,int m,int d){//学生信息录入
    if(!judgeDate(y,m,d)){
        cout<<"输入的日期有误!\n";
        int p;
        BinSearch(id,&p);
        BookSystem[p].remain++;
        return;
    }

    int pos,ans;
    pos=BinSearchStudent(s,&ans);
    student stu;
    stu.num++;
    if(ans==-1)
    {
        stu.id=s;
        StudentSystem.insert(StudentSystem.begin()+pos,stu);

    }

    if(Student[s]==0) Student[s]=id3++;
    StudentToId[Student[s]].push_back({id,y,m,d});
    cout<<"借书成功！\n";
}

void SearchStudentInfo(string s){//寻找并输出借书证号对应的借书信息
    if(StudentToId[Student[s]].size()==0){
        cout<<"未找到此学生！"<<endl;
        return;
    }
    cout<<"学生借阅的图书为：\n";
    for(auto i:StudentToId[Student[s]]){
        SearchId(i.id);

        cout<<"书本的归还日期为："<<i.year<<"年"<<i.month<<"月"<<i.day<<"日"<<endl;
    }
}

void Print(){
    cout<<"----------所有库存信息----------"<<"\n";
    for(auto Book:BookSystem){
        cout<<"----------书籍信息----------"<<"\n"
        <<"书号："<<Book.id<<"\n"<<"书名："<<Book.name<<"\n"<<"书的作者："<<Book.author<<"\n"<<
        "书的现存："<<Book.remain<<"\n"<<"书的库存："<<Book.stock<<"\n";
    }
}

void DepositBookInfo(){
    ofstream fout("Booksystem.txt");
    for(auto Book:BookSystem){
        fout<<"书号为："<<Book.id<<"\n"<<"书名为："<<Book.name<<"\n"<<"书的作者为："<<Book.author<<"\n"<<
            "书的现存为："<<Book.remain<<"\n"<<"书的库存为："<<Book.stock<<"\n";
    }
    cout<<"写入成功！\n";
}

void DepositStudentInfo(){
    ofstream fout("Studentsystem.txt");
    for(auto stu:StudentSystem){
        fout<<"学生证号为：\n"<<stu.id<<"\n学生共借书："<<stu.num<<"本\n";
        cout<<stu.num<<endl;
        for(auto info:StudentToId[Student[stu.id]]){
            int pos;
            BinSearch(info.id,&pos);
            book Book=BookSystem[pos];
            fout<<"书号为："<<Book.id<<"\n"<<"书名为："<<Book.name<<"\n"<<"书的作者为："<<Book.author<<"\n"<<
                "书的现存为："<<Book.remain<<"\n"<<"书的库存为："<<Book.stock<<"\n";
        }
    }
    cout<<"写入成功！\n";
}

int main() {
    int n,y,m,d,flag=0;
    char pick;
    book b;
    string s,ss;
    while(true){
        cout<<"\n----------欢迎使用图书管理系统----------\n";
        //进入系统后显示界面
        cout<<"0、采编入库\n";
        cout<<"1、通过书号查询\n";
        cout<<"2、通过书名查询\n";
        cout<<"3、通过作者查询\n";
        cout<<"4、图书借阅\n";
        cout<<"5、图书归还\n";
        cout<<"6、查询已借图书信息\n";
        cout<<"7、输出所有库存信息\n";
        cout<<"8、将图书信息库写入Booksystem.txt：\n";
        cout<<"9、将学生信息库写入Studentsystem.txt\n";
        cout<<"e、退出\n";
        cout<<"请输入您要实现的功能：\n";
        cin>>pick;
        switch (pick) {
            case '0'://采编入库
                cout<<"请输入需要入库的书的数量:\n";
                cin>>n;
                cout<<"请输入需要入库的书的信息：\n";
                while(n--){
                    cin>>b.id>>b.name>>b.author>>b.remain>>b.stock;
                    //cout<<b.name<<"\n";
                    if(Name[b.name]==0) Name[b.name]=id1++;
                    if(Author[b.author]==0) Author[b.author]=id2++;
                    NameToId[Name[b.name]].emplace_back(b.id);
                    AuthorToId[Author[b.author]].emplace_back(b.id);
                    Push(b);

                }
                cout<<"入库完毕！"<<endl;
                break;
            case '1'://通过书号查询
                cout<<"请输入需要查询的书号：";
                cin>>s;
                SearchId(s);
                break;
            case '2'://通过书名查询
                cout<<"请输入书名：";
                cin>>s;
                SearchName(s);
                break;
            case '3'://通过作者查询
                cout<<"请输入作者：";
                cin>>s;
                SearchAuthor(s);
                break;
            case '4'://图书借阅
                cout<<"请输入需要借阅的书：";
                cin>>s;
                flag = Borrow(s);
                if(flag){
                    cout<<"\n请输入借书证号：";
                    cin>>ss;
                    cout<<"请输入归还日期（年 月 日）";
                    cin>>y>>m>>d;
                    InsertStudent(ss,s,y,m,d);
                }
                break;
            case '5'://图书归还
                cout<<"请输入需要归还的书：";
                cin>>s;
                cout<<"请输入借书证号：";
                cin>>ss;
                cout<<"请输入当前的日期（年 月 日）：";
                cin>>y>>m>>d;
                Return(s,ss,y,m,d);
                break;
            case '6'://查询已借图书信息
                cout<<"需要查询的借书证号：";
                cin>>s;
                SearchStudentInfo(s);
                break;
            case '7'://输出所有库存信息
                Print();
                break;
            case '8'://将图书信息库写入Booksystem.txt：
                DepositBookInfo();
                break;
            case '9'://将学生信息库写入Studentsystem.txt
                DepositStudentInfo();
                break;
            case 'e':
                cout<<"谢谢使用\n";
                return 0;
            default:
                cout<<"您输入的选择有误，请重新选择！\n";
                break;
        }

    }

}

/*
10
1 平凡的世界 路遥 200 200
2 八十天环游世界 儒勒凡尔纳 200 200
3 不平凡的世界 路遥 200 200
4 我的青春恋爱喜剧果然有问题1 渡航 300 300
5 我的青春恋爱喜剧果然有问题2 渡航 300 300
6 我的青春恋爱喜剧果然有问题3 渡航 200 200
7 我的青春恋爱喜剧果然有问题4 渡航 300 300
8 C++程序设计 谭浩强 600 600
9 平凡的世界 龙 200 200
2 八十天环游世界 儒勒凡尔纳 200 200
 * */