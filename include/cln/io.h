// I/O through <iostream>

#ifndef _CL_IO_H
#define _CL_IO_H

#include "cln/types.h"
#include "cln/modules.h"
#include <stdint.h>

// I/O through <iostream>

#ifdef floor
  #undef floor
  #include <iostream>
  #define floor cln_floor
#else
  #include <iostream>
#endif

namespace cln {

// compatibility:
typedef std::istream& cl_istream;
typedef std::ostream& cl_ostream;
extern std::ostream* cl_debugout_stream;
#define cl_debugout  (*cl_debugout_stream)

// Elementary operations on std::ostream&

inline void fprintchar (std::ostream& stream, char c)
{
	stream.put(c);
}

inline void fprint (std::ostream& stream, const char * string)
{
	stream << string;
}


extern void fprintdecimal (std::ostream& stream, uintptr_t x);
extern void fprintdecimal (std::ostream& stream, intptr_t x);

#if (pointer_bitsize != long_bitsize)
inline void fprintdecimal (std::ostream& stream, unsigned long x)
{
	fprintdecimal(stream,(uintptr_t)x);
}
inline void fprintdecimal (std::ostream& stream, long x)
{
	fprintdecimal(stream,(intptr_t)x);
}
#endif

#if (pointer_bitsize != int_bitsize)
inline void fprintdecimal (std::ostream& stream, unsigned int x)
{
	fprintdecimal(stream,(uintptr_t)x);
}
inline void fprintdecimal (std::ostream& stream, int x)
{
	fprintdecimal(stream,(long)x);
}
#endif

extern void fprinthexadecimal (std::ostream& stream, uintptr_t x);
extern void fprinthexadecimal (std::ostream& stream, intptr_t x);

#if (pointer_bitsize != long_bitsize)
inline void fprinthexadecimal (std::ostream& stream, unsigned long x)
{
	fprinthexadecimal(stream,(uintptr_t)x);
}
inline void fprinthexadecimal (std::ostream& stream, long x)
{
	fprinthexadecimal(stream,(intptr_t)x);
}
#endif

#if (pointer_bitsize != int_bitsize)
inline void fprinthexadecimal (std::ostream& stream, unsigned int x)
{
	fprinthexadecimal(stream,(uintptr_t)x);
}
inline void fprinthexadecimal (std::ostream& stream, int x)
{
	fprinthexadecimal(stream,(intptr_t)x);
}
#endif

struct cl_print_flags;
struct cl_print_number_flags;
struct cl_print_real_flags;
struct cl_print_rational_flags;
struct cl_print_float_flags;

class cl_prin_globals_init_helper
{
	static int count;
public:
	cl_prin_globals_init_helper();
	~cl_prin_globals_init_helper();
};
static cl_prin_globals_init_helper cl_prin_globals_init_helper_instance;

// Define the customary << and >> operators.

#define CL_DEFINE_PRINT_OPERATOR(_class_)  \
inline std::ostream& operator<< (std::ostream& stream, const _class_& x)	\
{									\
	fprint(stream,x);						\
	return stream;							\
}
	
}  // namespace cln

#endif /* _CL_IO_H */
