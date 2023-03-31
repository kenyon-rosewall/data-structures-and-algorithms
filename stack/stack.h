#pragma once

#ifndef STACK_H
#define STACK_H

#include "types.h"

//
// Stacks
//
// I decided to implement this with an array for two reasons. One, I have been using linked
// lists for other things such as graphs. Two, seeing as how a stacks I'm familiar with are
// linked to the hardware and have a hard limit and generate the condition of the now topical
// phrase "stack overflow." I also don't clear out the values of the popped items, which will
// lead to garbage data if you were to just look at the stack in its capacity. I'm fine with
// this solution.
//
// Due to Cs limitation at returning NULL for int types, I decided to return INT_MIN from
// stack_pop() when there wasn't any items in the stack. I could have gone a different way
// with this, but I'm okay with this. It couldn't be something simple like -1 because I am
// allowing the items to be negatve numbers all well. I also could have done somethnig similar
// when the stack was full, but I currently return NULL and print out to the stdout "Stack
// Overflow", even though I am aware that this isn't the error here, should just be something
// like "The stack is full."
//

//
// TODO
// * Implementing stack to perform tasks (infix expressions, reversing strings)
//

typedef struct stack stack;
struct stack
{
  i32 top;
  u32 capacity;
  i32 *stack_array;
};

stack *stack_create(u32 capacity);
void stack_destroy(stack *s);
void stack_dot(stack *s);
void stack_print(stack *s);

b32 stack_empty(stack *s);
b32 stack_full(stack *s);

void stack_push(stack *s, i32 item);
i32 stack_pop(stack *s);
i32 stack_peek(stack *s);

#endif // !STACK_H