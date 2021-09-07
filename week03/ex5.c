#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
    struct node* previous;
} node;

typedef struct doubly_linked_list {
    node *head;
    node* tail;
} doubly_linked_list;

doubly_linked_list list;

void insert_node(int a) {
    if (list.head == NULL) {
        list.head = (node*)malloc(sizeof(node));
        list.head->next = NULL;
        list.head->previous = NULL;
        list.head->value = a;
        list.tail = list.head;
    } else {
        list.tail->next = (node*)malloc(sizeof(node));
        list.tail->next->previous = list.tail;
        list.tail->next->next = NULL;
        list.tail->next->value = a;
        list.tail = list.tail->next;
    }
}

void delete_node(int a) {
    if (list.head->value == a) {
        node *temp = list.head;
        list.head = list.head->next;
        free(temp);
    } else if (list.tail->value == a) {
        node *temp = list.tail;
        list.tail = list.tail->previous;
        list.tail->next = NULL;
        free(temp);
    } else {
        node *p = list.head;
        while (p->next != NULL) {
            if (p->next->value == a) {
                node *temp = p->next;
                p->next = p->next->next;
                p->next->previous = p;
                free(temp);
                break;
            }
            p = p->next;
        }
    }
}

void print_list() {
    node *p = list.head;
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

int main() {
    list.head = NULL;
    list.tail = NULL;
    int n;
    while (1) {
        printf("Enter 0 to add number\n");
        printf("Enter 1 to show list\n");
        printf("Enter 2 to delete number\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &n);
        switch (n) {
            case 0:
                printf("Enter number to add\n");
                scanf("%d", &n);
                insert_node(n);
                system("clear");
                break;
            case 1:
                print_list();
                break;
            case 2:
                printf("Enter number to delete\n");
                scanf("%d", &n);
                delete_node(n);
                system("clear");
                break;
            case 3:
                return 0;
        }
    }
    return 0;
}
