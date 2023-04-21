#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct all_datas{
    int total_team;
    int play_choice;
    char team_name_array[15][60];

};
struct all_datas data;


//The "display_details" function displays team and player names or just team names depending on user input. It reads the data from two separate files, "team_name.txt" and "team_players.txt".
void display_details(){
    printf("\n-------------------------------------------------");
    printf("\n1.Display Team Names Only\n2. Display Team and Player Names: ");
    int choice,i;
    scanf("%d",&choice);
    if(choice==1||choice==2)
    {
    for(i=0;i<data.total_team;i++){
                printf("\n%s",data.team_name_array[i]);
            }
    switch(choice){
        case 1:{
            FILE *file;
            char ch;
            printf("\nThe name of teams in IPL are:\n");
            file = fopen("team_name.txt", "r");
            if (file == NULL) {
                printf("Error opening file.");
            }
            while ((ch = fgetc(file)) != EOF) {
                printf("%c", ch);
            }
            fclose(file);
            break;
        }
        case 2:{
            FILE *file;
            char ch;
            printf("\nThe name of teams and their players in IPL are:\n");
            file = fopen("team_players.txt", "r");
            if (file == NULL) {
                printf("Error opening file.");
            }
            while ((ch = fgetc(file)) != EOF) {
                printf("%c", ch);
            }
            fclose(file);
            break;
        }
    }
    }
    else{
        printf("Invalid Choice");
    }
    printf("\n-------------------------------------------------");
}


//The "delete_details" function deletes a team from the list of teams in the "team_name.txt" file.
void delete_details(){
    printf("\n-------------------------------------------------");
    FILE *fileptr1, *fileptr2;
    char ch;
    int delete_line, temp = 1;
    printf("\nThe name of current teams in IPL are:\n");
    fileptr1 = fopen("team_name.txt", "r");
    ch = getc(fileptr1);
   while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    //rewind
    rewind(fileptr1);
    printf(" \n Enter number of the team to be deleted:");
    scanf("%d", &delete_line);
    //open new file in write mode
    fileptr2 = fopen("team_name_updated.txt", "w");
    ch = 'A';
    while (ch != EOF)
    {
        ch = getc(fileptr1);
        //except the line to be deleted
        if (temp != delete_line)
        {
            //copy all lines in file
            putc(ch, fileptr2);
        }
        if (ch == '\n')
        {
            temp++;
        }
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove("team_name.txt");
    rename("team_name_updated.txt", "team_name.txt");
    printf("\n The updated list of teams in IPL:\n");
    fileptr1 = fopen("team_name.txt", "r");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    fclose(fileptr1);
    printf("\n-------------------------------------------------");
}


//The "player_details" function allows the user to add a team with 11 players to the "team_players.txt" file.
void player_details(){
    printf("\n-------------------------------------------------");
    struct all_datas data;
    char teamname[50]; 
    char playername[50]; 
    FILE *file;
    int i;
    file=fopen("team_players.txt","a");
    printf("\nEnter Team's Name: ");
    scanf("%s",teamname);
    fprintf(file, "\n%s\n",teamname);
    printf("\nPlease Enter Player Names:");
    for(i=0;i<11;i++){
        printf("\nPlayer %d: ",i+1);
        scanf("%s",playername);
        fprintf(file, "\n%d.",i+1);
        fprintf(file, "%s\n",playername);
    }
    fclose(file);
    printf("\n-------------------------------------------------");
}

//The "add_a_team" function adds a team to the "team_name.txt" file.
void add_a_team() {
    printf("\n-------------------------------------------------");
    struct all_datas data;
    int i=0,playchoice;
    FILE *file;
    file=fopen("team_name.txt","a"); 
    printf("\nPlease Enter the number of teams in the tournament:");
    scanf("%d", &data.total_team);
    for (i; i < data.total_team; i++) {
        printf("\nEnter the name of team:");
        scanf("%s", data.team_name_array[i]);
        fprintf(file, "%d.",i+1);
        fprintf(file, "%s\n",data.team_name_array[i]);
    }
    fclose(file);
    printf("\n-------------------------------------------------");
}

//The "print_schedule" function displays the current tournament schedule from the "schedule.txt" file.

void print_schedule(){
    FILE *file;
    //Opens the file in read mode using the fopen() function.
    file=fopen("schedule.txt","r");
    printf("The current schedule of IPL Tournament is-:\n");
    char ch;        
    if (file== NULL) {
        printf("Error opening file.");
    }
    // If the file is opened successfully, it reads the file character by character using a while loop and fgetc() function.
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    //Closes the file using fclose() function
    fclose(file);
    printf("\n-------------------------------------------------");
}


//The "tournamentschedule" function allows the user to create a tournament schedule by entering the number of matches, the teams playing each match, the date and venue of each match. It writes the schedule to the "schedule.txt" file.
void tournamentschedule() {
    // Print initial message and prompt user for number of matches
    printf("\n-------------------------------------------------");
    printf("Select the number of matches:");
    int matches, team_select, team_select2,flag=0;
    char date[20],venue[20],ch;
    FILE *file3;
    FILE *file1;
    int k=1;
    int i, currentLine=0;
    char line[100], line2[100];
    // Open team_name.txt file in read mode and schedule.txt file in append mode
    file1 = fopen("team_name.txt", "r");
    file3 = fopen("schedule.txt", "a");
    scanf("%d", &matches);
    // Print the current teams in IPL by reading team_name.txt file
    printf("The current teams in IPL are:");
    if (file1== NULL) {
                printf("Error opening file.");
            }
            while ((ch = fgetc(file1)) != EOF) {
                printf("%c", ch);
            }
    rewind(file1);
    // Prompt user for details of each match and write them to schedule.txt file
    while (matches > 0) {
        printf("\nEnter Team 1 number:");
        scanf("%d", &team_select);
        printf("\nEnter Team 2 number:");
        scanf("%d", &team_select2);
        printf("\nEnter the date of match:");
        scanf("%s", date);
        printf("\nEnter the venue of match:");
        scanf("%s", venue);
        matches--;
        currentLine = 0;
        flag=0;
        while (fgets(line, sizeof(line), file1)) {
            currentLine++;
            if (currentLine == team_select||flag==0) {
                fprintf(file3, "\nMatch %d\n", k);
                fprintf(file3, "\n%sVs\n", line);
                flag=1;
            }
            else if(currentLine == team_select2&&flag==0){
                fprintf(file3, "\nMatch %d\n", k);
                fprintf(file3, "\n%sVs\n", line);
                flag=1;
            }
            else if(currentLine == team_select && flag==1){
                fprintf(file3, "%s",line);
                fprintf(file3,"Date: %s\n",date);
                fprintf(file3,"Venue: %s\n",venue);
                rewind(file1);
                break;
            }
            else if(currentLine==team_select2 && flag==1){
                fprintf(file3, "%s",line);
                fprintf(file3,"Date: %s\n",date);
                fprintf(file3,"Venue: %s\n",venue);
                rewind(file1);
                break;
            }
        }
        k++;
    }
    // Close both files and print final message
    fclose(file1);
    fclose(file3);
    printf("\n-------------------------------------------------");
}

//The reset_documents function deletes the selected document(s) based on user input.

void reset_documents(){
    int choice;
    // Prompt the user for input
    printf("\nWhich document should be deleted?");
    printf("\n1.Team Names\n2.Player Names\n3.IPL Schedule \n4.All of the above\n");
    scanf("%d",&choice);
    // Delete the selected document(s) based on user input
    switch(choice){
        case 1:{
            remove("team_name.txt");
            printf("Action Performed Successfully!");
            printf("\n-------------------------------------------------");
            break;
        }
        case 2:{
            remove("team_players.txt");
            printf("Action Performed Successfully!");
            printf("\n-------------------------------------------------");
            break;
        }
        case 3:{
            remove("schedule.txt");
            printf("Action Performed Successfully!");
            printf("\n-------------------------------------------------");
            break;
        }
        case 4:{
            remove("team_name.txt");
            remove("team_players.txt");
            remove("schedule.txt");
            printf("Action Performed Successfully!");
            printf("\n-------------------------------------------------");
            break;
        }
    }
}
int main() {
    struct all_datas data;
    int i;
    int total_team,choice=0;
    char team_name;
    printf("-------------------------------------------------");
    printf("\nWelcome to IPL Cricket Tournament Scheduler");
    while(choice!=8){
    printf("\n1.Add a team\n2.Add Player Details\n3.Display names and player details of all teams\n4.Delete team details\n5.Updating the schedule\n6.Generate/Print the schedule\n7.Reset All documents\n8.Exit");
    printf("\nPlease select your choice:");
    scanf("%d",&choice);
    if(choice==1||choice==2||choice==3||choice==4||choice==5||choice==6||choice==7||choice==8)
    {
    switch(choice){
    case 1:{
        add_a_team();
        break;
    }
    case 2:{
        player_details();
        break;
    }
    case 3:{
        display_details();
        break;

    } 
    case 4:{
        delete_details();
        break;

    } 
    case 5:{
        tournamentschedule();
        break;

    } 
    case 6:{
        print_schedule();
        break;

    } 
    case 7:{
        reset_documents();
        break;

    } 
    }
    }
    else{
        printf("Invalid Input");
        break;
    }
    }
    printf("\n-------------------------------------------------");
    printf("Thank you for using our IPL Schedule Program.");
    printf("-------------------------------------------------");
    return 0;    
}

