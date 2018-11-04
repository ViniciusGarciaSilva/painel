#include <at892051.h>

sbit signal = P3^4;
sbit type = P3^5;

void delay(int delay_time);
void begin();
void start(int );
void send_signal();
void finish(int delay_time);
void allOn();
void allOff();
void blink(int delay_time, int repeat);
void run(int delay_time, int repeat);
void hitAndTurn(int delay_time, int repeat);
void runAndBack(int delay_time, int repeat);
void wait(int delay_time);
void set(float value, int delay_time);


int main( ) {
	begin();
	while(1) {
		run(10, 6);
		hitAndTurn(10, 3);
		runAndBack(10, 2);
	}
}

void wait(int delay_time) {
	allOff();
	delay(delay_time);
}

void blink(int delay_time, int repeat) {
	int i;
	start(0);
	for(i=0 ; i<repeat ; i++) {
		allOn();
		delay(delay_time);
		allOff();
		delay(delay_time);
	}
	finish(0);
}

void hitAndTurn(int delay_time, int repeat) {
	int i;
	start(0);
	if (type==0) {
		for(i=0 ; i<repeat ; i++) {
			P1 = 0xF3; // 11110011
			delay(delay_time);
			P1 = 0xF9; // 11111001
			delay(delay_time);
			P1 = 0xFC; // 11111100
			delay(delay_time);
			P1 = 0x7E; // 01111110
			delay(delay_time);
			P1 = 0x3F; // 00111111
			delay(delay_time);
			P1 = 0x9F; // 10011111
			delay(delay_time);
			P1 = 0xCF; // 11001111
			delay(delay_time);
			P1 = 0x9F; // 10011111
			delay(delay_time);
			P1 = 0x3F; // 00111111
			delay(delay_time);
			P1 = 0x7E; // 01111110
			delay(delay_time);
			P1 = 0xFC; // 11111100
			delay(delay_time);
			P1 = 0xF9; // 11111001
			delay(delay_time);
		}
	}
	else if(type==1) {
		for(i=0 ; i<repeat ; i++) {
			P1 = 0xCF; // 11001111
			delay(delay_time);
			P1 = 0x9F; // 10011111
			delay(delay_time);
			P1 = 0x3F; // 00111111
			delay(delay_time);
			P1 = 0x7E; // 01111110
			delay(delay_time);
			P1 = 0xFC; // 11111100
			delay(delay_time);
			P1 = 0xF9; // 11111001
			delay(delay_time);
			P1 = 0xF3; // 11110011
			delay(delay_time);
			P1 = 0xF9; // 11111001
			delay(delay_time);
			P1 = 0xFC; // 11111100
			delay(delay_time);
			P1 = 0x7E; // 01111110
			delay(delay_time);
			P1 = 0x3F; // 00111111
			delay(delay_time);
			P1 = 0x9F; // 10011111
			delay(delay_time);
		}
	}
	finish(0);
}

void run(int delay_time, int repeat) {
	int i;
	start(0);
	for (i=0 ; i<repeat ; i++) {
		set(0xF3, delay_time);
		set(0xF9, delay_time);
		set(0xFC, delay_time);
		set(0x7E, delay_time);
		set(0x3F, delay_time);
		set(0x9F, delay_time);
		set(0xCF, delay_time);
		set(0xE7, delay_time);
		/*
		P1 = 0xF3; // 11110011
		delay(delay_time);
		P1 = 0xF9; // 11111001
		delay(delay_time);
		P1 = 0xFC; // 11111100
		delay(delay_time);
		P1 = 0x7E; // 01111110
		delay(delay_time);
		P1 = 0x3F; // 00111111
		delay(delay_time);
		P1 = 0x9F; // 10011111
		delay(delay_time);
		P1 = 0xCF; // 11001111
		delay(delay_time);
		P1 = 0xE7; // 11100111
		delay(delay_time);
		*/
	}
	finish(0);
}

void set(float value, int delay_time) {
	P1 = value;
	delay(delay_time);
}

void runAndBack(int delay_time, int repeat) {
	int i;
	start(0);
	for (i=0 ; i<repeat ; i++) {
		P1 = 0xF3; // 11110011
		delay(delay_time);
		P1 = 0xF9; // 11111001
		delay(delay_time);
		P1 = 0xF3; // 11110011
		delay(delay_time);
		P1 = 0xF9; // 11111001
		delay(delay_time);
		P1 = 0xFC; // 11111100
		delay(delay_time);
		P1 = 0xF9; // 11111001
		delay(delay_time);
		P1 = 0xFC; // 11111100
		delay(delay_time);
		P1 = 0x7E; // 01111110
		delay(delay_time);
		P1 = 0xFC; // 11111100
		delay(delay_time);
		P1 = 0x7E; // 01111110
		delay(delay_time);
		P1 = 0x3F; // 00111111
		delay(delay_time);
		P1 = 0x7E; // 01111110
		delay(delay_time);
		P1 = 0x3F; // 00111111
		delay(delay_time);
		P1 = 0x9F; // 10011111
		delay(delay_time);
		P1 = 0x3F; // 00111111
		delay(delay_time);
		P1 = 0x9F; // 10011111
		delay(delay_time);
		P1 = 0xCF; // 11001111
		delay(delay_time);
		P1 = 0x9F; // 10011111
		delay(delay_time);
		P1 = 0xCF; // 11001111
		delay(delay_time);
		P1 = 0xE7; // 11100111
		delay(delay_time);
		P1 = 0xCF; // 11001111
		delay(delay_time);
		P1 = 0xE7; // 11100111
		delay(delay_time);
		P1 = 0xF3; // 11110011
		delay(delay_time);
		P1 = 0xE7; // 11100111
		delay(delay_time);
	}
	finish(0);
}

void load(int delay_time, int repeat) {
	P1 = 0xF7; // 11110111
	P1 = 0xF3; // 11110011
	P1 = 0xF1; // 11110001
	P1 = 0xF0; // 11110000
	P1 = 0x70; // 01110000
	P1 = 0x30; // 00110000
	P1 = 0x10; // 00010000
	P1 = 0x00; // 00000000
}

void unload(int delay_time, int repeat) {
	P1 = 0x10; // 00010000
	P1 = 0x30; // 00110000
	P1 = 0x70; // 01110000
	P1 = 0xF0; // 11110000
	P1 = 0xF1; // 11110001
	P1 = 0xF3; // 11110011
	P1 = 0xF7; // 11110111
	P1 = 0xFF; // 11111111
}

void reverseLoad(int delay_time, int repeat) {
	P1 = 0x08; // 00001000
	P1 = 0x0C; // 00001100
	P1 = 0x0E; // 00001110
	P1 = 0x0F; // 00001111
}
	
void delay(int value) { 
	int i,j;
	for( i=0 ; i<1000 ; i++)
		for( j=0 ; j<value ; j++ );
	return;
}

void allOn() {
	P1 = 0x00;
	
}

void allOff() {
	P1 = 0xFF; 
}

void send_signal() {
	signal=1;
	delay(1);
	signal=0;
	return;
}

void begin() {
	if (type == 1) {
		signal=0;
	}
	return;
}

void start(int delay_time) {
	if(type == 0){
		while(signal==0);
	}	
	else if(type == 1) {
		send_signal();
		delay(delay_time);
	}
	return;
}

void finish(int delay_time){
	if (type == 0) 
		delay(delay_time);
}