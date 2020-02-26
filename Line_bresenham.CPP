#include<conio.h>
#include<dos.h>
#include<iostream.h>
#include<stdio.h>
#include<math.h>
#include<graphics.h>
void bline(int x1,int y1,int x2,int y2)
{
    int dx=abs(x2-x1),dy=abs(y2-y1);
    int twody=2*dy,twodyminusdx=2*(dy-dx),twodx=2*dx,twodxminusdy=2*(dx-dy);
    float m=(float)(y2-y1)/(float)(x2-x1);
    if(m<0 && m>-1)
    {
	int p=twody-dx,x,y;
	if(x1>x2)
	{
	    x=x2;
	    y=y2;
	    x2=x1;
	}
	else
	{
	   x=x1;
	   y=y1;

	}
	putpixel(x,y,14);
	while(x<x2)
	{
	    x++;
	    if(p<0)
	    {
		p=p+twody;
	    }
	    else
	    {
		y--;
		p=p+twodyminusdx;
	    }
	    putpixel(x,y,14);
	   // delay(5);
	}

    }
    else if(m<-1)
    {
	int p=twodx-dy,x,y;
	if(y1>y2)
	{
	    x=x1;
	    y=y1;
	}
	else
	{
	    y=y2;
	    x=x2;
	    y2=y1;
	}
	while(y>y2)
	{
	    y--;
	    if(p<0)
	    {
		p=p+twodx;
	    }
	    else
	    {
		x++;
		p=p+twodxminusdy;
	    }
	    putpixel(x,y,14);
	}
     }
   else if(dx>=dy)
   {
	int p=twody-dx,x,y;
	if(x1>x2)
	{
	    x=x2;
	    y=y2;
	    x2=x1;
	}
	else
	{
	    x=x1;
	    y=y1;
	}
	putpixel(x,y,3);
	while(x<x2)
	{
	    x++;
	    if(p<0)
	    p=p+twody;
	    else
	    {
	       y++;
	       p=p+twodyminusdx;
	    }
	    putpixel(x,y,14);
	}
    }
      else if(dy>dx)
      {
	    int p=twodx-dy,x,y;
	if(y1>y2)
	{
	    x=x2;
	    y=y2;
	    y2=y1;
	}
	else
	{
	    x=x1;
	    y=y1;
	}
	putpixel(x,y,14);
	while(y<y2)
	{
	    y++;
	    if(p<0)p=p+twodx;
	    else
	    {
	       x++;
	       p=p+twodxminusdy;
	    }
	    putpixel(x,y,14);
	}
      }
}

void main()
{
    int x1,x2,y1,y2;
    cout<<"Enter the co-ordinates of line: ";
    cin>>x1>>y1>>x2>>y2;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"..//bgi ");
    cleardevice();
    bline(x1,y1,x2,y2);
    getch();
}






































