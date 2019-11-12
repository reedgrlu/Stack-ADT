
#include "Stack.h"

#include <cstddef>

using namespace std;

//    class StackNode {
//             public:
//                 int data;
//                 StackNode * next;
//         };
    
    // private:
    //     StackNode * head;
    //     StackNode * tail;


 // Desc:  Constructor
        // Post:  Stack is empty
        Stack::Stack(){

            //initialize head and tail pointers to NULL
            head = NULL;
            tail = NULL;
        };


        // Desc:  destructor
        // Post:  
        Stack::~Stack(){

        };


        // Desc:  Insert element x to the top of the stack.
        // Post:  
        void Stack::push(int x){

            StackNode * newnode = new StackNode;    //create new dynamic variable pointer
            newnode->data = x;  //give it the value of x
	        newnode->next = NULL;   //this node points to NULL, as it will be the new tail
           

	        if(head == NULL){
		        // empty list
                head = newnode;      
	        }else{
                tail->next = newnode;   //the old tail points to new node
            };
            
            tail = newnode;     //new node becomes new tail
        };


        // Desc:  Remove and return element at the top of the stack.
        //  Pre:  stack not empty
        // Post:  return tail element, assign new tail
        int Stack::pop(){
            StackNode * curr = new StackNode;  //create current pointer to cycle through stack
            StackNode * oldTail = new StackNode;    //create pointer oldTail

            oldTail = tail;     //assign oldtail to point to current tail
            curr = head;    //initialize curr to point to head element

            //if empty stack
            if(isEmpty()){
                return 0;
            };

            //if only one element in stack, return it and assign tail and head to point to NULL
            if(head == tail){
                tail = NULL;
                head = NULL;
                return oldTail->data;
            };


            //cycle through stack to find the second last element in the stack
            while(curr->next != tail){
                curr = curr->next;
            };

            //the second last element is now the new tail, and therefore points to NULL
            curr->next = NULL;
            tail = curr;
            
            return oldTail->data;
        };


        // Desc:  Return the topmost element of the stack.
        //  Pre:  stack not empty
        // Post:  return tail element
        int Stack::peek() const{
            if(isEmpty()){
                return 0;
            };


            return tail->data;
        
            
        };



        // Desc:  
        // Post:  
        bool Stack::isEmpty() const{
            return head == NULL;
        };
