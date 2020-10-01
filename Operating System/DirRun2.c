#include <stdio.h>
#include <dirent.h>
 
 main()
{
    struct dirent *de; 

    DIR *dr = opendir(".//Camera");
 
    if (dr == NULL)
    {
        printf("Could not open current directory" );
        return 0;
    }
 
    while ((de = readdir(dr)) != NULL)
            printf("%s\n", de->d_name);
 
    closedir(dr);    

}