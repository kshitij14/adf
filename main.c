/**
author : kshitij
date: 9th june 2014
**/



#include "bb.h"


unsigned long readback;                
int main()
{
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
<<<<<<< HEAD
    while(1)                                {
=======
    while(1)                                   
    {
>>>>>>> de6360d2e83b7f4e38feb34cf0e0abf479aa5899
      bitbang_initialise();

    
      BITBANG_SLE_PxOUT &= ~BITBANG_SLE_BIT;
   
    bitbang_write(0x00);
    bitbang_write(0x00);
    bitbang_write(0x01);
    bitbang_write(0xC7);
   
    BITBANG_SLE_PxOUT |= BITBANG_SLE_BIT; 
                   __delay_cycles(10);
    BITBANG_SLE_PxOUT &= ~BITBANG_SLE_BIT;
                   __delay_cycles(10);
    
<<<<<<< HEAD
    readback = bitbang_read(16);                    
=======
    readback = bitbang_read(16);                
    
>>>>>>> de6360d2e83b7f4e38feb34cf0e0abf479aa5899
    
    BITBANG_SLE_PxOUT &= ~BITBANG_SLE_BIT;
    bitbang_deinitialise();
    }
    while(1);
	return 0;

}



