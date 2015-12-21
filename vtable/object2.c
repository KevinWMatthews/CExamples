#include "object2.h"
#include "objectprivate.h"
#include <stdlib.h>

typedef struct Object2Struct * Object2;

typedef struct Object2Struct
{
  ObjectStruct base;
  char character;
} Object2Struct;

static void Object2_GetData(Object super, void * data)
{
  Object2 self = (Object2)super;
  char *char_data = (char *)data;

  if (!self || !char_data)
  {
    return;
  }

  *char_data = self->character;
}

static void Object2_SetData(Object super, void * data)
{
  Object2 self = (Object2)super;
  char *char_data = (char *)data;

  if (!self || !char_data)
  {
    return;
  }

  self->character = *char_data;
}

static void Object2_Double(Object super)
{
  return;
}

static ObjectInterfaceStruct interface = {
  .SetData = Object2_SetData,
  .GetData = Object2_GetData,
  .Double  = Object2_Double
};

Object Object2_Create(void)
{
  Object2 self = calloc(1, sizeof(Object2Struct));
  self->base.vtable = &interface;
  self->base.type = "Object2";
  self->base.id = 2;
  self->character = 'a';
  return (Object)self;
}
