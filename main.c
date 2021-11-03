#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>


int main() {
  DIR *d = opendir(".");
  printf("Statistics for directory: .\n");

  struct stat s;
  stat(".", &s);
  printf("Total Diectory Size: %lld\n", s.st_size);

  printf("Directories:\n");
  struct dirent *entry;
  entry = readdir(d);
  while (entry) {
    if (entry -> d_type == 4) printf("\t%s\n", entry -> d_name);
    entry = readdir(d);
  }
  closedir(d);

}
