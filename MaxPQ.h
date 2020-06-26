class PriorityQueue {
    private:
			vector<int> v;
    public:
    	  int getSize()
          {
              return v.size();
          }
    		
    	  bool isEmpty()
          {
              return v.size()==0;
          }
    	  
          int getMax()
          {
              if(v.size()==0)
                  return INT_MIN;
              else
                  return v[0];
          }
    		
		  void insert(int element)
          {
              v.push_back(element);
              int index=v.size()-1;  
              while(index!=0)
              {
                  int parentIndex=(index-1)/2;
                  if(v[index]>v[parentIndex])
                  {
                      swap(v[index],v[parentIndex]);
                      index=parentIndex;
                  }
                  else
                      break;
              }
          }
        
          int removeMax()
          {
              if(v.size()==0)
           	      return INT_MIN;
              
            int ans=v[0];
            int index= v.size()-1;
            swap(v[0],v[index]);
            v.pop_back();
            index= v.size()-1;
            int PI=0;
            int CI1=2*PI+1;
            int CI2=2*PI+2;

            while(CI1<index)
            {
             int indexxx=0;
             int mini=max(v[CI1],v[CI2]);
             if(mini==v[CI1])
               indexxx=CI1;
             else
               indexxx=CI2;
             if(v[PI]<v[indexxx])
              {
               swap(v[PI],v[indexxx]);
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
              if(v[PI]<v[CI1])
               swap(v[PI],v[CI1]);
            }
            return ans;
           
          }
              
    
};