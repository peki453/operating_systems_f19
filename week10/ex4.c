#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <dirent.h>

int main()
{
    int n = 1000, cntr = 0;
    long int* inode;
    inode = malloc(n * sizeof(long int));
    
    DIR *dir;
    struct dirent *dp;
    char * file_name;
    dir = opendir(".");
    
    while ((dp=readdir(dir)) != NULL) 
    {
        if ( !strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..") )
        {
            // do nothing
        } 
	else 
	{
            file_name = dp->d_name; 

	    if(cntr >= n) 
	    {
		n *= 2;		 
		inode = (long int*) realloc(inode, n);
	    }

	    inode[cntr] = (*dp).d_ino;
	    cntr++; 
        }
    }

    int* done = calloc(cntr, sizeof(int));
 
    for(int i = 0; i < cntr; i++) 
    {
	if(done[i] == 1) continue;

	int pass = 0;

	for(int j = i + 1; j < cntr; j++) 
	{
	    if(inode[i] == inode[j]) done[j] = 1, pass++;	
	}
	
	if(!pass) continue;
	printf("%ld ", inode[i]);

	dir = opendir(".");

	while ((dp=readdir(dir)) != NULL) 
	{
            if ( !strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..") )
            {
            	// do nothing
            } 
	    else 
	    {
		file_name = dp->d_name; 
		if((*dp).d_ino == inode[i]) printf("%s ", file_name);     	
       	    }
       }
       printf("\n");	
    }

    closedir(dir);

    return 0;
}