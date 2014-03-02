/*
 * GENERATED FILE - DO NOT EDIT
 * (c) Code Red Technologies Ltd, 2008-2014
 * (c) NXP Semiconductors 2013-2014
 * Linker script memory definitions
 * Created from LinkMemoryTemplate
 * By LPCXpresso v6.0.2 [Build 151] [2013-09-18]  on Sun Mar 02 14:36:45 JST 2014)
*/

MEMORY
{
  /* Define each memory region */
  MFlash4 (rx) : ORIGIN = 0x0, LENGTH = 0x1000 /* 4k */
  RamLoc1 (rwx) : ORIGIN = 0x10000000, LENGTH = 0x400 /* 1k */


}
  /* Define a symbol for the top of each memory region */
  __top_MFlash4 = 0x0 + 0x1000;
  __top_RamLoc1 = 0x10000000 + 0x400;



