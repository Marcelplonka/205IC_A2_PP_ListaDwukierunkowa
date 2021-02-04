void WypiszOdPoczatku(TypElementu *glowa);

void WypiszOdKonca(TypElementu *glowa);

int rozmiarListy(TypElementu *glowa);

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
            printf(" %i", obecny->value);
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



