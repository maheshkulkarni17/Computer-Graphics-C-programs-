#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
void main()
{
    clrscr();
    int noOfSides,k,dx,dy,temp;
    int x[20],points[20][2],c;
    float m[20];
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:/TurboC3/BGI");
    cout<<"Enter the no. of sides:"<<endl;
    cin>>noOfSides;
    for(int i=0;i<noOfSides;i++)
    {
	cout<<"X"<<i<<"  Y"<<i<<endl;
	cin>>points[i][0];
	cin>>points[i][1];
	cout<<endl;
    }
    points[noOfSides][0]=points[0][0];
    points[noOfSides][1]=points[0][1];
    cout<<"Enter the color code:"<<endl;
    cin>>c;
    //draw polygon
    for(int q=0;q<noOfSides;q++)
    {
	line(points[q][0],points[q][1],points[q+1][0],points[q+1][1]);
    }
    getch();
    //slope
    for(int w=0;w<noOfSides;w++)
    {
	dx=points[w+1][0]-points[w][0];
	dy=points[w+1][1]-points[w][1];
	if(dx==0)m[w]=0.0;
	if(dy==0)m[w]=1.0;
	if(dx!=0&&dy!=0){
	    m[w]=(float)dx/dy;
	}
    }
    for(int y=0;y<480;y++)
    {
	k=0;
	for(int p=0;p<noOfSides;p++)
	{
	    if((y>=points[p][1]&&y<points[p+1][1])||(y<points[p][1]&&y>=points[p+1][1]))
	    {
		x[k]=(int)(points[p][0]+m[p]*(y-points[p][1]));
		k++;
	    }
	}
	//sort x
	for(int j=0;j<k-1;j++)
	{
	    for(int z=0;z<k-1;z++)
	    {
		if(x[z]>x[z+1])
		{
		    temp=x[z];
		    x[z]=x[z+1];
		    x[z+1]=temp;
		}
	    }
	}
	setcolor(c);
	for(int r=0;r<k;r=r+2)
	{
	    line(x[r],y,x[r+1]+1,y);
	    delay(20);
	}
    }
    getch();
}