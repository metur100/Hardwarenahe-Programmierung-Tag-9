typedef struct{
	int day;
	int month;
	int year;
} date;

typedef enum{
	Katze, Hund
}tierart;

typedef struct tier{
	date geburtstag;
	tierart art;
	char *rasse;
	char *name;
	struct tier * next;
}tier;
