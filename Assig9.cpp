#include<iostream.h>
#include<string.h>
#include<conio.h>
#define max 20
using namespace std;

class AVLnode
{
	public:
		char keyword[20], meaning[20];
		AVLnode *left, *right;
		int ht;
};

class AVLTree
{
	public:
		AVLnode *root;
		AVLTree()
		{
			root=NULL;
		}
		
		AVLnode *rotate_right(AVLnode *x);
		AVLnode *rotate_left(AVLnode *x);
		AVLnode *LL(AVLnode *x);
		AVLnode *LR(AVLnode *x);
		AVLnode *RL(AVLnode *x);
		AVLnode *RR(AVLnode *x);
		
		int height(AVLnode *T);
		int BF(AVLnode *T);
		AVLnode *insert(AVLnode *root, char newkey[20], char mean[20]);
		void inorder(AVLnode *root);
		//AVLnode *serach(AVLnode *root, int key);
		//AVLnode *inorder(AVLnode *root); 		
};

//BF (Balance Factor): used to find out the balance factor of each node

AVLnode *AVLTree :: rotate_right(AVLnode *x)
{
	AVLnode *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return y;
} 

AVLnode *AVLTree :: rotate_left(AVLnode *x)
{
	AVLnode *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);
	return y;
}

int AVLTree :: height(AVLnode *T)
{
	int hl, hr;
	if(T==NULL)
		return 0;
	if(T->left==NULL && T->right==NULL)
		return 0;
	
	hl=height(T->left);
	hr=height(T->right);
	if(hl<hr)
		return hr+1;
	else 
		return hl+1;
}

int AVLTRee :: BF(AVLnode *T)
{
	int lh,rh;
	
	if(T==NULL)
		return 0;
	else
	{
		if(T->left==NULL)
			lh=0;
		else
		lh=1+T->left->ht;
	}
	return(lh=rh);
}

AVLnode *AVLTree :: LL(AVLnode *T)
{
	cout<<"\n in LL rotation\n";
	T=rotate_right(T);
	return T;
}
AVLnode *AVLTree :: RR(AVLnode *T)
{
	cout<<"\n in RR rotation\n";
	T=rotate_left(T);
	return T;
}

AVLnode *AVLTree :: LR(AVLnode *T)
{
	cout<<"\n in LR rotation\n";
	T->left=rotate_left(T->left);
	return T;
}
AVLnode *AVLTree :: RL(AVLnode *T)
{
	cout<<"\n in RL rotation\n";
	T->right=rotate_right(T->right);
	T=rotate_left(T)
	return T;
}

AVLnode *AVLTree :: insert(AVLnode *root, char newkey[20], char mean[20])
{
	AVLnode *curr;
	int lh,rh;
	if(root==NULL)
	{
		curr=new AVLnode;
	
		strcpy(curr->keyword, newkey);
		strcpy(curr->meaning, mean);
		curr->ht=0;
		curr->left=NULL;
		curr->right=NULL;
		root=curr;
		cout<<root->keyword;
	}
	else
	{
		//cout<<root->keyword;
		if(strcmp(newkey, root->keyword)<0)
		{
			root->left=insert(root->left,newkey,mean);
			//cout<<"\nBalance Factor: ";<<root->keyword<<" "<<BF(root);
		
			if(BF(root)==2)
			{
				if(strcmp(newkey,root->left->keyword)<0)
				{
					root=LL(root);
				}
				else
				{
					root=LR(root);
				}
			}
		 }
		 else
		 {
		 	if(strcmp(newkey,root->keyword)>0)
		 	{
		 		root->right=insert(root->right,newkey,mean);
		 		//cout<<"\n Balance Factor: "<<root->keyword<<" "<<BF(root);
		 		if(BF(root)==-2)
		 		{
		 			if(strcmp(newkey,root->right->keyword)>0)
		 			{
		 				root=RR(root);
		 			}
		 			else
		 			{
		 				root=RL(root);
		 			}
		 		}
		 	}
		 	else
		 		cout<<"Duplicate...";
		 }
	}
		 root->ht=height(root);
		 return root;
		 
}

int main()
{
	AVLTree AT;
	char keyword[20], meaning[20];
	int choice,i,n
	cout<<"\n-------Menu--------";
	cout<<"\n1.Insert a node\n2.Rotate Right\n3.Rotate Left\n4. Find Height \n5.Find Balance Factor\n6.Display\n";
	cout<<"\nEnter your choice: ";
	cin>>choice;
	
	switch(choice){
		case 1:
			 cout<<"\nEnter no. of words: ";
			 cin>>n;
			 
			 for(i=0;i<n;i++)
			 {
			 	cout<<"Enter Keyword: ";
			 	cin>>keyword;
			 	
			 	cout<<"\nEnter Meaning: ";
			 	cin>>meaning;
			 	
			 	AT.insert(AT.root,keyword,meaning);
			 }
			 break;
			 
		case 2:
			cout<<""
	}
}
    
