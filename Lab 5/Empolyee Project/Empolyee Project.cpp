#include <iostream>
#include<string>
using namespace std; 


class Employee  
{
protected : 
    string name; 
    int rank; 
    int tasksassigned; 

public : 
    Employee(string n, int r, int t ) : name(n) , rank(r) , tasksassigned(t)
    {

    }

    void IncreaseTasksAssigned()
    {
        tasksassigned++; 
    }

    void IncreaseRank()
    {
        rank++; 
    }

    int getrank() const
    {
        return rank; 
    }


    int gettasks() const
    {
        return tasksassigned;
    }

    virtual int Compare(Employee * e)
    {
        if (rank > e->getrank())
        {
            return 1;
        }
        else if (rank < e->getrank())
        {
            return -1;
        }
        else
            return 0; 
    }
   

    virtual void print() = 0; 

    virtual void AssignTask(Employee*) = 0; 


}; 

class DepEmp : public Employee
{
public:

    DepEmp(string n = "", int r = 0, int t = 0) : Employee(n, r, t)
    { }


    virtual void print()
    {
        cout << "Type is DepEmp" << endl;
        cout << "Name is " << name << endl;
        cout << "Rank is " << rank << endl;
        cout << "No. of Tasks assigned is " << tasksassigned << endl;
    }

    virtual void AssignTask(Employee* E)
    {
        if (dynamic_cast<Manager*>(E))
        {
            cout << "invalid" << endl;
        }
        else if (dynamic_cast<DepEmp*>(E))
        {
            if (rank > E->getrank())
            {
                E->IncreaseTasksAssigned();
            }
            else
                cout << "invalid" << endl;
        }
    }

};

class Manager : public Employee
{
public :

    Manager(string n = "", int r = 0, int t = 0) : Employee(n, r, t)
    { }

    
    
    virtual void print()
    {
        cout << "Type is Manager" << endl; 
        cout << "Name is " << name << endl;
        cout << "Rank is " << rank << endl;
        cout << "No. of Tasks assigned is " << tasksassigned << endl;
    }

    virtual void AssignTask(Employee* E)
    {
        if (dynamic_cast<Manager*>(E))
        {
            cout << "The assigment to is invalid" << endl;
        }
        else if (dynamic_cast<DepEmp*>(E))
        {
            E->IncreaseTasksAssigned(); 
        }
    }

    


};



int main()
{
    Employee* EmployeesList[3];
    EmployeesList[0] = new DepEmp("DepEmp1", 4, 7);
    EmployeesList[1] = new DepEmp("DepEmp2", 3, 5);
    EmployeesList[2] = new Manager("Manager1", 2, 2);

    // Print the details of all Employees
    cout << "Printing all Employees Details: \n";
    EmployeesList[0]->print();
    EmployeesList[1]->print();
    EmployeesList[2]->print();

    
    // Let DepEmp1 assign a task to DepEmp2 and then print the details of all employees
    cout << "DepEmp1 is assigning a task to DepEmp2 \n";
    EmployeesList[0]->AssignTask(EmployeesList[1]);

    int cmp = EmployeesList[0]->Compare(EmployeesList[1]);

    if (cmp == 1)
        cout << "DepEmp1 has higher rank than DepEmp2 \n";
    else if (cmp == 0)
        cout << "Both have same rank \n";
    else
        cout << "DepEmp2 has higher rank than DepEmp1 \n";

    cout << "\nPrinting all Employees Details: \n";
    EmployeesList[0]->print();
    EmployeesList[1]->print();
    EmployeesList[2]->print();

    

    return 0;
}
