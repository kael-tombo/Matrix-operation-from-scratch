#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include"PROTOTYPES.h"
void multiplication()
{
    printf("\n\n\n");
   printf("\t\t#########################################\n");
   printf("\t\t#\t                                #\n");
   printf("\t\t#    MULTIPLICATION DE DEUX MATRICES    #\n ");
   printf("\t\t#\t                                # \n");
   printf("\t\t#########################################\n");
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
    printf("\tRAPPEL:\n");
    printf("\t______\n");
    printf("\n\n");
    printf("LE PRODUIT DE DEUX MATRICES A ET B EXISTE SI LE NOMBRE DE COLONE DE A EST EGALE \n");
    printf("AU NOMBRE DE LIGNE DE LA MATRICE B.");
    printf("\n\n");
    int nb_ligne,nb_colone,i,j,k,nb_ligne_1,nb_colone_1;
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
   float tab1[nb_ligne][nb_colone];
   printf("\t  Entrer les elements de la premiere matrice :\n");
   printf("\n");
  for (i=0;i<nb_ligne;i++)
  {
      for(j=0;j<nb_colone;j++)
      {
          printf("\tmat_1[%d,%d]=",i+1,j+1);
          scanf("%f",&tab1[i][j]);
      }
     printf("\n");
  }
  float d,b;
 printf("\n\n");
    printf("\t<> saisissez les lignes et colones  de la matrice :\n");
    printf("\n\n");
    nb_ligne_1=nb_colone;
    do
    {
             printf("\t  le nombre de ligne:");
             scanf("%f",&b);
             printf("\t  le nombre de colonne:");
             scanf("%f",&d);
            if (d<=0||d!=(int)d)
            {
                printf("\t ERREUR ,NOMBRE DE LIGNE OU COLONNE D'UNE MATRICE NE PEUT ETRE NULL!\n");
                printf("\t ESSAYER UN NOMBRE POSITIF NON NULL!");
            }
            else if (b!=c)
            {
                printf("\n");
                printf("\t ERREUR ! Veuillez reessayer\n ");
                printf("\n\n");
            }
    }   while ((d<=0||d!=(int)d)||(b!=c));
    nb_colone_1=(int)d;
    float tab3[nb_ligne][nb_colone_1];
    float tab2[nb_ligne_1][nb_colone_1];
     printf("\n\n");
    printf("\t  Entrer les elements de la seconde  matrice :\n");
    printf("\n");
    for (i=0;i<nb_ligne_1;i++)
    {
                  for(j=0;j<nb_colone_1;j++)
                  {
                                 printf("\tmat_2[%d,%d]=",i+1,j+1);
                                 scanf("%f",&tab2[i][j]);
                  }
                  printf("\n");
    }
    for(k=0;k<nb_colone_1;k++)
    {
        for(i=0;i<nb_ligne;i++)
        {
            tab3[i][k]=0;
            for(j=0;j<nb_ligne_1;j++)
            {
                tab3[i][k]+=tab1[i][j]*tab2[j][k];
            }
        }
    }
    printf("\n\n");
    printf("\t Le resultat de la multiplication des deux matrice  est:\n");
    printf("\n");
    for(i=0;i<nb_ligne;i++)
    {
        for(j=0;j<nb_colone_1;j++)
        {
            printf("\t%.1f",tab3[i][j]);
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
                                multiplication();
                            }
                            else if (a==2)
                            {
                                   system("cls");
                                   MENU();
                            }
                            else printf("\n\t veuillez entrer 2 ou 1 !\n\n");
                }while(ch!=2||ch!=1||ch!=(int)ch);
}
