#include<iostream>
using namespace std;

struct Node{		// Node Structures
	int data;			// data field of Node 
	Node* adrs;		// Address field of Node
	
	Node(int val){		// Node constructor
		data = val;
		adrs = NULL;
	}	
};

class LinkedList{
	private:
		Node* head;		// declare head variable
		Node* current;	// declare temp variable		
	public:
		LinkedList(){		// constructor
			head = NULL;
		}		
		
		// ADD one new Node in the Last of List
		void addNode(int value){
			Node* newNode = new Node(value);
			
			if(head == NULL){		// if list is not Exist
				head = newNode;
				return;							
			}
			current = head;
			while(current->adrs != NULL){	// if Already list Exist
				current = current->adrs;
			}				
			current->adrs = newNode;
			//current = newNode;					
		}
		
		// ADD new Node in the Start of List
		void addNodeS(int value){
			Node* newNode = new Node(value);
			
			if(head == NULL){		// if list is not Exist
				head = newNode;
				return;							
			}					
			newNode->adrs = head;
			head = newNode;
			current = newNode;					
		}
		
		// print the complete list of nodes
		void printList(){
			if(head == NULL){
				cout<<"List is Empty"<<endl;				
			}
			else{
				current = head;
				while(current != NULL){
					cout<<current->data<<"   ";
					current = current->adrs;
				}
				cout<<"\n"<<endl;
			}			
		}
		
		//search Node
		void searchNode(int s_val){
			if(head == NULL){
				cout<<"List is Empty"<<endl;
				return;
			}
			current = head;
			while(current != NULL){
				if(current->data == s_val){
					cout<<"Value "<<current->data<<" is Found"<<endl;
					return;
				}
				current = current->adrs;				
			}
			cout<<"Data Not Found"<<endl;
		}
		
		//Delete Head Node from List
		void deleteHead(){
			if(head == NULL){
				cout<<"List is Empty"<<endl;
				return;
			}			
			current = head;
			head = head->adrs;				
			delete current;
		}
		
};

int main(){
	LinkedList obj;
	int s_val;
		
	obj.addNodeS(50);
	obj.addNodeS(70);
	obj.addNodeS(20);
	obj.addNodeS(30);	
		
	obj.printList();
	
	cout<<"Enter the searching value: ";
	cin>>s_val;
	obj.searchNode(s_val);
	
	obj.printList();
		
	obj.deleteHead();
	
	obj.printList();
	
	return 0;
}
