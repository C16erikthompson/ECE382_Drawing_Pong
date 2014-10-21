#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void moveDelay();

extern void drawBlock(unsigned char row, unsigned char col);

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)


void main() {

	unsigned char	x, y, yDir, xDir;
	unsigned int	i;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */


	init();
	initNokia();
	clearDisplay();
	x=4;		y=4;
	yDir=1;		xDir=1;
	drawBlock(y,x);

	while(1) {
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
				clearDisplay();
				drawBlock(y,x);
				for(i = 0; i<10; i++){
					moveDelay();}

		}
}
