#include<stdlib.h>
#include"header.h"

// Ich habe die Aufgabe nicht bis Ende gemacht und nicht getestet, weil ich nicht mehr Zeit habe.

int is_before(date a, date b){
	if(a.year > b.year )
		return 1;
	if(a.year < b.year)
		return -1;
	if(a.month > b.month)
		return 1;
	if(a.month < b.month)
		return -1;
	if (a.day > b.month)
		return 1;
	if (a.day < b.month)
		return -1;
	return 0;

}

tier *einfuegen_start(tier* add, tier *start){
	if(start == NULL){
		start = malloc(sizeof(tier));
		return start;
	}
	add =malloc(sizeof(tier));
	start->next = add;
	return add;
}

void speicher_anpassen(tier *entfernen){
	free(entfernen->rasse);
	free(entfernen->name);
	free(entfernen);
}

tier * entfernen(tier * start, char *name){
	tier *aktuell = start;
	tier *prev = NULL;
	while(aktuell!=NULL){
		if(strcmp(aktuell->name, name)==0){
			if(aktuell == start){
				start = start->next;
				speicher_anpassen(aktuell);
				return start;
			}else{
				prev->next = aktuell->next;
				speicher_anpassen(aktuell);
				return start;
			}
		}
		prev = aktuell;
		aktuell = aktuell->next;
	}
	return start;
}

void frei(tier *start){
	tier *aktuell = start;
	tier *neachste =NULL;
	while(aktuell!=NULL){
		neachste= aktuell->next;
		free(aktuell->name);
		free(aktuell->rasse);
		free(aktuell);
		aktuell = neachste;
	}
}

