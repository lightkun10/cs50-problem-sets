import cs50
from sys import argv
import csv

# open("students.db", "w").close() # comment this if writing a file for the first time
db = cs50.SQL("sqlite:///students.db")

# check CLI argument
if len(argv) != 2:
    print("Usage: python import.py data.csv")
    exit(1)

csv_file = argv[1]

# open CSV file
with open(csv_file) as file:

    # create a DictReader
    reader = csv.DictReader(file)

    # Iterate over CSV file
    for row in reader:

        house = row['house']
        birth = row['birth']

        # get each fullname
        full_name = row['name']
        
        # get splitted name
        split_name = full_name.split(" ")
        
        # parse name
        if len(split_name) == 3:
            first = split_name[0]
            middle = split_name[1]
            last = split_name[2]
        else:
            first = split_name[0]
            middle = None
            last = split_name[1]

        # insert to table
        db.execute("INSERT INTO students (house, birth, first, middle, last) VALUES(?, ?, ?, ?, ?)", house, birth, first, middle, last)
