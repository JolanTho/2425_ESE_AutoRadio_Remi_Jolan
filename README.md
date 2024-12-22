# 2425_ESE_AutoRadio_Remi_Jolan

# TP synthèse autoradio

## 2 - LeGPIO Expander et le VU mètre
### 1- Configuration 
1) La référence du GPIO Expander est MCP23017.
2) Sur la stm32 le SPI utilisé est le SPI3 avec le MOSI branché sur PB5 et le MISO sur PC11.
3) Paramètre pour configurer la stm32 :
   <p align="center"><img src="https://github.com/JolanTho/2425_ESE_AutoRadio_Remi_Jolan/blob/main/Photos/param%C3%A8tre_SPI_GPIO_Expander.png" width="600" /> </p> 

### 2 - Test
Pour vérifier que tout soit correctement configuré nous avons fais un rapide programme permettant de faire clignoter une LED, puis nous avons fait un chenillard pour vérifier si toutes les LEDs fonctionnaient correctement et enfin nous avons fait une fonction permettant d'allumer et d'éteindre chaque LED séparément on passant par un shell.



## 3 - Le CODEC audio SGTL5000

### 1 - Configuration préalable
1) Les pins I2C utilisées pour la configuration de la stm32 sont les pins PB10 et PB11. Cela correspond à l'I2C 2 de la stm32.

3) Configuration de SAI2_A

      <p align="center"><img src="https://github.com/JolanTho/2425_ESE_AutoRadio_Remi_Jolan/blob/main/Photos/parametre_SAI2.png" width="600" /> </p> 
   Configuration de SAI2_B
   <p align="center"><img src="https://github.com/JolanTho/2425_ESE_AutoRadio_Remi_Jolan/blob/main/Photos/parametre_SAIB.png" width="600" /> </p> 
### 2 - Configuration du CODEC par l'I2C
1) Visualisation de MCLK à l'oscilloscope
   <p align="center"><img src="https://github.com/JolanTho/2425_ESE_AutoRadio_Remi_Jolan/blob/main/Photos/mclk1.png" width="600" /> </p> 
3) observation de la trame I2C à l'oscilloscope
   
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
