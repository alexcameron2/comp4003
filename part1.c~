/* This is a dynamic sql program based on an sample written by Alkex Cameron - 100861937 */

#include <stdio.h>
exec sql include sqlca;
exec sql begin declare section;
	char statement[1024];
	char *MYID = "fedora/oracle11g";
exec sql end declare section;

int main(int argc, char argv[]){
	//connect sql
	exec sql connect :MYID;
	if (sqlca.slqcode < 0 ){
		printf("Could not connect to ORACLE!\n");
		exit(1);
	}

	//Create a the databse tables using dynamc msql method 1..and hard coding
	exec sql set transaction read write;

	//Create Suppliers table
	strcpy(statement, "CREATE TABLE Suppliers (supp_id varchar2(2) primary key, spp_name varchar2(10), status int, supp_city varchar(10))");
	exec sql execute immediate :statement;
	if (sqlca.sqlcode < 0){
		printf("Could not create Suppliers table\n");
	}
	else{
		printf("Created table: Suppliers\n");
	}

	//Create Parts table
	strcpy(statement, "CREATE TABLE Parts (part_id varchar2(2) primary key, part_name varchar2(10), part_color varchar2(6), weight float, part_city varchar(10))");
	exec sql execute immediate :statement;
	if (sqlca.sqlcode < 0){
		printf("Could not create Parts table\n");
	}
	else{
		printf("Created table: Parts\n");
	}

	//Create SuppliersToParts lookup table
	strcpy(statement, "CREATE TABLE SuppsToParts(supp_id varchar2(2), part_id varchar(2), quantity int, constaint t_pk primary key (supp_id, part_id))");
	exec sql execute immediate :statement;
	if (sqlca.sqlcode < 0){
		printf("Could not create SuppsToParts lookup table\n");
	}
	else{
		printf("Created table: SuppsToParts lookup table\n");
	}
	exec sql commit release;
	exit(0);	
}
