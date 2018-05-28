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
 cout<<"Swapping is taking place here"<<endl;
}

class List
{
	private:
	node *start;
	int listcount;
	
	public:
		List();
		void status();
		void display();
		int countL();
		void inserts(int);
		void insertm(int,int);
		void inserte(int);
		void insert();
		void deleteNodes();
		void deleteNodem(int);
		void deleteNodee();
		void deleteNode();
		void lsearchll(int);
		node *indextoaddress(int);
		void bsearchll(int,int,int);
		void bsortll();
		
};

List::List()
{
	start=NULL;
	listcount=0;
}


void List::status()
{
	if(start==NULL)
	 cout<<"List is Empty"<<endl;
	else if(start->next==NULL)
	 cout<<"List is Single Element List"<<endl;
	else
	 cout<<"List is Multiple Element List"<<endl;
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
}

void List::insertm(int x,int n)
{
	node *temp,*hand;
	hand=start;	
	temp=new node;
	temp->data=x;
	for(int j=0;j<n-2;j++)
	 hand=hand->next;
	temp->next=hand->next;
	hand->next=temp;
	listcount++;
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

void List::insert()
{
	int n=countL();
	int x,i;
	cout<<"Enter the Value You want to insert into List"<<endl;
	cin>>x;
	cout<<"Enter the Position at which You want to Insert into List"<<endl;
	cin>>i;
	if(i>0&&i<=listcount+1)
	{
	  if(i==1)
		inserts(x);
	 else if(i>1&&i<n)
		insertm(x,i);
	 else
		inserte(x);
    }
    
    else
      cout<<"Entered Position is Invalid"<<endl<<"Enter a Valid Position"<<endl;
}

void List::deleteNodes()
{
 node *hand;
 hand=start;
 start=start->next;
 hand->next=NULL;
 delete hand;
 --listcount;
}

void List::deleteNodem(int i)
{
	node *hand,*end;
	hand=start;
	for(int j=0;j<i-2;j++)
	 hand=hand->next;
	end=hand->next;
	hand->next=hand->next->next;
	end->next=NULL;
	delete end;
	--listcount;
}

void List::deleteNodee()
{
	node *hand,*temp;
	hand=start;
	while(hand->next->next!=NULL)
	{
		hand=hand->next;
	}
	temp=hand->next;
	temp->next=NULL;
	delete temp;
	hand->next=NULL;
	--listcount;
}

void List::deleteNode()
{
	int i,n;
	cout<<"Enter the Position from where you want to delete Node"<<endl;
	cin>>i;
	n=listcount;
	if(i>0&&i<=listcount)
	{
	  if(i==1)
		deleteNodes();
	 else if(i>1&&i<n)
		deleteNodem(i);
	 else
		deleteNodee();
    }
    
    else
      cout<<"Entered Position is Invalid"<<endl<<"Enter a Valid Position"<<endl;
}

void List::lsearchll(int x)
{
	int t=0;
	int i=1;
	node *head;
	head=start;
	
	while(head!=NULL)
	{
		if(head->data==x)
		{
			cout<<"Search Number Index is "<<i<<endl;
			t=1;
		}
		
		i++;
		head=head->next;
	}
	
	if(t==0)
		cout<<"Number does not exist in List"<<endl;
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
		cout<<"Number dont exist in the Linked List"<<endl;
		else
		cout<<"Position of Element "<<u<<endl;
	}
	if((lower->data)!=(upper->data))
	{
		int mid=(l+u)/2;
		node *middle;
		middle=indextoaddress(mid);
		if(n==(middle->data))
			bsearchll(n,mid,mid);
		else
		{
			if(n<(middle->data)) 
				bsearchll(n,l,mid-1);
			else
				bsearchll(n,mid+1,u);
		 }
	}
}

void List::bsortll()
{
 node *first,*second;
 for(int i=0;i<listcount-1;i++)
  for(int j=0;j<listcount-i-1;j++)
   {
    first=indextoaddress(j);
    second=indextoaddress(j+1);
    cout<<first->data<<" "<<second->data<<endl;
	if((first->data)>(second->data))
     {swapll(first,second);cout<<"After Swapping"<<first->data<<" "<<second->data<<endl;}
   }
 cout<<endl<<"Array after Bubble Sort Operation"<<endl;
 display();
}

int main()
{
	List x;
	int s,t=1;
	while(t)
	{
	  system("cls");
	  cout<<"Select 1 if you want to Insert the Data into Linked List"<<endl;
	  cout<<"Select 2 if you want to Delete the Data from Linked List"<<endl;
	  cout<<"Select 3 if you want to Display the Elements of Linked List"<<endl;
	  cout<<"Select 4 if you want to Display the Status of Linked List"<<endl;
	  cout<<"Select 5 if you want to Display the Length of Linked List"<<endl;
	  cout<<"Select 6 if you want to Linear Search from Linked List"<<endl;
	  cout<<"Select 7 if you want to Binary Search from Linked List"<<endl;
	  cout<<"Select 8 if you want to Bubble Sort the Linked List"<<endl;
	  cout<<"Select 9 if you want to Exit from Program"<<endl;
	  cin>>s;
	  switch(s)
	   {
		 case 1:
		   x.insert();
		   goto d;
		 case 2:
		   x.deleteNode();
		   goto d;
		 case 3:
		 	x.display();
		 	goto d;
		 case 4:
		 	x.status();
		 	goto d;
	     case 5:
	      	cout<<"Length of the Linked List is "<<x.countL()<<endl;
	      	goto d;
	      	
	     case 6:
	     	int searchit;
			cout<<"Enter the Number you want to Search in Linked List"<<endl;
	     	cin>>searchit;
	     	x.lsearchll(searchit);
	     	goto d;
	     case 7:
		 	int bsearchit;
			cout<<"Enter the Number you want to Search in Linked List"<<endl;
			cin>>bsearchit;
			x.bsearchll(bsearchit,0,x.countL()-1);
			goto d;
		 case 8:
		 	x.bsortll();
		 	goto d;
				
	     case 9:
	      	t=0;
		    goto d;
		    
			d:
		    	
		  default:
		  	char c;
			cout<<"Enter a Character to continue"<<endl;
		  	cin>>c;
		  	break;
       }
    }
	return 0;
}

