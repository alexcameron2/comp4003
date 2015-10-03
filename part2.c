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
//	if (sqlca.sqlcode < 0){
//		printf("Could not connect to oracle!\n");
//		exit(1);
//	}
//	else{
		printf("Connected to Oracle\n");
//	}
	
exit(1);	 
}
