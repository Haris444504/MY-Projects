
import csv

class Student :
    def __init__(self , name , age , Id , Gpa ):
        self.__name = name 
        self.__age = age 
        self.__Id = Id
        self.__Gpa = Gpa 

    @property
    def get_Name(self):
        return self.__name
    @property
    def get_Age(self):
        return self.__age
    @property
    def get_Id(self):
        return self.__Id
    @property
    def get_Gpa(self):
        return self.__Gpa
    
class Information(Student):
    __student = []
    def __init__(self , student = [] , iscreated = False) :
        self.__student = []
        self.__iscreated = iscreated
    

    def Add_Student(self):
        name = input("Enter Name of Student : ")
        Id = input("Enter  ID of Student : ")
        age = int(input("Enter Age of Student : "))
        Gpa = float(input("Enter (GRADE POINT AVERAGE) --GPA-- of Student : "))


        student = Student(name , Id , age , Gpa)
        self.__student.append(student)
        self.__iscreated = True 
        with open("StudentManagement_System.txt" , "a+" ,newline= "") as file:
            file.seek(0)
            is_empty = (file.read(1) == "")
            file.seek(0,2)


            writer = csv.DictWriter(file , fieldnames=["name" , "Id","age" , "Gpa"])

            if is_empty :
                writer.writeheader()
            for student in self.__student :
                writer.writerow({
                    "name" : student.get_Name,
                    "age" : student.get_Age,
                    "Id" : student.get_Id,
                    "Gpa" : student.get_Gpa
                })

    def show_student(self):
        try :
            with open("StudentManagement_System.txt" , "r") as file:
                reader = csv.DictReader(file)
                found = False
                for row in reader :
                    found = True
                    print("----------------------------------------")
                    print("Student Information")
                    print(f"Name  of Student : {row['name']}")
                    print(f"Age of Student   : {row['age']}")
                    print(f"Id of Student  : {row['Id']}")
                    print(f"Gpa of Student : {row['Gpa']}")
                if not found:
                    print("No data Avaliable.")
        except FileNotFoundError:
            print("File not found. Please add records first.")

class Delete(Information) :

    def Delete_student(self) :
            id = input("Enter Id of student : ")
            update_Student = []
            found = False
            try :
                with open("StudentManagement_System.txt" , "r") as file :
                    reader = csv.DictReader(file)
                    for row in reader  :
                        if row['Id'] != id :
                            update_Student.append(row)
                        else :
                            found =  True
            except FileNotFoundError :
                print("File not found")
                return 
            
            if found :
                with open("StudentManagement_System.txt" , "w") as file :
                    writer = csv.DictWriter(file , fieldnames=["name" , "Id","age" , "Gpa"])
                    writer.writeheader()
                    writer.writerows(update_Student)
                print("Record Deleted successfully.")
            else :
                print("No record found.")

class Serach(Information) :
    def Search_Info(self) :
        search_Id = input("Enter Id of Student : ")
        found = False
        try:
            with open("StudentManagement_System.txt", "r") as file:
                reader = csv.DictReader(file)
                for row in reader:
                    if row['Id'] == search_Id:
                        found = True
                        print("----------------------------------------")
                        print("Student Information")
                        print(f"Name  of Student : {row['name']}")
                        print(f"Age of Student   : {row['age']}")
                        print(f"Id of Student  : {row['Id']}")
                        print(f"Gpa of Student : {row['Gpa']}")
            if not found:
                print("No record found with the given Id.")
        except FileNotFoundError:
            print("File not found. Please add records first.")

def Show_Menu():   
    print("-----------------Student Managment System----------------\n")
    print(" 1 - Add a Student Record . ")
    print(" 2 - Show details of all students Record .")
    print(" 3 - Search a Student Record . ")
    print(" 4 - Update a Student Record . ")
    print(" 5 - Delete a Student Record . ")
    print(" 6 - Exiting from a System   . ")


Info = Information()
S = Serach()
D = Delete()
while(True) :
    Show_Menu()
    try :
        choice = int(input("Enter your choice (1 - 5 ): "))
        if choice == 1 :
            Info.Add_Student()
        elif choice == 2 :
            Info.show_student()
        elif choice == 3 :
            S.Search_Info()
        elif choice == 4 :
            print("------Under coding!----------")
        elif choice == 5 :
            D.Delete_student()
        elif choice :
            print("\n\n -----------------Exiting---------------------\n\n")
            exit()
        else :
            print("\n-------------------Invalid Input--------------\n")
            continue
    except ValueError :
        print("\n----------------------Invalid Input Value-----------------\n")