#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
void ddaLine(int x1,int y1,int x2,int y2)
{
    int dx=x2-x1,dy=y2-y1,steps;
    if(abs(dx)>abs(dy))
    steps=abs(dx);
    else
    steps=abs(dy);
    float xi,yi,x=x1,y=y1;
    xi=(float)dx/(float)steps;
    yi=(float)dy/(float)steps;
    for(int k=0;k<=steps;k++)
    {
	float a=0.5,b=0.5;
	if(dx<0)a=a*-1;
	if(dy<0)b=b*-1;
	putpixel(x+a,y+b,2);
	x=x+xi;
	y=y+yi;
    }
}
int main()
{
     int gd=0,gm;
     int x1=200,y1=100,x2=340,y2=180;
//     cin>>x1>>y1>>x2>>y2;
     initgraph(&gd,&gm,"..//bgi ");
     cleardevice();
     ddaLine(x1,y1,x2,y2);
     setcolor(15);
     line(200,101+5,340,181+5);
     getch();
     closegraph();
     return 0;
}