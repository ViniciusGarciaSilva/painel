#include <at892051.h>

sbit signal = P3^4;
sbit type = P3^5;

void delay(int delay_time);
void begin();
void start();
void send_signal();
void clear_signal();
void finish(int delay_time);
void allOn();
void allOff();
void blink(int delay_time, int repeat);
void run(int delay_time, int repeat);
void hitAndTurn(int delay_time, int repeat);
void runAndBack(int delay_time, int repeat);
void wait(int delay_time);
void set(float value, int delay_time);
void load(int delay_time);
void unload(int delay_time);
void reverseLoad(int delay_time);
void loadReverseLoad(int delay_time, repeat);
void loadUnload(int delay_time, repeat);

int main( ) {
	while(1) {
		run(50,10);
		loadReverseLoad(150,2);
		run(100,5);
		loadReverseLoad(50,10);
	}
}

void wait(int delay_time) {
	allOff();
	delay(delay_time);
}

void blink(int delay_time, int repeat) {
	int i;
	start();
	for(i=0 ; i<repeat ; i++) {
		allOn();
		delay(delay_time);
		allOff();
		delay(delay_time);
	}
}

void hitAndTurn(int delay_time, int repeat) {
	int i;
	start();
	if (type==0) {
		for(i=0 ; i<repeat ; i++) {
			set(0xF3, delay_time); // 11110011
			set(0xF9, delay_time); // 11111001
			set(0xFC, delay_time); // 11111100
			set(0x7E, delay_time); // 01111110
			set(0x3F, delay_time); // 00111111
			set(0x9F, delay_time); // 10011111
			set(0xCF, delay_time); // 11001111
			set(0x9F, delay_time); // 10011111
			set(0x3F, delay_time); // 00111111
			set(0x7E, delay_time); // 01111110
			set(0xFC, delay_time); // 11111100
			set(0xF9, delay_time); // 11111001
		}
	}
	else if(type==1) {
		for(i=0 ; i<repeat ; i++) {
			set(0xCF, delay_time); // 11001111
			set(0x9F, delay_time); // 10011111
			set(0x3F, delay_time); // 00111111
			set(0x7E, delay_time); // 01111110
			set(0xFC, delay_time); // 11111100
			set(0xF9, delay_time); // 11111001
			set(0xF3, delay_time); // 11110011
			set(0xF9, delay_time); // 11111001
			set(0xFC, delay_time); // 11111100
			set(0x7E, delay_time); // 01111110
			set(0x3F, delay_time); // 00111111
			set(0x9F, delay_time); // 10011111
		}
	}
}

void run(int delay_time, int repeat) {
	int i;
	start();
	for (i=0 ; i<repeat ; i++) {
		set(0xF3, delay_time); // 11110011
		set(0xF9, delay_time); // 11111001
		set(0xFC, delay_time); // 11111100
		set(0x7E, delay_time); // 01111110
		set(0x3F, delay_time); // 00111111
		set(0x9F, delay_time); // 10011111
		set(0xCF, delay_time); // 11001111
		set(0xE7, delay_time); // 11100111
	}
}

void set(float value, int delay_time) {
	P1 = value;
	delay(delay_time);
}

void runAndBack(int delay_time, int repeat) {
	int i;
	start();
	for (i=0 ; i<repeat ; i++) {
		set(0xF3, delay_time); // 11110011
		set(0xF9, delay_time); // 11111001
		set(0xF3, delay_time); // 11110011
		set(0xF9, delay_time); // 11111001
		set(0xFC, delay_time); // 11111100
		set(0xF9, delay_time); // 11111001
		set(0xFC, delay_time); // 11111100
		set(0x7E, delay_time); // 01111110
		set(0xFC, delay_time); // 11111100
		set(0x7E, delay_time); // 01111110
		set(0x3F, delay_time); // 00111111
		set(0x7E, delay_time); // 01111110
		set(0x3F, delay_time); // 00111111
		set(0x9F, delay_time); // 10011111
		set(0x3F, delay_time); // 00111111
		set(0x9F, delay_time); // 10011111
		set(0xCF, delay_time); // 11001111
		set(0x9F, delay_time); // 10011111
		set(0xCF, delay_time); // 11001111
		set(0xE7, delay_time); // 11100111
		set(0xCF, delay_time); // 11001111
		set(0xE7, delay_time); // 11100111
	}
}

void loadUnload(int delay_time, repeat){
	int i;
	start();
	for ( i=0 ; i<repeat ; i++) {
		load(delay_time);
		unload(delay_time);
	}
}

void loadReverseLoad(int delay_time, repeat) {
	int i;
	start();
	for ( i=0 ; i<repeat ; i++) {
		load(delay_time);
		reverseLoad(delay_time);
	}
}

void load(int delay_time) {
	set(0xF7, delay_time); // 11110111
	set(0xF3, delay_time); // 11110011
	set(0xF1, delay_time); // 11110001
	set(0xF0, delay_time); // 11110000
	set(0x70, delay_time); // 01110000
	set(0x30, delay_time); // 00110000
	set(0x10, delay_time); // 00010000
	set(0x00, delay_time); // 00000000
}

void unload(int delay_time) {
	set(0x10, delay_time); // 00010000
	set(0x30, delay_time); // 00110000
	set(0x70, delay_time); // 01110000
	set(0xF0, delay_time); // 11110000
	set(0xF1, delay_time); // 11110001
	set(0xF3, delay_time); // 11110011
	set(0xF7, delay_time); // 11110111
	set(0xFF, delay_time); // 11111111
}

void reverseLoad(int delay_time) {
	set(0x08, delay_time); // 00001000
	set(0x0C, delay_time); // 00001100
	set(0x0E, delay_time); // 00001110
	set(0x0F, delay_time); // 00001111
	set(0x8F, delay_time); // 10001111
	set(0xCF, delay_time); // 11001111
	set(0xEF, delay_time); // 11101111
	set(0xFF, delay_time); // 11111111
}
	
void delay(int value) { 
	int i,j;
	for( i=0 ; i<100 ; i++)
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
	return;
}

void clear_signal() {
	signal=0;
	return;
}

void begin() {
	if (type == 1) {
		signal=0;
	}
	return;
}

void start() {
	/*if(type == 0){
		delay(50);
		while(signal==0) {
		};
	}	
	else {
		clear_signal();
		delay(100);
		send_signal(); 
	}
	return;
	*/
}

void finish(int delay_time){
	if (type == 0) 
		delay(delay_time);
}