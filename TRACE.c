#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include"PROTOTYPES.h"
void trace_matrice()
{
   printf("\t\t###################################\n");
   printf("\t\t#\t                          #\n");
   printf("\t\t#      TRACE D'UNE MATRICE        #\n ");
   printf("\t\t#\t                          # \n");
   printf("\t\t###################################\n");
   printf("\n\n\n\n");
        /*
    <> ici on utilise une variable flottante au lieu d'un entier pour la dimension de la matrice pour eviter
          qu'a un moment donner l'utilisateur saisie par accident un nombre réelle ce qui crééera un bug au niveau du programme
          car la dimension d'une matrice ne peut etre un reelle et que l'ordinateur a reserver une variable entiere mais pas un flottant!
           Et pour continuer l'explication ,on caste la partie entiere de celle-ci dans une variable entiere qui sera la dimension de la matrice!
           ici on fait une casting mais pas une conversion!
    <>Soit q un flottant  et l'instruction  q!=(int)q signifie "q different de sa partie entière "
    <>Ici la partie entiere  est different de sa definition mathematiques  ! exemple: 5.825 , si tu demande a l'ordinateur d'afficher la partie entiere
    de ce nombre alors il affichera 5 ,c'est a dire toute les chiffres se trouvant a gauche du virgule ! exemple: 7.9999999 alors la partie entiere est 7 mais pas 8!
    */
    int nb_ligne,nb_colone,i,j;
    printf("\t saisissez les lignes et colones  de la matrice :\n");
    printf("\n\n");
    float l,c;
    do
    {
        printf("\t> le nombre de ligne:");
        scanf("%f",&l);
        printf("\n");
        printf("\t> le nombre de colonne:");
        scanf("%f",&c);
        printf("\n");
        if ((l!=(int)l||c!=(int)c)||(l<=0||c<=0))
        {
            printf("\tERREUR,le nombre de ligne ou colonne d'une matrice ne peut etre un reelle ou negatif ou null!\n");
            printf("\n");
            printf("\tveuillez entrer un entier positif!\n");
           printf("\n");
        }
    }while((l!=(int)l||c!=(int)c)||(l<=0||c<=0));
    nb_ligne=(int)l;
    nb_colone=(int)c;
    float  M[nb_ligne][nb_colone];
    float resultat=0;
    printf("\n");
    printf("\t Veuillez saisir les elements de la matrice :\n");
    for (i=0;i<nb_ligne;i++)
    {
        printf("\n");
        for (j=0;j<nb_colone;j++)
        {
            printf ("\tM[%d,%d]=",i+1,j+1);
            scanf("%f",&M[i][j]);
        }
    }
    printf("\n");
    printf("\t le matrice que vous avez entrer est :\n");
    printf("\n\n");
    for (i=0;i<nb_ligne;i++)
    {
        for(j=0;j<nb_colone;j++)
        {
            printf("\t%.1f",M[i][j]);
        }
        printf("\n\n");
    }
    for (i=0;i<nb_ligne;i++)
    {
        for(j=0;j<nb_colone;j++)
        {
            if (i==j)
            {
                resultat+=M[i][j];
            }
        }

    }
    printf("\n\n");
   printf("\t###################################################\n");
   printf("\t#\t                                          #\n");
   printf("\t#         LE TRACE DE CETTE MATRICE EST  %.1f\t  #\n ",resultat);
   printf("\t#\t                                          # \n");
   printf("\t###################################################\n");
   printf("\n\n\n\n");
   printf("\t[/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/]");
   printf("\n\n\n");
                float ch;
                int a;
                            printf("\t    1 - faire un nouveau calcul \n");
                            printf("\n");
                            printf("\t    2 - Aller au menu principale \n");
                            printf("\n\n");
                do
                {
                            printf("\t   saisissez 1 ou 2:");
                            scanf("%f",&ch);
                            a=(int)ch;
                            if (a==1)
                            {
                                  system("cls");
                                trace_matrice();
                            }
                            else if (a==2)
                            {
                                   system("cls");
                                   MENU();
                            }
                            else printf("\n\t veuillez entrer 2 ou 1 !\n\n");
                }while(ch!=2||ch!=1||ch!=(int)ch);
}
