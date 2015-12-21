#include <stdio.h>
#include <stdlib.h>

//Read and rename with vtable

typedef struct VariableStruct * Variable;
typedef struct DataTypeStruct * DataType;
typedef struct CharDataTypeStruct * CharDataType;
typedef struct IntDataTypeStruct * IntDataType;
typedef struct DataTypeInterfaceStruct *DataTypeInterface;


//The interface that the high-level struct uses to interact with
//the various permutations of low-level details
typedef struct DataTypeInterfaceStruct
{
  DataType (*Initialize)(void);
  void (*GetData)(DataType self, void *data);
  void (*SetData)(DataType self, void *data);
} DataTypeInterfaceStruct;

// The high-level struct that you'll access.
typedef struct VariableStruct
{
  DataTypeInterface interface;
  DataType data_type;
} VariableStruct;

//Declaration of the low level details
// typedef struct DataType
// {

// } DataType;

typedef struct IntDataTypeStruct
{
  int integer;
} IntDataTypeStruct;

typedef struct CharDataTypeStruct
{
  char character;
} CharDataTypeStruct;

DataType CharInitialize(void)
{
  CharDataType self = calloc(1, sizeof(CharDataTypeStruct));
  self->character = 0;
  return (DataType)self;
}

void CharGetData(DataType self, void *data)
{
  CharDataType char_struct = (CharDataType)self;
  char *char_data = (char *)data;

  *char_data = char_struct->character;
}

void CharSetData(DataType self, void *data)
{
  CharDataType char_struct = (CharDataType)self;
  char *char_data = (char *)data;

  char_struct->character = *char_data;
}

DataType IntInitialize(void)
{
  IntDataType self = calloc(1, sizeof(IntDataTypeStruct));
  return (DataType)self;
}

void IntGetData(DataType self, void *data)
{
  IntDataType int_struct = (IntDataType)self;
  int *int_data = (int *)data;

  *int_data = int_struct->integer;
}

void IntSetData(DataType self, void *data)
{
  IntDataType int_struct = (IntDataType)self;
  int *int_data = (int *)data;

  int_struct->integer = *int_data;
}

//Definitions of low-level details
DataTypeInterfaceStruct IntInterface = {
  .Initialize = IntInitialize,
  .GetData    = IntGetData,
  .SetData    = IntSetData
};

DataTypeInterfaceStruct CharInterface = {
  .Initialize = CharInitialize,
  .GetData    = CharGetData,
  .SetData    = CharSetData
};

void Variable_SetData(Variable self, void *data)
{
  self->interface->SetData(self->data_type, data);
}

void Variable_GetData(Variable self, void *data)
{
  self->interface->GetData(self->data_type, data);
}

int main(void)
{
  char main_char = 'a';
  char new_char = 'z';
  int main_int = 42;
  int new_int = 66;
  //This will go in a Variable_Create function
  DataType char_data_type = CharInitialize();
  DataType int_data_type = IntInitialize();
  VariableStruct character_variable = {
    .interface = &CharInterface,
    .data_type = char_data_type
  };
  VariableStruct integer_variable = {
    .interface = &IntInterface,
    .data_type = int_data_type
  };

  Variable char_var = &character_variable;
  Variable int_var = &integer_variable;

  printf("How to return variable data types.\n");
  printf("\n%s\n", "Print integer:");
  Variable_GetData(int_var, (void*)&new_int);
  printf("internal data before being set: %d\n", new_int);
  Variable_SetData(int_var, (void*)&main_int);
  Variable_GetData(int_var, (void*)&new_int);
  printf("internal_data after being set: %d\n", new_int);

  printf("\n%s\n", "Print Character:");
  Variable_GetData(char_var, (void*)&new_char);
  printf("internal data before being set: %c\n", new_char);
  Variable_SetData(char_var, (void*)&main_char);
  Variable_GetData(char_var, (void*)&new_char);
  printf("internal_data after being set: %c\n", new_char);

  return 0;
}
