#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include "spukdefs.c"

//The only thing this package should have is a URL or file path
struct spuket get_spuket(package * pack) {
  struct spuket * return_variable;
  int status;
  //Use url in package pack to populate the linked list of addrinfo structs in the spuket
  if (status = getaddrinfo(pack->url, NULL, NULL, &(return_variable->reference)) != 0)
    fprintf(stderr, "ERROR getaddrinfo(): %s\n", gai_strerror(status)); //Thanks beej
  return_variable->reference->ai_family = return_variable->address_family;
  return_variable->reference->ai_socktype = return_variable->socket_type;
  return_variable->reference->ai_protocol = return_variable->protocol;  
  if (return_variable->sockfd = socket(return_variable->address_family, return_variable->socket_type, return_variable->protocol) == -1)
    fprintf(stderr, "ERROR socket(): %s\n", perrror(return_variable->sockfd));
  return_variable->software = &pack;
  return return_variable;
}


