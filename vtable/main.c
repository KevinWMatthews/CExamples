#include <stdio.h>

//Prototypes
void simple_print(int i);
void simple_print_double(int i);
void fancy_print(int i);
void fancy_print_double(int i);

//Struct definition
typedef struct PrintInterface
{
  void (*print)(int i);
  void (*print_double)(int i);
} PrintInterface;

//Public struct declarations
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

  printf("Hello, world!\n\n");
  printf("%s\n", "Simple print:");
  simple_interface.print(1);
  simple_interface.print_double(1);
  printf("%s\n", "\nFancy print:");
  fancy_interface.print(1);
  fancy_interface.print_double(1);
  printf("\n");
}

//Helper functions
void simple_print(int i)
{
  printf("%d\n", i);
}

void simple_print_double(int i)
{
  printf("%d\n", 2*i);
}

void fancy_print(int i)
{
  printf("The value is: %d\n", i);
}

void fancy_print_double(int i)
{
  printf("The value is: %d\n", 2*i);
}
