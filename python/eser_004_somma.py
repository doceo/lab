#acquisisco input di tipo numerico e lo converto direttamente in intero
x = int(input("inserisci un numero: "))
y = int(input("inserisci un altro numero: "))


if x>y:

	max = x 
else:
	max = y

#prima di restituire in output un valore numerico lo devo convertire in stringa tramite la funzione str()

print("il più grande dei due è:", str(max))


#somma di tutti i numeri antecedenti al più grande dei due

somma = 0
i = 0

while i<= max:
	somma = somma + i
	i = i + 1
	
	print("somma = somma + i ->", somma)
	print("i = i + 1 ->", i)
		
print ("La somma dei numeri da 1 a" , str(max), "è", str(somma))

