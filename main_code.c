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
    char Titre[25];
    char Description[100];
    Date_Echeance Date_Ech;
    int Priorite; // 1==>faible 2==>moyenne 3==>eleve
    int Status;   // 0==>Incomplete 1==>Complete
} Taches;
Taches tache[100];
int taille = 0;
void AjouterTach()
{
    getchar();
    printf("Titre de la Tache: \n");
    gets(tache[taille].Titre);
    printf("Description du Tache: \n");
    gets(tache[taille].Description);
    printf("Jour: (entre 1 et 31) ");
    scanf("%2d", &tache[taille].Date_Ech.jour);
    // Virifie si le jour entre 1 et 31
    if (tache[taille].Date_Ech.jour < 1 || tache[taille].Date_Ech.jour > 31)
    {
        printf("Jour invalid. Entrer un jour entre 1 et 31.\n");
        return;
    }
    printf("Mois: (entre 1 et 12) ");
    scanf("%2d", &tache[taille].Date_Ech.mois);
    // Virifie si le mois entre 1 et 12
    if (tache[taille].Date_Ech.mois < 1 || tache[taille].Date_Ech.mois > 12)
    {
        printf("Mois invalid. Entrer un mois entre 1 et 12.\n");
        return;
    }
    printf("Annee: (entre 2023 et 2024) ");
    scanf("%4d", &tache[taille].Date_Ech.annee);
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
            printf("Titre: %s \nDescription: %s \nDate d'echeance: %d/%d/%d \n", tache[i].Titre, tache[i].Description, tache[i].Date_Ech.jour, tache[i].Date_Ech.mois, tache[i].Date_Ech.annee);
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
            printf("\n______________________\n");
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
        printf("La nouvelle Titre: ");
        gets(tache[index - 1].Titre);
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
void FiltrerTacheParPriorite()
{
    int priorite;
    printf("Priorite (1.faible 2.moyenne 3.eleve): ");
    scanf("%d", &priorite);
    for (int i = 0; i < taille; i++)
    {
        if (tache[i].Priorite == priorite)
        {
            printf("Tache N:%d\n", i + 1);
            printf("______________________\n");
            printf("Titre: %s \nDescription: %s \nDate d'echeance: %d/%d/%d \n", tache[i].Titre, tache[i].Description, tache[i].Date_Ech.jour, tache[i].Date_Ech.mois, tache[i].Date_Ech.annee);
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

            printf("\n");
        }
    }
}
void FiltrerTacheParDate()
{
    int Jour, Mois, Annee;
    printf("Jour: (entre 1 et 31) ");
    scanf("%2d", &Jour);
    // Virifie si le jour entre 1 et 31
    if (Jour < 1 || Jour > 31)
    {
        printf("Jour invalid. Entrer un jour entre 1 et 31.\n");
        return;
    }
    printf("Mois: (entre 1 et 12) ");
    scanf("%2d", &Mois);
    // Virifie si le mois entre 1 et 12
    if (Mois < 1 || Mois > 12)
    {
        printf("Mois invalid. Entrer un mois entre 1 et 12.\n");
        return;
    }
    printf("Annee: (entre 2023 et 2024) ");
    scanf("%4d", &Annee);
    // Virifie si l'annee entre  2023 et 2024
    if (Annee < 2023 || Annee > 2024)
    {
        printf("Annee invelid. Entrer annee entre 2023 et 2024.\n");
        return;
    }
    printf("\n");
    for (int i = 0; i < taille; i++)
    {
        if (tache[i].Date_Ech.jour == Jour && tache[i].Date_Ech.mois == Mois && tache[i].Date_Ech.annee == Annee)
        {
            printf("Tache N:%d\n", i + 1);
            printf("Titre: %s \nDescription: %s \nDate d'echeance: %d/%d/%d \n", tache[i].Titre, tache[i].Description, tache[i].Date_Ech.jour, tache[i].Date_Ech.mois, tache[i].Date_Ech.annee);
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
            printf("\n");
        }
    }
}
void OrderParDateCroissan()
{
    Taches temp;
    for (int i = 0; i < taille - 1; i++)
    {
        for (int j = i + 1; j < taille; j++)
        {
            if (tache[i].Date_Ech.annee > tache[j].Date_Ech.annee || (tache[i].Date_Ech.annee == tache[j].Date_Ech.annee && tache[i].Date_Ech.mois > tache[j].Date_Ech.mois) || (tache[i].Date_Ech.annee == tache[j].Date_Ech.annee && tache[i].Date_Ech.mois == tache[j].Date_Ech.mois && tache[i].Date_Ech.jour > tache[j].Date_Ech.jour))
            {
                temp = tache[i];
                tache[i] = tache[j];
                tache[j] = temp;
            }
        }
    }
    printf("Les tache a ete trie par Date d'echeance. ");
}
void OrderParDateDecroissan()
{
    Taches temp;
    for (int i = 0; i < taille - 1; i++)
    {
        for (int j = i + 1; j < taille; j++)
        {
            if (tache[i].Date_Ech.annee < tache[j].Date_Ech.annee || (tache[i].Date_Ech.annee == tache[j].Date_Ech.annee && tache[i].Date_Ech.mois < tache[j].Date_Ech.mois) || (tache[i].Date_Ech.annee == tache[j].Date_Ech.annee && tache[i].Date_Ech.mois == tache[j].Date_Ech.mois && tache[i].Date_Ech.jour < tache[j].Date_Ech.jour))
            {
                temp = tache[i];
                tache[i] = tache[j];
                tache[j] = temp;
            }
        }
    }
    printf("Les tache a ete trie par Date d'echeance. ");
}

void Souvgarder()
{
    FILE *file = fopen("tasks.txt", "w");
    if (file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < taille; i++)
    {
        fprintf(file, "Titre: %s, Description: %s, Date: %d/%d/%d, %d, %d\n", tache[i].Titre, tache[i].Description, tache[i].Date_Ech.jour, tache[i].Date_Ech.mois, tache[i].Date_Ech.annee,
                tache[i].Priorite, tache[i].Status);
    }

    fclose(file);
    printf("Les Taches sauvegardes dans le fichier tasks.txt avec succes!\n");
}
void Design()
{

    printf("\n ________________________PROJET FIN SAS____________________________ \n"
           "|                                                                  |\n"
           "|                                                                  |\n"
           "|                                                                  |\n"
           "|                                                                  |\n"
           "|                                                                  |\n"
           "|                                                                  |\n"
           "|                            Realiser par:     Mohamed MANBAR      |\n"
           "|                            Encadre par:      Ibrahim Zeroual     |\n"
           "|                                                                  |\n"
           "|__________________________________________________________________|\n");
}
void Acceuil()
{
    Design();
    int choix;
    do
    {
        printf("\n __________________________ MENU__________________________________________\n"
               "|                                                                         |\n"
               "|               1 : Ajouter une tache                                     |\n"
               "|               2 : Afficher la tache                                     |\n"
               "|               3 : Modifier la tache                                     |\n"
               "|               4 : Supprimer une tache                                   |\n"
               "|               5 : Filtrer les taches par priorite                       |\n"
               "|               6 : Filtrer les taches par Date                           |\n"
               "|               7 : Oreder les taches par Date d'echeance (Croissan)      |\n"
               "|               8 : Oreder les taches par Date d'echeance (Decroissan)    |\n"
               "|               9 : Souvgarder les taches dans un fichier .txt            |\n"
               "|              10 : Quitter le Programme                                  |\n"
               "|_________________________________________________________________________|\n");
        printf("Choix: ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            AjouterTach();
            break;
        case 2:
            AfficherTache();
            break;
        case 3:
            ModifierTache();
            break;
        case 4:
            SupprimerTache();
            break;
        case 5:
            FiltrerTacheParPriorite();
            break;
        case 6:
            FiltrerTacheParDate();
            break;
        case 7:
            OrderParDateCroissan();
            break;
        case 8:
            OrderParDateDecroissan();
            break;
        case 9:
            Souvgarder();
            break;
        case 10:
            printf("Fin Programme! ");
            break;
        default:
            printf("choix invalide! ");
            break;
        }
    } while (choix != 10);
}
int main()
{
    Acceuil();
    return 0;
}