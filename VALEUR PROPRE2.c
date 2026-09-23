#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include"PROTOTYPES.h"
int valeur_propre()
{
    int Nb_iteration=0,dim,i,j,v,k,vrai=1,yes=1;
    float  **vect, **tab_temp,**t,**RESULT,***M,**mat_result,**matrice,**w,**trans,**mat_unit,**BASE,beta,n,N,dimension;
    printf("\n\n\n");
    printf("\t\t########################################\n");
    printf("\t\t#\t                               #\n");
    printf("\t\t#      VALEUR PROPRE D'UNE MATRICE     #\n ");
    printf("\t\t#\t                               # \n");
    printf("\t\t########################################\n");
    printf("\n\n\n\n");
    /*

    Pour la recherche des valeurs propres, on utilise l'algorithme QR et de Householder:

    >> on factorise la matrice de la forme A=QR.

    >> l'algorithme g?n?re une suite de matrice semblable ? la matrice initiale.

    >> A la convergence, les elements diagonaux de la matrice de convergence correspondent aux valeurs propres de la matrice initiale .

    */
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
    }
    while(dimension!=(int)dimension||dimension<=0);
    dim=(int)dimension;
    Pile Chaine=NouvellePile();
    t=malloc2(dim,dim);
    matrice=malloc2(dim,dim); //allocation de la matrice initiale
    printf("\n\n");
    printf("\t VEUILLEZ ENTRER  UNE MATRICE :");
    printf("\n\n");
    saisie(matrice,dim,dim); // saisie et afffichage de la matrice initiale
   affecter(t,matrice,dim);
    for (i=0; i<dim; i++)
    {
        for (j=0; j<dim; j++)
        {
            if (i!=j)
            {
                yes*=(matrice[i][j]==matrice[j][i]);
            }
        }
    }
    if (!yes)
    {
        for (i=1; i<dim; i++)
        {
            vrai*=(matrice[i][0]==0);
        }
        if (!vrai)
        {
            matrice=hessenberg(matrice,dim);
        }
    }

    while (!Convergence(Chaine,dim))
    {
          // >allocation des matrices
        {
            tab_temp=malloc2(dim,dim);
            RESULT=malloc2(dim,dim);
            M=malloc3(dim-1,dim);
            mat_result=malloc2(dim,dim);
            mat_unit=malloc2(dim,dim);
            vect=malloc2(dim,1);
            w=malloc2(dim,dim);
            trans=malloc2(1,dim);
            BASE=malloc2(dim,1);
        }
        for (v=0; v<dim-1; v++)
        {
           // N  est le norme du vecteur colonne
            for (k=dim-1; k>=0; k--)
            {
                vect[k][0]=0;
            }
            for (k=v; k<dim; k++)
            {
                vect[k][0]=matrice[k][v];
            }
            //calcul de la norme du vecteur colonne
            N=norm_vect(vect,dim,1);
            /*cette procede change le signe de la norme du vecteur colone en fonction du signe du premier element du vecteur colone*/
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
            for (k=0; k<dim; k++)
            {
                for (j=0; j<dim; j++)
                {
                    M[v][k][j]=w[k][j];
                }
            }
            for (k=dim-1; k>=0; k--)
            {
                for (j=dim-1; j>=0; j--)
                {
                    mat_result[k][0]=0;
                }
            }
            _multiplication(mat_result,w,matrice,dim,dim,dim,dim); // multiplication de w1 par la matrice initiale
             affecter(matrice,mat_result,dim);
        }
        for (k=0; k<dim; k++)
        {
            for (j=0; j<dim; j++)
            {
                RESULT[k][j]=M[0][k][j];// on initialise la matrice temporaire par w1
            }
        }
        for (k=0; k<=dim-3; k++)
        {
            /* on multiplie les w1w2......wn*/
            tab_temp=MULT(M,dim,k,RESULT);
            affecter(RESULT,tab_temp,dim);
        }
        InitialiserAZero(tab_temp,dim);
        for (k=0; k<=dim-2; k++)
        {
            // on multiplie R par w1w2.....wn
            tab_temp=MULT2(M,dim,k,matrice);
            affecter(matrice,tab_temp,dim);
        }
        Chaine=Empiler(Chaine,matrice,dim);
        {
            LIB(M,dim-1,dim);
            liberer(w,dim);
            liberer(trans,1);
            liberer(BASE,dim);
            liberer(tab_temp,dim);
            liberer(RESULT,dim);
            liberer(mat_unit,dim);
            liberer(mat_result,dim);
            liberer(vect,dim);
        }
        Nb_iteration++;
        if (Nb_iteration>30&&dim<5)  break;
    }
    printf("\n\n");
    printf("\tApres %d iterations , Les valeurs propres de la matrice sont :\n",Nb_iteration);
    printf("\n\n");
    for (i=0; i<dim; i++)
    {
        printf("\t >>  X%d = %d\n\n",i+1,(int)Round(matrice[i][i]));
    }
    printf("\n\n");
    CalculMultipliciteEtDimDeEspaceVectAssocieA1Vp(matrice,t,dim);
    printf("\n\n\n");
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
        printf("\t    saisissez 1 ou 2:");
        scanf("%f",&ch);
        a=(int)ch;
        if (a==1)
        {
            system("cls");
            valeur_propre();
        }
        else if (a==2)
        {
            system("cls");
            MENU();
        }
        else
            printf("\n\t veuillez entrer 2 ou 1 !\n\n");
    }
    while(ch!=2||ch!=1||ch!=(int)ch);
    liberer(matrice,dim);
    return 0;
}

int Convergence(Pile Chaine,int dim)
{
    /*
    >  On sait que a la convergence , les elements diagonaux  des matrices  d?compos?s ne change plus !
    >  Alors on test si les diagonales des deux matrices qui se suivent sont ?gaux ! Si oui , on arr?te l'iteration
       et le(s) valeur(s) propre(s)  sont la diagonale  sinon on continue .
    >  Et pour liberer la memoire , d?s que le test est fini alors on supprime la premi?re ?lement de pile a l'aide de la fonction  ""DeleteFirstElement(Chaine,dim);""
    */
    int ok=1,i;
    if (longueur(Chaine)>1)
    {
        for (i=0; i<dim; i++)
        {
            ok*=(Chaine->Matrix[i][i]==Chaine->next->Matrix[i][i]);
        }

        if (!ok)
        {
            Chaine=DeleteFirstElement(Chaine,dim);
        }
        else
        {
           Chaine=NettoyerPile(Chaine,dim);
        }
        return ok;
    }
    else
         return 0;
}

Pile NettoyerPile(Pile st,int dim)
{
    maillon *temp;
    if (PileVide(st))
           return NouvellePile();

    temp=st->next;
    liberer(st->Matrix,dim);
    free(st);

    return  NettoyerPile(temp,dim);
}

int  longueur(Pile st)
{
    int length=0;
    while (!PileVide(st))
    {
        length++;
        st=st->next;
    }
    return length;
}

int  length_stack(Stack st)
{
    int length=0;
    while (!is_empty_stack(st))
    {
        length++;
        st=st->next;
    }
    return length;
}

void InitialiserAZero(float **matrice,int dim)
{
    int i,j;
    for (i=0; i<dim; i++)
    {
        for (j=0; j<dim; j++)
        {
            matrice[i][j]=0;
        }
    }
}

void CalculMultipliciteEtDimDeEspaceVectAssocieA1Vp(float **Mat,float **MatInit,int dim)
{
    int Count1,Count2,Tp1=1;
    Stack Vp=new_stack(),Temp;
    float  **matrice,Tp;
    matrice=malloc2(dim,dim);
    if (is_empty_stack(Vp))

        for (Count1=0; Count1<dim; Count1++)
        {
            Tp=1;
            Temp=Vp;
            if (is_empty_stack(Vp))
            {
                affecter(matrice,MatInit,dim);
                for (Count2=0; Count2<dim; Count2++)
                {
                    matrice[Count2][Count2]-=Round(Mat[Count1][Count1]);
                }
                for (Count2=Count1+1; Count2<dim; Count2++)
                {
                    Tp+=(Round(Mat[Count1][Count1])==Round(Mat[Count2][Count2]));
                }
                Vp=push_Stack(Vp,Round(Mat[Count1][Count1]),(int)Tp,(dim-Rang_Matrice_Pour_valeur_Propre(matrice,dim)));
            }
            else if (Count1!=0&&((int)Round(Mat[Count1][Count1])==(int)Round(Mat[Count1-1][Count1-1])))    continue;
            else
            {
                while (!is_empty_stack(Temp))
                {
                    Tp1*=((int)Round(Temp->value)!=(int)Round(Mat[Count1][Count1]));
                    Temp=Temp->next;
                }
                if (Tp1==1)
                {
                    affecter(matrice,MatInit,dim);
                    for (Count2=0; Count2<dim; Count2++)
                    {
                        matrice[Count2][Count2]-=Round(Mat[Count1][Count1]);
                    }
                    for (Count2=Count1+1; Count2<dim; Count2++)
                    {
                        Tp+=(Round(Mat[Count1][Count1])==Round(Mat[Count2][Count2]));
                    }
                    Vp=push_Stack(Vp,Round(Mat[Count1][Count1]),(int)Tp,(dim-Rang_Matrice_Pour_valeur_Propre(matrice,dim)));
                }
            }
        }
    /*

     > On test si la multiplicit? de la valeur propre correspond ? la dimension de l'espace vectorielle associ?  !

     > Si elles correspondent alors la matrice est diagonalisable !

     > Sinon la matrice n'est pas diagonalisable !

    */

Tp1=1;

int dimension=0;

if (length_stack(Vp)==dim)  printf("\n>> Puisque toutes les valeurs prores sont distinctes \n\n , alors la matrice que vous avez saisie est diagonalisable ! (d'apres le theoreme 9)\n");
else
{
            while (!is_empty_stack(Vp))
            {
                printf("\n\t>> Valeur propre :  %d \n\n\t   multiplite :  %d \n\n\t   Dimension de l'EV associe : %d  \n\n ",(int)Round(Vp->value),Vp->multipliciter,Vp->Dim_espace_Vect_Associe);
                Tp1*=(Vp->multipliciter>=Vp->Dim_espace_Vect_Associe);
                dimension+=Vp->Dim_espace_Vect_Associe;
                Vp=Vp->next;
            }
            if (Tp1==1&&dimension==dim)  printf("\n\n\t>>> la matrice que vous avez saisie est diagonalisable ! \n\n");
            else   printf("\n\n\t>>> la matrice que vous avez saisie n'est pas diagonalisable ! \n\n");

}
    Vp=clear_stack(Vp);
    liberer(matrice,dim);
}

int Rang_Matrice_Pour_valeur_Propre(float  **matrice,int dim)
{
    int i,j,k,m,n;
    float rang=0, c,temp=0;
    for( i=0; i<dim; i++)
    {
        if (matrice[i][i]==0&&i!=dim-1)
        {
            k=i+1;
            do
            {
                if (matrice[k][i]!=0)
                {
                    for (m=0; m<dim; m++)
                    {
                        temp=matrice[i][m];
                        matrice[i][m]=matrice[k][m]; // on permute les lignes
                        matrice[k][m]=temp;
                    }
                }
                else if (matrice[k][i]==0&&k!=dim-1)
                {
                    k++;// on incremente le compteur si  l'element suivant est encore null
                }
                else if (matrice[k][i]==0&&k==dim-1)
                {
                    k=i+1;
                    do
                    {
                        if (matrice[i][k]!=0)
                        {
                            for (m=0; m<dim; m++)
                            {
                                temp=matrice[m][i];
                                matrice[m][i]=matrice[m][k];    // on permute les colonnes
                                matrice[m][k]=temp;
                            }
                        }
                        else if (matrice[i][k]==0)
                        {
                            k++;// on incremente le compteur si  l'element suivant est encore null
                        }
                        else if (matrice[i][k]==0&&k==dim-1)       goto etiq;

                    }
                    while (matrice[i][k]==0&&k<dim);
                }
            }
            while (matrice[i][i]==0&&k<dim);
            if (matrice[i][i]!=0)
            {
                c=matrice[i][i];
                for (n=0; n<dim; n++)
                {
                    matrice[i][n]=matrice[i][n]/c;
                }
                for(k=i+1; k<dim; k++)
                {
                    for (j=dim-1; j>=i; j--)
                    {
                        matrice[k][j]=matrice[k][j]-matrice[k][i]*matrice[i][j];
                    }
                }
            }
        }
        else if (abs((int)matrice[i][i])!=0)
        {
            c=matrice[i][i];

            for (n=0; n<dim; n++)
            {
                matrice[i][n]=matrice[i][n]/c;
            }

            for(k=i+1; k<dim; k++)
            {
                for (j=dim-1; j>=i; j--)
                {
                    matrice[k][j]=matrice[k][j]-matrice[k][i]*matrice[i][j];
                }
            }
        }
    }

etiq:
    for (i=0; i<dim; i++)
    {
        if (matrice[i][i]==1)
        {
            rang+=matrice[i][i];
        }
    }
    return (int)rang;
}

Stack new_stack()
{
    return NULL;
}

int is_empty_stack(Stack st)
{
    if (st==NULL)
        return 1;
    else
        return 0;
}

int PileVide(Pile st)
{
    if (st==NULL)
        return 1;
    else
        return 0;
}

Pile NouvellePile()
{
    return NULL;
}

Stack clear_stack(Stack st)
{
    ValeurPropre *element;

    if (is_empty_stack(st))
        return new_stack();

    element=st->next;
    free(st);

    return clear_stack(element);
}

Pile DeleteFirstElement(Pile st,int dim)
{
    Pile M;
    M=st->next;
    st->next=NouvellePile();
    liberer(M->Matrix,dim);
    free(M);
    return st;
}

Stack push_Stack(Stack st, float Tp,int Mult,int DimEspVectAssocie)
{
    ValeurPropre *Vp;
    // allocation de la  liste pour contenir le(s) valeur(s) propre(s)!
    Vp=malloc(sizeof(*Vp));

    if (Vp==NULL)
    {
        fprintf(stderr, "erreur d'allocation");
        exit(EXIT_FAILURE);
    }

    Vp->value=Tp;
    Vp->multipliciter=Mult;
    Vp->Dim_espace_Vect_Associe=DimEspVectAssocie;
    Vp->next=st;

    return Vp;
}

Pile Empiler(Pile st,float **matrice,int dim)
{
    maillon *M;
    M=malloc(sizeof(*M));
    if (M==NULL)
    {
        fprintf(stderr, "erreur d'allocation");
        exit(EXIT_FAILURE);
    }
    M->Matrix=malloc2(dim,dim);
    affecter(M->Matrix,matrice,dim);
    M->next=st;
    return M;
}

void affecter(float **M,float **N,int dim)
{
    int i,j;
    for (i=0; i<dim; i++)
    {
        for (j=0; j<dim; j++)
        {
            M[i][j]=N[i][j];
        }
    }
}

void _multi_scalaire(float **mat,int li,int co,float  scal)
{
    int i,j;
    for (i=0; i<li; i++)
    {
        for (j=0; j<co; j++)
        {
            mat[i][j]=scal*mat[i][j];
        }
    }
}
float  **malloc2 ( int dim1, int dim2 )
{
    float  **m;
    int i;
    m=(float **)calloc(dim1,sizeof(float *));
    for (i=0; i<dim1; i++)
    {
        m[i]=(float*)calloc(dim2,sizeof(float));
    }
    return m;
}
void _initial_base(float  **mat,float  norm,int li,int co,int count)
{
    int i,j;
    for (i=0; i<li; i++)
    {
        for (j=0; j<co; j++)
        {
            if (i==count)
            {
                mat[i][j]=norm;
            }
            else
                mat[i][j]=0;
        }
    }
}
void _initial_unit(float  **mat,int k)
{
    int i,j;
    for (i=0; i<k; i++)
    {
        for (j=0; j<k; j++)
        {
            if (i==j)
            {
                mat[i][i]=1;
            }
            else
                mat[i][j]=0;
        }
    }
}
void initial_vect(float  **result,float  **mat,int li,int w)
{
    int i;
    int m=0;
    for (i=0; i<li; i++)
    {
        for (m=w; m<li; m++)
        {
            result[0][i]=mat[m][w];
        }
    }
}
void _transpose(float  **result,float  **mat,int li,int co)
{
    int i,k;
    for (i=0; i<co; i++)
    {
        for (k=0; k<li; k++)
        {
            result[i][k]=mat[k][i];
        }
    }
}
float  norm_vect(float  **mat,int li,int co )
{
    int i,j;
    float temp=0;
    for (i=0; i<li; i++)
    {
        for (j=0; j<co; j++)
        {
            temp+=pow(mat[i][j],2);
        }
    }

    return (float)sqrt(temp);
}

void _soustraction_vetc(float **result,float  **mat,float  **b,int li,int co)
{
    int i,j;
    for (i=0; i<li; i++)
    {
        for (j=0; j<co; j++)
        {
            result[i][j]=mat[i][j]-b[i][j];
        }
    }
}

void _multiplication(float  **result,float  **mat1,float **mat2,int li1,int co1,int li2,int co2)
{
    int i,j,k;
    for(i=0; i<li1; i++)
    {
        for(k=0; k<co2; k++)
        {
            result[i][k]=0;
            for(j=0; j<co1; j++)
            {
                result[i][k]+=mat1 [i][j]*mat2 [j][k];
            }
        }
    }
}

float  **MULTIPLICATION_MAT(float  **mat1,float   **mat2,int li1,int co1,int li2,int co2)
{
    float  **result;
    result=malloc2(li1,co2);
    int i,j,k;
    for(i=0; i<li1; i++)
    {
        for(k=0; k<co2; k++)
        {
            result[i][k]=0;
            for(j=0; j<co1; j++)
            {
                result[i][k]+=mat1 [i][j]*mat2 [j][k];
            }
        }
    }
    return result;
}

void affichage(float  **mat,int li,int co)
{
    int i,j;
    printf("\n\n\n");
    for (i=0; i<li; i++)
    {
        for (j=0; j<co; j++)
        {
            printf("\t %f",mat[i][j]);
        }
        printf("\n\n");
    }
    printf("\n\n\n");
}

float  **MULT (float  ***mat,int dim,int dim_vect,float  **m )// avec m est la matrice M[0][i][j]
{
    float  **mat_temp;
    mat_temp=malloc2(dim,dim);
    int i,j,k;
    for(i=0; i<dim; i++)
    {
        for(k=0; k<dim; k++)
        {
            mat_temp[i][k]=0;
            for(j=0; j<dim; j++)
            {
                mat_temp[i][k]+=m[i][j]*mat[dim_vect+1][j][k];
            }
        }
    }
    return mat_temp;
}
float **MULT2 (float ***mat,int dim,int dim_vect,float   **m )// avec m est la matrice M[0][i][j]
{
    float   **mat_temp;
    mat_temp=malloc2(dim,dim);
    int i,j,k;
    for(i=0; i<dim; i++)
    {
        for(k=0; k<dim; k++)
        {
            mat_temp[i][k]=0;
            for(j=0; j<dim; j++)
            {
                mat_temp[i][k]+=m[i][j]*mat[dim_vect][j][k];
            }
        }
    }
    return mat_temp;
}
float  ***malloc3(int dim1,int dim2)/* ici dim1 va contenir le nombre de matrice dans le tableau unidimensinnel et
dim2 la dimension des matrices */
{
    float   ***m;
    int i,j;
    m=(float ***)calloc(dim1,sizeof(float **));
    for (i=0; i<dim1; i++)
    {
        m[i]=(float **)calloc(dim2,sizeof(float*));
    }
    for (i=0; i<dim1; i++)
    {
        for(j=0; j<dim2; j++)
        {
            m[i][j]=(float *)calloc(dim2,sizeof(float ));
        }
    }
    return m;
}
void liberer (float  **mat,int dim1)
{
    int i;
    for (i=0; i<dim1; i++)
    {
        free(mat[i]);
    }
    free(mat);
}
void LIB(float ***mat,int dim1,int dim2)
{
    int i,j;
    for (i=0; i<dim1; i++)
    {
        for (j=0; j<dim2; j++)
        {
            free(mat[i][j]);
        }
    }
    for (i=0; i<dim1; i++)
    {
        free(mat[i]);
    }
    free(mat);
}
/* Helper function: parses a string containing either a float or a fraction (a/b) */
int parse_float_or_fraction(const char *str, float *result)
{
    float num, den;

    // Check if the input is in fraction format: "a/b"
    if (sscanf(str, "%f/%f", &num, &den) == 2)
    {
        if (den == 0.0f)
        {
            printf("  [Erreur] Division par zero impossible.\n");
            return 0; // Failure
        }
        *result = num / den;
        return 1; // Success
    }

    // Otherwise, check for a standard float or integer: "a"
    if (sscanf(str, "%f", &num) == 1)
    {
        *result = num;
        return 1; // Success
    }

    printf("  [Erreur] Format invalide. Entrez un nombre (ex: 3.5) ou une fraction (ex: 1/10).\n");
    return 0; // Failure
}

void saisie(float **mat, int lign, int co)
{
    int i, j;
    char buffer[64];

    // Predefined 9x9 matrix from your data
    static const float preset[9][9] = {
        { 1.0000f, -2.0000f,  0.0000f,  0.0000f, -3.0000f,  4.0000f,  0.5000f, -7.0000f, -9.0000f},
        { 0.0000f,  2.0000f,  4.0000f,  5.0000f, -0.3333f,  7.0000f,  0.0000f,  1.0000f,  1.0000f},
        {-2.0000f,  4.0000f,  7.0000f, 17.0000f, -0.1000f, -5.0000f,  1.0000f,  7.0000f,  2.0000f},
        { 2.0000f, 12.0000f, 73.0000f, 21.0000f, -0.2000f,  1.0000f,  2.0000f, -7.0000f,  1.0000f},
        { 2.0000f, -0.0909f, -5.0000f,  7.0000f,  1.0000f, 11.0000f,  1.0000f,  2.0000f,  2.0000f},
        { 3.0000f, -6.0000f,  1.0000f, -5.0000f,  1.0000f,  3.0000f,  3.0000f,  4.0000f,  0.0000f},
        { 0.0000f,  0.0000f,  0.0000f, -7.0000f,  1.0000f,  2.0000f,  2.0000f, -0.2000f,  1.0000f},
        { 1.0000f,  2.0000f, -6.0000f,  1.0000f,  3.0000f,  4.0000f,  5.0000f,  6.0000f, 77.0000f},
        { 1.0000f,  2.0000f,  0.0000f,  0.0000f,  0.0000f, -1.0000f,  2.0000f, 69.0000f, 67.0000f}
    };

    char choice = 'n';
    if (lign == 9 && co == 9)
    {
        printf("\nCharger la matrice 9x9 par defaut ? (o/n) : ");
        if (scanf(" %c", &choice) == 1 && (choice == 'o' || choice == 'O' || choice == 'y' || choice == 'Y'))
        {
            for (i = 0; i < 9; i++)
            {
                for (j = 0; j < 9; j++)
                {
                    mat[i][j] = preset[i][j];
                }
            }
            goto affichage;
        }
    }

    // Manual input fallback (supports fractions like 1/10 or -1/63)
    for (i = 0; i < lign; i++)
    {
        printf("\n");
        for (j = 0; j < co; j++)
        {
            int valid = 0;
            while (!valid)
            {
                printf("\t M[%d,%d] = ", i + 1, j + 1);
                if (scanf("%63s", buffer) != 1) return;
                valid = parse_float_or_fraction(buffer, &mat[i][j]);
            }
        }
    }

affichage:
    printf("\n\n\t La matrice saisie est :\n\n");
    for (i = 0; i < lign; i++)
    {
        for (j = 0; j < co; j++)
        {
            printf("\t %8.4f", mat[i][j]);
        }
        printf("\n\n");
    }
    printf("\n");
}

void show_matrix(float **mat_unit, int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        // Visual brackets for matrix display
        char left_bracket  = (n == 1) ? '[' : (i == 0 ? '/' : (i == n - 1 ? '\\' : '|'));
        char right_bracket = (n == 1) ? ']' : (i == 0 ? '\\' : (i == n - 1 ? '/' : '|'));

        printf("    %c ", left_bracket);

        for (j = 0; j < n; j++)
        {
            // Avoid displaying "-0.00000" caused by floating-point precision
            float val = mat_unit[i][j];
            if (fabs(val) < 1e-6f) {
                val = 0.0f;
            }

            // %11.5f ensures fixed column width so columns stay straight
            printf("%11.5f ", val);
        }

        printf("%c\n", right_bracket);
    }
    printf("\n");
}

float  Round (float valeur)
{
    return floor(valeur+0.5);
}
