// https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/

/*
 split the linked list into two: one containing all even nodes and other containing all odd nodes. And finally attach the odd node linked list after the even node linked list.
 */

public void segregateEvenOdd() {
    
    Node evenStart = null;
    Node evenEnd = null;
    Node oddStart = null;
    Node oddEnd = null;
    Node currentNode = head;
    
    while(currentNode != null) {
        int element = currentNode.data;
        
        if(element % 2 == 0) {
            
            if(evenStart == null) {
                evenStart = currentNode;
                evenEnd = evenStart;
            } else {
                evenEnd.next = currentNode;
                evenEnd = evenEnd.next;
            }
            
        } else {
            
            if(oddStart == null) {
                oddStart = currentNode;
                oddEnd = oddStart;
            } else {
                oddEnd.next = currentNode;
                oddEnd = oddEnd.next;
            }
        }
        // Move head pointer one step in forward direction
        currentNode = currentNode.next;
    }
    
    
    if(oddStart == null || evenStart == null) {
        return;
    }
    
    evenEnd.next = oddStart;
    oddEnd.next = null;
    head=evenStart;
}



/*
The idea is to get pointer to the last node of list. And then traverse the list starting from the head node and move the odd valued nodes from their current position to end of the list.

*/

void segregateEvenOdd(struct Node **head_ref)
{
    struct Node *end = *head_ref;
    struct Node *prev = NULL;
    struct Node *curr = *head_ref;
    
    /* Get pointer to the last node */
    while (end->next != NULL)
        end = end->next;
    
    struct Node *new_end = end;
    
    /* Consider all odd nodes before the first even node
     and move then after end */
    while (curr->data %2 != 0 && curr != end)
    {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }
    
    // 10->8->17->17->15
    /* Do following steps only if there is any even node */
    if (curr->data%2 == 0)
    {
        /* Change the head pointer to point to first even node */
        *head_ref = curr;
        
        /* now current points to the first even node */
        while (curr != end)
        {
            if ( (curr->data)%2 == 0 )
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                /* break the link between prev and current */
                prev->next = curr->next;
                
                /* Make next of curr as NULL  */
                curr->next = NULL;
                
                /* Move curr to end */
                new_end->next = curr;
                
                /* make curr as new end of list */
                new_end = curr;
                
                /* Update current pointer to next of the moved node */
                curr = prev->next;
            }
        }
    }
    
    /* We must have prev set before executing lines following this
     statement */
    else prev = curr;
    
    /* If there are more than 1 odd nodes and end of original list is
     odd then move this node to end to maintain same order of odd
     numbers in modified list */
    if (new_end!=end && (end->data)%2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
    return;
}
