import random
import string
print("\t\t\t\tWellcome to charater guessing Game : ")
number = random.choice(string.ascii_lowercase)
attempt = 0
while True :
    guess = str(input("Enter a number : "))
    attempt += 1
    if guess < number :
         print("Too Low ! Try again")
    elif guess > number :
         print("Too High! Try again")
    else :
         print("Congratation you guess a correct Letter : ",guess,"in attempts : " , attempt)
         break
