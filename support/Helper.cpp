#include <sys/types.h>

namespace Helper
{
	bool initialized;
	int ones[256];

  /* returns the number of binary ones in 'num'
   *
   */
	int count_ones(int num)
	{
		int count = 0;
		for (int i=0; i<8; i++) {
			count += num & 1;
			num >>= 1;
		}
		return count;
	}

	/* returns the number of binary ones in 'number'
   */
	int number_of_ones(ulong number)
	{
		int count=0;

		if (!initialized) {
			for (int i=0; i<256; i++)
				ones[i] = count_ones(i);

			initialized = true;
		}

		// Count ones for 64 bits..(8 bytes)
		for (int i=0; i<8; i++) {
			count += ones[number & 0xFF];
			number >>= 8;
		}
		return count;
	}
}

