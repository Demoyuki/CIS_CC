/*
	Modified by: Victor Marrujo
	Assignment: Chpt5 PA
	Filename: StackAsArray.c
	Date: Feburary 25h, 2024 (completed on Feburary 29, 2024) 
*/ 


#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 2

// Structure to represent the stack
typedef struct 
{
    int *array;
    int size;
    int top;
} Stack;

// Function to resize the stack
void stackResize(Stack *stack) 
{
    stack->size *= 2;
    stack->array = realloc(stack->array, stack->size * sizeof(int));
} //stackResize

// Function to push an item onto the stack
int push(Stack *stack, int item) 
{
    if (stack->top == stack->size - 1) 
	{
        stackResize(stack);
    } //if
    stack->array[++stack->top] = item;
    return 1;
} //push

// Function to pop an item from the stack
int pop(Stack *stack) {
    if (stack->top == -1) 
	{
        printf("Stack underflow\n");
        return -1; // You can choose a different value to represent underflow
    } //if
    return stack->array[stack->top--];
} //pop

// Function to check if the stack is empty
int isEmpty(Stack *stack)
 {
    return (stack->top == -1);
} //isEmpty

// Function to peek at the top item of the stack
int peek(Stack *stack) 
{
    if (stack->top == -1) 
	{
        printf("Stack is empty\n");
        return -1; // You can choose a different value to represent underflow
    } //if
    return stack->array[stack->top];
} //peek

// Function to print the stack
void printStack(Stack *stack) 
{
    if (isEmpty(stack)) {
        printf("\nStack is empty\n");
        return;
    } //isEmpty
    printf("\nStack contains:\n");
    for (int i = stack->top; i >= 0; i--) 
	{
        printf("%d\n", stack->array[i]);
    } //for
} //printStack

int main() 
{
    int allocationSize, maxLength;
    printf("Enter allocation size: ");
    scanf("%d", &allocationSize);

    Stack stack;
    stack.size = (allocationSize > 0) ? allocationSize : INITIAL_SIZE;
    stack.array = (int *)malloc(stack.size * sizeof(int));
    stack.top = -1;

    printf("Enter maximum length (-1 for unbounded): ");
    scanf("%d", &maxLength);

    // Test scenario
    int item;

    // 1. Push item 1 to stack.
    printf("\nPushing item 1: %s\n", (push(&stack, 1) ? "Success" : "Failed"));

    // 2. Push item 2 to stack.
    printf("Pushing item 2: %s\n", (push(&stack, 2) ? "Success" : "Failed"));

    // 3. Call peek and display the top item on the stack.
    printf("Top item on the stack: %d\n", peek(&stack));

    // 4. Push item 3 to stack.
    printf("Pushing item 3: %s\n", (push(&stack, 3) ? "Success" : "Failed"));

    // 5. Display the stack’s length.
    printf("Stack length: %d\n", stack.top + 1);

    // 6. Pop an item from the stack and display the item’s value.
    printf("\nPopped item: %d\n", pop(&stack));

    // 7. Call peek and display the top item on the stack.
    printf("Top item on the stack: %d\n", peek(&stack));

    // 8. Push item 4 to stack.
    printf("\nPushing item 4: %s\n", (push(&stack, 4) ? "Success" : "Failed"));

    // 9. Print the stack.
    printStack(&stack);

    // 10. Push item 5 to stack.
    printf("\nPushing item 5: %s\n", (push(&stack, 5) ? "Success" : "Failed"));

    // 11. Pop an item from the stack and display the item’s value.
    printf("Popped item: %d\n", pop(&stack));

    // 12. Push item 6 to stack.
    printf("Pushing item 6: %s\n", (push(&stack, 6) ? "Success" : "Failed"));

    // 13. Print the stack.
    printStack(&stack);

    // 14. Pop an item from the stack and display the item’s value.
    printf("\nPopped item: %d\n", pop(&stack));

    // 15. Call isEmpty to display if the stack is empty.
    printf("Is the stack empty? %s\n", (isEmpty(&stack) ? "Yes" : "No"));

    // 16. Pop an item from the stack and display the item’s value.
    printf("\nPopped item: %d\n", pop(&stack));

    // 17. Pop an item from the stack and display the item’s value.
    printf("Popped item: %d\n", pop(&stack));

    // 18. Pop an item from the stack and display the item’s value.
    printf("Popped item: %d\n", pop(&stack));

    // 19. Call isEmpty to display if the stack is empty.
    printf("Is the stack empty? %s\n", (isEmpty(&stack) ? "Yes" : "No"));

    // Free allocated memory
    free(stack.array);

    return 0;
} //main
