#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30
/**
 * Main
 */
int main(int argc, char **argv)
{
  char *path = malloc(100);
  char *c_path = argv[0];
  int i_path = 0;
  // Parse command line
  for ( int i =1; i<argc ; i++){
    char *word = argv[i];
    // copy the word to path
    int length = strlen(word);
    for (int i = 0; i<length; i++){
      *(path + i_path) = *(word + i);
      i_path++;
    }
  }
  // add the last char for a string
  if (i_path == 0){
    *path = '.';
  }
  *(path + i_path + 1 ) = *"\0";

  // Open directory  
  struct d;
  DIR *d;
  struct dirent *dir;
  d = opendir(path);
  // // // Repeatly read and print entries
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
    }
  }
  // Close directory
  closedir(d);
  return 0;
}