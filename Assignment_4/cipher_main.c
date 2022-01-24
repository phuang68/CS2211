#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include "ciphers.h"
//C89
//Author:Pu Huang
//Student Number: 250986943
/*Short Description: this is a c program that takes a string,encrypts it,decrypts it and calculate the frequency of the tex
*/
#define BUFFER_SIZE 100

int main(){
	char *plaintext, *cyphertext,*decrpyted,*k,buffer[BUFFER_SIZE],kk[BUFFER_SIZE];
	int i,choice,l,key;
	double letters[26];
	printf("Input plaintext: \n");
	scanf("%[^\n]s",buffer);
	plaintext = buffer;
	printf("\nPlaintext:\n%s\n",plaintext);


	printf("\nAvailable Ciphers:\n1) Caesar\n2) Vigenere\n");
	printf("\nSelect Cipher:");
	i = scanf("%d",&choice);

	//check if the choice is valid
	if(i!=1 || (choice != 1 && choice != 2)){
		printf("Error: bad selection!\n");
		return EXIT_FAILURE;
	}
	
	//return the result of encryption based on the choice
	if(choice == 1){
		getchar();//clear previous input
		printf("\nInput key as number:");
		i = scanf("%d",&key);
	
		//check if the key input is valid
		if(i!=1){
		printf("Error: bad key input!\n");
		return EXIT_FAILURE;
		}

		cyphertext = caesar_encrypt(plaintext,key);
		decrpyted = caesar_decrypt(cyphertext,key);	
	}
	else{	
		getchar();//clear previous input
		printf("Input key as string: ");
		scanf("%[^\n]s",kk);
		k = kk;

			
                for(i = 0; *(k + i) != 0; i++){
                        if(!isalpha(*(k + i))){
                                printf("Error: Bad Key! Invalid Char!\n");
                                return EXIT_FAILURE;
                        }
                }
		
		cyphertext = vigen_encrypt(plaintext,k);
		decrpyted = vigen_decrypt(cyphertext,k);
	}	
	
	printf("\nPlaintext:\n%s\n",plaintext);
		
		printf("\nCiphertext:\n");
		printf("%s\n",cyphertext);
		
		printf("\nPlaintext:\n");
		printf("%s\n",decrpyted);

		printf("\nFrequency analysis:\n");
			freq_analysis(cyphertext,letters);
		for(l = 0;l < 26;l++){
			printf("%c:",(char)(l+65));
			printf("%1.1f\n",*(letters+l));
		}

	//free up the memory
        free(cyphertext);
        free(decrpyted);
			
	return 0;
}