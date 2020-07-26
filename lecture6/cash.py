# get_float and print, with multiple arguments
from cs50 import get_float

def main():  # set function
    while True:  # while it is true 
        change = get_float("enter change: ")  # get input from user 
        if change > 0:  # break if input is greter than 0 
            break
    count = 0  # variable for numbers of coins 
    if change > 0:  # if change is greater than 0
        while change >= 0.25:  # while change is greater than 0.25 
            change -= 0.25  # subtract from 0.25
            count += 1  # add one to the count 
    
        while change >= 0.10:  # while change is greater than 0.10 
            change -= 0.10  # subtract from 0.10
            count += 1  # add one to the count 
    
        while change > 0.04:  # while change is greater than 0.05 
            change -= 0.05  # subtract from 0.05
            count += 1  # add one to the count 
    
        while change < 0.05 and change >= 0.01:  # while change is greater than 0.01 
            change -= 0.01  # subtract from 0.01
            count += 1  # add one to the count 
        print(count)  # print the numbers of coins 
    else:
        print(count)  #print count 

if __name__ == "__main__":  # state function 
    main()  # return to main 

