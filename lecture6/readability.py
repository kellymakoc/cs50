# get_string and print, with multiple arguments
from cs50 import get_string

# def main():
text = get_string("text: ")  # get input from user
letter = 0  # number of letters
word = 0  # number of words
sen = 0  # number of sentences
t = len(text)  # change to array
for i in range(t):  # for loop. loop in each element in the array
    if text[i].isalnum() == True:  # if it is a letter
        letter += 1  # add one to letter for count

for i in range(t):  # for loop. loop in each element in the array
    if text[i].isspace() == True and text[i+1].isalnum() == True:  # if (text[i] == ' ') or (text[i + 1].isalnum()):
        word += 1  # add one to word for count

for i in range(t):  # for loop. loop in each element in the array
    if text[i] == "?" or text[i] == "." or text[i] == "!":  # if (text[i] == '?') or (text[i] == '.') or (text[i] == '!'):
        sen += 1  # add one to sen for count

L = (letter / word) * 100  # calculation for letter per 100 words
S = (sen / word) * 100  # calculation for sentences per 100 words
grade = (0.0588 * L) - (0.296 * S) - 15.8  # calculation for determination which grade level

if grade < 1:  # if grade is less than 1
    print("Before Grade 1")  # print
elif grade < 16:  # if grade is less than 16
    print("Grade", round(grade))  # print
else:  # else
    print("Grade 16+")  # print

# if __name__ == "__main__":
 #   main()