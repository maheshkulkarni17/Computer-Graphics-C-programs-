#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int x1,y1,x2,y2,xmin,ymin,xmax,ymax;

void liang();
float max(float,float,float);
float min(float,float,float);

void main()
{
	int gd=0,gm;
	clrscr();
	printf("Enter the clipping region :\nXmin : ");
	scanf("%d",&xmin);
	printf("Ymin : ");
	scanf("%d",&ymin);
	printf("Xmax : ");
	scanf("%d",&xmax);
	printf("Ymax : ");
	scanf("%d",&ymax);
	printf("Enter the end points of line :\nx1 : ");
	scanf("%d",&x1);
	printf("y1 : ");
	scanf("%d",&y1);
	printf("x2 : ");
	scanf("%d",&x2);
	printf("y2 : ");
	scanf("%d",&y2);

	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	line(xmin,ymin,xmin,ymax);
	line(xmin,ymin,xmax,ymin);
	line(xmin,ymax,xmax,ymax);
	line(xmax,ymin,xmax,ymax);

	line(x1,y1,x2,y2);
	liang();
	getch();
}

void liang()
{
	int i,dx,dy,p[4],q[4],X1,X2,Y1,Y2;
	float t[4],T1,T2;
	dx=x2-x1;
	dy=y2-y1;
	p[0]=-dx;
	q[0]=x1-xmin;
	p[1]=dx;
	q[1]=xmax-x1;
	p[2]=-dy;
	q[2]=y1-ymin;
	p[3]=dy;
	q[3]=ymax-y1;

	for(i=0;i<4;i++)
	{
		if(p[i]!=0)
		{
			t[i]=(float)q[i]/p[i];
		}
		else
		{
			if(i==0 || i==2)
				t[i]=0;
			if(i==1 || i==3)
				t[i]=1;
		}
	}
	T1=max(t[0],t[2],0);
	T2=min(t[1],t[3],1);
	X1=x1+(int)((float)dx*T1);
	X2=x1+(int)((float)dx*T2);
	Y1=y1+(int)((float)dy*T1);
	Y2=y1+(int)((float)dy*T2);
	setcolor(4);
	line(X1,Y1,X2,Y2);
}

float max(float a,float b,float c)
{
	if(a>=b && a>=c)
		return a;
	if(b>=a && b>=c)
		return b;
	if(c>=a && c>=b)
		return c;
}

float min(float a,float b,float c)
{
	if(a<=b && a<=c)
		return a;
	if(b<=a && b<=c)
		return b;
	if(c<=a && c<=b)
		return c;
}