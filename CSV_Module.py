import csv

class Student:
    def __init__(self, name=" ", Id=0, Gpa=0.0):
        self.__name = name
        self.__ID = int(Id)
        self.__Gpa = float(Gpa)

    @property
    def name(self):
        return self.__name

    @property
    def ID(self):
        return self.__ID

    @property
    def Gpa(self):
        return self.__Gpa

class StudentProcessor:
    def __init__(self):
        self.students = []

    def get_info(self):
        name = input("Enter name of student: ")
        Id = int(input("Enter your Id: "))
        Gpa = float(input("Enter your Gpa: "))
        student = Student(name, Id, Gpa)
        self.students.append(student)

    def write_file(self, filename):
    
        with open(filename, "a+", newline='') as file:
            file.seek(0) 
            is_empty = (file.read(1) == "")
            file.seek(0, 2)  # Move cursor back to end before writing

            writer = csv.DictWriter(file, fieldnames=["name", "id", "gpa"])
            if is_empty:
                writer.writeheader()

            for student in self.students:
                writer.writerow({"name": student.name, "id": student.ID, "gpa": student.Gpa})

    def read_csv_file(self, filename):
        print("\nReading from file:")
        with open(filename, "r") as file:
            reader = csv.DictReader(file)
            for row in reader:
                print(f"Name: {row['name']}, ID: {row['id']}, GPA: {row['gpa']}")

    def show_info(self, filename):
        print("\nRaw file content:")
        with open(filename, "r") as f:
            print(f.read())

# Example usage
filename = "Module.csv"
processor = StudentProcessor()
processor.get_info()
processor.write_file(filename)
processor.show_info(filename)
processor.read_csv_file(filename)
