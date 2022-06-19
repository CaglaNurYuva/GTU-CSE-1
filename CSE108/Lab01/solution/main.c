#include <stdio.h>

int main() {
	int x1, x2, y1, y2;
	printf("x1: ");
	scanf("%d", &x1);
	printf("y1: ");
	scanf("%d", &y1);
	printf("x2: ");
	scanf("%d", &x2);
	printf("y2: ");
	scanf("%d", &y2);
	
	// midpoint 
	float mx = (x1+x2)*1.0 / 2;
	float my = (y1+y2)*1.0 / 2;
	printf("\nMidpoint: M(x,y) = (%.1f, %.1f)", mx, my);
	
	// slope
	float m = (y2-y1) *1.0 / (x2-x1);
	printf("\n\nSlope: m = (%.1f)", m);
	
	// area of the circle
	float pi = 3.14;
	// distance formula gives us "r" only. since we need r2, we ignore the square root.
	float r2 = (mx-x1)*(mx-x1) + (my-y1)*(my-y1); 
	float area = pi*r2;
	printf("\n\nArea: A = %.1f\n\n", area);
	
	return 0;
}
