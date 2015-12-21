#include "object1.h"
#include "objectprivate.h"  //So that it knows what interface it needs to fulfill
#include <stdlib.h>

typedef struct Object1Struct * Object1;

typedef struct Object1Struct
{
  ObjectStruct base;
  int data;
} Object1Struct;

static void Object1_GetData(Object super, void *data)
{
  Object1 self = (Object1)super;
  int *int_data = (int *)data;
  if (!data)
  {
    return;
  }
  if (!self || !self->base.vtable)
  {
    *int_data = 0;
    return;
  }
  *int_data = self->data;
}

static void Object1_SetData(Object super, void *data)
{
  Object1 self = (Object1)super;
  int *int_data = (int *)data;
  if (!data)
  {
    return;
  }
  if (!self || !self->base.vtable)
  {
    *int_data = 0;
    return;
  }
  self->data = *int_data;
}

static void Object1_Double(Object super)
{
  Object1 self = (Object1)super;
  if (!self)
  {
    return;
  }
  self->data *= 2;
}

ObjectInterfaceStruct interface = {
  .SetData = Object1_SetData,
  .GetData = Object1_GetData,
  .Double  = Object1_Double
};

Object Object1_Create(void)
{
  Object1 self  = calloc(1, sizeof(Object1Struct));
  self->base.vtable = &interface;
  self->base.type   = "Object1";
  self->base.id     = 1;
  self->data        = 0;
  return (Object)self;
}
