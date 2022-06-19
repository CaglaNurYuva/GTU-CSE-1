#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char bookname[30];
	char author[30];
	int year;
	struct node *next;
};



struct node * insert_node(struct node *root, char * b, char * a, int y){
  // case 1
  if (root==NULL){
    root=(struct node *)malloc(sizeof(struct node));
    root->next=NULL;
    strcpy(root->bookname,b);
    strcpy(root->author,a);
    root->year = y;
    return root;
  }
  // case 2
  if (root->year >= y){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    strcpy(temp->bookname,b);
    strcpy(temp->author,a);
    temp->year 	= y;
    temp->next=root;
    return temp;
  }
  
  // case 3
  struct node * iter=root;
  while(iter->next!=NULL && iter->next->year < y )
    iter=iter->next;
  struct node * temp=(struct node *)malloc(sizeof(struct node));
  temp->next=iter->next;
  iter->next=temp;
    strcpy(temp->bookname,b);
    strcpy(temp->author,a);
  temp->year = y;
  return root;
}
void print_nodes(struct node *n){
	printf("Printing linked list... \n\n");
	while(n != NULL){
		printf("%s\t%s\t%d\n",n->bookname, n->author, n->year);
		n = n->next;
	}
	printf("\n");
}

struct node* delete_node(struct node *root, char * bn){
    if(root == NULL){ //if there is no element
    	printf("There is no element in the list.\n\n");
        return root;
	}
	
	else if (strcmp(root->bookname, bn)==0){ //if the first element is what we are looking for
		struct node *temp = root->next;
		free(root);
		printf("%s has been deleted.\n\n",bn);
		return temp;
	}
	
	else{
		struct node *iter = root;
		struct node *previousNode;
		int flag = 0;
		
		// this loop will try to find the element. if it finds iter will keep this element and previousNode will keep the the previous one. 
		do{
			if(strcmp(iter->bookname, bn)==0){
				flag = 1;
				break;
			}
			previousNode = iter;	
			iter = iter->next;	
		}while (iter!=NULL);
		
		
		// if we found the element in the loop, we delete it
		if(flag==1){
			previousNode ->next = iter->next;
			free(iter);
			printf("%s has been deleted.\n\n",bn);
			return root;
		}
		
		// if we couldn't find the element, return
		else{
			printf("%s is not in the list.\n\n", bn);
			return root;
		}
	}
}

struct node* read_file (){
	FILE *fptr = fopen("source.txt","r");
	if (fptr==NULL){
		printf("Couldn't open the file'.");
		exit(1);
	}
	struct node *root = NULL;
	char bookname[30];
	char author[30];
	int year;
	while (!feof(fptr)){
		fscanf(fptr,"%s %s %d", bookname, author, &year);
		root = insert_node(root, bookname, author, year);
	}
	fclose(fptr);
	return root;
}


int main(){
	struct node* root = read_file();
	print_nodes(root);
	char str[30];
	printf("Which book do you want to delete? ");
	scanf("%s", str);
	root = delete_node(root, str);
	print_nodes(root);
}
