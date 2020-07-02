#include "aufgabe2_date.h"
#include <stdio.h>
#include <string.h>

typedef enum {
    HUND, KATZE
} tierart;

struct{
    char rasse[100];
    char name[100];
    date geburtstag;
    tierart art;
} typedef tier;

int read_tiere(tier *tiere, int anzahl);
void print_tiere(tier *tiere, int anzahl);
void aeltestes_tier(tier *tiere, int anzahl);
int tierart_einlesen(char* art);
void print_tierart(tierart art);

int main(int argc, char **argv){
    int anzahl = 10;
    tier tiere[anzahl];
    anzahl = read_tiere(tiere, anzahl);
    printf("Alle Tiere:\n");
    print_tiere(tiere, anzahl);
    puts("");
    aeltestes_tier(tiere, anzahl);
}

int read_tiere(tier *tiere, int anzahl){
    char rasse[100];
    char name[100];
    int day;
    int month;
    int year;
    char art[20];

    int i = 0;
    while((scanf("%s %s %i %i %i %s", rasse, name, &day, &month, &year, art) != EOF) && i < anzahl){
        strcpy(tiere[i].rasse, rasse);
        strcpy(tiere[i].name, name);
        tiere[i].geburtstag.day = day;
        tiere[i].geburtstag.month = month;
        tiere[i].geburtstag.year = year;
        tiere[i].art = tierart_einlesen(art); 
        i++;
    }
    return i;
}

void print_tiere(tier *tiere, int anzahl){
    for(int i = 0; i < anzahl; i++){
        printf(" ***********************************************\n"
            " *  %s ist ein ein %s ", tiere[i].name, tiere[i].rasse);
        print_tierart(tiere[i].art); 
        printf(".\n *  Sein/Ihr Geburtstag ist am ");
        print_date(tiere[i].geburtstag);
    }
    printf(" ***********************************************\n");
}

void aeltestes_tier(tier *tiere, int anzahl){
    tier aeltestes = tiere[0];
    for(int i = 1; i < anzahl; i++){
        if( is_before(tiere[i].geburtstag, aeltestes.geburtstag) == -1){
             aeltestes = tiere[i];
        }
    }
    printf("Das älteste Tier ist: \n");
    print_tiere(&aeltestes, 1);
}

int tierart_einlesen(char* art){
    if(strcmp(art, "Katze") == 0) return KATZE;
    return HUND;
}

void print_tierart(tierart art){
    switch (art){
        case KATZE:
            printf("(Katze)");
            break;
        default:
            printf("(Hund)");
    }
}
