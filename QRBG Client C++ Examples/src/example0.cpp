#include <stdio.h>		// printf
#include "QRBG.h"

int main(int argc, char* argv[]) {
	QRBG rndService;
	rndService.defineServer("random.irb.hr", 1227);
	rndService.defineUser("mhawash", "seven11");

	// acquire some of supported types: byte, integer, long integer, float and double
	printf("QRBG service returned byte: %x \n", rndService.getByte());
	printf("QRBG service returned integer: %x \n", rndService.getInt());
	printf("QRBG service returned long integer: %x \n", rndService.getLongInt());
	printf("QRBG service returned float: %f \n", rndService.getFloat());
	printf("QRBG service returned double: %f \n", rndService.getDouble());

	// acquire arbitrary number of random bytes
	const int size = 313;
	byte buffer[size];
	printf("Requesting %d random bytes.. ", size);
	rndService.getBytes(buffer, size);
	printf("Received.\n");
}
