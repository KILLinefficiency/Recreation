#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

int len(struct Node* current) {
    int count = 0;
    while(current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int get_item(struct Node* current, int index) {
    int current_index = 0;
    while(current != NULL) {
        if(current_index == index) {
            return current->data;
        }
        current_index++;
        current = current->next;
    }
    return -1;
}

void print_linked_list(struct Node* current) {
    printf("[ ");
    while(current != NULL) {
        printf("%d, ", current->data);
        current = current->next;
    }
    printf("]\n");
};

int main() {
    struct Node x, y, z;

    x.data = 19;
    x.next = &y;

    y.data = 29;
    y.next = &z;

    z.data = 39;
    z.next = NULL;

    printf("The first element: %d\n", get_item(&x, 0));
    printf("The third element: %d\n", get_item(&x, 2));
    printf("The entire Linked List: ");
    print_linked_list(&x);
    printf("The length of the Linked List is: %d\n", len(&x));

    return 0;
}