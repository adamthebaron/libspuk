#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdbool.h>

/* Package structure which is used with a socket and has a variety of different flags, usually used for spuk the package manager */
typedef struct{
  /* Each bit in this byte represents an option.
     1st bit: Install if on, download if off
     2nd bit: Check configure script if on, do nothing if off
     3rd bit: Check makefile if on, do nothing if off
     4th bit: Skip MD5 check if on
     5th bit: Skip SHA check if on
     6th bit: Remove package if on
     7th bit: Build package if on
     8th bit: Extract package if on
     Bitwise operation for the win.
*/
  char options; //A char is reprsented as 1 byte.
  /* URL to EXACT location where file is. */
  char * url;
  /* Size of tarball in bytes */
  size_t size;
  /* Checksums to be safe */
  char * md5sum;
  char * sha512sum;
  /* This is for file I/O and the actual package management on the machine */
  profile package_io;
}package;



/* Interface between a package and the files it added/removed */
typedef struct{
	/* Number of files added */
	signed int files_added;
	/* Number of files removed */
	signed int files_removed;
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
