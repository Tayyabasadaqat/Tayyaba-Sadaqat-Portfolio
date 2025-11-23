#include <iostream>
#include<stdlib.h>
using namespace std;
class car
{
    private:
    string name;
    int model_number;
    float price;
    public:
    car():name(" "),model_number(0),price(0.0)
    {}
    void set_data()
    {
        cout<<"Enter name of the car"<<endl;
        cin>>name;
        cout<<"Enter model number of the car:"<<endl;
        cin>>model_number;
        cout<<"Enter price of the car:"<<endl;
        cin>>price;
    }
    void get_data()
    {
        cout<<"The name of the car is: "<<name<<endl;
        cout<<"The model number of car is: "<<model_number<<endl;
        cout<<"The price of the car is: "<<price<<endl;
    }
    void reset_data()
    {
        name=" ";
        model_number=0;
        price=0.0;
    }
};
class qarray
{
    private:
    car q[10];
    int rear,front;
    public:
    qarray()
    {
        rear=-1;
        front=0;
    }
    void insert()
    {
        if(rear==9)
        {
            cout<<"Overflowed"<<endl;
            return;
        }
        car c1;
        c1.set_data();
        rear=rear+1;
        q[rear]=c1;
    }
    void removed()
    {
        if(rear==-1)
        {
            cout<<"Underflowed"<<endl;
            return;
        }
        car c2;
        c2=q[front];
        for (int i=0;i<=rear;i++)
        {
            q[i]=q[i+1];
        }
        q[rear].reset_data();
        rear=rear-1;
        cout<<"The data deleted is: ";
        c2.get_data();
    }
    void traverse()
    {
        if(rear==-1)
        {
            cout<<"Underflowed"<<endl;
            return;
        }
        for(int i=0;i<=rear;i++)
        {
            q[i].get_data();
        }
    }
    bool isempty()
    {
        if(rear==-1)
        {
            cout<<"Array Empty"<<endl;
            return true;
        }
        else
        return false;
    }
    bool isfull()
    {
        if(rear==9)
        {
            cout<<"Array Full"<<endl;
            return true;
        }
        else
        return false;
    }
};
int main()
{
    qarray aq;
   int choice;
   do
   {
        cout<<"Welcome to the MENU: \nTo navigate to the desired function press following: "<<endl;
        cout<<"Enter 1 for traversing data: "<<endl;
        cout<<"Enter 2 for inserting more data: "<<endl;
        cout<<"Enter 3 for deleting data: "<<endl;
        cout<<"Enter 4 to check if the array of the queue is empty: "<<endl;
        cout<<"Enter 5 to check if the array of the queue is full:  "<<endl;
        cout<<"Enter 0 to exit the menu: "<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: aq.traverse();
            break;
            case 2: aq.insert();
            break;
            case 3: aq.removed();
            break;
            case 4: aq.isempty();
            break;
            case 5: aq.isfull();
            break;
            case 0: cout<<"Exiting program....."<<endl;
            break;
            default: cout<<"Invalid Choice: "<<endl;
            break;
        }
   } while (choice!=0);
   return 0;
   
}