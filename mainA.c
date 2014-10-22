#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay(unsigned char inv);
extern void moveDelay();
extern void drawPaddle(paddleY,paddleX);
void		moveBall(unsigned char yDir, unsigned char xDir, unsigned char y, unsigned char x);

extern void drawBlock(unsigned char row, unsigned char col, unsigned char inv);

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)

void main() {

	unsigned char	x, y, yDir, xDir, paddleY, paddleX, button_press, inv;
	int	i, j, k;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	button_press = FALSE;
	x=4;		y=4;		paddleY=4; 	paddleX = 1;
	yDir=1;		xDir=1;		k = 0;		inv = 2;
	init();
	initNokia();
	clearDisplay(inv);
	drawBlock(y,x, inv);
	// =======================================================================

	while(1)
	{
	// ===Ball Movement=======================================================
		if (x<=1 && (y <= paddleY && y >= paddleY-1))		//detects if ball struck the paddle
			xDir=1;
		if (x==0)											//detects if ball missed the paddle
		{
			for(k = 0; k<8; k++)
			{
				for(j = 0; j<12; j++)
				{
					drawBlock(j,k, inv);					//draws the loss screen
				}
			}
			while(button_press == FALSE)
			{
				if(AUX_BUTTON == 0)							//restarts a game that has been lost
				{
					button_press = TRUE;
				}
			}
			xDir=1;
		}
		if (yDir == 1)										//moves ball down and detects walls
		{
			y++;
			if (y>=8)
				yDir=0;
		}
		if (yDir == 0)										//moves ball up and detects walls
		{
			y--;
			if (y<=0)
				yDir=1;
		}
		if (xDir == 0)										//moves ball left
		{
			x--;
		}
		if (xDir == 1)										//moves ball right and detects wall
		{
			x++;
			if (x>=11)
				xDir=0;
		}
	// =================================================================
	// ===Paddle Movement===============================================
		if (UP_BUTTON == 0)
		{
			while(UP_BUTTON == 0);
			if (paddleY>=1)
				paddleY-=1;
			button_press = TRUE;
		}
		else if (DOWN_BUTTON == 0)
		{
			while(DOWN_BUTTON == 0);
			if (paddleY<=6)
				paddleY+=1;
			button_press = TRUE;
		}
		if (button_press)
		{
			button_press = FALSE;
			clearDisplay(inv);

			drawPaddle(paddleY,paddleX, inv);
			drawPaddle((paddleY-1),(paddleX),inv);

			drawBlock(y,x,inv);
		}
	// ========================================================

		clearDisplay(inv);

		drawBlock(y,x,inv);

		drawPaddle(paddleY,paddleX);
		drawPaddle((paddleY-1),(paddleX));

	//	===Time Delay============================================
		for(i = 0; i<8; i++)									// provides the time delay and encapsulates paddle movement 
		{														// to allow for constant movement
			if (UP_BUTTON == 0)
			{
				while(UP_BUTTON == 0);
				if (paddleY>=1)
					paddleY-=1;
				button_press = TRUE;
			}
			else if (DOWN_BUTTON == 0)
			{
				while(DOWN_BUTTON == 0);
				if (paddleY<=6)
					paddleY+=1;
				button_press = TRUE;
			}
			if (button_press)
			{
				button_press = FALSE;
				clearDisplay(inv);

				drawPaddle(paddleY,paddleX, inv);
				drawPaddle((paddleY-1),(paddleX),inv);

				drawBlock(y,x,inv);
			}
			moveDelay();
		}
	}
}
