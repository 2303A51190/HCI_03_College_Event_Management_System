#include <stdio.h>
#include <stdlib.h>
typedef struct Node 
{
    char data;
    struct Node* next;
    struct Node* prev;
} Node;
Node* createNode(char data) 
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void insertNode(Node** head, char data) 
{
    Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    Node* lastNode = *head;
    while (lastNode->next) 
    {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode->prev = lastNode;
}
int isPalindrome(Node* head) 
{
    Node* start = head;
    Node* end = head;

    
    while (end->next)
    {
        end = end->next;
    }

    
    while (start != end && start->prev != end) 
    {
        if (start->data != end->data) 
        {
            return 0;  
        }
        start = start->next;
        end = end->prev;
    }

    return 1;  
}

int main() {
    int N;
    printf("Enter the length of the password: ");
    scanf("%d", &N);
    Node* head = NULL;
    printf("Enter the characters of the password:\n");
    for (int i = 0; i < N; i++)
    {
        char data;
        scanf(" %c", &data);  
        insertNode(&head, data);
    }
    if (isPalindrome(head)) 
    {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}