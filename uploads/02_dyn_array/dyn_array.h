typedef struct dyn_array {
    /* Die Elemente des Arrays sollen fill_level, length und strings heißen.
     * Wählen Sie geeignete Datentypen! */
} dyn_array;

/* Erstellt ein dyn_array mit Länge 1 und Füllstand 0. */
dyn_array* create();

/* Verdoppelt die Größe des gegebenen Arrays. */
void double_array(dyn_array *arr);

/* Halbiert die Größe des gegebenen Arrays, falls es maximal zur Hälfte gefüllt ist. */
void halve_array(dyn_array *arr);

/* Fügt ein Element am Ende ein und verdoppelt vorher die Arraygröße, falls nötig. */
void add_last(dyn_array *arr, char *string);

/* Entfernt den gegebenen String aus dem Array und schiebt das Array wieder zusammen.
 * Falls möglich soll die Größe des Arrays anschließend halbiert werden. */
void remove_string(dyn_array *arr, char *string);

/* Gibt den gesamten Speicher wieder frei (Ohne Unittests). */
void free_array(dyn_array *arr);

/* Gibt alle Elemente des Arrays aus (Ohne Unittests, bereits implementiert) */
void print_array(dyn_array* arr);

/* Platz für eigene Funktionen
   ... */
