print ("Snake water game .")
import random
'''
snake = 1 
gun = 0
water = -1
'''
computer = random.choice([1,-1,0])
reversedic = {1 : "snake" , 0  : "gun" , -1 : "water"}
Newone = reversedic[computer]
you = input("Enter your choice : ")
mainDictationary = {  "snake" : 1 ,  "water": -1, "gun" : 0}
print(f"you chose {you} and computer chose {Newone}")
totalDecesion = mainDictationary[you]

if computer == totalDecesion  :
    print("Its draw!")
else :
    if computer == 1 and totalDecesion == 0 :
        print("you win")
    else :
        print("you lose")
    