#include <stdio.h>
#include <ctype.h>

void jerseyPrompt(int i);
void ratingPrompt(int x);
void printRoster(int jerseyNums[], int ratingNums[]);
char menu();
void updatePlayer();
void removePlayer();
void setupPlayers();

const int NUM_PLAYERS = 5;
int jerseys[5];
int ratings[5];

int main() {
    setupPlayers();
    printRoster(jerseys,ratings);
    char input = menu();
    while(input!='q')
    {
        if(input=='u')
        {
            printf("\n");
            updatePlayer();
            input = menu();
        } else if(input=='r')
        {
            printf("\n");
            removePlayer();
            input = menu();
        } else if(input=='o')
        {
            printf("\n");
            printRoster(jerseys,ratings);
            input = menu();
        } else 
        {
            printf("\n");
            printf("Invalid option\n");
            printf("\n");
            input=menu();

        }
    }
    return 0;
}

void jerseyPrompt(int i)
{
    printf("Enter player %d's jersey number:\n",i);
}

void ratingPrompt(int x)
{
    printf("Enter player %d's rating:\n",x);
}

void setupPlayers()
{
    for(int j=0;j<NUM_PLAYERS;j++)
   {
        jerseyPrompt(j+1);
        int num;
        scanf("%d",&num);
        if(num<0||num>99)
        {
            while(num<0||num>99)
            {
                printf("Invalid jersey number. ");
                jerseyPrompt(j+1);
                scanf("%d",&num);
            }

        }
        jerseys[j] = num;

        ratingPrompt(j+1);
        int rat;
        scanf("%d",&rat);
        if(rat<1||rat>10)
        {
            while(rat<1||rat>10)
            {
                printf("Invalid player rating. ");
                ratingPrompt(j+1);
                scanf("%d",&rat);
            }
        }
        ratings[j] = rat;
        printf("\n");
   }
}

void printRoster(int jerseyNums[], int ratingNums[])
{   
    printf("ROSTER\n");

    for(int k=0;k<NUM_PLAYERS;k++)
    {
        printf("Player %d -- Jersey number: %d, Rating: %d\n",k+1,jerseys[k],ratings[k]);
    }
    printf("\n");
}

char menu()
{
    printf("MENU\n");
    printf("u - Update player rating\n");
    printf("r - Replace player\n");
    printf("o - Output roster\n");
    printf("q - Quit\n");
    printf("\n");
    printf("Choose an option:\n");
    char letter;
    scanf(" %c",&letter);
   /* if(letter!='u'||letter!='r'||letter!='o'||letter!='q')
    {
        while(letter!='u'||letter!='r'||letter!='o'||letter!='q')
        {
            printf("Invalid input")
        }
    }*/
    return letter;
    
}

void updatePlayer()
{
    printf("Enter jersey number for rating update:\n");
    int change;
    int new;
    int match;
    int p1=jerseys[0];
    int p2=jerseys[1];
    int p3=jerseys[2];
    int p4=jerseys[3];
    int p5=jerseys[4];
    scanf("%d",&change);
    while((change<0||change>99)||(change!=p1&&change!=p2&&change!=p3&&change!=p4&&change!=p5))
    {
        printf("Invalid jersey number. Enter valid jersey number:\n");
        scanf("%d",&change);
    }
    for(int i=0;i<NUM_PLAYERS;i++)
    {
        if(jerseys[i]==change)
        {
            match=i;
        }
    }
    printf("Found jersey number. Enter new rating for player:\n");
    scanf("%d",&new);
    while(new<1||new>10)
    {
        printf("Invalid player rating. Enter valid rating:\n");
        scanf("%d",&new);
    }
    ratings[match]=new;
    printf("\n");
}

void removePlayer()
{
    printf("Enter jersey number to replace:\n");
    int change;
    int newj;
    int newr;
    int match;
    int p1=jerseys[0];
    int p2=jerseys[1];
    int p3=jerseys[2];
    int p4=jerseys[3];
    int p5=jerseys[4];
    scanf("%d",&change);
    while((change<0||change>99)||(change!=p1&&change!=p2&&change!=p3&&change!=p4&&change!=p5))
    {
        printf("Invalid jersey number. Enter valid jersey number:\n");
        scanf("%d",&change);
    }
    for(int i=0;i<NUM_PLAYERS;i++)
    {
        if(jerseys[i]==change)
        {
            match=i;
        }
    }
    printf("Found player. Enter new jersey number:\n");
    scanf("%d",&newj);
    while(newj<0||newj>99)
    {
        printf("Invalid jersey number. Enter valid jersey number:\n");
        scanf("%d",&newj);
    }
    jerseys[match] = newj;

    printf("Enter player rating:\n");
    scanf("%d",&newr);
    while(newr<1|| newr>10)
    {
        printf("Invalid player rating. Enter valid rating:\n");
        scanf("%d",&newr);
    }
    ratings[match]=newr;
    printf("\n");

}