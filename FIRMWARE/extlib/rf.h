#ifndef RF_H
#define RF_H

#include "msp430.h"


//Radio registers
#define RSSI_OFFSET -76;
#define CORR_THR                      0x14
#define CCA_THR                       0xF8
#define TXFILTCFG                     XREG( 0x61FA )
#define TXFILTCFG_RESET_VALUE         0x09
#define  PANL     XREG( 0x6172 ) //PAN LSB
#define  PANH     XREG( 0x6173 ) //PAN MSB
#define  SHORT_ADDRL     XREG( 0x6174 ) //Short addresss LSB
#define  SHORT_ADDRH     XREG( 0x6175 ) //Short address MSB

// Immediate strobe processor command instructions (issue twice)
#define ISRXON        0xE3
#define ISTXON        0xE9
#define ISTXONCCA     0xEA
#define ISRFOFF       0xEF
#define ISFLUSHRX     0xED
#define ISFLUSHTX     0xEE

typedef struct {
  short pan;
  short addr;
  char channel;
  char txPower;
} rfConfig_t;

//Prototypes
void radioInit(rfConfig_t rfConfig);
void sendPacket(char* ptr, short len, short pan, short dest, short src);
char receivePacket(char* ptr, char len, signed char* rssi);
char isPacketReady(void);

#endif
