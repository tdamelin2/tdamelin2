import random 
import time
from NumDict import *

def NumCheckOne(self): 
    if self < 1 or self > 100:
        print("CHOOSE A NUMBER BETWEEN 1 AND 100")
    else:
        Misc["X"] = 1

def NumConfirmation(self): 
    if self == number["Main"]:
        print('Your number is {}'.format(Guess["Main"]))
        print("Thanks for Playing")
        exit()

def Lower(self):
    if self == "L":
        Guess["Back"] = Guess["High"] 
        Guess["High"] = Guess["Main"]
        if number["Main"] > Guess["Main"]:
            print("DON'T LIE")
            Guess["High"] = Guess["Back"]
    

def Higher(self):
    if self == "H":
        Guess["Back"] = Guess["Low"]
        Guess["Low"] = Guess["Main"]
        if number["Main"] < Guess["Main"]:
            Guess["Low"] = Guess["Back"]
            print("DON'T LIE")

while Misc["X"] == 0:
    try:
     number["Main"] = int(input("Choose a number between 1 and 100: > "))    
     NumCheckOne(number["Main"])  
    except ValueError: 
        print("CHOOSE A NUMBER")

while Misc["X"] == 1: 
    Guess["Main"] = random.randint(Guess["Low"], Guess["High"])
    print("Computer Guess: {}".format(Guess["Main"]))
    NumConfirmation(Guess["Main"])
    HL = " "
    HL = input("Is your Number Higher(H) or Lower(L): > ")
    Lower(HL)
    Higher(HL)