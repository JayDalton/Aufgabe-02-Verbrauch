#define MILLIMETER 1
#define ZENTIMETER 2
#define DEZIMETER 3
#define METER 4
#define KILOMETER 5
#define ZOLL 6
#define FUSS 7
#define YARD 8
#define MEILEN 9

#define MICROLITER 1
#define MILLILITER 2
#define ZENTILITER 3
#define DEZILITER 4
#define LITER 5
#define DEKALITER 6
#define HEKTOLITER 7
#define KILOLITER 8
#define MEGALITER 9
#define KUBIKMILLIMETER 10
#define KUBIKZENTIMETER 11
#define KUBIKDEZIMETER 12
#define KUBIKMETER 13
#define KUBIKDEKAMETER 13
#define GALLONEN 14
#define BARREL 15

// Konvertiert - Volumen
double konvertiere_einheit(double einheit, unsigned int eingang, unsigned int ausgang);
double konvertiere_volumen(double volumen, unsigned int eingang, unsigned int ausgang);
double konvertiere_distanz(double distanz, unsigned int eingang, unsigned int ausgang);

// Konvertiert - Währung
double konvertiere_euro_nach_dollar(double wert, double kurs);
double konvertiere_dollar_nach_euro(double wert, double kurs);

double berechne_verhalten(double wert1, unsigned int faktor, double wert2);
double berechne_kehrwert(double wert);
