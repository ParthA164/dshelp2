#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node*next;
	
		Node(int data){
			this->data=data;
			next=NULL;
			
		}
		
};

class CircularSinglyLinkedList{
	private:
		Node* head;
	public:
		CircularSinglyLinkedList(){
			head=NULL;
		}
		
		bool Search(int value){
			if(head==NULL){
				cout<<"Linked List is Empty"<<endl;
				return false;
			}
			Node* temp=head;
			do{
				if(temp->data=value){
					cout<<"Element found "<<endl;
					return true;
				}
				temp=temp->next;
			}while(temp!=head);
			cout<<"Element not found"<<endl;
			return false;
		}
		
		void Display(){
			if(head==NULL){
				cout<<"Linked list is empty"<<endl;
				return;
			}
			Node* temp=head;
			do{
				cout<<temp->data<<" ";
				temp=temp->next;
			}while(temp!=head);
			cout<<endl;
		}
		void InsertAtBeginnning(int element){
			Node* newNode=new Node(element);
			if(head==NULL){
				head=newNode;
				newNode->next=head;
			}
			else{
				Node* current=head;
				while(current->next!=head){
					current=current->next;
				}
				current->next=newNode;
				newNode->next=head;
				head=newNode;
			}
		}
		
		void InsertAtEnd(int element){
			Node* newNode=new Node(element);
			if(head==NULL){
				head=newNode;
				newNode->next=head;
			}
			else{
				Node* current=head;
				while(current->next!=head){
					current=current->next;
				}
				current->next=newNode;
				newNode->next=head;
				
			}
		}
		
		void InsertAfterSpecificValue(int element, int value){
			Node* newNode=new Node(element);
			if(head==NULL){
				head=newNode;
				newNode->next=head;
			}
			else{
				Node* current=head;
				while(current->next!=head && current->data!=element){
					current=current->next;
				}
				if(current->next==head && current->data!=value){
					cout<<"Value not present in the list"<<endl;
					return;
				}
				else{
					newNode->next=current->next;
					current->next=newNode;
					
				}
			}
		}
		void DeleteFromBeginning(){
			if(head==NULL){
				cout<<"Linked List is empty"<<endl;
				return;
			}
			Node*temp=head;
			if(head->next==head){
				head=NULL;
			}
			else{
				Node*current=head;
				while(current->next!=head){
					current=current->next;
				}
				head=head->next;
				current->next=head;
			}
			delete temp;
		}
		void DeleteFromEnd(){
			if(head==NULL){
				cout<<"Linked List is Empty"<<endl;
				return;
			}
			
			if(head->next==head){
				head=NULL;
			}
			else{
				Node* current=head;
				while(current->next->next!=head){
					current=current->next;
				}
				Node*temp1=current->next;
				current->next=head;
				delete temp1;
				
			}
		}	
		void DeleteFromEnd2(){
			if(head==NULL){
				cout<<"Linked List is Empty"<<endl;
				return;
			}
			
			if(head->next==head){
				head=NULL;
			}
			else{
				Node* current=head;
				Node*prev=NULL;
				while(current->next!=head){
					prev=current;
					current=current->next;
				}
				prev->next=head;
			    delete current;
				
			}
		}	
		void DeleteSpecificValue(int value){
			if(head==NULL){
				cout<<"Linked list is empty"<<endl;
				return;
			}
			Node* current=head;
			Node* prev=NULL;
			while(current->next!=head && current->data!=value){
				prev=current;
				current=current->next;
			}
			if(current->data!=value){
				cout<<"Value not found"<<endl;
				return;
			}
			else if(current==head){
				DeleteFromBeginning();
			}
			else if(current->next==head){
				DeleteFromEnd();
			}
			else{
				prev->next=current->next;
				delete current;
			}
			
		}
		
};

int main(){
	
	CircularSinglyLinkedList q1;
	q1.InsertAtEnd(10);
	q1.InsertAtEnd(20);
	q1.InsertAtEnd(30);
	q1.InsertAtEnd(40);
	q1.Display();
    q1.DeleteSpecificValue(20);
	q1.Display();
	
	
	return 0;
}
