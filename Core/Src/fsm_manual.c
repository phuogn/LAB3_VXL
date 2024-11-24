/*
 * fsm_manual.c
 *
 *  Created on: Nov 11, 2024
 *      Author: MSIFPT
 */
#include "fsm_manual.h"

int led_time;
int led_time2;
int ledd = 1;
int led_timea, led_timeb, led_time2a, led_time2b;

void fsm_manual() {
	switch(status) {
		case MAN_RED_GREEN:
			//TODO

			LIGHT_RED_GREEN();

			if (isModePressed() == 1) {
				status = MAN_RED_YELOW;
			}
			if (isApplyPressed() == 1) {
				status = current_status;
				setTimer(1,current_time*1000);
			}
			break;
		case MAN_RED_YELOW:
			//TODO

			LIGHT_RED_YELOW();

			if (isModePressed() == 1) {
				status = MAN_GREEN_RED;
			}
			if (isApplyPressed() == 1) {
				status = current_status;
				setTimer(1,current_time*1000);
			}
			break;
		case MAN_GREEN_RED:
			//TODO

			LIGHT_GREEN_RED();

			if (isModePressed() == 1) {
				status = MAN_YELOW_RED;
			}
			if (isApplyPressed() == 1) {
				status = current_status;
				setTimer(1,current_time*1000);
			}
			break;
		case MAN_YELOW_RED:
			//TODO

			LIGHT_YELOW_RED();

			if (isModePressed() == 1) {
				status = MAN_RED_GREEN;
			}
			if (isApplyPressed() == 1) {
				status = current_status;
				setTimer(1,current_time*1000);
			}
			break;
		default:
			break;
		}
}
