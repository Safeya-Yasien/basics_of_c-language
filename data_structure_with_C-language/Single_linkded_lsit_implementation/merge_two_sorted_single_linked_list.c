SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
    if (head1 == NULL)
        return (head2);
    if (head2 == NULL)
        return (head1);
    
    SinglyLinkedListNode *new_head = NULL;
    
    if (head1->data <= head2->data)
    {
        new_head = head1;
        head1 = head1->next;
    }
    else
    {
        new_head = head2;
        head2 = head2->next;
    }
    
    SinglyLinkedListNode *temp_head = new_head;
    
    while (head1 != NULL && head2 != NULL)
    {
        SinglyLinkedListNode *temp = NULL;
        
        if (head1->data <= head2->data)
        {
            temp = head1;
            head1 = head1->next;
        }
        else
        {
            temp = head2;
            head2 = head2->next;
        }
        
        temp_head->next = temp;
        temp_head = temp;
    }
    
    if (head1 != NULL)
        temp_head->next = head1;
    else if (head2 != NULL)
        temp_head->next = head2;
    
    return (new_head);
    
}

