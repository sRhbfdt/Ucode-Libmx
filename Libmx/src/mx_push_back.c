#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    if (!*list) {
        *list = mx_create_node(data);
        return;
    }
    t_list *temp = mx_create_node(data);
    temp->next = NULL;
    temp->next = data;

    t_list *curr = *list;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
}

