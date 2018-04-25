// User modifiable memory allocator.

#ifndef _CL_MALLOC_H
#define _CL_MALLOC_H

#include <cstdlib>

namespace cln {

#ifdef _MSC_VER
// Avoid a static initialization fiasco when static variables of GiNaC are initialized (e.g. integral::relative_integration_error)
extern void* malloc_hook (size_t size);

extern "C" void free (void* ptr);
inline void free_hook (void* ptr) {
	free(ptr);
}
#else
// Function like malloc() which returns aligned memory of size (> 0) bytes.
extern void* (*malloc_hook) (size_t size);
// Function like free() which makes available for reuse such memory.
extern void (*free_hook) (void* ptr);
#endif

}  // namespace cln

#endif /* _CL_MALLOC_H */
