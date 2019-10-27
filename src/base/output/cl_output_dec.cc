// fprintdecimal().

// General includes.
#include "base/cl_sysdep.h"

// Specification.
#include "cln/io.h"


// Implementation.

namespace cln {

// We don't use `stream << x' or `stream << dec << x', because an ostream
// carries so many attributes, and we don't want to modifies these attributes.

void fprintdecimal_impl (std::ostream& stream, uintptr_t x)
{
	#define bufsize (((sizeof(uintptr_t)*53)/22)+1) // 53/22 > 8*log(2)/log(10)
	var char buf[bufsize+1];
	var char* bufptr = &buf[bufsize];
	*bufptr = '\0';
	do {
		uintptr_t q = x / 10;
		uintptr_t r = x % 10;
		*--bufptr = '0'+r;
		x = q;
	} while (x > 0);
	fprint(stream,bufptr);
	#undef bufsize
}

void fprintdecimal_impl (std::ostream& stream, intptr_t x)
{
	if (x >= 0)
		fprintdecimal(stream,(uintptr_t)x);
	else {
		fprintchar(stream,'-');
		fprintdecimal(stream,(uintptr_t)(-1-x)+1);
	}
}

#if defined(HAVE_LONGLONG) && (long_long_bitsize > pointer_bitsize)

void fprintdecimal (std::ostream& stream, unsigned long long x)
{
	#define bufsize (((sizeof(unsigned long long)*53)/22)+1) // 53/22 > 8*log(2)/log(10)
	var char buf[bufsize+1];
	var char* bufptr = &buf[bufsize];
	*bufptr = '\0';
	do {
		unsigned long long q = x / 10;
		unsigned long long r = x % 10;
		*--bufptr = '0'+r;
		x = q;
	} while (x > 0);
	fprint(stream,bufptr);
	#undef bufsize
}

void fprintdecimal (std::ostream& stream, long long x)
{
	if (x >= 0)
		fprintdecimal(stream,(unsigned long long)x);
	else {
		fprintchar(stream,'-');
		fprintdecimal(stream,(unsigned long long)(-1-x)+1);
	}
}

#endif

}  // namespace cln
