/*  
	Name- Amar Soni
	Roll- 411702

	This code is to calculate routing table for source node using Link State Algorithm(LSA).
	Assumptions are - 
				1.maximum number of node this code can accept is 30
				2.This code will consider 16 as infinity to avoid counting to infinity problem
				3.if there is no path between given nodes, distanceace will be 16 and next hop id will be max_node+1(i.e. 31)

*/


#include<iostream>
using namespace std; 

#define max_node 30

struct Node{
	int distance;
	int previous;
	int indicator;
};

int main(){
	int nodes,src_node,i,j,k,min;
	cout<<"Enter the number of nodes in the network  ";
	cin>>nodes;
		
	struct Node vertex[nodes];
	int costMatrix[nodes][nodes];
	cout<<"Enter the cost matrix (assuming 20 as infinite) ";
	for(i=0;i<nodes;i++){
		for(j=0;j<nodes;j++){
			cin>>costMatrix[i][j];
			if(costMatrix[i][j]>20){
				cout<<"Cost should not exceed infinity which is 20 here. Please start the program again.";
				return 1;
			}
		}
	}

	cout<<" Enter the source router: ";
	cin>>src_node;

	for(i=0;i<nodes;i++){
		vertex[i].indicator=0;
		vertex[i].distance=costMatrix[src_node][i];
		vertex[i].previous=src_node;
	}

	vertex[src_node].indicator=1;
	for(i=0;i<nodes;i++){
		min=16;
		for(j=0;j<nodes;j++){
			if(vertex[j].indicator==0){
				if(vertex[j].distance<min){
					k=j;	
					min=vertex[j].distance;
					}
			}
		}
		vertex[k].indicator=1;
		for(j=0;j<nodes;j++){
			if(vertex[j].indicator==0){
				if(vertex[j].distance>min+costMatrix[k][j]){
					vertex[j].distance=min+costMatrix[k][j];
					vertex[j].previous=k;
				}
			}
		}
	}

	
	cout<<"From "<<src_node+1<<" to :"<<endl;
	for(j=0;j<nodes;j++){
		cout<<"Node "<<j+1<<" distance "<<vertex[j].distance<<" previous "<<vertex[j].previous+1<<endl;
	}
	return 0;
}

					
		














