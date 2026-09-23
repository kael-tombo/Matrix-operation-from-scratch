#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include"PROTOTYPES.h"
void inverse()
{   float q,**mat_unit,**matrice_1,**matrice;
    int i,j,y,k,m,n;
    printf("\n\n\n");
   printf("\t\t###############################\n");
   printf("\t\t#\t                      #\n");
   printf("\t\t#  INVERSION D'UNE MATRICE    #");
   printf("\t\t#\t                      # \n");
   printf("\t\t###############################\n");
   printf("\n\n\n");
    printf("\t[/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/]");
   printf("\n\n\n");
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
    etiq:
    printf("\t VEUILLEZ SAISIR  LA DIMENSION DE LA MATRICE:");
    do
    {
          scanf("%f",&q);
          if (q!=(int)q||q<=0)
          {
                  printf("\n");
                  printf("\t erreur , la taille d'une matrice ne peut etre un reelle ou negatif ou null !\n");
                  printf("\n");
                  printf("\t entrer un entier positif non null!\n");
                  printf("\n");
          }
    }while(q!=(int)q||q<=0);
     n=(int)q;
    mat_unit=malloc2(n,n);
    matrice=malloc2(n,n);
    matrice_1=malloc2(n,n);
    float  c,temp,temp1;
    printf("\n\n");
    printf("\t VEUILLEZ SAISIR VOTRE MATRICE :");
    printf("\n\n");
    saisie(matrice,n,n);
    for (i=0;i< n;i++)
    {
        for (j=0;j<n;j++)
        {
            matrice_1[i][j]=matrice[i][j];
        }
    }
    // on procède a l'initialisation de la matrice unité !
    for (i=0;i<n;i++)
    {
          for (j=0;j<n;j++)
          {
                 if (i==j)
                 {
                     mat_unit[i][j]=1;
                 }
                 else mat_unit[i][j]=0;
          }
    }
       //si le determinant est non null alors on passe a l'inversion de la matrice
        if (determinant(matrice_1,n)!=0)
        {
                      for (i=0;i<n;i++)
                      {
                                k=i+1;
                                // <>si le pivot est non null alors  on transforme la matrice
                                //<>sinon on permute la ligne du pivot par la ligne suivant
                                if (matrice[i][i]==0)
                                {
                                                     do
                                                     {
                                                                  if (matrice[k][i]!=0)
                                                                  {
                                                                                  for (m=0;m<n;m++)
                                                                                  {
                                                                                            // on permute les lignes!
                                                                                             temp=matrice[i][m];
                                                                                             matrice[i][m]=matrice[k][m];
                                                                                             matrice[k][m]=temp;
                                                                                             // de même on permute aussi les lignes de la matrice  unité !
                                                                                             temp1=mat_unit[i][m];
                                                                                             mat_unit[i][m]=mat_unit[k][m];
                                                                                             mat_unit[k][m]=temp1;
                                                                                  }
                                                                  }
                                                                 else if (matrice[k][i]==0)
                                                                  {
                                                                              // on incremente le compteur si  l'element suivant est encore null
                                                                                 k++;
                                                                  }
                                                     } while (matrice[i][i]==0&&k<n);
                                }
                                /* on divise encore la ligne du pivot par le pivot pour avoir des 1 sur la diagonale de la premiere matrice
                                et on effectue le meme operation pour la matrice unite */
                                            c=matrice[i][i];
                                           for (y=0;y<n;y++)
                                           {
                                                             matrice[i][y]=matrice[i][y]/c;
                                                             mat_unit[i][y]=mat_unit[i][y]/c;
                                            }
                                 /*> premiere etape : on transforme la premiere matrice en matrice triangulaire superieure
                                   pour avoir des zero en dessous de la diagonale*/
                                            for(k=i+1;k<n;k++)
                                            {
                                                                for (j=0;j<n-1;j++)
                                                                {
                                                                                  mat_unit[k][j]=mat_unit[k][j]-mat_unit[i][j]*matrice[k][i];
                                                                }
                                                                for (j=n-1;j>=i;j--)
                                                                {
                                                                    matrice[k][j]=matrice[k][j]-matrice[k][i]*matrice[i][j];
                                                                }
                                            }
                        }
         /*>> seconde etape: une fois qu'on a une matrice triangulaire superieure ,il ne reste plus qu'a
          transformer la  matrice  en matrice unité c-a-d en effectuant le meme operation pour faire apparaitre des zeros
          au déssus de la diagonale  principale  et sans oublier de faire le même operation pour l'autre matrice! */
                    for (i=n-1;i>=0;i--)
                    {
                                          for(k=i-1;k>=0;k--)
                                          {
                                                            for (j=0;j<n;j++)
                                                            {
                                                                               mat_unit[k][j]=mat_unit[k][j]-matrice[k][i]*mat_unit[i][j];
                                                            }
                                                            for (j=0;j<n;j++)
                                                            {
                                                                               matrice[k][j]=matrice[k][j]-matrice[k][i]*matrice[i][j];
                                                            }
                                          }
                     }
                    /* ET A LA FIN  LA MATRICE INITIALE S'EST TRANSFORMER EN MATRICE UNITE ET LA MATRICE UNITE DU
          DEBUT S'EST TRANFORME EN MATRICE INVERSE ! c'est un peu complique mais il suffit juste de comprendre
          le fonctionement de l'algorithme de gauss-jordan */
                    printf("\n\n");
                    printf("\t>> L'INVERSE DE CETTE MATRICE EST  :\n");
                    printf("\n\n");
                    show_matrix(mat_unit,n);
    }
    else
    {
        printf("\tERREUR ,cette matrice n'est pas inversible car le determinant est null!\n");
        printf("\n");
        printf("\t essayer une autre matrice s'il vous plait !\n");
        printf("\n");
        goto etiq;
    }
    // >> on libère les mémoires allouès par les matrices :
    liberer(matrice_1,n);
    liberer(matrice,n);
    liberer(mat_unit,n);
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
                                inverse();
                            }
                            else if (a==2)
                            {
                                   system("cls");
                                   MENU();
                            }
                            else printf("\n\t veuillez entrer 2 ou 1 !\n\n");
                }while(ch!=2||ch!=1||ch!=(int)ch);
}
void INVERSER_MAT(float **T,float  **matrice,int n,int z)
{
    int i,j,y,k,m;
float   mat_unit[n][n];
float  **matrice_1;
    matrice_1=malloc2(n,n);
float    c,temp,temp1;
    for (i=0;i< n;i++)
    {

        for (j=0;j<n;j++)
        {
            matrice_1[i][j]=matrice[i][j];
        }
    }    printf("\n");
    for (i=0;i<n;i++)
    {
          for (j=0;j<n;j++)
          {
                 if (i==j)
                 {
                     mat_unit[i][j]=1;
                 }
                 else mat_unit[i][j]=0;
          }
    }
     float det =1;
    det=determinant(matrice_1,n);
        if (det!=0) //si le determinant est non null alors on passe a l'inversion de la matrice
        {
            z=1;
                      for (i=0;i<n;i++)
                      {
                                k=i+1;
                                // <>si le pivot est non null alors  on transforme la matrice
                                //<>sinon on permute la ligne du pivot par la ligne suivant
                                if (matrice[i][i]==0)
                                {
                                                     do
                                                     {
                                                                  if (matrice[k][i]!=0)
                                                                  {
                                                                                  for (m=0;m<n;m++)
                                                                                  {
                                                                                             temp=matrice[i][m];
                                                                                             matrice[i][m]=matrice[k][m]; // on permute les lignes
                                                                                             matrice[k][m]=temp;
                                                                                             temp1=mat_unit[i][m];
                                                                                             mat_unit[i][m]=mat_unit[k][m];// de meme on permute aussi les lignes de la matrice  unite

                                                                                             mat_unit[k][m]=temp1;
                                                                                  }
                                                                  }
                                                                 else if (matrice[k][i]==0)
                                                                  {
                                                                                 k++;// on incremente le compteur si  l'element suivant est encore null
                                                                  }
                                                   } while (matrice[i][i]==0&&k<n);
                                }
                                /* on divise encore la ligne du pivot par le pivot pour avoir des 1 sur la diagonale de la premiere matrice
                                et on effectue le meme operation pour la matrice unite */
                                            c=matrice[i][i];
                                           for (y=0;y<n;y++)
                                           {
                                                             matrice[i][y]=matrice[i][y]/c;
                                                             mat_unit[i][y]=mat_unit[i][y]/c;
                                            }
                                 /* premiere etape : on transforme la premiere matrice en matrice triangulaire superieure
                                   pour avoir des zero en dessous de la diagonale*/
                                            for(k=i+1;k<n;k++)
                                            {
                                                                for (j=0;j<n-1;j++)
                                                                {
                                                                                  mat_unit[k][j]=mat_unit[k][j]-mat_unit[i][j]*matrice[k][i];
                                                                }
                                                                for (j=n-1;j>=i;j--)
                                                                {
                                                                    matrice[k][j]=matrice[k][j]-matrice[k][i]*matrice[i][j];
                                                                }
                                            }
                        }
         /* seconde etape: une fois qu'on a une matrice triangulaire superieure ,il ne reste plus qu'a
          transformer la  matrice  en matrice unite c-a-d en effectuant le meme operation pour faire apparaitre des zero
          au dessus de la diagonale  principale  et sans oublier de faire le meme operation pour l'autre matrice! */
                    for (i=n-1;i>=0;i--)
                    {
                                          for(k=i-1;k>=0;k--)
                                          {
                                                            for (j=0;j<n;j++)
                                                            {
                                                                               mat_unit[k][j]=mat_unit[k][j]-matrice[k][i]*mat_unit[i][j];
                                                            }
                                                            for (j=0;j<n;j++)
                                                            {
                                                                               matrice[k][j]=matrice[k][j]-matrice[k][i]*matrice[i][j];
                                                            }
                                          }
                     }
                    /* ET A LA FIN  LA MATRICE INITIALE S'EST TRANSFORME EN MATRICE UNITE ET LA MATRICE UNITE DU
          DEBUT S'EST TRANFORMER EN MATRICE INVERSE ! c'est un peu complique mais il suffit juste de comprendre
          le fonctionement de l'algorithme de gauss-jordan */
    }
    else z=0;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            T[i][j]=mat_unit[i][j];
        }
    }
}
