#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    openlog(NULL,0,LOG_USER);

    if(argc < 3) {
        syslog(LOG_ERR, "Missing argument(s)");
        exit(1);
    }

    char *writefile = argv[1];
    char *writestring = (char *)malloc(strlen(argv[2]) + 1);
    sprintf(writestring, "%s\n", argv[2]);


    int fd = creat(writefile, 0644);
    if(fd==-1) {
        syslog(LOG_ERR, "open: %s", strerror(errno));
        exit(1);
    }
    syslog(LOG_DEBUG,"Writing %s to %s", writestring, writefile);
    ssize_t nr;
    nr = write(fd,writestring,strlen(writestring));
    if(nr==-1) {
        syslog(LOG_ERR, "write: %s", strerror(errno));
        exit(1);
    }
    if(close(fd) == -1) {
        syslog(LOG_ERR, "close: %s", strerror(errno));
        exit(1);
    }

    exit(0);
}
