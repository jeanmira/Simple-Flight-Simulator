#------------------------------- /usr/bin/g++-7 -------------------------------#
#------------------------------- coding: utf-8 --------------------------------#
# Criado por: Jean Marcelo Mira Junior
# Versão: 1.1
# Criado em: 8/10/2020
# Sistema operacional: Linux - Ubuntu 20.04.1 LTS
# Objetivo: estabelecer um padrão de Makefile para a disciplina de programação 3
#------------------------------------------------------------------------------#

# Copilador
CC = g++ -std=c++17

# Flags de copilacao
FLAGS	= -W -Wall -pedantic -Wextra -Werror

# Variaveis do tipo execultavel
O = *.o

#Nome do execultavel
EXE = exe

# Comando para limpar arquivo
RM = rm -rf

# Comando para pegar todos os .cpp da pasta do Makefile
APPNAME = $(wildcard *.cpp)

# Copila e execulta o programa e depois apaga todos os arquivos .o e o
# execultavel criado
all: run clean

# Limpa o terminal de verdade
limpa:
	tput reset

# Copila e execulta o programa
run:
	$(CC) $(FLAGS) -c $(APPNAME)
	$(CC) $(FLAGS) -o $(EXE) $(O)
	./$(EXE)

# Apaga todos os arquivos .o e o execultavel criado
clean:
	$(RM) $(O)
	$(RM) $(EXE)

.PHONY: all clean
#------------------------------------------------------------------------------#