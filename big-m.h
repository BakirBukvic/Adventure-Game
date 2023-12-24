 
#ifndef ROGUE_H
#define ROGUE_H

 #include <stdio.h>
    #include <stdlib.h>
    #include <Windows.h>
    #include <conio.h>
    #include <time.h>
    #define HODNJIK 35
    #define VRATA 15
    #define ZID 186
    #define PLAFON 205
    #define LIJEVIG 201
    #define DESNIG 187
    #define LIJEVID 200
    #define DESNID 188
    #define HEIGHT 18
    #define WIDTH 80






typedef struct{
    int x,y;
}Position; 


typedef struct{

    int health;
    int attack;

    int constHealth;
    int constAttack;


}Stats;

typedef struct{
    Position position;
    char karakter;
    char constKarakter;
    char oldChar;
    Stats stats;
    int alive;

} Enemy;



// Strukture i tipovi


    typedef struct {
    Position position;
    char karakter;
    char oldChar;
    char ime[20];
    Stats stats;
    int alive;
    int inRegion;

        }Player;


    typedef struct {
        char data[HEIGHT][WIDTH];
            } World;



        // krene od tacke x i y te se siri prema desno. 
        typedef struct {
            Position position; 
            int width, height;
            char fillCharacter;
            int regionSize;
            Position doors[4];
            Enemy enemy;


                } Region;

        // array regija
       

     Region regions[5];





     void initWorld(World *world);
      void initalPosition(Player *player, Region *region);
        void movement(Player *player, World *world, Region *region);
        void initPlayer(Player *player, World *world);
         void kreator(Player *player);
         void regionIntoWorld(Region *region, World *world);
         void regionInit(Region *region, int startY, int startX, int height, int width, char fillCharacter);
         void initializeRegions(World *world);
          void doorL(Region *region, World *world,int index, int brVrata);
          void doorR(Region *region, World *world, int index, int brVrata );
          void doorT(Region *region, World *world, int index, int brVrata );
          void doorB(Region *region, World *world, int index, int brVrata );
           void initializeDoors(World *world, Region *region);
           void enemyInit( Region *region, World *world);
            void enemySpawnActivation(Player *player, Region *region, World *world);
            void putXOnEdges(World *world);
            int connectDoors(World *world, int r1, int r2, int door1, int door2);
            void initHallways(World *world);
             void playerHealth(Player *player);
             void enemiesIntoWorld(World *world, Region *region);
            void initalStatsEnemy(Region *region);
            void initiateCombat(Player *player, Region *region);
            void checkHealth(Region *region);
        void initalStatsPlayer(Player *player, int odabir);

     #endif