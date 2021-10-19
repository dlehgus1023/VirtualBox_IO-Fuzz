#include <stdio.h>
#include <stdlib.h>
#include <sys/io.h>

int main() {
  iopl(3);

  for(int port = 0x0; port <= 0xffff; port++) {
    FILE* fp = fopen("last.txt", "w");
    fprintf(fp, "[+] I/O PORT : %#x\n", port);
    fclose(fp);

    for(int value = -0xf; value <= 0xffff; value++) {
      outb(value, port);
      outw(value, port);
      outl(value, port);
    }

  printf("[+] I/O PORT : %#x\n", port);
  }
  return 0;
}