from cs50 import get_string  # get_string and print, with multiple arguments

print('Height: ', end='')  # print what is needed
height = int(input())  # get input from user

while(height > 8 or height < 1):  # while loop
    print("That is an invalid input")  # check invalid input
    print('Height: ', end='')  # ask for input
    height = int(input())  # get input

for i in range(1, height + 1):  # for loop for hashes
    print(" " * (height - i) + "#" * i)  # print hashes

