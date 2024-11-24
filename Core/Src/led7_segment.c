/*
 * led7_segment.c
 *
 *  Created on: Nov 11, 2024
 *      Author: MSIFPT
 */

#include "led7_segment.h"

void init_segment() {
	HAL_GPIO_WritePin(GPIOB, SEGMENT1A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, SEGMENT2A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, SEGMENT3A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, SEGMENT4A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, SEGMENT5A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, SEGMENT6A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, SEGMENT7A_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, SEGMENT1B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, SEGMENT2B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, SEGMENT3B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, SEGMENT4B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, SEGMENT5B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, SEGMENT6B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, SEGMENT7B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED7A2_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, LED7A1_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, LED7B2_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, LED7B1_Pin, SET);
}

void display7SEG(int road, int num) {
	// Mảng lưu giá trị các đoạn cho các số từ 0 đến 9
	    uint8_t segments[10] = {
	        0xC0, // 0 -> các đoạn a b c d e f (g tắt)
	        0xF9, // 1 -> các đoạn b c (a, d, e, f, g tắt)
	        0xA4, // 2 -> các đoạn a b d e g (c, f tắt)
	        0xB0, // 3 -> các đoạn a b c d g (e, f tắt)
	        0x99, // 4 -> các đoạn b c f g (a, d, e tắt)
	        0x92, // 5 -> các đoạn a c d f g (b, e tắt)
	        0x82, // 6 -> các đoạn a c d e f g (b tắt)
	        0xF8, // 7 -> các đoạn a b c (d, e, f, g tắt)
	        0x80, // 8 -> tất cả các đoạn a b c d e f g đều sáng
	        0x90  // 9 -> các đoạn a b c f g (d, e tắt)
	    };
	    if (road == 1) {
	    	HAL_GPIO_WritePin(GPIOB, SEGMENT1A_Pin, (segments[num] & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    	HAL_GPIO_WritePin(GPIOB, SEGMENT2A_Pin, (segments[num] & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    	HAL_GPIO_WritePin(GPIOB, SEGMENT3A_Pin, (segments[num] & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    	HAL_GPIO_WritePin(GPIOB, SEGMENT4A_Pin, (segments[num] & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    	HAL_GPIO_WritePin(GPIOB, SEGMENT5A_Pin, (segments[num] & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    	HAL_GPIO_WritePin(GPIOB, SEGMENT6A_Pin, (segments[num] & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    	HAL_GPIO_WritePin(GPIOB, SEGMENT7A_Pin, (segments[num] & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    } else {
	    	HAL_GPIO_WritePin(GPIOA, SEGMENT1B_Pin, (segments[num] & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    	HAL_GPIO_WritePin(GPIOA, SEGMENT2B_Pin, (segments[num] & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    	HAL_GPIO_WritePin(GPIOB, SEGMENT3B_Pin, (segments[num] & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    	HAL_GPIO_WritePin(GPIOC, SEGMENT4B_Pin, (segments[num] & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    	HAL_GPIO_WritePin(GPIOC, SEGMENT5B_Pin, (segments[num] & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    	HAL_GPIO_WritePin(GPIOC, SEGMENT6B_Pin, (segments[num] & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    	HAL_GPIO_WritePin(GPIOA, SEGMENT7B_Pin, (segments[num] & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    }
}

void led7_seg1(int led, int time) {
	if (led == 1) {
		HAL_GPIO_WritePin(GPIOB, LED7A2_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED7A1_Pin, RESET);
		display7SEG(1, time);
	}else {
		HAL_GPIO_WritePin(GPIOB, LED7A1_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED7A2_Pin, RESET);
		display7SEG(1, time);
	}
}

void led7_seg2(int led, int time) {
	if (led == 1) {
		HAL_GPIO_WritePin(GPIOB, LED7B2_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED7B1_Pin, RESET);
		display7SEG(2, time);
	}else {
		HAL_GPIO_WritePin(GPIOB, LED7B1_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED7B2_Pin, RESET);
		display7SEG(2, time);
	}
}

void led_setting() {

}

