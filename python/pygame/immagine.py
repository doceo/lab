import pygame

# bisogna inizializzare la libreria
pygame.init()

dimensione_schermo = (800,600)

# si deve costruire un oggetto finestra
finestra = pygame.display.set_mode(dimensione_schermo)
superficie = pygame.display.get_surface()
pygame.display.set_caption("titolo del gioco")


