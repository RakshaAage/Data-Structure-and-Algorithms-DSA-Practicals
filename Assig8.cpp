/*"There are flight paths between cities. 
If there is a flight between city A and city B then there is an edge between the cities. 
The cost of the edge can be the time that flight take to reach city B from A, or the amount of fuel used for the journey. 
Represent this as a graph. The node can be represented by airport name or name of the city. 
Use adjacency list representation of the graph or use adjacency matrix representation of the graph.
Check whether the graph is connected or not. Justify the storage representation used."
*/


#include<iostream>
#include<string>
using namespace std;
#define MAX 50
                                                                                                                                                                                                                          

class flight
{	
	public:
		   string city[MAX];
		   int T[MAX][MAX];
		   int F[MAX][MAX];
		   void readGraph();
    	   bool isConnected();
		   void display();
		   void delete_flight();
		   void delete_city();
		   void search();
};

void flight::readGraph()
{
	int n,i,j,ans;
	cout<<"Enter the number of cities: "<<endl;
	cin>>n;
	cout<<"Enter the names of cities: "<<endl;
	for(i=0;i<n;i++)
		{
		cin>>city[i];
		}

	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
		cout<<"Is "<<city[i]<<" & "<<city[j]<<" connected? (1/0)"<<endl;
		cin>>ans;
		if(ans==1)
			{cout<<"Enter time reqiured for the flight: "<<endl;
			 cin>>T[i][j];
			 cout<<"Enter fuel reqiured for the flight: "<<endl;
			 cin>>F[i][j];
			}	
		}
}

void flight::display()
{
	int i,j,n;
	for(i=0;i<n;i++)
		cout<<"/n";
		for(j=0;j<n;j++)
			{
			 cout<<T[i][j]<<" ";
			}

	for(i=0;i<n;i++)
		cout<<"/n";
		for(j=0;j<n;j++)
			{
			 cout<<F[i][j]<<" ";
			}
}

bool flight::isConnected()
{}

int main()
{
flight f;
f.readGraph();
f.display();
return 0;
}
