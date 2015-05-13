#include <stdio.h>

#ifndef NULL
#define NULL 0
#endif

int (*fp1)(float, char, char) = NULL;   // Define a function pointer and initialize it to NULL
int (*fp2)(int a, int b) = NULL;

int f1(float a, char b, char c) { printf("In f1\n"); return a+b+c; }
int f2(int a, int b) { printf("In f2\n"); return a*b; }
// void callingConvention(float a, char b, char c) __attribute__((cdecl));


//*** Assign address to function pointer ***//
void AssignAddressToFunctionPointer(void)
{
  printf("\nAssign Address To Function Pointer\n");
  fp1 = f1;   // Short assignment
  fp2 = &f2;  // Proper assignment using address operator
}


//*** Compare function pointers ***//
void CompareFunctionPointers(void)
{
  void (*fp)(void) = NULL;

  printf("\nCompare Function Pointers\n");

  if (fp == 0)
  {
    printf("fp is NULL\n");
  }
  else
  {
    printf("fp has an address\n");
  }

  if (fp1 > 0)
  {
    if (fp1 == &f1)
    {
      printf("fp1 == f1\n");
    }
    else
    {
      printf("fp1 != f1\n");
    }
  }

  if (fp2 != 0)
  {
    if (fp2 == &f2)
    {
      printf("fp2 == f2\n");
    }
    else
    {
      printf("fp2 != f2\n");
    }
  }
}


//*** Pass function pointers as arguments ***//
int fpAsArg1(float a, char b, char c, int (*fptr)(float, char, char))    // Pass a function pointer as an argument
{
  return (*fptr)(a, b, c);  // Dereference the function pointer, i.e. call the function
}

int fpAsArg2(int a, int b, int (*fptr)(int, int))
{
  return (*fptr)(a, b);
}

void PassFunctionPointerAsArgument(void)
{
  int res;
  printf("\nPass a function pointer as an argument\n");

  res = fpAsArg1(12, 'b', 'c', fp1);
  printf("Result: %d\n", res);

  res = fpAsArg2(7, 6, &f2);
  printf("Result: %d\n", res);
}


//*** Return a function pointer ***//
// Five functions that fit our prototype: int (*)(int, int)
int add(int a, int b)
{
  return a+b;
}

int subtract(int a, int b)
{
  return a-b;
}

int multiply(int a, int b)
{
  return a*b;
}

int divide(int a, int b)
{
  if (b != 0)
    return a/b;
  else
    return 666;
}

int undefinedOpCode(int a, int b)
{
  return 666;
}

// Return a function pointer corresponding to the given operation code:
//   '+' -> addition
//   '-' -> subtraction

// Initially was char getMathFunction(char opCode)
// Now instead of returning a char, we're returning a function pointer that takes two ints and returns an int:
// int (*<original_function>)(int, int)
int (*getMathFunction(char opCode))(int, int)
{
  if (opCode == '+')
    return &add;
  else if (opCode == '-')
    return &subtract;
  else
    return &undefinedOpCode;
}

// Above was the hard way; we can also use a typedef and it's a bit more clear
typedef int (*mathFunction)(int, int);    // C compiler magic!! Typedefs mathFunction with int (*)(int, int)
mathFunction getMathFunctionWithTypedef(char opCode)
{
  if (opCode == '+')
    return &add;
  else if (opCode == '-')
    return &subtract;
  else
    return &undefinedOpCode;
}

void ReturnAFunctionPointer(void)
{
  // Define a function pointer to hold the return value
  int (*fp)(int, int) = NULL;
  int res;

  printf("\nReturn a function pointer:\n");

  fp = getMathFunction('+');
  res = (*fp)(2, 2);
  printf("%d\n", res);

  fp = getMathFunction('-');
  res = (*fp)(3, 4);
  printf("%d\n", res);

  fp = getMathFunction('!');
  res = (*fp)(6, 7);
  printf("%d\n", res);

  printf("\n");
  fp = getMathFunctionWithTypedef('+');
  res = (*fp)(2, 2);
  printf("%d\n", res);

  fp = getMathFunctionWithTypedef('-');
  res = (*fp)(3, 4);
  printf("%d\n", res);

  fp = getMathFunctionWithTypedef('!');
  res = (*fp)(6, 7);
  printf("%d\n", res);
}


//*** Arrays of function pointers ***//
void ArrayOfFunctionPointers(void)
{
  int res, i;
  // Declare an array of function pointers
  int (*fpa1[4])(int, int) = {NULL};    // function pointer array; careful with the syntax!!
  // Declare an array of function pointers using the typedef
  mathFunction fpa2[4] = {NULL};

  printf("\nExecuting functions from an array of function pointers:\n");

  // Initialize both function pointer arrays
  fpa1[0] = &add;
  fpa1[1] = &subtract;
  fpa1[2] = &multiply;
  fpa1[3] = &divide;

  fpa2[0] = &add;
  fpa2[1] = &subtract;
  fpa2[2] = &multiply;
  fpa2[3] = &divide;

  // Call each function
  for (i = 0; i < 4; i++)
  {
    res = (*fpa1[i])(3, 4); // Call the function pointer using an array index
    printf("%d\n", res);
  }

  printf("\n");
  for (i =0; i < 4; i++)
  {
    res = (*fpa2[i])(3, 4); // Call the function pointer using an array index
    printf("%d\n", res);
  }
}


//*** main ***//
int main(void)
{
  int r1, r2;

  AssignAddressToFunctionPointer();

  CompareFunctionPointers();

  PassFunctionPointerAsArgument();

  ReturnAFunctionPointer();

  ArrayOfFunctionPointers();

  return 0;
}
