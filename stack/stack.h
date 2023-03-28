#pragma once

#ifndef STACK_H
#define STACK_H

#include "types.h"

// 
// Stacks
//
//
//

//
// TODO
// * 
//

typedef struct stack stack;
struct stack
{
  i32 top;
  u32 capacity;
  i32* stack_array; 
};

stack* stack_create(u32 capacity);
void stack_destroy(stack* s);
void stack_dot(stack* s);
void stack_print(stack* s);

b32 stack_empty(stack* s);
b32 stack_full(stack* s);

void stack_push(stack* s, i32 item);
i32 stack_pop(stack* s);
i32 stack_peek(stack* s);

#endif // !STACK_H