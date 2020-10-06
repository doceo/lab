#acquisisco input di tipo numerico e lo converto direttamente in intero
x = int(input("inserisci un numero: "))
y = int(input("inserisci un altro numero: "))



multiplo_x = x
multiplo_y = y

while multiplo_x != multiplo_y:

	if multiplo_x < multiplo_y:
		multiplo_x = multiplo_x + x
	
	else:
		multiplo_y = multiplo_y + y

mcm = multiplo_x

print("il mcm tra",str(x),"e",str(y), "è", str(mcm))

