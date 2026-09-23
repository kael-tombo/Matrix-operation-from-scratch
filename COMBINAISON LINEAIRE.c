#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include"PROTOTYPES.h"
void COMBINAISON()
{
    printf("\n\n\n");
   printf("\t\t########################################\n");
   printf("\t\t#\t                               #\n");
   printf("\t\t#    COMBINAISON LINEAIRE DE MATRICE   #\n ");
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
    int i,j,k,nb_ligne,nb_colone,nb_matrice;
    float l,c,nb;
    do
    {
         printf("\t>> veuillez enter le nombre de matrice a combiner:");
         scanf("%f",&nb);
         printf("\n\n");
         printf("\t > entrer le nombre de ligne de la matrice: ");
         scanf("%f",&l);
         printf("\n\n");
         printf("\t > enter le nombre de colonne:");
         scanf("%f",&c);
         if (nb<1||c<1||l<1||nb!=(int)nb||l!=(int)l||c!=(int)c)
         {
             printf("\n\n");
             printf("\t ERREUR! le nombre de matrice ou ligne ou colonne d'une matrice,\n ");
             printf("\t ne peut etre un reelle ou NULL ou negatif ! Essayez un entier positif non null !");
             printf("\n\n");
         }
    }while(nb<1||c<1||l<1||nb!=(int)nb||l!=(int)l||c!=(int)c);
    nb_matrice=(int)nb;
    nb_ligne=(int)l;
    nb_colone=(int)c;
    float matrice[nb_matrice][nb_ligne][nb_colone];
    float scalaire[nb_matrice];
    float resultat[nb_ligne][nb_colone];
    float temp=0;
    int m,n,w;
    printf("\n\n");
    printf("\t<=>veuillez entrer les elements des matrices (de la matrice):\n");
    printf("\n\n");
    for (k=0;k<nb_matrice;k++)
    {
        printf("\t ==> matrice %d",k+1);
            printf("\n\n");
            for (i=0;i<nb_ligne;i++)
            {
                 for (j=0;j<nb_colone;j++)
                 {
                        printf("\t    M%d[%d,%d]=",k+1,i+1,j+1);
                       scanf("%f",&matrice[k][i][j]);
                 } printf("\n\n");
            }
    }
                printf("\n\n");
                printf("\t >> veuillez entrer les scalaires pour les matrices (le scalaire pour la  matrice):");
                printf("\n\n");
                for (i=0;i<nb_matrice;i++)
                {
                    printf("\t >scalaire pour la matrice %d",i+1);
                    printf("\n\n");
                    printf("\tscalaire %d=",i+1);
                    scanf("%f",&scalaire[i]);
                    printf("\n\n");
                }
    for (m=0;m<nb_ligne;m++)
    {
        for (n=0;n<nb_colone;n++)
        {
            for (w=0;w<nb_matrice;w++)
            {
                temp+=scalaire[w]*matrice[w][m][n];
              resultat[m][n]=temp;
            }
            temp=0;
        }
    }
  printf("\n\n");
    printf("\t==> le resultat de combinaison lineaire est la matrice : ");
    printf("\n\n");
    for (i=0;i<nb_ligne;i++)
    {
        for (j=0;j<nb_colone;j++)
        {
            printf("\t %.2f ",resultat[i][j]);
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
                                COMBINAISON();
                            }
                            else if (a==2)
                            {
                                   system("cls");
                                   MENU();
                            }
                            else printf("\n\t veuillez entrer 2 ou 1 !\n\n");
                }while(ch!=2||ch!=1||ch!=(int)ch);
}
