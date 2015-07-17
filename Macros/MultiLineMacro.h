#define SINGLE_LINE_MACRO(arg) ((arg) + 1)
#define SINGLE_LINE_MACRO_WITH_BRACES(arg) { (arg) + 1; }

#define MULTI_LINE_MACRO(arg) ( \
  ((arg) * 2) == \
  ((arg) + 2) \
)
#define MULTI_LINE_MACRO_WITH_BRACES(arg) { \
  ((arg) * 2) == \
  ((arg) + 2); \
}

//If you use this it won't compile.
//You can't but a ; inside ().
//Use braces instead
#define MULTI_STATEMENT_MACRO(arg) ( \
  ((arg) * 3 == (arg) + 3); \
  ((arg) / 3 == (arg) - 3); \
)

#define MULTI_STATEMENT_MACRO_WITH_BRACES(arg) { \
  ((arg) * 3 == (arg) + 3); \
  ((arg) / 3 == (arg) - 3); \
}
