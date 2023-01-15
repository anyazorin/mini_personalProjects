// C program to convert
// IEEE 754 floating point representation
// into real value

#include <math.h>
#include <stdio.h>

typedef union {
 
	float f;
	struct
	{

		// Order is important.
		// Here the members of the union data structure
		// use the same memory (32 bits).
		// The ordering is taken
		// from the LSB to the MSB.

		unsigned int mantissa : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;

	} raw;
} myfloat;

// Function to convert a binary array
// to the corresponding integer
unsigned int convertToInt(int* arr, int low, int high)
{
	unsigned f = 0, i;
	for (i = high; i >= low; i--) {
		f = f + arr[i] * pow(2, high - i);
	}
	return f;
}

// Driver Code
int main()
{

	// INPUT THE FLOAT YOU ARE TRYING TO CONVERT HERE
    //FIRST ROW IS THE SIGN
    //SECOND IS EXPONENT
    //THIRD IS MANTISSA
    //RECOMPILE AND IGNORE WARNING GENERATED
	unsigned int ieee[32]
		= { 0,
			1, 0, 0, 0, 0, 1, 0, 0,
            0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	myfloat var;

	// Convert the least significant
	// mantissa part (23 bits)
	// to corresponding decimal integer
	unsigned f = convertToInt(ieee, 9, 31);

	// Assign integer representation of mantissa
	var.raw.mantissa = f;

	// Convert the exponent part (8 bits)
	// to a corresponding decimal integer
	f = convertToInt(ieee, 1, 8);

	// Assign integer representation
	// of the exponent
	var.raw.exponent = f;

	// Assign sign bit
	var.raw.sign = ieee[0];

	printf("The float value of the given"
		" IEEE-754 representation is : \n");
	printf("%f", var.f);
}
