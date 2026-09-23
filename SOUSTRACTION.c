#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include"PROTOTYPES.h"
void soustraction()
{
        printf("\n\n\n");
   printf("\t\t########################################\n");
   printf("\t\t#\t                               #\n");
   printf("\t\t#    SOUSTRACTION DE DEUX  MATRICES    #\n ");
   printf("\t\t#\t                               # \n");
   printf("\t\t########################################\n");
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
    int nb_ligne,nb_colone;
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
            printf("\tle nombre de ligne ou colonne d'une matrice ne peut etre un reelle ou negatif ou null!\n");
            printf("\n");
            printf("\tveuillez entrer un entier positif!\n");
           printf("\n");
        }
    }while((l!=(int)l||c!=(int)c)||(l<=0||c<=0));
    nb_ligne=(int)l;
    nb_colone=(int)c;
    float tab[nb_ligne][nb_colone];float tab1[nb_ligne][nb_ligne];
    float result[nb_ligne][nb_colone];
    int i,j;
    printf("\n\n");
    printf("\t >veuillez entrer les elements de la premiere matrice:\n");
     printf("\n\n");
    for (i=0;i<=nb_ligne-1;i++)
    {
        for (j=0;j<=nb_colone-1;j++)
        {
            printf("\t  matrice_1[%d,%d]=",i+1,j+1);
            scanf("%f",&tab[i][j]);
        }
    }
    printf("\n\n");
    printf("\t >veuillez entrer les elements de la seconde matrice:\n");
    printf("\n\n");
    for (i=0;i<=nb_ligne-1;i++)
    {
        for (j=0;j<=nb_colone-1;j++)
        {
            printf("\t  matrice_2[%d,%d]=",i+1,j+1);
            scanf("%f",&tab1[i][j]);

        }
    }
    for (i=0;i<=nb_ligne-1;i++)
    {
        for (j=0;j<=nb_colone-1;j++)
        {
            result[i][j]=tab1[i][j]-tab[i][j];
        }
    }
    printf("\n");
    printf("\t le premier matrice est :\n");
    printf("\n");
    for (i=0;i<=nb_ligne-1;i++)
    {
        for (j=0;j<=nb_colone-1;j++)
        {
            printf("\t%.2f", tab[i][j]);
        }
        printf("\n\n");
    }
    printf("\n");
    printf("\t Et la seconde matrice est :\n");
    printf("\n");
    for (i=0;i<=nb_ligne-1;i++)
    {
           for (j=0;j<=nb_colone-1;j++)
           {
                     printf("\t%.2f", tab1[i][j]);
           }
           printf("\n\n");
    }
    printf("\n\n");
    printf("\t ET LE RESULTAT DE LA SOUSTRACTION  DE CES DEUX MATRICES EST :\n ");
    printf("\n\n");
       for (i=0;i<=nb_ligne-1;i++)
       {
                  for (j=0;j<=nb_colone-1;j++)
                  {
                            printf("\t%.2f",result[i][j]);
                  }
                  printf("\n\n");
       }
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
                                soustraction();
                            }
                            else if (a==2)
                            {
                                   system("cls");
                                   MENU();
                            }
                            else printf("\n\t veuillez entrer 2 ou 1 !\n\n");
                }while(ch!=2||ch!=1||ch!=(int)ch);
}
