#hw1
#Applied by:
Noga Anaby 318298296
Shahar Amshili 308054337


gcc main.c -o main
gcc Car.c -ansi -Wall -pedantic-errors -lm -o car

gcc -g  Client.c -o client_c
gcc -g  Utils.c -o Utils_c
gcc -g main.c -o main

gcc -g  Utils.h -o utils
gcc Client.c Utils.c Car.c main.c -o main
gcc -g Client.c Utils.c main.c -o main
"fix include all include are in file = > Utils.h , other file's dont have include for ext lib"
