//编译环境：Visual C++ 6.0，EasyX_20190219(beta)
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
  
void pen()
 {
     int x0, y0;  
     MOUSEMSG m;        // 定义鼠标消息
     while (true)
     {
     flag:                //重置开始
         m = GetMouseMsg();// 获取一次鼠标消息
         switch (m.uMsg)

         {
         case WM_LBUTTONDOWN:x0 = m.x; y0 = m.y;    //鼠标第一次按下时，得到坐标（x0,y0）
             while (true)
             {
                 m = GetMouseMsg();// 获取一条鼠标消息
                 line(x0, y0, m.x, m.y);
                 x0 = m.x; y0 = m.y;
                 switch (m.uMsg)
                 {
                 case WM_LBUTTONUP:
                     goto flag;   //跳回到flag处进行重置
                     break;     
                 }
             }
             break;   
         }
     }
 } 
void main()
{        
    initgraph(640, 480); 
	setcolor(YELLOW);
    MOUSEMSG m;   
	while(true)
	   {pen();}
}

