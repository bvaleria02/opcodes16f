#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "../include/libopcode16.h"

const op_register_file_map_t op_registers_file_map[OP_BANK_COUNT][OP_BANK_SIZE] = {
  {
    {
      .reserved = true,
      .name="INDF",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="TMR0",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="PCL",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="STATUS",
      .bits={
        {.active = true,  .name   = "C"},
        {.active = true,  .name   = "DC"},
        {.active = true,  .name   = "Z"},
        {.active = true,  .name   = "PD"},
        {.active = true,  .name   = "TO"},
        {.active = true,  .name   = "RP0"},
        {.active = true,  .name   = "RP1"},
        {.active = true,  .name   = "IRP"},
      }
    },
    {
      .reserved = true,
      .name="FSR",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="PORTA",
      .bits={
        {.active = true,  .name   = "RA0"},
        {.active = true,  .name   = "RA1"},
        {.active = true,  .name   = "RA2"},
        {.active = true,  .name   = "RA3"},
        {.active = true,  .name   = "RA4"},
        {.active = true,  .name   = "RA5"},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="PORTB",
      .bits={
        {.active = true,  .name   = "RB0"},
        {.active = true,  .name   = "RB1"},
        {.active = true,  .name   = "RB2"},
        {.active = true,  .name   = "RB3"},
        {.active = true,  .name   = "RB4"},
        {.active = true,  .name   = "RB5"},
        {.active = true,  .name   = "RB6"},
        {.active = true,  .name   = "RB7"},
      }
    },
    {
      .reserved = true,
      .name="PORTC",
      .bits={
        {.active = true,  .name   = "RC0"},
        {.active = true,  .name   = "RC1"},
        {.active = true,  .name   = "RC2"},
        {.active = true,  .name   = "RC3"},
        {.active = true,  .name   = "RC4"},
        {.active = true,  .name   = "RC5"},
        {.active = true,  .name   = "RC6"},
        {.active = true,  .name   = "RC7"},
      }
    },
    {
      .reserved = true,
      .name="PORTD",
      .bits={
        {.active = true,  .name   = "RD0"},
        {.active = true,  .name   = "RD1"},
        {.active = true,  .name   = "RD2"},
        {.active = true,  .name   = "RD3"},
        {.active = true,  .name   = "RD4"},
        {.active = true,  .name   = "RD5"},
        {.active = true,  .name   = "RD6"},
        {.active = true,  .name   = "RD7"},
      }
    },
    {
      .reserved = true,
      .name="PORTE",
      .bits={
        {.active = true,  .name   = "RE0"},
        {.active = true,  .name   = "RE1"},
        {.active = true,  .name   = "RE2"},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="PCLATH",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="INTCON",
      .bits={
        {.active = true,  .name   = "RBIF"},
        {.active = true,  .name   = "INTF"},
        {.active = true,  .name   = "TMROIF"},
        {.active = true,  .name   = "RBIE"},
        {.active = true,  .name   = "INTE"},
        {.active = true,  .name   = "TMROIE"},
        {.active = true,  .name   = "PEIE"},
        {.active = true,  .name   = "GIE"},
      }
    },
    {
      .reserved = true,
      .name="PIR1",
      .bits={
        {.active = true,  .name   = "TMR1IF"},
        {.active = true,  .name   = "TMR2IF"},
        {.active = true,  .name   = "CCP1IF"},
        {.active = true,  .name   = "SSPIF"},
        {.active = true,  .name   = "TXIF"},
        {.active = true,  .name   = "RCIF"},
        {.active = true,  .name   = "ADIF"},
        {.active = true,  .name   = "PSPIF"},
      }
    },
    {
      .reserved = true,
      .name="PIR2",
      .bits={
        {.active = true,  .name   = "CCP2IF"},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = true,  .name   = "BCLIF"},
        {.active = true,  .name   = "EEIF"},
        {.active = false, .name   = NULL},
        {.active = true,  .name   = "CMIF"},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="TMR1L",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="TMR1H",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="T1CON",
      .bits={
        {.active = true,  .name   = "TMR1ON"},
        {.active = true,  .name   = "TMR1CS"},
        {.active = true,  .name   = "T1SYNC"},
        {.active = true,  .name   = "T1OSCEN"},
        {.active = true,  .name   = "T1CKS0"},
        {.active = true,  .name   = "T1CKS1"},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="TMR2",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="T2CON",
      .bits={
        {.active = true,  .name   = "T2CKPS0"},
        {.active = true,  .name   = "T2CKPS1"},
        {.active = true,  .name   = "TMR2ON"},
        {.active = true,  .name   = "TOUTPS0"},
        {.active = true,  .name   = "TOUTPS1"},
        {.active = true,  .name   = "TOUTPS2"},
        {.active = true,  .name   = "TOUTPS3"},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="SSPBUF",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="SSPCON",
      .bits={
        {.active = true,  .name   = "SSPM0"},
        {.active = true,  .name   = "SSPM1"},
        {.active = true,  .name   = "SSPM2"},
        {.active = true,  .name   = "SSPM3"},
        {.active = true,  .name   = "CKP"},
        {.active = true,  .name   = "SSPEN"},
        {.active = true,  .name   = "SSPOV"},
        {.active = true,  .name   = "WCOL"},
      }
    },
    {
      .reserved = true,
      .name="CCPR1L",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="CCPR1H",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="CCP1CON",
      .bits={
        {.active = true,  .name   = "CCP1M0"},
        {.active = true,  .name   = "CCP1M1"},
        {.active = true,  .name   = "CCP1M2"},
        {.active = true,  .name   = "CCP1M3"},
        {.active = true,  .name   = "CCP1Y"},
        {.active = true,  .name   = "CCP1X"},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="RCSTA",
      .bits={
        {.active = true,  .name   = "RX9D"},
        {.active = true,  .name   = "OERR"},
        {.active = true,  .name   = "FERR"},
        {.active = true,  .name   = "ADDEN"},
        {.active = true,  .name   = "CREN"},
        {.active = true,  .name   = "SREN"},
        {.active = true,  .name   = "RX9"},
        {.active = true,  .name   = "SPEN"},
      }
    },
    {
      .reserved = true,
      .name="TXREG",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="RCREG",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="CCPR2L",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="CCPR2H",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="CCP2CON",
      .bits={
        {.active = true,  .name   = "CCP2M0"},
        {.active = true,  .name   = "CCP2M1"},
        {.active = true,  .name   = "CCP2M2"},
        {.active = true,  .name   = "CCP2M3"},
        {.active = true,  .name   = "CCP2Y"},
        {.active = true,  .name   = "CCP2X"},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="ADRESH",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="ADCON0",
      .bits={
        {.active = true,  .name   = "ADON"},
        {.active = false, .name   = NULL},
        {.active = true,  .name   = "GO/DONE"},
        {.active = true,  .name   = "CHS0"},
        {.active = true,  .name   = "CHS1"},
        {.active = true,  .name   = "CHS2"},
        {.active = true,  .name   = "ADCS0"},
        {.active = true,  .name   = "ADCS1"},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
  },
  {
    {
      .reserved = true,
      .name="INDF",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="OPTION_REG",
      .bits={
        {.active = true,  .name   = "PS0"},
        {.active = true,  .name   = "PS1"},
        {.active = true,  .name   = "PS2"},
        {.active = true,  .name   = "PSA"},
        {.active = true,  .name   = "T0SE"},
        {.active = true,  .name   = "T0CS"},
        {.active = true,  .name   = "INTEDG"},
        {.active = true,  .name   = "RBPU"},
      }
    },
    {
      .reserved = true,
      .name="PCL",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="STATUS",
      .bits={
        {.active = true,  .name   = "C"},
        {.active = true,  .name   = "DC"},
        {.active = true,  .name   = "Z"},
        {.active = true,  .name   = "PD"},
        {.active = true,  .name   = "TO"},
        {.active = true,  .name   = "RP0"},
        {.active = true,  .name   = "RP1"},
        {.active = true,  .name   = "IRP"},
      }
    },
    {
      .reserved = true,
      .name="FSR",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="TRISA",
      .bits={
        {.active = true,  .name   = "TA0"},
        {.active = true,  .name   = "TA1"},
        {.active = true,  .name   = "TA2"},
        {.active = true,  .name   = "TA3"},
        {.active = true,  .name   = "TA4"},
        {.active = true,  .name   = "TA5"},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="TRISB",
      .bits={
        {.active = true,  .name   = "TB0"},
        {.active = true,  .name   = "TB1"},
        {.active = true,  .name   = "TB2"},
        {.active = true,  .name   = "TB3"},
        {.active = true,  .name   = "TB4"},
        {.active = true,  .name   = "TB5"},
        {.active = true,  .name   = "TB6"},
        {.active = true,  .name   = "TB7"},
      }
    },
    {
      .reserved = true,
      .name="TRISC",
      .bits={
        {.active = true,  .name   = "TC0"},
        {.active = true,  .name   = "TC1"},
        {.active = true,  .name   = "TC2"},
        {.active = true,  .name   = "TC3"},
        {.active = true,  .name   = "TC4"},
        {.active = true,  .name   = "TC5"},
        {.active = true,  .name   = "TC6"},
        {.active = true,  .name   = "TC7"},
      }
    },
    {
      .reserved = true,
      .name="TRISD",
      .bits={
        {.active = true,  .name   = "TD0"},
        {.active = true,  .name   = "TD1"},
        {.active = true,  .name   = "TD2"},
        {.active = true,  .name   = "TD3"},
        {.active = true,  .name   = "TD4"},
        {.active = true,  .name   = "TD5"},
        {.active = true,  .name   = "TD6"},
        {.active = true,  .name   = "TD7"},
      }
    },
    {
      .reserved = true,
      .name="TRISE",
      .bits={
        {.active = true,  .name   = "TE0"},
        {.active = true,  .name   = "TE1"},
        {.active = true,  .name   = "TE2"},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="PCLATH",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="INTCON",
      .bits={
        {.active = true,  .name   = "RBIF"},
        {.active = true,  .name   = "INTF"},
        {.active = true,  .name   = "TMROIF"},
        {.active = true,  .name   = "RBIE"},
        {.active = true,  .name   = "INTE"},
        {.active = true,  .name   = "TMROIE"},
        {.active = true,  .name   = "PEIE"},
        {.active = true,  .name   = "GIE"},
      }
    },
    {
      .reserved = true,
      .name="PIE1",
      .bits={
        {.active = true,  .name   = "TMR1E"},
        {.active = true,  .name   = "TMR2E"},
        {.active = true,  .name   = "CCP1IE"},
        {.active = true,  .name   = "SSPIE"},
        {.active = true,  .name   = "TXIE"},
        {.active = true,  .name   = "RCIE"},
        {.active = true,  .name   = "ADIE"},
        {.active = true,  .name   = "PSPIE"},
      }
    },
    {
      .reserved = true,
      .name="PIE2",
      .bits={
        {.active = true,  .name   = "CCP2IE"},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = true,  .name   = "BCLIE"},
        {.active = true,  .name   = "EEIE"},
        {.active = false, .name   = NULL},
        {.active = true,  .name   = "CMIE"},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="PCON",
      .bits={
        {.active = true,  .name   = "BOR"},
        {.active = true,  .name   = "POR"},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="SSPCON2",
      .bits={
        {.active = true,  .name   = "SEN"},
        {.active = true,  .name   = "RSEN"},
        {.active = true,  .name   = "PEN"},
        {.active = true,  .name   = "RCEN"},
        {.active = true,  .name   = "ACKEN"},
        {.active = true,  .name   = "ACKDT"},
        {.active = true,  .name   = "ACKSTAT"},
        {.active = true,  .name   = "GCEN"},
      }
    },
    {
      .reserved = true,
      .name="PR2",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="SSPADD",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="SSPSTAT",
      .bits={
        {.active = true,  .name   = "BF"},
        {.active = true,  .name   = "UA"},
        {.active = true,  .name   = "R/W"},
        {.active = true,  .name   = "S"},
        {.active = true,  .name   = "P"},
        {.active = true,  .name   = "D/A"},
        {.active = true,  .name   = "CKE"},
        {.active = true,  .name   = "SMP"},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="TXSTA",
      .bits={
        {.active = true,  .name   = "TX9D"},
        {.active = true,  .name   = "TRMT"},
        {.active = true,  .name   = "BRGH"},
        {.active = false, .name   = NULL},
        {.active = true,  .name   = "SYNC"},
        {.active = true,  .name   = "TXEN"},
        {.active = true,  .name   = "TX9"},
        {.active = true,  .name   = "CSRC"},
      }
    },
    {
      .reserved = true,
      .name="SPBRG",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="CMCON",
      .bits={
        {.active = true,  .name   = "CM0"},
        {.active = true,  .name   = "CM1"},
        {.active = true,  .name   = "CM2"},
        {.active = true,  .name   = "CIS"},
        {.active = true,  .name   = "C1INV"},
        {.active = true,  .name   = "C2INV"},
        {.active = true,  .name   = "C1OUT"},
        {.active = true,  .name   = "C2OUT"},
      }
    },
    {
      .reserved = true,
      .name="CVRCON",
      .bits={
        {.active = true,  .name   = "CVR0"},
        {.active = true,  .name   = "CVR1"},
        {.active = true,  .name   = "CVR2"},
        {.active = true,  .name   = "CVR3"},
        {.active = false, .name   = NULL},
        {.active = true,  .name   = "CVRR"},
        {.active = true,  .name   = "CVROE"},
        {.active = true,  .name   = "CVREN"},
      }
    },
    {
      .reserved = true,
      .name="ADRESL",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="ADCON1",
      .bits={
        {.active = true,  .name   = "PCFG0"},
        {.active = true,  .name   = "PCFG1"},
        {.active = true,  .name   = "PCFG2"},
        {.active = true,  .name   = "PCFG3"},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = true,  .name   = "ADCS2"},
        {.active = true,  .name   = "ADFM"},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
  },
  {
    {
      .reserved = true,
      .name="INDF",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="TMR0",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="PCL",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="STATUS",
      .bits={
        {.active = true,  .name   = "C"},
        {.active = true,  .name   = "DC"},
        {.active = true,  .name   = "Z"},
        {.active = true,  .name   = "PD"},
        {.active = true,  .name   = "TO"},
        {.active = true,  .name   = "RP0"},
        {.active = true,  .name   = "RP1"},
        {.active = true,  .name   = "IRP"},
      }
    },
    {
      .reserved = true,
      .name="FSR",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="PORTB",
      .bits={
        {.active = true,  .name   = "RB0"},
        {.active = true,  .name   = "RB1"},
        {.active = true,  .name   = "RB2"},
        {.active = true,  .name   = "RB3"},
        {.active = true,  .name   = "RB4"},
        {.active = true,  .name   = "RB5"},
        {.active = true,  .name   = "RB6"},
        {.active = true,  .name   = "RB7"},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="PCLATH",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="INTCON",
      .bits={
        {.active = true,  .name   = "RBIF"},
        {.active = true,  .name   = "INTF"},
        {.active = true,  .name   = "TMR0IF"},
        {.active = true,  .name   = "RBIE"},
        {.active = true,  .name   = "INTE"},
        {.active = true,  .name   = "TMR0IE"},
        {.active = true,  .name   = "PEIE"},
        {.active = true,  .name   = "GIE"},
      }
    },
    {
      .reserved = true,
      .name="EEDATA",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="EEADR",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="EEDATH",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="EEADRH",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
  },
  {
    {
      .reserved = true,
      .name="INDF",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="OPTION_REG",
      .bits={
        {.active = true,  .name   = "PS0"},
        {.active = true,  .name   = "PS1"},
        {.active = true,  .name   = "PS2"},
        {.active = true,  .name   = "PSA"},
        {.active = true,  .name   = "T0SE"},
        {.active = true,  .name   = "T0CS"},
        {.active = true,  .name   = "INTEDG"},
        {.active = true,  .name   = "RBPU"},
      }
    },
    {
      .reserved = true,
      .name="PCL",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="STATUS",
      .bits={
        {.active = true,  .name   = "C"},
        {.active = true,  .name   = "DC"},
        {.active = true,  .name   = "Z"},
        {.active = true,  .name   = "PD"},
        {.active = true,  .name   = "TO"},
        {.active = true,  .name   = "RP0"},
        {.active = true,  .name   = "RP1"},
        {.active = true,  .name   = "IRP"},
      }
    },
    {
      .reserved = true,
      .name="FSR",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="TRISB",
      .bits={
        {.active = true,  .name   = "TB0"},
        {.active = true,  .name   = "TB1"},
        {.active = true,  .name   = "TB2"},
        {.active = true,  .name   = "TB3"},
        {.active = true,  .name   = "TB4"},
        {.active = true,  .name   = "TB5"},
        {.active = true,  .name   = "TB6"},
        {.active = true,  .name   = "TB7"},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL}  ,
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="PCLATH",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="INTCON",
      .bits={
        {.active = true,  .name   = "RBIF"},
        {.active = true,  .name   = "INTF"},
        {.active = true,  .name   = "TMR0IF"},
        {.active = true,  .name   = "RBIE"},
        {.active = true,  .name   = "INTE"},
        {.active = true,  .name   = "TMR0IF"},
        {.active = true,  .name   = "PEIE"},
        {.active = true,  .name   = "GIE"},
      }
    },
    {
      .reserved = true,
      .name="EECON1",
      .bits={
        {.active = true,  .name   = "RD"},
        {.active = true,  .name   = "WR"},
        {.active = true,  .name   = "WREN"},
        {.active = true,  .name   = "WERR"},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = true,  .name   = "EEPGD"},
      }
    },
    {
      .reserved = true,
      .name="EECON2",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="RESERVED",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = true,
      .name="RESERVED",
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
    {
      .reserved = false,
      .name=NULL,
      .bits={
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
        {.active = false, .name   = NULL},
      }
    },
  },
};
