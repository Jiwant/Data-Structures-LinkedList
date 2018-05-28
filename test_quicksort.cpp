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
 cout<<11111<<endl;
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
		int partitionll(int,int);
		void quicksortll(int,int);
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

int List::partitionll(int p,int q)
{
	node *pivot,*first,*second;
	pivot=indextoaddress(p);
	int x=pivot->data;
	int i,j;
	i=p;
	for(j=p+1;j<=q;j++)
	{
		second=indextoaddress(j);
		if(second->data<=x)
		{
			i=i+1;
			first=indextoaddress(i);
			swap(first,second);
		}
	}
	swapll(pivot,first);
	return i;
}

void List::quicksortll(int p,int q)
{
	if(p>=q)
    {
        int pqr=3;
         return;
	}
   	 
	
	else
	{
		int m=partitionll(p,q);
		quicksortll(p,m-1);
		quicksortll(m+1,q);
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
	x.quicksortll(0,x.countL()-1);
	cout<<"Displaying Sorted Array after Merge Sort Operation"<<endl;
	x.display();
	return 0;
}

