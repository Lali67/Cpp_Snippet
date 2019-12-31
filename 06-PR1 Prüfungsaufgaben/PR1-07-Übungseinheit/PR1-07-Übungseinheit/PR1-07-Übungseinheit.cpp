/*Definieren Sie eine Struktur zur Darstellung von Punkten im R3(drei double Werte für die x-, y-und z-Komponente). 
Definieren Sie eine Funktion, die einen Vektor von Punkten als Parameter, sowie einen weiteren Punkt P 
als Parameter erhält und jenen Punkt aus dem Vektor retourniert, der am weitesten von P entfernt ist
(sollte es mehrere Punkte im Vektor gegeben,di ealle den maximalen Abstand haben,so ist ein beliebiger dieser Punkte
zu retournieren).Ist der Vektorleer,so gibt es kein Maximum und somit ist folgerichtig eine Exception vom Typ 
runtime_error zu werfen.
Hinweis: Für die Berechnung des Abstandes zweier Punkte wird die euklidische Distanz verwendet.

Zusatzaufgabe (etwa 15 bis 30 Minuten extra):Die Funktion soll so abgeändert werden, dass ein double Wert
als dritter Parameter übergeben wird. Retourniert werden soll ein Vektor mit allen Punkten aus dem Eingangsvektor,
die vom Eingangspunkt nicht weiter entfernt sind,als der double Wert.Die geänderte Funktion soll keine Exception werfen,
sondern gegebenenfalls einen leeren Vektor retournieren.
*/

