
#include "msp430.h"

#include "hal_boot.h"


/******************************************************************************/

#if (TOOLSET == IAR_TOOLS)
  __no_init __root static unsigned long long Signature @SIGNATURE_ADDR;
#else
  static unsigned long long Signature =  SIGNATURE_ADDR;
#endif

void SetBootloaderSignature(void)
{
  Signature = BOOTLOADER_SIGNATURE;
}

void ClearBootloaderSignature(void)
{
  Signature = 0;
}

unsigned long long GetBootloaderSignature(void)
{
  return Signature;
}


/******************************************************************************/

#if (TOOLSET == IAR_TOOLS)
  __no_init __root static unsigned int ResetSource @RESET_REASON_ADDR;
#else
  static unsigned int ResetSource = RESET_REASON_ADDR;
#endif

void SaveResetSource(void)
{
  /* save and then clear reason for reset */
  ResetSource = SYSRSTIV;
  SYSRSTIV = 0;
  
}

unsigned int GetResetSource(void)
{
  return ResetSource;
}

/******************************************************************************/



