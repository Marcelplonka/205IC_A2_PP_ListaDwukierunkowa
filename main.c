#include <stdio.h>
#include <stdlib.h>
#include "DodawanieDoListy.h"
#include "WypisywanieListy.h"
#include "UsuwanieZListy.h"

int main() {

    TypElementu *glowa;
    glowa = (TypElementu *) malloc(sizeof(TypElementu));
    glowa = NULL;

    int index = -1;


    while (opcje != 0) {

        printf("\nAktualny stan listy: ");
        WypiszOdPoczatku(glowa);

        printf("\n\nCo chcesz zrobic?\n");
        printf("1. Dodac element na poczatek listy.\n");
        printf("2. Dodac element na koniec listy.\n");
        printf("3. Dodac element do srodka.\n");
        printf("4. Usunac element.\n");
        printf("5. Wyswietlic liste w odwrotnej kolejnosci.\n");
        printf("0. Zakonczyc program.\n");


        scanf("%i", &opcje);

        switch (opcje) {
            case 0:
                return 0;

            case 1:
                printf("Wpisz liczbe: ");
                scanf("%i", &wartosc);
                DodajNaPoczatekListy(&glowa, wartosc);
                break;
            case 2:
                printf("Wpisz liczbe: ");
                scanf("%i", &wartosc);
                DodajNaKoniecListy(&glowa, wartosc);
                break;
            case 3:
                printf("Wpisz liczbe: ");
                scanf("%i", &wartosc);
                printf("\nWpisz index po ktorym liczba ma zostac dodana: ");
                scanf("%i", &index);
                DodajDoSrodka(&glowa, wartosc, index);
                break;
            case 4:
                printf("Wpisz indeks elementu ktorego chcesz sie pozbyc: ");
                scanf("%i", &index);
                UsunZListy(&glowa, wartosc, index);
                break;

            case 5:
                WypiszOdKonca(glowa);
                break;

            default:
                printf("Podaj wlasciwa opcje.");
                break;

        }

    }


    return 0;
}