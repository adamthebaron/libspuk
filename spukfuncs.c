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
int get_spuket(package *pack) {
  struct addrinfo *source;
  struct addrinfo hints;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = 0;
  getaddrinfo(pack->url, "echo")
}

/* Take connect() when dealing with the appropriate socket, add spuket, and you pretty much have the return variable of this. */

int connect_spuket(spuket *spukfd) {
  if (*spukfd->socket_type != SOCK_DGRAM) {
    struct sockaddr_in internet_address;
  }

}
