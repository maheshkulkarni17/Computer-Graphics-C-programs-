#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

void hil(float a,float b,float c,float d,float centx,float centy,int currlevel,int maxlevel,float hlf);
int  main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:/turboc3/bgi");
float n=6;
float x=240,y=240,d=120;

setcolor(0);
hil(1,2,3,4,240,240,1,4,120);   //  hil(4,1,2,3,x,y,currlevel,maxlevel,d)
getch();
}

void hil(float a,float b,float c,float d,float centx,float centy,int currlevel,int maxlevel,float hlf)
{
	float tx[5],ty[5];
	tx[1]=centx+hlf;
	ty[1]=centy+hlf;

	tx[2]=centx+hlf;
	ty[2]=centy-hlf;	// centx=240, centy=240, n=6, hlf=120

	tx[3]=centx-hlf;
	ty[3]=centy-hlf;

	tx[4]=centx-hlf;
	ty[4]=centy+hlf;


	if(currlevel<maxlevel)
	{
		hil(a,d,c,b,tx[a],ty[a],currlevel+1,maxlevel,hlf/2);
		hil(a,b,c,d,tx[b],ty[b],currlevel+1,maxlevel,hlf/2);
		hil(a,b,c,d,tx[c],ty[c],currlevel+1,maxlevel,hlf/2);
		hil(c,b,a,d,tx[d],ty[d],currlevel+1,maxlevel,hlf/2);
	}
	else
	{
		lineto(tx[a],ty[a]);
		setcolor(WHITE);
		lineto(tx[b],ty[b]);
		lineto(tx[c],ty[c]);
		lineto(tx[d],ty[d]);
		delay(50);
	}
}
