/*
 * fsm_automatic.c
 *
 *  Created on: Nov 10, 2024
 *      Author: MSIFPT
 */
#include "fsm_automatic.h"

int time;
int time2;
int led = 1;
int timea, timeb, time2a, time2b;

void fsm_automatic_run() {
	switch(status) {
	case INIT:
		//TODO
		time = red/1000;
		time2 = green/1000;
		INIT_LIGHT();
		init_segment();
		status = RED_GREEN;
		setTimer(0,SCAN_TIME);
		setTimer(1,green);
		setTimer(2,1000);
		break;
	case RED_GREEN:
		//TODO
		timea = time/10; timeb = time%10;
		time2a = time2/10; time2b = time2%10;
		led7_seg1(led, (led==1)?timea:timeb);
		led7_seg2(led, (led==1)?time2a:time2b);
		LIGHT_RED_GREEN();
		if (timer_flag[0] == 1) {
			led = led == 1 ? 2 : 1;
			setTimer(0,SCAN_TIME);
		}
		if (timer_flag[2] == 1) {
			time--;
			time2--;
			setTimer(2,1000);
		}
		if (timer_flag[1] == 1) {
			status = RED_YELOW;
			setTimer(1,yelow);
			time2 = yelow/1000;
		}
		if (isModePressed() == 1) {
			init_segment();
			status = MAN_RED_GREEN;
			current_status = RED_GREEN;
			current_time = time < time2 ? time : time2;
		}
		if (isApplyPressed() == 1) {
			current_status = RED_GREEN;
			current_time = time < time2 ? time : time2;
			status = SETTING;
		}
		break;
	case RED_YELOW:
		//TODO
		timea = time/10; timeb = time%10;
		time2a = time2/10; time2b = time2%10;
		led7_seg1(led, (led==1)?timea:timeb);
		led7_seg2(led, (led==1)?time2a:time2b);
		LIGHT_RED_YELOW();
		if (timer_flag[0] == 1) {
			led = led == 1 ? 2 : 1;
			setTimer(0,SCAN_TIME);
		}
		if (timer_flag[2] == 1) {
			time--;
			time2--;
			setTimer(2,1000);
		}
		if (timer_flag[1] == 1) {
			status = GREEN_RED;
			setTimer(1,green);
			time = green/1000;
			time2 = red/1000;
		}
		if (isModePressed() == 1) {
			init_segment();
			status = MAN_RED_YELOW;
			current_status = RED_YELOW;
			current_time = time < time2 ? time : time2;
		}
		if (isApplyPressed() == 1) {
			current_status = RED_GREEN;
			current_time = time < time2 ? time : time2;
			status = SETTING;
		}
		break;
	case GREEN_RED:
		//TODO
		timea = time/10; timeb = time%10;
		time2a = time2/10; time2b = time2%10;
		led7_seg1(led, (led==1)?timea:timeb);
		led7_seg2(led, (led==1)?time2a:time2b);
		LIGHT_GREEN_RED();
		if (timer_flag[0] == 1) {
			led = led == 1 ? 2 : 1;
			setTimer(0,SCAN_TIME);
		}
		if (timer_flag[2] == 1) {
			time--;
			time2--;
			setTimer(2,1000);
		}
		if (timer_flag[1] == 1) {
			status = YELOW_RED;
			setTimer(1,yelow);
			time = yelow/1000;
		}
		if (isModePressed() == 1) {
			init_segment();
			status = MAN_GREEN_RED;
			current_status = GREEN_RED;
			current_time = time < time2 ? time : time2;
		}
		if (isApplyPressed() == 1) {
			current_status = RED_GREEN;
			current_time = time < time2 ? time : time2;
			status = SETTING;
		}
		break;
	case YELOW_RED:
		//TODO
		timea = time/10; timeb = time%10;
		time2a = time2/10; time2b = time2%10;
		led7_seg1(led, (led==1)?timea:timeb);
		led7_seg2(led, (led==1)?time2a:time2b);
		LIGHT_YELOW_RED();
		if (timer_flag[0] == 1) {
			led = led == 1 ? 2 : 1;
			setTimer(0,SCAN_TIME);
		}
		if (timer_flag[2] == 1) {
			time--;
			time2--;
			setTimer(2,1000);
		}
		if (timer_flag[1] == 1) {
			status = RED_GREEN;
			setTimer(1,green);
			time2 = green/1000;
			time = red/1000;
		}
		if (isModePressed() == 1) {
			init_segment();
			status = MAN_YELOW_RED;
			current_status = YELOW_RED;
			current_time = time < time2 ? time : time2;
		}
		if (isApplyPressed() == 1) {
			current_status = RED_GREEN;
			current_time = time < time2 ? time : time2;
			status = SETTING;
		}
		break;
	default:
		break;
	}
}

