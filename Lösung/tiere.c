#include "datenstruktur.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Ich habe die Aufgabe nicht bis Ende gemacht und nicht getestet, weil ich nicht mehr Zeit habe.

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
void print_tiere(tier *tiere);
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
    tier *aktuell = NULL;
    tier *pre= NULL;
    tier *start =NULL;

    while((scanf("%s %s %i %i %i %s", rasse, name, &day, &month, &year, art) != EOF) && anzahl<5 ){
	aktuell = einfuegen_start(aktuell,pre);
	aktuell->name = malloc(sizeof(char)*strlen(name)+1);
	strcpy(aktuell->name, name);
	aktuell->rasse = malloc(sizeof(char)*strlen(rasse)+1);
	strcpy(aktuell->rasse, rasse);
	aktuell-> geburtstag.day = day;
	aktuell-> geburtstag.month = month;
	aktuell-> geburtstag.year = year;
	aktuell-> art = finde_art(art); 
	    if(start == NULL){
		start = aktuell;
	    }
	pre = aktuell;
        anzahl++;
	}
	return anzahl;
}
void print(tier *start){
 	tier *aktuell = start;
 	while(aktuell!=NULL){
        puts("*********************************************");
	 	printf("%s ist ein ein %s (%s) \n" ,aktuell->name,aktuell->rasse,aktuell->name);
        printf("Sein/Ihr Geburtstag ist am %i \n",aktuell->geburtstag.year,aktuell->geburtstag.month,aktuell->geburtstag.day);
        aktuell = aktuell->next;        
        printf("Das nächste Tier in der Liste ist an Adresse:%li\n",aktuell);
        puts("*********************************************");
        }
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
