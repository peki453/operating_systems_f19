#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() 
{
    int file = open("/dev/random", O_RDONLY);
    
    char buff[21];
    buff[20] = '\0';
    
    read(file, buf, 20);
    printf("%s\n", buff);
    
    close(file);
    
    return 0;
}