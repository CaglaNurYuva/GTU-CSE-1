#include <stdlib.h> 
#include <string.h> 
#include <stdio.h> 
	 
typedef struct {
   int book_id;
   int year; 
   char title[50]; 
   char author[50]; 
   char subject[100];
}Book;

int size = 2;
int lastIndex = 0;
int run = 1;
int subrun = 1;
int selection = 0;
int counter = 0;
int subselection = 0;

Book* Books;
char tempValue[100];

void addBook(Book _Book){
	/*Control the size of array, if array is full resize the array.*/
	if(lastIndex >= size){
		Book* tempBooks = (Book*) calloc(size * 2, sizeof(Book) );
		for(int i =0; i<size; i++){
			tempBooks[i] = Books[i];
		}
		free(Books);
		Books = tempBooks;
		size *=2;
	}
	Books[lastIndex++] = _Book;
}

void listBooks(){
	printf("\nList of Books\n");
	printf("**********************\n");
	for(int i=0; i<lastIndex;i++){
			printf("%d. Book; \nTitle => %s\nAuthor => %s\nSubject => %s\nYear => %d\n", i+1, Books[i].title, Books[i].author, Books[i].subject, Books[i].year );
			printf("**********************\n");
	}
}

void sortBooks(int sort){
    Book _tempBook;
    if(sort == 1){
    	for (int i = 0; i < lastIndex - 1; i++){
        	for (int j = 0; j < (lastIndex - 1 - i); j++){
            	if (Books[j].year < Books[j + 1].year){
                	_tempBook = Books[j];
                	Books[j] = Books[j + 1];
                	Books[j + 1] = _tempBook;
            	} 
        	}
    	}
	}else if(sort == 2){
		for (int i = 0; i < lastIndex - 1; i++){
        	for (int j = 0; j < (lastIndex - 1 - i); j++){
            	if (Books[j].book_id > Books[j + 1].book_id){
                	_tempBook = Books[j];
                	Books[j] = Books[j + 1];
                	Books[j + 1] = _tempBook;
            	} 
        	}
    	}
	}
}

int main (int argc, char *argv[]) 
{
	Books = (Book*) malloc( sizeof(Book) * size ); 
	Book _tempBook;
	
	while(run){
		printf("MENU\n");
		printf("\t1. Add New Book\n");
		printf("\t2. List Books\n");
		printf("\t3. EXIT\n");
		printf("\nChoose = ");
		scanf("%d",&selection);
		printf("**********************\n");
		subrun = 1;
		switch(selection){
			case 1:
				printf("Please enter book title = ");
				fflush(stdin);
				scanf("%[^\n]",&(_tempBook.title));
				printf("Please enter book author = ");
				fflush(stdin);
				scanf("%[^\n]",&(_tempBook.author));
				printf("Please enter book subject = ");
				fflush(stdin);
				scanf("%[^\n]",&(_tempBook.subject));
				printf("Please enter book year = ");
				fflush(stdin);
				scanf("%d",&(_tempBook.year));
				_tempBook.book_id = lastIndex;
    			addBook(_tempBook);
				printf("\n**********************\n");
				selection = 0;
    			break;
    		case 2:
    			while(subrun){
    				printf("SUBMENU\n");
					printf("\t1. Get by Title\n");
					printf("\t2. Get by Author\n");
					printf("\t3. Get by Subject\n");
					printf("\t4. Sorted List by Year (DESC)\n");
					printf("\t5. List All Books\n");
					printf("\t6. EXIT SUBMENU\n");
					printf("\nChoose = ");
					scanf("%d",&subselection);
					printf("**********************\n");
					selection = 0;
					switch(subselection){
						case 1:
							printf("Enter a books title = ");
							fflush(stdin);
							scanf("%[^\n]",&tempValue);
							for(int i=0; i<lastIndex;i++){
								if(!strcmp(Books[i].title,tempValue)){
									printf("Book found\n");
									printf("Title => %s\nAuthor => %s\nSubject => %s\nYear => %d\n", Books[i].title, Books[i].author, Books[i].subject, Books[i].year );
									printf("**********************\n");
									counter = 1;
								}
							}
							if(counter != 1){
								printf("Book not found.\n");
								printf("**********************\n");
							}
							counter = 0;
							break;
						case 2:
							printf("Enter a books Author = ");
							fflush(stdin);
							scanf("%[^\n]",&tempValue);
							for(int i=0; i<lastIndex;i++){
								if(!strcmp(Books[i].author,tempValue)){
									printf("Book found\n");
									printf("Title => %s\nAuthor => %s\nSubject => %s\nYear => %d\n", Books[i].title, Books[i].author, Books[i].subject, Books[i].year );
									printf("**********************\n");
									counter = 1;
								}
							}
							if(counter != 1){
								printf("Book not found.\n");
								printf("**********************\n");
							}
							counter = 0;
							break;
						case 3:
							printf("Enter a books Subject = ");
							fflush(stdin);
							scanf("%[^\n]",&tempValue);
							for(int i=0; i<lastIndex;i++){
								if(!strcmp(Books[i].subject,tempValue)){
									printf("Book found\n");
									printf("Title => %s\nAuthor => %s\nSubject => %s\nYear => %d\n", Books[i].title, Books[i].author, Books[i].subject, Books[i].year );
									printf("**********************\n");
									counter = 1;
								}
							}
							if(counter != 1){
								printf("Book not found.\n");
								printf("**********************\n");
							}
							counter = 0;
							break;
						case 4:
							sortBooks(1);
							listBooks();
							break;
						case 5:
							sortBooks(2);
    						listBooks();
							break;
						case 6:
							subrun = 0;
							break;
						default:
    						printf("TRY AGAIN.\n");
    						break;
					}
				}
    			break;
    		case 3:
    			run = 0;
    			break;
    		default:
    			printf("TRY AGAIN.\n");
				break;
		}
	}
	return 0;
}
