# 2425_ESE_AutoRadio_Remi_Jolan

# TP synthèse autoradio

## 2 - LeGPIO Expander et le VU mètre
### 1- Configuration 
1) La référence du GPIO Expander est MCP23017.
2) Sur la stm32 le SPI utilisé est le SPI3 avec le MOSI branché sur PB5 et le MISO sur PC11.
3) MEttre la photo des paramètre.


## 3 - Le CODEC audio SGTL5000
### 2 - Configuration du CODEC par l'I2C
Adresse des registre :
- CHIP_ANA_POWER : 0x0030
- CHIP_LINREG_CTRL : 0x0026
-  CHIP_REF_CTRL : 0x0028
-  CHIP_LINE_OUT_CTRL : 0x002C
-  CHIP_SHORT_CTRL : 0x003C
-  CHIP_ANA_CTRL : 0x0024
-  CHIP_DIG_POWER : 0x0002
-  CHIP_LINE_OUT_VOL : 0x002E
-  CHIP_CLK_CTRL : 0x0004
-  CHIP_I2S_CTRL : 0x0006
-  CHIP_ADCDAC_CTRL : 0x000E
- CHIP_DAC_VOL : 0x0010
