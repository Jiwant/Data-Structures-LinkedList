#include<iostream>
using namespace std;
//Node is used as Element of Linked List
struct node
{
	int data;
	node *next;
};
//List is used to build complex Linked List
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
		void bsearchll(int,int,int);
		~List();
};

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
	int n=0;
	node *hand;
	hand=start;
	while(hand!=NULL)
	 {
	  hand=hand->next;
	  n++;
	 }
     
     return n;
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

void List::bsearchll(int n,int l,int u)
{
	node *lower,*upper;
	lower=indextoaddress(l);
	upper=indextoaddress(u);
	if(l==u)
	{
		if(lower->data!=n)
		cout<<"Number dont exist in the Array List"<<endl;
		else
		cout<<"Position of Element "<<u+1<<endl;
	}
	if((lower->data)!=(upper->data))
	{
		int mid=(l+u)/2;
		node *middle;
		middle=indextoaddress(mid);
		if(n==(middle->data))
			bsearch(n,mid,mid);
		else
		{
			if(n<(middle->data)) 
				bsearch(n,l,mid-1);
			else
				bsearch(n,mid+1,u);
		 }
	}
}

int main()
{
	List x;
	x.inserts(1);
	x.inserte(2);
	x.inserte(3);
	x.inserte(4);
	x.inserte(5);
	x.display();
	return 0;
}
