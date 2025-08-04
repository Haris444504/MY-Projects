# Fake use generator 

import random

print("----------------Fake new Genrator--------------------")

Subject = ["Haris" , "Hamad" , "Musfira" , "Saad" , "Arham"]
actions = ["Eating grass" , "scrolling" , "telling the truth" , "writing homework"]
places = ["In bathroom" , "On solar plates" , "In Almira" , "In the pool"]

while True :
    subject = random.choice(Subject)
    Actions = random.choice(actions)
    Places = random.choice(places)

    headline = f"BREAKING NEWS : {subject}  {Actions}  {Places}"
    print("\n",headline ,"\n")
    user_Input = input("Do you want to generate another headline (yes/no) : ").strip().lower()

    if user_Input == "yes" :
        continue
    elif user_Input == "no" :
        print("--------------------------------Exiting----------------------")
        break

    else :
        print("Invalid choice .")
        
