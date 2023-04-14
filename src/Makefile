PROJ_NAME=ted

ALUNO=geraldoasn
LIBS= -lm
OBJETOS=text.h text.c circle.h circle.c rect.h rect.c line.h line.c objects.h path.h path.c archive.h archive.c fila.h fila.c lista.h lista.c structures.h qry.h qry.c svg.h svg.c geo.h geo.c main.c

# compilador
CC=gcc

# Flags
CFLAGS= -ggdb -O0 -std=c99 -fstack-protector-all -Werror=implicit-function-declaration
LDFLAGS=-O0

$(PROJ_NAME): $(OBJETOS)
	$(CC) -o $(PROJ_NAME)$(LDFLAGS)  $(OBJETOS) $(LIBS)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

#
# COLOCAR DEPENDENCIAS DE CADA MODULO
#
# Exemplo: suponha que o arquivo a.c possua os seguintes includes:
#
#   #include "a.h"
#   #include "b.h"
#   #include "c.h"
# 
# a.o: a.h b.h c.h a.c


#
# EMPACOTAR PARA ENTREGA
#
#   -  se necessario: sudo apt install zip

pack: $(PROJ_NAME)
	rm -f ../$(ALUNO).zip
	echo $(ALUNO)
	date >> .entrega
	cd ..; zip $(ALUNO).zip -r src/*.c src/*.h src/Makefile LEIA-ME.txt .entrega

clr:
	rm -f *.o $(PROJ_NAME) *~
	rm -f ../$(ALUNO).zip
	clear	