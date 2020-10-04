#include<iostream.h>
#include<iomanip.h>
#include<fstream.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
#include<time.h>
/////////////for variable///////////////////
class variables
{
	public:
		int x,y;
		int xtemp,ytemp;
		int temp1,temp2;
		int click;
		variables(int temporary1,int temporary2)
		{
			x=temporary1;
			y=temporary2;
		}
		variables()
		{
			xtemp=1000;
			ytemp=1000;
		}
};
///////////class for games////////////
class ping_pong
{
	public:
		int ballcolor;
		int ballstyle;
};
/////////////adminstrative///////////////
struct data
{
	char name[20];
	char pass[20];
};
////////////////////calculator/////////
int button,x,y,x1,y1,x2,y2,s;
long double num=0,get,num1=0,result=0;
char opr;
int a,b,r,i1,count,c,sq,newnum=1,d=0;
//////////////////global variables////////////////////////
int Left = 240, Top = 120, Width = 210, Height = 210 ;
double _YYYY,_MM,_DD,_tempyy,_tempmm;
int clicker=0,state=1,xpos,ypos,mod=1,click;
char name[20],pass[20];
///////////////////////////////////////copy////////////////////////////////////
union REGS in,out;
void setposi(int&xpos,int &ypos)
{
	in.x.ax=4;
	in.x.cx=xpos;
	in.x.dx=ypos;
	int86(51,&in,&out);
}
int callmouse()
{
	in.x.ax=1;
	int86(51,&in,&out);
	return 1;
}
void mouseposi(int &xpos,int &ypos,int &click)
{
	in.x.ax=3;
	int86(51,&in,&out);
	click=out.x.bx;
	xpos=out.x.cx;
	ypos=out.x.dx;
}
void showptr()
{
   in.x.ax=1;
   int86(0x33,&in,&out);
}
void hideptr()
{
   in.x.ax=2;
   int86(0x33,&in,&out);
}
void restrictptr(int x1,int y1,int x2,int y2)
{
    in.x.ax=7;
    out.x.cx=x1;
    out.x.dx=x2;
    int86(0x33,&in,&out);
    in.x.ax=8;
    out.x.cx=y1;
    out.x.dx=y2;
    int86(0x33,&in,&out);
}
////////////////////////main designs and layout////////////////////////////////////
void design_startup()
{
	char *design[]={"p","a","r","r","o","t"};
	delay(1000);
	randomize();
	settextstyle(2,0,10);
	setfillstyle(1,0);
	int col=15,letter=0,cont=0;
	float x1=0,y1,x2=0,y2;
	delay(50);
	for(int i=0;i<2250;x1+=0.1,x2+=0.1,i++)
	{
		y1=sin(x1-20);
		y2=cos(x2);
		col=random(15)+1;
		setcolor(col);
		putpixel(x2*3,(y2+10)*30,col);
		putpixel(x1*3,(y1+10)*30,col);
		if(i==321)
		{
			cont=1;
			letter=0;
		}
		else if(i==2*321)
		{
			cont=1;
			letter=1;
		}
		else if(i==3*321)
		{
			cont=1;
			letter=2;
		}
		else if(i==4*321)
		{
			cont=1;
			letter=3;
		}
		else if(i==5*321)
		{
			cont=1;
			letter=4;
		}
		else if(i==6*321)
		{
			cont=1;
			letter=5;
		}
		else
			cont=0;
		if(cont)
		{
			bar(100,100,400,250);
			outtextxy(getmaxx()/2,getmaxy()/2-65,design[letter]);
		}
		delay(3);
	}
	delay(1000);
	bar(100,100,400,250);
	for(i=0;i<6;i++)
	{
		settextstyle(9,0,5);
		setcolor(random(15)+1);
		outtextxy(200+i*40,getmaxy()/2-80,design[i]);
	}
	delay(1000);
}
void bar_design()
{
	variables temp_var(1000,1000);
	mouseposi(temp_var.xtemp,temp_var.ytemp,temp_var.temp1);
	setposi(temp_var.x,temp_var.y);
	bar(0,21,130,300);
	rectangle(0,21,130,40);
	rectangle(0,40,130,60);
	rectangle(0,60,130,80);
	rectangle(0,80,130,100);
	rectangle(0,100,130,120);
	rectangle(0,120,130,140);
	rectangle(0,140,130,160);
	rectangle(0,160,130,180);
	rectangle(0,180,130,200);
	rectangle(0,200,130,220);
	rectangle(0,220,130,240);
	rectangle(0,260,130,240);
	rectangle(0,260,130,280);
	rectangle(0,280,130,300);
	settextstyle(2,0,5);
	outtextxy(2,180,"calculator");
	outtextxy(2,160,"calendar");
	outtextxy(2,120,"ping pong");
	outtextxy(1,140,"|||||||||||||||||||||||||||||||||");
	outtextxy(2,220,"settings");
	outtextxy(2,20,"doc read");
	outtextxy(2,40,"doc write");
	outtextxy(2,80,"turtle");
	outtextxy(1,200,"|||||||||||||||||||||||||||||||||");
	outtextxy(1,60,"|||||||||||||||||||||||||||||||||");
	outtextxy(1,100,"|||||||||||||||||||||||||||||||||");
	outtextxy(2,240,"sleep");
	outtextxy(2,260,"restart");
	outtextxy(2,280,"shutdown");
	setposi(temp_var.xtemp,temp_var.ytemp);
}
void design()
{
	void home_proc1();
	setfillstyle(1,9);
	bar(0,700,700,0);
	setfillstyle(1,7);
	bar(0,20,700,0);
	setcolor(0);
	setfillstyle(1,0);
	fillellipse(11,10,10,10);
	settextstyle(4,0,1);
	setcolor(9);
	outtextxy(7,-6,"p");
	setcolor(4);
	rectangle(0,20,70,0);
	settextstyle(2,0,6);
	setcolor(0);
	outtextxy(25,-1,"start");
	home_proc1();
}
////////////////////////////app and functions///////////////////////
/////app functions and designs//////////////

////////calendar    //////////////////////////
char *_output(double cap)
{
	double dd;
	char CDD[6],CD[6];
	int l=0;
	dd=cap;
	gcvt(dd,10,CDD);
	l=strlen(CDD);
	if(l == 1)
	{
		  strcpy(CD,"0");
		  strcat(CD,CDD);
	}
	else
	{
		  strcpy(CD,CDD);
	}

	return(CD);
}
int _NumberOfDays(int month, int year)
{
	int No_of_days = 0;
	switch(month)
	{
		case 1:
			No_of_days = 31;
			break;
		case 2:
			if((year)%4 == 0)
				No_of_days = 29;
			else
				No_of_days = 28;
			break;
		case 3:
			No_of_days = 31;
			break;
		case 4:
			No_of_days = 30;
			break;
		case 5:
			No_of_days = 31;
			break;
		case 6:
			No_of_days = 30;
			break;
		case 7:
			No_of_days = 31;
			break;
		case 8:
			No_of_days = 31;
			break;
		case 9:
			No_of_days = 30;
			break;
		case 10:
			No_of_days = 31;
			break;
		case 11:
			No_of_days = 30;
			break;
		case 12:
			No_of_days = 31;
			break;
	}
	return No_of_days;
}
void DrawBox(int left,int top, int width, int height, int bgcolor)
{
	setfillstyle(SOLID_FILL,bgcolor);
	bar(left,top,left+width,top+height);
	setcolor(BLACK);
	line(left+1,top+1,left+width-1,top+1);
	line(left+1,top+1,left+1,top+height-1);
	setcolor(DARKGRAY);
	line(left,top,left+width,top);
	line(left,top,left,top+height);
	setcolor(DARKGRAY);
	line(left+1,top+height-1,left+width-1,top+height-1);
	line(left+width-1,top+1,left+width-1,top+height-1);
}
void DrawCaption(int left, int top, int width, int height, char *str, int col)
{
	setcolor(col);
	outtextxy(left+(width/2)-(textwidth(str)/2)+1,
	top+(height/2)-(textheight(str)/2)+1,str);
}
char *month(double mon)
{
	char month_name[][80] = {"January","Febuary","March","April","May",
	"June","July","August","September","October","November","December"};
	return (month_name[mon-1]);
}
int No_Of_Days(char date1[], char date2[])
{
	int d1, m1, y1;
	int d2, m2, y2;
	int D,M,Y;
	int Arr[12];
	int i,count;
	y1 = (date1[6] - 48) * 1000 + (date1[7] - 48) * 100 + (date1[8] - 48) * 10 + (date1[9] - 48);
	m1 = (date1[3] - 48) * 10 + (date1[4] - 48);
	d1 = (date1[0] - 48) * 10 + (date1[1] - 48);
	y2 = (date2[6] - 48) * 1000 + (date2[7] - 48) * 100 + (date2[8] - 48) * 10 + (date2[9] - 48);
	m2 = (date2[3] - 48) * 10 + (date2[4] - 48);
	d2 = (date2[0] - 48) * 10 + (date2[1] - 48);
	if (y1 > y2 || (m1 > m2 && y1 == y2))
	{
		D = d1;
		M = m1;
		Y = y1;
		d1 = d2;
		m1 = m2;
		y1 = y2;
		d2 = D;
		m2 = M;
		y2 = Y;
	}
	count = 0;
	for (i = m1 ; i < (m2 + (y2 - y1) * 12) ; i++)
	{
		if (i > 12 )
		{
			i = 1;
			y1 = y1 + 1;
		}
		Arr[0] = 31;
		if (y1 % 4 == 0 )
		{
			Arr[1] = 29;
		}
		else
		{
			Arr[1] = 28;
		}
		Arr[2] = 31;
		Arr[3] = 30;
		Arr[4] = 31;
		Arr[5] = 30;
		Arr[6] = 31;
		Arr[7] = 31;
		Arr[8] = 30;
		Arr[9] = 31;
		Arr[10] = 30;
		Arr[11] = 31;
		count = count + (Arr[i - 1]);
	}
	count = count + d2 - d1;
	if (count < 0 )
		count = count * -1;
	return count;
}
int Name_Of_Day()
{
	/* Assuming in 2015 on first january the day was thrusday. */
	/* Let S-1 M-2 T-3 W-4 T-5 F-6 S-7 */
	char datebuff[20];
	int _day = 5;
	int total_days = 0;
	strcpy(datebuff,"01");
	strcat(datebuff,"/");
	strcat(datebuff,_output(_MM));
	strcat(datebuff,"/");
	strcat(datebuff,_output(_YYYY));
	total_days = No_Of_Days(datebuff, "01/01/2015");
	if(_YYYY>=2015)
	{
		for(int k=1; k<= total_days; k++)
		{
			_day++;
			if(_day> 7)
				_day = 1;
		}
	}
	else
	{
		for(int k=1; k<= total_days; k++)
		{
			_day--;
			if(_day< 1)
				_day = 7;
		}
	}
	return _day;
}
void WriteDays(int left, int top)
{
	int No_of_days;
	char str[20];
	int _left = left;
	int _col = 0;
	No_of_days = _NumberOfDays((int)_MM, (int)_YYYY);
	left = left+(Name_Of_Day()-1)*30;
	for(int i=0;i< No_of_days;i++)
	{
		if(left >= _left+210)
		{
			left = _left;
			top += 30;
		}
		if(_YYYY == _tempyy && _MM == _tempmm && _DD == i+1)
		{
			setfillstyle(SOLID_FILL,BLUE);
			bar(left-2,top-5,left+15,top+10);
			_col = 1;
		}
	/*****************************/
		if(_col == 1)
		{
			setcolor(WHITE);
			_col = 0;
		}
		else if(left == _left)
		setcolor(RED);
		else
		setcolor(BLACK);
		outtextxy(left,top,gcvt(i+1,10,str));
		left += 30;
	}
}
void Draw()
{
	int left=Left,top=Top;
	int color = RED;
	char str[10];
	char days[][2]={"S","M","T","W","T","F","S"};
	/******************************************/
	DrawBox(Left,Top,Width,Height,WHITE);
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(Left+3,Top+3,Left+Width-3,Top+20);
	for(int i=0;i<7;i++)
	{
		setcolor(color);
		outtextxy(left+10,top+8,days[i]);
		left += 30;
		color = LIGHTGRAY;
	}
	/*******************************************/
	DrawBox(Left,Top-40,Width,40,LIGHTGRAY);
	DrawBox(Left+5,Top-30,Width/2-10,20,WHITE);
	DrawBox(Left+Width/2+5,Top-30,Width/2-10,20,WHITE);
	DrawCaption(Left+5,Top-30,Width/2-10,20,gcvt(_YYYY,10,str),BLUE);
	DrawCaption(Left+Width/2+5,Top-30,Width/2-10,20,month(_MM),BLUE);
}
void Init()
{
	char date[9];
	_strdate(date);
	/////////variables for ascii signs ////////////
	char up[2]={24};
	char down[2]={25};
	char left[2]={27};
	char right[2]={26};
	///date is in string format//////////
	////converting char to int //////
	int day1=date[3]-48,day2=date[4]-48;
	int month1=date[0]-48,month2=date[0]-48;
	int year1=date[6]-48,year2=date[7]-48;
	////////////////
	_YYYY=2000+(year1*10+year2);
	_MM=month1*10+month2;
	_DD=day1*10+day2;
	_tempyy = _YYYY;
	_tempmm = _MM;
	DrawBox(0,0,700,700,0);
	DrawBox(50,30,570,430,9);
	DrawBox(50,30,569,20,BLUE);
	DrawBox(150,350,380,102,LIGHTGRAY);
	setcolor(DARKGRAY);
	rectangle(150,350,530,452);
	setcolor(WHITE);
	outtextxy(55,35,"CALENDAR");
	setcolor(0);
	DrawBox(600,30,20,20,0);
	DrawBox(320,360,30,25,0);
	DrawBox(285,390,30,25,0);
	DrawBox(355,390,30,25,0);
	DrawBox(320,420,30,25,0);
	setcolor(0);
	outtextxy(90,165,"Using Keys :");
	outtextxy(90,180,up);
	outtextxy(92,180," : Increase Year");
	outtextxy(90,190,down);
	outtextxy(92,190," : Decrease Year");
	outtextxy(90,200,right);
	outtextxy(92,200," : Increase Month");
	outtextxy(90,210,left);
	outtextxy(92,210," : Decrease Month");
	setcolor(15);
	outtextxy(606,35,"X");
	setcolor(4);
	outtextxy(200,400,"PARROT");
	setcolor(9);
	outtextxy(330,368,up);
	outtextxy(330,429,down);
	outtextxy(295,398,left);
	outtextxy(365,398,right);

}
int cord_action_calendar(int xpos,int ypos)
{
	if((xpos>320&&xpos<350)&&(ypos>360&&ypos<385))
		return 1;
	else if(ypos>390&&ypos<415)
	{
		if(xpos>285&&xpos<315)
			return 4;
		else if(xpos>355&&xpos<385)
			return 3;
	}
	else if((xpos>320&&xpos<350)&&(ypos>420&&ypos<445))
		return 2;
	else if((xpos>600&&xpos<620)&&(ypos>30&&ypos<50))
		return 0;
	return 10;
}
void calendar()
{
	void main2();
	settextstyle(0,0,1);
	variables var(1000,1000);
	int decision,xpos,ypos,click;
	mouseposi(xpos,ypos,click);
	setposi(var.x,var.y);
	Init();
	Draw();
	WriteDays(Left+10,Top+40);
	setposi(xpos,ypos);
	do
	{

		mouseposi(xpos,ypos,click);
		if(click==1)
			decision=cord_action_calendar(xpos,ypos);
		switch(decision)
		{
			case 0: //Esc
				cleardevice();
				main2();
				break;
			case 1: // up arrow key - year increases
				if(_YYYY < 2070)
					_YYYY++;
				Draw();
				WriteDays(Left+10,Top+40);
				break;
			case 2: // Down arrow key - year decreases
			if(_YYYY > 1500)
				_YYYY--;
			Draw();
			WriteDays(Left+10,Top+40);
			break;
			case 3: // right arrow key - month increases
				if(_YYYY < 2070)
					_MM++;
				if(_MM>12 && _YYYY < 2070)
				{
					_MM = 1;
					_YYYY++;
				}
				Draw();
				WriteDays(Left+10,Top+40);
				break;
			case 4: // left arrow key - month decreases
				if(_YYYY>1500)
					_MM--;
					if(_MM < 1 && _YYYY > 1500)
					{
						_MM = 12;
						_YYYY--;
					}
					Draw();
					WriteDays(Left+10,Top+40);
					break;
		}
		delay(150);
		decision=10;
	}while(1);
}

//////////////////ping pong game/////////////////////
void design_game()
{
	setcolor(15);
	line(1,0,1,700);
	line(1,0,700,1);
	line(400,0,400,700);
	line(0,478,700,478);
	line(638,0,638,700);
	settextstyle(2,0,9);
	outtextxy(450,40,"PING PONG");
	settextstyle(2,0,4);
	outtextxy(420,150,"high score:");
	outtextxy(420,180,"score     :");
}
int process_game(int x1,int x2,int p1)
{
	if(((p1>x1-4)&&(p1<x2+4)))
		return 2;
	return 0;
}
void game(int col,int sty)
{
	randomize();
	int opt,score=0,highscore=0;
	int p1=98,p2=0;
	int reflexx=1,reflexy=2;
	int bary1=getmaxy()-8,barx1=100,bary2=getmaxy()-5,barx2=130;
	ifstream ifile;
	ifile.open("PINGPONG.TXT",ios::in|ios::binary);
	ifile.read((char *)&highscore,sizeof(highscore));
	ifile.close();
	while(opt!=27)
	{
		if(kbhit())
		{
			opt=getch();
			if(opt==77)
			{
				setfillstyle(1,0);
				bar(barx1,bary1,barx2,bary2);
				setfillstyle(1,15);
				if(barx2<395)
				{
					barx1+=5;
					barx2+=5;
				}
			}
			if(opt==75)
			{
				setfillstyle(1,0);
				bar(barx1,bary1,barx2,bary2);
				if(barx1>5)
				{
					barx1-=5;
					barx2-=5;
				}
			}
		}
		setfillstyle(9,15);
		bar(barx1,bary1,barx2,bary2);
		if(p1>394)
			reflexx=-1;
		else if(p1<5)
			reflexx=1;
		if(p2>getmaxy()-12)
		{
			reflexy=process_game(barx1,barx2,p1);
			score++;
		}
		else if(p2<6)
			reflexy=-2;
		if(reflexx==1)
		{
			p1=p1++;

		}
		if(reflexy==2)
		{
			p2--;
		}
		if(reflexy==-2)
		{
			p2++;
		}
		if(reflexx==-1)
		{
			p1--;
		}
		if(reflexy==0)
		{
			break;
		}
		setfillstyle(1,0);
		bar(2,1,398,getmaxy()-8);
		line(1,0,700,1);
		setfillstyle(sty,col);
		fillellipse(p1,p2,3,3);
		delay(5);
		gotoxy(62,12);
		cout<<score;
		gotoxy(62,10);
		ofstream ofile;
		ofile.open("PINGPONG.TXT",ios::out|ios::binary);
		if(highscore<=score)
		{
			gotoxy(62,10);
			ofile.write((char *)&score,sizeof(score));
			cout<<score;
		}
		else
			cout<<highscore;
	}
}
void process_select_ballsty(int &ballstyle)
{
	int xpos,ypos,click,des=0;
	ballstyle=0;
	int posi;
	do
	{
		mouseposi(xpos,ypos,click);
		if(click==1)
		{
			if((pow((xpos-30),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballstyle=1;
			}
			if((pow((xpos-80),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballstyle=2;
			}
			if((pow((xpos-130),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballstyle=3;
			}
			if((pow((xpos-180),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballstyle=4;
			}
			if((pow((xpos-230),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballstyle=5;
			}
			if((pow((xpos-280),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballstyle=6;
			}
			if((pow((xpos-330),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballstyle=7;
			}
			if((pow((xpos-380),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballstyle=8;
			}
			if((pow((xpos-430),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballstyle=9;
			}
			if((pow((xpos-480),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballstyle=10;
			}
			if((pow((xpos-530),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballstyle=11;
			}
		}
	}while(!des);
}
void process_select_ballcol(int &ballcolor)
{
	int xpos,ypos,click,des=0;
	ballcolor=0;
	int posi;
	do
	{
		mouseposi(xpos,ypos,click);
		if(click==1)
		{
			if((pow((xpos-30),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballcolor=1;
			}
			if((pow((xpos-80),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballcolor=2;
			}
			if((pow((xpos-130),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballcolor=3;
			}
			if((pow((xpos-180),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballcolor=4;
			}
			if((pow((xpos-230),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballcolor=5;
			}
			if((pow((xpos-280),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballcolor=6;
			}
			if((pow((xpos-330),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballcolor=7;
			}
			if((pow((xpos-380),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballcolor=8;
			}
			if((pow((xpos-430),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballcolor=9;
			}
			if((pow((xpos-480),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballcolor=10;
			}
			if((pow((xpos-530),2)+pow((ypos-200),2))<100)
			{
				des=1;
				ballcolor=11;
			}
		}
	}while(!des);
}
void process_game()
{
	cleardevice();
	ping_pong user;
	int des,xpos,ypos,click,x=1000,y=1000;
	line(1,0,1,700);
	line(1,0,700,1);
	line(0,478,700,478);
	line(638,0,638,700);
	settextstyle(0,0,5);
	setcolor(3);
	outtextxy(150,50,"ping pong");
	setcolor(9);
	settextstyle(0,0,2);
	outtextxy(10,150,"select ball color:");
	int ballcord[]={30,200,80,200,130,200,180,200,
	230,200,280,200,330,200,380,200,430,200,480,200,530,200};
	user.ballcolor=1;
	mouseposi(xpos,ypos,click);
	setposi(x,y);
	for(int i=0;i<23;i+=2,user.ballcolor++)
	{
		setfillstyle(1,user.ballcolor);
		setcolor(15);
		fillellipse(ballcord[i],ballcord[i+1],10,10);
	}
	setposi(xpos,ypos);
	process_select_ballcol(user.ballcolor);
	mouseposi(xpos,ypos,click);
	setposi(x,y);
	setfillstyle(1,0);
	bar(200,100,280,190);
	settextstyle(0,0,5);
	setcolor(3);
	outtextxy(150,50,"ping pong");
	setcolor(9);
	settextstyle(0,0,2);
	outtextxy(10,150,"select ball style:");
	user.ballstyle=0;
	for(i=0;i<22;i+=2,user.ballstyle++)
	{
		setfillstyle(user.ballstyle,user.ballcolor);
		setcolor(user.ballcolor);
		fillellipse(ballcord[i],ballcord[i+1],10,10);
	}
	setposi(xpos,ypos);
	delay(150);
	process_select_ballsty(user.ballstyle);
	cleardevice();
	design_game();
	game(user.ballcolor,user.ballstyle);
}
void animation_game()
{
	hideptr();
	cleardevice();
	for(int i=0;i<15;i++)
	{
		settextstyle(0,0,5);
		setcolor(i);
		outtextxy(150,100,"ping pong");
		delay(300);
	}
}
void pingpong()
{
	void main2();
	int opt;
	cleardevice();
	animation_game();
	showptr();
	process_game();
	setfillstyle(1,0);
	bar(0,0,700,700);
	settextstyle(2,0,10);
	DrawBox(1,1,getmaxx(),getmaxy(),0);
	outtextxy(getmaxx()/2-150,200,"try again(y/n)");
	do
	{
		opt=getch();
		if(opt=='y'||opt=='Y')
			pingpong();
		else if(opt=='N'||opt=='n')
			main2();
	}while(1);
}
///////////////////////calculator//////////
long double addnum(int getnum)
{
	num=num*10+getnum;
	return(num);
}
void calculator()
{
	void main2();
	int driver=DETECT,mode;
	int q,p[12];
	char input;
	char *inpu[4][4]={"1","2","3","4",
	"5","6","7","8",
	"9","0","+","-" ,
	"*","/","clr","="};
	char inp[4][4]={'1','2','3','4',
	'5','6','7','8',
	'9','0','+','-' ,
	'*','/','l','='};
	hideptr();
	cleardevice();
	setfillstyle(CLOSE_DOT_FILL,10);
	bar(260,82,450,320);
	bar(430,70,450,320);
	setfillstyle(1,GREEN);
	bar(236,82,432,300);
	setcolor(GREEN);
	rectangle(238,50,430,80);
	rectangle(237,49,431,81);
	rectangle(236,48,432,82);
	c=240;
	d=100;
	s=0;
	for(a=0;a<4;a++)
	{
		c=240;
		for(b=0;b<4;b++)
		{
			setfillstyle(1,RED);
			bar(c,d,c+40,d+40);
			setcolor(YELLOW);
			outtextxy(c+10,d+14,inpu[a][b]);
			c+=50;
		}
		d+=50;
	}
	num=0;
	gotoxy(36,5);
	printf("%18.1Lf",num);
	count=0;
	while(!kbhit())
	{
		outtextxy(30,20,"Press any key to exit..");
		i1=0;
		c=240;
		d=100;
		rectangle(0,0,638,478);
		showptr();
		mouseposi(x,y,button);
		for(a=0;a<4;a++)
		{
			c=240;
			for(b=0;b<4;b++)
			{
				if((x>=c&&x<=c+40)&&(y>=d&&y<=d+40))
				{
					if((button&1)==1)
					{
						while((button&1)==1)
						{
							setcolor(10);
							rectangle(c,d,c+40,d+40);
							rectangle(c-1,d-1,c+41,d+41);
							rectangle(c-2,d-2,c+42,d+42);
							break;
						}
				delay(100);
				setcolor(GREEN);
				rectangle(c,d,c+40,d+40);
				rectangle(c-1,d-1,c+41,d+41);
				rectangle(c-2,d-2,c+42,d+42);
				input=inp[a][b];
				switch(input)
				{
	case '1':
		get=addnum(1);
		gotoxy(36,5);
		printf("%18.1Lf",get);
		break;
	case '2':
		get=addnum(2);
		gotoxy(36,5);
		printf("%18.1Lf",get);
		break;
	case '3':
		get=addnum(3);
		gotoxy(36,5);
		printf("%18.1Lf",get);
		break;
	case '4':
		get=addnum(4);
		gotoxy(36,5);
		printf("%18.1Lf",get);
		break;
	case '5':
		get=addnum(5);
		gotoxy(36,5);
		printf("%18.1Lf",get);
		break;
	case '6':
		get=addnum(6);
		gotoxy(36,5);
		printf("%18.1Lf",get);
		break;
	case '7':
		get=addnum(7);
		gotoxy(36,5);
		printf("%18.1Lf",get);
		break;
	case '8':
		get=addnum(8);
		gotoxy(36,5);
		printf("%18.1Lf",get);
		break;
	case '9':
		get=addnum(9);
		gotoxy(36,5);
		printf("%18.1Lf",get);
		break;
	case '0':
		get=addnum(0);
		gotoxy(36,5);
		printf("%18.1Lf",get);
		break;
	case '+':
		num1=num;
		num=0;
		opr='+';
		gotoxy(36,5);
		printf("%18.1Lf",num);
		break;
	case '-':
		num1=num;
		num=0;
		opr='-';
		gotoxy(36,5);
		printf("%18.1Lf",num);
		break;
	case '*':
		num1=num;
		num=0;
		opr='*';
		gotoxy(36,5);
		printf("%18.1Lf",num);
		break;
	case '/':
		num1=num;
		num=0;
		opr='/';
		gotoxy(36,5);
		printf("%18.1Lf",num);
		break;
	case 'l':
		num=0;
		num1=0;
		result=0;
		count=0;
		gotoxy(36,5);
		printf("%18.1Lf",num);
		break;
	case '=':
		switch(opr)
		{
			case '+':
			if(count<1)
			{
				result=num+num1;
			}
			else
			{
				result=result+num;
			}
			gotoxy(36,5);
			printf("%18.1Lf",result);
			count+=1;
			break;
		case '-':
			if(count<1)
			{
				result=num1-num;
			}
			else
			{
				result=result-num;
			}
			gotoxy(36,5);
			printf("%18.1Lf",result);
			count+=1;
			break;
		case '*':
			if(count<1)
			{
			result=num1*num;
			}
			else
			{
				result=result*num;
			}
			gotoxy(36,5);
			printf("%18.1Lf",result);
			count+=1;
			break;
		case '/':
			if(count<1)
			{
				result=num1/num;
			}
			else
			{
				result=result/num;
			}
			gotoxy(36,5);
			printf("%18.1Lf",result);
			count+=1;
			break;
		}
	}
	}
	}
	c+=50;
	}
	d+=50;
	}
	setcolor(YELLOW);
	delay(150);
	}
	main2();
}
////////////////////settings//////////////

///////////////////////////////////////////////////
void DrawBox1(int left,int top, int width, int height, int bgcolor,int fill=1)
{
	setfillstyle(fill,bgcolor);
	bar(left,top,left+width,top+height);
	setcolor(BLACK);
	line(left+1,top+1,left+width-1,top+1);
	line(left+1,top+1,left+1,top+height-1);
	setcolor(DARKGRAY);
	line(left,top,left+width,top);
	line(left,top,left,top+height);
	setcolor(DARKGRAY);
	line(left+1,top+height-1,left+width-1,top+height-1);
	line(left+width-1,top+1,left+width-1,top+height-1);
}
void animation_settings()
{
	hideptr();
	char *animate[]={"s","e","t","t","i","n","g","s"};
	randomize();
	for(int i=0;i<8;i++)
	{
		delay(100);
		settextstyle(3,0,4);
		setcolor(random(15)+1);
		outtextxy(getmaxx()/2,getmaxy()/2,animate[i]);
		delay(500);
		cleardevice();
	}
	for(i=0;i<8;i++)
	{
		settextstyle(2,0,8);
		setcolor(random(15)+1);
		outtextxy(200+i*33,300,animate[i]);
	}
	int setbar1[10]={295,207,307,195,357,240,344,252,295,207}
	,setbar2[10]={340,193,357,207,294,236,309,252,344,207};
	setfillstyle(1,5);
	setcolor(15);
	bar(270,180,380,265);
	setfillstyle(1,WHITE);
	bar(318,190,332,255);
	bar(290,215,360,228);
	fillpoly(4,setbar1);
	fillpoly(4,setbar2);
	fillellipse(325,222,25,25);
	setfillstyle(1,5);
	fillellipse(325,222,12,12);
	delay(1000);
	showptr();
}
void cordaction_info()
{
	int xpos,ypos,click;
	void design_settings_1();
	mouseposi(xpos,ypos,click);
	if(click==1)
	{
		if((xpos>620&&xpos<660)&&(ypos>0&&ypos<20))
		{
			cleardevice();
			design_settings_1();
		}
	}
}
void reset_p()
{
	int opt;
	data user;
	void design_settings_1();
	setfillstyle(1,3);
	hideptr();
	bar(0,0,700,700);
	showptr();
	settextstyle(2,0,6);
	outtextxy(10,80,"are you sure?");
	outtextxy(10,110,"enter:continue     esc:exit");
	do
	{
		opt=getch();
		switch(opt)
		{
			case 13:
				int contd;
				char pass[20],paswrd[20];
				ifstream Ifile("USER.DAT",ios::out||ios::binary);
				Ifile.read((char*)&user,sizeof(user));
				Ifile.close();
				hideptr();
				bar(0,0,700,748);
				showptr();
				outtextxy(10,205,"PASSWORD:");
				setfillstyle(0,0);
				bar(95,205,260,225);
				window(13,14,40,25);
				gets(paswrd);
				contd=strcmp(paswrd,user.pass);
				if(!contd)
				{
				remove("USER.DAT");
				hideptr();
				bar(0,0,700,700);
				setfillstyle(9,9);
				bar(100,160,getmaxx()-100,180);
				for(int i=110;i<=getmaxx()-110;i++)
				{
					outtextxy(120,180,"removing...");
					setfillstyle(1,0);
					bar(110,168,i,172);
					delay(50);
				}
				getch();
				exit(0);
				}
				else
				{
					settextstyle(2,0,4);
					outtextxy(10,300,"wrong password !!! do you want to continue:");
					outtextxy(10,310,"enter:retry        ESC:escape");
					opt=getch();
					switch(opt)
					{
						case 13:
							reset_p();
							break;
						case 27:
							hideptr();
							design_settings_1();
					};
				}
				break;
			case 27:
				hideptr();
				design_settings_1();
				break;
		};
	}while(1);
}
void info()
{
	hideptr();
	DrawBox1(0,0,getmaxx(),getmaxy(),8,10);
	DrawBox1(0,0,getmaxx(),20,0,1);
	settextstyle(2,0,6);
	outtextxy(625,-2,"X");
	setfillstyle(9,8);
	fillellipse(getmaxx()/2,100,50,50);
	settextstyle(3,0,9);
	setcolor(4);
	outtextxy(300,45,"P");
	outtextxy(200,120,"parrot");
	settextstyle(2,0,4);
	bar(200,250,470,400);
	int i=250;
	do
	{
		showptr();
		setcolor(i);
		setfillstyle(9,8);
		bar(200,250,470,400);
		settextstyle(7,0,3);
		outtextxy(350,i,"THANKS");
		settextstyle(2,0,5);
		setcolor(i+20);
		outtextxy(300,i+30," GAUTAM SIR");
		outtextxy(300,i+45," MARYGIRI SCHOOL");
		outtextxy(300,i+60," PARENTS");
		outtextxy(300,i+75," FRIENDS");
		if(i>300)
			i=250;
		else
			i=i+5;
		delay(100);
		cordaction_info();
	}while(1);
}
void account_p_add()
{
		void admin_proc_create(),adm_create_background();
		void pixelise_adm(int,int),smalllogo();
		hideptr();
		cleardevice();
		pixelise_adm(90000,1);
		smalllogo();
		adm_create_background();
		delay(100);
		admin_proc_create();
}
void cordaction_account()
{
	void design_settings_1();
	do
	{
	mouseposi(xpos,ypos,click);
	if(click==1)
	{
		if((xpos>620&&xpos<660)&&(ypos>0&&ypos<20))
		{
			cleardevice();
			design_settings_1();
		}
		if((xpos>50&&xpos<130)&&(ypos>200&&ypos<250))
		{
			account_p_add();
		}
	}
	}while(1);
}
void account_p()
{
	cleardevice();
	callmouse();
	hideptr();
	DrawBox1(0,0,getmaxx(),getmaxy(),8,10);
	DrawBox1(0,0,getmaxx(),20,0,1);
	settextstyle(2,0,6);
	outtextxy(625,-2,"X");
	setcolor(9);
	settextstyle(9,0,5);
	outtextxy(150,30,"ACCOUNTS");
	setfillstyle(1,15);
	settextstyle(2,0,8);
	bar(50,200,130,250);
	outtextxy(70,210,"ADD");
	showptr();
	cordaction_account();
}
void cordaction_settings(int xpos,int ypos)
{
	void main2();
	void turtle();
	if((xpos>620&&xpos<660)&&(ypos>0&&ypos<20))
	{
		main2();
	}
	if((xpos>270&&xpos<380)&&(ypos>70&&ypos<155))
	{
		turtle();
	}
	if((xpos>125&&xpos<235)&&(ypos>180&&ypos<265))
	{
		info();
	}
	if((xpos>270&&xpos<380)&&(ypos<385&&ypos>300))
	{
		reset_p();
	}
	if((xpos>390&&xpos<500)&&(ypos<265&&ypos>180))
	{
		account_p();
	}
}
void process_settings()
{
	int xpos,ypos,click;
	callmouse();
	do
	{
		mouseposi(xpos,ypos,click);
		if(click==1)
			cordaction_settings(xpos,ypos);
	}while(1);
}
void design_settings_1()
{
	hideptr();
	DrawBox1(0,0,700,700,0,1);
	DrawBox1(0,20,700,700,8,10);
	DrawBox1(620,0,40,20,0);
	settextstyle(2,0,7);
	setcolor(15);
	outtextxy(625,-2,"X");
	outtextxy(10,-2,"settings");
	setcolor(15);
	int setbar1[10]={295,207,307,195,357,240,344,252,295,207}
	,setbar2[10]={340,193,357,207,294,236,309,252,344,207};
	setfillstyle(1,5);
	bar(270,180,380,265);
	setfillstyle(1,WHITE);
	bar(318,190,332,255);
	bar(290,215,360,228);
	fillpoly(4,setbar1);
	fillpoly(4,setbar2);
	fillellipse(325,222,25,25);
	setfillstyle(1,5);
	fillellipse(325,222,12,12);
	line(0,20,270,180);
	line(getmaxx(),20,380,180);
	line(0,getmaxy(),270,265);
	line(getmaxx(),getmaxy(),380,265);
	setfillstyle(1,15);
	bar(270,70,380,155);
	bar(125,180,235,265);
	bar(270,300,380,385);
	bar(415,180,525,265);
	setcolor(5);
	outtextxy(290,90,"switch");
	outtextxy(150,200,"info");
	outtextxy(290,320,"reset");
	outtextxy(408,200,"Accounts");
	showptr();
	delay(200);
	process_settings();
}
void design_settings()
{
	animation_settings();
	design_settings_1();
}
////////////////////////////turtle/////////////////////
//starting the system
void turtle()
{
	hideptr();
	void startup(),home_turtle();
	mod=0;
	startup();
	home_turtle();
}
//intro page
void startup()
{
	setfillstyle(10,9);
	bar(0,0,700,700);
	settextstyle(1,0,5);
	outtextxy(245,200,"TURTLE");
	circle(310,300,20);
	for(int i=3;i>0;--i)
	{
		setcolor(i);
		outtextxy(245,200,"TURTLE");
		window(39,19,80,25);
		printf("%d",i);
		sleep(i);
	}
	cleardevice();
}
////////////                     applications                //////////////
//////////////////////////////////doc writer/////////////////////////////////
void doc_write()
{
	void home_turtle();
	int line=0,opt;
	char usertext[80],filename[20];
	setfillstyle(9,DARKGRAY);
	bar(700,600,0,30);
	settextstyle(3,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(230,0,"document writer");
	setfillstyle(XHATCH_FILL,5);
	bar(700,50,0,30);
	setfillstyle(11,DARKGRAY);
	bar(700,50,0,448);
	setfillstyle(0,0);
	bar(0,50,700,448);
	settextstyle(2,0,7);
	outtextxy(10,203,"FILENAME:");
	settextstyle(2,0,4);
	window(15,14,40,25);
	gets(filename);
	setfillstyle(0,0);
	bar(0,50,700,448);
	window(3,4,40,25);
	for(int i=0;i<700;i++)
	{
		if(line<=80)
		{
			line++;
			usertext[i]=getch();
		}
		else
		{
			line=1;
			usertext[i]='\n';
		}
		if(usertext[i]==27)
		{
			ofstream Ofile(filename,ios::out|ios::trunc);
			Ofile.write((char *)&usertext,i-1);
			Ofile.close();
			break;
		}
		else if(usertext[i]==9)
			break;
		else if(usertext[i]==13)
		{
			line=1;
			usertext[i]='\n';
			cout<<usertext[i];
		}
		else if(usertext[i]==8)
		{
			line-=2;
			i-=1;
			int x=wherex();
			int y=wherey();
			gotoxy(x=x-1,y);
			cout<<'\0';
			gotoxy(x,y);
		}
		else
			cout<<usertext[i];
	}
	setfillstyle(0,0);
	bar(0,50,700,448);
	setfillstyle(11,DARKGRAY);
	bar(0,300,700,448);
	gotoxy(20,25);
	cout<<usertext<<"****";
	getch();
	outtextxy(410,310,"press enter to write a new file");
	outtextxy(450,340,"press esc to exit");
	settextstyle(2,0,7);
	outtextxy(150,240,"FILE SAVED");
	opt=getch();
	switch(opt)
	{
		case 13:
			doc_write();
			break;
		case 27:
			home_turtle();
			break;
	};
}
////////////////////////////////doc reader///////////////////////////////////
void doc_reader()
{
	void home_turtle();
	int line,opt;
	char usertext[80],filename[8];
	setfillstyle(9,DARKGRAY);
	bar(700,600,0,30);
	settextstyle(3,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(230,0,"document reader");
	setfillstyle(XHATCH_FILL,5);
	bar(700,50,0,30);
	setfillstyle(11,DARKGRAY);
	bar(700,50,400,448);
	settextstyle(8,0,5);
	setcolor(WHITE);
	outtextxy(420,120,"TURTLE");
	circle(589,130,7);
	settextstyle(0,0,1);
	outtextxy(587,126,"c");
	outtextxy(150,460,"version 1.0  COPYRIGHT (C) 2019 TURTLE.INC");
	setfillstyle(1,WHITE);
	bar(401,50,400,450);
	bar(700,449,0,450);
	bar(700,251,400,250);
	setfillstyle(0,0);
	bar(0,50,399,448);
	settextstyle(2,0,7);
	outtextxy(10,203,"FILENAME:");
	window(15,14,40,25);
	gets(filename);
	strupr(filename);
	ifstream Ifilecheck(filename,ios::nocreate);
	if(!Ifilecheck)
	{
		setfillstyle(0,0);
		bar(0,50,399,448);
		outtextxy(100,203,"FILE DOES NOT EXIST");
		outtextxy(40,300,"press enter-retry   esc-escape");
		opt=getch();
		switch(opt)
		{
			case 13:
				doc_reader();
				break;
			case 27:
				home_turtle();
				break;
		};
	}
	ifstream Ifile(filename,ios::in||ios::binary);
	Ifile.getline(usertext,2);;
	cout<<strlen(usertext);
	setfillstyle(0,0);
	bar(0,50,399,448);
	window(1,6,80,25);
	for(int i=0;i<=strlen(usertext);i++)
	{
		cout<<usertext[i];
	}
	getch();
	setfillstyle(0,0);
	bar(0,50,399,448);
	setfillstyle(11,DARKGRAY);
	bar(402,300,700,448);
	settextstyle(2,0,5);
	setcolor(14);
	outtextxy(410,310,"press enter to read a new file");
	outtextxy(450,340,"press esc to exit");
	settextstyle(2,0,7);
	Ifile.close();
	outtextxy(150,240,"FILE READ");
	opt=getch();
	switch(opt)
	{
		case 13:
			doc_reader();
			break;
		case 27:
			home_turtle();
			break;
	};
}
/////////////////////////calculator///////////////////////////////////
void get_number(int opt,int operation)
{
	outtextxy(100,220,"enter:");
	static long float num1,num2;
	if(opt)
	{
		window(10,10,40,25);
		cin>>num1;
	}
	else
	{
		bar(60,220,350,375);
		window(20,10,40,25);
		outtextxy(100,220,"enter:");
		char operation_sign=operation;
		cout<<operation_sign<<"        ";
		cin>>num2;
		switch(operation)
		{
			case 43:
			window(35,10,40,25);
			cout<<"="<<"          "<<num1+num2;
			break;
			case 45:
			window(35,10,40,25);
			cout<<"="<<"          "<<num1-num2;
			break;
			case 42:
			window(35,10,40,25);
			cout<<"="<<"          "<<num1*num2;
			break;
			case 47:
			window(35,10,40,25);
			cout<<"="<<"          "<<float(num1/num2);
			break;
		}
	}
}
void calc_proc()
{
	void calc();
	void main2();
	int opt,xrec=0,yrec=0,contd=1;
	int operation;
	setcolor(RED);
	setfillstyle(1,BLACK);
	rectangle(393,223,568,263);
	int xtemp1,xtemp2,ytemp1,ytemp2;
	int xcord1[2]={63,393};
	int xcord2[2]={348,568};
	int ycord1[4]={223,278,333,388};
	int ycord2[4]={263,318,373,428};
	xtemp1=xcord1[1];
	xtemp2=xcord2[1];
	ytemp1=ycord1[yrec];
	ytemp2=ycord2[yrec];
	get_number(1,0);
	bar(60,220,350,375);
	outtextxy(100,220,"select operation");
	do
	{
		opt=getch();
		switch(opt)
		{
			case 27:
				exit(0);
				break;
			case 77:
				if(ytemp1<388)
					break;
				else
				{
				xtemp1=xcord1[xrec];
				xtemp2=xcord2[xrec];
				setcolor(0);
				rectangle(xtemp1,ytemp1,xtemp2,ytemp2);
				xrec++;
				if(xrec==2)
					xrec=0;
				xtemp1=xcord1[xrec];
				xtemp2=xcord2[xrec];
				setcolor(RED);
				if(xtemp1==393)
				{
					xtemp2=568;
				}
				rectangle(xtemp1,ytemp1,xtemp2,ytemp2);
				break;
				}
			case 75:
				if(ytemp1<388)
					break;
				else
				{
				setcolor(0);
				rectangle(xtemp1,ytemp1,xtemp2,ytemp2);
				xrec--;
				if(xrec==-1)
					xrec=1;
				xtemp1=xcord1[xrec];
				xtemp2=xcord2[xrec];
				setcolor(RED);
				if(xtemp2==568)
				{
					xtemp1=393;
				}
				rectangle(xtemp1,ytemp1,xtemp2,ytemp2);
				break;
				}
			case 72:
				if(xtemp1<=363)
					break;
				else
				{
				ytemp1=ycord1[yrec];
				ytemp2=ycord2[yrec];
				setcolor(0);
				rectangle(xtemp1,ytemp1,xtemp2,ytemp2);
				yrec--;
				if(yrec==-1)
					yrec=3;
				ytemp1=ycord1[yrec];
				ytemp2=ycord2[yrec];
				setcolor(RED);
				rectangle(xtemp1,ytemp1,xtemp2,ytemp2);
				break;
				}
			case 80:
				if(xtemp1<=363)
					break;
				else
				{
				ytemp1=ycord1[yrec];
				ytemp2=ycord2[yrec];
				setcolor(0);
				rectangle(xtemp1,ytemp1,xtemp2,ytemp2);
				yrec++;
				if(yrec==4)
					yrec=0;
				ytemp1=ycord1[yrec];
				ytemp2=ycord2[yrec];
				setcolor(RED);
				rectangle(xtemp1,ytemp1,xtemp2,ytemp2);
				break;
				}
			case 13:
				contd=0;
				if(xtemp1==63)
				{
					if(mod==0)
						turtle();
					else
						main2();
				}
				else if(xtemp1==393&&ytemp1==223)
					operation=43;
				else if(xtemp1==393&&ytemp1==278)
					operation=45;
				else if(xtemp1==393&&ytemp1==333)
					operation=42;
				else
					operation=47;
				break;
		}
	}while(contd);
	get_number(0,operation);
	getch();
	calc();
}
void calc()
{
	setfillstyle(11,DARKGRAY);
	bar(0,0,700,700);
	settextstyle(2,0,10);
	setcolor(5);
	outtextxy(200,0,"CALCULATOR");
	setfillstyle(1,15);
	bar(50,100,580,440);
	setfillstyle(0,0);
	bar(60,110,570,190);
	bar(390,220,570,265);
	bar(390,275,570,320);
	bar(60,220,350,375);
	bar(390,330,570,375);
	bar(60,385,350,430);
	bar(390,385,570,430);
	settextstyle(2,0,8);
	setcolor(15);
	outtextxy(175,395,"OFF");
	outtextxy(480,228,"+");
	outtextxy(480,280,"-");
	outtextxy(480,332,"x");
	outtextxy(480,388,"/");
	calc_proc();
}
///////////////////calendar&clock
int findday()
{
	char day[5];
	time_t t;
	time(&t);
	movmem(ctime(&t),day,2);
	if(day[0]=='S'&&day[1]=='u')
		return 1;
	else if(day[0]=='M')
		return 2;
	else if(day[0]=='T'&&day[1]=='u')
		return 3;
	else if(day[0]=='W')
		return 4;
	else if(day[0]=='T'&&day[1]=='h')
		return 5;
	else if(day[0]=='F')
		return 6;
	else if(day[0]=='S'&&day[1]=='a')
		return 7;
	else
		return 0;
}
int finddate()
{
	struct date d;
	getdate(&d);
	return d.da_day;
}
int maxday()
{
	int lastday=0;
	struct date d;
	getdate(&d);
	int month=d.da_mon;
	int year=d.da_year;
	switch(month)
	{
		case 1:
			lastday=31;
			break;
		case 3:
			lastday=31;
			break;
		case 5:
			lastday=31;
			break;
		case 7:
			lastday=31;
			break;
		case 8:
			lastday=31;
			break;
		case 10:
			lastday=31;
			break;
		case 12:
			lastday=31;
			break;
		case 4:
			lastday=30;
			break;
		case 6:
			lastday=30;
			break;
		case 9:
			lastday=30;
			break;
		case 11:
			lastday=30;
			break;
		case 2:
			if(year%4==0)
				lastday=29;
			else
				lastday=28;
			break;
	};
	return lastday;
}
int month_now()
{
	struct date d;
	getdate(&d);
	return d.da_mon;
}
int year_now(int value)
{
	time_t t;
	char *get_year=ctime(&t);
	char year[1];
	time(&t);
	ctime(&t);
	year[1]=get_year[value];
	return year[1];
}
void calendar(int firstday)
{
	void clock_proc();
	window(1,1,40,25);
	setfillstyle(1,3);
	bar(0,0,700,700);
	setbkcolor(3);
	int temp=firstday;
	int lastday=maxday();
	int thismonth=month_now();
	char *year_val[]={"0","1","2","3","4","5","6","7","8","9"};
	char *months[]={'\0',"January", "February", "March", "April",
	"May", "June","July", "August", "September", "October",
	"November", "December"};
	char daydisp[]="Su   Mo   Tu   We   Th   Fr   Sa";
	cout<<"\n\n\n\n\n\n\n\n\t\t\t";
	setcolor(8);
	settextstyle(2,0,10);
	int year,value=20,width=0;
	for(int yearvalue=0;yearvalue<4;yearvalue++)
	{
		year=year_now(value);
		outtextxy(20+width,30,year_val[year-48]);
		width=width+20;
		++value;
	}
	outtextxy(190,60,months[thismonth]);
	setcolor(14);
	settextstyle(0,0,1);
	outtextxy(190,120,daydisp);
	for(int i=1;i<=lastday;i++)
	{
		if(i==1)
		{
			cout<<"\n\t\t\t"<<setw(5*(firstday-1)+1)<<i<<setw(5);
			++temp;
		}
		else
		{
			++temp;
			if(i==9&&temp!=1)
				cout<<i<<setw(6);
			else
				cout<<i<<setw(5);
			if(temp>7)
			{
				cout<<"\n\t\t\t";
				temp=1;
			}
		}
	}
	clock_proc();
}
void calendar_proc()
{
	int day=findday(),temp=day;
	int date=finddate();
	for(int i=date;i!=1;--i,--temp)
	{
		if(temp<1)
			temp=7;
	}
	calendar(temp);
}
void time_disp(char hour1,char hour2,char min1,char min2,char sec1,char sec2)
{
	char *time_value[]={"0","1","2","3","4","5","6","7","8","9"};
	settextstyle(2,0,10);
	outtextxy(200,300,time_value[hour1]);
	outtextxy(220,300,time_value[hour2]);
	outtextxy(240,300," :");
	outtextxy(290,300,time_value[min1]);
	outtextxy(310,300,time_value[min2]);
	outtextxy(320,300," :");
	outtextxy(370,300,time_value[sec1]);
	outtextxy(400,300,time_value[sec2]);
}
void clock_proc()
{
   void home_turtle();
   do
   {
	setfillstyle(1,3);
	bar(180,220,550,340);
	time_t t;
	char *get_time=ctime(&t);
	char hour[2],min[2],sec[2];
	time(&t);
	ctime(&t);
	hour[1]=get_time[11];
	hour[2]=get_time[12];
	min[1]=get_time[14];
	min[2]=get_time[15];
	sec[1]=get_time[17];
	sec[2]=get_time[18];
	time_disp(hour[1]-48,hour[2]-48,min[1]-48,min[2]-48,sec[1]-48,sec[2]-48);
	//-48 for converting integers in char form to int form
	//i.e ascii conversion
	delay(100);
   }while(!kbhit());
   home_turtle();
}
////////////////////////////////settings/////////////////////////////////////////
////**************ACCOUNTS*****************************************/
int valid_name(char name[20])
{
	int res1,res2;
	if(strlen(name)<4||strlen(name)>20)
		res1=1;
	else
		res1=0;
	for(int i=0;i<strlen(name);i++)
	{
		if(name[i]==' '||name[i]==27)
		{
			res2=1;
			break;
		}
		else
			res2=0;
	}
	if(res1||res2)
		return 1;
	else
		return 0;
}
//for changing new user name
void nw_uname()
{
	int res,opt;
	char old_uname[20],new_uname[20];
	setfillstyle(1,3);
	bar(0,100,300,448);
	settextstyle(3,0,1);
	outtextxy(10,155,"OLD USERNAME:");
	setfillstyle(1,0);
	bar(145,155,290,183);
	ifstream Ifile("TURTLE0.DAT",ios::out||ios::binary);
	Ifile>>old_uname;
	outtextxy(148,155,old_uname);
	Ifile.close();
	outtextxy(10,200,"NEW USERNAME:");
	bar(145,200,290,228);
	bar(80,350,230,400);
	outtextxy(120,360,"CONFIRM");
	do
	{
		window(20,14,40,25);
		cout<<"                ";
		window(20,14,40,25);
		gets(new_uname);
		res=valid_name(new_uname);
	}while(res);
	do
	{
		opt=getch();
		switch(opt)
		{
			case 13:
				remove("TURTLE0.DAT");
				ofstream Ofile("TURTLE0.DAT",ios::out||ios::binary);
				Ofile<<new_uname;
				Ofile.close();
				void accountpage();
				accountpage();
				break;
			case 27:
				exit(0);
				break;
		};
	}while(1);
}
//check whether the password is valid
int valid_pass(char pass[20])
{
	int res1,res2;
	if(strlen(pass)<8||strlen(pass)>20)
		res1=1;
	else
		res1=0;
	for(int i=0;i<strlen(pass);i++)
	{
		if(pass[i]==' '||pass[i]==27)
		{
			res2=1;
			break;
		}
		else
			res2=0;
	}
	if(res1||res2)
		return 1;
	else
		return 0;
}
void nw_paswrd()
{
	void accountpage();
	int res,opt,contd;
	char pass[20],old_pass[20],new_pass[20];
	setfillstyle(1,3);
	bar(0,100,300,448);
	settextstyle(3,0,1);
	outtextxy(10,155,"OLD PASSWORD:");
	setfillstyle(1,0);
	bar(145,155,290,183);
	ifstream Ifile("TURTLE1.DAT",ios::out||ios::binary);
	Ifile>>old_pass;
	Ifile.close();
	outtextxy(10,200,"NEW PASSWORD:");
	bar(145,200,290,228);
	bar(80,350,230,400);
	outtextxy(120,360,"CONFIRM");
	window(20,11,40,25);
	gets(pass);
	contd=strcmp(pass,old_pass);
	if(!contd)
	{
		do
		{
			window(20,14,40,25);
			cout<<"                ";
			window(20,14,40,25);
			gets(new_pass);
			res=valid_name(new_pass);
		}while(res);
		do
		{
			opt=getch();
			switch(opt)
			{
				case 13:
					rectangle(79,349,231,405);
					remove("TURTLE1.DAT");
					ofstream Ofile("TURTLE1.DAT",ios::out||ios::binary);
					Ofile<<new_pass;
					Ofile.close();
					accountpage();
					break;
				case 27:
					exit(0);
					break;
			};
		}while(1);
	}
	else
	{
		settextstyle(2,0,4);
		outtextxy(10,300,"wrong password !!! do you want to continue:");
		outtextxy(10,310,"enter:retry        ESC:escape");
		opt=getch();
		switch(opt)
		{
			case 13:
				nw_paswrd();
				break;
			case 27:
				accountpage();
		};
	}
}
void accountpage()
{
	void settings();
	void nw_uname();
	void nw_paswrd();
	int opt;
	long int cord[2]={150,200},temp[1];
	temp[0]=cord[0];
	temp[1]=cord[1];
	setfillstyle(1,3);
	bar(0,50,300,448);
	settextstyle(2,0,10);
	outtextxy(60,50,"Accounts");
	settextstyle(3,0,2);
	outtextxy(10,160,"CHANGE USERNAME");
	outtextxy(10,210,"CHANGE PASSWORD");
	rectangle(0,150,300,200);
	do
	{
		opt=getch();
		switch(opt)
		{
			case 27:
				settings();
				break;
			case 80:
				setcolor(3);
				rectangle(0,temp[0],300,temp[1]);
				temp[0]+=50;
				temp[1]+=50;
				if(temp[0]>200)
				{
					setcolor(RED);
					temp[0]=150;
					temp[1]=200;
					rectangle(0,temp[0],300,temp[1]);
				}
				else
				{
					setcolor(RED);
					rectangle(0,temp[0],300,temp[1]);
				}
				break;
			case 72:
				setcolor(3);
				rectangle(0,temp[0],300,temp[1]);
				temp[0]-=50;
				temp[1]-=50;
				if(temp[0]<150)
				{
					setcolor(RED);
					temp[0]=200;
					temp[1]=250;
					rectangle(0,temp[0],300,temp[1]);
				}
				else
				{
					setcolor(RED);
					rectangle(0,temp[0],300,temp[1]);
				}
				break;
			case 13:
				if(temp[0]==150)
					nw_uname();
				else
					nw_paswrd();
		}
	}while(1);
}
/********************************FEEDBACK***********************************/
void feedback()
{
	void settings();
	do
	{
		int score=0,opt;
		setfillstyle(1,3);
		bar(0,50,300,448);
		setcolor(10);
		settextstyle(2,0,10);
		outtextxy(60,60,"FEEDBACK");
		settextstyle(0,0,1);
		setcolor(0);
		outtextxy(1,150,"how likely are you to recommend this");
		outtextxy(1,160,"to a friend or colleague?");
		outtextxy(1,200,"9:extremely likely    0:not likely");
		outtextxy(1,260,"SCORE:");
		setfillstyle(1,9);
		bar(80,380,230,400);
		setcolor(4);
		outtextxy(120,390,"SUBMIT");
		setfillstyle(1,0);
		bar(50,250,180,275);
		window(9,17,40,25);
		score=getch();
		if(((score-48)>=0)&&((score-48)<=10))
		{
			cout<<score-48;
			setcolor(4);
			rectangle(80,380,230,400);
			opt=getch();
			switch(opt)
			{
				case 27:
					settings();
					break;
				case 8:
					feedback();
					break;
				case 13:
					remove("TURTLE2.DAT");
					ofstream Ofile("TURTLE2.DAT",ios::out||ios::binary);
					Ofile<<score;
					Ofile.close();
					settings();
					break;
			};
		}
		else if(score==27)
			settings();
		else
			feedback();
	}while(1);
}
/*******************************RESET************************************/
void reset()
{
	void settings();
	int opt;
	setfillstyle(1,3);
	bar(0,50,300,448);
	settextstyle(2,0,6);
	outtextxy(10,80,"are you sure?");
	outtextxy(10,110,"enter:continue     esc:exit");
	do
	{
		opt=getch();
		switch(opt)
		{
			case 13:
				int contd;
				char pass[20],paswrd[20];
				ifstream Ifile("TURTLE1.DAT",ios::out||ios::binary);
				Ifile>>pass;
				Ifile.close();
				bar(0,50,300,448);
				outtextxy(10,205,"PASSWORD:");
				setfillstyle(0,0);
				bar(95,205,260,225);
				window(13,14,40,25);
				gets(paswrd);
				contd=strcmp(paswrd,pass);
				if(!contd)
				{
				remove("TURTLE0.DAT");
				remove("TURTLE1.DAT");
				setfillstyle(9,9);
				bar(100,160,360,180);
				for(int i=110;i<=350;i++)
				{
					outtextxy(120,180,"removing...");
					setfillstyle(1,0);
					bar(110,168,i,172);
					delay(120);
				}
				getch();
				exit(0);
				}
				else
				{
					settextstyle(2,0,4);
					outtextxy(10,300,"wrong password !!! do you want to continue:");
					outtextxy(10,310,"enter:retry        ESC:escape");
					opt=getch();
					switch(opt)
					{
						case 13:
							reset();
							break;
						case 27:
							settings();
					};
				}
				break;
			case 27:
				settings();
				break;
		};
	}while(1);
}
/*****************************-system information-**************************/
void sysinfo()
{
	void proc(int);
	setfillstyle(1,3);
	bar(0,50,300,448);
	setcolor(0);
	settextstyle(2,0,7);
	setfillstyle(1,3);
	outtextxy(30,70,"software information");
	outtextxy(30,120,"help");
	outtextxy(30,170,"credits");
	outtextxy(30,220,"next version");
	proc(1);
	getch();
}
void softinfo()
{
	setfillstyle(1,3);
	bar(0,50,300,448);
	settextstyle(1,0,5);
	setcolor(0);
	outtextxy(70,150,"TURTLE");
	settextstyle(2,0,5);
	outtextxy(10,250,"version 1.0");
	getch();
	sysinfo();
}
void help()
{
	setfillstyle(1,3);
	bar(0,50,300,448);
	settextstyle(7,0,3);
	setcolor(9);
	outtextxy(100,100,"HELP");
	settextstyle(2,0,5);
	outtextxy(10,150,"for help: contact geojollyc@gmail.com");
	getch();
	sysinfo();
}
void credits()
{
	int i=200;//i is varying coordinate of a text
	setfillstyle(1,3);
	bar(0,50,300,448);
	setcolor(9);
	outtextxy(100,100,"CREDITS");
	do
	{
		setcolor(i);
		setfillstyle(0,0);
		bar(30,150,270,420);
		settextstyle(7,0,3);
		outtextxy(100,i,"THANKS");
		settextstyle(2,0,5);
		setcolor(i+20);
		outtextxy(50,i+30," GAUTAM SIR");
		outtextxy(50,i+45," MARYGIRI SCHOOL");
		outtextxy(50,i+60," PARENTS");
		outtextxy(50,i+75," FRIENDS");
		if(i>320)
			i=150;
		else
			i=i+5;
		delay(100);
	}while(!kbhit());
	getch();
	sysinfo();
}
void comingsoon()
{
	setfillstyle(1,3);
	bar(0,50,300,448);
	setfillstyle(1,9);
	setcolor(9);
	pieslice(150,280,0,360,150);
	setcolor(5);
	settextstyle(9,0,1);
	outtextxy(50,70,"NEXT VERSION");
	settextstyle(2,0,5);
	setcolor(0);
	outtextxy(85,140,"#improved security");
	outtextxy(85,160,"#improved graphics");
	outtextxy(85,180,"#improved clock");
	outtextxy(85,200,"#improved date facilities");
	outtextxy(85,220,"#increased applications");
	outtextxy(85,240,"#display time");
	int col=1;//color for text
	do
	{
		setfillstyle(1,0);
		bar(72,300,200,330);
		if(col>10)
			col=1;
		else
			col++;
		setcolor(col);
		outtextxy(95,300,"version 2.0");
		outtextxy(80,310,"...coming soon...");
		delay(100);
		}while(!kbhit());
	getch();
	sysinfo();
}
/*******************************process***********************************/
void proc(int a)
{
	void settings(),home_turtle();
	int i;
	long int cord[4]={250,100,200,50},temp[1];//coordinates
	int opt;
	temp[0]=cord[1];
	temp[1]=cord[3];
	setcolor(RED);
	rectangle(300,temp[0],0,temp[1]);
	do
	{
		opt=getch();
		switch(opt)
		{
			case 72:
				setcolor(3);
				rectangle(300,temp[0],0,temp[1]);
				temp[0]-=50;
				temp[1]-=50;
				if(temp[1]<50)
				{
					temp[0]=250;
					temp[1]=200;
					setcolor(RED);
					rectangle(300,temp[0],0,temp[1]);
				}
				else
				{
					setcolor(RED);
					rectangle(300,temp[0],0,temp[1]);
				}
				break;
			case 80:
				setcolor(3);
				rectangle(300,temp[0],0,temp[1]);
				temp[0]+=50;
				temp[1]+=50;
				if(temp[0]>250)
				{
					temp[0]=cord[1];
					temp[1]=cord[3];
					setcolor(RED);
					rectangle(300,temp[0],0,temp[1]);
				}
				else
				{
					setcolor(RED);
					rectangle(300,temp[0],0,temp[1]);
				}
				break;
			case 13:
				switch(a)
				{
				case 0:
					if(temp[0]==100)
						accountpage();
					else if(temp[0]==150)
						feedback();
					else if(temp[0]==200)
						reset();
					else
						sysinfo();
					break;
				case 1:
					if(temp[0]==100)
						softinfo();
					else if(temp[0]==150)
						help();
					else if(temp[0]==200)
						credits();
					else
						comingsoon();
					break;
				};
			case 27:
				if(!a)
					home_turtle();
				else
					settings();
		};
	}while(1);
}
void settings()
{
	int poly[8]={230,125,250,105,270,125,230,125};
	char up[2]={24},down[2]={25},enter[2]={28};
	setfillstyle(9,DARKGRAY);
	bar(700,600,0,30);
	settextstyle(3,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(260,0,"settings");
	setfillstyle(XHATCH_FILL,DARKGRAY);
	bar(700,50,0,30);
	setfillstyle(1,3);
	bar(300,100,0,50);
	setcolor(0);
	outtextxy(30,60,"ACCOUNTS");
	setcolor(WHITE);
	circle(250,70,12);
	circle(250,97,15);
	setfillstyle(1,3);
	bar(300,150,0,100);
	setcolor(0);
	outtextxy(30,110,"FEEDBACK");
	setfillstyle(1,WHITE);
	bar(230,145,270,125);
	fillpoly(4,poly);
	setcolor(0);
	line(230,126,270,126);
	setfillstyle(1,1000);
	bar(245,145,255,135);
	setfillstyle(1,3);
	bar(300,200,0,150);
	outtextxy(30,160,"RESET");
	setcolor(WHITE);
	arc(250,175,160,120,20);
	line(241,160,243,162);
	line(241,160,243,153);
	line(250,175,250,160);
	line(250,175,235,180);
	setfillstyle(1,3);
	bar(300,450,0,200);
	setcolor(0);
	outtextxy(30,210,"SYSTEM INFO");
	setfillstyle(1,0);
	bar(240,210,260,240);
	setfillstyle(1,WHITE);
	bar(243,215,257,237);
	settextstyle(1,0,1);
	setcolor(4);
	outtextxy(248,215,"i");
	setfillstyle(11,DARKGRAY);
	bar(700,50,300,448);
	settextstyle(8,0,5);
	setcolor(WHITE);
	outtextxy(390,120,"TURTLE");
	circle(570,130,7);
	settextstyle(0,0,1);
	outtextxy(567,126,"c");
	outtextxy(150,460,"version 1.0  COPYRIGHT (C) 2019 TURTLE.INC");
	setfillstyle(1,WHITE);
	bar(301,50,300,450);
	bar(700,449,0,450);
	bar(700,251,300,250);
	setcolor(6);
	settextstyle(0,0,1);
	outtextxy(310,280,up);
	outtextxy(310,310,down);
	outtextxy(310,340,enter);
	outtextxy(310,370,"ESC");
	outtextxy(340,280,":right");
	outtextxy(340,310,":down");
	outtextxy(340,340,":select");
	outtextxy(340,370,":back");
	proc(0);
}
////////////////////////////////sleep function////////////////////////////
void sleeper()
{
	void home_turtle();
	do
	{
		int time;
		setfillstyle(1,0);
		bar(0,0,700,700);
		setcolor(5);
		outtextxy(200,100,"sleep for(s):");
		window(48,8,80,25);
		cin>>time;
		setfillstyle(1,9);
		bar(0,0,700,700);
		settextstyle(2,0,7);
		for (int i=1; i<=time; i++)
		{
			window(30,12,40,25);
			printf("Sleeping for %d seconds\n", i);
			sleep(i);
		}
		break;
	}while(1);
	home_turtle();
}
///////////////////////////restart&shutdown/////////////////////////////////
void res_shut_design(int opt)
{
	for(int i=0;i<3;i++)
	{
		cleardevice();
		setfillstyle(1,WHITE);
		fillellipse(380,300,15,15);
		delay(500);
		fillellipse(320,350,15,15);
		delay(500);
		fillellipse(260,300,15,15);
		delay(500);
		fillellipse(320,250,15,15);
		delay(500);
		cleardevice();
		delay(500);
	}
	switch(opt)
	{
		case 6:
			turtle();
			break;
		case 7:
			exit(0);
			break;
	};
}
/////////////////////home functions/////////////////////////////////////
void homebkgrd(int opt)
{
	char *application[]={"doc writer","doc read","calculator","date &time"," settings","  sleep"," restart"," shutdown"};
	setcolor(14);
	setfillstyle(11,11);
	fillellipse(320,250,150,150);
	setfillstyle(9,5);
	settextstyle(2,0,8);
	outtextxy(255,290,application[opt]);
	switch(opt)
	{
		case 0:
			int doctriangle[8]={340,160,360,160,360,180,340,160};
			setfillstyle(0,0);
			bar(279,159,361,271);
			setfillstyle(1,WHITE);
			bar(280,160,360,270);
			setcolor(0);
			rectangle(340,160,360,180);
			line(340,160,360,180);
			setfillstyle(11,11);
			fillpoly(3,doctriangle);
			setcolor(RED);
			line(285,202,320,202);
			line(285,210,320,210);
			line(285,218,320,218);
			line(285,226,320,226);
			line(285,234,320,234);
			line(285,242,320,242);
			setcolor(0);
			rectangle(325,185,355,260);
			break;
		case 1:
			setfillstyle(1,WHITE);
			bar(280,160,360,270);
			setcolor(1);
			outtextxy(290,170,"A ");
			line(310,194,355,194);
			line(285,205,355,205);
			setfillstyle(11,1);
			bar(325,215,355,235);
			setcolor(RED);
			line(285,218,320,218);
			line(285,226,320,226);
			line(285,233,320,233);
			setcolor(0);
			line(285,250,355,250);
			line(285,242,355,242);
			settextstyle(2,0,5);
			outtextxy(320,255,"1");
			break;
		case 2:
			setfillstyle(0,0);
			bar(277,157,363,278);
			bar(285,165,355,180);
			setfillstyle(1,LIGHTGRAY);
			bar(280,160,360,275);
			setfillstyle(0,0);
			bar(285,165,355,190);
			bar(285,200,305,220);
			bar(310,200,330,220);
			bar(335,200,355,220);
			bar(285,225,305,245);
			bar(310,225,330,245);
			bar(335,225,355,245);
			bar(285,250,305,270);
			bar(310,250,330,270);
			bar(335,250,355,270);
			settextstyle(2,0,5);
			setcolor(WHITE);
			outtextxy(293,202,"1");
			outtextxy(318,202,"2");
			outtextxy(343,202,"3");
			outtextxy(293,227,"4");
			outtextxy(318,227,"5");
			outtextxy(343,227,"6");
			outtextxy(293,252,"7");
			outtextxy(318,252,"8");
			outtextxy(343,252,"9");
			outtextxy(290,170,"112+33");
			break;
		case 3:
			setfillstyle(1,0);
			bar(270,180,380,265);
			setfillstyle(1,WHITE);
			bar(275,185,375,200);
			bar(275,207,375,260);
			setfillstyle(1,0);
			bar(280,173,287,195);
			bar(370,173,363,195);
			setcolor(0);
			setfillstyle(1,0);
			bar(280,212,370,255);
			fillellipse(370,255,35,35);
			setcolor(WHITE);
			setfillstyle(1,WHITE);
			bar(295,207,305,260);
			bar(320,207,330,260);
			bar(345,207,355,223);
			bar(280,222,375,227);
			bar(280,239,375,243);
			bar(280,212,300,222);
			setfillstyle(1,0);
			setcolor(0);
			fillellipse(370,255,35,35);
			setcolor(WHITE);
			setfillstyle(1,WHITE);
			fillellipse(370,255,30,30);
			setfillstyle(1,0);
			bar(368,255,373,238);
			bar(368,257,385,252);
			break;
		case 4:
			int setbar1[10]={295,207,307,195,357,240,344,252,295,207}
			,setbar2[10]={340,193,357,207,294,236,309,252,344,207};
			setfillstyle(1,5);
			bar(270,180,380,265);
			setfillstyle(1,WHITE);
			bar(318,190,332,255);
			bar(290,215,360,228);
			fillpoly(4,setbar1);
			fillpoly(4,setbar2);
			fillellipse(325,222,25,25);
			setfillstyle(1,5);
			fillellipse(325,222,12,12);
			break;
		case 5:
			setcolor(0);
			setfillstyle(1,14);
			fillellipse(320,222,35,35);
			setfillstyle(11,11);
			fillellipse(317,200,40,40);
			bar(260,160,370,218);
			break;
		case 6:
			setcolor(WHITE);
			arc(320,222,155,135,40);
			setfillstyle(1,WHITE);
			line(270,228,282,205);
			line(292,228,282,205);
			break;
		case 7:
			setfillstyle(1,0);
			setcolor(0);
			fillellipse(320,222,35,35);
			setfillstyle(11,11);
			fillellipse(320,222,30,30);
			setfillstyle(1,0);
			bar(318,205,322,175);
			break;
		case 8:
			setfillstyle(11,11);
			fillellipse(320,250,150,150);
			setcolor(9);
			settextstyle(4,0,7);
			outtextxy(300,222,"P");
			settextstyle(3,0,4);
			outtextxy(270,300,"parrot");
			break;
	};
}
void home_proc()
{
	static int app=0;
	void main2();
	int opt;
	homebkgrd(app);
	opt=getch();
	do
	{
		switch(opt)
		{
			case 75:
				if(app>0)
					--app;
				else
					app=8;
				break;
			case 77:
				if(app<8)
					++app;
				else
					app=0;
				break;
			case 13:
				switch(app)
				{
					case 0:
						doc_write();
						break;
					case 1:
						doc_reader();
						break;
					case 2:
						calc();
						break;
					case 3:
						calendar_proc();
						break;
					case 4:
						settings();
						break;
					case 5:
						sleeper();
						break;
					case 6:
						app=0;
						res_shut_design(6);
						break;
					case 7:
						res_shut_design(7);
						break;
					case 8:
						showptr();
						main2();
						break;
				};
		};
		homebkgrd(app);
		opt=getch();
	}while(1);
}
void home_turtle()
{
	int arrow1[8]={580,250,580,230,600,240,580,250},arrow2[8]={30,250,30,230,10,240,30,250};
	clearviewport();
	setbkcolor(0);
	setfillstyle(11,DARKGRAY);
	bar(0,0,700,700);
	setcolor(5);
	settextstyle(2,0,10);
	outtextxy(245,20,"TURTLE");
	setcolor(14);
	setfillstyle(11,11);
	fillellipse(320,250,150,150);
	setfillstyle(9,5);
	fillpoly(4,arrow1);
	fillpoly(4,arrow2);
	home_proc();
	getch();
	exit(0);
}
void setting()
{
	design_settings();
}
void doc_w()
{
	hideptr();
	void main2();
	int line=0,opt;
	bar(0,0,700,700);
	char usertext[80],filename[8];
	setfillstyle(9,DARKGRAY);
	bar(700,600,0,30);
	settextstyle(3,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(230,0,"document writer");
	setfillstyle(1,8);
	bar(0,50,700,448);
	settextstyle(2,0,7);
	outtextxy(10,203,"FILENAME:");
	settextstyle(2,0,4);
	window(15,14,40,25);
	gets(filename);
	setfillstyle(0,0);
	bar(0,50,799,448);
	setfillstyle(11,DARKGRAY);
	window(1,7,80,25);
	for(int i=0;i<700;i++)
	{
		if(line<=80)
		{
			line++;
			usertext[i]=getch();
		}
		else
		{
			line=1;
			usertext[i]='\n';
		}
		if(usertext[i]==27)
		{
			ofstream Ofile(filename,ios::out||ios::binary);
			Ofile<<usertext;
			Ofile.close();
			break;
		}
		else if(usertext[i]==9)
			break;
		else if(usertext[i]==13)
		{
			line=1;
			usertext[i]='\n';
			cout<<usertext[i];
		}
		else if(usertext[i]==8)
		{
			line-=2;
			i-=1;
			int x=wherex();
			int y=wherey();
			gotoxy(x=x-1,y);
			cout<<'\0';
			gotoxy(x,y);
		}
		else
			cout<<usertext[i];
	}
	setfillstyle(0,0);
	bar(0,50,799,448);
	outtextxy(410,310,"press enter to write a new file");
	outtextxy(450,340,"press esc to exit");
	settextstyle(2,0,7);
	outtextxy(150,240,"FILE SAVED");
	opt=getch();
	switch(opt)
	{
		case 13:
			doc_w();
			break;
		case 27:
			main2();
			break;
	};
}
////////////////////////////////doc reader///////////////////////////////////
void doc_r()
{
	hideptr();
	void main2();
	int line,opt;
	bar(0,0,700,700);
	char usertext[80],filename[20];
	setfillstyle(9,DARKGRAY);
	bar(700,600,0,30);
	settextstyle(3,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(230,0,"document reader");
	setfillstyle(XHATCH_FILL,5);
	bar(700,50,0,30);
	setfillstyle(11,DARKGRAY);
	bar(700,50,0,448);
	settextstyle(8,0,5);
	setcolor(WHITE);
	bar(0,50,799,448);
	settextstyle(2,0,7);
	outtextxy(10,203,"FILENAME:");
	window(15,14,40,25);
	gets(filename);
	strupr(filename);
	ifstream Ifilecheck(filename,ios::nocreate);
	if(!Ifilecheck)
	{
		setfillstyle(0,0);
		bar(0,50,700,448);
		outtextxy(100,203,"FILE DOES NOT EXIST");
		outtextxy(40,300,"press enter-retry   esc-escape");
		opt=getch();
		switch(opt)
		{
			case 13:
				doc_r();
				break;
			case 27:
				main2();
				break;
		};
	}
	Ifilecheck.close();
	ifstream Ifile(filename,ios::in||ios::binary);
	do
	{
		Ifile.getline(usertext,80);
		setfillstyle(0,0);
		bar(0,50,700,448);
		window(1,6,80,25);
		for(int i=0;i<=strlen(usertext);i++)
		{
			if(i%80==0&&i!=0)
				cout<<"\n";
			else
				cout<<usertext[i];
		}
	}while(!Ifile.eof());
	getch();
	setfillstyle(0,0);
	bar(0,50,799,448);
	settextstyle(2,0,5);
	setcolor(14);
	outtextxy(410,310,"press enter to read a new file");
	outtextxy(450,340,"press esc to exit");
	settextstyle(2,0,7);
	Ifile.close();
	outtextxy(150,240,"FILE READ");
	opt=getch();
	switch(opt)
	{
		case 13:
			doc_r();
			break;
		case 27:
			main2();
			break;
	};
}
////////end of settings//////////////////
////apps///////////////
void shutdown()
{
	cleardevice();
	void rotate_design();
	rotate_design();
	exit(1);
}
void restart()
{
	void main(),rotate_design();
	cleardevice();
	rotate_design();
	closegraph();
	main();
}
void sleep()
{
	void main2();
	cleardevice();
	while(!kbhit())
	{
	}
	closegraph();
	main2();
}
//////////////////////////main process//////////////////////////
void screen_clear()
{
	void main2();
	cleardevice();
	closegraph();
	main2();
}
void rotate_design()
{
	for(int rotate=0;rotate<=1000;rotate++)
	{
		setcolor(9);
		arc(300,400,0+rotate,140+rotate,15);
		setcolor(3);
		arc(300,400,-10-rotate,130-rotate,15);
		setcolor(1);
		arc(300,400,0+rotate,140+rotate,12);
		setcolor(RED);
		arc(300,400,-10-rotate,130-rotate,12);
		delay(1);
		cleardevice();
	}
}
void bar_action(int ypos)
{
	if(ypos>280&&ypos<300)
	{
		shutdown();
	}
	else if(ypos>260&&ypos<280)
	{
		restart();
	}
	else if(ypos>240&&ypos<260)
	{
		sleep();
	}
	else if(ypos>180&&ypos<200)
	{
		calculator();
	}
	else if(ypos>160&&ypos<180)
	{
		calendar();
	}
	else if(ypos>120&&ypos<140)
	{
		pingpong();
	}
	else if(ypos>220&&ypos<240)
	{
		setting();
	}
	else if(ypos>20&&ypos<40)
	{
		doc_r();
	}
	else if(ypos>40&&ypos<60)
	{
		doc_w();
	}
	else if(ypos>80&&ypos<100)
	{
		turtle();
	}

}
void cord_action(int xpos,int ypos)
{
	variables temp_var(200,300);
	setfillstyle(1,8);
	if(::clicker==0)
	{
		if((xpos>0&&xpos<71)&&(ypos>0&&ypos<21))
		{
			::clicker=1;
			bar_design();
		}
	}
	else
	{
		if((xpos>0&&xpos<130)&&(ypos>21&&ypos<300))
			bar_action(ypos);
		else
		{
			mouseposi(temp_var.xtemp,temp_var.ytemp,temp_var.temp1);
			setposi(temp_var.x,temp_var.y);
			setfillstyle(1,9);
			bar(0,21,130,300);
			setposi(temp_var.xtemp,temp_var.ytemp);
			::clicker=0;
		}
	}
}
void time()
{
	time_t rtime;
	struct tm*currentTime;
	char a[10];
	setfillstyle(1,7);
	bar(300,0,720,20);
	rtime=time(0);
	currentTime=localtime(&rtime);
	strftime(a,40,"%I:%M:%S",currentTime);
	settextstyle(2,0,5);
	setcolor(0);
	outtextxy(580,3,a);
	setcolor(BLACK);
	delay(10);
}
void home_proc1()
{
	variables temp_var(300,200);
	setposi(temp_var.x,temp_var.y);
	int xpos,ypos,click;
	do
	{
		mouseposi(xpos,ypos,click);
		if(click==1)
			cord_action(xpos,ypos);
		delay(150);
		state=1;
		time();
	}
	while(1);
}
void home()
{
	callmouse();
	variables temp_var(1000,1000);
	setposi(temp_var.x,temp_var.y);
	design();
}
void main2()
{
	cleardevice();
	callmouse();
	variables temp_var(1000,1000);
	setposi(temp_var.x,temp_var.y);
	design();
}
////////////////////////////////////////////////////////////////////////
void loading()
{
	cleardevice();
	setfillstyle(9,1);
	bar(80,403,500,418);
	settextstyle(1,0,2);
	setcolor(9);
	outtextxy(270,375,"loading...");
	for(int i=83;i<497;i++)
	{
		setfillstyle(5,10);
		bar(83,406,i,415);
		delay(5);
	}
}
void pixelise_adm(int dots,int mode)
{
	randomize();
	for(int dot=0;dot<=dots;dot++)
	{
		if(mode==1)
			putpixel(random(1000),random(1000),random(15));
		else
		{
			putpixel(random(228),random(1200),random(15));
			putpixel(random(3000),random(120),random(15));
			putpixel(392+random(392),random(1000),random(15));
		}
	}
}
void smalllogo()
{
	fillellipse(300,80,40,40);
	setfillstyle(10,9);
	fillellipse(300,80,41,41);
	settextstyle(4,0,6);
	setcolor(3);
	outtextxy(287,35,"P");
}
void adm_create_background()
{
	hideptr();
	setfillstyle(1,9);
	bar(170,160,450,185);
	settextstyle(6,0,2);
	setcolor(0);
	outtextxy(270,153,"c r e a t e");
	setfillstyle(1,15);
	bar(170,360,450,185);
	setcolor(0);
	outtextxy(185,200,"USER:");
	outtextxy(185,250,"PASS:");
	setfillstyle(1,0);
	bar(240,208,440,225);
	bar(241,256,440,273);
	setfillstyle(1,15);
	setfillstyle(1,10);
	bar(280,300,380,330);
	settextstyle(6,0,3);
	setcolor(9);
	outtextxy(295,295,"CREATE");
	showptr();
}
void adminbar_create()
{
	pixelise_adm(90000,1);
	smalllogo();
	adm_create_background();
}
void highlight(int col,int w,int x,int y,int z)
{
	setcolor(col);
	rectangle(w,x,y,z);
	rectangle(w+1,x+1,y-1,z-1);
	rectangle(w+2,x+2,y-2,z-2);
}
void admin_process_create(data user)
{
	ofstream file;
	file.open("USER.DAT",ios::out|ios::binary|ios::ate);
	file.write((char *)&user,sizeof(data));
	file.close();
	loading();
	home();
}
void cord_action_create(int xpos,int ypos)
{
	gotoxy(1,1);
	data user;
	int temppos[]={xpos+1000,ypos+1000};
	static int tempcord[4]={0,0,0,0};
	setposi(temppos[0],temppos[1]);
	if((xpos>=280&&xpos<=380)&&(ypos>=300&&ypos<=330))
	{
		highlight(15,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
		tempcord[0]=280;
		tempcord[1]=300;
		tempcord[2]=380;
		tempcord[3]=330;
		highlight(4,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
		strcpy(user.name,name);
		strcpy(user.pass,pass);
		if((strlen(user.name)>0)&&(strlen(user.pass)>0))
			admin_process_create(user);
	}
	else if((xpos>=240&&xpos<=440)&&(ypos>=195&&ypos<=225))
	{
		if(tempcord[0]==280)
			highlight(10,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
		else
			highlight(15,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
		strcpy(user.name,NULL);
		tempcord[0]=240;
		tempcord[1]=205;
		tempcord[2]=440;
		tempcord[3]=227;
		highlight(4,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
		gotoxy(32,14);
		gets(name);
	}
	else if((xpos>=241&&xpos<=440)&&(ypos>=255&&ypos<=285))
	{
		if(tempcord[0]==280)
			highlight(10,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
		else
			highlight(15,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
		strcpy(user.pass,NULL);
		tempcord[0]=241;
		tempcord[1]=253;
		tempcord[2]=440;
		tempcord[3]=275;
		highlight(4,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
		gotoxy(32,17);
		gets(pass);
	}
	else
	{
		highlight(15,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
	}
	setposi(xpos,ypos);
}
void admin_proc_create()
{
	showptr();
	do
	{
		int xpos,ypos,click;
		mouseposi(xpos,ypos,click);
		if(click==1)
			cord_action_create(xpos,ypos);
		delay(100);
	}
	while(1);
}
////////////////////////////////////////////////////
//////////////////////////////////////////
void adm_login_background()
{
	setfillstyle(1,9);
	bar(170,160,450,185);
	settextstyle(6,0,2);
	setcolor(0);
	outtextxy(270,153,"l o g i n");
	setfillstyle(1,15);
	bar(170,360,450,185);
	setcolor(0);
	settextstyle(6,0,1);
	outtextxy(185,200,"USER:");
	outtextxy(185,250,"PASS:");
	setfillstyle(1,0);
	bar(240,208,440,225);
	bar(241,256,440,273);
	setfillstyle(1,15);
	setfillstyle(1,10);
	bar(280,300,380,330);
	settextstyle(2,0,8);
	setcolor(9);
	outtextxy(282,298," LOGIN");
}
void adminbar_login()
{
	pixelise_adm(90000,1);
	smalllogo();
	adm_login_background();
}
void admin_process_login(data user)
{
	void process();
	ifstream ifile;
	data temp;
	ifile.open("USER.DAT",ios::in|ios::binary);
	while(!ifile.eof())
	{
		ifile.read((char *)&temp,sizeof(data));
		if(!strcmp(temp.name,user.name)&&!strcmp(temp.pass,user.pass))
		{
			loading();
			home();
		}
	}
	cleardevice();
	process();
}
void cord_action_login(int xpos,int ypos)
{
	gotoxy(1,1);
	static data user;
	int temppos[]={xpos+1000,ypos+1000};
	static int tempcord[4]={0,0,0,0};
	setposi(temppos[0],temppos[1]);
	if((xpos>=280&&xpos<=380)&&(ypos>=300&&ypos<=330))
	{
		highlight(15,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
		tempcord[0]=280;
		tempcord[1]=300;
		tempcord[2]=380;
		tempcord[3]=330;
		highlight(4,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
		if((strlen(user.name)>0)&&(strlen(user.pass)>0))
			admin_process_login(user);
	}
	else if((xpos>=240&&xpos<=440)&&(ypos>=195&&ypos<=225))
	{
		if(tempcord[0]==280)
			highlight(10,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
		else
			highlight(15,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
		strcpy(user.name,NULL);
		tempcord[0]=240;
		tempcord[1]=205;
		tempcord[2]=440;
		tempcord[3]=227;
		highlight(4,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
		gotoxy(32,14);
		gets(user.name);
	}
	else if((xpos>=241&&xpos<=440)&&(ypos>=255&&ypos<=285))
	{
		if(tempcord[0]==280)
			highlight(10,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
		else
			highlight(15,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
		strcpy(user.pass,NULL);
		tempcord[0]=241;
		tempcord[1]=253;
		tempcord[2]=440;
		tempcord[3]=275;
		highlight(4,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
		gotoxy(32,17);
		gets(user.pass);
	}
	else
	{
		highlight(15,tempcord[0],tempcord[1],tempcord[2],tempcord[3]);
	}
	setposi(xpos,ypos);
}
void admin_proc_login()
{
	do
	{
		int xpos,ypos,click;
		mouseposi(xpos,ypos,click);
		if(click==1)
			cord_action_login(xpos,ypos);
		delay(100);
	}
	while(1);
}
void process()
{
	int x=300,y=300;
	void admin_proc_login();
	cleardevice();
	delay(2000);
	ifstream ifile;
	ifile.open("USER.DAT",ios::binary|ios::noreplace);
	if(!ifile)
	{
		adminbar_create();
		setposi(x,y);
		callmouse();
		admin_proc_create();
	}
	else
	{
		adminbar_login();
		setposi(x,y);
		callmouse();
		admin_proc_login();
	}
}
///////////////////////////////////////start////////////////////////////
void main()
{
	clrscr();
	mod=1;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:/turboc3/bgi");
	design_startup();
	process();
	getch();
}