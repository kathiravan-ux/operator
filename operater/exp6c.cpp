#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_name_len 20
typedef num{file_node,directory_node} node type
typedef struct node{
	char name[max_name_len];
	node type type;
	struct node*parent;
	struct node*child;
	struct node*siblings;
}node;
node*create node(const char*name,nodetype type);
void add child(node*parent,node*child);
node*findchild(node*parent,const char*name);
void printtree(node*root,int depth);
node*navigation(node*root,const char*path);
int main(){
	node*root=create node("root",directory_node);
	node*current=root;
	char command[10],name[max_name_len],path[100];
	printf("tree directory structure simulation\n");
while(1){
	printf("\ncurrentdirectory:%s\n",current->name);
	printf("command:\n");
	printf("mkdir<dirname>-createdirectory\n");
	printf("touch<filename>-create file\n");
	printf("cd<dirname-change directory\n");
	printf("/s-list connects\n");
	printf("tree-display tree\n");
	printf("exit-quit\n");
	printf("enter commands");
	scanf("%s",name);
	if(find child (current name)!=NULL){
		printf("directory or file with name '%s' already exits\n",name);
	}else{
		node*dir=createnode(name,directory_node);
		add child(current,dir);
		printf("directory'%s'created\n",name);
	}
	}
	else if(strcmp(command,"touch")==0){
		scanf("%s",name);
		if(find child(current,name)!=NULL){
			printf("directory or file name'%s'already exists\n",name);
	}else{
		node*file=createnode(name,file_node);
		addchild(current,file);
		printf("file '%s'created\n",name);
	}
	}
	else if(strcmp(command,"cd")==0){
		scanf("%s",name);
		if(strcmp(name"..")==0){
			if(current->parent!=NULL)current=current->parent;
			else print("already at the root directoru\n");
		}else{
			node*dir=find child(current,name);
			if(dir!=NULL&&dir->type==directory_node){
				current=dir;
			}else{
				printf("directory not found:%s\n",name);
			}
		}
	}
    else if(strcmp(command,"Ls")==0){
	    node*temp=current->child;
	    if(temp==NULL){
		    printf("directory is empty\n");
		    while(temp!=NULL){
			    printf("%s\t%s\n",temp->name,temp->type==directory_node?"<dir>":"<file>");
			    temp=temp->sibling;
		    }
	    }
	    else if(strcmp(command,"tree")==0){
	    	print tree(root,0);
		}
		else if(strcmp(command,"exit")==0){
			break;
		}else{
			printf("invalid command\n");
		}
    }
    return 0;
}
node*create node(const char*name,nodetype type){
	node*node=(node*)malloc(sizeof(node));
	strcpy(node->name,name);
	node->type=type;
	node->parent=NULL;
	node->child=NULL;
	node->siblings=NULL;
}
void add child(node*parent,node*child){
	child->parent=parent;
	if(parent->child==NULL){
		parent->child=child;
	}else{
		node*temp=parent->child;
		while(temp->sibling!=NULL){
			temp->sibling=child;
		}
	}
	}
	node*find child(node*parent,const char*name)
	node*temp=parent->child;
	while(temp!=NULL){
		if(strcmp(temp->name,name)==0){
			return temp;
		}temp=temp->sibling;
	}return NULL;
}
void print