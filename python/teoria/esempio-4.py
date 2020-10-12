#python3
a = float(input("inserisci il dividendo: "))
b = float(input("inserisci il divisore": ))

risultato = a/b
resto = a%b

if resto !=0:
    print(a, " diviso ", b, " risulta ", risultato)
    print(a," non è divisibile per ",b," e il resto è", resto)
else:
    print(a, " diviso ", b, " risulta ", risultato)
    print(a," non è divisibile per ",b," e il resto è", resto)

print("fine programma")