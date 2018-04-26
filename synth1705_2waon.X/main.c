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


unsigned char scale[] = {
    //        NOTE_C1, NOTE_D1, NOTE_E1, NOTE_F1, NOTE_G1, NOTE_A1, NOTE_B1,
    //        NOTE_C2, NOTE_D2, NOTE_E2, NOTE_F2, NOTE_G2, NOTE_A2, NOTE_B2,
    //        NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3,
    //        NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4,
    //        NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5,

    //re  mi   so  la  ti
    //        NOTE_D1, NOTE_E1, NOTE_G1, NOTE_A1, NOTE_B1,
    //        NOTE_D2, NOTE_E2, NOTE_G2, 
    //        NOTE_A2, NOTE_B2,
    //        NOTE_D3, NOTE_E3, NOTE_G3, NOTE_A3, NOTE_B3,
    //        NOTE_D4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_B4,
    //        NOTE_D5, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_B5,
    //        NOTE_D6, //NOTE_E6, NOTE_G6,
    NOTE_B0,
    NOTE_D1, NOTE_E1, NOTE_G1, NOTE_A1, NOTE_B1,
    NOTE_D2, NOTE_E2, NOTE_G2, NOTE_A2, NOTE_B2,
    NOTE_D3, NOTE_E3, NOTE_G3, NOTE_A3, NOTE_B3,
    NOTE_D4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_B4,
    NOTE_D5, NOTE_E5, NOTE_G5, //NOTE_A5, NOTE_B5,

    // NOTE_F6, NOTE_G6, NOTE_A6, NOTE_AS6, NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_G7, NOTE_A7

    // NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_GS5, NOTE_B5,
    // NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_GS6, NOTE_B6,

    //    NOTE_D1, NOTE_E1, NOTE_F1, NOTE_G1, NOTE_GS1, NOTE_AS1,
    //    NOTE_D2, NOTE_E2, NOTE_F2, NOTE_G2, NOTE_GS2, NOTE_AS2,
    //    NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_GS3, NOTE_AS3,
    //    NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_AS4,
    //    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_GS5, NOTE_AS5,
    //    NOTE_C6, NOTE_D6, NOTE_E6, NOTE_F6, //NOTE_G6, NOTE_GS6,
    //NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_G7, NOTE_GS7,

    //  NOTE_C5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5,
    //  NOTE_C6, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_A6,
    //  NOTE_C7, NOTE_E7, NOTE_F7, NOTE_G7, NOTE_A7

};

void soundPlay(char n, char onkai) {
    if (voice_on[n] == 0) {
        voice_on[n] = 1;
        dat_d[n] = onkai_d[onkai];
        dat_f[n] = onkai_f[onkai];
        env[n] = 0;
        envelopeCount[n] = ENV_DELAY;
        pos_f[n] = 0;
        pos_d[n] = 0;
    }
}

void main(void) {
    // initialize the device
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    for (int i = 0; i < _MAX_CHORUS; i++) {
        voice_on[i] = 0;
        env[i] = 0;
        envelopeCount[i] = 0;
        pos_d[i] = 0;
        pos_f[i] = 0;
    }

    ENV_DELAY = 20;

    mtouch_button_deviation_t d;
    mtouch_button_deviation_t d2;

    int s = 0;
    float ave;
    int count = 0;
    int dcnt = 0;
    int ss = 0;
    int ms = sizeof (scale) / sizeof (unsigned char);
    while (1) {
        //        MTOUCH_Service_Mainloop();
        //        d = MTOUCH_Button_Deviation_Get(Sensor_AN4);
        //        ave = ave * 2.0 / 3.0 + (float) (d) / 3.0;
        //        //
        //        if (d > 0 && ss == 0 && ave > 0) {
        //            //            ss = 1;
        //            ENV_DELAY = (ave * 5); // / 2);
        //            if (ENV_DELAY < 1)ENV_DELAY = 1;
        //            //            //            s = (int) ((d) / 12.0);
        //            //            if (s >= ms) s = 0; //s = ms - 1;
        //        }

        //        if (MTOUCH_Button_isPressed(Sensor_AN4)) {

        //        }
        for (int i = 0; i < _MAX_CHORUS; i++) {
            if (voice_on[i] == 0) {

                s++;
                if (s < 0)s = 0;
                if (s >= ms) s = 0;
                soundPlay(i, scale[s]);
                __delay_ms(100);

            }
        }
    }
}
/**
 End of File
 */