/*
 * button.c
 *
 *  Created on: Nov 10, 2024
 *      Author: MSIFPT
 */
#include "button.h"
int KeyReg0[4] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg1[4] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg2[4] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};
int KeyReg3[4] = {NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE};

int TimeOutForKeyPress[4] =  {500,500,500,500};
int button_pressed[4] = {0,0,0,0};
int button1_long_pressed = 0;
int button_flag[4] = {0,0,0,0};

int isApplyPressed(){
	if(button_flag[3] == 1){
		button_flag[3] = 0;
		return 1;
	}
	return 0;
}
int isModePressed(){
	if(button_flag[0] == 1){
		button_flag[0] = 0;
		return 1;
	}
	return 0;
}
int isTimeUpPressed(){
	if(button_flag[1] == 1){
		button_flag[1] = 0;
		return 1;
	}
	return 0;
}
int isTimeDownPressed(){
	if(button_flag[2] == 1){
		button_flag[2] = 0;
		return 1;
	}
	return 0;
}

int isButton1LongPressed(){
	if(button1_long_pressed == 1){
		button1_long_pressed = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(){
	//TODO
	//HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	button1_flag = 1;
}

void getKeyInput(){
	for (int i = 0; i < 4; i++) {
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
	}

  // Add your key
  KeyReg0[0] = HAL_GPIO_ReadPin(MODE_GPIO_Port, MODE_Pin);
  KeyReg0[1] = HAL_GPIO_ReadPin(TIME_UP_GPIO_Port, TIME_UP_Pin);
  KeyReg0[2] = HAL_GPIO_ReadPin(TIME_DOWN_GPIO_Port, TIME_DOWN_Pin);
  KeyReg0[3] = HAL_GPIO_ReadPin(APPLY_GPIO_Port, APPLY_Pin);
  	  for (int i = 0; i < 4; i++) {
  		  if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
  			  if (KeyReg2[i] != KeyReg3[i]){
  				  KeyReg3[i] = KeyReg2[i];

  				  if (KeyReg3[i] == PRESSED_STATE){
  					  TimeOutForKeyPress[i] = 500;
  					  //subKeyProcess();
  					  button_flag[i] = 1;
  				  }

  			  }else{
  				  TimeOutForKeyPress[i] --;
  				  if (TimeOutForKeyPress[i] == 0){
  					  TimeOutForKeyPress[i] = 500;
  					  if (KeyReg3[i] == PRESSED_STATE){
  						  //subKeyProcess();
  						button1_long_pressed = 1;
  					  }
  				  }
  			  }
  		  }
  	  }
}

