#include <tennis_scoreboard_functions.h>

void menu()
{
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TENNIS SCOREBOARD TRACKER \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\t\t\t1.New Scorecard\n");
    printf("\t\t\t\t2.View Scorecard\n");
    printf("\t\t\t\t3.Exit\n\n\n\n\n\t\t Enter your choice:");
}

int print_points(int pointsWon)
{
    if (pointsWon == 1)
    {
        return 15;
    }
    else if (pointsWon == 2)
    {
        return 30;
    }
    else if (pointsWon == 3)
    {
        return 40;
    }
}

int current_game_score(int a_team, int b_team)
{
    if(a_team < 3 || b_team <3)
        return 1;
    else if(a_team == b_team)
        return 2;
    else
        return 3;
}

void display_score(int serve, int set_counter)
{
            /* first we are printing what team is serving */
            printf("\n\t\t\tTeam %c to serve:\n", ((serve==-1)?'A':'B'));

            /* now we print all of the completed sets scores */
            printf("\t\t\t");
            for(int i=0; i<set_counter; i++)
            {
                if( serve == -1 )
                    printf("%d-%d ", TeamA.set_scores[i], TeamB.set_scores[i]);
                else
                    printf("%d-%d ", TeamB.set_scores[i], TeamA.set_scores[i]);
            }
    
            /* now we can print the current set score */
            if( serve == -1 )
                printf("%d-%d\n", TeamA.game_wins, TeamB.game_wins);
            else
                printf("%d-%d\n", TeamB.game_wins, TeamA.game_wins);
    
            /* and now print the current game score */
            switch(current_game_score(TeamA.point_wins,TeamB.point_wins))
            {
                case 1:
                if( serve == -1 )
                {
                    if(TeamA.point_wins == 0)
                    {
                        printf("\t\t\tLove");
                    }
                    else
                    {
                        printf("\t\t\t%d", print_points(TeamA.point_wins));
                    }
                    printf("-");
                    if(TeamB.point_wins == 0)
                    {
                        printf("Love");
                    }
                    else
                    {
                        printf("%d", print_points(TeamB.point_wins));
                    }
                }
                else
                {
                    if(TeamB.point_wins == 0)
                    {
                        printf("\t\t\tLove");
                    }
                    else
                    {
                        printf("\t\t\t%d", print_points(TeamB.point_wins));
                    }
                    printf("-");
                    if(TeamA.point_wins == 0)
                    {
                        printf("Love");
                    }
                    else
                    {
                        printf("%d", print_points(TeamA.point_wins));
                    }
                }
                printf("\n");
                break;

                case 2:
                printf("\t\t\tDeuce");
                break;

                case 3:
                if(serve == -1)
                {
                    if(TeamA.point_wins > TeamB.point_wins)
                    {
                        printf("\t\t\tAdvantage Server\n");
                    }
                    else
                    {
                        printf("\t\t\tAdvantage Receiver\n");
                    }
                }
                else
                {
                    if(TeamB.point_wins > TeamA.point_wins)
                    {
                        printf("\t\t\tAdvantage Server\n");
                    }
                    else
                    {
                        printf("\t\t\tAdvantage Receiver\n");
                    }
                }
            }
            printf("\n");
}

void scoreboard(FILE *newfile)
{
    int serve = -1;         // this means that the first team to serve is team A                                         

    int set_counter = 0;    // counts ongoing number of sets                                          

    int ch,flag = 0,fault_count = 0;

    char ret = '\0';        // temp var to clear buffer

    printf("\n\tYour Name:");
    scanf("%[^\n]%*c",Match.umpire_name);
    printf("\n\tTournament:");
    scanf("%[^\n]%*c",Match.tournament);
    printf("\n\tVenue:");
    scanf("%[^\n]%*c",Match.venue);
    printf("\n\tNo Of Sets:");
    scanf("%d",&Match.number_of_sets);
    scanf("%c",&ret);                                              
    printf("\n\tSingles/Doubles(S/D):");
    scanf("%[^\n]%*c",&Match.number_of_players);
    printf("\n\tDate(dd/mm/yyyy):");
    scanf("%[^\n]%*c",Match.date);
    printf("\n\tStarting Time:");
    scanf("%[^\n]%*c",Match.start_time);
    printf("\n\tTeam A:");
    scanf("%[^\n]%*c",TeamA.team_name);
    printf("\n\tFirst Player Name:");
    scanf("%[^\n]%*c",TeamA.player_name_1);
    printf("\n\tGender(M/F/O):");
    scanf("%[^\n]%*c",&TeamA.gender[0]);
    if(Match.number_of_players=='D')
    {
        printf("\n\tSecond Player Name:");
        scanf("%[^\n]%*c",TeamA.player_name_2);
        printf("\n\tGender(M/F/O):");
        scanf("%[^\n]%*c",&TeamA.gender[1]);
    }
    printf("\n\tTeam B:");
    scanf("%[^\n]%*c",TeamB.team_name);
    printf("\n\tFirst Player Name:");
    scanf("%[^\n]%*c",TeamB.player_name_1);
    printf("\n\tGender(M/F/O):");
    scanf("%[^\n]%*c",&TeamB.gender[0]);
    if(Match.number_of_players=='D')
    {
        printf("\n\tSecond Player Name:");
        scanf("%[^\n]%*c",TeamB.player_name_2);
        printf("\n\tGender(M/F/O):");
        scanf("%[^\n]%*c",&TeamB.gender[1]);
    }
    printf("\n\tStart Tracking:");

    TeamA.point_wins=0;
    TeamB.point_wins=0;
    TeamA.game_wins=0;
    TeamB.game_wins=0;
    TeamA.set_wins=0;
    TeamB.set_wins=0;

    while ( (ch = getchar()) != EOF && flag!=1)
    {
        if (ch == 'A' || ch=='a')
        {
            TeamA.point_wins++;

            /* Checks to see if he won the game
            that means that player A won at least 4 points,
            and that the difference between the points is at least 2 */
            if (TeamA.point_wins >= 4 && (TeamA.point_wins - TeamB.point_wins) >= 2  )
            {
                TeamA.game_wins++;
                /* Now we need to check whether player A won the set
                that is he has won at least 6 games, 
                and the difference between the games won is >=2 */
                if (TeamA.game_wins >= 6 && (TeamA.game_wins - TeamB.game_wins) >= 2)
                {
                    /* Player A has won the set, so we save the set score and update the games won */
                    TeamA.set_scores[set_counter] = TeamA.game_wins;
                    TeamB.set_scores[set_counter] = TeamB.game_wins;
                    set_counter ++ ;
                    TeamA.game_wins = 0;
                    TeamB.game_wins = 0;

                    TeamA.set_wins++;
                    /* Now we check to see whether player A won the match,
                    that means that he won at least 3 sets */
                    if (TeamA.set_wins == ((Match.number_of_sets/2)+1))  
                    {
                        printf("\t\t\tGame, set, match:%s ",TeamA.team_name);
                        int i;
                        for (i=0; i<set_counter; i++)
                        {
                            printf("%d-%d ", TeamA.set_scores[i], TeamB.set_scores[i]);
                        }
                        printf("\n");
                        flag=1;
                    }

                }
                /* Player A has won the game so we can reset the points for both player */
                TeamA.point_wins = 0;
                TeamB.point_wins = 0;
                /* After every game we need to change the player serving */
                serve *= -1;
            }
            fault_count=0;
        }
        else if (ch == 'B' || ch=='b')
        {
            TeamB.point_wins++;
            /* Checks to see if he won the game
            that means that player B won at least 4 points,
            and that the diffrence between the points is at least 2 */
            if (TeamB.point_wins >= 4 && (TeamB.point_wins - TeamA.point_wins) >= 2  )
            {
                TeamB.game_wins++;
                /* Now we need to check whether player B won the set
                that is he has won at least 6 games, 
                and the difference between the games won is >=2 */
                if (TeamB.game_wins >= 6 && (TeamB.game_wins - TeamA.game_wins) >= 2)
                {
                    /* Player B has won the set, so we save the set score and update the games won */
                    TeamA.set_scores[set_counter] = TeamA.game_wins;
                    TeamB.set_scores[set_counter] = TeamB.game_wins;
                    set_counter ++ ;
                    TeamA.game_wins = 0;
                    TeamB.game_wins = 0;

                    TeamB.set_wins ++;
                    /* Now we check to see whether player B won the match,
                    that means that he won at least 3 sets */
                    if (TeamB.set_wins == ((Match.number_of_sets/2)+1))
                    {
                        printf("\t\t\tGame, set, match:%s ",TeamB.team_name);
                        int i;
                        for (i=0; i<set_counter; i++)
                        {
                            printf("%d-%d ", TeamB.set_scores[i], TeamA.set_scores[i]);
                        }
                        printf("\n");
                        flag=1;
                    }
                }
                /* Player B has won the game so we can reset the points for both player */
                TeamA.point_wins = 0;
                TeamB.point_wins = 0;
                /* After every game we need to change the player serving */
                serve *= -1;
            }
            fault_count=0;
        }
        else if(ch=='F' || ch=='f')
        {
            fault_count++;              
            if(fault_count%2==1)                                            // Single fault results only in a re-serve
            {
                printf("\t\t\tFault. Serve Again.\n");
            }
            if(fault_count%2==0)                                            // 2 consecutive faults, which results in a point addition to the reciever
            {
                printf("\t\t\tDouble Fault. Point Receiver.\n");
                if (serve == -1)
                {
                    TeamB.point_wins++;
                    if (TeamB.point_wins >= 4 && (TeamB.point_wins - TeamA.point_wins) >= 2  )
                    {
                        TeamB.game_wins++;

                        if (TeamB.game_wins >= 6 && (TeamB.game_wins - TeamA.game_wins) >= 2)
                        {
                            TeamA.set_scores[set_counter] = TeamA.game_wins;
                            TeamB.set_scores[set_counter] = TeamB.game_wins;
                            set_counter ++ ;
                            TeamA.game_wins = 0;
                            TeamB.game_wins = 0;

                            TeamB.set_wins ++;

                            if (TeamB.set_wins == ((Match.number_of_sets/2)+1))
                            {
                                printf("\t\t\tGame, set, match:%s ",TeamB.team_name);
                                int i;
                                for (i=0; i<set_counter; i++)
                                {
                                    printf("%d-%d ", TeamB.set_scores[i], TeamA.set_scores[i]);
                                }
                                printf("\n");
                                flag=1;
                            }
                        }
                        TeamA.point_wins = 0;
                        TeamB.point_wins = 0;
                        serve *= -1;
                    }
                }
                else
                {
                    TeamA.point_wins++;
                    if (TeamA.point_wins >= 4 && (TeamA.point_wins - TeamB.point_wins) >= 2  )
                    {
                        TeamA.game_wins++;

                        if (TeamA.game_wins >= 6 && (TeamA.game_wins - TeamB.game_wins) >= 2)
                        {
                            TeamA.set_scores[set_counter] = TeamA.game_wins;
                            TeamB.set_scores[set_counter] = TeamB.game_wins;
                            set_counter ++ ;
                            TeamA.game_wins = 0;
                            TeamB.game_wins = 0;

                            TeamA.set_wins++;

                            if (TeamA.set_wins == ((Match.number_of_sets/2)+1))                                        
                            {
                                printf("\t\t\tGame, set, match:%s ",TeamA.team_name);
                                int i;
                                for (i=0; i<set_counter; i++)
                                {
                                    printf("%d-%d ", TeamA.set_scores[i], TeamB.set_scores[i]);
                                }
                                printf("\n");
                                flag=1;
                            }
                        }
                        TeamA.point_wins = 0;
                        TeamB.point_wins = 0;
                        serve *= -1;
                    }
                }
            }
        }
        else if(ch=='N' || ch=='n')
        {
            printf("\t\t\tNet Serve. Serve Again\n");
        }
        else if(ch=='\n')
        {
            display_score(serve,set_counter);
        }
    }
    printf("\n\tEnding Time:");
    scanf("%[^\n]%*c",Match.end_time);

    ret='\0';

    fwrite(&Match,sizeof(Match),1,newfile);
    fwrite(&TeamA,sizeof(TeamA),1,newfile);
    fwrite(&TeamB,sizeof(TeamB),1,newfile);

    printf("\n\tPress Enter to return to main menu window");
    while(ret!='\n')
    {
        scanf("%c",&ret);
    }
}

void menu_option(int select)
{
    char pass[19],password[19]="notaseasyasitseems";
    char ret='\0';

    FILE *newfile,*filelist;
    char filename[20];
    char extension[]=".txt";
    char filenamewithdirectory[]="Files//";
    char filenamecheck[20];
    char filenamecheckvar;
    int j=0,flag=1;

    if(select==1)
    {
        system("color 30");
        printf("\n\n\t\tEnter the password to login:");
        scanf("%[^\n]%*c",pass);
        if (strcmp(pass,password)==0)
        {
            printf("\n\n\tPassword Match!\n\tLOADING");
            for(int i=0;i<=6;i++)
            {
                printf(".");
            }
            system("cls");

            printf("\n\t\t\tMATCH TRACKER WINDOW");
            filelist=fopen("Files//filelist.txt","a+");
            if(filelist==NULL)
            {
                printf(" File Listing Error...");
                exit(1);
            }
            while(flag==1)
            {
                if (flag==1)
                {
                    printf("\n\tPlease enter the new file name: ");
                    scanf(" %[^\n]%*c",filename);
                    j=0;
                }
                rewind(filelist);
                while(filenamecheckvar!=EOF)
                {
                    filenamecheckvar=fgetc(filelist);
                    filenamecheck[j]=filenamecheckvar;
                    if(filenamecheckvar=='\n')
                    {
                        filenamecheck[j]='\0';
                        j=-1;
                        if(strcmp(filenamecheck,filename)==0)
                        {
                            printf("\tFilename already exists, please give new filename.");
                            flag=1;
                            break;
                        }
                    }
                    j++;
                    flag=0;
                }
            }
            fseek(filelist,0,SEEK_END);
            fprintf(filelist,"%s",filename);
            fprintf(filelist,"\n");
            fclose(filelist);
            strcat(filename,extension);
            strcat(filenamewithdirectory,filename);
            newfile=fopen(filenamewithdirectory,"w");
            if(newfile==NULL)
                printf("Error...");
            printf("\tCreating file");
            for(int i=0;i<=6;i++)
            {
                printf(".");
            }
            printf("\n\tFile Created.");

            scoreboard(newfile);
            system("cls");
        }
        else
        {
            printf("\n\n\tWrong password, REDIRECTING\a");
            for(int i=0;i<=6;i++)
            {
                printf(".");
            }
            system("cls");
        }
    }
    else if(select==2)
    {
        system("color 80");
        system("cls");
        printf("\n\t\t\tMATCH REVIEW WINDOW\n");

        retry:
        printf("\n\tEnter the name of the existing file to open: ");
        scanf(" %[^\n]%*c",filename);
        strcat(filename,extension);
        strcat(filenamewithdirectory,filename);
        newfile=fopen(filenamewithdirectory,"r");
        if(newfile==NULL)
        {
            printf("\tError...no such existing file");
            goto retry;
        }

        fread(&Match,sizeof(Match),1,newfile);
        fread(&TeamA,sizeof(TeamA),1,newfile);
        fread(&TeamB,sizeof(TeamB),1,newfile);

        printf("\n\tYour Name:%s",Match.umpire_name);
        printf("\n\tTournament:%s",Match.tournament);
        printf("\n\tVenue:%s",Match.venue);
        printf("\n\tNo Of Sets:%d",Match.number_of_sets);
        printf("\n\tSingles/Doubles(S/D):%c",Match.number_of_players);
        printf("\n\tDate(dd/mm/yyyy):%s",Match.date);
        printf("\n\tStarting Time:%s",Match.start_time);
        printf("\n\tEnding Time:%s",Match.end_time);
        printf("\n");
        printf("\n\tTeam A:%s",TeamA.team_name);
        printf("\n\tFirst Player Name:%s",TeamA.player_name_1);
        printf("\n\tGender(M/F/O):%c",TeamA.gender[0]);
        if(Match.number_of_players=='D')
        {
            printf("\n\tSecond Player Name:%s",TeamA.player_name_2);
            printf("\n\tGender(M/F/O):%c",TeamA.gender[1]);
        }
        printf("\n");
        printf("\n\tTeam B:%s",TeamB.team_name);
        printf("\n\tFirst Player Name:%s",TeamB.player_name_1);
        printf("\n\tGender(M/F/O):%c",TeamB.gender[0]);
        if(Match.number_of_players=='D')
        {
            printf("\n\tSecond Player Name:%s",TeamB.player_name_2);
            printf("\n\tGender(M/F/O):%c",TeamB.gender[1]);
        }
        printf("\n");
        if(TeamA.set_wins>TeamB.set_wins)
        {
            printf("\n\t%s defeated %s and won by:",TeamA.team_name,TeamB.team_name);
            for(int i=0; i<Match.number_of_sets; i++)
            {
                printf("%d-%d ", TeamA.set_scores[i], TeamB.set_scores[i]);
            }
            printf("\n");
        }
        else
        {
            printf("\n\t%s defeated %s and won by:",TeamB.team_name,TeamA.team_name);
            for(int i=0; i<Match.number_of_sets; i++)
            {
                printf("%d-%d ", TeamB.set_scores[i], TeamA.set_scores[i]);
            }
            printf("\n");
        }

        printf("\n\tPress Enter to return to the main menu window");
        while(ret!='\n')
        {
            scanf("%c",&ret);
        }
        system("cls");
    }
}

