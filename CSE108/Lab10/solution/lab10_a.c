#include <stdio.h>
#include <math.h>
#define PI 3.14

// part 1
struct coordinates{
	int x,y;
};

struct circle{
	struct coordinates points[2];
	float r, p, a; //radius, perimeter, area
};

float calculate_r(struct circle c1){ //distance func
	int a = (c1.points[0].x - c1.points[1].x)*(c1.points[0].x - c1.points[1].x);
	int b = (c1.points[0].y - c1.points[1].y)*(c1.points[0].y - c1.points[1].y);
	return sqrt (a+b);
}


void print_struct(struct circle circle_array[], int array_size, float last_printed_element, int last_printed_index){
	int ind=0,i;
	float min = 10000, max=0;
	
    	for (i = 0; i < array_size; i++){
    		// trying to find the max, because if we already printed max, then the function should stop
		if (circle_array[i].r > max)
			max = circle_array[i].r;
		
    		// we are trying to find the minimum number, but it cant be the last printed element
    		// this statement will ignore circles with same parameter
  		if (circle_array[i].r < min   &&    i != last_printed_index &&    circle_array[i].r > last_printed_element){
	    		min = circle_array[i].r;
	    		ind = i;
		}
	}
	// if we are checking the last element, max element should be equal to min and the recursive function should stop
	if (max == last_printed_element)
		return;	
		
	printf("Circle %d\tRadius: %.2f  \tPerimeter: %.2f  \tArea: %.2f\n", ind+1, circle_array[ind].r, circle_array[ind].p, circle_array[ind].a);
	print_struct(circle_array, array_size, min, ind); 
	return;
}



// part 2
int is_prime (int n, int k){ // k should be 2 at the first call
	if (n==k) // k can't be equal to or larger than n
		return 1;
	else if (n%k == 0)
		return 0;
	else{
		return is_prime(n, k+1);
	}
}

void factorization (int n, int k){
	if(n!=2 && k==1)
		return;
	int p = is_prime(k,2);
	// if the current number is not prime, we won't check if it can divide the number "n"
	if (p==1 && n%k == 0){
		printf("%d*",k);
		factorization(n/k, n/k);
	}
	else
		factorization (n, k-1);
}

int main(){
	// part 1
	int arr_size,i;
	struct circle my_circles[10];
	printf("PART1 \n\nNumber of circles: ");
	scanf("%d", &arr_size);
	for (i=0; i<arr_size; i++){
		printf("\nCircle %d...\nCoordinates of center: \t",i+1);
		scanf("%d %d", &my_circles[i].points[0].x,&my_circles[i].points[0].y);
		printf("Coordinates of point P: ");
		scanf("%d %d", &my_circles[i].points[1].x,&my_circles[i].points[1].y);
		my_circles[i].r = calculate_r (my_circles[i]);
		my_circles[i].p = 2*PI*my_circles[i].r;
		my_circles[i].a = PI*my_circles[i].r*my_circles[i].r;
	}
	printf("\n\nPrinting circles in an ascending order...\n\n");
	print_struct(my_circles, arr_size, -1, -1);
	
	// part 2
	printf("\n\n\nPART 2\n\nEnter a number: ");
	int n;
	scanf("%d", &n);
	if (is_prime(n,2) == 1)
		printf("%d is a prime number.",n);
	else{
		printf("%d = ", n);
		factorization(n,n-1);
	}
	return 0;
}
