// https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
struct Node
{
    int data;
    struct Node* next;
};
void MoveNode(struct Node** destRef, struct Node** sourceRef)
{
    /* the front source node  */
    struct Node* newNode = *sourceRef;
    assert(newNode != NULL);
    
    /* Advance the source pointer */
    *sourceRef = newNode->next;
    
    /* Link the old dest off the new node */
    newNode->next = *destRef;
    
    /* Move dest to point to the new node */
    *destRef = newNode;
}


struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    struct Node* result = NULL;
    
    /* point to the last result pointer */
    struct Node** lastPtrRef = &result;
    
    while(1)
    {
        if (a == NULL)
        {
            *lastPtrRef = b;
            break;
        }
        else if (b==NULL)
        {
            *lastPtrRef = a;
            break;
        }
        if(a->data <= b->data)
        {
            MoveNode(lastPtrRef, &a);
        }
        else
        {
            MoveNode(lastPtrRef, &b);
        }
        
        /* tricky: advance to point to the next ".next" field */
        lastPtrRef = &((*lastPtrRef)->next);
    }
    return(result);
}
