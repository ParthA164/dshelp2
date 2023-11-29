#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node*next;
		Node*prev;
		Node(int data){
			this->data=data;
			next=NULL;
			prev=NULL;
		}
};

class DoublyLinkedList{
	private:
		Node*head;
    public:
    	DoublyLinkedList(){
    		head=NULL;
		}
		
		
    bool Search(int element){
    	Node* current=head;
    	while(current!=NULL){
    		if(current->data==element){
    			return true;
			}
			current=current->next;
		}
		return false;
	}
	
	void Display(){
		if(head==NULL){
			cout<<"Linked list is empty"<<endl;
			return;
		}
		Node* current=head;
		while(current!=NULL){
			cout<<current->data<<" ";
			current=current->next;
		}
	}
	
	void InsertAtBeginning(int element){
		Node* newNode=new Node(element);
		if(head==NULL){
			head=newNode;
			return;
		}
		else{
			newNode->next=head;
			head->prev=newNode;
			head=newNode;
		}
		
	}
	void InsertAtEnd(int element){
		Node* newNode=new Node(element);
		if(head==NULL){
			head=newNode;
			return;
		}
		Node* current=head;
		while(current->next!=NULL){
			current=current->next;
		}
		current->next=newNode;
		newNode->prev=current;
		
	}
	void InsertAfterSpecificValue(int element,int value){
		Node* newNode=new Node(element);
		Node* current=head;
		while(current!=NULL){
			if(current->data==value){
				newNode->next=current->next;
				newNode->prev=current;
				if(current->next!=NULL){
					current->next->prev=newNode;
				}
				current->next=newNode;
				return;
			}
			current=current->next;
		}
		cout<<"Value not found in the list"<<endl;
	}
	void DeleteFromBeginning(){
		if(head==NULL){
			cout<<"Linked list is Empty"<<endl;
			return;
		}
		Node* temp=head;
		head=head->next;
		if(head!=NULL){
		head->prev=NULL;
	}
		delete temp;
	}
	
	void DeleteFromEnd(){
		if(head==NULL){
			cout<<"Linked list is Empty"<<endl;
			return;
		}
		Node* current=head;
		if(head->next==NULL){
			delete head;
			return;
		}
		while(current->next->next!=NULL){
			current=current->next;
		}
		delete current->next;
		current->next=NULL;
		
	}
	void DeleteAfterSpecificNode(int value){
		if(head==NULL){
			cout<<"Linked list is empty"<<endl;
			return;
		}
		Node* current=head;
		while(current!=NULL && current->data!=value){
			current=current->next;
		}
		if(current==NULL){
			cout<<"Value not found in the list"<<endl;
			return;
		}
		else{
			if(current->next!=NULL){
			Node*temp=current->next;
			current->next=temp->next;
			if(temp->next!=NULL){
				temp->next->prev=current;
			}
				delete temp;
				return;
		}
		else{
			cout<<"Nothing to delete after value"<<endl;
			return;
			
		}
		}
	}
	
};






int main(){
	DoublyLinkedList l1;
	l1.InsertAtEnd(10);
	l1.InsertAtEnd(20);
	l1.InsertAtEnd(30);
	l1.InsertAtEnd(40);
	l1.InsertAtBeginning(100);
	l1.InsertAfterSpecificValue(200,100);
	l1.DeleteFromBeginning();
//	l1.DeleteFromEnd();
	l1.DeleteAfterSpecificNode(20);
	l1.DeleteAfterSpecificNode(20);
	l1.Display();
	
	
	return 0;
}
