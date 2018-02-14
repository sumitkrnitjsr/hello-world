// https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

// Count the number of nodes in loop.

int detectAndRemoveLoop(struct Node *list)
{
    struct Node  *slow_p = list, *fast_p = list;
    
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        
        /* If slow_p and fast_p meet at some point then there
         is a loop */
        if (slow_p == fast_p)
        {
            removeLoop(slow_p, list);
            
            /* Return 1 to indicate that loop is found */
            return 1;
        }
    }
    
    /* Return 0 to indeciate that ther is no loop*/
    return 0;
}

/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop(struct Node *loop_node, struct Node *head)
{
    struct Node *ptr1 = loop_node;
    struct Node *ptr2 = loop_node;
    
    // Count the number of nodes in loop
    unsigned int k = 1, i;
    while (ptr1->next != ptr2)
    {
        ptr1 = ptr1->next;
        k++;
    }
    
    // Fix one pointer to head
    ptr1 = head;
    
    // And the other pointer to k nodes after head
    ptr2 = head;
    for (i = 0; i < k; i++)
        ptr2 = ptr2->next;
    
    /*  Move both pointers at the same pace,
     they will meet at loop starting node */
    while (ptr2 != ptr1)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    // Get pointer to the last node
    ptr2 = ptr2->next;
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;
    
    /* Set the next node of the loop ending node
     to fix the loop */
    ptr2->next = NULL;
}



//////////////////////////////////////////////////////


// if we start slow pointer from head and move both slow and fast pointers at same speed until fast don’t meet, they would meet at the beginning of the loop.

void detectAndRemoveLoop(Node *head)
{
    // If list is empty or has only one node
    // without loop
    if (head == NULL || head->next == NULL)
        return;
    
    Node *slow = head, *fast = head;
    
    // Move slow and fast 1 and 2 steps
    // ahead respectively.
    slow = slow->next;
    fast = fast->next->next;
    
    // Search for loop using slow and
    // fast pointers
    while (fast && fast->next)
    {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    /* If loop exists */
    if (slow == fast)
    {
        slow = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
    }
}

