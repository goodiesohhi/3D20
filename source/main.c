/*
	Hello World example made by Aurelio Mannara for ctrulib
	This code was modified for the last time on: 12/12/2014 21:00 UTC+1
*/

#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
	gfxInitDefault();
    gfxSetDoubleBuffering(GFX_BOTTOM, false);
	u8* fb = gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL);
	//Initialize console on top screen. Using NULL as the second argument tells the console library to use the internal console structure as current one
	consoleInit(GFX_TOP, NULL);

	//Move the cursor to row 15 and column 19 and then prints "Hello World!"
	//To move the cursor you have to print "\x1b[r;cH", where r and c are respectively
	//the row and column where you want your cursor to move
	//The top screen has 30 rows and 50 columns
	//The bottom screen has 30 rows and 40 columns
	int roll=0;
	printf("\x1b[15;2HX=D20 A=D10 Y=D6 B=D4 SELECT= D12 UP=D8");
	printf("\x1b[2;0H ROLL: %03d; ", roll);

	printf("\x1b[29;15HPress Start to exit.");
	
    
	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();
        if (kDown & KEY_X){
	

        roll = 1 + (rand() % (int)(20 - 1 + 1));
		printf("\x1b[2;0H ROLL: %03d; ", roll);
		};
		
		 if (kDown & KEY_A){
	

        roll = 1 + (rand() % (int)(10 - 1 + 1));
		printf("\x1b[2;0H ROLL: %03d; ", roll);
		};
		if (kDown & KEY_Y){
	

        roll = 1 + (rand() % (int)(6 - 1 + 1));
		printf("\x1b[2;0H ROLL: %03d; ", roll);
		};
		if (kDown & KEY_B){
	

        roll = 1 + (rand() % (int)(4 - 1 + 1));
		printf("\x1b[2;0H ROLL: %03d; ", roll);
		};
		
		if (kDown & KEY_SELECT){
	

        roll = 1 + (rand() % (int)(12 - 1 + 1));
		printf("\x1b[2;0H ROLL: %03d; ", roll);
		};
		
		if (kDown & KEY_DUP){
	

        roll = 1 + (rand() % (int)(8 - 1 + 1));
		printf("\x1b[2;0H ROLL: %03d; ", roll);
		};
		if (kDown & KEY_START) break; // break in order to return to hbmenu

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
	}

	gfxExit();
	return 0;
}
