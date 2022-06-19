#include <stdio.h>
#include <string.h>

#define MAX_LEN 100




void concatAlphabeticReverseSort(char arr[][MAX_LEN], int n, char catStr[]){
	char temp[MAX_LEN];
	int m=n;

	for(int i=0; i<n; i++){			
		for(int j=0; j<m-1; j++){
			if(strcmp(arr[j],arr[j+1])<0){
				strcpy(temp,arr[j]);
				strcpy(arr[j],arr[j+1]);
				strcpy(arr[j+1],temp);

			}
		}
		m--;
	}
	
	for(int i=0; i<n; i++){
		strcat(catStr,arr[i]);	//After sorting finish we add all elements to catstr array
	}

	
}

void generateTagParserCustomized(char temp[], char arr[]){
	if(strlen(arr)<5){
		strcpy(temp,"<<");	// If length of array is less than 5 we start with <<
	}
	else if(strlen(arr)>10){
		strcpy(temp,"/+"); // If length of array is more than 5 we start with /+
	}else{
		strcpy(temp,"*");	// else start with *
	}	
		
	strcat(temp,&arr[1]);	//adding array to temp except than first element
			//After that steps we add the last char(s) to end of temp
	if(strlen(arr)<5){
		temp[strlen(arr)]='>';	
		temp[strlen(arr)+1]='>';
	}
	else if(strlen(arr)>10){
		temp[strlen(arr)]='+';
		temp[strlen(arr)+1]='/';
	}else{
		temp[strlen(arr)-1]='*';
	}
}

int main(){
	char arr[MAX_LEN][MAX_LEN],temp[MAX_LEN],arr2[MAX_LEN];
	int n;
	char catStr[MAX_LEN];
	void concatAlphabeticReverseSort(char arr[][MAX_LEN], int n, char catStr[]);
	void generateTagParserCustomized(char temp[], char arr[]);
	printf("Enter the count of how many strings you willl enter: \n");
	scanf("%d",&n);					/* We take the number of string value after that we take the strings and after sorting print it to screen*/
	printf("Enter strings: \n");	
	for(int i=0; i<n; i++){
		scanf("%s",arr[i]);		
	}	
	printf("Given array is:\n");		
	for(int i=0; i<n; i++){
		printf("%d: %s\n",i,arr[i]);		
	}
	
	concatAlphabeticReverseSort(arr, n, catStr);	/* For the second part we take the array from user and print it with tags to screen */
	printf("Sorted array is:\n");		
	for(int i=0; i<n; i++){
		printf("%d: %s\n",i,arr[i]);		
	}	
	printf("Result is:\n%s\n",catStr);	
	
	printf("Enter a string: \n");
	scanf("%s",arr2);
	
	generateTagParserCustomized(temp,arr2);
	printf("%s\n",temp);	
}





