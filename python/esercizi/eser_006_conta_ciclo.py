#input di una stringa
primo = int(input("inserisci il primo numero: "))
secondo = int(input("inserisci il secondo numero: "))


if primo>secondo:
	comodo = primo
	primo = secondo
	secondo = comodo

#ciclo di while

i = primo

while i<=secondo:
	
	print("il valore è:", i)
	i = i + 1
	
