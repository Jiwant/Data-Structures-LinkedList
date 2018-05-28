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
};
