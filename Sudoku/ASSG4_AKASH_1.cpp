#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct list{
	struct Node* head;
};

struct Graph{
	int v;
	struct list* arr;
	int visted[1000];
};

Graph* make_graph(int v){
	int i;
	Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->arr=(struct list*)malloc(sizeof(struct list)*v);
	graph->v=v;
	for(i=0;i<v;i++){
		graph->visted[i]=0;
		graph->arr[i].head=NULL;
	}
	return graph;
}
struct Node* creat_node(int data){
	struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}
 void add_edge(struct Graph* graph,int e1,int e2 ){
 	if(e1 <graph->v && e1 <graph->v ){
 		if(graph->arr[e1].head==NULL)
 		graph->arr[e1].head=creat_node(e1);;
	 
	 struct Node* newnode2=creat_node(e2);
	 struct Node* temp=graph->arr[e1].head;
	 while(temp->next!=NULL){
	 	temp=temp->next;
	 }
	 temp->next=newnode2;
	 }
 }

void display(struct Graph* graph){
	int i;
	for(i=0;i<graph->v;i++){
	 struct Node* temp=graph->arr[i].head;
	 while(temp){
	 	printf(" %d ",temp->data);
	 	temp=temp->next;
	 }
	 if(graph->arr[i].head!=NULL)
	 printf("\n");
	}
}

void DFS(struct Graph* graph,int s){
    graph->visted[s]=1;
    
   // printf(" vidted %d ",graph->visted[s]);
    printf("%d ",s);
    struct Node* temp=graph->arr[s].head;
   // printf("%d ",temp->data);
    while(temp){
    	if(graph->visted[temp->data]==0){
    	//	printf("temp %d ",temp->data);
			DFS(graph,temp->data);    		
		}
		temp=temp->next;
	}
	
}

int main(){
	int v,e,e1,e2,s;
	printf("Enter vertex and edge");
	scanf("%d %d",&v,&e);
	struct Graph* graph=make_graph(v);
	while(e--){
	printf("enter two edegs");
	scanf("%d %d",&e1,&e2);
	add_edge(graph,e1,e2);
	}
	display(graph);
	printf("Enter source vertex");
	scanf("%d",&s);
	DFS(graph,s);
}
