import random


#funzione per riconoscere l'appartenenza ad un gruppo
def inviaCodice(parola):
	gruppi = ['GACP', 'DLMT88', 'DjIckar', 'Giosimera', 'Enzotor', 'Darkdj651', 'Vittraff', 'Pedataangelinocastelli']

	trovato = parola in gruppi
	
	if trovato:
		quesito = 'domande/domanda' + str(random.randint(1, 4)) + '.txt'

		#print quesito

		in_file = open(quesito,"r")
		domanda = in_file.read()
		in_file.close()

		
	else:
		domanda = "non appartieni a nessun gruppo"
	
	return domanda
