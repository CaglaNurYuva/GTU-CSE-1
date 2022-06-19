#include<stdio.h>
#include <stdlib.h>
 
typedef struct{ 
int * array; 
int currentsize; 
} dynamic_array;

void 	print_array(dynamic_array a){
	int i =0;
	printf("*********************\n");
	for( i=0 ; i < a.currentsize ; i++ ) {
      printf("%d\n",a.array[i]);
   }
}

int *resize_array(int *array, int currentsize) {
  int *temp = calloc((currentsize+1), sizeof(int)); // copy incoming array and resize it
  int i;
  for (i = 0; i < currentsize; i++) {
    temp[i] = array[i];
  }
  free(array); // free incoming array
  return temp; // return the copy
}

dynamic_array read_from_file(char *filename, dynamic_array a){
	FILE *fp;
	fp = fopen(filename, "r"); // read mode
	a.currentsize = 0;
	int number;
	
	if (fp == NULL)
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	
	while (!feof (fp))
    {  
      	fscanf (fp, "%d ", &number); 
      	if(a.currentsize == 0){ // reading first element
 			a.array = (int*)calloc(1, sizeof(int));
      		a.array[0] = number;
      		a.currentsize++;
		  }
      	else{
      		a.array = resize_array(a.array, a.currentsize); // reading other elements
      		a.array[a.currentsize]= number;
      		a.currentsize++;
		  }
	}
    	
	fclose(fp);
	return a;
}

dynamic_array removeData(dynamic_array b, int d){
	int control = 0;
	dynamic_array temp;
  	temp.currentsize = b.currentsize - 1;
  	temp.array = calloc(temp.currentsize,sizeof(int));
	int i;
	int j=0;
	// copying array, except incoming data.
	for (i = 0; i < b.currentsize; i++) {
    	if (b.array[i] != d){ // if the value is not "d", copy it
    		temp.array[j] = b.array[i];
    		j++;
		}
  	}	
  	control = 0;
	return temp; //return copy
}

int main(){
	dynamic_array tempArray, firstArray, lastArray;
	char *filename = "source.txt";
	int input = 0;
	
	firstArray = read_from_file(filename,tempArray);
	printf("Data in source file\n");
	print_array(firstArray);	
	
	printf("Enter the number you want to be deleted: ");
    scanf("%d", &input);
    
	lastArray = removeData(firstArray,input);
	printf("Array after deletion\n");
	print_array(lastArray);
	
	return 0;
}
