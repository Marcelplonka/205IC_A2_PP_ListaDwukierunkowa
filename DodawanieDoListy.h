typedef struct Element {
    int value;
    struct Element *next;
    struct Element *prev;
} TypElementu;

int opcje = -1;
int wartosc = -1;


void DodajNaKoniecListy(TypElementu **glowa, int wartosc);

void DodajDoSrodka(TypElementu **glowa, int wartosc, int pozycja);

void DodajNaPoczatekListy(TypElementu **glowa, int wartosc);

//------------------------------------------------------------------------------

void DodajNaPoczatekListy(TypElementu **glowa, int wartosc) {

    if (*glowa == NULL) {
        *glowa = (TypElementu *) malloc(sizeof(TypElementu));
        (*glowa)->value = wartosc;
        (*glowa)->prev = NULL;
        (*glowa)->next = NULL;
    } else {
        TypElementu *obecny;
        obecny = (TypElementu *) malloc(sizeof(TypElementu));
        obecny->value = wartosc;
        obecny->prev = NULL;
        obecny->next = (*glowa);
        (*glowa)->prev = obecny;
        *glowa = obecny;
    }
}

void DodajNaKoniecListy(TypElementu **glowa, int wartosc) {

    if (*glowa == NULL) {
        *glowa = (TypElementu *) malloc(sizeof(TypElementu));
        (*glowa)->value = wartosc;
        (*glowa)->prev = NULL;
        (*glowa)->next = NULL;
    } else {
        TypElementu *obecny = *glowa;
        TypElementu *nowyElement;

        while (obecny->next != NULL) {
            obecny = obecny->next;
        }

        obecny->next = (TypElementu *) malloc(sizeof(TypElementu));
        obecny->next->value = wartosc;
        obecny->next->prev = obecny;
        obecny->next->next = NULL;
    }
}

void DodajDoSrodka(TypElementu **glowa, int wartosc, int pozycja) {

    if (pozycja == 0) DodajNaPoczatekListy(glowa, wartosc);
    else {
        if (pozycja == rozmiarListy(*glowa)) DodajNaKoniecListy(glowa, wartosc);
        else {
            TypElementu *obecny = *glowa;

            int i = 0;
            while (obecny->next != NULL && i < pozycja - 1) {
                obecny = obecny->next;
                i++;
            }

            obecny->next->value = wartosc;
            obecny->next->prev = obecny;
            obecny->next->next = obecny->next;

        }
    }
}