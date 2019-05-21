#include<iostream>
#include<windows.h>
using namespace std;

struct adjacent{
	int nodeAdj;
	adjacent* nextAdj;
};

struct element{
	int node;
	element* next;
	adjacent* firstAdj;
};

typedef element* pointerNode;
typedef adjacent* pointerAdj;
typedef pointerNode list;

void createListNode(list& first){
	first = NULL;
}

void createNode(pointerNode& pBaru,int vertex){
	pBaru = new element;
	pBaru->node = vertex;
	pBaru->next = NULL;
	pBaru->firstAdj = NULL;
}

void createAdj(pointerAdj& pBaru,int vertex){
	pBaru = new adjacent;
	pBaru->nodeAdj = vertex;
	pBaru->nextAdj = NULL;
}

void insertAdj(pointerNode& currNode,pointerAdj pBaruAdj){
	pointerAdj last;
	if(currNode->firstAdj == NULL){
		currNode->firstAdj = pBaruAdj;
	}else{
		last = currNode->firstAdj;
		while(last->nextAdj != NULL){
			last = last->nextAdj;
		}
		last->nextAdj = pBaruAdj;
	}
}

void insertElement(list& first, pointerNode pBaruNode, int size){
	pointerNode last;
	pointerAdj pBaruAdj;
	if(first == NULL){
		first = pBaruNode;
	}else{
		last = first;
		while(last->next != NULL){
			last = last->next;
		}
		last->next = pBaruNode;
	}
	if(size>0){
		cout<<"Masukan node yang berhubungan dengan "<<pBaruNode->node<<" : "<<endl;
	}
	for(int i = 0; i < size; i++){
		int vertex;
		cin>>vertex;
		createAdj(pBaruAdj,vertex);
		insertAdj(pBaruNode,pBaruAdj);
	}
}

void output(list first){
	pointerNode pOut;
	pointerAdj pOutAdj;
	if(first == NULL){
		cout<<"Tidak ada Node"<<endl;
	}else{
		pOut = first;

		while(pOut != NULL){
			cout<<"Parent = "<<pOut->node<<endl;
			if(pOut->firstAdj == NULL){
				cout<<"Tidak ada adjacency"<<endl;
			}else{
				pOutAdj = pOut->firstAdj;
				cout<<"Child = ";
				while(pOutAdj != NULL){
					cout<<pOutAdj->nodeAdj<<" ";
					pOutAdj = pOutAdj->nextAdj;
				}
			}
			cout<<endl;
			pOut = pOut->next;

		}
	}
}

int main(){
	list first;
	pointerNode node;

	createListNode(first);

	createNode(node,1);
	insertElement(first,node,2);
	createNode(node,2);
	insertElement(first,node,4);
	createNode(node,3);
	insertElement(first,node,5);
	createNode(node,4);
	insertElement(first,node,2);
	createNode(node,5);
	insertElement(first,node,4);
	createNode(node,6);
	insertElement(first,node,1);
	createNode(node,7);
	insertElement(first,node,2);
	createNode(node,8);
	insertElement(first,node,2);
	output(first);
	system("pause");
}
