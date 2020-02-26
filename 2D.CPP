

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int a[10][3];
double t[3][3];

void disp(int);
void Translate(int);
void Scaling(int);
void Scaling2(int);
void Reflection(int);
void Rotation(int);
void Rotation2(int);
void matmul(int);

void matmul(int n)
{
	int i=0,j=0,k=0,c[10][3];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j]=0;
			for(k=0;k<3;k++)
			{
				c[i][j]=c[i][j]+(a[i][k]*t[k][j]);
			}
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			a[i][j]=c[i][j];
		}
	}
}

void main()
{
	int gd=0,gm,i,n,j,ch=0;
	//clrscr();
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
			{
				t[i][j]=1;
			}
			else
			{
				t[i][j]=0;
			}
		}
	}
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	printf("Enter the coordinates :\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&a[i][j]);
		}
		a[i][j]=1;
	}

	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	disp(n);
	do{
		printf("1: Translation\n2: Scaling\n3: Scaling about arbitary point\n4: Reflection\n5: Rotation\n6: Rotation about arbitary point\n7: Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				Translate(n);
				disp(n);
				break;
			case 2:
				Scaling(n);
				disp(n);
				break;
			case 3:
				Scaling2(n);
				disp(n);
				break;
			case 4:
				Reflection(n);
				disp(n);
				break;
			case 5:
				Rotation(n);
				disp(n);
				break;
			case 6:
				Rotation2(n);
				disp(n);
				break;
		}
	}while(ch!=7);
}

void Scaling(int n)
{
	int sx,sy;
	printf("Scaling in x : ");
	scanf("%d",&sx);
	printf("Scaling in y : ");
	scanf("%d",&sy);
	t[0][0]=sx;
	t[1][1]=sy;
	matmul(n);
	t[0][0]=1;
	t[1][1]=1;
}

void Scaling2(int n)
{
	int ptx,pty;
	printf("Scaling about a point :\nx : ");
	scanf("%d",&ptx);
	printf("y : ");
	scanf("%d",&pty);
	t[2][0]=-ptx;
	t[2][1]=-pty;
	matmul(n);
	t[2][0]=0;
	t[2][1]=0;
	Scaling(n);
	t[2][0]=ptx;
	t[2][1]=pty;
	matmul(n);
}

void Translate(int n)
{
	int tx,ty;
	printf("Translation by x :");
	scanf("%d",&tx);
	printf("Translation by y :");
	scanf("%d",&ty);
	//clrscr();
	t[2][0]=tx;
	t[2][1]=ty;
	matmul(n);
	t[2][0]=0;
	t[2][1]=0;
}

void disp(int n)
{
	int i;
	setcolor(15);
	line(getmaxx()/2,0,getmaxx()/2,getmaxy()); 	//axes
	line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	outtextxy(0,getmaxy()/2,"x-axis");
	outtextxy(getmaxx()/2,0," y-axis");
	outtextxy(0,0,"(-,+)");
	outtextxy(getmaxx()-40,0,"(+,+)");
	outtextxy(0,getmaxy()-10,"(-,-)");
	outtextxy(getmaxx()-40,getmaxy()-10,"(+,-)");
	setcolor(4);
	for(i=0;i<n-1;i++)                      	//Display poly
	{
		line(a[i][0]+getmaxx()/2,getmaxy()/2-a[i][1],a[i+1][0]+getmaxx()/2,getmaxy()/2-a[i+1][1]);
	}
	line(a[0][0]+getmaxx()/2,getmaxy()/2-a[0][1],a[i][0]+getmaxx()/2,getmaxy()/2-a[i][1]);
	getch();
	cleardevice();
}

void Reflection(int n)
{
	int ch;
	printf("1: About x-axis\n2: About y-axis\n3: About y=x\n4: About y=-x\nEnter your choice : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			t[1][1]=-1;
			matmul(n);
			t[1][1]=1;
			break;
		case 2:
			t[0][0]=-1;
			matmul(n);
			t[0][0]=1;
			break;
		case 3:
			t[0][0]=0;
			t[0][1]=1;
			t[1][0]=1;
			t[1][1]=0;
			matmul(n);
			t[0][0]=1;
			t[0][1]=0;
			t[1][0]=0;
			t[1][1]=1;
			break;
		case 4:
			t[0][0]=0;
			t[0][1]=-1;
			t[1][0]=-1;
			t[1][1]=0;
			matmul(n);
			t[0][0]=1;
			t[0][1]=0;
			t[1][0]=0;
			t[1][1]=1;
			break;
	}
}

void Rotation(int n)
{
	int angle;
	double rad;
	printf("Angle of rotation : ");
	scanf("%d",&angle);
	rad=3.14*angle/180;
	t[0][0]=cos(rad);
	t[0][1]=sin(rad);
	t[1][0]=-sin(rad);
	t[1][1]=cos(rad);
	matmul(n);
	t[0][0]=1;
	t[0][1]=0;
	t[1][0]=0;
	t[1][1]=1;
}

void Rotation2(int n)
{
	int ptx,pty;
	printf("Enter the coordinates of point:\nx : ");
	scanf("%d",&ptx);
	printf("y : ");
	scanf("%d",&pty);
	t[2][0]=-ptx;
	t[2][1]=-pty;
	matmul(n);
	t[2][0]=0;
	t[2][1]=0;
	Rotation(n);
	t[2][0]=ptx;
	t[2][1]=pty;
	matmul(n);
	t[2][0]=0;
	t[2][1]=0;
}