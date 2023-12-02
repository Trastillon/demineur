#compilation
CC = gcc -Wall -g


#raccourcis des dossiers
srcdir = ./
bindir = ./
docdir = ./
savedir = ./

#raccourcis pour les différents type de fichiers :
#code .c (dossier src)
SRC = $(wildcard $(srcdir)*.c)
#header .h (dossier src)
HEAD = $(wildcard $(srcdir)*.h)
#objet .o (dossier bin)
OBJ = $(subst $(srcdir), $(bindir),$(SRC:.c=.o))
#exectuable (dossier bin)
PROG = $(bindir)run

#raccourcis des commandes :
#clean: supprimer le fichier compilé et les fichers objets
RM = rm -f $(PROG) $(OBJ)
#save: créer des sauvegardes des fichiers sources
CP = cp $(SRC) $(savedir)



#ligne qui va être lancée sans argument
all : $(PROG)

#crée le fichier executable à partir des fichiers .o
$(PROG) : $(OBJ)
	$(CC) $^ -o $@  -lm
	rm -f $(OBJ)

#crée les fichiers .o à partir des fichiers .c et .h
./bin/%.o : ./src/%.c
	$(CC) -c $^ -o $@

#permet de lancer sans erreur
.PHONY : clean
#permet de supprimer le fichier compilé et tous les fichiers objets
clean : 
	$(RM)

#permet de lancer sans erreur
.PHONY : save
#permet de sauvegarder les fichiers sources
save :
	$(CP)
