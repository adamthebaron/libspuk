#include <sys/socket.h>
#include <netinet/in.h>
#include <spuk/typedefs.c>
#include <stdlib.h>

/* Get socket for specific location, protocol, and port */
int getsocket(package *pack) {
char url_parse[(sizeof(char)*(*pack->url)) + 1];
unsigned i = 0; //Increment variable
while(url_parse != ':') {
url_parse[i] = *pack->url[i];
i++;
}
i = 0;
char protocol[5];
protocol = url_parse;
if (url_parse[i] != '\0')
url_parse[i] = '\0';

}
