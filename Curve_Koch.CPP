
//CG Assignment to implement koch curve

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>

void koch(int x1,int y1,int x2, int y2,int n);
int midx,midy,maxx,maxy;

void main()
    {
	int gd=0,gm,x1,y1,x2,y2,order,k,n,i;

	initgraph(&gd,&gm,"c:/turboc3/bgi");

	maxx=getmaxx();//Max possible x co-ordinate
	maxy=getmaxy();//Maz possible y co-ordinate

	midx=getmaxx()/2;//x co-ordinate of origin
	midy=getmaxy()/2;//y co-ordinate of origin

	printf("Enter line co-cordinates: \n");

	printf("x1 y1: ");
	scanf("%d %d",&x1,&y1);

	printf("x2 y2: ");
	scanf("%d %d",&x2,&y2);

	printf("Enter order of curve: ");
	scanf("%d",&order);

	//line(x1,y1,x2,y2);
	koch(x1,y1,x2,y2,order);
	getch();

    }

void koch(int x1,int y1,int x2, int y2,int n)     //IMPLEMENTATION OF MAIN FUNCTION OF KOCH CURVE
{
	int dx,dy,xa,ya,xb,yb,xc,yc;
	if(n>0)
	{
	dx=(x2-x1)/3;
	dy=(y2-y1)/3;
	xa=x1+dx;
	ya=y1+dy;
	xb=x1+2*dx;
	yb=y1+2*dy;
     /*
	xc=xa+(0.5*dx);          									        // ANGLE=60 SO WE DIRECTLY PUT VALUES
	yc=ya-(0.866*dx);

       */
	xc=xa+(0.5*dx+0.866*dy);          									        // ANGLE=60 SO WE DIRECTLY PUT VALUES
	yc=ya-(0.866*dx-0.5*dy);


	koch(x1,y1,xa,ya,n-1);
	koch(xa,ya,xc,yc,n-1);
	koch(xc,yc,xb,yb,n-1);
	koch(xb,yb,x2,y2,n-1);
	}
	else
	{
	  setcolor(14);
	  line(x1,y1,x2,y2);
	}
}


