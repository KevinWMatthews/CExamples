#ifndef object_H
#define object_H

typedef struct ObjectStruct * Object;

//There is no create method here. You don't create a generic object.
//Instead, you create a specific one.
//However, you use these generic functions to act on the varying objects.
void Object_Get(Object self, void *data);
void Object_Set(Object self, void *data);
void Object_Double(Object self);  //Only valid for numeric data.

#include "objectprivate.h"

#endif