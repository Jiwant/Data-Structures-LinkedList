#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};

void swapll(node *x,node *y)
{
 node *temp;
 temp=new node;
 temp->next=NULL;
 temp->data=y->data;
 y->data=x->data;
 x->data=temp->data;
 delete temp;
}

class List
{
	private:
	node *start;
	int listcount;
	
	public:
		List();
		void display();
		int countL();
		void inserts(int);
		void inserte(int);
		node *indextoaddress(int);
		void mergell(int,int,int);
		void mergesortll(int,int);
};

List::List()
{
	start==NULL;
}

void List::display()
{
	cout<<"Displaying the Elements of List"<<endl;
	node *temp;
	temp=start;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	
	temp=start;
	while(temp!=NULL)
	{
		cout<<temp<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int List::countL()
{
	return listcount;
}

void List::inserts(int x)
{
	node *temp,*hand;
	hand=start;
	temp=new node;
	temp->data=x;
	temp->next=start;
	start=temp;
	listcount++;
	void bsearchll(int,int,int);
}

void List::inserte(int x)
{
	node *temp,*hand;
	temp=new node;
	temp->data=x;
	hand=start;
	while(hand->next!=NULL)
	 hand=hand->next;
	hand->next=temp;
	hand=hand->next;
	hand->next=NULL;
	listcount++;
}

node* List::indextoaddress(int i)
{
	node *hand;
	hand=start;
	for(int j=0;j<i-1;j++)
		hand=hand->next;
	return hand;
}

void List::mergell(int l,int mid,int u)
{
	node *hand;
	hand=new node;
	hand->next=NULL;
	int i=l,
	j=mid+1;
	int n=u-l+1;
	int k=0;
	int *brr=new int[n];
	while(i<=mid||j<=u)
	{
		if(i>mid||j>u)					
		 {
		 	if(i>mid&&j<=u)
		 	 {
				hand=indextoaddress(j);
				brr[k++]=hand->data;
				j++;
			 }
		 	else if(i<=mid&&j>u)
		 	 {
				hand=indextoaddress(i);
				brr[k++]=hand->data;
				i++;
			 }
		 }
		else
		 {
		    node *first,*second;
			first=indextoaddress(i);
			second=indextoaddress(j);
			if((first->data)<(second->data))
		     {
				hand=indextoaddress(i);
				brr[k++]=hand->data;
				i++;
			 }
		    else
		     {
				hand=indextoaddress(j);
				brr[k++]=hand->data;
				j++;
			 }
	     }
    }
        
		for(int k=0;k<n;k++)
		 {
			hand=indextoaddress(l+k);
			hand->data=brr[k];
		 }
		
		
	
}

void List::mergesortll(int i,int j)
{
	if(i==j)
	 int pqr=1;
	
	else
	{
		int mid=(i+j)/2;
		mergesortll(i,mid);
		mergesortll(mid+1,j);
		mergell(i,mid,j);
	}
}
int main()
{
	List x;
	x.inserts(1);
	x.inserte(4);
	x.inserte(2);
	x.inserte(5);
	x.inserte(3);
	x.display();
	x.mergesortll(0,x.countL()-1);
	cout<<"Displaying Sorted Array after Merge Sort Operation"<<endl;
	x.display();
	return 0;
}

