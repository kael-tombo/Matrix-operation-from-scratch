#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include"PROTOTYPES.h"
int DETERMINANT_1()
{
    printf("\n\n\n");
   printf("\t\t###############################\n");
   printf("\t\t#\t                      #\n");
   printf("\t\t#  DETERMINANT D'UNE MATRICE  #\n ");
   printf("\t\t#\t                      # \n");
   printf("\t\t###############################\n");
   printf("\n\n\n\n");
    int i,j,k,m,x;
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
    float q;
    do
    {
          printf("\t veuillez entrer la dimension de la matrice :");
          scanf("%f",&q);
          if (q!=(int)q||q<=0)
          {
                  printf("\n\n");
                  printf("\t erreur , la taille d'une matrice ne peut etre un reelle ou negatif ou null !\n");
                  printf("\n");
                  printf("\t entrer un entier positif non null!\n");
                  printf("\n\n");
          }
    }while(q!=(int)q||q<=0);
     x=(int)q;
     float temp=0,**matrice;
     float scalaire=1;
     float det =1;
     float l=1;
matrice=malloc2(x,x);
printf("\n\n");
printf("\t veuillez entrer une matrice : ");
printf("\n\n");
saisie(matrice,x,x);
  for( i=0;i<x-1;i++)
   {
        k=i+1;
                               do
                               {
                                         if (matrice[k][i]!=0&&matrice[i][i]==0)
                                         {
                                                    for (m=0;m<x;m++)
                                                   {
                                                             // on permute les lignes
                                                             temp=matrice[i][m];
                                                             matrice[i][m]=matrice[k][m];
                                                             matrice[k][m]=temp;
                                                    }
                                                    scalaire*=matrice[i][i];
                                                    det*=-1;
                                                    l=det;
                                         }
                                         else if((k==x-1&&matrice[k-1][i]==0)&&matrice[k][i]==0)
                                         {
                                                 det=0;
   printf("\n");
   printf("\t###################################################\n");
   printf("\t#\t                                          #\n");
   printf("\t#  LE DETERMINANT DE CETTE MATRICE EST : %.2f\t  #\n ",det);
   printf("\t#\t                                          # \n");
   printf("\t###################################################\n");
   printf("\n\n\n\n");
                                                 return 0;
                                         }
                                        else if (matrice[k][i]==0)
                                         {
                                                    // on incremente le compteur si  l'element suivant est encore null
                                                    k++;
                                         }

                        } while (matrice[i][i]==0&&k<x);
                      /*  c=matrice[i][i];
                        for (n=0;n<x;n++)
                        {
                                matrice[i][n]=matrice[i][n]/c;// ici on divise la ligne du pivot par le pivot
                        }*/
                        for(k=i+1;k<x;k++)
                        {
                                for (j=x-1;j>=i;j--)
                                {
                                            matrice[k][j]=matrice[k][j]-((matrice[k][i]*matrice[i][j])/matrice[i][i]);
                                }
                       }
   }
   for (i=0;i<x;i++)
   {
       // det=l*scalaire*matrice[i][i];
       det*=l*matrice[i][i];
   }
   printf("\n");
   printf("\t###################################################\n");
   printf("\t#\t                                          #\n");
   printf("\t#  LE DETERMINANT DE CETTE MATRICE EST : %.2f\t  #\n ",det);
   printf("\t#\t                                          # \n");
   printf("\t###################################################\n");
   printf("\n\n\n\n");
   liberer(matrice,x);
   printf("\n");
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
                                DETERMINANT_1();
                            }
                            else if (a==2)
                            {
                                   system("cls");
                                   MENU();
                            }
                            else printf("\n\t veuillez entrer 2 ou 1 !\n\n");
                }while(ch!=2||ch!=1||ch!=(int)ch);
    return 0;
}

float  determinant(float  **matrice,int x)
{
     int i,j,k,m,n;
    float c,temp; temp=0;
    float  scalaire=1;
     float  det =1;
   float  l=1;
     for( i=0;i<x-1;i++)
     {
          k=i+1;
                               do
                               {
                                         if (matrice[k][i]!=0)
                                         {
                                                    for (m=0;m<x;m++)
                                                   {
                                                             temp=matrice[i][m];
                                                             matrice[i][m]=matrice[k][m]; // on permute les lignes
                                                             matrice[k][m]=temp;
                                                    }
                                                    scalaire*=matrice[i][i];
                                                    det*=-1;
                                                    l=det;
                                           }
                                         else if((k==x-1&&matrice[k-1][i]==0)&&matrice[k][i]==0)
                                         {
                                                 det=0;  return det;
                                         }
                                        else if (matrice[k][i]==0)
                                         {
                                                    k++;// on incremente le compteur si  l'element suivant est encore null
                                         }

                        } while (matrice[i][i]==0&&k<x);
                       c=matrice[i][i];
                       for (n=0;n<x;n++)
                       {
                                matrice[i][n]=matrice[i][n]/c;// ici on divise la ligne du pivot par le pivot
                       }
                       for(k=i+1;k<x;k++)
                       {
                             for (j=x-1;j>=i;j--)
                             {
                                    matrice[k][j]=matrice[k][j]-matrice[k][i]*matrice[i][j];
                             }
                       }
   }
   for (i=0;i<x;i++)
   {
        det=l*scalaire*matrice[i][i];
   }
   return det;
}
