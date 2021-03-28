def funktion(x):
    if x > 0:
        if x % 4 == 0:
            funktion(x - 1)
            print('x', end = " ")
        else:
            print('y', end = " ")
            funktion(x//3)

print(funktion(26))