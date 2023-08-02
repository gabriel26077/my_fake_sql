DATABASES_PATH = $(abspath $(CURDIR)/DATABASES/)



all:
	gcc src\fake_sgbd.c src\repl.c -o bin\a.exe

run: 
	.\bin\a.exe