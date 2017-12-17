import random

import string

def inviaCodice(parola):
        gruppi = ['GACP', 'DLMT88', 'DjIckar', 'Giosimera', 'Enzotor', 'Darkdj651']

        trovato = parola in gruppi

        if trovato:
                domanda = random.randint(1, 3)
        else:
                domanda = -1

        return domanda



r=inviaCodice('GACP')

quesito = 'domande/domanda' + str(r) + '.txt'

print quesito

in_file = open(quesito,"r")
text = in_file.read()
in_file.close()

print r 
print '\n'
print text