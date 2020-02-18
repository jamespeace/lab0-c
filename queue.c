#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    /* TODO: What if malloc returned NULL? */
    if (!q)
        return NULL;
    q->head = NULL;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* TODO: How about freeing the list elements and the strings? */
    /* Free queue structure */
    if (!q)
        return;
    if (q->head) {
        list_ele_t *current, *next;
        current = q->head;
        /* traverse through the lists. */
        while (current) {
            next = current->next;
            /* free array of value. */
            if (current->value) {
                free(current->value);
            }
            free(current);
            current = next;
        }
    }
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;
    char *p;
    size_t len;
    bool isHeadNull;

    isHeadNull = false;
    newh = malloc(sizeof(list_ele_t));
    if (!newh)
        return false;
    /* q is NULL */
    if (!q) {
        q = q_new();
        isHeadNull = true;
    }
    /* Allocate space for the string and copy it */
    len = strlen(s) + 1;    /* + 1 for '\0' */
    p = malloc(len);
    if (!p) {
        free(newh);
        if (isHeadNull)
            free(q);
        return false;
    }
    memcpy(p, s, len);
    newh->value = p;
    newh->next = q->head;
    q->head = newh;
    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    list_ele_t *newt;
    size_t     len;
    char       *p;

    if (!q)
        return false;
    newt = malloc(sizeof(list_ele_t));
    if (!newt)
        return false;

    len = strlen(s) + 1;
    p = malloc(len);
    if (!p) {
        free(newt);
        return false;
    }
    memcpy(p, s, len);
    newt->value = p;
    newt->next = NULL;
    q->tail = newt;
    return false;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* TODO: You need to fix up this code. */
    /* TODO: Remove the above comment when you are about to implement. */
    q->head = q->head->next;
    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    /* TODO: Remove the above comment when you are about to implement. */
    return 0;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
