while True:
    try:
        height = int(input("Enter size: "))
    except ValueError:
        pass # continue
    else:
        break # finish handling exceptions

while height < 1 or height > 8:
    height = int(input("Enter size: "))

for row in range(height):
    for col in range(height - 1 - row):
        print(" ", end="")
    for hash in range(0 + row + 1):
        print("#", end="")
    print()