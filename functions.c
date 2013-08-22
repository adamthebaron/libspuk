#include <sys/socket.h>
#include <netinet/in.h>

/* Get socket for specific location, protocl, and port */
int getsocket(package *pack) {
	char url_parse[(sizeof(char)*(*pack->url)) + 1];
	strcpy(url_parse, *pack->url);
	while()
}
