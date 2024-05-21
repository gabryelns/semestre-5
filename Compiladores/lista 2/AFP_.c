#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node Node;
struct Node
{
    char value;
    Node *next;
};

typedef struct Stack Stack;
struct Stack
{
    Node *top;
};

Stack *create_stack()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

Node *create_node(char value)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void push(Stack *stack, char value)
{
    Node *new_node = create_node(value);
    new_node->next = stack->top;
    stack->top = new_node;
}

Node *pop(Stack *stack)
{
    if (stack->top == NULL) return NULL;
    Node *temp = stack->top;
    stack->top = stack->top->next;
    return temp;
}

int is_empty(Stack *stack)
{
    return stack->top == NULL;
}

int main()
{
    char input[1000];
    int length = 0;
    Stack *stack = create_stack(); 

    while (scanf("%s", input) != EOF)
    {
        length = strlen(input);
        for (int i = 0; i < length; i++)
        {
            if (is_empty(stack))
            {
                push(stack, input[i]);
                printf("%c\n", toupper(input[i]));
            }
            else if (input[i] != stack->top->value)
            {
                pop(stack);
                if (is_empty(stack))
                {
                    printf("nil\n");
                }
                else
                {
                    Node *temp = stack->top;
                    while (temp != NULL)
                    {
                        printf("%c", toupper(temp->value));
                        temp = temp->next;
                    }
                    printf("\n");
                }
            }
            else
            {
                push(stack, input[i]);
                Node *temp = stack->top;
                while (temp != NULL)
                {
                    printf("%c", toupper(temp->value));
                    temp = temp->next;
                }
                printf("\n");
            }
        }

        if (is_empty(stack))
            printf("Aceito\n\n");
        else
            printf("Rejeito\n\n");
        
        stack->top = NULL;
    }
    return 0;
}
