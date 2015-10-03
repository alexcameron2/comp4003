/* This is a dynamic sql program based on an sample written by Alkex Cameron - 100861937 */

#include <stdio.h>
#include <string.h>

void catchOracleError();

int main(){
	exec sql begin declare section;
		char *user = "oracle";
		char pword = "oracle11g";
	exec sql end declare section;

	printf("Connected to Oracle\n");
return;	 
}
