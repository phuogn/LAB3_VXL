/*
 * software_timer.h
 *
 *  Created on: Nov 10, 2024
 *      Author: MSIFPT
 */

#ifndef SRC_SOFTWARE_TIMER_H_
#define SRC_SOFTWARE_TIMER_H_

extern int timer_flag[10];

void setTimer(int index, int counter);
void timer_run();

#endif /* SRC_SOFTWARE_TIMER_H_ */
