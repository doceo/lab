#acquisisco input di tipo numerico
x = input("inserisci un numero: ")
y = input("inserisci un altro numero: ")


if x>y:

#trasformo un valore numerico generico in un numero intero tramite la funzione int()
	max = int(x) 
	print(x)

else:
	max = int(y)
	print(y)

#prima di restituire in output un valore numerico lo devo convertire in stringa tramite la funzione str()

print("il più grande dei due è: ", str(max))


#somma di tutti i numeri antecedenti al più grande dei due

somma = 0
i = 0

while i<= max:
	somma = somma + i
	i = i + 1
print ("La somma dei numeri da 1 a " , str(max), " è ", (somma))

