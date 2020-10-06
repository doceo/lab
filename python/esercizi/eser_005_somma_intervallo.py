#acquisisco input di tipo numerico e lo converto direttamente in intero
x = int(input("inserisci un numero: "))
y = int(input("inserisci un altro numero: "))


if x>y:

	max = x 
	min = y
else:
	max = y
	min = x

#prima di restituire in output un valore numerico lo devo convertire in stringa tramite la funzione str()

print("il più grande dei due è", str(max), ", il più piccolo è", str(min))


#somma di tutti i numeri antecedenti al più grande dei due

somma = 0
i = 0

while i<= max:
	print("i è", str(i), "somma è", str(somma))
	somma = somma + i
	i = i + 1
	
print ("La somma dei numeri da 1 a" , str(max), "è", str(somma))

#sommiamo invece i numeri compresi nell'intervallo tra X e Y

somma = min
i = min

while i<= max:
	print("i è", str(i), "somma è", str(somma))
	somma = somma + i
	i = i + 1
	
print ("La somma dei numeri da ",str(min), "e" , str(max), "è", str(somma))



