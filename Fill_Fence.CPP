#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
//#include"Linef.c"
void bre(int x1,int y1,int x2,int y2);
int sign(float arg);
int arrx[15],arry[15],ver,index,mid;
int xmin,xmax;
void getdata()
{
  int i;
  printf("Enter the number of vertices  ");
  scanf("%d",&ver);

  for(i=0;i<ver;i++)
      {
       printf("Enter the vertex  ");
       scanf("%d%d",&arrx[i],&arry[i]);
       }
      cleardevice();
}
void draw()
{
  int i,j;
  for(i=0;i<ver;i++)
    {
      j=i+1;
      if(j==ver)
       j=0;
    bre(arrx[i],arry[i],arrx[j],arry[j]);
    }
    getch();
}
void minmax()
{
  int i;
  xmax=xmin=arrx[0];
  for(i=0;i<ver;i++)
  {
     if(arrx[i]<xmin)
      xmin=arrx[i];
     if(arrx[i]>xmax)
      xmax=arrx[i];
  }
}

void complement(int x,int y)
{
  int i,j=x+1;
  for(i=j;i<mid;i++)
  {
    if(getpixel(i,y)==0)
     putpixel(i,y,4);
    else if(getpixel(i,y)==4)
     putpixel(i,y,0);
  }
}
void complementb(int x,int y)
{
  int i,j=x-1;
  for(i=j;i>=mid;i--)
  {
    if(getpixel(i,y)==0)
     putpixel(i,y,1);
   else if(getpixel(i,y)==1)
     putpixel(i,y,0);
  }
}
void main()
{
   int gd,gm,x,y,count,c,i=0,d,k;
   float m,p;
   gd=DETECT;
   initgraph(&gd,&gm,"c:/turboc3/bgi");
   getdata();
   minmax();
   mid=(xmin+xmax)/2;
   draw();

   while(i<ver)
   {

      count=1;
      d=i+1;
      if(d==ver)
      d=0;
      if(arry[i]>arry[d])
	{ y=arry[d];
	 c=arry[i];
	 k=arrx[d];
	 }
      else
      {
	y=arry[i];
	c=arry[d];
	k=arrx[i];
	}

      m=(1.0*(arry[d]-arry[i]))/(arrx[d]-arrx[i]);
    while(y<c)
      {
	y++;
	x=k+(1.0*count)/m;
	count++;
	if(x<mid)
	complement(x,y);
	else
	complementb(x,y);
      }
    i++;
   }
   getch();
   delay(100);
}
int sign(float arg)
{
	if(arg<0)
	return -1;
	if(arg==0)
	return 0;
	if(arg>0)
	return 1;
}
void bre(int x1,int y1,int x2,int y2)
{
	int s1,s2,exchange,y,x,i;
	float dx,dy,g,temp;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	x=x1;
	y=y1;
	s1=sign(x2-x1);
	s2=sign(y2-y1);
	if(dy>dx)
	{
	temp=dx;
	dx=dy;
	dy=temp;
	exchange=1;
	}
	else
	exchange=0;
	g=2*dy-dx;
	i=1;
	while(i<=dx)
	{
	putpixel(x,y,YELLOW);
	delay(1);
	while(g>=0)
	{
	if(exchange==1)
	x=x+s1;
	else
	y=y+s2;
	g=g-2*dx;

	}
	if(exchange==1)
	 y=y+s2;
	 else
	 x=x+s1;
	 g=g+2*dy;
	 i++;
	 }
	 }



