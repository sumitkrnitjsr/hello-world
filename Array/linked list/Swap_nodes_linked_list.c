// https://www.geeksforgeeks.org/swap-nodes-in-a-linked-list-without-swapping-data/

void swapNodes(struct Node **head_ref, int x, int y)
{
    // Nothing to do if x and y are same
    if (x == y) return;
    
    // Search for x (keep track of prevX and CurrX
    struct Node *prevX = NULL, *currX = *head_ref;
    while (currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }
    
    // Search for y (keep track of prevY and CurrY
    struct Node *prevY = NULL, *currY = *head_ref;
    while (currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }
    
    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL)
        return;
    
    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        *head_ref = currY;
    
    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else  // Else make x as new head
        *head_ref = currX;
    
    // Swap next pointers
    struct Node *temp = currY->next;
    currY->next = currX->next;
    currX->next  = temp;
}
