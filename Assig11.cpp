#include <iostream>
#include <fstream>
using namespace std;

struct student
{
	int rollno;
	char name[20];
	char div;
	char add[30];
	
	
	void getdata()
	{
		
		cout<<"\nEnter Roll no. : "<<endl;
		cin>>rollno;
		cout<<"\nEnter Name : "<<endl;
		cin>>name;
		cout<<"\nEnter DIV : "<<endl;
		cin>>div;
		cout<<"\nEnter Address : "<<endl;
		cin>>add;
	}
	
	void putdata()
	{
		//cout<<"\n "<<"Roll NO. "<<"  "<<"NAME"<<"  "<<"DIV"<<"  "<<"ADDRESS"<<endl;
		cout<<"\n "<<rollno<<" \t\t  "<<name<<" \t  "<<div<<" \t  "<<add<<endl;
	}
};

class File
{
	fstream fp; 
	student s;
	public:
	void create(); 
	void display();
	void append();
	void search();
	void update();
	void display1();
}; 

void File::create()
{
	char ans;
	fp.open("std.txt",ios::out);
	do{
		s.getdata();
		fp.write((char*)&s,sizeof(s));
		cout<<"\nDo you want to add more: (Y/N): ";
		cin>>ans;
	}while(ans=='y');
	fp.close();
	

}

void File::display()
{
	cout<<"\nRoll No. \tStud.Name \t\tDivision \tAddress";
	fp.open("std.txt",ios::in);
	while(!fp.eof())
	{
		fp.read((char*)&s,sizeof(s));
		if(!fp.eof())
		s.putdata();
	}
	fp.close();
}

void File::append()
{
	fp.open("std.txt",ios::app);
	s.getdata();
	fp.write((char*)&s,sizeof(s));
	fp.close();
}

void File::search()
{
	fp.open("std.txt",ios::in);
	int r;
	cout << "\n Enter roll to be searched :";
	cin >> r;
	while (!fp.eof())
	{
		fp.read((char*)&s,sizeof(s));
		if (!fp.eof() and s.rollno==r) 
		{
			s.putdata();
			//break;
		}
		
		
	}
		
	cout<<"Student does not exist ! ";
		
	
	fp.close();
}

void File::update()
{
	int r;
	fp.open("std.txt",ios::in|ios::out);
	cout<<"\nEnter Roll no. to be upadated: ";
	cin>>r;
	
	while(fp.read((char*)&s,sizeof(s)))
	{
		//read record from student file
		if(s.rollno==r)
		{
			cout<<"\nUpdating....\n";
			cout<<"\nEnter name to update: ";
			cin>>s.name;
			//move pointer to previous record
			fp.seekp(-1*sizeof(s),ios::cur);
			fp.write((char*)&s,sizeof(s)); //rewrite the record
			break;
		}
		
	}
	while(!fp.eof())
	{
		fp.read((char*)&s,sizeof(s));
		if(!fp.eof())
		s.putdata();
	}
	fp.close();
}

int main()
{
  	File obj;
  	int ch;
  	do{
 
	  	cout<<"\n\n1.CREATE \n2.DISPLAY \n3.APPEND \n4.SEARCH \n5.UPDATE"<<endl;
	  	cout<<"\nEnter your choice "<<endl;
	  	cin>>ch;
	  	switch(ch)
	  	{
	  		case 1:
	  			obj.create();
	  			break;
	  		case 2:
	  			obj.display();
	  			break;
	  		case 3:
	  			obj.append();
	  			break;
	  		case 4:
	  			obj.search();
	  			break;
	  		case 5:
	  			obj.update();
	  			break;	
	  	}
	  }while(ch!=6);
  	

return 0;
}








