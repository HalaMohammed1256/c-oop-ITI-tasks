#include <iostream>
#include <string.h>

using namespace std;
///id name age salary commission deduction Setters And Getter  Print Function
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
    Employee emp;
    int iTemp;
    float Ftemp;

    do{
        cout<<"Please, enter the employee id: ";
        cin>>iTemp;
        emp.setId(iTemp);

        cout<<"Please, enter the employee name: ";
        cin>>cTemp;
        emp.setName(cTemp);

        cout<<"Please, enter the employee age: ";
        cin>>iTemp;
        emp.setAge(iTemp);

        cout<<"Please, enter the employee salary: ";
        cin>>Ftemp;
        emp.setSalary(Ftemp);

        cout<<"Please, enter the employee commission: ";
        cin>>Ftemp;
        emp.setCommission(Ftemp);

        cout<<"Please, enter the employee deduction: ";
        cin>>Ftemp;
        emp.setDeduction(Ftemp);

        cout<<"\n\nEmployee Details:\n";
        emp.printEmployee();

        cout<<"\nDo you want to redo the task? y|n:  ";
        cin>>redo;
        cout<<endl<<endl;

    }while(redo == 'y' || redo == 'Y');


    return 0;
}
