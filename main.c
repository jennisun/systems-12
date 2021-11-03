#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>


int main() {
  DIR *d = opendir(".");
  printf("Statistics for directory: .\n");

  struct stat s;
  stat(".", &s);
  printf("Total Diectory Size: %lld\n", s.st_size);



}
