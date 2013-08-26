#include <nds.h>
#include <stdio.h>

unsigned long long int iterativeFibonacci( unsigned int number );

void OnKeyPressed( int key ) {
	   if( key > 0 )
	      iprintf( "%c", key );
}

int main( void )  
{

	consoleDemoInit();

	Keyboard *kbd = keyboardDemoInit();

	kbd->OnKeyPressed = OnKeyPressed;

	while(1) {
		unsigned int n;

		iprintf( " Enter a unsigned integers: " );
		scanf( "%u", &n );

		iprintf( " Fibonacci %u = %llu\n", n, iterativeFibonacci( n ) );

      	scanKeys();
      	while(!keysDown())scanKeys();

      	swiWaitForVBlank();
      	consoleClear();
   	}

   	return 0;
}

unsigned long long int iterativeFibonacci( unsigned int number )
{
	unsigned int x = 0;
	unsigned int y = 1;
	int i;

	if ( number == 0 )
		return 0;

	for ( i = 1; i < number; i++ ) {
		y += x;
		x = y -x;
	}
	
	return y;
}
