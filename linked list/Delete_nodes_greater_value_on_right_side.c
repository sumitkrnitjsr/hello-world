// https://www.geeksforgeeks.org/delete-nodes-which-have-a-greater-value-on-right-side/

void delLesserNodes(struct Node **head_ref)
{
    /* 1) Reverse the linked list */
    reverseList(head_ref);
    
    /* 2) In the reversed list, delete nodes which have a node
     with greater value node on left side. Note that head
     node is never deleted because it is the leftmost node.*/
    _delLesserNodes(*head_ref);
    
    /* 3) Reverse the linked list again to retain the
     original order */
    reverseList(head_ref);
}

/* Deletes nodes which have greater value node(s) on left side */
void _delLesserNodes(struct Node *head)
{
    struct Node *current = head;
    
    /* Initialize max */
    struct Node *maxnode = head;
    struct Node *temp;
    
    while (current != NULL && current->next != NULL)
    {
        /* If current is smaller than max, then delete current */
        if(current->next->data < maxnode->data)
        {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        
        /* If current is greater than max, then update max and
         move current */
        else
        {
            current = current->next;
            maxnode = current;
        }
    }
}
