#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int xmax,ymax,xmin,ymin;
int array[40],arr[40];
float m;
int i;
class point
{	public:
		int x;
		int y;
};
void clipLineL(float x1,float y1,float x2,float y2){
	if(x1!=x2){
		m=float(y2-y1)/float(x2-x1);
	}else m=999999;
	//if(xmin<=x1&&xmin<=x2&&xmax>=x1&&xmax>=x2&&ymin<=y1&&ymin<=y2&&ymax>=y1&&ymax>=y2)
	if(xmin<=x1&&xmin<=x2)
	{
		//line(x1,y1,x2,y2);
		array[i]=x2;
		array[i+1]=y2;
		i+=2;
		return;
	}
	//left clip
	if(xmin>=x1&&xmin<=x2){
		x1=xmin;
		y1=y2+m*(xmin-x2);
		array[i]=x1;
		array[i+1]=y1;
		array[i+2]=x2;
		array[i+3]=y2;
		i=i+4;

	}
	else if(xmin<=x1&&xmin>=x2)
	{
		x2=xmin;
		y2=y1+m*(xmin-x1);
		array[i]=x2;
		array[i+1]=y2;
		i=i+2;
	}
}
void clipLineR(float x1,float y1,float x2,float y2){
	if(x1!=x2){
		m=float(y2-y1)/float(x2-x1);
	}else m=999999;
       //	if(xmin<=x1&&xmin<=x2&&xmax>=x1&&xmax>=x2&&ymin<=y1&&ymin<=y2&&ymax>=y1&&ymax>=y2)
	if(x1<=xmax&&x2<xmax)
	{
		//line(x1,y1,x2,y2);
		arr[i]=x2;
		arr[i+1]=y2;
		i+=2;
		return;
	}
	//right clip
	if(xmax>=x1&&xmax<=x2){
		x2=xmax;
		y2=y1-m*(x1-xmax);
		arr[i]=x2;
		arr[i+1]=y2;
		i+=2;
		return;
	}
	else if(xmax<=x1&&xmax>=x2){
		x1=xmax;
		y1=y2-m*(x2-xmax);
		arr[i]=x1;
		arr[i+1]=y1;
		arr[i+2]=x2;
		arr[i+3]=y2;
		i+=4;
}
}
void clipLineB(float x1,float y1,float x2,float y2){
	if(x1!=x2){
		m=float(y2-y1)/float(x2-x1);
	}else m=999999;
	//if(xmin<=x1&&xmin<=x2&&xmax>=x1&&xmax>=x2&&ymin<=y1&&ymin<=y2&&ymax>=y1&&ymax>=y2)
	if(y1>=ymin&&y2>=ymin)
	{

		//line(x1,y1,x2,y2);
		array[i]=x2;
		array[i+1]=y2;
		i+=2;
		return;
	}
	if(ymin>=y1&&ymin<=y2){
		y1=ymin;
		if(m!=0){
			x1=x2-(y2-ymin)/m;
		}
		array[i]=x1;
		array[i+1]=y1;
		array[i+2]= x2;
		array[i+3]=y2;
		i+=4;

	}
	else if(ymin<y1&&ymin>y2){
		y2=ymin;
		if(m!=0)
			x2=x1-(y1-ymin)/m;
		array[i]=x2;
		array[i+1]=y2;
		i+=2;
	}
}
void clipLineT(float x1,float y1,float x2,float y2){
	if(x1!=x2){
		m=float(y2-y1)/float(x2-x1);
	}else m=999999;
	//if(xmin<=x1&&xmin<=x2&&xmax>=x1&&xmax>=x2&&ymin<=y1&&ymin<=y2&&ymax>=y1&&ymax>=y2)
	if(y1<ymax&&y2<ymax)
	{
		//line(x1,y1,x2,y2);
		arr[i]=x2;
		arr[i+1]=y2;
		i+=2;
		return;
	}
	//top clip
	if(ymax>=y1&&ymax<=y2){
		y2=ymax;
		if(m!=0){
			x2=x1-(y1-ymax)/m;
		}
		arr[i]=x2;
		arr[i+1]=y2;
		i+=2;
	}
	else if(ymax<=y1&&ymax>=y2){
		y1=ymax;
		if(m!=0)
			x1=x2-(y2-ymax)/m;
		arr[i]=x1;
		arr[i+1]=y1;
		arr[i+2]=x2;
		arr[i+3]=y2;
		i+=4;
	}
}
int main(){

	int gd=0,gm,pVertices;
	initgraph(&gd,&gm,"..//bgi");
	point pPts[10];
	cout<<"\nEnter the xmin, ymin, xmax and ymax of the clipping window :-  \n";
	cout<<"xmin = ";
	cin>>xmin;
	cout<<"ymin = ";
	cin>>ymin;
	cout<<"xmax = ";
	cin>>xmax;
	cout<<"ymax = ";
	cin>>ymax;

	cout<<"\nEnter the number of vertices of the clipping polygon :(1-10)\n";
	cin>>pVertices;
	cout<<"\nEnter the coordinates of the clipping convex polygon :\n";
	for(int a=0;a<pVertices;a++){
		cout<<"x"<<a+1<<" = ";
		cin>>pPts[a].x;
		cout<<"y"<<a+1<<" = ";
		cin>>pPts[a].y;
	}
	rectangle(xmin,ymin,xmax,ymax);

	for(int b=0;b<pVertices-1;b++){
		line(pPts[b].x,pPts[b].y,pPts[b+1].x,pPts[b+1].y);
			}
	line(pPts[pVertices-1].x,pPts[pVertices-1].y,pPts[0].x,pPts[0].y);
	getch();
	cleardevice();
	setcolor(14);
	outtextxy(50,50 ,"Clipped Polygon :-");

	rectangle(xmin,ymin,xmax,ymax);
	i=0;

	for(int c=0;c<pVertices-1;c++){
		clipLineL(pPts[c].x,pPts[c].y,pPts[c+1].x,pPts[c+1].y);
	}
	clipLineL(pPts[pVertices-1].x,pPts[pVertices-1].y,pPts[0].x,pPts[0].y);
	int e=i;
	i=0;
       //	cout<<"\nleft clip"<<endl;
	for(int d=0;d<e-3;d+=2){
	      //	cout<<array[d]<<" "<<array[d+1]<<" "<<array[d+2]<<" "<<array[d+3]<<endl;
		clipLineR(array[d],array[d+1],array[d+2],array[d+3]);
	}
	clipLineR (array[e-2],array[e-1],array[0],array[1]);
	e=i;
	i=0;
	//cout<<"\nright clip"<<endl;
	for(int f=0;f<e-3;f+=2){
	       //	cout<<arr[f]<<" "<<arr[f+1]<<" "<<arr[f+2]<<" "<<arr[f+3]<<endl;
		clipLineB(arr[f],arr[f+1],arr[f+2],arr[f+3]);
	}
	clipLineB(arr[e-2],arr[e-1],arr[0],arr[1]);
	e=i;
	i=0;
       //	cout<<"\nbottom clip"<<endl;
	for(int g=0;g<e-3;g+=2){
	      //	cout<<array[g]<<" "<<array[g+1]<<" "<<array[g+2]<<" "<<array[g+3]<<endl;
		clipLineT(array[g],array[g+1],array[g+2],array[g+3]);
	}
	clipLineT(array[e-2],array[e-1],array[0],array[1]);
	e=i;
	setcolor(5);
       //	cout<<"\ntop clip"<<endl;
	for(int h=0;h<e-3;h+=2){
	      // 	cout<<arr[h]<<" "<<arr[h+1]<<" "<<arr[h+2]<<" "<<arr[h+3]<<endl;
		line(arr[h],arr[h+1],arr[h+2],arr[h+3]);
	}
	line(arr[e-2],arr[e-1],arr[0],arr[1]);
	getch();
}