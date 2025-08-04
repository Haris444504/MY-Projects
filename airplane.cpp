#include <iostream>
#include <string>

using namespace std;

string arr1[20]; // Flight name
string arr2[20]; // Seat count
string arr3[20]; // Departure time
string arr4[20]; // Destination
string arr5[20]; // Flight number
string availability[20]; // Availability status
int total = 0;
int seat;
string name,pass,CNIC,flightnum;
void enter() {
    int choice;
    cout << "Enter number of flights: ";
    cin >> choice;

    if (total + choice > 20) {
        cout << "Maximum flight capacity reached (20)." << endl;
        return;
    }
    if (total + choice == 20) {
        cout << "Invalid number of flights." << endl;
        return;
    }
    for (int i = total; i < total + choice; i++) {
        cout << "Enter name of flight: ";
        cin.ignore(); 
        getline(cin, arr1[i]);

        cout << "Enter seat count: ";
        getline(cin, arr2[i]);

        cout << "Enter departure time: ";
        getline(cin, arr3[i]);

        cout << "Enter destination: ";
        cin.ignore();
        getline(cin, arr4[i]);

        cout << "Enter flight number: ";
        getline(cin, arr5[i]);

        cout << "Enter availability status: ";
        getline(cin, availability[i]);

        cout << "------------------------" << endl;
    }
    total += choice;
}

void display() {
    if (total == 0) {
        cout << "No data available." << endl;
    } else {
        for (int i = 0; i < total; i++) {
            cout << "Name: " << arr1[i] << endl;
            cout << "Seats: " << arr2[i] << endl;
            cout << "Departure time: " << arr3[i] << endl;
            cout << "Destination: " << arr4[i] << endl;
            cout << "Flight number: " << arr5[i] << endl;
            cout << "Availability status: " << availability[i] << endl;
            cout << "------------------------" << endl;
        }
    }
}

void booking() {
    if (total == 0) {
        cout << "No data available." << endl;
    } else {
        string flightName;
        cout << "Enter flight name: ";
        cin.ignore();
        getline(cin, flightName);
        cout<<"Enter seat number : ";
        cin>>seat;
       
        bool fightfound = false;
        for(int i = 0;i<total;i++)
        {
        	if(arr1[i] == flightName)
        	
        	{
        		cout<<"Name : "<<arr1[i]<<endl;
        		cout<<"Seats : "<<arr2[i]<<endl;
        		cout<<"Departure time : "<<arr3[i]<<endl;
        		cout<<"Fight number : "<<arr4[i]<<endl;
        		cout<<"Avalibility : "<<arr5[i]<<endl;
        		
        		fightfound = true ;
                
        		cout<<"Name : ";
        		cin.ignore();
        		getline(cin,name);
        		cout<<"Password : ";
        		getline(cin,pass);
        		cout<<"CNIC : ";
        		getline(cin,CNIC);
        		cin.ignore();
        		cout<<"Enter Fight number you want to book : ";
        		getline(cin,flightnum);
        		bool ispresent  = false;
        		bool fightfounding = false;
        		for(int j = 0;j < total ; j++)
        		{
        			if(arr5[j] == flightnum && arr1[j] == flightName)
        			{
        				cout<<"Booking confirmed : "<<endl;
        				cout<<"name : "<<name<<endl;
        				cout<<"password : "<<pass<<endl;
        				cout<<"Cnic : "<<CNIC<<endl;
        				cout<<"Fight number : "<<flightnum<<endl;
                        cout<<"Seat no : "<<seat<<endl;
                        cout<<"_________________________________________________"<<endl;
                        
        				bool bookingfound = true;
        				break;
					}
				}
				if (!booking) {
                    cout << "Flight number or flight name does not match." << endl;
                }
                break;
            }
        }
        if (!fightfound) {
            cout << "Flight not found." << endl;
        }
    }
        		
        		
			}

void search()
{
	string check;
    cout<<" Enter the flight number that is to be checked : ";
    cin.ignore();
    getline( cin , check );
    bool issearched = false ;
    for(int i = 0 ; i < total ; i++)
    {
        if( check == arr5[i] )
        {
            cout<<" flight is found ............................"<<endl;
            for (int i = 0; i < total; i++) {
                cout << "Name: " << arr1[i] << endl;
                cout << "Seats: " << arr2[i] << endl;
                cout << "Departure time: " << arr3[i] << endl;
                cout << "Destination: " << arr4[i] << endl;
                cout << "Flight number: " << arr5[i] << endl;
                cout << "Availability status: " << availability[i] << endl;
                cout << "------------------------" << endl;
                issearched = true ;
            }
            break;
            
            
        }
        if(!issearched)
        {
        	cout<<"FLIGHT NOT FOUND>>>>>>>>"<<endl;
		}
    }



}
void cancel()
{
    string position, check;
    cout<<" Enter the flight number that is to be checked : ";
    cin.ignore();
    getline( cin , check );
    cout<<"Enter seat number you book : ";
    cin>>position;
    bool iscancel = false;
    for(int i = 0 ; i < total ; i++)
    {
       if( check == arr5[i] && position == arr2[i])
        {
            cout<<" flight is found ............................"<<endl;
            for (int i = 0; i < total; i++) {
            	cout<<"Booking cancelled : "<<endl;
        				cout<<"name : "<<name<<endl;
        				cout<<"password : "<<pass<<endl;
        				cout<<"Cnic : "<<CNIC<<endl;
        				cout<<"Fight number : "<<flightnum<<endl;
                        cout<<"Seat no : "<<seat<<endl;
                        cout<<"____________________________________________"<<endl;
                        iscancel = true;
                
            }
            
            break;
        }
         if(!iscancel)
        {
        	cout<<"Ticket NOT FOUND>>>>>>>>"<<endl;
		}
        
    }
	
}

int main()
{
	while(true)
	{
	
	int option ;
    cout<<"1- Enter record "<<endl;
    cout<<"2-display record "<<endl;
    cout<<"3-Booking "<<endl;
    cout<<"4-search "<<endl;
    cout<<"5-cancellation "<<endl;
    cout<<"6-Exit ."<<endl;
    cout<<"Enter choice : ";
    cin>>option;
    if(option ==1)
   enter();
   if(option == 2)
   display();
   if(option == 3)
   booking();
   if(option == 4)
   search();
   if(option == 5)
   cancel(); 
   if(option ==6)
   exit(0);
   
}
}

