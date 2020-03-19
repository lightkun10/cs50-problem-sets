from sys import argv
import re
import csv

if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

str_list = []

"""
Open the CSV file
Inspired by MaxMayo from Discord chat
"""

with open(argv[1], "r") as dnafile:
    # read the file
    reader = csv.reader(dnafile)
    # make a list of designated strs
    str_list = next(reader)[1:] # ignore 1st line
    # make a list of dna's holder
    data_list = list(reader)


"""
Open the TXT(sequences) file
Inpired by Drewon from Discord.
"""
seqfile = open(argv[2], "r")
seqfile = seqfile.read().replace("\n", "")

found_seqs = []

for pattern in str_list:
    itr = 0
    repetition = 0
    highest_reps = 0

    while itr < len(seqfile):
        cur_str = seqfile[itr:len(pattern)+itr]
        
        if pattern == cur_str:
            itr += len(pattern)
            repetition += 1

            if repetition > highest_reps:
                highest_reps = repetition

        else:
            repetition = 0
            itr += 1

    found_seqs.append(highest_reps)

"""
Open the CSV file
inspired by Franciscosta from Discord chat
"""

with open(argv[1], "r") as dnafile:
    reader = csv.reader(dnafile)
    
    # skip the header
    next(reader)

    # Iterate row-by-row
    for row in reader:

        # take each name of row
        names = row[0]

        # remove the header
        row.remove(row[0])

        # convert all string numbers into int
        for i in range(len(row)):
            row[i] = int(row[i])
        
        # compare
        if row == found_seqs:
            print(names)
            exit(0)
    
    print("No match")
