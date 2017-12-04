#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
void move(int x,int y)
{
	HANDLE hout;
	COORD coord;	
	coord.X=x;
	coord.Y=y;	
	hout=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout,coord);
}//移动光标
class background
{
	int x;
	int y;
public:
	showback();
};//背景
background::showback()
{
	int i;
	int j;
	x=31;
	y=31;
	for(i=0;i<y;i++)
	{
		for(j=0;j<x;j++)
		{
			if(i==0)
				cout<<"┳";
			else if(i==y-1)
				cout<<"┻";
			else if(j==0)
				cout<<"┣";
			else if(j==x-1)
				cout<<"┫";
			else if(i%2==1&&j%2==1)
				cout<<"╬";
			else
				cout<<"╋";
		}
			cout<<"\n";
	}	
}//创建背景类函数
class spot
{

public:
	int cx;
	int cy;
	int state;
	//spot(int x=0,int y=0){cx=x;cy=y;};
	showspot();//显示移动
	showspotbk();//显示点
};//点类
spot::showspot()
{
	move(((cx-1)*2+1)*2,(cy-1)*2+1);
	if(state==0)
		cout<<"  ";
	else if(state==1)
		cout<<"⊙";
	else
		cout<<"◎";
}
spot::showspotbk()
{
	move(((cx-1)*2+1)*2,(cy-1)*2+1);
	if(state==0)
		cout<<"╬";
	else if(state==1)
		cout<<"○";
	else
		cout<<"●";
}
int main()
{
	CONSOLE_CURSOR_INFO cursor_info={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);//隐藏光标
	int t=1;
	background bg;
	bg.showback();
	spot st[15][15];
	register int i,j;
	for(i=1;i<=15;i++)
	{
		for(j=1;j<=15;j++)
		{
			st[i-1][j-1].cx=i;
			st[i-1][j-1].cy=j;
			st[i-1][j-1].state=0;
		}
	}
	i=7;
	j=7;
	st[i][j].showspot();
	char a;
	while(1)
	{
		if(t==1)
		{
			move(64,30);
			cout<<"黑棋回合";
		}
		else
		{
			move(64,30);
			cout<<"白棋回合";
		}
		a=getch();//wasd 方向键 数字键 操作
			if(a=='8'||a=='2'||a=='4'||a=='6'||a==72||a==80||a==75||a==77||a=='w'||a=='s'||a=='a'||a=='d')
			{
				st[i][j].showspotbk();
			/*	switch(a)
				{
				case 72:
				case 'w':
				case '8':j-=1;break;
				case 80:
				case 's':
				case '2':j+=1;break;
				case 75:
				case 'a':
				case '4':i-=1;break;
				case 77:
				case 'd':
				case '6':i+=1;break;
				}*/
				if((a==72||a=='w'||a=='8')&&j!=0)
				{
					j-=1;
				}

				if((a==80||a=='s'||a=='2')&&j!=14)
				{
					j+=1;
				}
				if((a==75||a=='a'||a=='4')&&i!=0)
				{
					i-=1;
				}	
				if((a==77||a=='d'||a=='6')&&i!=14)
				{
					i+=1;
				}
					st[i][j].showspot();
			}
			if((a==13||a==32)&&(st[i][j].state==0))//回车空格有效
			{
				st[i][j].state=t;
				if(t==1)
					t=2;
				else
					t=1;
				st[i][j].showspot();
			}
			register int i1,j1;
			for(i1=2;i1<13;i1++)
			{
				for(j1=2;j1<13;j1++)
				{
					if(st[i1][j1].state!=0&&((st[i1][j1].state==st[i1-1][j1].state&&st[i1][j1].state==st[i1-2][j1].state&&st[i1][j1].state==st[i1+1][j1].state&&st[i1][j1].state==st[i1+2][j1].state)||
					(st[i1][j1].state==st[i1][j1-1].state&&st[i1][j1].state==st[i1][j1-2].state&&st[i1][j1].state==st[i1][j1+1].state&&st[i1][j1].state==st[i1][j1+2].state)||
					(st[i1][j1].state==st[i1-1][j1-1].state&&st[i1][j1].state==st[i1-2][j1-2].state&&st[i1][j1].state==st[i1+1][j1+1].state&&st[i1][j1].state==st[i1+2][j1+2].state)||
					(st[i1][j1].state==st[i1-1][j1+1].state&&st[i1][j1].state==st[i1-2][j1+2].state&&st[i1][j1].state==st[i1+1][j1-1].state&&st[i1][j1].state==st[i1+2][j1-2].state)))
					{
						move(64,30);
						if(st[i1][j1].state==1)
							cout<<"黑棋胜  ";
						else
							cout<<"白棋胜  ";
					Sleep(3000);
					system("cls");	
					main();
					}//满足条件 输出胜利信息

				}
			}
	}
	move(60,60);
	return 0;
}