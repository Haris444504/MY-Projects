

from turtle import up


total = 0 
class CreateAccount:
    def __init__(self , name = "" , password = "" , iscreated = False , islogin = False) :
        self.__name = name 
        self.__password = password
        self.__iscreated = iscreated
        self.__islogin = islogin
    @property
    def get_UserName(self):
        return self.__name
    @property
    def get_Password(self):
        return self.__password
    @property 
    def get_Created(self):
        return self.__iscreated
    @property 
    def get_Login(self):
        return self.__islogin
    def get_Info(self):
        self.__name = input("Create your username: ")
        while True:
            self.__password = input("Create password (8-16 chars): ")
            if 8 <= len(self.__password) <= 16:
                break
            print("Invalid length. Try again.")
        print("Account created successfully!")

        with open("INFO.txt", "w") as file:
            file.write(f"{self.__name}\n")
            file.write(f"{self.__password}\n")


        
    def Login_Account(self):
        try:
            with open("INFO.txt", "r") as file:
                lines = file.readlines()
                if len(lines) < 2:
                    print("Account data is corrupted. Please recreate account.")
                    return
                stored_name = lines[0].strip()
                stored_password = lines[1].strip()
        except FileNotFoundError:
            print("No account found.")
            return

        name = input("Enter username: ")
        password = input("Enter password: ")

        if name == stored_name and password == stored_password:
            print("Login successful!")
            self.__islogin = True
        else:
            print("Invalid credentials.")
            self.__islogin = False


class Cars_Detail :
    _CAR = []
    _ismade = False
    def __init__ (self , Car_name = "" , Car_model_Year = 0 , Car_Brand = "" , Car_Number = "" , Car_Average = 0 , is_Available = False , Rental_cost = 0):
        self.__Car_name = Car_name
        self.__Car_model_Year = Car_model_Year
        self.__Car_Brand = Car_Brand
        self.__Car_Number = Car_Number
        self.__Car_Average = Car_Average
        self.__is_Available = is_Available
        self.__Rental_cost = Rental_cost
    
    def Add_Car(self):
            name = input("Enter car name : ")
            model = input("Enter Car model Year : ")
            Brand = input("Enter Car brand name : ")
            number = input("Enter Car Number plate Number : ")
            average = float(input("Enter average of car :  "))
            cost = int(input("Enter Rental cost of Car  :"))
            available = True
            CARS = Cars_Detail(name , model , Brand , number , average , available , cost )
            Cars_Detail._CAR.append(CARS)
            self._ismade = True
            with open("CAR_System.txt" , "a+" , newline= "") as file :
                file.write(f"Name of Car : {name}\n")
                file.write(f"Model of Car : {model}\n")
                file.write(f"Brand of Car : {Brand}\n")
                file.write(f"Number of Car : {number}\n")
                file.write(f"Average of Car : {average} km/h \n")
                file.write(f"Rental cost of Car : {cost}\n")
                if available == True :
                    file.write(f"Avaliblility of Car : Yes")
                else :
                    file.write(f"Avaliblility of Car : No")

    def show_Details_of_Car(self) :
        with open("CAR_System.txt" , "r") as file :
            print(file.read())

    @classmethod
    def get_Car(cls):
        return cls._CAR

    def get_made(self):
        self._ismade
    def get_Car_name(self):
        return self.__Car_name

    def get_Car_Number(self):
        return self.__Car_Number

    def get_Availability(self):
        return self.__is_Available
    
    def set_avalibility(self):
        self.__is_Available = True

    def get_Rental_Cost(self):
        return self.__Rental_cost

    def set_Unavailable(self):
        self.__is_Available = False

    def set_name(self , name):
        self.__Car_name = name
    
    def set_Year(self , year):
        self.__Car_model_Year = year

    def set_brand(self , brand):
        self.__Car_Brand = brand
    def set_number(self , num):

        self.__Car_Number = num
    def set_average(self , avg):
        self.__Car_Average = avg 

    def set_cost(self , cost):
        self.__Rental_cost = cost

class Rent(Cars_Detail):
    def __init__(self):
        pass

    def Calculate_Cost(self, car):
        days = int(input("Enter number of rental days: "))
        total = days * car.get_Rental_Cost()
        print(f"Total cost for {days} days: {total}")
        return total
    def Rent_car(self):
        Rent_car_name = input("Enter the name of car: ")
        Rent_car_number = input("Enter rental car number: ")
        found = False

        for car in Cars_Detail.get_Car():
            if Rent_car_name.lower() == car.get_Car_name().lower() and Rent_car_number.lower() == car.get_Car_Number().lower():
                found = True
                if car.get_Availability():
                    cost = self.Calculate_Cost(car)
                    car.set_Unavailable()
                    print("Car rented successfully.")
                    print(f"Name of Car: {car.get_Car_name()}")
                    print(f"Number of Car: {car.get_Car_Number()}") # This method must exist in your class
                    print(f"Rental Cost: {cost}")
                else:
                    print("Car is not available.")
                break  # Once found, no need to continue the loop

        if not found:
            print("Car not found.")

class Return_Car(Cars_Detail):
    def __init__(self):
        pass

    def Return_Car(self):
        Return_name = input("Enter car name  : ")
        Return_Number = input("Enter number of car : ")

        found = False 

        for car in Cars_Detail.get_Car():
            if Return_name.lower() == car.get_Car_name().lower() and Return_Number == car.get_Car_Number().lower() :
                found = True 
                if not car.get_Availability() :
                    print("Car return successfully.")
                    car.set_avalibility()
                    print(f"Name of Car: {car.get_Car_name()}")
                    print(f"Number of Car: {car.get_Car_Number()}") # This method must exist in your class
                    
                else :
                    print("Car is already in list ---- returned.")
                break
            if not found :
                print("No car found.") 

class Remove_Car(Cars_Detail):
    def __init__(self, Car_name="", Car_model_Year=0, Car_Brand="", Car_Number="", Car_Average=0, is_Available=False, Rental_cost=0):
        super().__init__(Car_name, Car_model_Year, Car_Brand, Car_Number, Car_Average, is_Available, Rental_cost)

    def RemoveCar(self):
        remove_name = input("Enter the name of car: ").lower()
        remove_number = input("Enter the number of car: ").lower()
        found = False

        for car in Cars_Detail.get_Car():
            if remove_name == car.get_Car_name().lower() and remove_number == car.get_Car_Number().lower():
                found = True
                Cars_Detail._CAR.remove(car)
                print(f"Car {car.get_Car_name()} with number {car.get_Car_Number()} removed successfully.")
                break

class Update_Car(Cars_Detail):
    def __init__(self, Car_name="", Car_model_Year=0, Car_Brand="", Car_Number="", Car_Average=0, is_Available=False, Rental_cost=0):
        super().__init__(Car_name, Car_model_Year, Car_Brand, Car_Number, Car_Average, is_Available, Rental_cost)

    def Update(self):
        update_name = input("Enter car name to update: ").lower()
        update_number = input("Enter car number to update: ").lower()
        found = False

        car_list = Cars_Detail.get_Car()

        for i, car in enumerate(car_list):
            if update_name == car.get_Car_name().lower() and update_number == car.get_Car_Number().lower():
                found = True

            # Collect new details
                name = input("Enter new car name: ")
                model = input("Enter new car model year: ")
                brand = input("Enter new car brand name: ")
                number = input("Enter new car number plate: ")
                average = float(input("Enter new average of car: "))
                cost = int(input("Enter new rental cost of car: "))
                available = True

            # Create updated car object
                updated_car = Cars_Detail(name, model, brand, number, average, available, cost)

            # Replace old car
                car_list[i] = updated_car

                print("Car updated successfully.")
                break

        if not found:
            print("No matching car found to update.")
        else:
        # Save updated list to file
            with open("CAR_System.txt", "w") as file:
                for car in car_list:
                    file.write(f"Name of Car: {car.get_Car_name()}\n")
                    file.write(f"Model of Car: {car.get_Year()}\n")
                    file.write(f"Brand of Car: {car.get_brand()}\n")
                    file.write(f"Number of Car: {car.get_Car_Number()}\n")
                    file.write(f"Average of Car: {car.get_average()} km/h\n")
                    file.write(f"Rental cost of Car: {car.get_cost()}\n")
                    file.write(f"Availability of Car: {'Yes' if car.get_Availability() else 'No'}\n\n")

                

def Menu() :       
        print(" 1 - Add Car .")
        print(" 2 - Remove Car .")
        print(" 3 - Show Cars.")
        print(" 4 - Update Car Information .")
        print(" 5 - Rent a Car .")
        print(" 6 - Return a Car .")
        print(" 7 - Exit.")
        
            
def First_Step():
    CA = CreateAccount()
    CD = Cars_Detail()
    R = Rent()
    Re = Return_Car()
    Rm = Remove_Car()
    U = Update_Car()
    # Check if account exists
    try:
        with open("INFO.txt", "r"):
            account_exists = True
    except FileNotFoundError:
        account_exists = False

    if not account_exists:
        print("No account found. Please create an account.")
        CA.get_Info()

    # Login process
    CA.Login_Account()

    # Main menu loop after login
    while True:
        Menu()
        choice = int(input("Enter your choice: "))
        if choice == 1:
            CD.Add_Car()
        elif choice == 2 :
            Rm.RemoveCar()
        elif choice == 4 :
            U.Update()
        elif choice == 5 :
            R.Rent_car()
        elif choice == 6 :
            Re.Return_Car()
        elif choice == 3:
            CD.show_Details_of_Car()
        elif choice == 7:
            print("Exiting.")
            break
        else:
            print("Invalid choice.")

First_Step()