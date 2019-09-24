#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *line;
  size_t size;
  char *a;
  
  size = 100;
  line = (char*) malloc (size + 1);
  a = disemvowel(line);
  
  while (getline(&line, &size, stdin) > 0) {
    printf("%s\n", a);
  }
  free(a);
  free(line);
}
