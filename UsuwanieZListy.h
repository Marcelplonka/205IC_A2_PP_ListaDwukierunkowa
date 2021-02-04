void UsunZListy(TypElementu **glowa, int wartosc, int pozycja);

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
