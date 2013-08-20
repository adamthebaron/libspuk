#include <sys/socket.h>
#include <netinet/in.h>

/* Package structure which is used with a socket*/
typedef struct{
	/* URL to EXACT location where tarball is. Accept protocols in README */
	char const * const URL;
	/* Y-you know what... I don't know why I declared this. */
	char const * const filename;
	/* Location of tarball on server */
	char const * const location;
	/* Size of tarball in bytes */
	float size;
	/* Checksums to be safe */
	char const * const MD5SUM;
	char const * const SHA512SUM;
	/* Port to use, some defaults are defined at the top of "spuk.h" */
	int const port;

}package;