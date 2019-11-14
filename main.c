#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

int main() {
  struct stat demo_meta;
  stat("demo", &demo_meta);
  char permissions[8][6] = {"---", "x--", "-w-", "xw-", "--r", "x-r", "-wr", "xwr"};
  char read_perm[100];

  printf("Metadata about demo file\n");
  printf("\tfile size: %d\n", demo_meta.st_size);
  printf("\tmode: %d\n", demo_meta.st_mode);
  printf("\tmode: %d %d\n", demo_meta.st_mode % 8, demo_meta.st_mode / 64 % 8);
  printf("\tmode: %o\n", demo_meta.st_mode);
  sprintf(read_perm, "%s%s%s", permissions[demo_meta.st_mode / 64 % 8], permissions[demo_meta.st_mode / 8 % 8], permissions[demo_meta.st_mode % 8]);
  printf("\tmode: %s\n", read_perm);
  printf("\ttime of last access: %s\n", ctime(&demo_meta.st_atime));
  return 0;
}
