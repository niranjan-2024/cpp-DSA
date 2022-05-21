Node* partition(Node *l, Node *h){
    int x = h->data;
    Node *i = l->prev;
    for (Node *j = l; j != h; j = j->next)
    {
        if (j->data <= x)
        {
            i = (i == NULL)? l : i->next;
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL)? l : i->next; 
    swap(&(i->data), &(h->data));
    return i;
}
