#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

typedef struct __node {
    int value;
    struct __node *next;
} node_t;

void add_entry(node_t **head, int new_value)
{
    node_t **indirect = head;

    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = new_value;
    new_node->next = NULL;

    assert(new_node);
    while (*indirect)
        indirect = &(*indirect)->next;
    *indirect = new_node;
}

void print_list(node_t *head)
{
    for (node_t *current = head; current; current = current->next)
        printf("%d ", current->value);
    printf("\n");
}

void remove_entry(node_t **head, node_t *entry)
{
    node_t **indirect = head;

    while ((*indirect) != entry)
        indirect = &(*indirect)->next;

    *indirect = entry->next;
    free(entry);
}

void shuffle(node_t **head)
{
    //Initial Range
    int range = 0;
    node_t **indirect = head;
    while (*indirect) {
        range++;
        indirect = &(*indirect)->next;
    }

    srand(time(NULL));

    node_t *cursor = NULL;
    while (range)
    {
        //roll
        int roll = rand()%range;

        //strick out the number
        indirect = head;
        while(roll)
        {
            indirect = &(*indirect)->next;
            roll--;
        }
        
        add_entry(&cursor,(*indirect)->value);

        remove_entry(&(*head), *indirect);
        range--;
    }
    *head = cursor;
}

int main(int argc, char const *argv[])
{
    node_t *head = NULL;

    print_list(head);

    add_entry(&head, 72);
    add_entry(&head, 101);
    add_entry(&head, 108);
    add_entry(&head, 109);
    add_entry(&head, 110);
    add_entry(&head, 111);

    print_list(head);

    shuffle(&head);
    print_list(head);

    return 0;
}