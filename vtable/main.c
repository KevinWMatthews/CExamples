#include "object.h"
#include "object1.h"
#include "object2.h"
#include <stdio.h>

int main(void)
{
  int integer;
  int *integer_ptr = &integer;
  int new_integer = 42;
  Object obj1 = Object1_Create();

  char character;
  char *character_ptr = &character;
  char new_character = 'c';
  Object obj2 = Object2_Create();

  printf("\nWorking with integers:\n");
  Object_Get(obj1, (void *)integer_ptr);
  printf("Get data before setting: %d\n", integer);
  Object_Set(obj1, (void *)&new_integer);
  Object_Get(obj1, (void *)integer_ptr);
  printf("Get data after setting: %d\n", integer);
  Object_Double(obj1);
  Object_Get(obj1, (void *)integer_ptr);
  printf("Get data after doubling: %d\n", integer);

  printf("\nWorking with characters:\n");
  Object_Get(obj2, (void *)character_ptr);
  printf("Get data before setting: %c\n", character);
  Object_Set(obj2, (void *)&new_character);
  Object_Get(obj2, (void *)character_ptr);
  printf("Get data after setting: %c\n", character);
  Object_Double(obj2);
  Object_Get(obj2, (void *)character_ptr);
  printf("Get data after doubling: %c\n", character);

  return 0;
}
