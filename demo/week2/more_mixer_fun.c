// ----------------------------------------------------------------------------
//
// -------------------------------- C Basic Mixer --------------------------------
//
// ----------------------------------------------------------------------------
//
//  Purpose : To study the effects of performing operations on 
//            mixed data types.
//
//  Author  : Paul Zoski
//  Date    : 4/3/99
//  Modified: reformatted, JL Popyack Jan. 2002, Jan. 2003.
//  Modified: rewritten by Jun Yuan-Murray, 2016, August.
// 
// ----------------------------------------------------------------------------

#include <stdio.h>

// ----------------------------------------------------------------------------
//
// ------------------------------- Main Program -------------------------------
//
// ----------------------------------------------------------------------------

void conditionmixer() {
	int i = 6;
	char ch = 'm';
	
	printf("3==(4==3) = %d\n", 3==(4==3));
	printf("!\"abc\" =%d\n", !"abc");

	printf("%d\n", 2 * 3 == 6 && (i = i + 1));
        printf("%d\n", i);
}

void typemixer() {
	float x=2.2, y=4.2/5.1, z=1.116e-5;
 	char dollarSign = '$';		
        printf ("x = %f \ty=%f \t\t z=%e\n", x, y, z);		
	// ---------------------------------------------------------------------		
		
	printf("x/dollarSign = %f\n", x/dollarSign);
	// ---------------------------------------------------------------------
}
int main( void )
{
	typemixer();
        conditionmixer();
	return 0;
}
