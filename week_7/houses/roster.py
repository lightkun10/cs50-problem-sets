from cs50 import SQL
from sys import argv
import csv

# open("students.db", "w").close()
db = SQL("sqlite:///students.db")

# check CLI argument
if len(argv) != 2:
    print("Usage: python import.py house")
    exit(1)

house_inpt = argv[1]

result = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", house_inpt)

for res in result:
    if res['middle'] == None:
        full_name = f"{res['first']} {res['last']}"
        birth = f", born {res['birth']}"
        print(full_name + birth)
    else:
        full_name = f"{res['first']} {res['middle']} {res['last']}"
        birth = f", born {res['birth']}"
        print(full_name + birth)
