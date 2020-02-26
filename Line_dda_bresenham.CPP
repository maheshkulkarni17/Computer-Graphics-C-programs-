#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void dda(int ,int ,int ,int );
void bresenham(int ,int ,int ,int );
void main()
{
clrscr();
int ch,x1,x2,y1,y2,gm,dx,dy,gd=DETECT;
initgraph(&gd,&gm,"C:/TurboC3/BGI");
printf("Enter coordinates of start pt: ");
scanf("%d %d",&x1,&y1);
printf("Enter coordinates of  End Pt: ");
scanf("%d %d",&x2,&y2);
printf("--Select Algorithm--");
printf("\nPress 1: DDA \tPress 2: Bresenham");
printf("\nEnter your choice: ");
scanf("%d",&ch);
switch(ch)
  {
	case 1:
		 dda(x1,y1,x2,y2);
		 break;
	  case 2:
		 bresenham(x1,y1,x2,y2);
		 break;
  }
setcolor(5);
line(x1,y1+5,x2,y2+5);
getch();
}///////////main ends

void dda(int x1,int y1,int x2,int y2)
{
int temp,dy,dx;
float m,x,y;
dx=x2-x1;
dy=y2-y1;
m=(float)dy/dx;
x=x1;
y=y1;
if(x2<x1)
{
temp=x1;
x1=x2;
x2=temp;

temp=y1;
y1=y2;
y2=temp;
}

if(abs(dx)>abs(dy))
 {
 while(x1<=x2)
	{
	putpixel(x1,y1,14);
	x1++;
	y=y+m;
	y1=y+0.5;
	}
 }
 else
 {
	while(y1<=y2)
	{
		 putpixel(x1,y1,14);
		y1++;
		x=x+(1/m);
		x1=x+0.5;
	}

 }
}

void bresenham(int x1,int y1,int x2,int y2)
{
 int g,dy,dx,temp;
 if(x2<x1)
{
temp=x1;
x1=x2;
x2=temp;

temp=y1;
y1=y2;
y2=temp;

}
dx=x2-x1;
dy=y2-y1;


g=2*dy-dx;
if(abs(dx)>abs(dy))
 {
while(x1<=x2)
  {
  putpixel(x1,y1,14);
    if(g>=0)
    {
    y1++;
    g=g+2*dy-2*dx;
    }
    else
    {
    g=g+2*dy;
    }
    x1++;
  }
}
else
{
while(y1<=y2)
  {
     putpixel(x1,y1,14);
     if(g>=0)
     {
       x1++;
       g=g+2*dx-2*dy;
      }
    else
     {
	 g=g+2*dx;
     }
	 y1++;
  }
 }
}
