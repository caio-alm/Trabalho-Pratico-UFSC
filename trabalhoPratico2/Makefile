CC = gcc
TARGET = time
SOURCE = ./src
INCLUDE = ./INCLUDE
OBJETOS = ./objs

all: obj
	$(CC) $(OBJETOS)/utils.o $(OBJETOS)/menus.o $(OBJETOS)/cadastro.o $(OBJETOS)/relatorios.o $(OBJETOS)/buscas.o $(OBJETOS)/arquivos_jogadores.o $(OBJETOS)/arquivos_partidas.o $(OBJETOS)/main.o -o $(TARGET)


obj:
	$(CC) -c $(SOURCE)/utils.c -o $(OBJETOS)/utils.o
	$(CC) -c $(SOURCE)/menus.c -o $(OBJETOS)/menus.o
	$(CC) -c $(SOURCE)/cadastro.c -o $(OBJETOS)/cadastro.o
	$(CC) -c $(SOURCE)/relatorios.c -o $(OBJETOS)/relatorios.o
	$(CC) -c $(SOURCE)/buscas.c -o $(OBJETOS)/buscas.o
	$(CC) -c $(SOURCE)/arquivos_jogadores.c -o $(OBJETOS)/arquivos_jogadores.o
	$(CC) -c $(SOURCE)/arquivos_partidas.c -o $(OBJETOS)/arquivos_partidas.o
	$(CC) -c main.c -o $(OBJETOS)/main.o


clear:
	rm $(TARGET)
	rm $(OBJETOS)/*.o
