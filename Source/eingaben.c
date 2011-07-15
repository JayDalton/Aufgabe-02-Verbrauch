//###############################################################################
/**	
  Die Funktion erzeugt die Ausgabe einer uebergebenen Zeichenkette und fordert 
  den Nutzer zur Eingabe einer ganzen Zahl zwischen zwei gegebenen Grenzen auf.
	
  @param	titel	Beschriftung der Eingabeaufforderung	
  @param	minimum	Minimum des definierten Wertebereiches
  @param	maximum	Maximum des definierten Wertebereiches

  @return	Die im Wertebereich definierte Ganzzahl
**/
//###############################################################################
int erfasse_ganzzahl(const char *titel, int minimum, int maximum)
{
  int puffer = 0;
  int ergebnis = 0;

  printf("%-60s", titel);

  while (scanf("%i", &ergebnis) == 0 || (ergebnis < minimum || maximum < ergebnis)) 
  {
    printf("\nBitte Werte von '%i' bis '%i' eingeben.\n", minimum, maximum);
    do { 
      puffer = getchar(); 
    } while (puffer != 10);
  }

  return ergebnis;
}

//###############################################################################
/**	
  Die Funktion erzeugt die Ausgabe einer uebergebenen Zeichenkette und fordert 
  den Nutzer zur Eingabe einer Gleitkommazahl zwischen zwei gegebenen Grenzen auf.

  @param	titel	Beschriftung der Eingabeaufforderung	
  @param	minimum	Minimum des definierten Wertebereiches
  @param	maximum	Maximum des definierten Wertebereiches

  @return	Die im Wertebereich definierte Gleitkommazahl.
*/
//###############################################################################
double erfasse_gleitzahl(const char *titel, double minimum, double maximum)
{
  int puffer = 0;
  double ergebnis = 0;

  printf("%-60s", titel);

  while (scanf("%lf", &ergebnis) == 0 || (ergebnis < minimum || maximum < ergebnis)) 
  {
    printf("\nBitte Werte von '%.2lf' bis '%.2lf' eingeben: ", minimum, maximum);
    do { 
      puffer = getchar(); 
    } while (puffer != 10);
  }

  return ergebnis;
}

//###############################################################################
/**	
  Die Funktion erzeugt die Ausgabe einer uebergebenen Zeichenkette und fordert 
  den Nutzer zur Eingabe einer Auswahl zwischen j und n auf.

  @param	titel	Beschriftung der Eingabeaufforderung	

  @return	Liefert 1 für Zustimmung und 0 für Ablehnung
*/
//###############################################################################
int erfasse_antwort(const char *titel)
{
  int puffer = 0;
  char ergebnis;

  printf("\n\n%s : ", titel);

  while (scanf("%s", &ergebnis) == 0 || (ergebnis != 106 && ergebnis != 110)) 
  {
    printf("\nBitte nur 'j' oder 'n' eingeben.\n");
    do { 
      puffer = getchar(); 
    } while (puffer != 10);
  }

  return ergebnis == 106 ? 1 : 0;
}
