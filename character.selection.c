
#include <stdio.h>

int selectClass(){


  int selectedClass = 0;

// beskonacna while petlja, iskljuci se kada je dobra selekcija

//*pukne kada se uneste text umjesto broja*
    while (1) { 
//*pukne kada se uneste text umjesto broja*



//ISPIS=========================================================================

        printf("Izaberi klasu:\n");
        printf("  1) Vitez\n  2) Carobnjak\n  3) Lopov\n");

        scanf("%d", &selectedClass);

//ISPIS=========================================================================


// iskljuci while petlju ako je dobra selekcija
        if (selectedClass >= 1 && selectedClass <= 3) {
            break; 
            
      
        } else {
            printf("Ne nudimo broj: %d, molimo izaberitie broj od 1-3\n",selectedClass);
        }
    }
return  selectedClass;



 }

 int onSelectedKlasa(){

int odabir=selectClass();

    
 switch (odabir) {
        case 1:
            printf("\n Vitez si ");
         
            break;

        case 2:
             printf("\n Carobnjak  si ");
          
            break;

        case 3:
            printf("\n Lopov  si ");
         
            break;

        default:
          
            printf("Neocekivana greska.\n");

}

return odabir;
 }



 char *selectName(){

    static char selectedName[20];
    printf("Kako se zovete? \n");
    scanf("%s", selectedName );
    return selectedName;


}

