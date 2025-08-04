#include <iostream>
using namespace std;
int pin = 4567;
int total = 0;
int balance = 0;
int record = 1;
void deposit()
{
    long double a ;
   cout<<"Amount want to deposit : "<<endl;
   cin>>a; 
   cout<<"You have been deposited : "<<a<<"$"<<endl;
   total = a;
   balance += total; 
}
void checkbalance()
{
    cout<<"Total balance = "<<total+balance<<endl;
    total = balance;
}
void withdrawn()
{
    int d;
    long double b;
    cout<<"Enter amount to be withdrawn : ";
    cin>>b;
    if(b > total)
    cout<<"Insufficient amount .."<<endl;
    if(b <= total)
    {
        cout<<"you have been withdrwan : "<<b<<"$"<<endl;
        d = total - b;
        cout<<"Remaining : "<<d<<"$"<<endl; 
    }
}
void accounts()
{
    if(record == 1)
    {
    while (true)
    {
    int option;
    cout<<"1-open account."<<endl;
    cout<<"2-set the current account."<<endl;
    cout<<"3-delete account."<<endl;
    cout<<"Enter option : ";
    cin>>option;
    long double number;
    string name; 
    int code;
    cin.ignore();
    if(option == 1)
    {
        
        cout<<"Your name for account : ";
        getline(cin,name);
        cout<<"Enter your number for account : ";
        cin>>number;
        cout<<"Enter pin of account security: ";
        cin>>code;
        cin.ignore();
        cout<<"name : "<<name<<endl;
        cout<<"Number : "<<number<<endl;
        cout<<"Pin : "<<code<<endl;
        pin = code;
    }
    if(option == 2)
    {
        cout<<"Prevoius details : "<<endl;
        cout<<"name : "<<name<<endl;
        cout<<"Number : "<<number<<endl;
        cout<<"Pin : "<<code<<endl;
        cout<<"Enter new data .. "<<endl;
        cout<<"Your name for account : ";
        getline(cin,name);
        cout<<"Enter your number for account : ";
        cin>>number;
        cout<<"Enter pin of account security: ";
        cin>>code;
        cin.ignore();
        cout<<"name : "<<name<<endl;
        cout<<"Number : "<<number<<endl;
        cout<<"Pin : "<<code<<endl;
        pin = code;
    }
    if(option == 3)
    {
        record == 0;
        cout<<"del account ...."<<endl;
    }
    if(option == 0)
    {
        break;
    }
}
}
}

int main()
{
    while(true)
    {
    cout<<"1-Deposit ."<<endl;
    cout<<"2-Withdraw."<<endl;
    cout<<"3-check balance."<<endl;
    cout<<"4-account creation."<<endl;
    cout<<"5-Exit."<<endl;
    int choice ;
    cout<<"Enter choice (1-5): ";
    cin>>choice;
    switch(choice)
    {
        case 1 : 
        deposit();
        break;
        case 2 : 
        withdrawn();
        break;
        case 3 :
        checkbalance();
        break;
        case 4 : 
        accounts();
        break;
        case 5 : 
        exit(0);
        break;
        default :
        cout<<"Invalid ..."<<endl;  
    }

}

}
