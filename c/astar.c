#include <stdio.h>
#include <stdlib.h>
#define MAXCOLCOUNT 32
void printGrid(char grid[][MAXCOLCOUNT], int rowcount, int colcount);
typedef struct node{
	int posx;
	int posy;
	int g;
	int f;
	node *prev;
	node *next;
}Node;

int main()
{
	FILE *fp;
	char c;
	char grid[12][32];
	int i = 0; 
	int j = 0;
	int rowcount, colcount;						//	Count variables
	int startx, starty, destx, desty;			//	Start and Dest positions
	int curposx, curposy;						// 	Current position
	Node *openlist = (Node *)malloc(sizeof (Node));

	
	// Read the contents of the file
	fp = fopen("grid.txt", "r");
	c = getc(fp);
	while(c != EOF)
	{
		if(c != '\n')
		{
			grid[i][j] = c;
			j++;
			if(c == 's')
			{
				startx = i; starty = j;
			}
			else if (c == 'd')
			{
				destx = i; desty = j;
			}
			colcount = j;
		}
		else
		{
			j = 0;
			i++;
		}
		c = getc(fp);
	}
	fclose(fp);
	rowcount = i;
	
	// Print the contents of the file
	//printGrid(grid, rowcount, colcount );
	
	// Assign start node and put it on closed list
	Node startnode, nextnode;
	startnode.posx = startx;
	startnode.posy = starty;
	startnode.g = 0;
	startnode.f = 0;
	startnode.prev = NULL;
	startnode.next = NULL;
	
	return 0;
}



void printGrid(char grid[][MAXCOLCOUNT], int rowcount, int colcount)
{
	int i, j;
	for(i=0; i<rowcount;i++)
	{
		for(j=0;j<colcount;j++)
		{
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
}
