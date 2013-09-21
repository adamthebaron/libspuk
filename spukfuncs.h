/* WELCOME TO POINTER HELL */
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
struct spuket * get_spuket(package * pack) {
  struct spuket * return_variable;
  memset(&return_variable, 0, sizeof(struct spuket));
  int status;
  //Use url in package pack to populate the linked list of addrinfo structs in the spuket
  if ((status = getaddrinfo(pack->url, NULL, NULL, &(return_variable->reference))) != 0)
    fprintf(stderr, "ERROR getaddrinfo(): %s\n", gai_strerror(status)); //Thanks beej
  return_variable->reference->ai_family = return_variable->address_family;
  return_variable->reference->ai_socktype = return_variable->socket_type;
  return_variable->reference->ai_protocol = return_variable->protocol;  
  if ((return_variable->sockfd = socket(return_variable->address_family, return_variable->socket_type, return_variable->protocol)) == -1)
    fprintf(stderr, "ERROR: socket()");
  return_variable->software = &(*pack);
  return return_variable;
}


/*So, its September 21st, 2013, and I haven't commited code in 13 days. I feel like crap. 
  Like, I just, I hate myself and I am never going to be good at this and I grow old and
  you know... paranoid stuff that is just plain not true, but I can't convince myself to 
  think like that. Well, anyways, you know that feeling you have when you read code that 
  you wrote, but do not understand? I am having that feeling right now. Not only am I 
  having that feeling, I also feel like a pro wrote that code. So, I guess thats an 
  improbable plus. That is, you probably think I am lying and cocky. Think what you want,
  I'll be busy writing software for the rest of my life. I am Catholic though, so God is
  in there somewhere. Maybe I will be IT at a monastery or something.*/
int download_and_prepare_file(struct spuket *spkt) {
  char address[512];
  int status;
  address = spkt->software->url;
  if(system("wget %s --directory-prefix=%s", address, DOWNLOADED) == -1) {
    //Something tells me this if statement is not safe.
    printf("ERROR: Download failed. I cannot give you more info because I don't know wtf errno is.");
  }
  /* FILE DOWNLOADED */


}

int uncompress_file(struct spuket *spkt) {


}
