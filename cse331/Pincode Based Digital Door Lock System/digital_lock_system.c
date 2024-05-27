#include <reg51.h>
#include <string.h>
// Pin configuration for LEDs
sbit lw = P0^0;
sbit lb = P0^2;
sbit lr = P0^4;

// Pin configuration for 7-segment display
sbit da = P1^0;
sbit db = P1^1;
sbit dc = P1^2;
sbit dd = P1^3;
sbit de = P1^4;
sbit df = P1^5;
sbit dg = P1^6;

// Pin configuration for stepper motor
sbit m1 = P2^0;
sbit m2 = P2^1;
sbit m3 = P2^2;
sbit m4 = P2^3;

// Pin configuration for keypad column
sbit c1 = P3^0;
sbit c2 = P3^1;
sbit c3 = P3^2;

// Pin configuration for keypad row
sbit r1 = P3^3;
sbit r2 = P3^4;
sbit r3 = P3^5;
sbit r4 = P3^6;

int n;	// counter
char key;	// pressed digit
char codes[] = "54321";	// PIN Code
char id[5];	

// Function Declaration
void init_led();          // Initialize LEDs
void init_display();      // Initialize 7-segment display
void delay(int);          // Delay function
char scan_key();					// get digit
char read_keypad();				// access the keypad
void display_digit(char);	// display the digit
void door_open();					// open door
void door_close();				// close door

void main() {
	for(;;){
		P1 = 0x00;	//Using port 1 as output port
		P2 = 0x00;	//Using port 1 as output port
		P3 = 0xff;	//Using port 1 as input port
		P0 = 0x00;	//Using port 1 as output port
		lw = 1;
		lb = 1;
		lr = 1;
		init_led();
		init_display();
		n = 0;
		while(n<5){
			key = scan_key();
			id[n] = key;
			delay(100);
			n++;
		}
		if(strcmp(codes, id) ==0){
			door_open();
			
		}
		else{
			lw = 0;
			lr = 0;
			delay(4000);
			lr = 1;
			delay(2);
		}
	}
}

void door_open(){
	lw = 0;
	lb = 0;
	delay(200);
	m4= 1;
	m2 = m3 = m1 = 0;
	delay(200);
	m3 = 1;
	m1 = m2 = m4 = 0;
	delay(5000);
	door_close();
	delay(200);
	
}
void door_close(){
	lw = 0;
	lb = 1;
	delay(200);
	m4 = 1;
	m1 = m2 = m3 = 0;
	delay(200);
	m1 = 1;
	m2 = m3 = m4 = 0;
	delay(200);
	
}


void init_led() {
		delay(2);
    lw = 0;  // lw LED always on
		delay(2);
}

void init_display(){
		da=db=dc=dd=de=df=dg=0;
		delay(2);
}

char scan_key()
{
	char b='a';
	while(b=='a'){
		b=read_keypad();
	}
	return b;
}
//Function to take input from Lcd Keyboard 4*3
char read_keypad(){
	c1=c2=c3=1; // all columns are initially low
	r1=r2=r3=r4=0; // all rows are initially low (active-high)
	
	//when first row is active and others are incactive
	r1=0;
	r2=r3=r4=1;
	//if row=0 column=0 then 1 is returned or if we enter 1 in keypad 2
	if(c1==0){
		display_digit('1');
		delay(2);
		return '1';
	}
	//if row=0 column=1 then 2 is returned or if we enter  in keypad 2
	if(c2==0){
		display_digit('2');
		delay(2);
		return '2';
	}
	//if row=0 column=2 then 3 is returned or if we enter  in keypad 3
	if(c3==0){
		display_digit('3');
		delay(2);
		return '3';
	}
	
	//when second row is active and others are incactive
	r2=0;
	r1=r3=r4=1;
	//if row=1 column=0 then 4 is returned or if we enter  in keypad 4
	if(c1==0){
		display_digit('4');
		delay(2);
		return '4';
	}
	//if row=1 column=1 then 5 is returned or if we enter  in keypad 5
	if(c2==0){
		display_digit('5');
		delay(2);
		return '5';
	}
	//if row=1 column=2 then 6 is returned or if we enter  in keypad 6
	if(c3==0){
		display_digit('6');
		delay(2);
		return '6';
	}
	
	//when third row is active and others are incactive
	r3=0;
	r1=r2=r4=1;
	//if row=2 column=0 then 7 is returned or if we enter  in keypad 7
	if(c1==0){
		display_digit('7');
		delay(2);
		return '7';
	}
	//if row=2 column=1 then 8 is returned or if we enter  in keypad 8
	if(c2==0){
		display_digit('8');
		delay(2);
		return '8';
	}
	//if row=2 column=2 then 9 is returned or if we enter  in keypad 9
	if(c3==0){
		display_digit('9');
		delay(2);
		return '9';
	}
	
	//when fourth row is active and others are incactive
	r4=0;
	r1=r2=r3=1;
	//if row=3 column=0 then * is returned or if we enter  in keypad *
	//if(c1==0){
	//	lcddata('*');
	//	delay(2);
	//	return 0;
	//}
	//if row=3 column=1 then 0 is returned or if we enter  in keypad 0
	if(c2==0){
		display_digit('0');
		delay(2);
		return '0';
	}

	return 'a';
}

void display_digit(char digit) {
    switch (digit) {
        case '0':
            da = db = dc = dd = de = df = 1;
            dg = 0;
            break;
        case '1':
            db = dc = 1;
            da = dd = de = df = dg = 0;
            break;
        case '2':
            da = db = dd = de = dg = 1;
            dc = df = 0;
            break;
        case '3':
            da = db = dc = dd = dg = 1;
            de = df = 0;
            break;
        case '4':
            db = dc = df = dg = 1;
            da = dd = de = 0;
            break;
        case '5':
            da = df = dd = dc = dg = 1;
            db = de = 0;
            break;
        case '6':
            da = dc = dd = de = df = dg = 1;
            db = 0;
            break;
        case '7':
            da = db = dc = 1;
            dd = de = df = dg = 0;
            break;
        case '8':
            da = db = dc = dd = de = df = dg = 1;
            break;
        case '9':
            da = db = dc = dd = de = df = dg = 1;
            de = 0;
            break;
        default:
            break;
    }
    delay(300); // Delay for 200ms to display the digit
    init_display(); // Turn off the display after showing the digit
}

void delay(int ms) {
    int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 120; j++);
}