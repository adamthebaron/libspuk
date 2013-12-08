/* WELCOME TO POINTER HELL */
/* You may be asking why I am passing each individual variable to a function-specific
   scope variable. I don't freaking know. It looks cool and impresses people. So, money.*/
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <errno.h>
#include "spukdefs.h"
#include "libspuk.h"

package * get_package_url(char *s) {
  package * return_variable;
  memset(&return_variable, 0, sizeof(package));
  return_variable->url = &(*s);
  return return_variable;
}


/* The only thing that should be accessed in the passed package is the url. */
struct spuket * get_spuket(package *pack) {
  struct spuket * return_variable;
  memset(&return_variable, 0, sizeof(struct spuket));
  int status;
  if(status = getaddrinfo(pack->url, NULL, NULL, &(return_variable->reference)) != 0)
  	fprintf(stderr, "ERROR getaddrinfo(): %s\n", gai_strerror(status)); //Thanks beej
   /* Upon a successful getaddrinfo() call, we can assume two things:
	1. The host NIC card works properly with its TCP/IP stack (I dont know anything.)
	2. We have the IP address of the location we are to connect to.*/
  return_variable->reference->ai_family = return_variable->address_family;
  return_variable->reference->ai_socktype = return_variable->socket_type;
  return_variable->reference->ai_protocol = return_variable->protocol;  
  if ((return_variable->sockfd = socket(return_variable->address_family, return_variable->socket_type, return_variable->protocol)) == -1)
    fprintf(stderr, "ERROR: socket()");
  return_variable->software = pack;
  return return_variable;
}

/* What we now have is a spuket with the following information:
      a protocol family (AF_INET, AF_INET6, AF_UNIX)
      a socket type (SOCK_DGRAM, SOCK_STREAM, possibly even SOCK_RAW)
      a protocol specific to the protocol family (I dont frikin know)
      */
int connect_spuket(struct spuket *spkt) {
  
  
}
