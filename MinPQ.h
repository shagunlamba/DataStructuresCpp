class PriorityQueue {
    vector<int> pq;
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
    int removeMin() 
    {
        int ans=pq[0];
            int index= pq.size()-1;
            swap(pq[0],pq[index]);
            pq.pop_back();
            index= pq.size()-1;
            int PI=0;
            int CI1=2*PI+1;
            int CI2=2*PI+2;

            while(CI1<index)
            {
             int indexxx=0;
             int mini=min(pq[CI1],pq[CI2]);
             if(mini==pq[CI1])
               indexxx=CI1;
             else
               indexxx=CI2;
             if(pq[PI]>pq[indexxx])
              {
               swap(pq[PI],pq[indexxx]);
               PI=indexxx;
               CI1=2*PI+1;
               CI2=2*PI+2;
              }
             else 
              {
                break;
              }
            }
            if(CI1==index)
            { 
              int indexxx=0;
              if(pq[PI]>pq[CI1])
               swap(pq[PI],pq[CI1]);
            }
            return ans;
          
    }
    
    
};