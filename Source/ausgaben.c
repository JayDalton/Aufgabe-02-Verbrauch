//###############################################################################
/**
  Die Funktion erzeugt die Ausgabe einer uebergebenen Zeichenkette indem 
  diese formatiert als neue Zeile in die Standardausgabe geschrieben wird.
  
  @param	inhalt	Die auszugebenen Zeichenkette

  @return	Liefert die Anzahl der ausgegebenen Zeichen
**/
//###############################################################################
int schreibe_zeile(const char *inhalt)
{
  return printf("\n%s", inhalt);
}
	
//###############################################################################
/**
  Die Funktion erzeugt die Ausgabe einer uebergebenen Gleitkommazahl indem 
  diese formatiert als neue Zeile in die Standardausgabe geschrieben wird.

  @param	titel	Die auszugebene Zeichenkette
  @param	wert	Der auszugebene Wert
  @param	format	Das Format der Ausgabe

  @return	Liefert die Anzahl der ausgegebenen Zeichen
**/
//###############################################################################
int schreibe_gleitkomma(const char *titel, double wert, unsigned int format)
{
  return printf("\n %s : %.*f \n", titel, format, wert);
}

//###############################################################################
/**
  Die Funktion erzeugt die Ausgabe einer uebergebenen ganzen Zahl indem 
  diese formatiert als neue Zeile in die Standardausgabe geschrieben wird.

  @param	titel	Die auszugebene Zeichenkette
  @param	wert	Der auszugebene Wert
  @param	format	Das Format der Ausgabe

  @return	Liefert die Anzahl der ausgegebenen Zeichen
**/
//###############################################################################
int schreibe_ganzzahl(const char *titel, int wert, double format)
{
  char puffer[60];
  sprintf(puffer, "\n %%s : %%%.1lflf \n", format);
  return printf(puffer, titel, wert);
}
