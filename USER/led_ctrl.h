#ifndef __LED_CTRL_H__
#define __LED_CTRL_H__

enum led_num{
	D1,D2,D3,D4
};

enum led_state{
	ON,OFF
};

void led_inint(void);

void led_ctr(int led_num,int state);

#endif