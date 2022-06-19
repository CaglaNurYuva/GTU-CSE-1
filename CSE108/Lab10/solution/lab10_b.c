#include <stdio.h>
#include <string.h>


// part 1
struct number{
	char number_as_str[5];
	int number_as_int;
};

struct combination{
	struct number n;
	struct number r;
	int result;	
};

int get_digit (char c){
	switch(c){
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return -1;
	}
}


// this function is generating the number starting from right side
int parse_to_int (char *number_as_str, int length){
	// if length is 1, we have only 1 digit to parse to int, after parsing it, the function should stop
	if (length==1)
		return get_digit(number_as_str[length-1]); 
    return 10 * parse_to_int(number_as_str, length-1) + get_digit(number_as_str[length-1]); // decreasing length by one to get the next element
}

int factorial (int n){
	if (n==1)
		return 1;
	else
		return n*factorial(n-1);
}

int is_number (char *number_as_str, int length){
	if (length==0)
		return 1;
	int k = get_digit(number_as_str[length-1]);
	if (k==-1)
		return 0;
	return is_number(number_as_str, length-1);
}

// part 2
int find(int decimal_number, int base)
{
    if (decimal_number == 0)
        return 0;
    else
        return (decimal_number % base + 10 *
                find(decimal_number / base, base));
}
 
int main()
{ 
	printf("PART 1\n\n");
	struct combination my_comb;
	int a,b;
	while(1){
		printf("n: ");
		scanf("%s", my_comb.n.number_as_str);
		printf("r: ");
		scanf("%s", my_comb.r.number_as_str);
		a = is_number(my_comb.n.number_as_str, strlen(my_comb.n.number_as_str));
		b = is_number(my_comb.r.number_as_str, strlen(my_comb.r.number_as_str));
		if (a==0 || b==0)
			printf("\nInputs are not valid. Please try again..\n\n");
		else
			break;
	}
	
	my_comb.n.number_as_int = parse_to_int (my_comb.n.number_as_str, strlen(my_comb.n.number_as_str));
	my_comb.r.number_as_int = parse_to_int (my_comb.r.number_as_str, strlen(my_comb.r.number_as_str));
	int k = factorial(my_comb.n.number_as_int);
	int l = factorial(my_comb.r.number_as_int);
	int dif = my_comb.n.number_as_int - my_comb.r.number_as_int;
	int m = factorial(dif);
	my_comb.result = k/(l*m);
	printf("Combination (%d,%d) = %d ", my_comb.n.number_as_int, my_comb.r.number_as_int, my_comb.result);
	
	printf("\n\nPART 2\n\n");
	int g,h;
	printf("Decimal number: ");
	scanf("%d", &g);
	printf("Base: ");
	scanf("%d", &h);
	
	printf("%d in base %d is: %d", g, h, find(g,h));
	
}
