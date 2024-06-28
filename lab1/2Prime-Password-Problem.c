#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int data;
    struct node *next;
};

// Function to find prime factors and return the linked list of factors
struct node *primeFactor(int num) {
    struct node *head = NULL, *new_node, *tmp = NULL;

    // Find even factors
    while (num % 2 == 0) {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = 2;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            tmp = head;
        } else {
            tmp->next = new_node;
            tmp = tmp->next;
        }
        num /= 2;
    }

    // Find odd factors
    for (int i = 3; i <= sqrt(num); i += 2) {
        while (num % i == 0) {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = i;
            new_node->next = NULL;
            if (head == NULL) {
                head = new_node;
                tmp = head;
            } else {
                tmp->next = new_node;
                tmp = tmp->next;
            }
            num /= i;
        }
    }

    // If num is still greater than 2, it must be prime
    if (num > 2) {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            tmp = head;
        } else {
            tmp->next = new_node;
            tmp = tmp->next;
        }
    }

    return head;
}

// Function to print the linked list
void print_list(struct node *head) {
    struct node *tmp;
    for (tmp = head; tmp; tmp = tmp->next) {
        printf("%d\n", tmp->data);
    }
}

void print_list2(struct node *head) {
    struct node *tmp = head;
    int count = 1;
    int first = 1;

    while (tmp != NULL) {
        if (tmp->next != NULL && tmp->data == tmp->next->data) {
            count++;
        } else {
            if (!first) {
                printf(" x ");
            }
            if (count > 1) {
                printf("%d^%d", tmp->data, count);
            } else {
                printf("%d", tmp->data);
            }
            count = 1;
            first = 0;
        }
        tmp = tmp->next;
    }
    printf("\n");
}

// Function to free the linked list
void free_list(struct node *head) {
    struct node *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    struct node *head;
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    head = primeFactor(number); // Correctly assign the returned head

    printf("%d = ", number);
    print_list2(head); // Print the prime factors

    free_list(head); // Free the allocated memory

    return 0;
}
