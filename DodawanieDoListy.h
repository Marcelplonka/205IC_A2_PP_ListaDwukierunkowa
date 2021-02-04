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

void WypiszOdPoczatku(TypElementu *glowa);

void WypiszOdKonca(TypElementu *glowa);

int rozmiarListy(TypElementu *glowa);

void UsunZListy(TypElementu **glowa, int wartosc, int pozycja);


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

//------------------------------------------------------------------------------

void WypiszOdPoczatku(TypElementu *glowa) {
    printf("\n");
    if (glowa == NULL) printf("Lista jest pusta");
    else {
        TypElementu *obecny = glowa;
        do {
            printf(" %i", obecny->value);
            obecny = obecny->next;
        } while (obecny != NULL);
    }
}

void WypiszOdKonca(TypElementu *glowa) {
    printf("\n");
    if (glowa == NULL) printf("Lista jest pusta");
    else {
        TypElementu *obecny = glowa;
        while (obecny->next != NULL) {
            obecny = obecny->next;
        }


        do {
            printf("%i", obecny->value);
            printf("\n");
            obecny = obecny->prev;
        } while (obecny != NULL);

    }
}


int rozmiarListy(TypElementu *glowa) {
    int obecny = 0;
    if (glowa == NULL) return obecny;
    else {
        TypElementu *obecny = glowa;
        do {
            obecny++;
            obecny = obecny->next;
        } while (obecny != NULL);
    }
    return obecny;
}

//------------------------------------------------------------------------------

void UsunZListy(TypElementu **glowa, int wartosc, int pozycja) {

    if (pozycja == 1) {
        if (*glowa != NULL) {
            if ((*glowa)->next == NULL) {
                *glowa = NULL;
            } else {
                TypElementu *tmp;
                tmp = (*glowa)->next;
                free(*glowa);
                *glowa = tmp;
                (*glowa)->prev = NULL;
            }

        } else {

            TypElementu *obecny = *glowa;
            while (obecny->next->next != NULL) {
                obecny = obecny->next;
            }
            free(obecny->next);
            obecny->next = NULL;
        }

    } else {
        TypElementu *obecny = *glowa;
        TypElementu *tmp;

        int i = 0;
        while (obecny->next != NULL && i < pozycja) {
            obecny = obecny->next;
            i++;
        }

        tmp = obecny->next;
        obecny->next = tmp->next;
        obecny->next->prev = obecny;
        free(tmp);
    }
}