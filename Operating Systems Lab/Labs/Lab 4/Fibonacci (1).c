#include <stdio.h>

int main(int argc, char* argv[])
{
  int i, n = atoi(argv[1]);
  int t1 = 0, t2 = 1;
  int t3 = t1 + t2;
  printf("\nFibonacci Series : %d, %d, ", t1, t2);
  for (i = 3; i <= n; i++)
  {
    printf("%d, ", t3);
    t1 = t2;
    t2 = t3;
    t3 = t1 + t2;
  }
  printf("\n");
  return 0;
}
