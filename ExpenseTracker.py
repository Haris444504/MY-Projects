print("\t\t\t\t\t\t Welcome to Expense Tracker App")

# Global variables
name = ""
email = ""
password = ""
records = []
iscreated = False
isdone = False

def creationAccount():
    global name, email, password, iscreated
    print("Welcome to Account Creation")
    name = input("Enter username: ").capitalize()
    password = input("Enter your specific password: ")
    email = input("Enter your email account: ")
    print("✅ Account created successfully!")
    iscreated = True

def LoginAccount():
    global isdone
    if not iscreated:
        print("⚠️ Please create an account first!")
        return
    print("Welcome to Login")
    email1 = input("Enter your email: ")
    password1 = input("Enter your password: ")
    if email1 == email and password1 == password:
        print("✅ Login successful!")
        isdone = True
        App_Process()
    else:
        print("❌ Invalid email or password. Please try again.")

def AddRecord():
    if not isdone:
        print("⚠️ You must be logged in to add a record.")
        return
    record = {}
    record['budget'] = int(input("Enter the amount of the budget: "))
    record['category'] = input("Enter the category: ")
    for i in range(1, 6):
        record[f'item{i}'] = input(f"Enter item {i}: ")
    records.append(record)
    print("✅ Record added:", record)

def UpdateRecord():
    if not isdone or not records:
        print("⚠️ No records to update or not logged in.")
        return
    print("Current Record:", records[-1])
    print("Updating last record...")
    AddRecord()  # Simplified: Replaces with a new record

def deleteRecord():
    if not isdone or not records:
        print("⚠️ No records to delete or not logged in.")
        return
    removed = records.pop()
    print("✅ Deleted Record:", removed)

def App_Process():
    while True:
        print("\n---------- Expense Tracker Menu ----------")
        print("1 - Add a Record")
        print("2 - Delete Last Record")
        print("3 - Update Last Record")
        print("4 - Show All Records")
        print("5 - Logout")

        choice = int(input("Enter your choice: "))
        if choice == 1:
            AddRecord()
        elif choice == 2:
            deleteRecord()
        elif choice == 3:
            UpdateRecord()
        elif choice == 4:
            print("📂 All Records:")
            for rec in records:
                print(rec)
        elif choice == 5:
            print("🚪 Logged out.")
            break
        else:
            print("❌ Invalid option.")

def show_menu():
    print("\n========== Main Menu ==========")
    print("1 - Create Account")
    print("2 - Login to Account")
    print("3 - Exit")

while True:
    show_menu()
    try:
        main_choice = int(input("Enter your choice: "))
        if main_choice == 1:
            creationAccount()
        elif main_choice == 2:
            LoginAccount()
        elif main_choice == 3:
            print("👋 Exiting... Goodbye!")
            break
        else:
            print("❌ Invalid option. Try again.")
    except ValueError:
        print("⚠️ Please enter a valid number.")
