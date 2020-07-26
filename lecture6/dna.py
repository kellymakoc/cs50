from csv import reader, DictReader
from sys import argv

if len(argv) < 3:  # if arugement command line is less than 3
    print("Usage: python dna.py data.csv sequence.txt \n")  # print
    exit()  # exit program

with open(argv[2]) as dnafile:  # open dna file
    dnareader = reader(dnafile)  # read the sequences from the dna file
    for row in dnareader:  # read every row in the sequences
        dnalist = row;  # make a list of the rows

dna = dnalist [0]  # dna is assigned to index 0 in the array
sequences = {}  # sequence is assigned to index 0 in the array

with open(argv[1]) as peoplefile:  # open the sequences file from database in to a list
    people = reader(peoplefile)  # read the file
    for row in people:
        dnaSequences = row  # dna sequence is the row in the file
        dnaSequences.pop(0)
        break
# for the sequence in the dictionary
for item in dnaSequences:
    sequences[item] = 1

for key in sequences:  # iterate the dna sequence to find repeated sequences
    k = len(key)
    mtemp = 0
    temp = 0
    for i in range (len(dna)):  # after counted sequence it skip to the end to avoid multiply counting
        while temp > 0:
            temp -= 1
            continue

        if dna[i: i + k] == key:  # assume a certain sequence is the key
            while dna[i - k: i] == dna[i: i + k]:  # if another sequence is the same as the "key" sequence
                temp += 1  # add 1
                i += k  # add to k

            if temp > mtemp:  # if temp is greater than the max
                mtemp = temp  # max will be the value of temp
    sequences[key] += mtemp  # find the index value in the array as the max value

with open(argv[1], newline = '') as peoplefile:  # open database of the people
    people = DictReader(peoplefile)  # people are the names in the dictionary
    for person in people: # go thru all the people
        match = 0
        for dna in sequences:  # and compare the sequences of the key and theirs
            if sequences[dna] == int(person[dna]):  # if the sequences match
                match += 1  # add 1 to match
        if match == len(sequences):  # if the value of match is equal to the index order of sequences
            print(person['name'])  # print the name of the person
            exit()  # exit program

    print("No match")  # else print no match