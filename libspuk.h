#include <sys/socket.h>
#include <netinet/in.h>
#define DEFAULT_FTP 20
#define DEFAULT_HTTP 80
#define DEFAULT_HTTPS 443
#define DEFAULT_SSH 22
#define DEFAULT_SFTP 22
#define DEFAULT_FTPS 22
#define DEFAULT_TELNET 23
//#define DEFAULT_DNS 53

#define INSTALLED "/var/log/installed"
#define REMOVED "/var/log/removed"
#define DOWNLOADED "/var/log/downloaded"
#define WEBADDR "/var/log/webaddr"
#define CONFIGURE "/etc/spuk.conf"
#define DENY "/etc/spuk.deny"
#define FILES "/var/spuk/files"
