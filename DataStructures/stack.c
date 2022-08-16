#include <stdio.h>
#include <limits.h>

#define SIZE 5

typedef struct {
    int stack[SIZE];
    int stack_ptr;
} Stack;

void init_stack(Stack* s) {
    for(int count = 0; count < SIZE; count++) {
        s->stack[count] = 0;
    }
    s->stack_ptr = -1;
}

int push(Stack* s, int value) {
    if(s->stack_ptr >= (SIZE - 1)) {
        return INT_MIN;
    }

    s->stack_ptr++;
    s->stack[s->stack_ptr] = value; 
    return 0;
}

int pop(Stack* s) {
    if(s->stack_ptr <= -1) {
        s->stack_ptr = -1;
        return INT_MIN;
    }
    int return_value = s->stack[s->stack_ptr];
    s->stack[s->stack_ptr] = 0;
    s->stack_ptr = 0;
    return return_value;
}

int main() {

    return 0;
}