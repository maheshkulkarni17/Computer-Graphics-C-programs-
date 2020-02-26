#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>


void b_fill(int x, int y,int b_color,int new_c)
{
    if ((getpixel(x, y) != b_color) && (getpixel(x,y)!=new_c))
    {
	putpixel(x, y, new_c);
	delay(3);
	b_fill(x + 1, y,b_color,new_c);
	b_fill(x, y - 1,b_color,new_c);
	b_fill(x, y + 1,b_color,new_c);
	b_fill(x - 1, y,b_color,new_c);
    }
}

void main()
{
    int gd = DETECT, gm = DETECT , b_color,new_c;
    initgraph(&gd, &gm, "C:\\TurboC3\\bgi");
    cleardevice();
    rectangle(200, 200, 250,250);
    printf("\n\nEnter boundary colour : ");
    scanf("%d",&b_color);
    printf("\nEnter new color : ");
    scanf("%d",&new_c);
    b_fill(210, 210,b_color,new_c);
    getch();
}