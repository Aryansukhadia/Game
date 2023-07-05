#include<stdio.h>
#include<conio.h>
void main(){
	  int candyX=40,candyY=2,boxX=40,boxY=22,score=0,lifeline=3,d;
	  char ch;
	  start:

		clrscr();
		gotoxy(60,5);
		cprintf("SCORE=%d",score);
		gotoxy(60,6);
		cprintf("LIFELINE=%d",lifeline);
		textcolor(CYAN);
		gotoxy(candyX,candyY);
		cprintf("0");
		gotoxy(boxX,boxY);
		cprintf("#");
		gotoxy(boxX+8,boxY);
		cprintf("#");
		gotoxy(boxX,boxY+1);
		cprintf("#########");
		if(kbhit()){
			ch=getch();
			switch(ch){
				case 'a':if(boxX>1){
					 boxX--;
					 }
					break;
				case 'd':if(boxX<73){
					 boxX++;
					 }
					break;
				case'A':if(boxX>1){
					boxX--;
					}
					break;
				case 'D':if(boxX<73){
					boxX++;
					}
					break;
				case 'x' :exit(0);
				case 'X' :exit(0);
			}
		}
		candyY++;
		if(candyY==22){
		    d=candyX-boxX;
		    if(d>=1 && d<=6){
			  score++;
		    }else{
			 lifeline--;
			 if(lifeline==0){
				clrscr();
				gotoxy(40,13);
				textcolor(RED);
				sound(200);
				delay(500);
				nosound();
				cprintf("GAME IS OVER");

				getch();
				exit(0);
			 }
		    }
		candyX=rand()%80+1;
		candyY=2;
	  }

	  delay(200);
	 goto start;


}