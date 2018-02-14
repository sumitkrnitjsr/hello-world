// https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/

int detectloop(struct Node *list)
{
    struct Node  *slow_p = list, *fast_p = list;
    
    while (slow_p && fast_p && fast_p->next )
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
            printf("Found Loop");
            return 1;
        }
    }
    return 0;
}
