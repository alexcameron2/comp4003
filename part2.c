/* This is a dynamic sql program based on an sample written by Alkex Cameron - 100861937 */

#include <stdio.h>
#include <string.h>

exec sql include sqlca;
	
exec sql begin declare section;
	char *identity = "oracle/oracle11g";
	char statement[1024];
exec sql end declare section;


void catchOracleError();

int main(){
	exec sql connect :identity;
	if (sqlca.sqlcode < 0){
		printf("Could not connect to oracle!\n");
		exit(1);
	}
	else{
		printf("Connected to Oracle\n");
	}

	exec sql set transaction read write;
	//Creat Tables

	//Create the Suppliers table
	strcpy(statement,"CREATE TABLE Suppliers (supp_id varchar2(2) primary key, spp_name varchar2(10), status int, supp_city varchar(10))");
	
	exec sql execute immediate :statement;
	if (sqlca.sqlcode < 0){
		printf("Could not create Suppliers table\n");
		exit(1);
	}
	else{
		printf("Created Suppliers table!\n");
	}

	//Create the Parts table
	strcpy(statement,"CREATE TABLE Parts (part_id varchar2(2) primary key, part_name varchar2(8), part_color varchar2(8), weight float, part_city varchar(10))");
	
	exec sql execute immediate :statement;
	if (sqlca.sqlcode < 0){
		printf("Could not create Parts table\n");
		exit(1);
	}
	else{
		printf("Created Parts table!\n");
	}

	//Create the SuppToPart lookup table
	strcpy(statement,"CREATE TABLE SuppToPart (supp_id varchar2(2), part_id varchar2(2), quantity int, constraint PK_D primary key (supp_id, part_id))");
	
	exec sql execute immediate :statement;
	if (sqlca.sqlcode < 0){
		printf("Could not create SuppToPart lookup table\n");
		exit(1);
	}
	else{
		printf("Created SuppToPart table!\n");
	}

exit(1);	 
}
