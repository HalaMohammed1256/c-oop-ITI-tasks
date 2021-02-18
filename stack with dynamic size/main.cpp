#include <iostream>

using namespace std;

template <class Type>
class Stack{
    private:
        int capacity;
        int topStack;
        Type *ptr;

    public:
        /// constructor
        Stack(){
            capacity = 5;
            topStack = 0;
            ptr = new Type[capacity];
        }

        /// destructor
        ~Stack(){
            delete [] ptr;
        }

        /// stack function
        /// return the value at the top of stack
        Type top(){
            return ptr[topStack - 1];
        }

        /// to check if stack empty or not
        bool isEmpty(){
            return topStack == 0;
        }

        /// return size of the stack
        int stackSize(){
            return capacity;
        }

        /// to add value to the stack
        void push(Type value){
            if(topStack != capacity){
                ptr[topStack] = value;
                topStack++;
            }
            else{
                int oldSize = capacity;
                capacity += 5;
                Type *temp = ptr;
                ptr = new Type[capacity];
                for(int i = 0; i < capacity; i++){
                    ptr[i] = temp[i];
                }
                delete [] temp;
                ptr[topStack] = value;
                topStack++;
            }
        }

        /// to remove last value from stack
        void pop(){
            if(!isEmpty()){
                topStack--;
            }
            else{
                cout<<"the stack is empty"<<endl;
            }
        }

        /// fully remove stack
        void removeStack(){
            topStack = 0;
            capacity = 0;
            ptr = NULL;
        }

        /// print stack
        void printStack(){
            for(int i = topStack - 1; i > 0; i--){
                    cout<<ptr[i]<<" ";
            }
            cout<<endl;
        }

};



int main()
{
    Stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    stk.push(60);
    stk.push(70);
    stk.push(80);
    stk.push(90);
    stk.push(100);

    cout<<"stack before pop:\n";
    stk.printStack();

    stk.pop();
    stk.pop();
    stk.pop();

    cout<<"\nstack after 3 pop:\n";
    stk.printStack();

    cout<<"\ntop value in stack:\n"<<stk.top();

    cout<<"\n\nstack size before push more values:\n"<<stk.stackSize();

    stk.push(360);
    stk.push(400);
    stk.push(68);
    stk.push(460);
    stk.push(98);

    cout<<"\n\nstack after 5 push:\n";
    stk.printStack();

    cout<<"\n\nstack size before push more values:\n"<<stk.stackSize();

    stk.removeStack();
    cout<<"\n\nstack after remove:\n";
    stk.printStack();









    return 0;
}
