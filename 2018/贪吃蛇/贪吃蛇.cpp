#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cstring>
#include <cstdio>
#include <iostream>
#define N 22
using namespace std;

	int gameover;
	
	int x1,y1;//�������

	int x,y;

	long start; 
//========================
//���ʵ����Ӧ��initialize
//========================

//���涨��̰���ߵ�������
class snake_position{
	public:
		
		int x,y;//x��ʾ�У�y��ʾ�� 
		
		snake_position(){};
		
		void initialize(int &);//�����ʼ�� 
}; 

snake_position position[(N-2)*(N-2)+1];//����̰�������������飬��(N-2)*(N-2)������

void snake_position::initialize(int &j){
	x = 1;
	
	y = j;
}  

//���涨��̰���ߵ�����ͼ

class snake_map{
	private:
		
		char s[N][N];//����̰�������̣�����ǽ�ڡ�
		
		int grade,length;
		
		int gamespeed;//ǰ��ʱ����
		
		char direction;//��ʼ����£������˶�
		
		int head,tail;
		
		int score;
		
		bool gameauto;
		
	public:
	
		snake_map(int h=4,int t=1,int l=4,char d=77,int s=0):length(l),direction(d),head(h),tail(t),score(s){}
		//d=77 Ĭ������ 
		
		void initialize(); //��ʼ������
		
		void show_game();
		
		int update_game();
		
		void setpoint();
		
		void getgrade();
		
		void display(); 
}; 

//�����ʼ����������̰���ߵ�����ͼ���г�ʼ��

void snake_map::initialize(){
	
	for(int i=1;i<=3;i++)
		s[1][i]='*';
		
	s[1][4]='#';
	
	for(int i=1;i<=N-2;i++)
		for(int j=1;j<=N-2;j++)
			s[i][j]=' ';//��ʼ��̰���������м�հײ���
			
	for(int i=0;i<=N-1;i++)
		s[0][i] = s[N-1][i] = '-'; //��ʼ��̰������������ǽ�� 
		
	for(int i=1;i<=N-2;i++)
		s[i][0] = s[i][N-1] = '|'; //��ʼ��̰������������ǽ�� 
} 

void snake_map::show_game(){
	system("cls"); //����
	
	cout<<endl;
	
	for(int i=0;i<N;i++){
		
		cout<<'\t';
		
		for(int j=0;j<N;j++)
			cout<<s[i][j]<<' '; //���̰��������
			
		if(i==2) cout<< "\t�ȼ���" <<grade;
		
		if(i==6) cout<< "\t�ٶȣ�" <<gamespeed;
		
		if(i==10) cout<<"\t�÷֣�" <<score << "��";
		
		if(i==14) cout<<"\t��ͣ����һ�¿ո��";
		
		if(i==18) cout<<"\t�����������¿ո��";
		
		cout<<endl; 
	}
} 

//����ѡ��ȼ�
void snake_map::getgrade(){
	
	cin>>grade;
	
	while( grade>7 || grade<1 ){
		cout << "����������1-7ѡ��ȼ�����������������Ч" <<endl;
		
		cin>>grade; 
	}
	
	switch(grade){
		
		case 1: gamespeed = 120; gameauto = 0; break;
		
		case 2: gamespeed = 100; gameauto = 0; break;
		
		case 3: gamespeed = 80; gameauto = 0; break;
		
		case 4: gamespeed = 60; gameauto = 0; break;
		
		case 5: gamespeed = 40; gameauto = 0; break;
		
		case 6: gamespeed = 20; gameauto = 0; break;
		
		case 7: grade = 1; gamespeed = 1000; gameauto = 1; break;
	}
}

//����ȼ����÷�����Լ��ƺ�

void snake_map::display(){
	
	cout<< "\n\t\t\t\t�ȼ���" <<grade;
	
	cout<< "\n\n\n\t\t\t\t�ٶȣ�"<<gamespeed;
	
	cout<< "\n\n\n\t\t\t\t�÷֣�"<<score <<"��"; 
} 

//������� �ף�
void snake_map::setpoint(){
	
	srand(time(0));
	
	do{
		x1 = rand() % (N-2) + 1;
		
		y1 = rand() % (N-2) + 1;
		
	}while(s[x1][y1]!=' ');
	
	s[x1][y1]='*';
} 

char key,lastkey=75;//Ĭ�����ҳ��� 

int snake_map::update_game(){
	
	gameover = 1;
	
	key = direction;lastkey = key;
		if(key==72) lastkey=80;
		else if(key==80) lastkey=72;
		else if(key==75) lastkey=77;
		else if(key==77) lastkey=75;

	start = clock();
	
	while((gameover=(clock()-start<=gamespeed))&&!kbhit()); //kbhit - ������������ 
	//����м����»�ʱ�䳬���Զ�ǰ��ʱ��������ֹѭ��
	
	
		if(gameover){
			
			getch();
			key=getch();
		} 
		
			if(key==lastkey){
				if(lastkey==72) key=80;
				else if(lastkey==80) key=72;
				else if(lastkey==75) key=77;
				else if(lastkey==77) key=75;
			}
			
			
		
		if(key == ' ')
		{	
			while(getch()!=' '){};//����ʵ�ֵ��ǰ��ո���ͣ�����ո������ 
		}
		
		else
		
			direction = key;
			
			switch(direction){
				
				case 72: x = position[head].x-1; y = position[head].y; break; //'w'��
				
				case 80: x = position[head].x+1; y = position[head].y; break; //'s'��
				
				case 75: x = position[head].x; y = position[head].y-1; break; //'a'��
				
				case 77: x = position[head].x; y = position[head].y+1; //'d'��
			}
			
			if(x==0) x=N-2;
			else if (x==N-1) x=1;
			
			if(y==0) y=N-2;
			else if(y==N-1) y=1;
		
			
			if(!(direction==72||direction==80||direction==75||direction==77)) //�����Ƿ����
			
				gameover = 0;
			
			
			/*	
			else if(x==0 || x==N-1 || y==0 || y==N-1)//����ǽ�� 
			{
				gameover = 0;
				
			}
			*/
			
				
			else if(s[x][y]=='*'&&!(x==x1&&y==y1)) //��ͷ�������� 
			
				gameover = 0;
				
			else if(x==x1 && y==y1)
			{
				//���ף����ȼ�1
				
				length ++;
				if(length >=8 && gameauto)
				
				{
					length -= 8;
					
					grade++;
					
					if(gamespeed>=200)
						
						gamespeed = 200; //�ı�̰����ǰ���ٶ�
						
					else
					
						gamespeed = 100; 
				 } 
				 
				 s[x][y]= '#'; //������ͷ
				 
				 s[position[head].x][position[head].y] = '*'; //���׺�ԭ����ͷ��Ϊ����
				 
				 head = (head+1) % ( (N-2)*(N-2) ); //ȡ��ͷ����
				 
				 position[head].x = x;
				 
				 position[head].y = y;
				 
				 show_game();
				 
				 gameover = 1;
				 
				 score +=grade*20; //�ӷ�
				 
				 setpoint(); //������ 
				 
			}
			 
			 else
			 {//������ 
			 
			 	s[position[tail].x][position[tail].y]=' ';//����β�ÿ�
				 
				tail = (tail+1) % ( (N-2) * (N-2) );//������β����
				 
				s[position[head].x][position[head].y]='*';//����ͷ��Ϊ����
				
				head = (head+1) % ( (N-2) * (N-2) );
				
				position[head].x = x;
				
				position[head].y = y;
				
				s[position[head].x][position[head].y]='#';//������ͷ 
				
				gameover = 1;
			  } 
			  
	return gameover;

}


//====================
//����������
//====================

int main(){
	char ctn = 'y';
	
	int nodead;
	
	cout<<"\n\n\n\n\n\t\t\t ��ӭ����̰������Ϸ��"<<endl; //��ӭ����
	
	cout<<"\n\n\n\t\t\t ����������Ͽ�ʼ������"<<endl;//׼����ʼ
	
	getch();
	
	while(ctn=='y')
	{
		system("cls"); //����
		
		snake_map snake;
		
		snake.initialize();
		
		cout<<"\n\n����������ѡ����Ϸ�ȼ���" <<endl;
		
		cout<<"\n\n\n\t\t\t1.�ȼ�һ���ٶ� 120 \n\n\t\t\t2.�ȼ������ٶ� 100 \n\n\t\t\t3.�ȼ������ٶ� 80 ";
		
		cout<<"\n\n\t\t\t4.�ȼ��ģ��ٶ� 60 \n\n\t\t\t5.�ȼ��壺�ٶ� 40 \n\n\t\t\t6.�ȼ������ٶ� 20 \n\n\t\t\t7.�Զ�����ģʽ" <<endl;
		
		snake.getgrade();//��ȡ�ȼ� 
		
		for(int i=1;i<=4;i++){
			position[i].initialize(i);//��ʼ������ 
		} 
		
		snake.setpoint();//������һ����
		
		do
		{
			snake.show_game();
			
			nodead = snake.update_game();
		}while(nodead);
		
		system("cls"); //����
		
		
		cout<<"\n\n\n\t\t\t\tGameover! \n\n"<<endl;
		
		snake.display();//����ȼ�/�÷����
		
		cout<<"\n\n\n\t\t �Ƿ������Ϸ������ y ������n �˳�"<<endl;
		
		cin>>ctn; 
	 } 
	 
	 return 0;
} 
