#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
class student
{
	public:
		string  name;
		student()
		{
			
		}
		student(string n)
		{
			name=n;
		}
};
class calculations:public student
{
	int a,b;
	public:
		calculations()
		{
			
		}
		calculations(int c,int d,string n):student(n)
		{
			a=c;
			b=d;
		}
		int  cal()
		{
			int i;
		    float d=((float)a/b)*100;
        	if(d<75)
	        {
	          int c=1;
	          for(i=0;c;i++)
	          {
	         	a++;
		        b++;
		        d=((float)a/b)*100;
		        if(d>=75)
		         c=0;
	          }
	          cout<<"No. of lectures to get back into safe zone: "<<i;
	          return i;
            }
            else if(d>=75)
	        {
	          int c=1;
	          for(i=0;c;i++)
	          {
		       b++;
		       d=((float)a/b)*100;
		       if(d<=75.1)
		       c=0;
              }
	          if(i==1)
	          cout<<"75 attendance";
	          else
	          {
	           cout<<"max bunks allowed: "<<i-1;
               return i;
              }
	        }	
		}
	
};
int main()
{
	cout<<"Press 1 for file input\nPress 2 for console input\n";
	int q;
	string name;
	int a,b,i;
	float d;
	cin>>q;
	ofstream ol("r.txt");
	calculations s[2];
	if(q==1)
	{
	ifstream il("b.txt");
	for(int j=0;j<2;j++)
	{
			il>>name;
			il>>a;
			il>>b;
			d=(float)a/b;
			cout<<"Name: "<<name<<"\nattended: "<<a<<"\ntotal lectures: "<<b<<"\n";
			ol<<"Name: "<<name<<"\nattended: "<<a<<"\ntotal lectures: "<<b<<"\n";
		calculations p(a,b,name);
		s[j]=p;
		i=s[j].cal();
		if(d<0.75)
		ol<<"No. of lectures to get back into safe zone: "<<i;
		else if(d>0.75)
		ol<<"max bunks allowed: "<<i-1;
		else if(d==0.75)
		ol<<"75 attendance";
		ol<<"\n";
		cout<<"\n";
	}
    }
	if(q==2)
	{
		for(int j=0;j<2;j++)
	{
			cin>>name;
			cin>>a;
			cin>>b;
			d=(float)a/b;
			cout<<"Name: "<<name<<"\nattended: "<<a<<"\ntotal lectures: "<<b<<"\n";
			ol<<"Name: "<<name<<"\nattended: "<<a<<"\ntotal lectures: "<<b<<"\n";
		calculations p(a,b,name);
		s[j]=p;
		i=s[j].cal();
			if(d<0.75)
		ol<<"No. of lectures to get back into safe zone: "<<i;
		else if(d>0.75)
		ol<<"max bunks allowed: "<<i-1;
		else if(d==0.75)
		ol<<"75 attendance";
		ol<<"\n";
		cout<<"\n";
	}	
	}
}
