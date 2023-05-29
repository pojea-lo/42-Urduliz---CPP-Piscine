import  random2
import  sys

try:
    num = int(input("Por favor, introduce una cantidad de números: "))

    numeros = list(range(1, num))
    random2.shuffle(numeros)

    for i in numeros:
        print (i, "", end=' ')
    print("")

except:
    print ("Adminto solo números")