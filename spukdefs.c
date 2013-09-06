#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdbool.h>

/* Package structure which is used with a socket and has a variety of different flags, usually used for spuk the package manager */
typedef struct{
  /* Only download, do not install */
  bool no_install;
  /* Edit configure script if present */
  bool edit_configure;
  /* Edit makefile script if present */
  bool edit_makefile; 
  /* URL to EXACT location where file is. */
  char * url;
  /* Size of tarball in bytes */
  size_t size;
  /* Checksums to be safe */
  char * md5sum;
  char * sha512sum;
}package;



/* Interface between a package and the files it added/removed */
typedef struct{
	/* Package that we will be dealing with */
	package * software;
	/* Number of files added */
	int files_added;
	/* Number of files removed */
	int files_removed;
        /* Array of file paths that point to EACH file that the package has installed */
 	char * const files[];
}profile;



/* wrapper around the standard socket which helps with the creation of a socket tailored to a package */
struct spuket{

	/* Protocol family to use. For example, AF_INET, which is a bunch of protocols to use with IPv4 */
        int address_family;
	/* The type of transmission between the two computers. For example, SOCK_STREAM for a reliable connection */
	int socket_type;
	/* That one parameter in socket() that everyone sets to 0 */
	int protocol;
	/* Package that we will be dealing with */
	package * software;
	/* This is a function pointer to a socket() call with it's parameters
	  equal to the values in address_family, socket_type, and protocol*/
	//int (*sock_desc) (int address_family, int socket_type, int protocol);
        int sockfd;
        /* Reference */
	struct addrinfo *reference;
	/* Linked list, used only when argv has multiple addresses. */
	struct spuket *next_spuket;
};
