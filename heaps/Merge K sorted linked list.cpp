class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data > b->data;
    }
};

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
         priority_queue<Node* ,vector<Node*>,compare> min_heap;
         
         if(K==0){
             return NULL;
         }
         for(int i=0;i<K;i++){
             if(arr[i]!=NULL){
                 min_heap.push(arr[i]);
             }
         }
         
         Node* head = NULL;
         Node* tail = NULL;
         
         while(min_heap.size()>0){
             Node* top = min_heap.top();
             min_heap.pop();
             
             if(top->next!=NULL){
                     min_heap.push(top->next);
                 }
             
             if(head == NULL){
                 head = top;
                 tail = top;
             }
             else{
                 tail->next = top;
                 tail = top;
             }
         }
         return head;
    }
};
