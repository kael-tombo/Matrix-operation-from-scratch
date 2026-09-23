#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include"PROTOTYPES.h"
void diagonalisation()
{
    printf("\n\n\n");
   printf("\t\t########################################\n");
   printf("\t\t#\t                               #\n");
   printf("\t\t#     DIAGONALISATION D'UNE MATRICE    #\n ");
   printf("\t\t#\t                               # \n");
   printf("\t\t########################################\n");
   printf("\n\n\n");
   printf("\t[/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/]");
   printf("\n\n\n");
    printf("\tRAPPEL:\n");
    printf("\t______\n");
    printf("\n\n");
    printf(" \tUNE MATRICE A EST DIAGONALISABLE SI ET SEULEMENT S'IL EXISTE \n");
     printf("\n");
    printf("\tUNE MATRICE P INVERSIBLE TEL QUE D=PT*A*P SOIT DIAGONALE. \n");
    printf("\n\n");
    int dim,i=0,ok=1,j,c=1,v,k,inversible=0,yes=1;
    float  n,N,beta,dimension,**vect, **BASE,**mat_unit, **trans, **w,**matrice, **mat_result, ***M, **RESULT, **tab_temp,**O,***TAB,**t,**T,**R;
    printf("\t SAISISSEZ LA DIMENSION DE LA MATRICE : ");
    do
    {
          scanf("%f",&dimension);
          if (dimension!=(int)dimension||dimension<=0)
          {
                  printf("\t erreur , la taille d'une matrice ne peut etre un reelle ou negatif ou null !\n");
                  printf("\n");
                  printf("\t entrer un entier positif non null!\n");
                  printf("\n");
          }
    }while(dimension!=(int)dimension||dimension<=0);
    dim=(int)dimension;

      double MATRCE[100][dim][dim];
      O=malloc2(dim,dim);
      R=malloc2(dim,dim);
     T=malloc2(dim,dim);
      tab_temp=malloc2(dim,dim);
      RESULT=malloc2(dim,dim);
      TAB=malloc3(100,dim);
      // M est  la matrice contenant les W0,W1,......,Wn
       M=malloc3(dim-1,dim);
       mat_result=malloc2(dim,dim);
       t=malloc2(dim,dim);
       //allocation du matrice unite en fonction de la dimension de la matrice
       mat_unit=malloc2(dim,dim);
       // vect est le vecteur colone de la matrice  initiale
       vect=malloc2(dim,1);
       //w est la matrice temporaire pour contenir les W0,W1,...,Wn
       w=malloc2(dim,dim);
       trans=malloc2(1,dim);
       // ici BASE orthonormale  associe a la vecteur colonne
       BASE=malloc2(dim,1);
       //allocation de la matrice initiale
      matrice=malloc2(dim,dim);
      // saisie et afffichage de la matrice initiale
      printf("\n");
      printf("\t VEUILLEZ SAISIR VOTRE MATRICE : ");
      printf("\n\n");
      saisie(matrice,dim,dim);
      // on teste si la matrice saisie est quelconque ou symetrique
      // si la matrice est quelconque  on applique la transformation de hessenberg ou tridiagonalisation!
      for (i=0;i<dim;i++)
        {
            for (j=0;j<dim;j++)
            {
                 if (i!=j)
                 {
                    yes*=(matrice[i][j]==matrice[j][i]);
                 }
            }
        }
        if (!yes)
        {
                matrice=hessenberg(matrice,dim);
        }
        for (i=0;i<dim;i++)
        {
            for (j=0;j<dim;j++)
            {
                t[i][j]=matrice[i][j];
            }
        }
do
{
        for (v=0;v<dim-1;v++)
         {
                  // N  est le norme du vecteur colone
                    for (k=dim-1;k>=0;k--)
                    {
                                vect[k][0]=0;
                    }
                    for (k=v;k<dim;k++)
                    {
                                vect[k][0]=matrice[k][v];
                    }
                    //calcul de la norme du vecteur colonne
                    N=norm_vect(vect,dim,1);
                    //cette procede change le signe de la norme du vecteur colone en fonction du signe du premier element du vecteur colone
                    if (vect[v][0]!=0)
                    {
                            N*=(-1)*(vect[v][0]/fabs(vect[v][0]));

                    }
                    //initialisation de la base
                   _initial_base(BASE,N,dim,1,v);
                   //initialisation de la matrice unite
                    _initial_unit(mat_unit,dim);
                    // u=x-ae1
                     _soustraction_vetc(vect,vect,BASE,dim,1);
                     // calul du norme de u
                     n=norm_vect(vect,dim,1);

                      beta=2/pow(n,2);
                      // transposition de u
                    _transpose(trans,vect,dim,1);
                    // multiplication de la transpose de v par v
                    _multiplication(w,vect,trans,dim,1,1,dim);
                    //      2/  ||u|| au carre
                    _multi_scalaire(w,dim,dim,beta);
                    // w1= I- 2* v*Tv
                    _soustraction_vetc(w,mat_unit,w,dim,dim);
                    for (k=0;k<dim;k++)
                      {
                          for (j=0;j<dim;j++)
                          {
                              M[v][k][j]=w[k][j];
                          }
                      }
                    for (k=dim-1;k>=0;k--)
                     {
                            for (j=dim-1;j>=0;j--)
                            {
                                mat_result[k][0]=0;
                            }
                     }
                      // multiplication de w1 par la matrice initiale
                      _multiplication(mat_result,w,matrice,dim,dim,dim,dim);
                      for (i=0;i<dim;i++)
                      {
                          for (j=0;j<dim;j++)
                          {
                                 matrice[i][j]=mat_result[i][j];
                          }
                      }
         }
                      // on initialise la matrice temporaire par w1
                      for (k=0;k<dim;k++)
                      {
                          for (j=0;j<dim;j++)
                          {
                              RESULT[k][j]=M[0][k][j];
                          }
                      }
                      for (k=0;k<=dim-3;k++)
                      {
                          tab_temp=MULT(M,dim,k,RESULT);
                        /* on fait cette procede pour que le resultat de la
                          multiplication aie en parametre de la fonction durant l'execution de la boucle*/
                          for(i=0;i<dim;i++)
                          {
                              for (j=0;j<dim;j++)
                              {
                                  RESULT[i][j]=tab_temp[i][j];
                              }
                          }
                         for(i=0;i<dim;i++)
                          {
                              for (j=0;j<dim;j++)
                              {
                                  tab_temp[i][j]=0;
                              }
                          }
                     }

                      for (k=0;k<=dim-2;k++)
                      {
                          tab_temp=MULT2(M,dim,k,matrice);
                          for(i=0;i<dim;i++)
                          {
                              for (j=0;j<dim;j++)
                              {
                                  matrice[i][j]=tab_temp[i][j];
                              }
                          }
                         for(i=0;i<dim;i++)
                          {
                              for (j=0;j<dim;j++)
                              {
                                  tab_temp[i][j]=0;
                              }
                          }
                     }
                    /*
                    ici on affecte dans cette matrice tridimensionnel la matrice decomposer
                     la haut pour que l'on puisse les tester ! ici on choisi une matrice tridimensionnelle
                     car les matrice sont indicés c'est a dire que l'on peut les identifier par leur addresse!

                      */
                     for (i=0;i<dim;i++)
                     {
                               for (j=0;j<dim;j++)
                               {
                                   MATRCE[0][i][j]=0;
                               }
                     }
                     for (i=0;i<dim;i++)
                     {
                               for (j=0;j<dim;j++)
                               {
                                   MATRCE[c][i][j]=matrice[i][j];
                               }
                     }
                     /*on affecte dans cette matrice tridimensionnel les matrices q1q2....qn*/

                    for (i=0;i<dim;i++)
                     {
                               for (j=0;j<dim;j++)
                               {
                                   TAB[c-1][i][j]=RESULT[i][j];
                               }
                     }

                     /*
                        ici on test si la diagonale des deux matrice successives :
                        si elles sont egaux alors on arrete l'iteration et les valeurs propres sont  la diagonale
                      */
                           ok=1;
                           for (i=0;i<dim;i++)
                           {
                                    ok*=(MATRCE[c][i][i]==MATRCE[c-1][i][i]);
                           }
                           //ici on incremente pour avoir l'element du vecteur suivant c'est a dire la matrice suivant
                           c++;
                           if(dim<=6&&c==80)
                           {
                               ok=1;
                           }
   }while (ok==0);
                    // on initialise la matrice temporaire par q1
                    for (k=0;k<dim;k++)
                    {
                          for (j=0;j<dim;j++)
                          {
                              RESULT[k][j]=TAB[0][k][j];
                          }
                      }
                      /*

                      > Et maintenant pour avoir les vecteurs propres , il suffit de multiplier les Q1*Q2*Q3..........*Qn!
                      >  Pour multiplier tous les elements de cette matrice tridimensionel, la fonction  float **MULT (float ***mat,int dim,int dim_vect,float **m )
                        qui  prend comme paramètre la matrice tridimensionel contenant les Q1*Q2*Q3..........*Qn !
                      > Le paramètre  dim_vect s'addresse au compteur de la boucle  c'est - à -dire si on incrémente le compteur alors on passe a l'élément
                       suivant de la matrice tridimensionel (je vous invite voir les fonctionnement des fonctions )!

                      */
                      for (k=0;k<=c-3;k++)
                      {
                          tab_temp=MULT(TAB,dim,k,RESULT);
                           for(i=0;i<dim;i++)
                           {
                              for (j=0;j<dim;j++)
                              {
                                  RESULT[i][j]=tab_temp[i][j];
                              }
                           }
                         for(i=0;i<dim;i++)
                          {
                              for (j=0;j<dim;j++)
                              {
                                  tab_temp[i][j]=0;
                              }
                          }
                      }
      printf("\n");
      printf("\t apres %d iterations Les valeurs propres sont :\n",c);
      printf("\n\n");
      for (i=0;i<dim;i++)
      {
          printf("\t >> X%d= %d\n\n",i+1,matrice[i][i]);
      }
      printf("\n");
    for (i=0;i<dim;i++)
    {
        for (j=0;j<dim;j++)
        {
              R[i][j]=RESULT[i][j];
        }
    }
   INVERSER_MAT(T,RESULT,dim,inversible);// on inverse le matrice de passage
   _multiplication(tab_temp,T,t,dim,dim,dim,dim);// p-1*a
    printf("\t La matrice des vecteurs propres  :");
    printf("\n\n");
    affichage(R,dim,dim);
   O=MULTIPLICATION_MAT(tab_temp,R,dim,dim,dim,dim);
    printf("\n\n");
    printf("\t  Le matrice D=p-1*A*p :\n");
    printf("\n\n");
    affichage(O,dim,dim);

    printf("\n\n");
    if (test_diag(O,matrice,dim))
    {
         printf("\tCETTE MATRICE EST DIAGONALISABLE !\n ");
    }
    else printf("\tCETTE MATRICE N'EST PAS DIAGONALISABLE !\n");
    /*
    Dans cette partie on libere les memoires alloués dans toute la fonction
    */
   liberer(O,dim);
   liberer(R,dim);
   LIB(TAB,100,dim);
   LIB(M,dim-1,dim);
   liberer(w,dim);
   liberer(trans,1);
   liberer(BASE,dim);
   liberer(tab_temp,dim);
   liberer(RESULT,dim);
   liberer(mat_unit,dim);
   liberer(mat_result,dim);
   liberer(matrice,dim);
   liberer(vect,dim);
   liberer(T,dim);
   liberer(t,dim);
   printf("\n\n");
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
                                diagonalisation();
                            }
                            else if (a==2)
                            {
                                   system("cls");
                                   MENU();
                            }
                            else printf("\n\t veuillez entrer 2 ou 1 !\n\n");
                }while(ch!=2||ch!=1||ch!=(int)ch);
}

int test_diag(float  **M,float  **N,int dim)
{
    int yes=1,i,j;
    for (i=0;i<dim;i++)
    {
        for (j=0;j<dim;j++)
        {
              if (i!=j)
              {
                   yes*=((int)M[i][j]==(int)N[i][j]);
              }
        }
    }
    return !yes;
}
