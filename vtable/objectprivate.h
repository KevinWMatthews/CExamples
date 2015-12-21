#ifndef objectprivate_H
#define objectprivate_H

typedef struct ObjectInterfaceStruct * ObjectInterface;

//Objects look here to determine what interface they need to fulfill.
typedef struct ObjectInterfaceStruct
{
  void (*SetData)(Object self, void *data);
  void (*GetData)(Object self, void *data);
  void (*Double)(Object self);   //Only valid for numeric data
} ObjectInterfaceStruct;

typedef struct ObjectStruct
{
  ObjectInterface vtable;
  //etc; whatever you need
  const char * type;
  int id;
} ObjectStruct;

#endif
