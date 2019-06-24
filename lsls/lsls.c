#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#define MAX 30

char* concat(const char *s1, const char *s2)
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1); // +1 to copy the null-terminator
    return result;
}

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
  // print the dir
  *(path + i_path + 1 ) = *"\0";
  printf("%s %s \n", c_path, path);
  
  // add the last char for a string
  if (i_path == 0){
    *path = '.';
    
  }
  

  // Open directory  
  struct d;
  DIR *d;
  struct dirent *dir;
  d = opendir(path);

  // Repeatly read and print entries
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      struct stat *st;
      char* file_path;
      if (path[strlen(path) -1] != '/'){
        char *dash = "/";
        char *dash_path = concat(path,dash);
        file_path = concat(dash_path, dir->d_name);
      } else{
        // the user put a path in with / at the end
        file_path= concat(path, dir->d_name);
      }
      stat(file_path, st);
      // off_t size = st.st_size;
      printf("%14ld %s\n", st->st_size,  dir->d_name);
    }
  }
  // Close directory
  closedir(d);
  return 0;
}