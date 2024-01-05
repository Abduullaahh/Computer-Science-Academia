#include<stdio.h>

int main()
{
  FILE *file;
  file = fopen("input.txt", "r");
  char data;
  int n;
  while(!feof(file))
  {
    data = fgetc(file);
    printf("%c", data);
  }
  file = fopen("integers.txt", "w");
  fclose(file);
  return 0;
}
