// General vectors of integers.

#ifndef _CL_GV_INTEGER_H
#define _CL_GV_INTEGER_H

#include "cln/number.h"
#include "cln/GV_rational.h"
#include "cln/integer_class.h"
#include "cln/io.h"

namespace cln {

// A vector of integers is *not* just a normal vector of numbers (the vectorops
// support the maxbits() operation), but we treat can it like this nevertheless.

#ifdef HAVE_TEMPLATE_NULL
template <>
#endif
struct cl_heap_GV<cl_I> : cl_heap {
	cl_GV_inner<cl_I> v;
	// here room for the elements
	sintL maxbits () const;
};
typedef cl_heap_GV<cl_I> cl_heap_GV_I;

struct cl_GV_I : public cl_GV<cl_I,cl_GV_RA> {
public:
	// Constructors.
	cl_GV_I ();
	cl_GV_I (const cl_GV_I&);
	// Create a vector of unconstrained integers.
	explicit cl_GV_I (uintL len);
	// Create a vector of m-bit integers (>=0, <2^m).
	cl_GV_I (uintL len, sintL m);
	// Assignment operators.
	cl_GV_I& operator= (const cl_GV_I&);
	// Number m of bits allowed per element (-1 if unconstrained).
	sintL maxbits () const
	{
		return ((const cl_heap_GV_I *) pointer)->maxbits();
	}
	// Private pointer manipulations.
	cl_GV_I (cl_heap_GV_I* p) : cl_GV<cl_I,cl_GV_RA> (p) {}
	cl_GV_I (cl_private_thing p) : cl_GV<cl_I,cl_GV_RA> (p) {}
};
inline cl_GV_I::cl_GV_I (const cl_GV_I& x) : cl_GV<cl_I,cl_GV_RA> (as_cl_private_thing(x)) {}
CL_DEFINE_ASSIGNMENT_OPERATOR(cl_GV_I,cl_GV_I)
extern cl_heap_GV_I* cl_make_heap_GV_I (uintL len);
inline cl_GV_I::cl_GV_I (uintL len)
	: cl_GV<cl_I,cl_GV_RA> (cl_make_heap_GV_I(len)) {}
extern cl_heap_GV_I* cl_make_heap_GV_I (uintL len, sintL m);
inline cl_GV_I::cl_GV_I (uintL len, sintL m)
	: cl_GV<cl_I,cl_GV_RA> (cl_make_heap_GV_I(len,m)) {}

// Private pointer manipulations. Never throw away a `struct cl_heap_GV_I *'!
extern const cl_GV_I cl_null_GV_I;
inline cl_GV_I::cl_GV_I ()
	: cl_GV<cl_I,cl_GV_RA> ((cl_heap_GV_I*) cl_null_GV_I) {}
CL_REQUIRE(cl_GV_I)

// Copy a vector.
extern const cl_GV_I copy (const cl_GV_I&);

// Output.
inline void fprint (cl_ostream stream, const cl_GV_I& x)
{
	extern cl_print_flags default_print_flags;
	extern void print_vector (cl_ostream stream, const cl_print_flags& flags, void (* fun) (cl_ostream, const cl_print_flags&, const cl_number&), const cl_GV_number& vector);
	extern void print_integer (cl_ostream stream, const cl_print_flags& flags, const cl_I& z);
	print_vector(stream, default_print_flags,
	             (void (*) (cl_ostream, const cl_print_flags&, const cl_number&))
	             (void (*) (cl_ostream, const cl_print_flags&, const cl_I&))
	             &print_integer,
	             x);
}
CL_DEFINE_PRINT_OPERATOR(cl_GV_I)

// Debugging support.
#ifdef CL_DEBUG
extern int cl_GV_I_debug_module;
static void* const cl_GV_I_debug_dummy[] = { &cl_GV_I_debug_dummy,
	&cl_GV_I_debug_module
};
#endif

}  // namespace cln

#endif /* _CL_GV_INTEGER_H */