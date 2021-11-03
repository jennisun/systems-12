#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>


int main() {
  DIR *d = opendir(".");
  printf("Statistics for directory: .\n");

  struct stat s;
  stat(".", &s);
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
  d = opendir(".");
  entry = readdir(d);
  while (entry) {
    stat(entry -> d_name, &s);
    if (entry -> d_type == 8) printf("\t%s\t%lld\n", entry -> d_name, s.st_size);
    entry = readdir(d);
  }
  closedir(d);

  return 0;

}
