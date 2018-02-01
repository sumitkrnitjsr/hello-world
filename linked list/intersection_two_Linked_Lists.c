// https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/

int getIntesectionNode(struct Node* head1, struct Node* head2)
{
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;
    
    if(c1 > c2)
    {
        d = c1 - c2;
        return _getIntesectionNode(d, head1, head2);
    }
    else
    {
        d = c2 - c1;
        return _getIntesectionNode(d, head2, head1);
    }
}

/* function to get the intersection point of two linked
 lists head1 and head2 where head1 has d more nodes than
 head2 */
int _getIntesectionNode(int d, struct Node* head1, struct Node* head2)
{
    int i;
    struct Node* current1 = head1;
    struct Node* current2 = head2;
    
    for(i = 0; i < d; i++)
    {
        if(current1 == NULL)
        {  return -1; }
        current1 = current1->next;
    }
    
    while(current1 !=  NULL && current2 != NULL)
    {
        if(current1 == current2)
            return current1->data;
        current1= current1->next;
        current2= current2->next;
    }
    
    return -1;
}
