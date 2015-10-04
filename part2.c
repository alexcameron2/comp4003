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
	char userInput[1024];
	char *input;
	
	while(1){
		printf("Enter a supplier in the form:  ID name status city\n.: ");
		fgets(userInput, 1024, stdin);
		printf("Attemping to create Supplier: -%s\n", userInput);
		
		if( strcmp(userInput, "quit") == 0){
			printf("Quitting\n");
			break;
		}
		char *supplierID = strtok(userInput, " \n");
printf("Extracted ID: --%s--\n", supplierID);
		char *supplierName = strtok(NULL, " \n");
printf("Extracted Name: --%s--\n", supplierName);
		int status = atoi(strtok(NULL, " \n"));
printf("Extracted status: --%d--\n", status);
		char *city = strtok(NULL, " \n");
printf("Extracted city: --%s--\n", city);
		
		strcpy(statement, "INSERT INTO Suppliers VALUES (:v1, :v2, :v3, :v4)");
		exec sql prepare s from :statement;
		if (sqlca.sqlcode < 0){
			printf("Statement not prepared!\n");
			break;
		}
		
		exec sql execute s using :supplierID, :supplierName, :status, :city;
		if (sqlca.sqlcode < 0){
			printf("Insert not complete!\n");
		}
		else {
			printf("Insertion completed\n");
		}
	}	
}

void AddToParts(){
	char userInput[1024];
	char *input;
	
	while(1){
		printf("Enter a part in the form: ID name colour weight city\n.:");
		fgets(userInput, 1024, stdin);
		printf("Attemping to create Part: -%s\n", userInput);
		
		if( strcmp(userInput, "quit") == 0){
			printf("Quitting\n");
			break;
		}
		char *partID = strtok(userInput, " \n");
printf("Extracted ID: --%s--\n", partID);
		char *partName = strtok(NULL, " \n");
printf("Extracted Name: --%s--\n", partName);
		char *partColour = strtok(NULL, " \n");
printf("Extracted Color: --%s--\n", partColour);
		float weight = atof(strtok(NULL, " \n"));
printf("Extracted weight: --%f--\n", weight);
		char *city = strtok (NULL, " \n");
printf("Extracted city: --%s--\n", city);
		
		strcpy(statement, "INSERT INTO Parts VALUES (:v1, :v2, :v3, :v4, :v5)");
		exec sql prepare s from :statement;
		if (sqlca.sqlcode < 0){
			printf("Statement not prepared!\n");
			break;
		}
		
		exec sql execute s using :partID, :partName, :partColour, :weight, :city;
		if (sqlca.sqlcode < 0){
			printf("Insert not complete!\n");
		}
		else {
			printf("Insertion completed\n");
		}
	}
}

void AddToLookup(){
	char userInput[1024];
	char *input;
	
	while(1){
		printf("Enter an entry in the form:\n supplierID partID quantity.\n");
		fgets(userInput, 1024, stdin);
		printf("Attemping to create Entry from:: -%s-\n", userInput);
		
		if( strcmp(userInput, "quit") == 0){
			printf("Quitting\n");
			break;
		}
		char *supplierID = strtok(userInput, " \n");
printf("user input ID: --%s--\n", supplierID);
		char *partID = strtok(NULL, " \n");
printf("user input part ID: --%s--\n");
		int quantity = atoi(strtok(NULL, " \n"));
printf("user input quantity: --%d--\n", quantity);
		
		strcpy(statement, "INSERT INTO SuppToPart VALUES (:v1, :v2, :v3)");
		exec sql prepare s from :statement;
		if (sqlca.sqlcode < 0){
			printf("Statement not prepared!\n");
			break;
		}
		
		exec sql execute s using :supplierID, :partID, :quantity;
		if (sqlca.sqlcode < 0){
			printf("Insert not complete!\n");
		}
		else {
			printf("Insertion completed\n");
		}
	}
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
		//set the last character to null, instead of a newline character
		userInput[strlen(userInput) - 1] = 0;

		printf("\nValue entered was -%s-...\n", userInput);
	 	
		//If the user enters 'quit' then quit the program and commit changes
		if (strcmp(userInput, "quit") == 0){
			printf("Quitting\n");
			break;
		}
		
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
