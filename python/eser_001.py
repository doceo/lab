x = input("inserisci un numero: ")
y = input("inserisci un altro numero: ")

stringa_uno = input("inserisci una parola: ")
stringa_due = input("inserisci una seconda parola: ")

print("il più grande dei due è: ")

if x>y:

	print(x)

else:
	print(y)

print("la lunghezza della prima parola è: ")
print (len(stringa_uno))


print("la lunghezza della seconda parola è: ")
print (len(stringa_due))

print("la parola più lunga è:")

if len(stringa_uno)>len(stringa_due):

	print (stringa_uno)

else: 
	print (stringa_due)

