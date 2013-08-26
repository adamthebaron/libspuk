#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "spukdefs.c"
/* Get spuket for specific location, protocol, and port
   Really, this function should be called to put values
   into the address_family, protocol, and socket_type 
   variables of a spuket */

int getspuket(package *pack) {
	char url_protocol[5];          //ftp://
	char top_level_domain[128];    //example.com/
	char path_to_file[128];		   //folder/directory/files/
	char filename[64];			   //program.tar.gz
	memcpy(url_protocol, (const char *) &pack->url, sizeof(char) * 4);
	if (url_protocol[5] == ':')
		url_protocol[5] == '\0';
	memcpy(top_level_domain, (const char *) &pack->url, sizeof(char) * 6);
	int i;
	for(i = 0; i <= (sizeof(top_level_domain)); i++) {
		if (top_level_domain[i] == ':' || top_level_domain[i] == '/')
			top_level_domain[i] = '\0';
	}
}
