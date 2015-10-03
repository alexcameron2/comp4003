/* This is a dynamic sql program based on an sample written by Alkex Cameron - 100861937 */

#include <stdio.h>
#include <string.h>

#include <sqlca.h>
#include <oraca.h>

EXEC ORACLE OPTION (ORACA=YES);
EXEC ORACLE OPTION (RELEASE_CURSOR=YES);

void catchOracleError();

int main(){
	char *username = "fedora";
	char *password = "oracle11g";
	char *statement;
	
	//If there in an oracle error, handle it
	EXEC SQL WHENEVER SQLERROR DO catchOracleError();

	//Connect to oracle
	EXEC SQL CONNECT :username IDENTIFIED BY :password;
	if (sqlca.sqlcode < 0){
		printf("Error connecting to oracle!\n");
		exit(1);
	}
	else{
		printf("Connected to Oracle\n");
	}
return;	 
}
