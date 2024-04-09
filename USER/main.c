#include "stm32f4xx.h"
//#include "led_ctrl.h"
//#include "beep.h"
#include "car.h"
#include "control.h"

//void delay(int a){
//	int i,j;
//	int t=a;
//	for(i=0;i<t;i++)
//	for(j=0;j<t;j++);
//}
//
//int main(void)
//{
//	led_init();
//    while(1) {
//	
//        led_ctr(D1, ON);
//        delay(5000);
//        led_ctr(D1, OFF);
//        delay(5000);
//        
//        led_ctr(D2, ON);
//        delay(5000);
//        led_ctr(D2, OFF);
//        delay(5000);
//        
//        led_ctr(D3, ON);
//        delay(5000);
//        led_ctr(D3, OFF);
//        delay(5000);
//        
//        led_ctr(D4, ON);
//        delay(5000);
//        led_ctr(D4, OFF);
//        delay(5000);
//    }
//}

//int main(void)
//{
//	beep_init();
//	beep_state(ON);
//
//}

//int main(void)
//{
//	while(1){
//
//		motor_init();
////		car_up();
////		car_back();
////		car_left();
////		car_right();
////		car_stop();
//	}
//}

//int main(void)
//{
//
//motor_init();
//control_init();
//
//while(1){
//
//	control_run();
//
//}
//}

int main(void)
{

motor_init();
control_init();

while(1){

	control_avoid();

}
}

