#include<iostream.h>
#include<conio.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>

void bcircle(int,int,int);

void main(){
    int gd=0,gm;
    initgraph(&gd,&gm,"..//bgi");
    int x,y,r;
    cleardevice();
    cout<<"Enter center point(x,y):";
    cin>>x>>y;
    cout<<"Enter radius: ";
    cin>>r;
    bcircle(x,y,r);
    getch();
}

void bcircle(int xc,int yc,int r)
{
    int x=0,y=r,d=3-2*r;
    while(x<y)
    {
	putpixel(x+xc,y+yc,14);
	putpixel(x+xc,-y+yc,14);
	putpixel(-x+xc,y+yc,14);
	putpixel(-x+xc,-y+yc,14);
	putpixel(y+xc,x+yc,14);
	putpixel(y+xc,-x+yc,14);
	putpixel(-y+xc,x+yc,14);
	putpixel(-y+xc,-x+yc,14);
	if(d<0)
	d=d+4*x+6;
	else
	{
	    y--;
	    d=d+4*(x-y)+10;
	}
	x++;
    }
}