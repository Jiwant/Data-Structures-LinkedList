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
		void ssortll();
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

void List::ssortll()
{
	node *first,*second;
	for(int i=0;i<listcount-1;i++)
		for(int j=i+1;j<listcount;j++)
			{
				first=indextoaddress(i);
				second=indextoaddress(j);
				if((first->data)>(second->data))
					swapll(first,second);
			}
	cout<<endl<<"Array after Selection Sort Operation"<<endl;
	display();
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
	x.ssortll();
	return 0;
}

