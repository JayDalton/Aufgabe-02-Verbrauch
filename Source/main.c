/*###############################################################################
  Kodierung: UTF-8 ohne BOM
  http://www.convertworld.com/de/kraftstoffverbrauch
###############################################################################*/

#include <stdio.h>
#include <stdlib.h>

#include "eingaben.h"
#include "ausgaben.h"
#include "einheiten.h"

#include "eingaben.c"
#include "ausgaben.c"
#include "einheiten.c"

/*###############################################################################
  Test: 700 Kilometer
  Test: 50 Liter
  Test: 1.429 Euro pro Liter (0.699 Liter pro Euro)
  Test: 2.739 Dollar pro Gallone (0.365 Gallonen pro Dollar)
  Test: 1 Euro = 1.3233 Dolar (1 Dollar = 0.7557 Euro)
###############################################################################*/

//###############################################################################
/**
  Das Programm berechnet nach dem vom Nutzer einzugebenen Werten für gefahrene Kilometer,
  verbrauchte Liter, Preis pro Liter in Euro, Preis pro Gallone in Dollar und den aktuelle 
  Wechselkurs von Euro zu Dollar, folgende Ausgaben:

  - Verbrauch Liter Benzin pro Kilometer, Entsprechung der gefahrenen Meilen pro Gallone Benzin.
  - Die Kosten der Fahrt in Euro, Kosten der Fahrt in den USA, der Entsprechung in Euro.
  - Die Differenz der Kosten fuer die Fahrt in Deutschland und in den USA
  - Preis pro Kilometer in Deutschland in Euro
  - Preis pro Kilometer in den USA in Euro
  - Prozentwert der Differenz der Kosten fuer die Fahrt in den USA und Deutschland
  - Gesamtkosten der durchschnittliche Fahrleistungen pro Jahr fuer 15000 Kilometer/Meilen in Deutschland/USA in Euro/Dollar

  @author Thomas Gerlach
  @version 1.0 
**/
//###############################################################################
int main(void)
{
  do {

    system("clear");
    printf("\n\tV e r b r a u c h\n");
    printf("\nDas Programm dient der Be- / Umrechnung vom Kraftstoffverbrauch.\n\n");

    double strecke_in_kilometer = erfasse_gleitzahl("Wie viel Kilometer sind Sie mit Ihrem PKW gefahren?", 1, 40000);
    double volumen_in_liter = erfasse_gleitzahl("Wie viel Liter Benzin haben Sie dabei verbraucht?", 1, 40000);
    double brd_euro_pro_liter = erfasse_gleitzahl("Wie viel Euro kostet ein Liter Benzin?", 0.1, 5.0);
    schreibe_zeile("");
    double usa_dollar_pro_gallone = erfasse_gleitzahl("Wie viel Dollar kostet eine Gallone Benzin in den USA?", 0.1, 20.0);
    double faktor_dollar_pro_euro = erfasse_gleitzahl("Was ist der aktuelle Wechselkurs von Euro zu Dollar?", 0.1, 10.0);

    double strecke_in_meilen = konvertiere_distanz(strecke_in_kilometer, KILOMETER, MEILEN);
    double volumen_in_gallonen = konvertiere_volumen(volumen_in_liter, LITER, GALLONEN);
    double verbrauch_liter_pro_kilometer = berechne_verhalten(volumen_in_liter, 1, strecke_in_kilometer);
    double reichweite_meilen_pro_gallone = berechne_verhalten(strecke_in_meilen, 1, volumen_in_gallonen);
    double faktor_euro_pro_dollar = berechne_kehrwert(faktor_dollar_pro_euro);
    //double brd_liter_pro_euro = berechne_kehrwert(brd_euro_pro_liter);
    //double usa_gallonen_pro_dollar = berechne_kehrwert(usa_dollar_pro_gallone);
    double brd_strecke_in_euro = volumen_in_liter * brd_euro_pro_liter;
    //double brd_strecke_in_dollar = brd_strecke_in_euro * faktor_dollar_pro_euro;
    double usa_strecke_in_dollar = volumen_in_gallonen * usa_dollar_pro_gallone;
    double usa_strecke_in_euro = usa_strecke_in_dollar * faktor_euro_pro_dollar;
    double differenz_strecke_in_euro = brd_strecke_in_euro - usa_strecke_in_euro;
    double brd_euro_pro_kilometer = brd_strecke_in_euro / strecke_in_kilometer;
    //double brd_kilometer_pro_euro = strecke_in_kilometer / brd_strecke_in_euro;
    double usa_euro_pro_kilometer = usa_strecke_in_euro / strecke_in_kilometer;
    double usa_dollar_pro_kilometer = usa_strecke_in_dollar / strecke_in_kilometer;
    double usa_dollar_pro_meile = usa_strecke_in_dollar / strecke_in_meilen;
    double usa_euro_pro_meile = usa_strecke_in_euro / strecke_in_meilen;
    //double usa_kilometer_pro_euro = strecke_in_kilometer / usa_strecke_in_euro;
    double prozent_euro_pro_anteil = 100 - (usa_euro_pro_kilometer * 100 / brd_euro_pro_kilometer);	// ???
    double brd_euro_pro_meile = brd_strecke_in_euro / strecke_in_meilen;

    schreibe_zeile("Aufgrund Ihrer Eingaben habe ich folgende Daten berechnet:");
    schreibe_zeile("");
    printf("\nSie haben %.3lf Liter Benzin pro Kilometer verbraucht.", verbrauch_liter_pro_kilometer);
    printf("\nDem entsprechen %.1lf gefahrene Meilen pro Gallone Benzin.", reichweite_meilen_pro_gallone);
    printf("\nBei einem Literpreis von %.2lf Euro hat Sie die Fahrt %.2lf Euro gekostet.", 
      brd_euro_pro_liter, brd_strecke_in_euro
    );
    schreibe_zeile("");
    printf("\nBeim Preis von %.2lf Dollar pro Gallone haette Sie die Fahrt in den USA %.2lf Dollar gekostet.", 
      usa_dollar_pro_gallone, usa_strecke_in_dollar
    );
    printf("\nBeim Wechselkurs von %.3lf Euro pro Dollar entspricht das %.3lf Euro.", 
      faktor_euro_pro_dollar, usa_strecke_in_euro
    );
    printf("\nDie Differenz der Kosten fuer die Fahrt in Deutschland und in den USA betraegt somit %.2lf Euro.",
      differenz_strecke_in_euro
    );
    schreibe_zeile("");
    printf("\nEin Kilometer Ihrer Fahrt hat in Deutschland %.2lf Euro gekostet.",
      brd_euro_pro_kilometer
    );
    printf("\nEin Kilometer Ihrer Fahrt haette in den USA %.2lf Euro gekostet.",
      usa_euro_pro_kilometer
    );
    schreibe_zeile("");
    printf("\nIn den USA sind die Kosten fuer die Fahrt somit um %.2lf Prozent geringer.",
      prozent_euro_pro_anteil
    );
    schreibe_zeile("");
    printf("\nUmgerechnet auf eine durchschnittliche Fahrleistung pro Jahr ergeben sich daraus folgende Werte:");
    schreibe_zeile("");
    printf("\n%-50s %10.2lf Euro",
      "Gesamtkosten fuer 15000 Kilometer in Deutschland:",
      15000 * brd_euro_pro_kilometer
    );
    printf("\n%-50s %10.2lf Euro",
      "Gesamtkosten fuer 15000 Kilometer in den USA:",
      15000 * usa_euro_pro_kilometer
    );
    printf("\n%-50s %10.2lf Dollar",
      "Gesamtkosten fuer 15000 Kilometer in den USA:",
      15000 * usa_dollar_pro_kilometer
    );

    schreibe_zeile("");

    printf("\n%-50s %10.2lf Dollar",
      "Gesamtkosten fuer 15000 Meilen in den USA:",
      15000 * usa_dollar_pro_meile
    );

    printf("\n%-50s %10.2lf Euro",
      "Gesamtkosten fuer 15000 Meilen in den USA:",
      15000 * usa_euro_pro_meile
    );

    printf("\n%-50s %10.2lf Euro",
      "Gesamtkosten fuer 15000 Meilen in Deutschland:",
      15000 * brd_euro_pro_meile);

    } while (erfasse_antwort("Nochmal berechnen? (j/n)"));
}

