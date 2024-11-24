/*
 * fsm_setting.c
 *
 *  Created on: Nov 11, 2024
 *      Author: MSIFPT
 */

#include "fsm_setting.h"

int count = 0, leds = 1;
int counta, countb;
int red_term, green_term, yelow_term;

void fsm_setting() {
	switch(status) {
		case SETTING:
			INIT_LIGHT();
			init_segment();
			setTimer(0,SCAN_TIME);
			status = RED_SETTING;
			count = red/1000;
			break;
		case RED_SETTING:
			//TODO
			counta = count/10; countb = count%10;
			led7_seg1(leds, (leds==1)?counta:countb);
			if (isTimeUpPressed() == 1) {
				count++;
				if (count > 99) count = 0;
			}
			if (isTimeDownPressed() == 1) {
				if (count > 0) count--;
			}
			if (isModePressed() == 1) {
				setTimer(1,current_time);
				status = current_status;
			}
			if (timer_flag[0] == 1) {
				setTimer(0,SCAN_TIME);
				Toggle_red();
				leds = leds == 1 ? 2 : 1;
			}
			if (isApplyPressed()) {
				INIT_LIGHT();
				setTimer(0,SCAN_TIME);
				red_term = count;
				count = yelow/1000;
				status = YELOW_SETTING;
			}
			break;
		case YELOW_SETTING:
			//TODO
			counta = count/10; countb = count%10;
			led7_seg1(leds, (leds==1)?counta:countb);
			if (isTimeUpPressed() == 1) {
				count++;
				if (count > 99) count = 0;
			}
			if (isTimeDownPressed() == 1) {
				if (count > 0) count--;
			}
			if (isModePressed() == 1) {
				setTimer(1,current_time);
				status = current_status;
			}
			if (timer_flag[0] == 1) {
				setTimer(0,SCAN_TIME);
				Toggle_yelow();
				leds = leds == 1 ? 2 : 1;
			}
			if (isApplyPressed()) {
				INIT_LIGHT();
				setTimer(0,SCAN_TIME);
				yelow_term = count;
				count = green/1000;
				status = GREEN_SETTING;
			}
			break;
		case GREEN_SETTING:
			//TODO
			counta = count/10; countb = count%10;
			led7_seg1(leds, (leds==1)?counta:countb);
			if (isTimeUpPressed() == 1) {
				count++;
				if (count > 99) count = 0;
			}
			if (isTimeDownPressed() == 1) {
				if (count > 0) count--;
			}
			if (isModePressed() == 1) {
				setTimer(1,current_time);
				status = current_status;
			}
			if (timer_flag[0] == 1) {
				setTimer(0,SCAN_TIME);
				Toggle_green();
				leds = leds == 1 ? 2 : 1;
			}
			if (isApplyPressed()) {
				setTimer(0,SCAN_TIME);
				green_term = count;
				count = 0;
				if (green_term > 0 && yelow_term > 0 && red_term == green_term + yelow_term) {
					red = red_term*1000;
					green = green_term*1000;
					yelow = yelow_term*1000;
				}
				status = INIT;
			}
			break;
		default:
			break;
	}
}
