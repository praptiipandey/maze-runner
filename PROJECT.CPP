#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

void maze(int,int);

void main()
	{
		int gd=DETECT,gm,x,y;
		char ch=0;
		initgraph(&gd,&gm,"..\\bgi");

		setaspectratio(1600,1280);


		x=80,y=40;
		maze(x,y);
		ch=0;

		while(ch!=27)
			{
				ch=getch();
				if((x==80&&y==40)&&(ch!=80))
					{
						outtextxy(350,200,"Invalid Input!!!!");
						continue;
					}

				switch(ch)
					{
						case 72:       //up
							if(getpixel(x,y-10)==3)
								{
									outtextxy(350,200,"Invalid Input!!!!");
									continue;
								}
							else
								y-=10;
						break;

						case 80:    //down
							if(getpixel(x,y+10)==3)
								{
									outtextxy(350,200,"Invalid Input!!!!");
									continue;
								}
							else
								y+=10;
						break;

						case 77:		  //right
							if(getpixel(x+10,y)==3)
								{
									outtextxy(350,200,"Invalid Input!!!!");
									continue;
								}
							else
								x+=10;
						break;

						case 75:		//left
							if(getpixel(x-10,y)==3)
								{
									outtextxy(350,200,"Invalid Input!!!!");
									continue;
								}
							else
								x-=10;
						break;
					}

				cleardevice();
				maze(x,y);

				if(x==310)
					{

						outtextxy(350,200,"You Won!!!");
						break;
					}
			}


		outtextxy(250,250,"press any key to exit.");
		getch();
		closegraph();
	}


void maze(int x,int y)
	{
		setcolor(3);
		line(50,50,70,50);
		line(90,50,290,50);
		line(290,50,290,290);
		line(290,310,290,370);
		line(50,370,290,370);
		line(50,50,50,370);
		line(70,70,70,90);
		line(50,90,70,90);
		line(90,70,90,90);
		line(90,90,270,90);
		line(50,110,250,110);
		line(270,90,270,230);
		line(270,230,150,230);
		line(150,230,150,150);
		line(150,150,90,150);
		line(250,110,250,150);
		line(250,150,200,150);
		line(200,150,200,130);
		line(200,130,70,130);
		line(70,130,70,310);
		line(70,310,150,310);
		line(150,310,150,350);
		line(150,350,250,350);
		line(250,350,250,310);
		line(250,310,170,310);
		line(170,310,170,330);
		line(170,330,230,330);
		line(90,150,90,290);
		line(90,290,290,290);
		line(170,130,170,170);
		line(270,290,270,350);
		rectangle(170,170,250,210);
		line(70,50,70,30);
		line(90,50,90,30);
		line(290,290,310,290);
		line(290,310,310,310);
		setcolor(WHITE);
		outtextxy(65,15,"Entry");
		outtextxy(315,297,"Exit");
		setcolor(YELLOW);
		circle(x,y,3);
		setfillstyle(1,2);
		floodfill(x,y,14);
	}
