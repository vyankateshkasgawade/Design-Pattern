#include <stdio.h>
#include <string.h>
#define MAX_PLAYERS 20 

// Define the structure for a player
 typedef struct Player 
{
    int jerseyNumber;
    char name[20];
    int runs;
    int wickets;
    int matchesPlayed;
}Player ;

void addplayer();
void removeplayer();
void searchplayerbyjerseynumber();
void searchplayerbyname();
void updateplayerdata();
void displayTop3PlayersByRuns();
void displayallplayers();

Player players[MAX_PLAYERS];	//[MAX_PLAYERS] specifies the size of the array
int playerCount = 0;			// the variable it is used to store the count of players in the system
int jerseyNumber; //store the jerseyno,searching for a player by jerseyno.,removing & update a player by jerseyno.
char playerName[20];	//store & searching

int main()
{
    int choice; 
	do{
        printf("\n............Player Management System.............\n");
        printf(" 1. Add Player\n");
        printf("2. Remove Player\n");
        printf("3. Search Player by Jersey Number\n");
        printf("4. Search Player by Name\n");
        printf("5. Update Player Data\n");
        printf("6. Display Top 3 Players\n");
        printf("7. Display All Players\n");
        printf("8. Exit\n");
        printf("...............................................\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
		 {
           case 1:
			{
               addplayer();
            }
            break;
              
            case 2:
			 {
               removeplayer();
            }
             break;
             
            case 3: 
			{
                searchplayerbyjerseynumber();
            }
             break;
             
            case 4:
			 {
                searchplayerbyname();
            }
             break;
             
            case 5: 
			{
                updateplayerdata();
            }
             break;
            
            case 6:
			 {
               displayTop3PlayersByRuns();
            }
             break;
             
             case 7:
			 {
			 	
              displayallplayers();
            }
             break;
             
            case 8: 
			{
                printf("Exiting the program.\n");
                return 0;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }

   }while(choice!=8);
}

void  addplayer()
{
  if (playerCount < MAX_PLAYERS)	//checks number of players currently in the system
	{
       Player newPlayer;			//  newPlayer is variable and datatype is Player
        printf("\n");        
        printf("Enter Jersey Number: ");
        scanf("%d", &newPlayer.jerseyNumber);
        
        printf("Enter Player Name: ");
        scanf(" %s", newPlayer.name);
        
        printf("Enter Runs: ");
        scanf("%d", &newPlayer.runs);
        
        printf("Enter Wickets: ");
        scanf("%d", &newPlayer.wickets);
        
        printf("Enter Matches Played: ");
        scanf("%d", &newPlayer.matchesPlayed);
        
  //newly player stored in the newPlayer variable &into the array at the position indicated by playerCount
        players[playerCount] = newPlayer; 
        playerCount++; //after adding a new player to the array, playerCount is incremented 
        
        printf("\nPlayer added successfully.\n");
         printf("...............................................\n");
     } 
	else
	 {
        printf("Maximum player limit reached. Cannot add more players.\n");
     }
   
              
}
void removeplayer()
{
	
    printf("Enter Jersey Number of the player to remove: ");
    scanf("%d", &jerseyNumber);
    
    int i, j;
    for (i = 0; i < playerCount; i++) //This loop iterates through the list of players 
	{
        if (players[i].jerseyNumber == jerseyNumber) //checks current player jno.and user search jno. is same 
		{
            for (j = i; j < playerCount - 1; j++) //playerCount-1 position of the player to be removed
			 {
			 
                players[j] = players[j + 1];	// removes the player from the array.
				                             
            }
            playerCount--;
            
            printf("Player removed successfully.\n");
          
        }
        else if (i == playerCount) 	// if the loop completes (i.e., i becomes equal to playerCount)
        {
          printf("Player with Jersey Number %d not found.\n", jerseyNumber);
    } 
  }  
}

void searchplayerbyjerseynumber()
{
	    printf("Enter Jersey Number of the player to search: ");
	    scanf("%d", &jerseyNumber);
	    
	    int i,flag;
	    for (i = 0; i < playerCount; i++) //This loop iterates through the list of players 
		{
	        if (players[i].jerseyNumber == jerseyNumber) //current player jno.and user search jno. is same then pf
			{
	            printf("Jersey Number: %d\n", players[i].jerseyNumber);
	            printf("Player Name: %s\n", players[i].name);
	            printf("Runs: %d\n", players[i].runs);
	            printf("Wickets: %d\n", players[i].wickets);
	            printf("Matches Played: %d\n", players[i].matchesPlayed);
	            flag =1;
	        }
	       else if (flag!=1) 	// if the loop completes (i.e., i becomes equal to playerCount)
		 {
	        printf("Player with Jersey Number %d not found.\n", jerseyNumber);
	    }
	}
}

void searchplayerbyname()
{
    printf("Enter Player Name to search: ");
    scanf(" %s", playerName);
    
    int i,flag;
    for (i = 0; i < playerCount; i++) 
	 {
        if (strcmp(players[i].name, playerName) == 0) //strcmp use for string comparison
		{
            printf("Jersey Number: %d\n", players[i].jerseyNumber);
            printf("Player Name: %s\n", players[i].name);
            printf("Runs: %d\n", players[i].runs);
            printf("Wickets: %d\n", players[i].wickets);
            printf("Matches Played: %d\n", players[i].matchesPlayed);
        	flag =1;
        }
    
    else if (flag != playerCount) 
	 {
        printf("Player with name '%s' not found.\n", playerName);
     }
 }
}

void  updateplayerdata()
{
	printf("Enter Jersey Number of the player to update: ");
	scanf("%d", &jerseyNumber);
	
	int i,flag;
	for (i = 0; i < playerCount; i++) 
	{
	    if (players[i].jerseyNumber == jerseyNumber) 
		{
	        printf("Enter new Runs: ");
	        scanf("%d", &players[i].runs);//pass the memory address of the runs field of the player whose data is updated
	        
	        printf("Enter new Wickets: ");
	        scanf("%d", &players[i].wickets);
	        
	        printf("Enter new Matches Played: ");
	        scanf("%d", &players[i].matchesPlayed);
	        
	        printf("Player data updated successfully.\n");
	        
	        flag =1;
	   
	    }
		else if (flag != playerCount) 
		{
	    	printf("Player with Jersey Number %d not found.\n", jerseyNumber);
		}
   }
}
void displayTop3PlayersByRuns()
{
 int i,j;  // Sort players based on runs (you can use any sorting algorithm)
    for ( i = 0; i < playerCount - 1; i++) 
	 {
        for ( j = 0; j < playerCount - i - 1; j++) 
		  {
            if (players[j].runs < players[j + 1].runs)   
			 {
                // Swap players[j] and players[j + 1]               
                players[j] = players[j + 1];     
				  Player temp = players[j];
				  	 players[j + 1] = temp;
            }       
		 }
    }
    // Display the top 3 players by runs    printf("Top 3 Players by Runs:\n");
    for (i = 0; i < playerCount && i < 3; i++)
	  { 
	  	
	  		
        	printf("%d. %s - Runs: %d\n", i + 1, players[i].name, players[i].runs); 
        	
        
	   }
}

void displayallplayers()
{
	printf("All Players:\n");
	int i;
	
	for (i = 0; i < playerCount; i++)
	 {
	    printf("\n...................Player %d....................\n",i+1);
	    printf("Jersey Number: %d\n", players[i].jerseyNumber);
	    printf("Player Name: %s\n", players[i].name);
	    printf("Runs: %d\n", players[i].runs);
	    printf("Wickets: %d\n", players[i].wickets);
	    printf("Matches Played: %d\n", players[i].matchesPlayed);
	     printf(".................................................\n");
	}
}                                      
