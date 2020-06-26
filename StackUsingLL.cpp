#include<iostream>
using namespace std;


template <typename T>
class Node {
    public :
    T data;
    Node<T> *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};

#include "Stack.h"
    int main() {
        
        Stack<int> st;
        
        int choice;
        cin >> choice;
        int input;
        
        while (choice !=-1) {
            if(choice == 1) 
            {
                cin >> input;
                st.push(input);
            }
            else if(choice == 2) 
            {
                int ans = st.pop();
                if(ans != 0) {
                    cout << ans << endl;
                }
                else {
                    cout << "-1" << endl;
                }
            }
            else if(choice == 3) 
            {
                int ans = st.top();
                if(ans != 0) {
                    cout << ans << endl;
                }
                else {
                    cout << "-1" << endl;
                }
            }
            else if(choice == 4) 
            {
                cout << st.getSize() << endl;
            }
            else if(choice == 5) 
            {
		        if(st.isEmpty()){
                	cout << "true" << endl;
		    }
            else
			  cout << "false" << endl;
            }
            cin >> choice;
        }
    
    }