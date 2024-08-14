#define ASSERT(expression) if(!(expression)) { *(s32*)0 = 0; }

#define kilobytes(value) (((s64)value)          * 1024LL)
#define megabytes(value) (kilobytes((s64)value) * 1024LL)
#define gigabytes(value) (megabytes((s64)value) * 1024LL)
#define terabytes(value) (gigabytes((s64)value) * 1024LL)

#define seconds(value)   ((value) * 1000)

#define internal static
#define global   static
#define local    static

typedef unsigned char       u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef char       s8;
typedef short     s16;
typedef int       b32;
typedef int       s32;
typedef long long s64;
typedef float     r32;
typedef double    r64;

struct string;

internal inline void COPY_MEM(void* source, void* destination, s32 size);
internal inline void CLEAR_MEM(void* source, s32 size);
