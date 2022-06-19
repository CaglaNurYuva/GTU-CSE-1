#include <stdio.h>
void printMatrix (char matrix[26][26]){
	int i, j;
	printf("Alphabet table:\n\n");
	// printing the alphabet
	for(i=0; i<26; i++){
		for (j=0; j<26; j++)
			printf("%c ", matrix[i][j]);
		printf("\n");		
	}
}

char encryption (char keyLetter, char plaintextLetter, char matrix[26][26]){
	int i,j;
	for(i=0; i<26; i++)
		if (matrix[i][0] == keyLetter) // checking if the current row is the one we are looking for
			for(j=0; j<26; j++)
				if (matrix[0][j] == plaintextLetter)// checking if the current column is the one we are looking for
					return matrix[i][j]; // returning their intersection
}

char decryption (char keyLetter, char ciphertextLetter, char matrix[26][26]){
	int i,j;
	for(i=0; i<26; i++)
		if (matrix[i][0] == keyLetter)// checking if the current row is the one we are looking for
			for(j=0; j<26; j++)
				if (matrix[i][j] == ciphertextLetter)// checking if the keystream letter generates ciphertext letter by using this column
					return matrix[0][j]; // returning the related column's letter
}


int main() {
    	char alphabets[26][26];
	char plaintext[10], key[3], keystream[10], ciphertext[10];
	char letter;
    	int i=0, j;
    	// generating the first row
	for (letter = 'A'; letter <= 'Z'; ++letter){
		alphabets[0][i] = letter;
		i++;
	}
	
	// generating the other rows
	for(i=1; i<26; i++)
	    	for (j=0; j<26; j++)
			alphabets[i][j] = alphabets[i-1][(j+1)%26];
	    
	// printing the table
	printMatrix(alphabets);
	
	printf("\n\n*** ENCRYPTION ***\n\nPlaintext: ");
	i=0;
	// reading plaintext
	letter = getchar();
	while(letter!= '\n'){ // read until the user hits enter 
		plaintext[i] = letter;
		letter = getchar();
		i++;
	}
	
	printf("Key: ");
	i=0;
	// reading key
	letter = getchar();
	while(letter!= '\n'){
		key[i] = letter;
		letter = getchar();
		i++;
	}
	
	printf("Keystream: ");
	for(i=0; i<10; i++)
		keystream[i] = key[i%3]; // generating the keystream
	for(i=0; i<10; i++)
		printf("%c", keystream[i]); // printing the keystream
	printf("\nCiphertext: ");
	for(i=0; i<10; i++){
		ciphertext[i] = encryption (keystream[i], plaintext[i], alphabets);
		printf("%c", ciphertext[i]); // printing the ciphertext
	}		
	

	
	printf("\n\n*** DECRYPTION ***\n\nCiphertext: ");
	i=0;
	// reading ciphertext
	letter = getchar();
	while(letter!= '\n'){
		ciphertext[i] = letter;
		letter = getchar();
		i++;
	}
	
	printf("Key: ");
	i=0;
	// reading key
	letter = getchar();
	while(letter!= '\n'){
		key[i] = letter;
		letter = getchar();
		i++;
	}
	
	printf("Keystream: ");
	for(i=0; i<10; i++)
		keystream[i] = key[i%3]; // generating keystream
	for(i=0; i<10; i++)
		printf("%c", keystream[i]);
	printf("\nCiphertext: ");
	for(i=0; i<10; i++){
		plaintext[i] = decryption (keystream[i], ciphertext[i], alphabets);
		printf("%c", plaintext[i]); // printing the plaintext
	}		
    return 0;
}
