# Hardwarenahe-Programmierung-Tag-9
Es ist soweit: In dieser Ubung nutzen Sie dynamische Speicherverwaltung in C! AuÃŸerderm Â¨ verwenden Sie valgrind, um Ihre Programme auf Speicherlecks zu untersuchen.

# Aufgabe 1 Tier-Daten II

Versuchen Sie bei der Losung dieser Aufgabe m¨oglichst viele Funktionen von Tag 8 wieder zu
verwenden. Passen Sie dabei die Datenstruktur und die Funktionen, die Sie an Tag 8 geschrieben
haben, geeignet an.

(a) Erweitern Sie Ihre Datenstruktur von Tag 8 so, dass Sie Tiere in einer verketteten Liste
speichern konnen.

(b) Schreiben Sie folgende Funktionen fur das Einfugen von Tieren in eine Liste:
• Eine Funktion einfuegen ende, die den Start einer Tier-Liste und ein neues Tier
erh¨alt und die das Tier ans Ende der Liste anhangt.
• Eine Funktion einfuegen start, die den Start einer Tier-Liste und ein neues Tier
erh¨alt und die das Tier an den Start der Liste einfugt.
• Eine Funktion einfuegen index, die den Start einer Tier-Liste, ein neues Tier sowie
eine Index-Position i erhalt, und die das Tier an Position i der Liste einfugt. Dabei
ist 0 der Index der ersten Listenposition. Falls der ubergebene Index zu klein/groß
fur die Liste ist, soll an die erste/letzte Listenposition eingefugt werden.

(c) Andern Sie die Funktionen read tiere und print tiere so ab, dass diese mit einer Liste
von Tieren statt einem Array von Tieren arbeiten.
(d) Schreiben Sie ein Hauptprogramm, das mithilfe Ihrer Losungen der vorherigen Teilaufgaben eine verkettete Liste mit 5 (oder mehr) Tieren aus einer Eingabe (z.B. Datei) erzeugt
und die Liste anschließend auf der Konsole ausgibt.
(e) Schreiben Sie eine Funktion, die den Start einer Liste von Tieren und einen Namen
ubergeben bekommt, und die das erste Tier mit diesem Namen aus der Liste entfernt
und l¨oscht.
(f) Schreiben Sie eine Funktion, die eine Tier-Liste als Eingabe erhalt und den Speicher der
gesamten Liste wieder freigibt.

(g) Erweitern Sie Ihr Hauptprogramm: fugen Sie nach dem Einlesen der Tiere Befehle hinzu,
um drei der Tiere wieder aus der Liste zu entfernen. Demonstrieren Sie dabei das L¨oschen
des ersten Elements der Liste, des letzten Elements der Liste, und eines Elements im
Innern der Liste.

(h) Uberprufen Sie Ihr Programm mir valgrind. valgrind darf keine Fehlerquellen melden.
Das heißt mindestens: Der komplette allozierte Speicher muss bei Beendigung des Programms wieder freigegeben sein. Es darf keine als possibly oder definitely lost markierten
Speicherbereiche und keine invalid reads oder invalid writes geben.

# Aufgabe 2 Dynamisches Array

In dieser Aufgabe sollen Sie eine Datenstruktur erstellen, die ein String-Array mit dynamischer
Kapazit¨at implementiert. Der Speicher fur die Strings muss dazu dynamisch alloziert werden.
Achten Sie auf eine sorgf¨altige Speicherverwaltung und auf die Erfullung aller Unittests!

(a) Definieren Sie in der Datei dyn array.h die Datenstruktur dyn array mit den Feldern length (Große des Arrays), fill level (Fullstand des Arrays) und strings (das StringArray selbst). Wahlen Sie fur die Felder geeignete Datentypen.

(b) Implementieren Sie die in dyn array.h vorgegebenen Funktionsprototypen und prufen Sie
Ihre Implementierungen mit den vorgegebenen Unittests.
(c) Uberprufen Sie Ihr Programm mit valgrind (wie bei Aufgabe 1).
