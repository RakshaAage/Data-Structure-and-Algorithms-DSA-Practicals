#include <iostream>
#include <fstream>
using namespace std;
//student structure
struct student
{
int roll;
char name[20];
void getdata(){
cout << "\n Enter roll and name :";
cin >> roll >> name;
}
void putdata(){
cout << "\n" << roll << " " << name ;
}
};//end of student

class File
{
fstream fp; student s;
public:
void create(); // create a file
void display();//display file contents
}; // end of class File

void File::create(){
char ans;
// open file in output mode
fp.open("student.dat",ios::out);
do{
//read record in memory
s.getdata();
//write record to file
fp.write((char*)&s,sizeof(s));
cout <<"\n Add more?";
cin>> ans;
}while(ans=='y');
fp.close(); }// end of create

void File::display(){
// open file in output mode
fp.open("student.dat",ios::in);
while (!fp.eof()){
//read record from file
fp.read((char*)&s,sizeof(s));
if (!fp.eof())
s.putdata();
//display record on screen
}
fp.close();
}// end of display


int main()
{
	File fobj;
	fobj.create();
	fobj.display();
	
	return 0;

}



/*void File:: append(){
char ans;
fp.open("student.dat",ios::app);
do{
s.getdata();
//read record in memory
fp.write((char*)&s,sizeof(s));
//write record to file
cout <<"\n Add more?";
cin>> ans;
}while(ans=='y');
fp.close();
}

void search(){
fp.open("student.dat",ios::in); int r;
cout << "\n Enter roll to be searched :";
cin >> r;
while (!fp.eof()){
fp.read((char*)&s,sizeof(s));
//read record from file
if (!fp.eof() and s.roll==r) {
s.putdata();
//display record on screen
break;
}
}
fp.close();
}

void physicaldelete(){
int r;
fstream tfp;// temporary file
fp.open("student.dat",ios::in);
tfp.open("temp",ios::out);
cout << "\n Enter roll to be deleted :";
cin >> r;
while (fp.read((char*)&s,sizeof(s))){
//read record from student file
if (s.roll==r){
cout << "\n Deleting .....\n";
s.putdata();
//display record on screen
}

else{
tfp.write((char*)&s,sizeof(s));
//write record to temp file
}
}// end of while
fp.close();
tfp.close();
remove("student.dat");
rename("temp","student.dat");
}*/
