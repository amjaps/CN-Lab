/*  
	Name- Amar Soni
	Roll- 411702

	This code is to calculate routing table for each node using Distance Vector Algorithm(DVA).
	Assumptions are - 	1.maximum number of node this code can accept is 30
		      			2.This code will consider 16 as infinity to avoid counting to infinity problem
		      			3.if there is no path between given nodes, distace will be 16 and next hop id will be 							max_node+1(i.e. 31)
*/
#include<iostream>
using namespace std;

#define max_node 30

struct Node{
	int dist[max_node];
	int next[max_node];
};

int main(){
	int nodes,i,j,k,flag=0;
	cout<<"Enter the number of nodes in network  ";
	cin>>nodes;
	
	struct Node vertice[nodes];
	int costmat[nodes][nodes];
	cout<<"Enter the cost matrix (assuming 16 as infinity) ";
	for(i=0;i<nodes;i++){
		for(j=0;j<nodes;j++){
			cin>>costmat[i][j];
			if(costmat[i][j]<17){
				vertice[i].dist[j]=costmat[i][j];
				if(costmat[i][j]<16){
					vertice[i].next[j]=j;
				}
				else{
					vertice[i].next[j]=max_node+1;
				}
			}
			else{
				cout<<"Cost should not exceed infinity which is 16. Please re-run the program.";
				return 1;
			}
		}	
	}


	//calculation of DVA
	do{
		flag=0;		
		for(i=0;i<nodes;i++){
			for(j=0;j<nodes;j++){
				for(k=0;k<nodes;k++){
					if(vertice[i].dist[j]>costmat[i][k]+vertice[k].dist[j]){
						if(costmat[i][k]+vertice[k].dist[j]<16){
							vertice[i].dist[j]=costmat[i][k]+vertice[k].dist[j];
							vertice[i].next[j]=k;
							flag++;				
						}
						else{
							vertice[i].dist[j]=16;
							vertice[i].next[j]=max_node+1;
							flag++;	
						}			
					}
				}
			}
		}
	}while(flag!=0);

	for(i=0;i<nodes;i++){
		cout<<"For Node "<<i+1<<endl;
		for(j=0;j<nodes;j++){
			cout<<"Node "<<j+1<<" distance "<<vertice[i].dist[j]<<" next "<<vertice[i].next[j]+1<<endl;
		}
	}
	return 0;
}
