#ifndef STRUCTURES_H_
#define STRUCTURES_H_


typedef struct Player
{
    char *last_name;
    char *first_name;
    int score;
} Player;


typedef struct Country
{
    char *name;
    int nr_players;
    int global_score;
    Player **players;
} Country;

typedef Player Info;

#endif