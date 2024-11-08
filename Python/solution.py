

print("Welcome to my Calculator")

while True:
    print("1 for Addition : ")
    print("2 for Subtraction : ")
    print("3 for Division : ")
    print("4 for Multiplication : ")
    print("5 for Terminating : ")

    key = input()
    if key == '5':
        exit()

    print("Enter a number : ")
    a = int(input())
    print("Enter another number : ")
    b = int(input())


    if key == '1':
        print(f"Addition of {a} and {b} is : {a+b}")
    elif key == '2':
        print(f"Subtraction of {a} and {b} is : {a - b}")
    elif key == '3':
        print(f"Division of {a} and {b} is : {a/b}")
    elif key == '4':
        print(f"Multiplication of {a} and {b} is : {a*b}")
    elif key == '5':
        exit()
    else:
        print("Invalid Input")
