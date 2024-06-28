#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int data;
    struct node *next;
};


struct node *primeFactor(int num){
    struct node *head = NULL, *new_node, *tmp = NULL;
    //find even factor
    while (num%2 == 0)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = 2;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            tmp = head;  // Initialize the tmp pointer to head
        } else {
            tmp->next = new_node;  // Link the new node to the last node in the list
            tmp = tmp->next;       // Move the tmp pointer to the new node
        }
        printf("2 %d\n",num);
        num /= 2;
    }
    //find odd factor
    for (int i=3; i <= sqrt(num); i = i+2){
        while (num%i == 0)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = i;
            new_node->next = NULL;
            if (head == NULL) {
                head = new_node;
                tmp = head;  // Initialize the tmp pointer to head
            } else {
                tmp->next = new_node;  // Link the new node to the last node in the list
                tmp = tmp->next;       // Move the tmp pointer to the new node
            }
            printf("-%d", i);
            printf("%d %d\n", i,num);
            num /= i;
        }
    }
    //return reamain (case1:cant divide by any number so it is prime ) (case2: sqrt(remain from last num/=2) < 3  )
    if (num > 2) {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            tmp = head;  // Initialize the tmp pointer to head
        } else {
            tmp->next = new_node;  // Link the new node to the last node in the list
            tmp = tmp->next;       // Move the tmp pointer to the new node
        }
        printf("%d", num);
    }
    return head;    
}

int main(){
    struct node *head, *tmp;
    int number;
    printf("enter: ");
    scanf("%d", &number);
    primeFactor(number);
    for (tmp = head; tmp; tmp = tmp->next)
        printf("%d\n", tmp->data);
}