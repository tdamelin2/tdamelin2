#Six solutions to return 5 if 7 is given and 7 if 5 is given 
def SolutionOne(): 
    x = input("Put A number in: > ")
    y = int(x)
    if y == 5:
        print(7)
    elif y== 7:
        print(5)
    else:
        print("Other Number")
def SolutionTwo():
    x = int(input("Choose a number: > "))
    print(x==5 and 7 or x== 7 and 5 or "Other Number")
def SolutionThree(): 
    x = int(input("Choose a number: > "))
    print (12 -x)
def SolutionFour():
     x = int(input("Choose a number: > "))
     match x:
        case 5:
            print(7)
        case 7:
            print(5)
        case _:
            print("Other Number") 
def SolutionFive(): 
     x = int(input("Choose a number: > "))
     y = ((("Other Number", 5) [x == 7]),7)[x == 5]
     print(y)
def SolutionSix():
    x = int(input("Choose a number: > "))
    while x == 5:
        print(7)
        break
    while x == 7:
        print(5)
        break
    else: 
        print("Other Number")

            



