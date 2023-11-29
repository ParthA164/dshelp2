#include<iostream>
#include<vector>
using namespace std;


class PriorityQueue{
	vector<int> pq;
	public:
		PriorityQueue(){
			
		}
		bool isEmpty(){
			return pq.size()==0;
		}
		int getSize(){
			return pq.size();
		}
		int getMax(){
			if(isEmpty()){
				return 0;
			}
			return pq[0];
		}
		void insert(int element){
			pq.push_back(element);
			int childIndex=pq.size()-1;
			while(childIndex>0){
				int parentIndex=(childIndex-1)/2;
				if(pq[childIndex]>pq[parentIndex]){
					int temp=pq[parentIndex];
					pq[parentIndex]=pq[childIndex];
					pq[childIndex]=temp;
				}
				else{
					break;
				}
				childIndex=parentIndex;
			}
		}
		
		int removeMax(){
			if(isEmpty()){
				return 0;
			}
			int ans=pq[0];
			pq[0]=pq[pq.size()-1];
			pq.pop_back();
			int parentIndex=0;
			int leftChildIndex=2*parentIndex+1;
			int rightChildIndex=2*parentIndex+2;
			while(leftChildIndex<pq.size()){
				int maxIndex=parentIndex;
				if(pq[maxIndex]<pq[leftChildIndex]){
					maxIndex=leftChildIndex;
				}
				if(pq[maxIndex]<pq[rightChildIndex] && rightChildIndex<pq.size()){
					maxIndex=rightChildIndex;
				}
				if(maxIndex==parentIndex){
					break;
					
				}else{
				
				int temp=pq[maxIndex];
				pq[maxIndex]=pq[parentIndex];
				pq[parentIndex]=temp;
			}
			parentIndex=maxIndex;
			leftChildIndex=2*parentIndex+1;
			rightChildIndex=2*parentIndex+2;
			}
			return ans;
		}
		
		void print(){
			for(int i=0;i<pq.size();i++){
				cout<<pq[i]<<" ";
			}
		}
		
};



int main(){
	PriorityQueue p;
	p.insert(50);
	p.insert(15);
	p.insert(25);
	p.insert(105);
	p.insert(3);
	p.print();
	
	return 0;
}
