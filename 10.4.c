#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int readFile() {
    char filnamn[20]="1.txt", filnamn2[20]="2.txt";
    char a[100], b[100], lengd[20], vikt[20];
    double bmi;
    FILE *infil = fopen(filnamn, "r+");
    FILE *utfil = fopen(filnamn2, "w");
    if (!infil){                                    // KONTROLLERAR SÅ ATT INFILEN EXISTERAR
            printf("%s existerar ej!", filnamn);
            return 0;
    }
    while (fgets(a, 100, infil) != NULL) {          // KÖR SÅ LÄNGE DET FINNS NÅGOT I FILEN
                bmi = 0;                            // NOLLSTÄLLER BMI VARIABELN.
                fgets(b, 100, infil);
                int countLengdVikt = 0;             // VARIABEL FÖR ATT RÄKNA UPP lengd[x]
                for (int i = 0;i<100;i++) {
                    if (b[i]==',') {                // KOLLAR EFTER , TECKEN
                        i++;
                        while (b[i]!=',') {         // KÖR TILL DEN UPPTÄCKER NÄSTA ,
                            lengd[countLengdVikt] = b[i];
                            countLengdVikt++;
                            i++;
                        }
                        countLengdVikt = 0;
                        i++;
                        while (b[i]!='\0') {        // KÖR TILLS DEN FÖR RADSLUT
                            vikt[countLengdVikt] = b[i];
                            countLengdVikt++;
                            i++;
                        }
                        bmi = atoi(vikt)/pow(0.01*atoi(lengd),2);  // GÖR OM VIKT OCH LENGD TILL IN RÄKNAR SEDAN UT vikt/(lengd*0,01)^2
                        printf("\nBMI: %f", bmi);
                        }
                }
                if (bmi > 30) {
                    fprintf(utfil, "%s", a);
                    fprintf(utfil, "%s", b);
                }
    }
}


int main()
{
    readFile();
    return 0;
}
