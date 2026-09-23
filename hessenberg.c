#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include"PROTOTYPES.h"
float ** hessenberg(float **matrice,int dim)
{
       int i,j,k,v;
       // BASE est la base orthonormale  associe a la vecteur colone
        //N est le norme du vecteur colone
       // ici vect est le vecteur colone de la matrice  initiale
      float **mat_unit, n,**mat_result,**vect,**BASE,**trans,**w,**tab_temp,N,beta;
       mat_result=malloc2(dim,dim);
       mat_unit=malloc2(dim,dim);//allocation du matrice unite en fonction de la dimension de la matrice
       vect=malloc2(dim,1);
        tab_temp=malloc2(dim,dim);
        w=malloc2(dim,dim);
        trans=malloc2(1,dim);
        BASE=malloc2(dim,1);
        for (v=1;v<dim-1;v++)
         {
                    for (k=dim-1;k>=0;k--)
                    {
                                vect[k][0]=0;
                    }
                    for (k=v;k<dim;k++)
                    {
                                vect[k][0]=matrice[k][v-1];
                    }
                    N=norm_vect(vect,dim,1);//calcul de la norme du vecteur colonne
                    /*
     <>  l'instruction suivante change le signe de la norme du vecteur colone en fonction du signe du premier element du vecteur colonne
                    */
                    if (vect[v][0]!=0)
                    {
                            N*=(-1)*(vect[v][0]/fabs(vect[v][0]));
                    }
                   _initial_base(BASE,N,dim,1,v);//initialisation de la base
                    _initial_unit(mat_unit,dim);//initialisation de la matrice unite
                     _soustraction_vetc(vect,vect,BASE,dim,1);// u=x-ae1
                     n=norm_vect(vect,dim,1);// calul du norme de u
                     beta=2/pow(n,2);
                    _transpose(trans,vect,dim,1);// transposition de u
                      _multiplication(w,vect,trans,dim,1,1,dim);// multiplication de la transpose de v par v
                    _multi_scalaire(w,dim,dim,beta); //      2/  ||u|| au carre
                    _soustraction_vetc(w,mat_unit,w,dim,dim);// w1= I- 2* v*Tv
                      _multiplication(mat_result,w,matrice,dim,dim,dim,dim); // multiplication de w1 par la matrice initiale
                      for (i=0;i<dim;i++)
                      {
                          for (j=0;j<dim;j++)
                          {
                                 matrice[i][j]=mat_result[i][j];
                          }
                      }
                    _multiplication(tab_temp,matrice,w,dim,dim,dim,dim);
                       for (i=0;i<dim;i++)
                      {
                          for (j=0;j<dim;j++)
                          {
                                 matrice[i][j]=tab_temp[i][j];
                          }
                      }
         }

        liberer(mat_result,dim);
        liberer(mat_unit,dim);
        liberer(vect,dim);
        liberer(BASE,dim);
        liberer(trans,dim);
        liberer(w,dim);
        liberer(tab_temp,dim);

return   matrice;

}

void diagonal_dominant (float ** matrice,float *vect,int dim)
{
     int i,k,ind,m,ok=1;
     float  temp,tp;
     for (i=0;i<dim-1;i++)
     {
          k=i+1;
          temp=matrice[i][i];
           while (k<dim)
           {
                 if (temp<matrice[k][i])
                 {
                     temp=matrice[k][i];
                     ind=k;
                 }
                 ok*=(matrice[i][i]>=matrice[k][i]);
                 k++;

           }
           if (!ok)
           {
                    for (m=0;m<dim;m++)
                    {
                             tp=matrice[i][m];
                              matrice[i][m]=matrice[ind][m]; // on permute les lignes
                             matrice[ind][m]=tp;
                    }
                        tp=vect[i];
                        vect[i]=vect[ind];
                        vect[ind]=tp;
           }


    }
}
