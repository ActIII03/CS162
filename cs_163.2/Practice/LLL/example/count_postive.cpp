int count_positive(){    if(!head)        return 0;    int count = count_positive(head->next);    if(head -> data % 2 == 0)        ++count;    return count;}
