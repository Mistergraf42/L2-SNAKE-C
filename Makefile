CC=gcc
OPTIONS= -W -Wall -std=c89 -pedantic -O3 `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV`
O=`pkg-config --libs-only-l MLV`

snake: main.o menu.o affichage_graphique.o recup_click.o deplacement.o map.o solo.o saves.o menu_options.o
	$(CC) $(OPTIONS) main.o menu.o affichage_graphique.o recup_click.o deplacement.o map.o solo.o saves.o menu_options.o $(O) -o snake

main.o: sources/main.c
	$(CC) $(OPTIONS) -c sources/main.c

menu.o: sources/menu.c heads/affichage_graphique.h
	$(CC) $(OPTIONS) -c sources/menu.c

affichage_graphique.o: sources/affichage_graphique.c heads/affichage_graphique.h
	$(CC) $(OPTIONS) -c sources/affichage_graphique.c

recup_click.o: sources/recup_click.c heads/recup_click.h
	$(CC) $(OPTIONS) -c sources/recup_click.c

deplacement.o: sources/deplacement.c heads/deplacement.h
	$(CC) $(OPTIONS) -c sources/deplacement.c

map.o: sources/map.c heads/map.h
	$(CC) $(OPTIONS) -c sources/map.c

solo.o: sources/solo.c heads/solo.h
	$(CC) $(OPTIONS) -c sources/solo.c

saves.o: sources/saves.c heads/saves.h
	$(CC) $(OPTIONS) -c sources/saves.c

menu_options.o: sources/menu_options.c heads/menu_options.h
	$(CC) $(OPTIONS) -c sources/menu_options.c

clean :
	rm -rf *.o *~ snake




