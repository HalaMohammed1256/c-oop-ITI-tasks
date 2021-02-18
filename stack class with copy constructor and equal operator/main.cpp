#include <iostream>

using namespace std;



class Stack
{
    /// private fields
    private:
    int *arr;
    int arrSize;
    int tos;

    static int counter;

    /// public fields
    public:
    static int getCounter()
    {
        return counter;
    }

    int getTos()const
    {
        return tos;
    }
    int * getArr() const
    {
        return arr;
    }

    /// constructors
    Stack()
    {
        counter++;
        cout<<"constructor"<<endl;
        tos = 0;
        arrSize = 5;
        arr = new int[arrSize];
    }
    Stack(int _size)
    {
        counter++;
        cout<<"constructor"<<endl;
        tos = 0;
        arrSize = _size;
        arr = new int[arrSize];
    }

    /// copy constructor
    Stack(const Stack &old){
        cout<<"copy constructor"<<endl;
        this->arrSize=old.arrSize;
        this->tos=old.tos;
        this->arr=new int [arrSize];
        for(int i=0;i<tos;i++)
        {
            arr[i]=old.arr[i];
        }
    }

    /// destructor
    ~Stack()
    {
        counter--;
        for(int i = 0; i< arrSize;i++)
        {
            arr[i]=-1;
        }

        delete [] arr;
        cout<<"\ndestructor"<<endl;
    }

    ///Conditioning
    int isFull()
    {
        return tos == arrSize;
    }
    int isEmpty()
    {
        return tos == 0;
    }

    /// push
    void push(int val)
    {
        if(!isFull())
        {
            arr[tos] = val;
            tos++;
        }
        else
        {
            cout<<"the stack is full"<<endl;
        }
    }

    /// pop
    int pop()
    {
        int retVal=-12121;
        if(!isEmpty())
        {
            tos--;
            retVal=arr[tos];
        }
        else
        {
            cout<<"the stack is empty"<<endl;
        }
        return retVal;
    }

    /// equal operator s1 = s2 => s1.operator(s2)
    Stack& operator=(const Stack& righ){
        delete [] this->arr;
        this->tos = righ.tos;
        this->arrSize = righ.arrSize;
        this->arr = new int[arrSize];

        for(int i = 0; i < tos; i++){
            this->arr[i] = righ.arr[i];
        }

        return *this;
    }

    /// friend function
    friend void printStack(const Stack& param);
};
int Stack::counter=0;



/// pass by value => copy constructor
void printStackV(Stack param)
{
    int *ptr=param.getArr();
    for(int i=0;i<param.getTos();i++)
    {
        cout<<ptr[i]<<" ";
    }
}

int main()
{

    Stack s1, s2(10);

    int val, objNumber, j = 0;
    char redo = 'y', question;


    do{
        cout<<"! first stack size = 5 & second stack size = 10\n\n";

        for(int i = 0; i < 5; i++){
            cout<<"please enter the first stack value at index "<<i+1<<":  ";
            cin>>val;
            s1.push(val);
        }
        cout<<"\n";

        for(int i = 0; i < 10; i++){
            cout<<"please enter the second stack value at index "<<i+1<<":  ";
            cin>>val;
            s2.push(val);
        }

        cout<<"\n\nBefore equal:\n\nfirst stack: \n";
        printStackV(s1);
        cout<<"\nsecond stack: \n";
        printStackV(s2);


        s1 = s2;
        cout<<"\n\nAfter equal => where first stack = second stack\n\nfirst stack after: \n";
        printStackV(s1);
        cout<<"\nsecond stack: \n";
        printStackV(s2);



        cout<<"\n\nDo you want to redo the task? y|n: ";
        cin>>redo;
        cout<<"\n\n";


    }while(redo == 'y' || redo == 'Y');

    return 0;
}
