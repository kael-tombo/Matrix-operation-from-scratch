#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include"PROTOTYPES.h"
void MENU()
{
    float choix;
    int a;
    printf("\n\n\n");
    printf("\t   ############################################ \n\t   #\t                                      #\n");
    printf("\t   #\t   WELCOME TO  MATRIX OPERATION       #\n\t   #\t                                      # \n");
    printf("\t   ############################################\n");
    printf("\n\n\n\n");
    printf ("\t Pour le moment ,on a les operations matricielles suivants :\n\n\n ");
    printf("\n\n");
    printf ("\t>  1.\tADDITION DE DEUX MATRICES\n\n");
    printf ("\t>  2.\tSOUSTRACTION DE DEUX MATRICES\n\n  ");
    printf ("\t>  3.\tMULTIPLICATION DE DEUX MATRICES\n\n");
    printf("\t>  4.\tMULTIPLICATION PAR SCALAIRE \n\n ");
    printf ("\t>  5.\tDETERMINANT D'UNE MATRICE\n\n ");
    printf ("\t>  6.\tTRANSPOSITION D'UNE MATRICE\n\n  ");
    printf ("\t>  7.\tTRACE D'UNE MATRICE \n\n");
    printf("\t>  8.\tCOMBINAISON LINEAIRE \n\n");
    printf ("\t>  9.\tINVERSION D'UNE MATRICE\n\n ");
    printf("\t>  10.\tRANG D'UNE MATRICE \n\n");
    printf ("\t>  11.\tVALEUR PROPRE D'UNE MATRICE \n\n");
    printf("\t>  12.\tDIAGONALISATION D'UNE MATRICE\n\n");
    printf ("\t>  13.\tTRIANGULARISATION D'UNE MATRICE\n\n");
    printf("\t>  14.\tRESOLUTION SYSTEME LINEAIRE\n\n");
     printf("\t>  15.\tPUISSANCE \n\n");
    printf("\t>  16.\tQUITTER LE PROGRAMME  \n\n\n");
    printf ("\tQuelle operation souhaitez-vous faire ?\n");
    printf("\n\n");
    do
    {
       printf("\t VEUILLEZ SAISIR UN ENTIER S'IL VOUS PLAIT :");
       scanf("%f",&choix);
       if(choix==(int)choix)
       {
                 a=(int)choix;
                 switch(a)
                 {
                     case 1:
                           {
                               system("cls");
                               addition();
                           }break;
                     case 2:
                           {
                               system("cls");
                               soustraction();
                           }break;
                     case 3:
                           {
                               system("cls");
                               multiplication();
                           }break ;
                     case 4:
                           {
                               system("cls");
                               mult_par_scalaire();
                           }break;
                    case 5:
                          {
                               system("cls");
                               DETERMINANT_1();
                          }break;
                    case 6:
                          {
                               system("cls");
                               transpose();
                          }break;
                    case 7:
                          {
                              system("cls");
                              trace_matrice();
                          }break;
                    case 8:
                          {
                               system("cls");
                               COMBINAISON();
                          }break;
                    case 9:
                          {
                               system("cls");
                               inverse();
                          }break;
                   case 10:
                          {
                              system("cls");
                              rang_matrice();
                          }break;
                   case 11:
                          {
                               system("cls");
                               valeur_propre();
                          }
                   case 12:
                          {
                               system("cls");
                               diagonalisation();
                          }break;
                   case 13:
                          {
                                system("cls");
                                triangularisation();
                          }break;
                    case 14:
                          {
                                system("cls");
                                methode_de_gauss();
                          }break;
                    case 15:
                        {
                            system("cls");
                            puissance();
                        }
                    case 16:   exit(0);
                    default :
                           {
                     printf("\n\n");
                     printf("\t ERREUR ! veuillez entrer un entier compris entre 1 et 16! \n");
                     printf("\n\n");
                           }
              }
         }
         else
         {
                     printf("\n\n");
                     printf("\t ERREUR ! veuillez entrer un entier compris entre 1 et 16! \n");
                     printf("\n\n");
         }

    }while(choix!=(int)choix||(choix<=0||choix>16));
}
