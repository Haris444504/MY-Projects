#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class ProgramStatus{
	public :
		virtual void ProgramExecution()  = 0 ;
		virtual void ProgramError() = 0 ;
};

class Record {
    private:
    int RecordNum;

	public : 
	Record () {
		RecordNum = 0;
	}
	Record (int RecordNum){
		this->RecordNum = RecordNum ;
	}
	void Display(){
    Record::Display();  
    cout << "Telephone Directory:" << endl;
}
};
class Telephone  : public Record {
    int ID[5];
    string name[5];
    string address[5];
    int phone_no[5];
    bool iscreated[5];
    int recordcount;

    public :
    Telephone() : Record (){
        recordcount = 0;
        for(int i = 0 ; i < 5 ; i++){
            ID[i] = 0;
            name[i] = " ";
            address[i] = " ";
            phone_no[i] = 0;
            iscreated[i] = false;
        } 
    }
void Insert(int& size) {
    char choice;

    do {
        ofstream file("MabahAdnan.txt", ios::app);
        if(!file){
            cout << "Error opening file." << endl;
            return;
        }
        for (int i = recordcount; i < size; i++) {
            cout << "\nRecord of " << i + 1 << endl;

            cin.ignore();  
            cout << "Enter Name: ";
            getline(cin, name[i]);

            cout << "Enter ID: ";
            cin >> ID[i];

            cin.ignore();  
            cout << "Enter Address: ";
            getline(cin, address[i]);

            cout << "Enter Phone No: ";
            cin >> phone_no[i];

            int save;
            cout << "Enter 0 to Save or 1 to Discard: ";
            cin >> save;

            if (save == 0) {
                iscreated[i] = true;
                recordcount++;
                file << "Name of Student: " << name[i] << endl;
                file << "ID: " << ID[i] << endl;
                file << "Address: " << address[i] << endl;
                file << "Phone No: " << phone_no[i] << endl;
                file << "----------------------------------------" << endl;
                cout << "Record saved.\n";
            } else if (save == 1) {
                iscreated[i] = false;
                cout << "Record not saved.\n";
            } else {
                cout << "Invalid option. Record discarded by default.\n";
                iscreated[i] = false;
            }

            if (recordcount >= size) {
                cout << "Maximum number of records reached.\n";
                break;
            }
        }

        if (recordcount >= size) break;

        cout << "\nDo you want to insert again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nInsertion process finished. Total records saved: " << recordcount << endl;
}

        void loadfromFile() {
                ifstream file("MabahAdnan.txt");
                if (!file) {
                    cout << "Error opening file." << endl;
                    return;
                }
                string line;
                while (getline(file, line)) {
                    cout << line << endl;
                }
                file.close();
            }   
    void Update(int &size){
         int Id;
        cout<<"Enter Searched Id : "; cin>>Id;
            for(int i = 0; i < size ; i++){
                if(Id == ID[i]){
            if(recordcount == 0 && iscreated[i] == false){
            cout<<"NO DATA AVALIABLE."<<endl;
            break;

        }
    }

            if(Id == ID[i]){
            if(recordcount != 0 && iscreated[i] == true) {
            ifstream file("MabahAdnan.txt", ios::app);
            if(!file){
                cout << "Error opening file." << endl;
                return;
            }
            cout<<"Previous one : \n"<<endl;
            loadfromFile();
            
        char x;
            cout<<"Enter Y for again Insert or N for menu : ";
            cin>>x;
            if(x == 'y'){cout<<"Enter New One \n"<<endl;
            cout << "Enter Name : ";cin.ignore(); getline(cin,name[i]); 
            cout<<"Enter ID : "; cin>>ID[i];
            cout<<"Enter Address : ";cin.ignore(); getline(cin,address[i]);
            cout<<"Enter phone No : "; cin>>phone_no[i];
            iscreated[i] = true;

            cout<<"New  : \n"<<endl;
            loadfromFile();
            }
            if(x == 'n'){
                cout<<"Record not updated."<<endl;
            }
            else{
                cout<<"Invalid option."<<endl;
            }
            char q;
            cout<<"Enter Y for again Insert or N for menu : ";
            cin>>q;



            if(q == 'y'){
            for(int i = 0; i < size ; i++){
                if(Id == ID[i]){
            if(recordcount == 0 && iscreated[i] == false){
            cout<<"NO DATA AVALIABLE."<<endl;
            break;

        }
    }

            if(Id == ID[i]){
            if(recordcount != 0 && iscreated[i] == true) {
            loadfromFile();
        char x;
            cout<<"Enter Y for again Insert or N for menu : ";
            cin>>x;
            if(x == 'y'){cout<<"Enter New One \n"<<endl;
            ofstream file("MabahAdnan.txt", ios::app);
            if(!file){
                cout << "Error opening file." << endl;
                return;
            }
            file << "Enter Name : ";cin.ignore(); getline(cin,name[i]); 
            file<<"Enter ID : "; cin>>ID[i];
            file<<"Enter Address : ";cin.ignore(); getline(cin,address[i]);
            file<<"Enter phone No : "; cin>>phone_no[i];
            iscreated[i] = true;

            cout<<"New  : \n"<<endl;
            loadfromFile();
            if(x == 'n'){
                cout<<"Record not updated."<<endl;
            }
            else {
                cout<<"Invalid option."<<endl;
            }
               
        }
    }
    else
    cout<<"Invalid Id."<<endl;

}
            }
        }
    }
}
    }
}
    void deleteRecord(int &size){
        int Id;
        cout<<"Enter Searched Id : "; cin>>Id;
            for(int i = 0; i < size ; i++){
                if(Id == ID[i]){
            if(recordcount == 0 && iscreated[i] == false){
            cout<<"NO DATA AVALIABLE."<<endl;
            break;

        }
    }
    

        if(Id == ID[i]){
            char x;
            cout<<"Enter Y for delete or N for menu : ";  
            cin>>x;
            if(x == 'y'){
            if(recordcount != 0 && iscreated[i] == true) {
            loadfromFile();
            iscreated[i] = false;
            recordcount--;
        }
            if(x == 'n'){
                cout<<"Record not deleted."<<endl;
            }
            else{
                cout<<"Invalid option."<<endl;
            }
            char q;
            cout<<"Enter Y for again Insert or N for menu : ";
            cin>>q;
            if(q == 'y'){
            int Id;
            cout<<"Enter Searched Id : "; cin>>Id;
            for(int i = 0; i < size ; i++){
                if(Id == ID[i]){
            if(recordcount == 0 && iscreated[i] == false){
            cout<<"NO DATA AVALIABLE."<<endl;
            break;

        }
    }

        if(Id == ID[i]){
            char x;
            cout<<"Enter Y for delete or N for menu : ";  
            cin>>x;
            if(x == 'y'){
            if(recordcount != 0 && iscreated[i] == true) {
            loadfromFile();
            iscreated[i] = false;
            recordcount--;
        }
            if(x == 'n'){
                cout<<"Record not deleted."<<endl;
            }
            else{
                cout<<"Invalid option."<<endl;
            }
    }
    else
    cout<<"Invalid Id."<<endl;

}
            }
        }
    }
}
            }
        }
        void searchrecord(int &size ){
        int Id;
        int t;
        cout<<"Press 1 for serach by id or 0 for search by name : ";
        cin>>t;
        if(t == 1 ){
		
        cout<<"Enter Searched Id : "; cin>>Id;
            for(int i = 0; i < size ; i++){
                if(Id == ID[i]){
            if(recordcount == 0 && iscreated[i] == false){
            cout<<"NO DATA AVALIABLE."<<endl;
            break;

        }
    }

        if(Id == ID[i]){
            char x;
            cout<<"Enter Y for search or N for menu : ";        cin>>x;
            if(x == 'y'){
            if(recordcount != 0 && iscreated[i] == true) {
            loadfromFile();
        }
    }
            if(x == 'n'){
                cout<<"Record not searched."<<endl;
            }
            else{
                cout<<"Invalid option."<<endl;
            }
            char q;
            cout<<"Enter Y for again Insert or N for menu : ";
            cin>>q;
            if(q == 'y'){
            int Id;
        cout<<"Enter Searched Id : "; cin>>Id;
            for(int i = 0; i < size ; i++){
                if(Id == ID[i]){
            if(recordcount == 0 && iscreated[i] == false){
            cout<<"NO DATA AVALIABLE."<<endl;
            break;

        }
    }

        if(Id == ID[i]){
            char x;
            cout<<"Enter Y for search or N for menu : ";        cin>>x;
            if(x == 'y'){
            if(recordcount != 0 && iscreated[i] == true) {
            loadfromFile();
        }
    }
            if(x == 'n'){
                cout<<"Record not searched."<<endl;
            }
            else{
                cout<<"Invalid option."<<endl;
            }
    }
    else
        cout<<"Invalid Id."<<endl;

}
}
        }
    }
}
    if(t == 0 ){
		string n;
        cout<<"Enter Searched name : "; cin>>n;
            for(int i = 0; i < size ; i++){
                if(n == name[i]){
            if(recordcount == 0 && iscreated[i] == false){
            cout<<"NO DATA AVALIABLE."<<endl;
            break;

        }
    }

        if(n == name[i]){
            char x;
            cout<<"Enter Y for search or N for menu : ";        cin>>x;
            if(x == 'y'){
            if(recordcount != 0 && iscreated[i] == true) {
            loadfromFile();
        }
    }
            if(x == 'n'){
                cout<<"Record not searched."<<endl;
            }
            else{
                cout<<"Invalid option."<<endl;
            }
            char q;
            cout<<"Enter Y for again Insert or N for menu : ";
            cin>>q;
            if(q == 'y'){
            string n;
        cout<<"Enter Searched Id : "; cin>>n;
            for(int i = 0; i < size ; i++){
                if(n == name[i]){
            if(recordcount == 0 && iscreated[i] == false){
            cout<<"NO DATA AVALIABLE."<<endl;
            break;

        }
    }

        if(n == name[i]){
            char x;
            cout<<"Enter Y for search or N for menu : ";        cin>>x;
            if(x == 'y'){
            if(recordcount != 0 && iscreated[i] == true) {
            cout << "Enter Name : "<<name[i]<<endl;
            cout<<"Enter ID : "<<ID[i]<<endl;;
            cout<<"Enter Address : "<<address[i]<<endl;
            cout<<"Enter phone No : "<<phone_no[i]<<endl;
        }
    }
            if(x == 'n'){
                cout<<"Record not searched."<<endl;
            }
            else{
                cout<<"Invalid option."<<endl;
            }
    }
    else
        cout<<"Invalid Id."<<endl;

}
}
        }
    }
}
}
    void viewList(int &size){
        for(int i = 0; i < size ; i++){
            if(recordcount == 0 && iscreated[i] == false){
            cout<<"NO DATA AVALIABLE."<<endl;
            break;
        }
        if(recordcount != 0 && iscreated[i] == true){
                
            cout << "Enter Name : "<<name[i]<<endl;
            cout<<"Enter ID : "<<ID[i]<<endl;;
            cout<<"Enter Address : "<<address[i]<<endl;
            cout<<"Enter phone No : "<<phone_no[i]<<endl;
        }
        
    }
}
    void display(){
        Record::Display(); 
        cout << "Telephone Directory:" << endl;
    }
    
bool operator==(const Telephone& other) {
    for (int i = 0; i < 5; i++) {
        if (iscreated[i] && other.ID[i] == this->ID[i]) {
            return true;
        }
    }
    return false;
}
friend ostream& operator<<(ostream& out, const Telephone& t) {
    for (int i = 0; i < 5; i++) {
        if (t.iscreated[i]) {
            out << "Name: " << t.name[i] << "\n";
            out << "ID: " << t.ID[i] << "\n";
            out << "Address: " << t.address[i] << "\n";
            out << "Phone No: " << t.phone_no[i] << "\n\n";
        }
    }
    return out;
}
    
};

class Status : public ProgramStatus {
    public :
    void ProgramExecution() override {
        cout << "Program is executing." << endl;
    }
    
    void ProgramError() override {
        cout << "No error occurred in the program." << endl;
    }
};

class AddressBook {
    Telephone* tel; 
public:
    AddressBook(Telephone* t) {
        tel = t;
    }
    void showAll(int size) {
        
        tel->viewList(size);  
    }
};

int main()
{
    int size;
    cout<<"Enter number of students whose data (max 5) : ";
    cin>>size;
    if(size  > 5){
        cout<<"Max using size is 5\n";
        size = 5;
    }
    int choice;
    Telephone T;
    AddressBook AB(&T); 
    Status S;
    Record R;

    do{
        cout<<"1. Insert a new student"<<endl;
        cout<<"2. Update an existing student"<<endl;
        cout<<"3. Delete a record"<<endl; 
        cout<<"4. Search for a student (using name or ID)"<<endl;
        cout<<"5. List directory"<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"Enter choice (1-5) : "<<endl;
        cin>>choice;

        if(choice == 1){
            T.Insert(size);
        }
        if(choice == 2){
            T.Update(size);
        }
        if(choice == 3){
            T.deleteRecord(size);
        }
        if(choice == 4){
            T.searchrecord(size);
        }
        if(choice == 5){
            T.viewList(size);
        }
        if(choice < 1 || choice > 5){
            cout<<"Invalid choice. Please try again."<<endl;
        }
        if(choice == 0){
            cout<<"Exiting the program."<<endl;
            break;
        }

cout << T; 
AB.showAll(size); 
        
        S.ProgramExecution();
        S.ProgramError();
        cout << "--------------------------------------------------------" << endl;

    }while(choice <=5);
}

