#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int shift;

//TODO create a function to, basicaly, bruteforce all possibilities
  printf("Choose shift number [1-26]: ");
  fflush(stdout);
  scanf("%d", &shift);

  if (shift < 1 || shift > 26) {
    fprintf(stderr, "Shift number is out of range");
    exit(EXIT_FAILURE);
  }

  char *inputFileName="folha_cifrada.txt";

  FILE *inputFile = fopen(inputFileName, "r");
  if (inputFile == NULL) {
    fprintf(stderr, "Failed to open input file\n");
    exit(EXIT_FAILURE);
  }

  char line[256];
  while (fgets(line, sizeof(line), inputFile)) {
    for (int i = 0; line[i] != '\0'; i++) {
      if (!isspace(line[i]) && !isblank(line[i]))
        printf("%c", (((line[i] - 97) + shift) % 26) + 97);
      else
        printf("%c", line[i]);
    }
  }

  fclose(inputFile);
  return 0;
}
