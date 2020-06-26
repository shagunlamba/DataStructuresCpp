template<typename T>
class Queue {
    Node<T>*head;
    Node<T>*tail;
    int size;
    
    public :
    Queue() {
        head=NULL;
        tail=NULL;
        size=0;
    }
    
    void enqueue(T data) {
       
        Node<T> *newNode = new Node<T>(data);
        if(head==NULL)
        {
        
         head=newNode;
         tail=newNode;
         size++;
        }
        else
        {   tail->next=newNode;
            tail=newNode;
            size++;
        }
        
        
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    T dequeue() {
       if(head==NULL)
       {
           return 0;
       }
        else 
        {
            T ans=head->data;
            head=head->next;
            size--;
            return ans;
            
        }
        // Returns 0 if queue is empty
    }
    
    T front()  {
        if(head==NULL)
            return 0;
        // Returns 0 if queue is empty
            else
            {
                return head->data;
            }
    }
};
