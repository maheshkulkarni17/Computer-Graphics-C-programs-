#include<stdlib.h>
#include<stdio.h>
#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
int xc,yc;
void display(int x,int y,int xc,int yc){
	putpixel(xc+x,yc+y,WHITE);
	putpixel(xc+y,yc+x,WHITE);
	putpixel(xc+y,yc-x,WHITE);
	putpixel(xc+x,yc-y,WHITE);
	putpixel(xc-x,yc+y,WHITE);
	putpixel(xc-x,yc-y,WHITE);
	putpixel(xc-y,yc-x,WHITE);
	putpixel(xc-y,yc+x,WHITE);
}
void midpointcircle(int xc,int yc,int r){
	int x=0,y=r,p=1-r;
	while(x<=y){

		if(p<=0){
			x=x+1;


			p=p+2*x+1;
			}
		else{
			x=x+1;
			y=y-1;

			p=p+2*x-2*y+1;
		}
		display(x,y,xc,yc
		);
	}

}




void main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	setcolor(RED);
	circle(200,200,100);
	midpointcircle(200,200,100);
	getch();
	closegraph();
	}

