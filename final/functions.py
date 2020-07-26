import cs50
import math

def add(num1,num2):
    result = round(num1 + num2,2)
    print("{0} + {1} = {2}".format(num1,num2, result))

def subtract(num1,num2):
    result = round(num1 - num2,2)
    print("{0} - {1} = {2}".format(num1,num2, result))

def multiply(num1,num2):
    result = round(num1 * num2,2)
    print("{0} * {1} = {2}".format(num1,num2, result))

def divide(num1,num2):
    if num2 == 0.0:
        print("cannot be divided by 0.")
    else:
        result = round(num1 / num2,2)
        print("{0} / {1} = {2}".format(num1,num2, result))

def p(base,power):
    result = round(pow(base,power),2)
    print("{0}^{1} = {2}".format(base,power,result))

def root (num):
    result = round(math.sqrt(num),2)
    print("√{0} = {1}".format(num, result))

def qrad(a,b,c):
    if a == 0.0:
        print("cannot be divided by zero")
    else:
        bsq =pow(b,2)
        ac = 4*a*c
        if (bsq-ac) < 0.0:
            print("invalid")
        else:
            dis = math.sqrt(bsq-ac)
            negb = b*-1
            denom = 2*a
            result1 = round((negb + dis) / denom,2)
            result2 = round((negb - dis) / denom,2)
            print("({0} + √{1}-{2})/{3} = {4}".format(negb, bsq, ac, denom, result1))
            print("another result: ({0} - √{1}-{2})/{3} = {4}".format(negb,bsq,ac,denom,result2))

def linear(x1, y1, x2, y2):
    if x1 ==x2:
        print("invalid")
    else:
        m = round((y2-y1) / (x2-x1), 2)
        b = round(y2-(m*x2), 2)
        print("The linear equation is y =", m, "x+", b)

def quad_area(num1,num2):
    result = round(num1*num2,2)
    print("{0} * {1} = {2}".format(num1,num2, result))

def circle_area(radius):
    result = round(math.pi*(radius*radius),2)
    print("{0} * ({1} * {2}) = {3}".format(math.pi,radius,radius, result))

def tri_area(base, height):
    result = round((base*height)/2,2)
    print("({0} * {1}) / 2 = {2}".format(base,height, result))

def quad_perimeter(num1,num2):
    result = round((num1 + num2)*2,2)
    print("({0} + {1}) * 2 = {2}".format(num1,num2, result))

def tri_perimeter(num1,num2,num3):
    result = round(num1+num2+num3,2)
    print("{0} + {1} + {2} = {3}".format(num1, num2, num3, result))

def circle_perimeter(radius):
    result = round(math.pi*radius*2,2)
    print("{0} * {1}^2 = {3}".format(math.pi, radius, result))

def pytheorm(num1,num2):
    if num1 == 0.0 or num2 == 0.0:
        print("invalid input")
    else:
        result = round(math.sqrt((pow(num1,2)*pow(num2,2))),2)
        print("√{0}^2 + {2}^2 = {3}".format(num1,num2,result))