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
void AfficherTache()
{
    if (taille == 0)
    {
        printf("Aucune tache disponible\n");
    }
    else
    {
        printf("--------------Taches---------------\n");
        for (int i = 0; i < taille; i++)
        {
            printf("Tache N %d:\n", i + 1);
            printf("\n");
            printf("Description: %s \nDate d'echeance: %d/%d/%d \n", tache[i].Description, tache[i].Date_Ech.jour, tache[i].Date_Ech.mois, tache[i].Date_Ech.annee);
            if (tache[i].Priorite == 1)
            {
                printf("Priorite: Faible\n");
            }
            else if (tache[i].Priorite == 2)
            {
                printf("Priorite: Moyenne\n");
            }
            else if (tache[i].Priorite == 3)
            {
                printf("Priorite: Eleve\n");
            }

            if (tache[i].Status == 0)
            {
                printf("Status: Incomplet\n");
            }
            else if (tache[i].Status == 1)
            {
                printf("Status: Complet\n");
            }
        }
    }
}
void ModifierTache()
{
    int index;
    printf("entrer le num de la tache a modifier: ");
    scanf("%d", &index);
    if (index >= 1 && index <= taille)
    {
        getchar();
        printf("La nouvelle Description: ");
        gets(tache[index - 1].Description);
        printf("Nouvelle Jour: ");
        scanf("%d", &tache[index - 1].Date_Ech.jour);
        printf("Nouvelle Mois: ");
        scanf("%d", &tache[index - 1].Date_Ech.mois);
        printf("Nouvelle Annee: ");
        scanf("%d", &tache[index - 1].Date_Ech.annee);
        printf("Nouvelle Priorite (1.faible 2.moyenne 3.eleve): ");
        scanf("%d", &tache[index - 1].Priorite);
        printf("La nouvelle Status (0.Incomplete 1.Complete): ");
        scanf("%d", &tache[index - 1].Status);
        printf("la tache a ete modifier avec succes\n");
    }
    else
    {
        printf("Numero invalide!!");
    }
}
void SupprimerTache()
{
    int index;
    char Confirm[3];
    printf("entrer le num de la tache a modifier: ");
    scanf("%d", &index);
    printf("Confirmer la Supprission (entrer oui pour supprimer sinon entrer non) :\n");
    scanf("%s", Confirm);
    if (index >= 1 && index <= taille)
    {
        if (strcmp(Confirm, "oui") == 0)
        {
            for (int i = index; i < taille - 1; i++)
            {
                tache[i] = tache[i + 1];
            }
            taille--;
            printf("\nla tache a ete supprimer avec succes\n");
        }
    }
    else
    {
        Acceuil();
        printf("Numero invalide!!");
    }
}
int main()
{

    return 0;
}