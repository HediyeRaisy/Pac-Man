//#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <time.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

unsigned char MAP[12][12];
int flag=0;

struct packman{
	int x;
	int y;
	int score;
} dp;
struct ghost{
	int x;
	int y;
} dg;
struct ghost1{
	int x;
	int y;
} dg1;

void printMap(unsigned char a[12][12]){
	int i;
	int j;
//	printf(COLOR_GREEN "asd" COLOR_RESET "\n");
	
	printf(COLOR_MAGENTA "Score: %d\n" COLOR_RESET, dp.score);
	printf("Packman: x = %d, y = %d\n", dp.x, dp.y);
	printf("G1: x = %d, y = %d\n", dg.x, dg.y);
	printf("G2: x = %d, y = %d\n", dg1.x, dg1.y);
	
	for(i = 0; i < 12; i++) {
		for(j = 0; j < 12; j++) {
			if (j == dp.x && i == dp.y) {
				printf(COLOR_YELLOW "P" COLOR_RESET);
			} 
			else if (j == dg.x && i==dg.y) {
				printf(COLOR_RED "G" COLOR_RESET);
			}
			 else if(j == dg1.x && i == dg1.y) {
				printf (COLOR_RED "g" COLOR_RESET);
			}
			else if(a[j][i] == 248) {
				printf("%c", a[j][i]);		
			}
			else 
				printf(COLOR_GREEN "%c" COLOR_RESET, a[j][i]);		
		}
		printf("\n");
	}
	
	}
void moveG(int x, int y,unsigned char MAP[12][12]){
	int flag;
	do{
		srand(time(0));
	    int d = rand() % 4;
		flag = 0;
		switch(d) {
			case 0: {
				if (MAP[x][y-1]==178||MAP[x][y-1]==103) {
					flag=1;
				}
				else
				 y -= 1;
		
				break;
			}
			case 1: {
				if (MAP[x-1][y]==178||MAP[x-1][y]==103) {
					flag=1;
				}
				else
				x-=1;
				
				break;
			}
			case 2: {
				if (MAP[x][y+1]==178||MAP[x][y+1]==103) {
					flag=1;
				}
				else
				y+=1;
			
			
				break;
			}
			case 3: {
				if (MAP[x+1][y]==178||MAP[x+1][y]==103) {
					flag=1;
				}
				else
				x+=1;
				
				break;
			}
		}
		
	} while(flag == 1);	
	dg.x=x;
	dg.y=y;
}
void moveG1(int x, int y,unsigned char MAP[12][12]){
	
	srand(time(0));
	int flag;
	
	do{
	    int d = rand() % 4;
		flag = 0;
		switch(d)
		{
			case 0: {
				if (MAP[x][y-1]==178 ) {
					flag=1;
				}
				else
				 y -= 1;
				break;
			}
			case 1: {
				if (MAP[x-1][y]==178 || MAP[x-1][y]==71)  {
					flag=1;
				}
				 
				else
				x-=1;
				
				break;
			}
			case 2: {
				if (MAP[x][y+1]==178 || MAP[x][y+1]==71) {
					flag=1;
				}
				
				else
				y+=1;
			
			
				break;
			}
			case 3: {
				if (MAP[x+1][y]==178 || MAP[x+1][y]==71) {
					flag=1;
				}
				else
					x+=1;	
				break;
			}
		}
		
	} while(flag == 1);
	dg1.x=x;
	dg1.y=y;
}
	
void moveP(int x , int y,unsigned char MAP[12][12]){
	int flag;
	char key;
	do {
		key = getch();
		flag = 0;
		switch(key) {
			case 72: {
				if(MAP[x][y-1] == 178) {
					flag=1;
				}
				else {	
					y-=1;
				}
				break;
			}
			case 75: {
				if(MAP[x-1][y] == 178) {
					flag=1;
				}
				else {
					x-=1;
				}
				break;
			}
			case 80: {
				
			    if(MAP[x][y+1] == 178) {
			    	flag = 1;
				}
				else
					y+=1;
				break;
			}
			case 77: {
				if(MAP[x+1][y] == 178) {
					flag = 1;
				}
				else
					x += 1;
				break;
			}
		}
	} while(flag == 1);
	dp.x=x;
	dp.y=y;
}
int endOfGame() {
	return (dp.x == dg.x && dp.y == dg.y || dp.x == dg1.x && dp.y == dg1.y);
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	printf(COLOR_GREEN "somethimg green" COLOR_RESET "\n");
	system("CLS");
	unsigned char MAP[12][12] = {
	{178,178,178,178,178,178,178,178,178,178,178,178},
	{178,248,248,248,248,248,248,248,248,248,248,178},
	{178,248,178,178,248,248,248,248,178,178,248,178},
	{178,248,178,248,248,248,248,248,248,178,248,178},
    {178,248,178,248,248,248,248,248,248,178,248,178},
    {178,248,178,248,248,248,248,248,248,178,248,178},
    {178,248,178,248,248,248,248,248,248,178,248,178},
    {178,248,178,248,248,248,248,248,248,178,248,178},
    {178,248,178,248,248,248,248,248,248,178,248,178},
    {178,248,178,178,248,248,248,248,178,178,248,178},
    {178,248,248,248,248,248,248,248,248,248,248,178},
    {178,178,178,178,178,178,178,178,178,178,178,178},
	};

	dp.x = 1;
	dp.y = 1;
	dp.score = 0;
	
	dg.x = 5;
	dg.y = 5;
	
	dg1.x = 7;
	dg1.y = 7;

	while(flag == 0) {
		
	    printMap(MAP);
	    
		if (MAP[dp.x][dp.y] == 248) {
	    	dp.score += 100;
	    	MAP[dp.x][dp.y]	=' ';
		}
	    
		Sleep(10);
	    
	    // after each Packman and ghosts movement we check the losing condition.
	    moveG1(dg1.x,dg1.y,MAP);
	    flag = endOfGame();
	    
		moveG(dg.x,dg.y,MAP);
	    flag = endOfGame();
		
		moveP(dp.x,dp.y,MAP);
	    flag = endOfGame(); 
		
		system("CLS");
	}
    if(flag == 1) { // falg == 1 means the game is over :)
    	system("CLS");
    	printf("GAME OVER ! YOUR SCORE: %d", dp.score);
	}   
	return 0;
}








































