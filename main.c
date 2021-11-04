#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char directory[500];
  DIR *d;

  if (argc > 2) printf("Too many arguements\n");
  else if (argc > 1) strcpy(directory, argv[1]);
  else {
    printf("Enter directory name: \n");
    return 0;
  }


  d = opendir(directory);
  printf("Statistics for directory: %s\n", argv[1]);

  struct stat s;
  stat(directory, &s);
  printf("Total Directory Size: %lld\n", s.st_size);

  printf("Directories:\n");
  struct dirent *entry;
  entry = readdir(d);
  while (entry) {
    if (entry -> d_type == 4) printf("\t%s\n", entry -> d_name);
    entry = readdir(d);
  }
  closedir(d);

  printf("Regular files:\n");
  d = opendir(directory);
  entry = readdir(d);
  while (entry) {
    stat(entry -> d_name, &s);
    if (entry -> d_type == 8) printf("\t%s\t%lld\n", entry -> d_name, s.st_size);
    entry = readdir(d);
  }
  closedir(d);

  return 0;

}
