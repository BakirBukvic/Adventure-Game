#include "big-m.h"

void win (Player *player,Region *region){


 FILE *file;

    file = fopen("score.txt", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }


    fprintf(file,"-------------------\n");
    fprintf(file, "Uspjesno pobjegao od horora Gracanicke kanalizacije: %s\n",player->ime);
    fprintf(file, "Hrabri: %s\n", player->stats.klasa);
    fprintf(file, "Pokupio sa sobom zlata: %d\n", player->inventory.zlato);

    for (int i=0;i<5;i++){

        if (strcmp(player->inventory.items[i], ".") != 0) {
            fprintf(file, "Ponijeo sa sobom: %s\n", player->inventory.items[i]);
        }
    }
    




    fprintf(file,"-------------------\n");
   
    fclose(file);










    system("cls");
    printf("Pobjedio si :) ");
    int x;
    scanf("%d",x);


}


void loose (Player *player, Region *region){
    FILE *file;

 
    file = fopen("mezar.txt", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

 
    fprintf(file,"-------------------\n");
    fprintf(file, "RIP: %s\n",player->ime);
    fprintf(file, "Hrabri: %s\n", player->stats.klasa);
    fprintf(file, "Ubijen od strane: %s\n", regions[player->inRegion].enemy.ime);
    fprintf(file, "Ubijen u regiji: %d\n", player->inRegion);




    fprintf(file,"-------------------\n");
   
    fclose(file);

    system("cls");
    printf("Izgubio si :( ");
     int x;
    scanf("%d",x);

}




void checkInventory(Player *player,char unos) {
    

    do {
        system("cls");
        printf("Inventory: \n");

        for (int i = 0; i < 5; i++) {
            printf("| [%d] %s | \n", i, player->inventory.items[i]);
        }
        printf("Zlatnici: %d\n", player->inventory.zlato);


        printf("Q je izlaz iz inventorya\n");
        printf("D je izbacivanje itema\n");
        unos = _getch();

        switch (unos) {
            case 'q':
                
                return;

            case 'd':
                printf("Unesite broj itema koji zelite da izbacite\n");
                int broj;
                scanf("%d", &broj);
              
                for (int i=0; i<5; i++){
                  
                  if (broj==i){

                if (strcmp(player->inventory.itemTypes[broj], "+Attack") == 0) {

                    player->stats.attack=player->stats.attack-5;
                 
                 
                  
                  
                }

                 else if (strcmp(player->inventory.itemTypes[broj], "+UkupanHp") == 0) {

                    player->stats.constHealth=player->stats.constHealth-5;
                 
             
                  
                  
                }

                   




    



                        strcpy(player->inventory.items[broj], ".");
                  }


                      
                            
                           
                   
                }

            


        }
    } while (1); 
}





void initalPosition(Player *player, Region *region){ 

    Region *region0 = &regions[0]; 
    player->oldChar = '.'; 


    
    player->position.y= region0->position.y+1;
    player->position.x= region0->position.x+2;

    player->inRegion=0; 

    }; 





void movement(Player *player, World *world, Region *region, char unos){


        int newX, newY;

        world->data[player->position.y][player->position.x] = player->oldChar;   


      
        switch (unos){
            case 'w':
                newY = player->position.y - 1;
                newX = player->position.x;


                
                break;
            case 's':
                newY = player->position.y + 1;
                newX = player->position.x;


            
                break;
            case 'd':
                newX = player->position.x + 1;
                newY = player->position.y;

                break;
            case 'a':
                newX = player->position.x - 1;
                newY = player->position.y;

            
                break;
            default:
                return; 
        }

     





        char newArea = world->data[newY][newX]; 

    

        if (newArea == '.' || newArea == '=' || newArea == VRATA) {  
        
        
       
         if ((newX==5 && newY==11)){
            printf("Troll: Stomp Stomp Stomp");
            sleep(1);
          
         }


        // ovo spasava karakter na koji player ide, da u sledecoj iteraciji loopa moze da ga vrati na staro mjesto
            player->oldChar = world->data[newY][newX];


            // salje u player strukturu nove kordinate playera

            player->position.y = newY;
            player->position.x = newX;
          
        }



        // ako player zeli ici na poziciju trenutnog enemya, pokrece combatSistem. 

   
       else if (newArea == regions[player->inRegion].enemy.constKarakter) {


               initiateCombat(player, region);
               
        }


else if (newArea=='^'){
    player->win=1;
    
}



// item pickup
    else if (newArea=='A' || newArea=='D' || newArea=='H'){


char *arrayOfStrings[] = {"Razbijeno Staklo", "Sumljiva Igla", "Zub Krokodila"};
char *arrayOfStrings2[] = {"Kartonski stit", "Perfektno ocuvana jakna", "Stakorska kapa"};


int randomIndex = rand() % 3;
char *randomString = arrayOfStrings[randomIndex];
char *randomString2 = arrayOfStrings2[randomIndex];




        regions[player->inRegion].item.pickedUp=1;
       
       
            player->position.y = newY;
            player->position.x = newX;

        


 

    
int itemAssigned;

for (int i=0; i<5; i++){
    itemAssigned = 0;
    switch (regions[player->inRegion].item.karakter)
    {
        case 'A':
            for (int j=0; j<5; j++) {
                if (strcmp(player->inventory.items[j], ".") == 0) {
                    strcpy(player->inventory.items[j], randomString);
                     printf("Pokupio si: %s \n",randomString);
                      sleep (2);
                    strcpy(player->inventory.itemTypes[j], "+Attack");
                    player->stats.attack=player->stats.attack+5;
                    itemAssigned = 1;
                    break;
                }
            }
            break;
        case 'D':
            for (int j=0; j<5; j++) {
                if (strcmp(player->inventory.items[j], ".") == 0) {
                    strcpy(player->inventory.items[j], randomString2);
                     printf("Pokupio si: %s \n",randomString2);
                      sleep (2);
                    strcpy(player->inventory.itemTypes[j], "+UkupanHp");
                    player->stats.constHealth=player->stats.constHealth+5;
                    itemAssigned = 1;
                    break;
                }
            }
            break;
        case 'H':
            printf ("Potpuno si izljicen\n");
            sleep (2);
            player->stats.health= player->stats.constHealth;
            itemAssigned = 1;
            break;
    }
    if (itemAssigned) break;
}
    }


else if (newArea=='z'){


    
    int random = rand() % 6 + 5;

    player->inventory.zlato=player->inventory.zlato+random;
    printf("Pokupio si %d zlatnika\n", random);
    sleep(2);
    regions[player->inRegion].zlato.pickedUp=1;
            player->position.y = newY;
            player->position.x = newX;
    



}



}
    // inicijalizira playera na mjesto deklarisano u funkciji movement
    void initPlayer(Player *player, World *world) {
    

    // postavlja world data na kordinatama playera u karakter koji je player izabro u funkciji kreator
        world->data[player->position.y][player->position.x] = player->karakter;
    }

// pocetna funkcija za deklarisanje imena playera i njegovog zeljenog znaka





void ime (Player *player){


    printf("Unesite vase ime:\n");
    scanf("%19s", player->ime);
     while (getchar() != '\n');

}



   void kreator (Player *player) {
   

 
   

    printf(" Pao si kroz labavi saht\n Nalazis se u mracnoj prostoriji.\n");
    printf(" Ispred sebe vidis stari kostur\n");
    printf(" Kostur u ruci drzi: \n1.Mac \n2.Magicni stap \n3.Luk i strijele\n");

    int unos = _getch();
 
    while(unos!='1' && unos!='2' && unos!='3'){
        printf("Unesite 1,2, ili 3\n");
        unos = _getch();


        
    }
int odabir = unos - '0';

    switch (odabir)
    {
        case 1:
            player->karakter = 'W';
            strcpy(player->stats.klasa, "Warrior");
            initalStatsPlayer(player,odabir);
            break;
        case 2:
            player->karakter = 'M';
            initalStatsPlayer(player,odabir);
            strcpy(player->stats.klasa, "Mage");
            break;
        case 3:
            player->karakter = 'A';
            initalStatsPlayer(player,odabir);
            strcpy(player->stats.klasa, "Archer");
            break;
    }
}


