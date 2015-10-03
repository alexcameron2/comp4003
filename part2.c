/* This is a dynamic sql program based on an sample written by Alkex Cameron - 100861937 */

#include <stdio.h>
#include <string.h>

exec sql include sqlca;
	
exec sql begin declare section;
	char *identity = "oracle/oracle11g";
	char statement[1024];
exec sql end declare section;


void catchOracleError();


void AddToSuppliers(){
	char userInput[100];
	
}

void AddToParts(){
	char userInput[100];
}

void AddToLookup(){
	char userInuput[100];
}


int main(){
	char userInput[100];
	exec sql connect :identity;
	if (sqlca.sqlcode < 0){
		printf("Could not connect to oracle!\n");
		exit(1);
	}
	else{
		printf("Connected to Oracle\n");
	}

	exec sql set transaction read write;
	while (1){
		printf("ADDING TABLE ENTRIES!!\n\nEnter table name to add to (or 'quit'):");
		printf(" ");;
		fgets(userInput, 100, stdin);

		printf("\nValue entered was -%s-...\n", userInput);
	 	
		//If the user enters 'quit' then quit the program and commit changes
		if (strcmp(userInput, "quit") == 0)
			printf("Quitting\n");
			break;
		)
		
		if ( strcmp(userInput, "Suppliers") == 0){
			AddToSuppliers();
		}
		else if ( strcmp(userInput, "Parts") == 0){
			AddToParts();
		}
		else if ( strcmp(userInput, "SuppToPart") == 0){
			AddToLookup();
		}
	}
exec sql commit release;
exit(0);	 
}
