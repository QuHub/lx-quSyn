#include "Rand.h"
#include <tr1/random>

using namespace std::tr1;

namespace Rand {
   #define BUF_SIZE (10)
  float buffer[BUF_SIZE];
  long index=0;
  int64 count=0;
  QRBG qrbg;
  bool connected=false;

  void connect() {
    try {
      qrbg.defineServer("random.irb.hr", 1227);
      qrbg.defineUser("mhawash", "seven11");
      connected = true;
    } catch(QRBG::InvalidArgumentError e) {
      printf("QRBG: Invalid username or password: %s\n", e.what());
    }
  }
  void fill_buffer() {
    try {
      if(!connected) connect();
      qrbg.getFloats(buffer, BUF_SIZE);
      index = 0;
      cout << "Fetching random numbers: " << (count+=BUF_SIZE) << "\n";
    } catch (QRBG::ServiceDenied e) {
      printf("QRBG: Service denied: %08x 08x\n", e.ServerResponse, e.RefusalReason);
      printf("--> Why: %s, Cure: %s\n", e.why(), e.cure());
    } catch (exception e) {
      printf("QRBG: Other exception: %s\n", e.what());
    }
  }

  ptrdiff_t for_random_shuffle(ptrdiff_t i) {
    //std::tr1::mt19937 eng;
    //std::tr1::uniform_int<int> unif(0, i);
    //return unif(eng);
    if((index % BUF_SIZE) == 0) fill_buffer();
    return (ptrdiff_t)((i-1)*buffer[index++]);
  }
}
