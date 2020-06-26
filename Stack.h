template <typename T>
class Stack {
    Node<T> *head;
    int size;
    
    public :
    
    Stack() {
         head= NULL;
         size=0;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    void push(T element) {
        Node<T> *newNode = new Node<T>(element);
        if(head== NULL)
        {
            head=newNode;
        }
        else
        {
            newNode->next=head;
            head=newNode;
        }
        size++;
    }
    
    T pop() {
        if(head==NULL)
            return 0;
        else
        {
            T ans=head->data;
            head=head->next;
            size--;
           return ans;
        }
        
    }
    
    T top() {
        if(head==NULL)
            return 0;
        else
            return head->data;
    }
    
 
};