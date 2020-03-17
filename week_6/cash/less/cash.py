owed = 0
quarter = 25
dime = 10
nickel = 5
penny = 1

while True:
    try:
        dollars = float(input("Enter change owed: "))
    except ValueError:
        pass
    else:
        break

while dollars < 0.00:
    dollars = float(input("Enter change owed: "))

coins = round(dollars * 100)

while coins >= quarter:
    coins = coins - quarter
    owed += 1

while coins >= dime:
    coins = coins - dime
    owed += 1

while coins >= nickel:
    coins = coins - nickel
    owed += 1

while coins >= penny:
    coins = coins - penny
    owed += 1

print(owed)