import cs50
from functions import *

print("This is a calculator that will assist you in math. What can I do for you today?")
print("""Select options as follow: <enter number>
    1. addition
    2. subtraction
    3. multiplication
    4. division
    5. squared
    6. squareroot
    7. quadratic equation
    8. quadratic shapes area
    9. circle area
    10. triangle area
    11. quadratic shapes perimeter
    12. triangle perimeter
    13. circle perimeter
    14. Pythagorean theorem
    15. linear equation""")

while True:
    choice = input("enter choice <enter number>: ")
    print("enter 'stop' to stop the program.")
    if choice == 'stop':
        print("Thank you for using this program.")
        break
    else:
        if choice =='1':
            print("enter two numbers for addition.")
            num1 = float(input("enter first number: "))
            num2 = float(input("enter another number to be added: "))
            add(num1, num2)
        elif choice =='2':
            print("enter two numbers for subtraction.")
            num1 = float(input("enter first number: "))
            num2 = float(input("enter another number to be subtracted: "))
            subtract(num1,num2)
        elif choice == '3':
            print("enter two numbers for multiplication.")
            num1 = float(input("enter first number: "))
            num2 = float(input("enter another number to be multiplied: "))
            multiply(num1,num2)
        elif choice == '4':
            print("enter two numbers for division.")
            num1 = float(input("enter first number: "))
            num2 = float(input("enter another number to be divided: "))
            divide(num1,num2)
        elif choice == '5':
            print("enter a base number and a power number.")
            base = float(input("enter the base number: "))
            power = float(input("enter the power number: "))
            p(base,power)
        elif choice == '6':
            print("enter a number for squareroot.")
            num = float(input("enter number: "))
            root(num)
        elif choice == '7':
            print("enter the values of A, b, c from your quadratic equation to find the zeros.")
            a = float(input("enter A value: "))
            b = float(input("enter B value: "))
            c = float(input("enter C value: "))
            qrad(a,b,c)
        elif choice == '8':
            print("enter the length and widith for the area of a qraduatic shape.")
            num1 = float(input("enter length: "))
            num2 = float(input("enter width: "))
            quad_area(num1, num2)
        elif choice == '9':
            print("enter the value of radius for the area of a circle.")
            radius = float(input("enter radius: "))
            circle_area(radius)
        elif choice == '10':
            print("enter the value of base and height for the area of a triangle.")
            base = float(input("enter the base: "))
            height = float(input("enter the height: "))
            tri_area(base, height)
        elif choice == '11':
            print("enter the length and widith for the perimeter of a qraduatic shape.")
            num1 = float(input("enter length: "))
            num2 = float(input("enter width: "))
            quad_perimeter(num1, num2)
        elif choice == '12':
            print("enter the lengths of the triangle for the perimeter.")
            num1 = float(input("enter side 1 length: "))
            num2 = float(input("enter side 2 length: "))
            num3 = float(input("enter side 3 length: "))
            tri_perimeter(num1, num2, num3)
        elif choice == '13':
            print("enter the value of radius for the perimeter of a circle.")
            radius = float(input("enter radius: "))
            circle_perimeter(radius)
        elif choice == '14':
            print("enter the two values of the length of the triangle to find the third length.")
            num1 = float(input("enter side a length: "))
            num2 = float(input("enter side b length: "))
            pytheorm(num1, num2)
        elif choice == '15':
            print("please enter two coordinates to get the linear equation.")
            x1 = float(input("enter x1: "))
            y1 = float(input("enter y1: "))
            x2 = float(input("enter x2: "))
            y2 = float(input("enter y2: "))
            linear(x1,y1,x2,y2)
        else:
            print("Invalid input. please try again.")