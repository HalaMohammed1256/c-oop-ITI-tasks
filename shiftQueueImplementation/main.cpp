#include <iostream>

using namespace std;

template <class Type>
class Queue{
    private:
        int capacity;
        int backIndex;
        int frontIndex;
        Type *ptr;

    public:
        /// constructor
        Queue(){
            capacity = 5;
            backIndex = 0;
            frontIndex = 0;
            ptr = new Type[capacity];
        }

        /// destructor
        ~Queue(){
            delete [] ptr;
        }

        /// Queue function
        /// return the value at the front of queue
        Type Front(){
            return ptr[frontIndex];
        }

        /// return the value at the back of queue
        Type Back(){
            return ptr[backIndex - 1];
        }

        /// to check if queue empty or not
        bool isEmpty(){
            return backIndex == 0;
        }

        /// return size of the queue
        int queueSize(){
            return capacity;
        }

        /// to add value to the stack
        void enqueue(Type value){
            if(backIndex != capacity){
                ptr[backIndex] = value;
                backIndex++;
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
                ptr[backIndex] = value;
                backIndex++;
            }
        }

        /// to remove last value from stack
        void dequeue(){
            if(!isEmpty()){
                for(int i = 0; i < backIndex - 1; i++){
                    ptr[i] = ptr[i+1];
                }
                backIndex--;
            }
            else{
                cout<<"the stack is empty"<<endl;
            }
        }

        /// fully remove stack
        void removeQueue(){
            backIndex = 0;
            capacity = 0;
            ptr = NULL;
        }

        /// print stack
        void printQueue(){
            for(int i = 0; i < backIndex; i++){
                    cout<<ptr[i]<<" ";
            }
            cout<<endl;
        }

};



int main()
{

    Queue<int> qu;

    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.enqueue(40);
    qu.enqueue(50);
    qu.enqueue(60);
    qu.enqueue(70);
    qu.enqueue(80);
    qu.enqueue(90);
    qu.enqueue(100);

    cout<<"queue before dequeue:\n";
    qu.printQueue();

    qu.dequeue();
    qu.dequeue();
    qu.dequeue();

    cout<<"\nqueue after 3 dequeue:\n";
    qu.printQueue();

    cout<<"\nfront value in queue:\n"<<qu.Front();
    cout<<"\n\nback value in queue:\n"<<qu.Back();

    cout<<"\n\nqueue size before enqueue more values:\n"<<qu.queueSize();

    qu.enqueue(360);
    qu.enqueue(400);
    qu.enqueue(68);
    qu.enqueue(460);
    qu.enqueue(98);
    cout<<"\n\nqueue size before enqueue more values:\n"<<qu.queueSize();

    qu.removeQueue();
    cout<<"\n\nqueue after remove:\n";
    qu.printQueue();
























    return 0;
}
