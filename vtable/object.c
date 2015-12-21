#include "object.h"
#include <stdlib.h>

void Object_Get(Object self, void *data)
{
  if (self)
    self->vtable->GetData(self, data);
}

void Object_Set(Object self, void *data)
{
  if (self)
    self->vtable->SetData(self, data);
}

void Object_Double(Object self)
{
  if (self)
  {
    self->vtable->Double(self);
  }
}
