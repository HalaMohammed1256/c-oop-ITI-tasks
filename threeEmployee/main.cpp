#include <iostream>
#include <string.h>

using namespace std;

class Employee{
    private:
        int id;
        int age;
        char name[10];
        float salary;
        float commission;
        float deduction;

    public:
        /// id setter and getter
        void setId(int _id){
            id = _id;
        }
        int getId(){
            return id;
        }

        /// age setter and getter
        void setAge(int _age){
            age = _age;
        }
        int getAge(){
            return age;
        }

        /// name setter and getter
        void setName(char* _name){
            strcpy(name, _name);
        }
        char* getName(){
            return name;
        }

        /// salary setter and getter
        void setSalary(float _salary){
            salary = _salary;
        }
        float getSalary(){
            return salary;
        }

        /// commission setter and getter
        void setCommission(float _commission){
            commission = _commission;
        }
        float getCommision(){
            return commission;
        }

        /// deduction setter and getter
        void setDeduction(float _deduction){
            deduction = _deduction;
        }
        float getDeduction(){
            return deduction;
        }

        void printEmployee(){
            cout<<"ID: "<<id<<"\nName: "<<name<<"\nAge: "<<age<<"\nSalary: "<<salary<<"\nCommission: "<<commission<<"\nDeduction: "<<deduction<<endl;
        }


};

int main()
{
    char redo = 'y', cTemp[10];
    int employeeNumber,iTemp;
    float Ftemp;


    cout<<"How many employee do you want? ";
    cin>>employeeNumber;
    Employee emp[employeeNumber];

    do{
        for(int i = 0; i < employeeNumber; i++){
            cout<<"\nPlease, enter the employee "<<i+1<<" id: ";
            cin>>iTemp;
            emp[i].setId(iTemp);

            cout<<"Please, enter the employee "<<i+1<<" name: ";
            cin>>cTemp;
            emp[i].setName(cTemp);

            cout<<"Please, enter the employee "<<i+1<<" age: ";
            cin>>iTemp;
            emp[i].setAge(iTemp);

            cout<<"Please, enter the employee "<<i+1<<" salary: ";
            cin>>Ftemp;
            emp[i].setSalary(Ftemp);

            cout<<"Please, enter the employee "<<i+1<<" commission: ";
            cin>>Ftemp;
            emp[i].setCommission(Ftemp);

            cout<<"Please, enter the employee "<<i+1<<" deduction: ";
            cin>>Ftemp;
            emp[i].setDeduction(Ftemp);
        }

        cout<<"\n\nEmployees Details:\n\n";
        for(int i = 0; i < employeeNumber; i++){
            emp[i].printEmployee();
            cout<<endl;
        }

        cout<<"\nDo you want to redo the task? y|n:  ";
        cin>>redo;
        cout<<endl<<endl;

    }while(redo == 'y' || redo == 'Y');


    return 0;
}
