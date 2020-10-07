/**
* @file tennis_scoreboard_functions.h
* Tennis scoreboard structures and functions implemented in this project
*
*/
#ifndef __TENNIS_SCOREBOARD_FUNCTIONS_H__
#define __TENNIS_SCOREBOARD_FUNCTIONS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct match
{
    int number_of_sets;             // No. of sets in the match
    char tournament[20];            // Name of tournament
    char venue[20];                 // Name of venue
    char number_of_players;         // Singles/Doubles
    char date[11];                  // Date in dd\mm\yyyy format
    char start_time[6];             // Match start time in 24 hour standard format(hh:mm)
    char end_time[6];               // Match end time in 24 hour standard format(hh:mm)
    char umpire_name[20];           // Chair umpire's name

}Match;

struct team
{
    char team_name[20];             // Name of team
    char player_name_1[20];         // Name of first player
    char player_name_2[20];         // Name of second player(only in doubles)
    char gender[2];                 // Male/Female/Other
    int set_scores[5];              // Games won by ethe teams are stored here
    int set_wins;                   // Count sets won by the team in a match
    int game_wins;                  // Counts games won by the team in a set
    int point_wins;                 // Counts points won by the team in a game

}TeamA,TeamB;                       // Here Team A is the team which serves first

/**
*  Function to print the main menu
*/
void menu();

/**
*  Converts integer points into actual tennis points
* @param[in] pointsWon
* @return Result is 15, 30 or 45
*/
int print_points(int pointsWon);

/**
*  Used to select required format to print current game score
* @param[in] a_team
* @param[in] b_team
* @return Result is either of the 3 integer values for selection
*/
int current_game_score(int a_team, int b_team);

/**
*  Displays the current score
* @param[in] serve
* @param[in] set_counter
*/
void display_score(int serve, int set_counter);

/**
*  Used to track an official tennis match
* @param[in] newfile
*/
void scoreboard(FILE *newfile);

/**
*  Used to perform the 2 main menu operations
* @param[in] select
*/
void menu_option(int select);

#endif  /* #define __TENNIS_SCOREBOARD_FUNCTIONS_H__ */
