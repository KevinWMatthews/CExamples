#include "MultiLineMacro.h"

int main()
{
  int i = 0;
  i++; i--;

  SINGLE_LINE_MACRO(1);
  SINGLE_LINE_MACRO_WITH_BRACES(1);

  MULTI_LINE_MACRO(2);
  MULTI_LINE_MACRO_WITH_BRACES(2);


  MULTI_STATEMENT_MACRO_WITH_BRACES(3);

  return 0;
}
