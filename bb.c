#include "bb.h"

void bitbang_initialise()
{
    BITBANG_CE_PxDIR |= BITBANG_CE_BIT;
    BITBANG_SLE_PxDIR |= BITBANG_SLE_BIT;
    BITBANG_SCLK_PxDIR |= BITBANG_SCLK_BIT;
    BITBANG_SDATA_PxDIR |= BITBANG_SDATA_BIT;
    BITBANG_SREAD_PxDIR &= ~BITBANG_SREAD_BIT;
    BITBANG_SREAD_PxREN |= BITBANG_SREAD_BIT;                   //PULL UP/DOWN ENABLED*
    
    BITBANG_CE_PxOUT |= BITBANG_CE_BIT;
    __delay_cycles(100000);            //wasn't included before 
    BITBANG_SLE_PxOUT &= ~BITBANG_SLE_BIT;
    BITBANG_SCLK_PxOUT &= ~BITBANG_SCLK_BIT;
  //  BITBANG_SDATA_PxOUT |= BITBANG_SDATA_BIT; ...big mistake
    BITBANG_SDATA_PxOUT &= ~ BITBANG_SDATA_BIT;
    
}

void bitbang_deinitialise()
{
	BITBANG_CE_PxOUT &= ~BITBANG_CE_BIT;
	BITBANG_SLE_PxOUT &= ~BITBANG_SLE_BIT;
	BITBANG_SCLK_PxOUT &= ~BITBANG_SCLK_BIT;
	BITBANG_SDATA_PxOUT &= ~BITBANG_SDATA_BIT;
}
    
void bitbang_write(unsigned char data)

{
  unsigned long i;
   for(i=0; i<8; i++)
{
   
   
    if(data & 0x80) 		//data is the 8 bit register
 { BITBANG_SDATA_PxOUT |= BITBANG_SDATA_BIT; }
    else
 { BITBANG_SDATA_PxOUT &= ~BITBANG_SDATA_BIT; }
 
    BITBANG_SCLK_PxOUT |= BITBANG_SCLK_BIT;             //try clearing the clock again here itself.
   __delay_cycles(100);
    BITBANG_SCLK_PxOUT &= ~BITBANG_SCLK_BIT;
    __delay_cycles(100);
    data=data<<1;
}
}

long bitbang_read(unsigned char bitsize)
{

  BITBANG_SDATA_PxOUT &= ~BITBANG_SDATA_BIT;
  BITBANG_SCLK_PxOUT &= ~BITBANG_SCLK_BIT;      
  BITBANG_SLE_PxOUT |= BITBANG_SLE_BIT;      
  __delay_cycles(10);

	
  /* Clock in first bit and discard */
	BITBANG_SCLK_PxOUT |= BITBANG_SCLK_BIT;
        __delay_cycles(50);
        BITBANG_SCLK_PxOUT &= ~BITBANG_SCLK_BIT;
        __delay_cycles(50);
  
  
	unsigned long i, value = 0;
	
        
        for(i = 0; i < bitsize; i++)
	{        
          value = value<<1;
		//BITBANG_SCLK_PxOUT &= ~BITBANG_SCLK_BIT;                //try low to high transition too
		       __delay_cycles(50);
 
                BITBANG_SCLK_PxOUT |= BITBANG_SCLK_BIT;
                       __delay_cycles(50);
 
		if((BITBANG_SREAD_PxIN & BITBANG_SREAD_BIT)>0)
                { value |= 1; }
                
                BITBANG_SCLK_PxOUT &= ~BITBANG_SCLK_BIT; 
                
                __delay_cycles(100);
                 
                
               // value = value | ((BITBANG_SREAD_PxIN & BITBANG_SREAD_BIT) << (bitsize - i));
	}
        
        //*** testing something
        /* for(i=0; i < 16; i++)
        {
            BITBANG_SCLK_PxOUT &= ~BITBANG_SCLK_BIT;
            BITBANG_SCLK_PxOUT |= BITBANG_SCLK_BIT;
            value2 = value2 | ((BITBANG_SREAD_PxIN & BITBANG_SREAD_BIT) << (16 - i)); 
        }
        */
        // ****testing over
        
	BITBANG_SCLK_PxOUT &= ~BITBANG_SCLK_BIT;
       
        
        
         // throw away last bit 
        BITBANG_SCLK_PxOUT |= BITBANG_SCLK_BIT;                 //before or after pulling sle low?
        BITBANG_SCLK_PxOUT &= ~BITBANG_SCLK_BIT;
	BITBANG_SLE_PxOUT &= ~BITBANG_SLE_BIT;
        return (value);
}

