#ifndef BB_H_
#define BB_H_

#include <msp430.h>
#include "msp430x54x.h"

//pin definations

#define BITBANG_CE_PxDIR       P1DIR  //P4DIR                     
#define BITBANG_CE_PxOUT   P1OUT//P4OUT                 
#define BITBANG_CE_PxOUT   P1OUT//P4OUT                     
#define BITBANG_CE_BIT     BIT1//BIT5                     

#define BITBANG_SREAD_PxDIR  P1DIR  //P1DIR             
#define BITBANG_SREAD_PxOUT  P1OUT//P1OUT
#define BITBANG_SREAD_BIT    BIT4//BIT7                       
#define BITBANG_SREAD_PxIN  P1IN
#define BITBANG_SREAD_PxREN P1REN

#define BITBANG_SLE_PxDIR   P1DIR//P5DIR                
#define BITBANG_SLE_PxOUT   P1OUT//P5OUT                
#define BITBANG_SLE_BIT     BIT2//BIT5                    

#define BITBANG_SDATA_PxDIR  P1DIR//P4DIR                   
#define BITBANG_SDATA_PxOUT  P1OUT//P4OUT                   
#define BITBANG_SDATA_BIT    BIT0//BIT0                   
#define BITBANG_SDATA_PxREN  P1REN                              

#define BITBANG_SCLK_PxDIR   P1DIR//P4DIR                   
#define BITBANG_SCLK_PxOUT   P1OUT//P4OUT                   
#define BITBANG_SLE_BIT     BIT2//BIT5                  

#define BITBANG_SDATA_PxDIR  P1DIR//P4DIR               
#define BITBANG_SDATA_PxOUT  P1OUT//P4OUT               
#define BITBANG_SDATA_BIT    BIT0//BIT0                 
#define BITBANG_SDATA_PxREN  P1REN                      

#define BITBANG_SCLK_PxDIR   P1DIR//P4DIR               
#define BITBANG_SCLK_PxOUT   P1OUT//P4OUT               
#define BITBANG_SCLK_BIT     BIT3//BIT3                   


//prototyping functions:

void bitbang_initialise();
void bitbang_deinitialise();
void bitbang_write(unsigned char data);
long bitbang_read(unsigned char bitsize);

#endif
