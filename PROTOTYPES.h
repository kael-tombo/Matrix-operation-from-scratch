#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED
typedef struct VP
{
    float  value;
    int multipliciter;
    int Dim_espace_Vect_Associe;
    struct VP *next;
}ValeurPropre,*Stack;
typedef struct Maille
{
    float **Matrix;
    struct Maille *next;
}*Pile,maillon;
void show_matrix(float **mat_unit, int n);
int parse_float_or_fraction(const char *str, float *result);
int  length_stack(Stack st);
Pile NettoyerPile(Pile st,int dim);
float  Round (float valeur);
int PileVide(Pile st);
Stack clear_stack(Stack st);
Pile NouvellePile();
Pile DeleteFirstElement(Pile st,int dim);
int  longueur(Pile st);
Stack push_Stack(Stack st,float Tp,int Mult,int DimEspVectAssocie);
int Convergence(Pile Chaine,int dim);
void InitialiserAZero(float **matrice,int dim);
int is_empty_stack(Stack st);
Pile Empiler(Pile st ,float **matrice,int dim);
Stack new_stack();
void affecter(float  **M,float  **N,int dim);
void CalculMultipliciteEtDimDeEspaceVectAssocieA1Vp(float **Mat,float  **MatInit,int dim);
int Rang_Matrice_Pour_valeur_Propre(float **matrice,int dim);
int valeur_propre();
void triangularisation();
void MENU();
int DETERMINANT_1();
void transpose();
void mult_par_scalaire ();
void trace_matrice();
void multiplication();
void  addition();
void soustraction();
void inverse();
void rang_matrice();
void COMBINAISON();
void liberer (float  **mat,int dim1);
void LIB(float ***mat,int dim1,int dim2);
float  ***malloc3(int dim1,int dim2);
float  **MULT2 (float  ***mat,int dim,int dim_vect,float **m );
float **MULT (float ***mat,int dim,int dim_vect,float  **m );
float  **malloc2 ( int dim1, int dim2 );
void saisie (float  **mat,int lign,int co );
void _multi_scalaire(float  **mat,int li,int co,float  scal);
void _initial_unit(float **mat,int k);
void initial_vect(float  **result ,float **mat ,int li,int w);
void _transpose(float  **result,float  **mat,int li,int co);
float  norm_vect(float  **mat,int li,int co );
void _soustraction_vetc(float  **result ,float  **mat,float  **b,int li,int co);
void _multiplication(float  **result,float  **mat1,float  **mat2,int li1,int co1,int li2,int co2);
void affichage(float **mat,int li,int co);
void _initial_base(float **mat,float  norm,int li ,int co,int count);
float  determinant(float  **matrice,int x);
void diagonalisation();
void INVERSER_MAT(float **T,float **matrice,int n,int z);
float ** hessenberg(float **matrice,int dim);
int test_diag(float **M,float **N,int dim);
float **MULTIPLICATION_MAT(float  **mat1,float  **mat2,int li1,int co1,int li2,int co2);
void diagonal_dominant (float ** matrice,float *vect,int dim);
void resolution_systeme();
void methode_de_gauss();
void puissance();
#endif // PROTOTYPES_H_INCLUDED
