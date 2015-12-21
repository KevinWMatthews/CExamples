#include <stdio.h>

typedef struct PrintStruct * PrintPointer;

//Struct definitions
typedef struct PrintInterface
{
  void (*print)(int i);
  void (*print_double)(int i);
} PrintInterface;

typedef struct PrintStruct {
  PrintInterface interface;
  int i;
} PrintStruct;

//Fucntion Prototypes
void PrintStruct_Print(PrintPointer p);
void PrintStruct_PrintDouble(PrintPointer p);

static void simple_print(int i);
static void simple_print_double(int i);
static void fancy_print(int i);
static void fancy_print_double(int i);


//Struct declarations
PrintInterface simple_interface = {
  .print = simple_print,
  .print_double = simple_print_double
};

PrintInterface fancy_interface = {
  .print = fancy_print,
  .print_double = fancy_print_double
};

//Main!
int main(void)
{
  PrintStruct simple_print_struct = {
    .interface = simple_interface,
    .i = 7
  };
  PrintPointer simple_print_pointer = &simple_print_struct;

  PrintStruct fancy_print_struct = {
    .interface = fancy_interface,
    .i = 42
  };
  PrintPointer fancy_print_pointer= &fancy_print_struct;

  printf("Hello, world!\n\n");

  printf("%s\n", "Simple print:");
  PrintStruct_Print(simple_print_pointer);
  PrintStruct_PrintDouble(simple_print_pointer);

  printf("%s\n", "\nFancy print:");
  PrintStruct_Print(fancy_print_pointer);
  PrintStruct_PrintDouble(fancy_print_pointer);

  printf("\n");
  return 0;
}

//Public functions
void PrintStruct_Print(PrintPointer p)
{
  p->interface.print(p->i);
}

void PrintStruct_PrintDouble(PrintPointer p)
{
  p->interface.print_double(p->i);
}

//Internal functions
static void simple_print(int i)
{
  printf("%d\n", i);
}

static void simple_print_double(int i)
{
  printf("%d\n", 2*i);
}

static void fancy_print(int i)
{
  printf("The value is: %d\n", i);
}

static void fancy_print_double(int i)
{
  printf("The value is: %d\n", 2*i);
}
