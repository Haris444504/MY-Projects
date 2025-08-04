#include<iostream>
using namespace std;
string arr1[20];
string arr2[20];
string arr3[20];
string arr4[20];
string arr5[20];
int total = 0;
void enter()
{
     int choice;
    cout << "How many students data you want to enter  : ";
    cin >> choice;
    cin.ignore();
    if (total == 0)
    {
        total = total + choice;
        for (int i = 0; i < choice; i++)
        {
            cout << endl << "Enter student data  : " << i + 1 << endl;
            cout << "Enter name : ";
            getline(cin, arr1[i]); 
            cout << "Enter ID : ";
            cin >> arr2[i];
            cout << "Enter age : ";
            cin >> arr3[i];
            cout << "Enter course : ";
            cin >> arr4[i];
            cout << "Enter CGPA : ";
            cin >> arr5[i];
            cin.ignore(); 
        }
    }
else 
{
    for(int i = total;i<total+choice;i++)
    {
        cout << endl << "Enter student data  : " << i + 1 << endl;
            cout << "Enter name : ";
            getline(cin, arr1[i]); 
            cout << "Enter ID : ";
            cin >> arr2[i];
            cout << "Enter age : ";
            cin >> arr3[i];
            cout << "Enter course : ";
            cin >> arr4[i];
            cout << "Enter CGPA : ";
            cin >> arr5[i];
            cin.ignore(); 
    }
    total=total+choice;

}
}
void show()
{
    if(total == 0)
    {
        cout<<"No data avaliable.."<<endl;
    }
    else
    {
    for(int i = 0;i<total;i++)
    {
        cout<<"Data of students ....."<<i+1<<endl;
        cout<<"Roll No of student  : "<<arr2[i]<<endl;
        cout<<"Name of student : "<<arr1[i]<<endl;
        cout<<"Age of student : "<<arr3[i]<<endl;
        cout<<"Course of student : "<<arr4[i]<<endl;
        cout<<"CGPA of student  : "<<arr5[i]<<endl;
    }

}
}
void search()
{
    string rollno;
    cout<<"Enter student roll number whose data you want top search: ";
    cin>>rollno;
    if(total == 0)
    {
        cout<<"No data avaliable.."<<endl;
    }
    else
    {
    for(int i = 0;i<total;i++)
    {
        if(rollno == arr2[i])
        {
            cout<<"Data of students ....."<<i+1<<endl;
            cout<<"Roll No of student  : "<<arr2[i]<<endl;
            cout<<"Name of student : "<<arr1[i]<<endl;
            cout<<"Age of student : "<<arr3[i]<<endl;
            cout<<"Course of student : "<<arr4[i]<<endl;
            cout<<"CGPA of student  : "<<arr5[i]<<endl; 
        }
    }

}
}
void Update() {
    string upd;
    cout << "Enter student roll number whose data you want to update : ";
    cin >> upd;

    if (total == 0) {
        cout << "no data.." << endl;
        return; 
    }

    bool found = false;
    for (int i = 0; i < total; i++) {
        if (upd == arr2[i]) {
            cout << endl << "Previous Data ...." << endl;
            cout << "Data of students ....." << i + 1 << endl;
            cout << "Roll No of student : " << arr2[i] << endl;
            cout << "Name of student : " << arr1[i] << endl;
            cout << "Age of student : " << arr3[i] << endl;
            cout << "Course of student : " << arr4[i] << endl;
            cout << "CGPA of student : " << arr5[i] << endl;

            cout << "Enter new data of student ....." << endl;
            cout << endl << "Enter student data : " << i + 1 << endl;
            cout << "Enter name : ";
            cin.ignore();
            getline(cin, arr1[i]);
            cout << "Enter ID : ";
            cin >> arr2[i];
            cout << "Enter age : ";
            cin >> arr3[i];
            cout << "Enter course : ";
            cin.ignore();
            getline(cin, arr4[i]);
            cout << "Enter CGPA : ";
            cin >> arr5[i];
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student with roll number " << upd << " not found." << endl;
    }
}

void deleterecord() 
{
    int a;
    cout << "1-DELETE ALL RECORD : " << endl;
    cout << "2-Delete specific record : " << endl;
    cin >> a;
    if (a == 1) {
        total = 0;
        cout << "All data deleted .." << endl;
    } else if (a == 2) {
        string rollno;
        cout << "Enter student roll number whose data you want to delete : ";
        cin >> rollno;

        bool found = false;
        for (int i = 0; i < total; i++) {
            if (rollno == arr2[i]) {
                for (int j = i; j < total - 1; j++)
				 { 
                    arr1[j] = arr1[j + 1];
                    arr2[j] = arr2[j + 1];
                    arr3[j] = arr3[j + 1];
                    arr4[j] = arr4[j + 1];
                    arr5[j] = arr5[j + 1];
                }
                total--; 
                cout << "Your required record is deleted.." << endl;
                found = true;
                break;
            }
        }
        if (!found)
    {
            cout << "Invalid input .." << endl;
        }
    } else 
	{
        cout << "Invalid choice." << endl;
    }
}
string A[20];
string B[20];
string C[20];
string D[20];
int whole = 0;
void add()
{
    cout<<"ADDING A BOOK ...."<<endl;
    int add;
    cout<<"How many book you want to add  : ";
    cin>>add;
    cin.ignore();
    if(whole == 0)
    {
    whole = whole + add;
    for(int i = 0;i<add;i++)
    {
        cout<<"BOOK DETAIL NO "<<i+1<<endl;
        cout<<"Enter book Title :";
        getline(cin,A[i]);
        cout<<"Enter book ID : ";
        getline(cin,B[i]);
        cout<<"Enter book Author : ";
        getline(cin,C[i]);
        cout<<"Enter avaibility status : ";
        cin>>D[i];
        cin.ignore();

    }
}
else
{
    for(int i = whole;i<whole + add;i++)
    {
        cout<<"BOOK DETAIL NO "<<i+1<<endl;
        cout<<" book Title :";
        cin>>A[i];
        cout<<" book ID : ";
        cin>>B[i];
        cout<<" book Author : ";
        cin>>C[i];
        cout<<" avaibility status : ";
        cin>>D[i];

    }

}
}
void view()
{
    if(whole == 0)
    {
        cout<<"No data avilable"<<endl;
    }
    else
    {
    for(int i = 0;i<whole;i++)
    {
        cout<<"BOOK DETAIL NO "<<i+1<<endl;
        cout<<"book Title :"<<A[i]<<endl;
        cout<<"book ID : "<<B[i]<<endl;
        cout<<"book Author : "<<C[i]<<endl;
        cout<<"avaibility status : "<<D[i]<<endl;

    }

}
}
void borrow()
{
    
	if(whole == 0)
	{
		cout<<"No data availiable ..."<<endl;
	}
	else 
	{
	string bor;
    cout<<"Enter book you want to borrow : ";
    cin>>bor;
    bool bookborrow = false;
     for(int i = 0;i<whole;i++)
     {
        if(bor == B[i])
        {
        	bookborrow = true;
                cout<<"Book Detail is : "<<endl;
                cout<<"BOOK DETAIL NO "<<i+1<<endl;
                cout<<"book Title :"<<A[i]<<endl;
                cout<<"book ID : "<<B[i]<<endl;
                cout<<"book Author : "<<C[i]<<endl;
                cout<<"avaibility status : "<<D[i]<<endl;
                cout<<"..........."<<endl;
                if(D[i] == "yes")
                {
                cout<<"Avaliable! borrow it.PLease return in  14 days."<<endl;
                cout<<"..................."<<endl;
                D[i] = "no";
                cout<<"AVilibilty status uploaded to : "<<D[i]<<endl;
            }
                else if(D[i]=="no")
                {
                	cout<<" NOt avilable."<<endl;
				}
            }
            else if(!bookborrow)
            {
            	cout<<"book not found."<<endl;
			}
        }
     }
 }

void returnbook()
{
	if(whole == 0)
	{
		cout<<"NO data availiable ..."<<endl;
	}
	else 
	{
	string ret;
	cout<<"ID of book you want to return : ";
	cin>>ret;
	for(int i = 0;i<whole;i++)
    {
    	if(ret == B[i])
    	{
		
        cout<<"BOOK DETAIL NO "<<i+1<<endl;
        cout<<"book Title :"<<A[i]<<endl;
        cout<<"book ID : "<<B[i]<<endl;
        cout<<"book Author : "<<C[i]<<endl;
        cout<<"avaibility status : "<<D[i]<<endl;
        D[i] = "yes";
        cout<<"Update status again to us : "<<D[i]<<endl;
    }

   } 
 }
} 
void deletebook()
{

   if(whole == 0)
	{
		cout<<"NO data availiable ..."<<endl;
	}
	else 
	{
	int del;
    cout << "1-DELETE ALL RECORD : " << endl;
    cout << "2-Delete specific record : " << endl;
    cin >> del;
    if (del == 1) {
        whole = 0;
        cout << "All data deleted .." << endl;
    } else if (del == 2) {
        string dell;
        cout << "Enter  ID whose data you want to delete : ";
        cin >> dell;

        bool bookdel = false;
        for (int i = 0; i < whole; i++) 
		{
            if (dell == B[i]) 
			{
                for (int j = i; j < whole - 1; j++)
				 { 
                    A[j] = A[j + 1];
                    B[j] = B[j + 1];
                    C[j] = C[j + 1];
                    D[j] = D[j + 1];
                    
                }
                whole--; 
                cout << "Your required record is deleted.." << endl;
                bookdel = true;
                break; 
            }
                else if (!bookdel)
        {
            cout << "Invalid input .." << endl;
        }
}
    }
	 else 
	{
        cout << "Invalid choice." << endl;
    }
 }
}


int main()
{
	while(true)
	{
		int option ;
		cout<<"1-Student management system : "<<endl;
		cout<<"2-Library management system : "<<endl;
		cout<<"0-Exit"<<endl;
		cin>>option;

		if(option == 1)
		{
			cout<<"Student management System."<<endl;
			int value;
			while(true)
			{  
				cout<<"1-Enter data of student  : "<<endl;
				cout<<"2-Show data of student  : "<<endl;
				cout<<"3-Search data of student  : "<<endl;
				cout<<"4-Update data of student  : "<<endl;
				cout<<"5-Delete data of student  : "<<endl;
				cout<<"6-Exit to main menu  : "<<endl;
				cin>>value;

				switch (value)
				{
					case 1  : enter(); break;
					case 2  : show(); break;
					case 3  : search(); break;
					case 4  : Update(); break;
					case 5  : deleterecord(); break;
					case 6  : goto main_menu;
					default : cout<<"INVALID INPUT .."<<endl;
				}
			}
		}
		else if(option == 2)
		{
			cout<<"Library management system . "<<endl;
			int pick;
			while(true)
			{
				cout<<"1-Add Book : "<<endl;
				cout<<"2-View Available book : "<<endl;
				cout<<"3-Borrow Book : "<<endl;
				cout<<"4-Return book : "<<endl;
				cout<<"5-Delete book : "<<endl;
				cout<<"6-Exit to main menu  : "<<endl;
				cin>>pick;

				switch (pick)
				{
					case 1 : add(); break;
					case 2 : view(); break;
					case 3 : borrow(); break;
					case 4 : returnbook(); break;
					case 5 : deletebook(); break;
					case 6 : goto main_menu;
					default : cout<<"INVALID INPUT .."<<endl;
				}
			}
		}
		else if(option == 0) 
			exit(0);

		main_menu:; 
	}
}

