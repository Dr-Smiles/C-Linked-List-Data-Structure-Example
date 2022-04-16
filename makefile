hepsi: program calistir

program: derle
	gcc ./lib/main.o ./lib/Kisi.o ./lib/Oyun.o ./lib/Dosya.o ./lib/ConsolePrinter.o -o ./bin/sonuc

derle:
	gcc -I "./include" -c ./src/main.c -o ./lib/main.o
	gcc -I "./include" -c ./src/Kisi.c -o ./lib/Kisi.o
	gcc -I "./include" -c ./src/Oyun.c -o ./lib/Oyun.o
	gcc -I "./include" -c ./src/Dosya.c -o ./lib/Dosya.o
	gcc -I "./include" -c ./src/ConsolePrinter.c -o ./lib/ConsolePrinter.o

calistir:
	./bin/sonuc.exe