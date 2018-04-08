/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1705
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
/*
                         Main application
 */
unsigned int a;
unsigned int c;

unsigned char scale[] = {
    //re  mi   so  la  ti
                      NOTE_G2, NOTE_A2, NOTE_B2,
    NOTE_D3, NOTE_E3, NOTE_G3, NOTE_A3, NOTE_B3,
    NOTE_D4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_B4,
    //NOTE_D5, //NOTE_E5, NOTE_G5, NOTE_A5, //NOTE_B5,
    // NOTE_D6, NOTE_E6, NOTE_G6, 
    
    // NOTE_D5, NOTE_E5, NOTE_G5, NOTE_A5,NOTE_B5,
    // NOTE_D6, NOTE_E6, NOTE_G6, NOTE_A6, NOTE_B6,
    // NOTE_D7, NOTE_E7, NOTE_G7, NOTE_A7//, NOTE_B7,

    // NOTE_F6, NOTE_G6, NOTE_A6, NOTE_AS6, NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_G7, NOTE_A7

    // NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_GS5, NOTE_B5,
    // NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_GS6, NOTE_B6,

    // NOTE_D2, NOTE_E2, NOTE_F2, NOTE_G2, NOTE_GS2, NOTE_AS2,
    // NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_GS3, NOTE_AS3,
    // NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_AS4,
    // NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_GS5, NOTE_AS5,
    // NOTE_C6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_GS6,
    // NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_G7, NOTE_GS7,

    //  NOTE_C5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5,
    //  NOTE_C6, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_A6,
    //  NOTE_C7, NOTE_E7, NOTE_F7, NOTE_G7, NOTE_A7

};


void soundPlay(char onkai) {
    //????
    dat_d = onkai_d[onkai];
    //????
    dat_f = onkai_f[onkai];
    //?????????????
    env = 0;
    envelopeCount = 0;
    //??????????1???
    voice_on = 1;
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    pitch = 0;
    count = 0;

    voice_on = 0;
    env = 0;
    envelopeCount = 0;
    pos_d = 0;
    pos_f = 0;

    ENV_DELAY = 100; //*40;
    
    mtouch_button_deviation_t d;
    int s;
    int state;
    while(1) {
        MTOUCH_Service_Mainloop();
        d = MTOUCH_Button_Deviation_Get(Sensor_AN4);
        // c++;
        // if(c%4000==0){
            // if(voice_on==0){
        // a = ramdom()*100;
        // if(voice_on==0){
            if(MTOUCH_Button_isPressed(Sensor_AN4)){
                if(d > 0){
                    if(state==0){
                        state=1;
                        s = (d/10);
                        if(s<0)s=0;
                        if(s>12)s=12;
                        soundPlay(scale[s]);
                    }
                }
            }else{
                state=0;
            }
        // }
    }
}
/**
 End of File
*/