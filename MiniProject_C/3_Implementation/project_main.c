#include <tennis_scoreboard_functions.h>

int main()
{
    int select;

    while(1)
    {
        start_again:
        system("color 0a");
        menu();
        scanf("%d",&select);
        system("cls");
        switch(select)
        {
            case 1:
            menu_option(1);
            goto start_again;
            case 2:
            menu_option(2);
            goto start_again;
            case 3:
            system ("cls");
            exit(0);
        }
    }

    // on start of the match, no points, no games, no sets are won by either players


    /*  we need a place for us to save the set scores
        so we will make 2 arrays one for player A set scores
        and the other for player B set scores, and in that array
        in position 0 we will save the scores of the first set,
        on position 1 score of the second set and so on*/
    /* the result can be at most 3:2, so the max number of sets is 5 */

}

