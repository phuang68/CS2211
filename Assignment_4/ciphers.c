#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ciphers.h"

char * caesar_encrypt(char *plaintext, int key){
	//declare a ciphertext pointer to return later
	char *cyphertext = (char *)malloc ((strlen(plaintext) + 1) * sizeof(char));
	char *temp;// declare a temporary string pointer
	
	//if the allocating is not working,exit the program
	if(cyphertext == NULL){
		printf("Error allocating memory!");
		exit(EXIT_FAILURE);
	}
	
	//copy the plaintext to the cyphertext
	strcpy(cyphertext,plaintext);
	
	//traverse the string
	for(temp = cyphertext ;*temp!='\0';temp++){
		if((int)*temp >= 97 && (int)*temp <= 122){//if the character is not in the range of alphabets ignore it
			*temp = (*temp - 97 - key)%26 + 65;
		}
		else if((int)*temp >= 65 && (int)*temp <=90 ){//either in the range of capital alphabets
			*temp += key;
		}	
		else //ignore it
			continue;
	}

	return cyphertext;
		
}

char * caesar_decrypt(char *ciphertext, int key){
	//declare a ciphertext pointer to return later
	char *plaintext = (char *)malloc ((strlen(ciphertext) + 1) * sizeof(char));
	char *p,*temp;// declare a temporary string pointer
	
	//if the allocating is not working,exit the program
	if(plaintext == NULL){
		printf("Error allocating memory!");
		exit(EXIT_FAILURE);
	}
	
	//copy the cyphertext to the plaintext
	strcpy(plaintext,ciphertext);
	
	//traverse the plaintext and shift it back
	for(temp = plaintext ;*temp!='\0';temp++){
		if((int)*temp >= 65 && (int)*temp <=90 ){//if the character is not in the range of capital alphabets
			*temp = (*temp - 65 + key) % 26 + 65;
		}	
		else //ignore it
			continue;
	}

	return plaintext;
		
}

char * vigen_encrypt(char *plaintext, char *key){
	//declare a ciphertext pointer and a padded key pointer to return later
	char *cyphertext = (char *)malloc ((strlen(plaintext) + 1) * sizeof(char));
	char *pad = (char *) malloc ((strlen(key) + 1) * sizeof(char));
	char *temp,*k;// declare a temporary string pointer
	
	//if the allocating is not working,exit the program
	if(cyphertext== NULL|| pad == NULL){
		printf("Error allocating memory!");
		exit(EXIT_FAILURE);
	}
	
	//copy the plaintext and key to cyphertext and padded key
	strcpy(cyphertext,plaintext);
	strcpy(pad,key);
	
	//change the letters to capital letters
	for(k = pad; *k!='\0';k++){
		if((int)*k >= 97 && (int)*k <= 122){//if the character is not in the range of capital alphabets change it
			*k = toupper(*k);
		}
		else
			continue;	
	}
	k = k - strlen(pad);//points back to the beginning of the key when the capitalization is done
	
	for(temp = cyphertext;*temp!='\0';temp++,k++){
		if(*k !='\0'){//check if it reaches to the end of the key
			if((int)*temp >= 97 && (int)*temp <= 122){//if the character is not in the range of alphabets ignore it
				*temp = (*temp - 97 + *k - 65)%26 + 65;
			}
			else if((int)*temp >= 65 && (int)*temp <=90 ){//either in the range of capital alphabets
				*temp = (*temp -65 + *k - 65) % 26 + 65;
			}	
			else //ignore it
				continue;
		}
		else{//if k pointer reaches to the end of the key,point it back to the beginning of the key
			k = k - strlen(key);//points back to the beginning of the key
			if((int)*temp >= 97 && (int)*temp <= 122){//if the character is not in the range of alphabets ignore it
				*temp = (*temp - 97 + *k - 65)%26 + 65;
			}
			else if((int)*temp >= 65 && (int)*temp <=90 ){//either in the range of capital alphabets
				*temp = (*temp -65 + *k - 65) % 26 + 65;
			}	
			else //ignore it
				continue;
		}	
	}

	return cyphertext;	
}

char * vigen_decrypt(char *ciphertext, char *key){
	//declare a negative key pointer to return later
	char *neg = (char *) malloc ((strlen(key) + 1) * sizeof(char));
	char *k;
	
	//if the allocating is not working,exit the program
	if(neg == NULL){
		printf("Error allocating memory!");
		exit(EXIT_FAILURE);
	}
	//copy key to pad
	strcpy(neg,key);
	
	//change the letters to capital letters
	for(k = neg; *k!='\0';k++){
		if((int)*k >= 97 && (int)*k <= 122){//if the character is not in the range of capital alphabets change it
			*k = toupper(*k);//change the character to a capital letter
			*k = (26 - (*k-65))%26 + 65;//make the character as negative letter
		}
		else 
			*k = (26 - (*k-65))%26 + 65;	
	}
	
	return vigen_encrypt(ciphertext,neg);
}

void freq_analysis(char *ciphertext, double letters[26]){
	//declare a ciphertext pointer and a padded key pointer to return later
	char *cyphertext = (char *)malloc ((strlen(ciphertext) + 1) * sizeof(char));
	char *temp;
	double total = 0;//count the total letters;
	int i;
	
	//if the memory allocating is not working,exit the program
	if(cyphertext == NULL){
		printf("Error allocating memory!");
		exit(EXIT_FAILURE);
	}
	
	//copy the plaintext to the cyphertext
	strcpy(cyphertext,ciphertext);
	
	//traverse the letters array and initialize every slot to value 0    
	for(i = 0; i < 26; i++){
                 *(letters + i) = 0.0; 
        }
		
	//traverse the string,and count the total number of letters and count num of each character in the string
	for(temp = cyphertext ;*temp!='\0';temp++){
		if((int)*temp >= 65 && (int)*temp <=90 ){
			 *(letters + ((int)*temp - 65))	=  *(letters + ((int)*temp - 65))+ 1;
			total++;
		}
		else//if the pointer now is not a character,check the next one 
			continue;
	}

	//points back to the beginning of the text;
	temp = temp - strlen(cyphertext);

	//traverse the string again and calculate the frequency to store in the character slot later
	for(i = 0; i < 26; i++){
		 *(letters + i) = (*(letters + i)/total)*100; 
	}
}


