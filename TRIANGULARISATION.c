#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include"PROTOTYPES.h"
void triangularisation()
{
    printf("\n\n\n");
   printf("\t\t########################################\n");
   printf("\t\t#\t                               #\n");
   printf("\t\t#   TRIANGULARISATION  D'UNE MATRICE   #\n ");
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
    int i,j,k,m,n=0;
    float temp; temp=0;
    float f,d;
    int nb_ligne,nb_colone;
    printf("\t<>veuillez entrer le nombre de ligne et colone de la matrice :\n");
    printf("\n\n");
    do
    {
            printf("\t> le nombre de ligne:");
            scanf("%f",&f);
            printf("\n");
            printf("\t> le nombre de colone:");
            scanf("%f",&d);
             if (f<1||d<1||f!=(int)f||d!=(int)d)
            {
                printf("\n");
            printf("ERREUR,le nombre de ligne ou colonne d'une matrice ne peut etre un reelle ou negatif ou null!\n");
            printf("\n");
            printf("\tveuillez entrer un entier positif!\n");
           printf("\n");
            }
    }while (f<1||d<1||f!=(int)f||d!=(int)d);
    nb_ligne=(int)f;
    nb_colone=(int)d;
    float matrice [nb_ligne][nb_colone];
         for (i=0;i<nb_ligne;i++)
       {
                  printf("\n\n");
                    for (j=0;j<nb_colone;j++)
                    {
                           printf("\t  M[%d,%d]=",i+1,j+1);
                           scanf("%f",&matrice[i][j]);
                    }
      }
      printf("\n\n");
      printf("\t => la matrice que vous avez entrer est :\n");
      printf("\n\n");
                 for (i=0;i<nb_ligne;i++)
                  {
                      for (j=0;j<nb_colone;j++)
                      {
                                       printf("\t%.2f",matrice[i][j]);
                      }
                            printf("\n\n");
                  }
   for( i=0;i<nb_ligne-1;i++)
   {
               if (matrice[i][i]==0)
               {
                        k=i+1;
                        do
                        {
                                        if (matrice[k][i]!=0)
                                        {
                                                        for (m=0;m<nb_colone;m++)
                                                        {
                                                                      temp=matrice[i][m];
                                                                      matrice[i][m]=matrice[k][m]; // on permute les lignes
                                                                      matrice[k][m]=temp;
                                                        }
                                        }
                                        else if (matrice[k][i]==0)
                                        {
                                                            k++;// on incremente le compteur si  l'element suivant est encore null
                                        }
                        } while (matrice[i][i]==0&&k<n);
               }
               for(k=i+1;k<nb_ligne;k++)
               {
                               for (j=nb_colone-1;j>=i;j--)
                               {
                                   matrice[k][j]=matrice[k][j]-((matrice[k][i]*matrice[i][j])/matrice[i][i]);
                               }
               }
   }
      printf("\n\n\n");
      printf("\t la forme echelonne de la matrice est :\n");
                 printf("\n\n");
                 for (i=0;i<nb_ligne;i++)
                  {
                      for (j=0;j<nb_colone;j++)
                      {
                                       printf("\t%.2f",matrice[i][j]);
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
                                triangularisation();
                            }
                            else if (a==2)
                            {
                                   system("cls");
                                   MENU();
                            }
                            else printf("\n\t veuillez entrer 2 ou 1 !\n\n");
                }while(ch!=2||ch!=1||ch!=(int)ch);
}
