#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

//function declarations
void multiply(int mat[3][3],int vertex[10][3],int n);
void shear(int vertex[10][3],int n);
void translation(int vertex[10][3],int n);
void scaling(int vertex[10][3],int n);
void reflect(int vertex[10][3],int n);

void init(int vertex[10][3],int n);

int main()
{
  int i,x,y;
  int vertex[10][3],n;
  int choice;
  //clear the screen
  clrscr();
  //taking inputs for the polygon object
  cout<<"\nEnter the no. of vertex : ";
  cin>>n;
   for(i=0;i<n;i++)
     {
	    cout<<"Enter the points (x,y): ";
	    cin>>x>>y;
	    vertex[i][0]=x;
	    vertex[i][1]=y;
	    vertex[i][2]=1;
     }
    cout<<"\nChoose transformation: ";
    cout<<"\n1. Shear";
    cout<<"\n2. Translation";
    cout<<"\n3. Scaling";
    cout<<"\n4. Reflection";
    cout<<"\nEnter your choice: ";
    cin>>choice;
     switch(choice)
     {
	     case 1:shear(vertex,n);
		    break;
	     case 2:translation(vertex,n);
		    break;
	     case 3:scaling(vertex,n);
		    break;
	     case 4:reflect(vertex,n);
		    break;
	     default:cout<<"Invalid choice!";
		    break;
     }
	 getch();
	 return 0;
}

void init(int vertex[10][3],int n)
{
   //initialisation of the graphics driver
   int gd=DETECT,gm,i;
   initgraph(&gd,&gm,"C:\\turboc3\\bgi");

setcolor(14);///////drawing x and y axes
line(320,0,320,479);
line(0,240,639,240);
////////////////////////////////////

  //drawing graph legends
   setcolor(3);
   line(540,23,520,23);
   setcolor(15);
   line(540,53,520,53);
   setcolor(14);
   outtextxy(550,20,"Original");
   outtextxy(550,50,"Transformed");

   //drawing the object
   setcolor(3);
   for(i=0;i<n-1;i++)
    {
       line(320+vertex[i][0],240-vertex[i][1],320+vertex[i+1][0],240-vertex[i+1][1]);
    }
     line(320+vertex[n-1][0],240-vertex[n-1][1],320+vertex[0][0],240-vertex[0][1]);

}

void multiply(int mat[3][3],int vertex[10][3],int n)
{
  int i,j,k;    // loop variables

  //array for storing final image matrix
 int res[10][3];

  //multiply the object matrix with shearing transformation matrix
  for(i=0;i<n;i++)
   {
     for(j=0;j<3;j++)
      {
	     res[i][j]=0;
	 for(k=0;k<3;k++)
	      {
		 res[i][j] = res[i][j] + vertex[i][k]*mat[k][j];
	       }
     }
   }

   //drawing the transformed image
   setcolor(15);
   for(i=0;i<n-1;i++)
    {
       line(320+res[i][0],240-res[i][1],320+res[i+1][0],240-res[i+1][1]);
     }
     line(320+res[n-1][0],240-res[n-1][1],320+res[0][0],240-res[0][1]);
}

void shear(int vertex[10][3],int n)
{
   //shearing transformation matrix
   int shear_array[3][3];
   int ysh,xsh,option;
   cout<<"\nMethods of shear transformations: ";
   cout<<"\n1. X shear";
   cout<<"\n2. Y shear";
   cout<<"\nEnter your choice: ";
   cin>>option;
   switch(option)
   {
	case 1:cout<<"\nEnter the X shear : ";
	       cin>>xsh;
	       ysh=0;
	       break;

	case 2:cout<<"\nEnter the Y shear : ";
	       cin>>ysh;
	       xsh=0;
	       break;

	default:cout<<"\nInvalid choice!";
		break;
   }
	    //values for Y shear
	    shear_array[0][0]=1;shear_array[0][1]=ysh;shear_array[0][2]=0;
	    shear_array[1][0]=xsh;shear_array[1][1]=1;shear_array[1][2]=0;
	    shear_array[2][0]=0;shear_array[2][1]=0;shear_array[2][2]=1;

		//initializing the graphics mode and drawing the original object
	     init(vertex,n);
		 //multiplying the object with shearing transformation matrix and displaying the sheared image
	     multiply(shear_array,vertex,n);
}

void translation(int vertex[10][3],int n)
{

   //shearing transformation matrix
   int shear_array[3][3];
   int tx,ty;
	       cout<<"\nTranslation parameters(x,y): ";
	       cin>>tx>>ty;
	    //values for Y shear
	    shear_array[0][0]=1;shear_array[0][1]=0;shear_array[0][2]=0;
	    shear_array[1][0]=0;shear_array[1][1]=1;shear_array[1][2]=0;
	    shear_array[2][0]=tx;shear_array[2][1]=ty;shear_array[2][2]=1;

		//initializing the graphics mode and drawing the original object
	     init(vertex,n);
	     cout<<"Translation.";
		 //multiplying the object with shearing translation matrix and displaying the sheared image
	     multiply(shear_array,vertex,n);
}

void scaling(int vertex[10][3],int n)
{
   //shearing transformation matrix
   int shear_array[3][3];
   int sx,sy;
	       cout<<"\nScaling parameters(Sx,Sy): ";
	       cin>>sx>>sy;
	    //values for Y shear
	    shear_array[0][0]=sx;shear_array[0][1]=0;shear_array[0][2]=0;
	    shear_array[1][0]=0;shear_array[1][1]=sy;shear_array[1][2]=0;
	    shear_array[2][0]=0;shear_array[2][1]=0;shear_array[2][2]=1;

		//initializing the graphics mode and drawing the original object
	     init(vertex,n);
	     cout<<"Scaling.";
		 //multiplying the object with scaling transformation matrix and displaying the sheared image
	     multiply(shear_array,vertex,n);
}

void reflect(int vertex[10][3],int n)
{
   //reflection transformation matrix
   int shear_array[3][3];
   int rx,ry;
   int choice;
   cout<<"\nMethods of reflection:";
   cout<<"\n1. About X-axis ";
   cout<<"\n2. About Y-axis ";
   cout<<"\n3. About origin ";
   cout<<"\nEnter choice: ";
   cin>>choice;
   switch(choice)
     {
	     case 1:rx=1;ry=-1;
		    break;
	     case 2:rx=-1;ry=1;
		    break;
	     case 3:rx=-1;ry=-1;
		    break;
	     default:cout<<"Invalid choice!";
		    break;
     }

	    //values for Y shear
	    shear_array[0][0]=rx;shear_array[0][1]=0;shear_array[0][2]=0;
	    shear_array[1][0]=0;shear_array[1][1]=ry;shear_array[1][2]=0;
	    shear_array[2][0]=0;shear_array[2][1]=0;shear_array[2][2]=1;

		//initializing the graphics mode and drawing the original object
	     init(vertex,n);
	     cout<<"Reflection.";
		 //multiplying the object with reflection transformation matrix and displaying the sheared image
	     multiply(shear_array,vertex,n);
}
