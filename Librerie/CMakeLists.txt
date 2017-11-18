#include_directories()
set(LIBRERIE_SRC #Non sono riuscito a farlo funzionare...
    libreria_principale.c
    libreria_principale.h
)
add_library(Librerie STATIC libreria_principale.c libreria_principale.h File.h File.c) #aggiungere i file src delle varie librerie