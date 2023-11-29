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

class SinglyLinkedList{
     	Node* head;
	public:
		
		SinglyLinkedList(){
			head=NULL;
		}
		void InsertAtBeginnnig(int element){
			Node* newNode=new Node(element);
			if (head==NULL){
				head=newNode;
				return;
			}
			newNode->next=head;
			head=newNode;
			return;
		}
		
		void InsertAtEnd(int element){
			Node* newNode=new Node(element);
			if(head==NULL){
				head=newNode;
				return;
			}
			Node* temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=newNode;
			}
			
			void InsertAfterSpecificValue(int element,int value){
				Node* newNode=new Node(element);
				Node* temp=head;
				if(head==NULL){
					head=newNode;
					return;
				}
				while(temp!=NULL && temp->data!=element){
					temp=temp->next;
				}
				if(temp==NULL){
					cout<<"Element after which value is to be inserted is not found"<<endl;
					return;
				}
				else{
					newNode->next=temp->next;
					temp->next=newNode;
					
				}
				
			}
			void InsertAfterSpecificPosition(int element,int position){
				Node* newNode=new Node(element);
				Node*temp=head;
				if(position<0){
					cout<<"Invalid position"<<endl;
					return;
				}
				if(position==0){
					newNode->next=head;
					head=newNode;
				}
				else{
					int currentPos=0;
					while(temp!=NULL && currentPos<position){
						temp=temp->next;
						currentPos++;
					}
					
					if(temp==NULL){
						cout<<"Position out of bounds"<<endl;
						return;
					}
					else{
						newNode->next=temp->next;
						temp->next=newNode;
					}
				}
			}
			
			void DeleteFromBeginning(){
				if(head==NULL){
					cout<<"Linked List is empty"<<endl;
					return;
				}
				Node*temp=head;
				head=head->next;
				delete temp;
			}
			void DeleteFromEnd(){
				if(head==NULL){
					cout<<"Linked list is empty"<<endl;
					return;
				}
				if(head->next==NULL){
					delete head;
					return;
				}
				Node* current=head;
				while(current->next->next!=NULL){
					current=current->next;
				}
				delete current->next;
				current->next=NULL;
			}
			void DeleteSpecificNode(int element){
				if(head==NULL){
					cout<<"Linked list is empty"<<endl;
					return;
				}
				Node* temp=head;
				Node* pre=NULL;
				while(temp!=NULL && temp->data!=element){
					pre=temp;
					temp=temp->next;
				}
				if(temp==NULL){
					cout<<"Element not found"<<endl;
					return;
				}
				
				if(temp==head){
					head=head->next;
				}
				else if(temp->next==NULL){
					pre->next=NULL;
					}
			    else{
			    	pre->next=temp->next;
			    	
				}
				delete temp;
				}
			
	    void DeleteSpecificPosition(int position){
	    	if(head==NULL){
	    		cout<<"Linked list is empty"<<endl;
	    		return;
			}
			if(position<0){
				cout<<"Invalid position"<<endl;
				return;
			}
			if(position==0){
				Node*temp=head;
				head=head->next;
				delete temp;
			}
			
	    	Node* current=head;
	    	int currentPos=0;
	    	while(current!=NULL && currentPos<position){
	    		current=current->next;
	    		currentPos++;
			}
			if(current==NULL || current->next==NULL){
				cout<<"Position out of bounds"<<endl;
				return;
			}
			Node*temp=current->next;
			current->next=current->next->next;
			delete temp;
		}
};

int main(){
	
	
	return 0;
}
