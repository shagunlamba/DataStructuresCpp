class Polynomial {
    public:
    int *degCoeff;     
    int capacity;
    
    public:
    
    Polynomial(){
        
        degCoeff= new int[10];
        capacity=10;
        for(int i=0;i<10;i++)
            degCoeff[i]=0;
    }
    
    Polynomial(Polynomial const & P)
    {
        this->degCoeff = new int[P.capacity];
        for(int i=0;i<P.capacity;i++)
        {
            this->degCoeff[i]= P.degCoeff[i];
        }
        this->capacity= P.capacity;
    }
    
    Polynomial operator=(Polynomial const & P)
    {   
        delete [] degCoeff;
        this->degCoeff = new int[P.capacity];
        for(int i=0;i<P.capacity;i++)
        {
            this->degCoeff[i]= P.degCoeff[i];
        }
        this->capacity= P.capacity;
    }
    
    void setCoefficient(int index, int coeff)
    {
        if(index>=capacity){
            int size=2*capacity;
        while(size<=index)
        {
            size*=2;
        }
         int *newdegCoeff= new int[size];
         for(int i=0;i<size;i++)
             newdegCoeff[i]=0;
             for(int i=0;i<capacity;i++)
             newdegCoeff[i]=degCoeff[i];
            capacity=size;
            delete []degCoeff;
            degCoeff=newdegCoeff;
                 
        }
        degCoeff[index]=coeff;
    }
    
    Polynomial operator+(Polynomial const & P)
    { 
      Polynomial Pnew;
        int i=0,j=0;
        while(i<this->capacity && j<P.capacity)
        {
            int deg=i;
            int coeff=this->degCoeff[i]+P.degCoeff[j];
            Pnew.setCoefficient(deg,coeff);
            i++;
            j++;
        }
        while(i<capacity){
            Pnew.setCoefficient(i,degCoeff[i]);
            i++;
        }
        while(j<P.capacity){
            Pnew.setCoefficient(j,P.degCoeff[j]);
            j++;
        }
        return Pnew;
    }
    
    Polynomial operator-(Polynomial const & P)
    {
       Polynomial Pnew;
        int i=0,j=0;
        while(i<this->capacity && j<P.capacity)
        {
            int deg=i;
            int coeff=this->degCoeff[i]-P.degCoeff[j];
            Pnew.setCoefficient(deg,coeff);
            i++;
            j++;
        }
        while(i<capacity){
            Pnew.setCoefficient(i,degCoeff[i]);
            i++;
        }
        while(j<P.capacity){
            Pnew.setCoefficient(j,(-1*P.degCoeff[j]));
            j++;
        }
        return Pnew;
    }
        
         Polynomial operator*(Polynomial const & P)
         {
             Polynomial Pnew;
             for(int i=0;i<P.capacity;i++)
             {
                 for(int j=0;j<capacity;j++)
                 {
                     int deg=i+j;
                     // int coeff= Pnew.getCoefficient(deg) + (this->degCoeff[i]*P.degCoeff[j]);
                     int coeff= Pnew.getCoefficient(deg) + (this->degCoeff[j]*P.degCoeff[i]);
                     Pnew.setCoefficient(deg,coeff);
                 }
             }
            return Pnew; 
         }
        
    
    int getCoefficient(int degree)
    {
        if(degree>=capacity)
            return 0;
       
            return degCoeff[degree];
    }
    
    void print()
    {
        for(int i=0;i<capacity;i++)
        {   if(degCoeff[i]!=0)
            cout<<degCoeff[i]<<"x"<<i<<" ";
        }
        cout<<endl;
    }
    
};