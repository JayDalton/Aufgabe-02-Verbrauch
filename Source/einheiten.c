//###############################################################################
/**
  Die Funktion liefert fuer eine uebergebene Laenge und deren uebergebene 
  (Quell-)Einheit den berechneten Wert der uebergebenen (Ziel-)Einheit.

  @param	distanz	Wert der Laenge
  @param	eingang	ganzzahlige Entsprechnung der Quelleinheit
  @param	ausgang	ganzzahlige Entsprechnung der Zieleinheit

  @return	Liefert umgerechneten Wert der Laenge
**/
//###############################################################################
double konvertiere_distanz(double distanz, unsigned int eingang, unsigned int ausgang)
{
  double faktor[10];

  faktor[MILLIMETER] = 1;
  faktor[ZENTIMETER] = 10;
  faktor[DEZIMETER] = 100;
  faktor[METER] = 1000;
  faktor[KILOMETER] = 1000000;
  faktor[ZOLL] = 25.4;
  faktor[FUSS] = 304.8;
  faktor[YARD] = 914.4;
  faktor[MEILEN] = 1609344;

  return distanz * faktor[eingang] / faktor[ausgang];
}

//###############################################################################
/**
  Die Funktion liefert fuer ein uebergebenes Volumen und deren uebergebene 
  (Quell-)Einheit den berechneten Wert der uebergebenen (Ziel-)Einheit.

  @param	volumen	Wert des Volumen
  @param	eingang	ganzzahlige Entsprechnung der Quelleinheit
  @param	ausgang	ganzzahlige Entsprechnung der Zieleinheit

  @return	Liefert umgerechneten Wert der Laenge
**/
//###############################################################################
double konvertiere_volumen(double volumen, unsigned int eingang, unsigned int ausgang)
{
  double faktor[20];

  faktor[MICROLITER] = 0.000001;
  faktor[MILLILITER] = 0.001;
  faktor[ZENTILITER] = 0.01;
  faktor[DEZILITER] = 0.1;
  faktor[LITER] = 1;
  faktor[DEKALITER] = 10;
  faktor[HEKTOLITER] = 100;
  faktor[KILOLITER] = 1000;
  faktor[MEGALITER] = 1000000;

  faktor[KUBIKMILLIMETER] = 0.000001;
  faktor[KUBIKZENTIMETER] = 0.001;
  faktor[KUBIKDEZIMETER] = 1;
  faktor[KUBIKMETER] = 1000;
  faktor[KUBIKDEKAMETER] = 1000000;

  faktor[GALLONEN] = 3.785411784;// (Imp.gal. = 4.54609)
  faktor[BARREL] = 158.987294928;// (Imp.bbl. = 159.113159869818)

  return volumen * faktor[eingang] / faktor[ausgang];
}

//###############################################################################
/**
  Die Funktion berechnet das Verhalten (Verhaeltnis) zweier uebergebener Werte zu
  einem uebergebenen Faktor und liefert den berechneten Wert. Prinzipskizze:
  
  Wert2    Wert1
  ------ = -----
  Faktor     x

  @param	wert1 Erster Wert
  @param	faktor Faktor
  @param	wert2 Zweiter Wert

  @return	Liefert das berechnete Verhaeltnis
**/
//###############################################################################
double berechne_verhalten(double wert1, unsigned int faktor, double wert2)
{
  return wert1 * faktor / wert2;
}

//###############################################################################
/**
  Die Funktion berechnet den Kehrwert eines uebergebenen Wertes.
  
  @param	wert Der Wert des zu berechnenden Kehrwertes

  @return	Liefert Kehrwert der uebergebenen Zahl
**/
//###############################################################################
double berechne_kehrwert(double wert)
{
	return 1 / wert;
}
