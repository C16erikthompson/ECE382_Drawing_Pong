#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void moveDelay();
extern void drawPaddle(paddleY,paddleX);
void		moveBall(unsigned char yDir, unsigned char xDir, unsigned char y, unsigned char x);

extern void drawBlock(unsigned char row, unsigned char col);

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)

/*void moveBall(unsigned char yDir, unsigned char xDir, unsigned char y, unsigned char x)
{
	if (yDir == 1) {
					y++;
					if (y>=8) yDir=0;
				}
				if (yDir == 0) {
					y--;
					if (y<=0) yDir=1;
				}
				if (xDir == 0) {
					x--;
					if (x<=0) xDir=1;
				}
				if (xDir == 1) {
					x++;
					if (x>=11) xDir=0;
				}
}*/
void main() {

	unsigned char	x, y, yDir, xDir, paddleY, paddleX, button_press;
	int	i, j, k;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	button_press = FALSE;

	init();
	initNokia();
	clearDisplay();
	x=4;		y=4;		paddleY=4; paddleX = 1;
	yDir=1;		xDir=1;		k = 0;
	drawBlock(y,x);

	while(1) {
//Ball Movement--------------------------------------------------
		if (x<=1 && (y <= paddleY && y >= paddleY-1))xDir=1;
		if (x==0){
			for(k = 0; k<8; k++){

			for(j = 0; j<10; j++){
				drawBlock(j,k);
			}}
			while(button_press == FALSE){
				if(AUX_BUTTON == 0)
				{
					button_press = TRUE;
				}
			}
			xDir=1;
		}
		if (yDir == 1) {
							y++;
							if (y>=8) yDir=0;
						}
						if (yDir == 0) {
							y--;
							if (y<=0) yDir=1;
						}
						if (xDir == 0) {
							x--;
							//if (x==1 && y <= paddleY) while(1);



						}
						if (xDir == 1) {
							x++;
							if (x>=11) xDir=0;
						}
//-----------------------------------------------------------
//Paddle Movement--------------------------------------------
									if (UP_BUTTON == 0) {
										while(UP_BUTTON == 0);
										if (paddleY>=1) paddleY=paddleY-1;
										button_press = TRUE;
									} else if (DOWN_BUTTON == 0) {
										while(DOWN_BUTTON == 0);
										if (paddleY<=6) paddleY=paddleY+1;
										button_press = TRUE;
									}
									if (button_press) {
										button_press = FALSE;
										clearDisplay();
										drawPaddle(paddleY,paddleX);
										drawBlock(y,x);
										drawPaddle((paddleY-1),(paddleX));
									}
//-----------------------------------------------------------
				//moveBall(yDir, xDir, y, x);
				clearDisplay();
				drawBlock(y,x);
				drawPaddle(paddleY,paddleX);
				drawPaddle((paddleY-1),(paddleX));
				for(i = 0; i<10; i++){
					moveDelay();}

		}
}
