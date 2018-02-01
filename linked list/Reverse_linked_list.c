// https://www.geeksforgeeks.org/reverse-a-linked-list/

// This function mainly calls reverseUtil()
// with prev as NULL
void reverse(Node **head)
{
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}

// A simple and tail recursive function to reverse
// a linked list.  prev is passed as NULL initially.
void reverseUtil(Node *curr, Node *prev, Node **head)
{
    /* If last node mark it head*/
    if (!curr->next)
    {
        *head = curr;
        
        /* Update next to prev node */
        curr->next = prev;
        return;
    }
    
    /* Save curr->next node for recursive call */
    node *next = curr->next;
    
    /* and update next ..*/
    curr->next = prev;
    
    reverseUtil(next, curr, head);
}



static void reverse(struct Node** head_ref)
{
    struct Node* prev   = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
