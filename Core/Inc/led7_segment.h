/*
 * led7_segment.h
 *
 *  Created on: Nov 11, 2024
 *      Author: MSIFPT
 */

#ifndef SRC_LED7_SEGMENT_H_
#define SRC_LED7_SEGMENT_H_

#include "global.h"
#include "main.h"

void init_segment();
void display7SEG(int LED, int num);
void led7_seg1(int led, int time);
void led7_seg2(int led, int time);
void led_setting();

#endif /* SRC_LED7_SEGMENT_H_ */
