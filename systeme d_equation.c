#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include"PROTOTYPES.h"
void resolution_systeme()
{
    printf("\n");
    printf("\t                   Merci d'avoir choisi :\n");
    printf("\n");
    printf("\t                   RESOLUTION SYSTEME LINEAIRE  \n");
    printf("\t                   ____________________________");
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

    >> pour la resolution d'un systeme lineaire,on utilise la mathode de GAUSS-SEIDDEL qui a pour principe:
    >rendre la matrice diagonal dominant

    */
    printf("un systeme d'equation est de la forme Ax=b avec A une matrice carré et x,b des vecteurs colonne dont x l'inconnue!\n\n ");
    float **matrice,*b,dimension,*vect,tp,*mat,*M,**matrice1;
    int dim,i,k,j,c=1,ok;
    do
    {
          printf("\t veuillez entrer la dimension de la matrice :");
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
    matrice=malloc2(dim,dim);
    b=calloc(dim,sizeof(float));
    vect=calloc(dim,sizeof(float));
    mat=calloc(dim,sizeof(float));
    M=calloc(1000,sizeof(float));
    matrice1=malloc2(dim,dim);
    etiq :
    printf("\n");
    printf("\t veuillez saisir la matrice A:\n");
    saisie(matrice,dim,dim);
    printf("\n");
    printf("\t Puis le vecteur colonne b :\n");
    printf("\n");
    for (i=0;i<dim;i++)
    {
        for (j=0;j<dim;j++)
        {
            matrice1[i][j]=matrice[i][j];
        }
    }
    for (i=0;i<dim;i++)
    {
        printf("\t b[%d]=",i+1);
        scanf("%f",&b[i]);
    }
   if (determinant(matrice1,dim)!=0)
    {
           diagonal_dominant(matrice,b,dim);
           do
           {
                   for (i=0;i<dim;i++)
                   {
                          vect[i]=0;
                   }
                   for (i=0;i<dim;i++)
                   {
                           tp=0;
                           for (j=0;j<dim;j++)
                           {
                                  k=j;
                                  if (i!=j&&k!=i)
                                  {
                                          tp+=((-1)*mat[k]*matrice[i][j]);
                                  }
                            }
                            vect[i]=(tp+b[i])*(1/matrice[i][i]);
                    }
                    for (i=0;i<dim;i++)
                     {
                           mat[i]=vect[i];
                     }
                    M[c]=vect[0];
                     ok=(M[c]==M[c-1]);
                     c++;
                     if (c==50)
                     {
                         ok=1;
                     }
            }while (ok==0);
    }
    else
    {
        printf("\t le determinant de cette matrice est null ! saisissez une autre matrice\n\n");
        printf("\n");
        goto etiq;
    }
        printf("\n\n");
        for (i=0;i<dim;i++)
        {
                  printf("\t X%d=%.2f\n\n",i+1,vect[i]);
        }
        /*on libere les memoires alloués*/
        liberer(matrice,dim);
        liberer(matrice1,dim);
        free(vect);
        free(M);
        free(b);
        free(mat);
        printf("\n\n\n");
        float ch;
       printf("\t 1-si vous-voulez faire un nouveau calcul \n");
       printf("\n");
       printf("\t 2-Aller au menu principale \n");
       printf("\n\n");
       do
       {
            printf("\t saisissez 1 ou 2:");
            scanf("%f",&ch);
            if (ch==1)
            {
                    system("cls");
                    resolution_systeme();
            }
            else if (ch==2)
            {
                    system("cls");
                    MENU();
            }
            else printf("\n\t veuillez entrer 2 ou 1 !\n");
            printf("\n");
        }while((ch!=2||ch!=1)||ch!=(int)ch);
}

void methode_de_gauss()
{
    printf("\n\n\n");
   printf("\t\t######################################\n");
   printf("\t\t#\t                             #\n");
   printf("\t\t#    RESOLUTION SYSTEME LINEAIRE     #\n ");
   printf("\t\t#\t                             # \n");
   printf("\t\t######################################\n");
   printf("\n\n\n\n");
    printf("\tun systeme d'equation est de la forme Ax=b avec A une matrice carre \n ");
    printf("\n");
    printf("\tet x,b des vecteurs colonne dont x l'inconnue!\n");
       printf("\n\n");
    float  **matrice,*b,dimension,*vect,tp,temp,*mat,**matrice1;
    int dim,i,k,j,m,n,c;
    do
    {
          printf("\t veuillez entrer la dimension de la matrice :");
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
    matrice=malloc2(dim,dim);
    b=calloc(dim,sizeof(float ));
    vect=calloc(dim,sizeof(float ));
    mat=calloc(dim,sizeof(float ));
    matrice1=malloc2(dim,dim);
    etiq :
    printf("\n");
    printf("\t veuillez saisir la matrice A:\n");
    saisie(matrice,dim,dim);
    printf("\n");
    printf("\t Puis le vecteur colonne b :\n");
    printf("\n");
    for (i=0;i<dim;i++)
    {
        for (j=0;j<dim;j++)
        {
            matrice1[i][j]=matrice[i][j];
        }
    }
    for (i=0;i<dim;i++)
    {
        printf("\t b[%d]=",i+1);
        scanf("%f",&b[i]);
    }
   if (determinant(matrice1,dim)!=0)
    {
                      for( i=0;i<dim-1;i++)
                      {
                                if (matrice[i][i]==0)
                                {
                                      k=i+1;
                                      do
                                      {
                                                  if (matrice[k][i]!=0)
                                                  {
                                                         for (m=0;m<dim;m++)
                                                         {
                                                                      temp=matrice[i][m];
                                                                      matrice[i][m]=matrice[k][m]; // on permute les lignes
                                                                      matrice[k][m]=temp;
                                                          }
                                                                      tp=b[i];
                                                                      b[i]=b[k];
                                                                      b[k]=tp;
                                                    }
                                                   else if (matrice[k][i]==0)
                                                   {
                                                            k++;// on incremente le compteur si  l'element suivant est encore null
                                                   }
                                       } while (matrice[i][i]==0&&k<n);
                                }
                               c=matrice[i][i];
                               b[i]=b[i]/c;
                               for (n=0;n<dim;n++)
                               {
                                      matrice[i][n]=matrice[i][n]/c;
                               }
                              for(k=i+1;k<dim;k++)
                              {
                                          b[k]=b[k]-b[i]*matrice[k][i];
                                          for (j=dim-1;j>=i;j--)
                                          {
                                                   matrice[k][j]=matrice[k][j]-matrice[k][i]*matrice[i][j];
                                          }
                              }
                        }
              for (i=dim-1;i>=0;i--)
              {
                          tp=0;
                           for (j=dim-1;j>=0;j--)
                           {
                                  if (i!=j)
                                  {
                                          tp+=((-1)*mat[j]*matrice[i][j]);
                                  }
                            }
                            vect[i]=(tp+b[i])/matrice[i][i];
                            mat[i]=vect[i];
             }
    }
    else
    {
        printf("\n\n");
        printf("\t le determinant de cette matrice est null ! saisissez une autre matrice\n\n");
        printf("\n\n");
        goto etiq;
    }
        printf("\n\n");
        printf("\t les solutions du systeme sont :\n\n");
        for (i=0;i<dim;i++)
        {
                  printf("\t>> X%d=%.1f\n\n",i+1,vect[i]);
        }
        /*on libere les memoires alloués*/
        liberer(matrice,dim);
        liberer(matrice1,dim);
        free(vect);
        free(b);
        free(mat);
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
                                methode_de_gauss();
                            }
                            else if (a==2)
                            {
                                   system("cls");
                                   MENU();
                            }
                            else printf("\n\t veuillez entrer 2 ou 1 !\n\n");
                }while(ch!=2||ch!=1||ch!=(int)ch);
}
void puissance()
{
    printf("\n\n\n");
   printf("\t\t###############################\n");
   printf("\t\t#\t                      #\n");
   printf("\t\t#   PUISSANCE D'UNE MATRICE   #\n ");
   printf("\t\t#\t                      # \n");
   printf("\t\t###############################\n");
   printf("\n\n\n\n");
    float  **matrice,**matrice1,dimension;
    int i,j,k,dim,p;
    do
    {
          printf("\t veuillez entrer la dimension de la matrice :");
          scanf("%f",&dimension);
          if (dimension!=(int)dimension||dimension<=0)
          {
                  printf("\t erreur , la taille d'une matrice ne peut etre un reelle ou negatif ou null !\n");
                  printf("\n");
                  printf("\t entrer un entier positif non null!\n");
                  printf("\n");
          }
    }while(dimension!=(int)dimension||dimension<=0);
    printf("\n\n");
    do
    {
            printf("\t veuillez saisir l'exposant(puissance):");
            scanf("%d",&p);
            if (p!=(int)p||p<=1)
            {
                printf("\t erreur ,l'exposant d'une matrice ne peut etre inferieure a 2!\n");
                printf("\n");
                printf("\t entrer un entier positif non null !\n");
            }
    }while(p!=(int)p||p<2);
    dim=(int)dimension;
    matrice=malloc2(dim,dim);
    matrice1=malloc2(dim,dim);
    saisie(matrice,dim,dim);
    affecter(matrice1,matrice,dim);
    for (k=0;k<p-1;k++)
    {
         matrice=MULTIPLICATION_MAT(matrice,matrice1,dim,dim,dim,dim);
    }
    printf("\n\n");
    printf("\t l'exposant %d de la matrice A est : \n",p);
    printf("\n");
    affichage(matrice,dim,dim);
   printf("\n\n\n\n");
   printf("\t[/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/#/]");
   printf("\n\n\n");
             float  ch;
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
