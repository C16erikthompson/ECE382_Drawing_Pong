ECE382_Drawing_Pong
===================

Etch-a-sketch and Pong Programs

#Required Functionality
  Required functionality consisted of creating an etch-a-sketch program in C displayed on the lcd attatchment for the MSP430.  To do this, a C program was created that utilized an assembly program similar to that created in Lab3.  As the assembly program already moved the block o the LCD by utiliing the buttons on the attatchment, the only changes that had to be made to the program consisted of taking out the #cleardisplay command that occured with each button press and passing a variable value (stored in a register dictated b the C program) to the register used for drawing the block as opposed to the previous 0xFF passed in.
  
#B Functionality
  B funtionality consisted of having the block bounce around the screen, using the edges of the screen as boundaries, without iput from the user.  To achieve this, button inputs were removed and replaced with if statements to dictate the direction and movement of the ball and handle collision detection.
  
#A Functionality
  A functionality consisted of makig a rudimentary pong game in which the user plays against himself, htting the ball continually against the walls.  To achieve this, the control from Required functionality were introduced ad tied to a vertical line with a length of 16 bits.  This line was essetially made into the left wall of the display, tying all collision conditions to the x and y of the paddle relatice to the x and why of the constantly moving ball.  Should the x-value of the ball be less than the x-value of the paddle (as the paddle was the left wall), while the y-values are ot equal, the game is over, displaying a pattern upon the screen.  To restart the game, the auxillary key is pressed.
  
#Bonus Functionaliy
  I was able to make the moving block into a ball by removing the loop the drew the block ad replacing it with a set of instuctions that drew each line of the 8 bit wide ball.  To figure out what inputs needed to be made to make the ball, I drew a ball bitwise on graph paper and wrote the corresponding columns of bits as hex values.  I passed these values into the program.
  
#Debugging
  The only issues I really ran into involved the syntax of C, or assembly that was to be utilized in C, as I am relatively green with these languages.  One such problem was forgetting to declare a variable as global ad continually recieveing an error that in no way hinted that this was the actual problem with my problem.
  
#Documentation
  None
