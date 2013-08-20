#include <sys/socket.h>
#include <netinet/in.h>

/* Get socket for specific location, protocl, and port */
int getsocket(package package, char const * const url);