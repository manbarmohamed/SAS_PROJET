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
Taches tache[100];
int taille = 0;
void AjouterTach()
{
    getchar();
    printf("Description du Tache: \n");
    gets(tache[taille].Description);
    printf("Jour: (entre 1 et 31) ");
    scanf("%d", &tache[taille].Date_Ech.jour);
    // Virifie si le jour entre 1 et 31
    if (tache[taille].Date_Ech.jour < 1 || tache[taille].Date_Ech.jour > 31)
    {
        printf("Jour invalid. Entrer un jour entre 1 et 31.\n");
        return;
    }
    printf("Mois: (entre 1 et 12) ");
    scanf("%d", &tache[taille].Date_Ech.mois);
    // Virifie si le mois entre 1 et 12
    if (tache[taille].Date_Ech.mois < 1 || tache[taille].Date_Ech.mois > 12)
    {
        printf("Mois invalid. Entrer un mois entre 1 et 12.\n");
        return;
    }
    printf("Annee: (entre 2023 et 2024) ");
    scanf("%d", &tache[taille].Date_Ech.annee);
    // Virifie si l'annee entre  2023 et 2024
    if (tache[taille].Date_Ech.annee < 2023 || tache[taille].Date_Ech.annee > 2024)
    {
        printf("Annee invelid. Entrer annee entre 2023 et 2024.\n");
        return;
    }
    printf("Priorite (1.faible 2.moyenne 3.eleve): ");
    scanf("%d", &tache[taille].Priorite);
    printf("Status (0.Incomplete 1.Complete): ");
    scanf("%d", &tache[taille].Status);
    taille++;
    printf("la tache a ete ajouter avec succes\n");
}
int main()
{

    return 0;
}