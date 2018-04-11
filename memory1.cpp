#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<gotoxy.h>
#define m 5
#define n 4
int a[10];
float random(int j)
{
	float z,l;
	z=(2^(j*clock()))*clock();
	l=sin(z);
	return l;
}
int print(int j)
{
	float l;
    qw:
    l=random(clock()*j);
	if(l>=-1.0 && l<-0.8)
	{
	    if(a[0]<2)
        {
            a[0]++;
            return 0;
        }
        else
            goto qw;
	}
	else if(l>=-0.8 && l<-0.6)
	{
	    if(a[1]<2)
	    {
	        a[1]++;
            return 1;
        }
        else
            goto qw;
	}
	else if(l>=-0.6 && l<-0.4)
	{
	    if(a[2]<2)
	    {
	        a[2]++;
            return 2;
		}
		else
            goto qw;
	}
	else if(l>=-0.4 && l<-0.2)
	{
	    if(a[3]<2)
	    {
	        a[3]++;
            return 3;
		}
		else
            goto qw;
	}
	else if(l>=-0.2 && l<0.0)
	{
	    if(a[4]<2)
	    {
	        a[4]++;
            return 4;
		}
		else
            goto qw;
	}
	else if(l>=0.0 && l<0.2)
	{
	    if(a[5]<2)
	    {
	        a[5]++;
            return 5;
        }
        else
            goto qw;
	}
	else if(l>=0.2 && l<0.4)
	{
	    if(a[6]<2)
	    {
	        a[6]++;
            return 6;
		}
		else
            goto qw;
	}
	else if(l>=0.4 && l<0.6)
	{
	    if(a[7]<2)
        {
            a[7]++;
            return 7;
		}
		else
            goto qw;
	}
	else if(l>=0.6 && l<=0.8)
	{
	    if(a[8]<2)
	    {
	        a[8]++;
            return 8;
		}
		else
            goto qw;
	}
	else if(l>=0.8 && l<=1.0)
	{
	    if(a[9]<2)
	    {
	        a[9]++;
            return 9;
		}
		else
            goto qw;
	}
}

using namespace std;
class game
{
	int real[m][n];
	int temp[m][n];
	  public:
	  static int x;
	  game()
	  {
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
            {
                temp[i][j]=0;
				real[i][j]=print((i^j)*clock());
			}
		}
	  }
	  void display();
	  void take();
	  int takerow();
	  int takecol();
};
int game::x;
void game::take()
{
	int r1,c1,r2,c2;

    rc:
	r1=takerow();
	c1=takecol();
	if(temp[r1][c1]==1)
    {
        gotoxy(15,21);
        cout<<"CELL IS ALREADY OPENED RE-TRY ::           ";
		gotoxy(50,21);
        goto rc;
    }
	gotoxy((8*c1)+33,(2*r1)+10);
	cout<<real[r1][c1];
	gotoxy(50,21);cout<<"  ";gotoxy(50,21);

	rcc:
	r2=takerow();
	c2=takecol();
	if(temp[r2][c2]==1)
    {
        gotoxy(15,21);
        cout<<"CELL IS ALREADY OPENED RE-TRY ::           ";
		gotoxy(50,21);
        goto rcc;
    }
    gotoxy((8*c2)+33,(2*r2)+10);
	cout<<real[r2][c2];
	gotoxy(50,21);cout<<"  ";gotoxy(50,21);

		 {
			if((r1==r2 && c1==c2) || (real[r1][c1]!=real[r2][c2]))
			{
				Sleep(1000);
				gotoxy((8*c1)+33,(2*r1)+10);cout<<'@';
                gotoxy((8*c2)+33,(2*r2)+10);cout<<'@';
                gotoxy(50,21);cout<<"  ";gotoxy(50,21);
			}
			else if(real[r1][c1]==real[r2][c2])
			{
                temp[r1][c1]=1;
			    temp[r2][c2]=1;
                x=x+2;
			}
		 }
}

	int main()
	{
		system("cls");
		cout<<"\n\n\n\n\n\n\n\t\tPRESS ANY KEY FOR START GAME...:";
		while(!kbhit());
		getch();
		game g;
		int y=m*n;
		int z=1,l=0;
		g.display();
		while(z)
		{
			//g.display();
			g.take();
			if(g.x==y)
			{
				z=0;
			}
			l++;
		}
		cout<<"------------------\n\n\tYOU COMPLETED,,,...";
		cout<<"\n\tYOUR SCORE (try)...-> "<<l;
		getch();
		return 0;
	}
void game::display()
{
	system("cls");
	gotoxy(20,3);
	cout<<"ENTER '-' FOR EXIT...\n\n";
	gotoxy(33,5);//33 41 49 57
	cout<<"0\t1\t2\t3";
	gotoxy(25,7);
	cout<<"*************************************\n\n";
	for(int i=0;i<m;i++)
	{
	    gotoxy(25,(2*i)+10);
		cout<<i<<"  | ";
		for(int j=0;j<n;j++)
		{
			cout<<"\t";
            cout<<'@';
		}
	}
	gotoxy(15,21);
	cout<<"ENTER CELL NO. TO OPEN IT ::              ";
	gotoxy(50,21);
}
int game::takerow()
{
	int p,x;
	rw:
	while(!kbhit());
	switch(getch())
	{
		case '-':
			exit(0);
			break;
		case '0':
			p=0;
			break;
		case '1':
			p=1;
			break;
		case '2':
			p=2;
			break;
		case '3':
			p=3;
			break;
		case '4':
			p=4;
			break;
		default:
		    gotoxy(15,21);
			cout<<"WRONG CHOICE OF ROW...RE-ENTER ::                           ";
            gotoxy(50,21);
			goto rw;
			break;
	}
	gotoxy(15,21);
	cout<<"ENTER CELL NO. TO OPEN IT ::           ";
	gotoxy(50,21);
	cout<<p;
	return p;
}
int game::takecol()
{
	int q;
	cw:
	while(!kbhit());
	switch(getch())
	{
		case '-':
			exit(0);
			break;
		case '0':
			q=0;
			break;
		case '1':
			q=1;
			break;
		case '2':
			q=2;
			break;
		case '3':
			q=3;
			break;
		default:
		    gotoxy(15,21);
			cout<<"WRONG CHOICE OF COLUM...RE-ENTER ::             ";
			gotoxy(50,21);
			goto cw;
			break;
	}
	cout<<q;
	gotoxy(15,21);
	cout<<"ENTER CELL NO. TO OPEN IT ::           ";
	gotoxy(50,21);
	return q;
}

