print("-----------Wellcome to Employee system---------------")

Employee = []
global name, iscreated, password

name = "" 
iscreated = False
password = ""

def Create_Account() :
    global name , iscreated , password 
    name = input("Enter your name : ")
    password = input("Enter your password : ")
    if len(password) < 6 and len(password) > 16:
        print("Password must be at least 6 characters long.")
        return
    if len(password) == 6 or len(password) <= 16:
        iscreated = True
        with open("account.txt","w") as f :
            f.write(f"Name of user : {name}\nPassword of user : {password}")
        print("Account created successfully!")


# for menu of Employee system 
def Menu() :
    while True :
        print("1-Add Employee")
        print("2-View Employees")
        print("3-Update Employee")
        print("4-Delete Employee")
        print("5-Go to salary sheet")
        print("6-Exit")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            Add_Employee()
        elif choice == 2:
            View_Employees()
        elif choice == 3:
            Update_Employee()
        elif choice == 4:
            Delete_Employee()
        elif choice == 5:
        # Salary_Sheet()
            print("non")
        elif choice == 6:
            print("Exiting the system.")
            exit()


def Add_Employee():
    # Function to add an employee
    Name = input("Enter employee name: ")
    Employee.append(Name)
    with open("employee.txt", "a") as f:
        f.write(f"Employee name : {Name}\n")
    print("Employee added successfully!")


def View_Employees() :
    if Employee :
        print("Employees List:")
        for emp in Employee  :
            print(emp)
        print("End of employee list.")


def Update_Employee() :
    # for updating value
    name_to_update  =   input("Enter the name of the employee to update: ")
    if name_to_update in Employee :
        new_name = input("Enter the new name: ")
        index = Employee.index(name_to_update)
        Employee[index] = new_name
        with open("employee.txt", "w") as f:
            for emp in Employee:
                f.write(f"Employee name : {emp}\n")
        print("Name update successfully!")


def Delete_Employee() :
    # for deleting employee record 
    name_to_Delete = input("Enter the name to be deleted : ")
    if name_to_Delete in Employee :
        index = Employee.index(name_to_Delete)
        Employee.pop(index)
        with open("employee.txt", "w") as f:
            for emp in Employee:
                f.write(f"Employee name : {emp}\n")
        print("Name deleted successfully")


# for login account 
def Login_Account() :
    global name , password ,iscreated 
    if iscreated == True :
            name1 = input("Enter your name : ")
            password1 = input("Enter your password : ")
            if name1 == name and password1 == password :
                print("Login successful!")
                Menu()
            else :
                print("Invalid credentials, please try again.")
    elif iscreated == False :
        print("You need to create an account first.")
        opion = print("you want to create an account? (yes/no) : ")
        if opion == "yes" :
            Create_Account()
            Menu()
        else :
            print("Exiting the system.")
            show_menu()



# for showing menu
def show_menu() :
    global iscreated 
    while True :
        print("1-Create Account.")
        print("2-Login Account.")
        print("3-Exit")
        choice = int(input("Enter your choice : "))
        if choice == 1 :
            if iscreated == False :
                Create_Account()
                Menu()
            else :
                Login_Account()
                Menu()
        elif choice == 2 :
            if iscreated == True :
                Login_Account()
                Menu()
        elif choice == 3 :
            print("Exiting the system.")
            exit()
        else :
            print("Invalid choice, please try again.")


while True:
    show_menu()
