#include<stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dyn_array.h"

/* Erstellt ein dyn_array mit Länge 1 und Füllstand 0. */
dyn_array* create(){
    dyn_array* a = malloc(sizeof(dyn_array));
    a->length =1;
    a->fill_level =0;
    a->strings = malloc(sizeof(char*)*a->length);
    return a;
}

/* Verdoppelt die Größe des gegebenen Arrays. */
void double_array(dyn_array *arr){
    arr->length *=2;   
    arr->strings = realloc(arr->strings,(sizeof(char*)*arr->length));
}

/* Halbiert die Größe des gegebenen Arrays, falls es maximal zur Hälfte gefüllt ist. */
void halve_array(dyn_array *arr){
    if(arr->fill_level<=arr->length/2 && arr->length >1){
        arr->length /=2;
        arr->strings = realloc(arr->strings,(sizeof(char*)*arr->length));
    }
}

/* Fügt ein Element am Ende ein und verdoppelt vorher die Arraygröße, falls nötig. */
void add_last(dyn_array *arr, char *string){
    if(arr->length == arr->fill_level){
        double_array(arr);
    }
    arr->strings[arr->fill_level]= malloc(sizeof(char)*strlen(string)+1);
    strcpy(arr->strings[arr->fill_level],string);
    arr->fill_level +=1;
}

/* Entfernt den gegebenen String aus dem Array und schiebt das Array wieder zusammen.
 * Falls möglich soll die Größe des Arrays anschließend halbiert werden. */
void remove_string(dyn_array *arr, char *string){
    for(int i =0; i< arr->fill_level; i++){
        if(strcmp(arr->strings[i],string) == 0){
            
            for(int j =i+1; j< arr->fill_level; j++){
                strcpy(arr->strings[j-1] , arr->strings[j]);
            }
            break;
        }
    }
    arr->fill_level-=1;
    halve_array(arr);
}

/* Gibt den gesamten Speicher wieder frei (Ohne Unittests). */
void free_array(dyn_array *arr){
    for(int i =0; i<arr->fill_level; i++){
        free(arr->strings[i]);
    }
    free(arr->strings);
    free(arr);
}

/* Gibt alle Elemente des Arrays aus (Ohne Unittests, bereits implementiert) */
void print_array(dyn_array* arr){
	int i;

	printf("**** Arraystatus ****\n");
	printf("Länge: %i\n", arr->length);
	printf("Füllstand: %i\n", arr->fill_level);

	for(i = 0; i < arr->fill_level; i++) {
		printf("[%i]: %s\n", i, arr->strings[i]);
	}
}

/* Platz für eigene Funktionen
   ... */
