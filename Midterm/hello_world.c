//GENERAL IMPORTS
#include <stdio.h>
#include <system.h>
#include <stdlib.h>
#include "altera_avalon_pio_regs.h"

//VGA IMPORTS
//#include "altera_up_avalon_video_character_buffer_with_dma.h"

//LCD IMPORTS
#include  "system.h"

//RS232 IMPORTS
#include <stdint.h>
#include "system.h"
#include "alt_types.h"
//#include "altera_avalon_uart.h"

//AUDIO IMPORTS
//#include "altera_up_avalon_audio.h"
#include "io.h"



int main(){

	  if((IORD_ALTERA_AVALON_PIO_DATA(ASW3_BASE)) == 0) //////////////////////////////0/////////////////////
	  {
		  IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE, 0xFF);
		  IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE, 0x00);
	  }
	  else if((IORD_ALTERA_AVALON_PIO_DATA(AW3_BASE)) == 1) //////////////////////////1/////////////////////
	  {
			alt_up_sd_card_dev *sd_card_dev;
			//audio code
			printf("Hello from Nios II!\n");
			alt_up_audio_dev * audio_dev;

			/* used for audio record/playback */
			unsigned int l_buf;
			unsigned int r_buf;


			// open the Audio port
			audio_dev = alt_up_audio_open_dev ("/dev/audio");

			if ( audio_dev == NULL)
			printf("Error: could not open audio device \n");
			else
			printf("Opened audio device \n");
			/* read and echo audio data */
			while(1)
			{
			int fifospace = alt_up_audio_read_fifo_avail (audio_dev, ALT_UP_AUDIO_RIGHT);
			if ( fifospace > 0 ) // check if data is available
			{
			// read audio buffer
			alt_up_audio_read_fifo (audio_dev, &(r_buf), 1, ALT_UP_AUDIO_RIGHT);
			alt_up_audio_read_fifo (audio_dev, &(l_buf), 1, ALT_UP_AUDIO_LEFT);
			// write audio buffer
			alt_up_audio_write_fifo (audio_dev, &(r_buf), 1, ALT_UP_AUDIO_RIGHT);
			alt_up_audio_write_fifo (audio_dev, &(l_buf), 1, ALT_UP_AUDIO_LEFT);
		}
	}
	  }
	  else if((IORD_ALTERA_AVALON_PIO_DATA(ASW3_BASE)) == 2)//////////////////////////////////////2/////////////////////////
	  {
		  IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE, 0x00);
		  IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE, 0x00);
		  
		  FILE *char_lcd_dev;
		  
		    //open the Character LCD port
			char_lcd_dev = fopen ("/dev/lcd","w");


			if (char_lcd_dev == NULL)
			alt_printf ("Error: could not open character LCD device\n");
			else
			{
			alt_printf ("Opened character LCD device\n");
			}

			char first_row[32];


			sprintf(first_row, "\nHello World");

			fwrite(first_row,32, 1, char_lcd_dev);
	  }
	  else if((IORD_ALTERA_AVALON_PIO_DATA(ASW3_BASE)) == 3)/////////////////////////////////////3//////////////////////
	  {		  
			FILE *char_lcd_dev;
		  
		    //open the Character LCD port
			char_lcd_dev = fopen ("/dev/lcd","w");


			if (char_lcd_dev == NULL)
			alt_printf ("Error: could not open character LCD device\n");
			else
			{
			alt_printf ("Opened character LCD device\n");
			}

			char first_row[32];


			sprintf(first_row, "\nHello World");

			fwrite(first_row,32, 1, char_lcd_dev);
			
	  }
	  else if((IORD_ALTERA_AVALON_PIO_DATA(ASW3_BASE)) == 4)///////////////////////////////////////4////////////////////////
	  {
		  	alt_up_char_buffer_dev * vga_dev;


			    // open the VGA port
			    	vga_dev = alt_up_char_buffer_open_dev("/dev/vga_charbuf");

			    	if (vga_dev == NULL)
			    	alt_printf ("Error: could not open VGA device \n");
			    	else
			    	alt_printf ("Opened VGA device \n");

			   // Write Hello, world!
			    	 alt_up_char_buffer_clear(vga_dev);

			   int x = 1;
			   int y=1;
			   int i;
			   char* hw = "c";
			   char *string=hw;
	  }  
	  else if((IORD_ALTERA_AVALON_PIO_DATA(SW1_BASE)) == 5) || (IORD_ALTERA_AVALON_PIO_DATA(SW1_BASE)) == 6) || (IORD_ALTERA_AVALON_PIO_DATA(SW1_BASE)) == 7)) //////5,6,7//////
	  {
		alt_up_char_buffer_dev * vga_dev;


			    // open the VGA port
			    	vga_dev = alt_up_char_buffer_open_dev("/dev/charbuff");

			    	if (vga_dev == NULL)
			    	alt_printf ("Error: could not open VGA device \n");
			    	else
			    	alt_printf ("Opened VGA device \n");

			   // Write Hello, world!
			    	 alt_up_char_buffer_clear(vga_dev);

			   int x = 1;
			   int y=1;
			   int i;
			   char* hw = "c";
			   char *string=hw;
			   
		FILE *char_lcd_dev;
		  
		    //open the Character LCD port
			char_lcd_dev = fopen ("/dev/lcd","w");


			if (char_lcd_dev == NULL)
			alt_printf ("Error: could not open character LCD device\n");
			else
			{
			alt_printf ("Opened character LCD device\n");
			}

			char first_row[32];


			sprintf(first_row, "\nHello World");

			fwrite(first_row,32, 1, char_lcd_dev);   
	  }
}
