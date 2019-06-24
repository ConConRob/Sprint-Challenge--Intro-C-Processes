#include <stdio.h>
#include <dirent.h>

#define MAX 30
/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char path[MAX];
  printf("Enter a path: ");
  fgets(path, MAX, stdin);

  printf("%s\n", path);
  // Open directory
  
  struct d;
  DIR *d;
  struct dirent *dir;

  d = opendir(".");
  // // Repeatly read and print entries
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
    }
  }
  // Close directory

  return 0;
}