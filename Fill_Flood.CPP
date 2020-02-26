#include<stdio.h>
#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
void b(float, float);
void push(int, int);
struct node
{
	int x,y;
	node *next;
};

struct node *home = NULL;

void main()
{
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	cleardevice();
	circle(320,240,200);
	b(320,160);
	getch();
	closegraph();
}

void b(float sx,float sy)
{
	float x=sx,y=sy;
	struct node *temp;
	push(x,y);
	temp=home;
	putpixel(x,y,RED);
	while(temp)
	 {
		x = temp->x;
		y = temp->y;
		if((getpixel(x+1,y)==BLACK))
		{
			putpixel(x+1,y,RED);
			push(x+1,y);
		}

		if((getpixel(x,y+1)==BLACK))
		{
			putpixel(x,y+1,RED);
			push(x,y+1);
		}

		if((getpixel(x,y-1)==BLACK))
		{
			putpixel(x,y-1,RED);
			push(x,y-1);
		}

		if((getpixel(x-1,y)==BLACK))
		{
			putpixel(x-1,y,RED);
			push(x-1,y);
		}

		struct node *temp1 = temp;
		temp = temp->next;
		free(temp1);
		delay(0.01);
	}
}

void push(int x,int y)
{
	struct node *nn = NULL;
	if(home==NULL)
	{
		nn = (struct node *)malloc(sizeof(struct node));
		nn->x = x;
		nn->y = y;
		nn->next = NULL;
		home = nn;
	}
	else
	{
		nn = (struct node *)malloc(sizeof(struct node));
		nn->x = x;
		nn->y = y;
		nn->next = NULL;
		home->next = nn;
		home = nn;
	}
}
