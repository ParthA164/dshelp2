#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		Node(int data){
			this->data=data;
			prev=NULL;
			next=NULL;
		}

};

class CircularDLL{
	private:
		Node* head;
	public:
		CircularDLL(){
			head=NULL;
		}
      void InsertAtBeginning(int element){
    	Node* newNode=new Node(element);
       	if(head==NULL){
       		newNode->next=newNode->prev=newNode;
		   }
		else{
			newNode->next=head;
			newNode->prev=head->prev;
			head->prev->next=newNode;          // check once
			head->prev=newNode;
		}
		head=newNode;
	}
	
	void InsertAtEnd(int element){
		Node* newNode=new Node(element);
		if(head==NULL){
			newNode->next=newNode->prev=newNode;
			head=newNode;
		}
		else{
			
			newNode->next=head;
		    newNode->prev=head->prev;
		    head->prev->next=newNode;
			head->prev=newNode;
		}
	}
	
	void InsertAfterSpecificValue(int element , int value){
		Node* newNode=new Node(element);
		if(head==NULL){
			newNode->next=newNode->prev=newNode;
			head=newNode;
		}
		else{
			Node* current=head;
			while(current->next!=head && current->data!=value){
				current=current->next;
			}
			if(current->data!=value && current->next==head){
				cout<<"Value not found in the list ";
				return;
			}
			else{
			   newNode->next=current->next;
			   current->next->prev=newNode;
			   current->next=newNode;
			}
		}
	}
     
     void deleteFromBeginning(){
     	if(head==NULL){
     		cout<<"Linked list is empty";
     		return;
		 }
		 else{
		 	Node* temp=head;
		 	if(head->next==head){
		 		head=NULL;
			 }
			 else{
			 	head->prev->next=head->next;
			 	head->next->prev=head->prev;
			 	head=head->next;
			 	
			 }
			 delete temp;
		 }
	 }
	 
	 void DeleteFromEnd(){
	 	if(head==NULL){
	 		cout<<"Linked list is empty";
	 		return;
		 }
		 else{
		 	Node* current=head;
		 	while(current->next!=head){
		 		current=current->next;
			 }
			 if(current==head){
			 	head=NULL;
			 }
			 else{
			 	current->prev->next=head;
			 	head->prev=current->prev;
			 }
			 delete current;
		 }
	 }
	 void DeleteSpecificNode(int value){
	 	if(head==NULL){
	 		cout<<"Linked list is empty "<<endl;
		 }
		 else{
		 	Node* current=head;
		 	while(current->next!=head && current->data!=value){
		 		current=current->next;
			 }
			 if(current->data!=value){
			 	cout<<"Value not found"<<endl;
			 	return;
			 }
			 else if(current==head){
			 	deleteFromBeginning();
			 }
			 else if(current->next==head){
			 	DeleteFromEnd();
			 }
			 else{
			 	current->prev->next=current->next;
			 	current->next->prev=current->prev;
			 	delete current;
			 }
		 }
	 }
     void Display(){
     	if(head==NULL){
     		cout<<"Linked list is empty"<<endl;
     		return;
		 }
		 Node*current=head;
		 do{
		 	cout<<current->data<<" ";
		 	current=current->next;
		 }while(current!=head);
		 cout<<endl;
		 
		 
	 }
};




int main(){
	CircularDLL q1;
	q1.InsertAtEnd(10);
	q1.InsertAtEnd(20);
	q1.InsertAtEnd(30);
	q1.InsertAtEnd(40);
	q1.Display();
    q1.DeleteSpecificNode(20);
    q1.DeleteFromEnd();
    q1.deleteFromBeginning();
    q1.InsertAtBeginning(50);
    q1.InsertAtEnd(10);
    q1.InsertAfterSpecificValue(20,30);
	q1.Display();
	
}
