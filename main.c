#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define MAXNAME 256
#define TABLE_LENGTH 10
typedef struct {
		char name[MAXNAME];
		int age; 
}person;

person *hashTable[TABLE_LENGTH] = { 0 }; 

void printTable() {
	printf("\n\n\n");
	for(int i = 0; i < TABLE_LENGTH; i++) {
		if(hashTable[i] != NULL) {
			printf("\t\t%d\t%s\n",i,  hashTable[i]->name);
		}
		else {
			printf("\t\t%d\t---\n", i); 
		}
	}
}

unsigned int hash(char *name) {
	unsigned int tmp; 

	for(int i = 0; i < strlen(name); i++) {
		tmp += name[i];
		tmp *= name[i]*3%7*tmp%name[i] + 32; 
	}

	return tmp%TABLE_LENGTH; 
}

int add(person *person) {
	
	unsigned int index = hash(person->name); 
	if(hashTable[index] == NULL) {
		hashTable[index] = person;
		return 0; 
	} 
	return 1; 
	
}

int removePerson(char *name) {
	int len = strlen(name); 
	unsigned int index = hash(name); 

	if(strcmp(hashTable[index]->name, name) == 0) {
		hashTable[index] = NULL; 
	}

	return 0;
}

int main(void) {
	printTable();

	person Memo = {.name = "Memo", .age = 19};
	person Bernd = {.name = "Bernd", .age = 19};
	person Anna = {.name = "Anna", .age = 19};

	add(&Memo); 
	add(&Bernd); 
	add(&Anna); 
	printTable();

	removePerson("Memo");

	printTable();
}
