
#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sf2d.h>
extern const struct {
 unsigned int width;
 unsigned int height;
 unsigned int bytes_per_pixel;
 unsigned char pixel_data[];
} logo;

int main(int argc, char **argv)


{
	
	sf2d_init();
	//Set the background color
	sf2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
	
	
	
	
	consoleInit(GFX_TOP, NULL);


	//The top screen has 30 rows and 50 columns
	//The bottom screen has 30 rows and 40 columns
	int roll=0;
	printf("\x1b[15;2HX=D20 A=D10 Y=D6 B=D4 SELECT= D12 UP=D8");
	printf("\x1b[2;0H ROLL: %03d; ", logo.width);

	printf("\x1b[29;15HPress Start to exit.");
	gfxSetDoubleBuffering(GFX_BOTTOM, false);

	
    sf2d_texture *tex_image = sf2d_create_texture_mem_RGBA8(logo.pixel_data, logo.width, logo.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);

	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		sf2d_draw_texture(tex_image, 0, 0);
	sf2d_end_frame();
	sf2d_swapbuffers();

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
    sf2d_free_texture(tex_image);
	sf2d_fini();
	gfxExit();
	return 0;
}
