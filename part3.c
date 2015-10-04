/* This is a dynamic sql program based on an sample written by Alkex Cameron - 100861937 */

#include <stdio.h>
#include <string.h>

exec sql include sqlca;
	
exec sql begin declare section;
	char *identity = "oracle/oracle11g";
	char statement[1024];
	char statement2[1024];
exec sql end declare section;


void catchOracleError();

int main(){
	char id[10];
	char name[10];
	int s;
	char c[10];
	exec sql connect :identity;
	if (sqlca.sqlcode < 0){
		printf("Could not connect to oracle!\n");
		exit(1);
	}
	else{
		printf("Connected to Oracle\n");
	}

	exec sql set transaction read write;
	
	strcpy(statement, "SELECT supp_id, supp_name, status, supp_city FROM Suppliers GROUP BY supp_id");
	
	exec sql prepare t from :statement;	
	if (sqlca.sqlcode < 0){
		printf("Couldn't prepare statement");
		exit(1);
	}
	
	exec sql declare a_cursor cursor for t;

	exec sql open a_cursor;
	if (sqlca.sqlcode < 0){
		printf("Couldn't open cursor");
		exit(1);
	}

	printf("|---S#-------Name-----Status-----City---|\n");
	printf("|---------|---------|---------|---------|\n");
	
	exec sql fetch a_cursor into :id, :name, :s, :c;
	printf("%10s %10s %10s %10s\n--------------------------------------\n", id, name, s, c);
	exec sql close a_cursor;
	

exec sql commit realease;
exit(0);	 
}
