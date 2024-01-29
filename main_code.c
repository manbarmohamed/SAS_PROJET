#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
} Date_Echeance;
typedef struct
{
    char Description[100];
    Date_Echeance Date_Ech;
    int Priorite;
    int Status; // 0==>Incomplete 1==>Complete
} Taches;

int main()
{

    return 0;
}