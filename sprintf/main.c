#include <stdio.h>

int main(void)
{
  float f = 0;
  int d = 0;
  char s[11] = {0};

  sprintf( s, "Int: %d", d );
  printf("%s\n", s);

  d = 7;
  sprintf( s, "Int: %d", d );
  printf("%s\n", s);

  sprintf(s, "Flt: %f", f);
  printf("%s\n", s);

  sprintf(s, "%1.1f", f);
  printf("%s\n", s);

  sprintf(s, "%1.2f", f);
  printf("%s\n", s);

  sprintf(s, "%8.2f", f);
  printf("%s\n", s);

  f = 0.7209;
  sprintf(s, "%5.2f", f);
  printf("%s\n", s);

  return 0;
}
