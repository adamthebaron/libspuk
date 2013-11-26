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
  return_variable->reference->ai_family = return_variable->address_family;
  return_variable->reference->ai_socktype = return_variable->socket_type;
  return_variable->reference->ai_protocol = return_variable->protocol;  
  if ((return_variable->sockfd = socket(return_variable->address_family, return_variable->socket_type, return_variable->protocol)) == -1)
    fprintf(stderr, "ERROR: socket()");
  return_variable->software = pack;
  return return_variable;
}


int download_and_prepare_spuket(struct spuket *spkt) {
  char *address];
  int status = -1;
  address = spkt->software->url;
  faddr = spkt->address_family;
  sock = spkt->socket_type;
  protocl = spkt->protocol;
  sockfd = socket(faddr, sock, protocl);
  if (sockfd == status)
    fprintf(stderr, "ERROR socket(): %s\n", gai_strerror(status));
  //if ((connect(sockfd, )


}

int uncompress_file_from_spuket(struct spuket *spkt) {


}
