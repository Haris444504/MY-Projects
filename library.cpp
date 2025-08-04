#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct Book
{
    string name;
    string id;
    string author;
    bool isavaliable;
    string username;
    string usernumber;
};
void enter(Book books[], int& bookCount)
{
    int choice ;
    cout<<"Enter How much books you want to enter  : ";
    cin>>choice;
    if(choice + bookCount > 100)
    {
        cout<<"Maximium capacity excceed (100)"<<endl;
    }
    for(int i = 0;i < choice;i++)
    {
        cout<<"Enter Name of Book "<<i+1<<": ";
        cin.ignore();
        getline(cin,books[bookCount].name);
        cout<<"Enter Id of Book : ";
        cin>>books[bookCount].id;
        cout<<"Enter Auther of Book : ";
        cin.ignore();
        getline(cin,books[bookCount].author);
        cout<<"Enter avalibility of Book : ";
        cout<<"____________________________________"<<endl;
        cin>>books[bookCount].isavaliable;
        bookCount++;
    }
}
void show(Book books[], int bookCount)
{
  if(bookCount == 0)
  {
    cout<<"NO DATA AVALIABLE............"<<endl;
  }
  else{
    for(int i = 0;i < bookCount;i++)
    {
         cout<<"Name of book : "<<books[i].name<<endl;
        cout<<"Id of book : "<<books[i].id<<endl;
        cout<<"Author of book : "<<books[i].author<<endl;
        cout<<"Avaliablility of book : "<<books[i].isavaliable<<endl;
    }
  }
}
void search(Book books[], int bookCount)
{
  string Idbyuser;
  cout<<"Enter Id for book : ";
  cin.ignore();
  getline(cin,Idbyuser);
  bool issearch = false;
  for(int i = 0; i < bookCount;i++)
  {
  if(Idbyuser == books[i].id)
  {
      cout<<"Name of book : "<<books[i].name<<endl;
        cout<<"Id of book : "<<books[i].id<<endl;
        cout<<"Author of book : "<<books[i].author<<endl;
        cout<<"Avaliablility of book : "<<books[i].isavaliable<<endl;
    issearch = true;

  break;
  }
 }
 if(!issearch)
 {
   cout<<"Book not found"<<endl;
 }
}
void borrow(Book books[], int bookCount)
{
    string Idbyuser;
    cout<<"Enter Id for book : ";
    cin.ignore();
    getline(cin,Idbyuser);
    bool issearch = false;
    for(int i = 0; i < bookCount;i++)
    {
        if(Idbyuser == books[i].id && books[i].isavaliable == 1)
    {
    cout<<"Enter your name : ";
    cin.ignore();
    getline(cin,books[i].username);
    cout<<"Enter your number for contract : ";
    cin.ignore();
    getline(cin,books[i].usernumber);
        cout<<"Name of book : "<<books[i].name<<endl;
        cout<<"Id of book : "<<books[i].id<<endl;
        cout<<"Author of book : "<<books[i].author<<endl;
        cout<<"Avaliablility of book : "<<books[i].isavaliable<<endl;
      issearch = true;
      books[i].isavaliable = 0;
      
    break;
    }
   }
   for(int i = 0; i < bookCount;i++)
    {
   if(!issearch)
   {
     cout<<"Book not found"<<endl;
     cout<<"Borrowed by : "<<books[i].username<<endl;
     break;
   }
}
}
void returned(Book books[], int bookCount)
{
    string nameofbook;
    cout<<"Enter name of book : ";
    cin.ignore();
    getline(cin,nameofbook);
    bool isreturn = false;
    for(int i = 0;i < bookCount;i++)
    {
        if(nameofbook == books[i].name)
        {
            cout<<"Name of book : "<<books[i].name<<endl;
        cout<<"Id of book : "<<books[i].id<<endl;
        cout<<"Author of book : "<<books[i].author<<endl;
        cout<<"Avaliablility of book : "<<books[i].isavaliable<<endl;
            isreturn = true;
            books[i].isavaliable = 1;
            break;
        }
    }
    if(!isreturn)
    {
       cout<<"book not found.."<<endl;
    }
}
void deleted(Book books[], int& bookCount)
{
    int opinion;
    cout<<"1-Delete all record.."<<endl;
    cout<<"2-Delete specific one ."<<endl;
    cout<<"Enter choice : ";
    cin>>opinion;
    if(opinion == 1)
    {
        bookCount = 0;
        cout<<"All data delelete successfully."<<endl;
        cout<<"---------------------"<<endl;
    }
    if(opinion == 2)
    {
        string iddel;
        cout<<"Enter book Id : ";
        cin.ignore();
        getline(cin,iddel);
        for(int i = 0;i<bookCount;i++)
        {
            if(iddel == books[i].id)
            {
                cout<<"delete this record ..."<<endl;
                bookCount--;
            }
            else 
            {
                cout<<"no book .."<<endl;
            }
        }
    }


}
int main()
{
    ofstream File("c:\\Haris\\haris.txt");
    const int max_book = 100;
    Book libraryBook[max_book];
    int bookCount = 0; // tracing............
    while (true)
    {
        int option;
        cout<<"1-Enter data of books only for libairy priavte access."<<endl;
        cout<<"2-Show all records of books ."<<endl;
        cout<<"3-Search books."<<endl;
        cout<<"4-Borrow book."<<endl;
        cout<<"5-Return book."<<endl;
        cout<<"6-Delete records (only library access.)"<<endl;
        cout<<"7-Exit system."<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"Enter choice : ";
        cin>>option;
        if(option == 1)
        {
            string pin = "lib@567";
            File << pin <<endl;
            string match;
            cout<<"Enter pin to access it : ";
            cin>>match;
            if(match == pin)
            {
                enter(libraryBook,bookCount);
            }
            else
            {
                cout<<"Invalid key ."<<endl;
            }
        }
        if(option == 2)
        {
          show(libraryBook,bookCount);
        }
        if(option == 3)
        {
           search(libraryBook,bookCount);
        }
        if(option == 4)
        {
          borrow(libraryBook,bookCount);
        }
        if(option == 5)
        {
          returned(libraryBook,bookCount);
        }
        if(option == 6)
        {
            string pass = "lib@789";
            File << pass <<endl;
            string key;
            cout<<"Enter Key : ";
            cin>>key;
            if(key == pass)
            {
                deleted(libraryBook,bookCount);
            }
            else
            {
                cout<<"Invalid key ."<<endl;
            }
            
        }
        if(option == 7)
        {
            exit(0);
        }
        
    }
    
   return 0;
}
