Voici une version corrigée et formalisée du texte :

---

# 2425_ESE_AutoRadio_Remi_Jolan  

# TP Synthèse Autoradio  

## 2 - Le GPIO Expander et le VU-mètre  

### 1 - Configuration  
1. La référence du GPIO Expander est **MCP23017**.  
2. Sur la STM32, le SPI utilisé est le **SPI3**, avec le **MOSI** branché sur **PB5** et le **MISO** sur **PC11**.  
3. Paramètres pour configurer la STM32 :  
   <p align="center"><img src="https://github.com/JolanTho/2425_ESE_AutoRadio_Remi_Jolan/blob/main/Photos/param%C3%A8tre_SPI_GPIO_Expander.png" width="600" /></p>  

### 2 - Tests  
Pour vérifier que tout est correctement configuré, nous avons écrit un programme simple permettant :  
1. De faire clignoter une LED.  
2. De réaliser un chenillard afin de tester toutes les LEDs.  
3. D’allumer et d’éteindre chaque LED séparément via un shell.

---

## 3 - Le CODEC audio SGTL5000  

### 1 - Configuration préalable  
1. Les pins I2C utilisées pour la configuration de la STM32 sont les pins **PB10** et **PB11**, correspondant à l’I2C 2 de la STM32.  
2. Configuration de **SAI2_A** :  
   <p align="center"><img src="https://github.com/JolanTho/2425_ESE_AutoRadio_Remi_Jolan/blob/main/Photos/parametre_SAI2.png" width="600" /></p>  
3. Configuration de **SAI2_B** :  
   <p align="center"><img src="https://github.com/JolanTho/2425_ESE_AutoRadio_Remi_Jolan/blob/main/Photos/parametre_SAIB.png" width="600" /></p>  

### 2 - Configuration du CODEC via l’I2C  
1. Visualisation du signal **MCLK** à l’oscilloscope :  
   <p align="center"><img src="https://github.com/JolanTho/2425_ESE_AutoRadio_Remi_Jolan/blob/main/Photos/mclk1.png" width="600" /></p>  
2. Observation de la trame I2C à l’oscilloscope :  
   <p align="center"><img src="https://github.com/JolanTho/2425_ESE_AutoRadio_Remi_Jolan/blob/main/Photos/I2C.png" width="600" /></p>  
3. Adresses des registres :  
   - **CHIP_ANA_POWER** : 0x0030  
   - **CHIP_LINREG_CTRL** : 0x0026  
   - **CHIP_REF_CTRL** : 0x0028  
   - **CHIP_LINE_OUT_CTRL** : 0x002C  
   - **CHIP_SHORT_CTRL** : 0x003C  
   - **CHIP_ANA_CTRL** : 0x0024  
   - **CHIP_DIG_POWER** : 0x0002  
   - **CHIP_LINE_OUT_VOL** : 0x002E  
   - **CHIP_CLK_CTRL** : 0x0004  
   - **CHIP_I2S_CTRL** : 0x0006  
   - **CHIP_ADCDAC_CTRL** : 0x000E  
   - **CHIP_DAC_VOL** : 0x0010  

### 3 - Signaux I2S  
Observation des signaux I2S à l’oscilloscope :  
<p align="center"><img src="https://github.com/JolanTho/2425_ESE_AutoRadio_Remi_Jolan/blob/main/Photos/sda1_.png" width="600" /></p>  

---
