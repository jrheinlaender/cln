// fprinthexadecimal().

// General includes.
#include "base/cl_sysdep.h"

// Specification.
#include "cln/io.h"


// Implementation.

namespace cln {

void fprinthexadecimal (std::ostream& stream, uintptr_t x)
{
	#define bufsize 16
	var char buf[bufsize+1];
	var char* bufptr = &buf[bufsize];
	*bufptr = '\0';
	do {
		unsigned long q = x / 16;
		unsigned long r = x % 16;
		*--bufptr = (r<10 ? '0'+r : 'A'-10+r);
		x = q;
	} while (x > 0);
	fprint(stream,bufptr);
	#undef bufsize
}

void fprinthexadecimal (std::ostream& stream, intptr_t x)
{
	if (x >= 0)
		fprintdecimal(stream,(uintptr_t)x);
	else {
		fprintchar(stream,'-');
		fprintdecimal(stream,(uintptr_t)(-1-x)+1);
	}
}

}  // namespace cln
