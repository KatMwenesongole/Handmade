#define PI  3.14159
#define TAU (2 * PI)
#include <math.h> //bad!

struct v4
{
    union
    {
	struct { r32 x; r32 y; r32 z; r32 w; };
	struct { r32 r; r32 g; r32 b; r32 a; };
    };
    v4 operator- ();
};
struct v3
{
    union
    {
	struct { r32 x; r32 y; r32 z; };
	struct { r32 r; r32 g; r32 b; };
    };
    v3 operator- ();
};
struct v2
{
    union
    {
	struct { r32 x; r32 y; };
	struct { r32 u; r32 v; };
    };
    v2 operator- ();
};

inline v4 vec4(r32 x, r32 y, r32 z, r32 w)
{
    v4 vec = { x, y, z, w };
    return(vec);
}
inline v3 vec3(r32 x, r32 y, r32 z)
{
    v3 vec = { x, y, z};
    return(vec);
}
inline v2 vec2(r32 x, r32 y)
{
    v2 vec = { x, y };
    return(vec);
}

// v2

inline v2  operator* (v2 vec, r32 s) {  return(vec2(vec.x*s, vec.y*s)); } // v2 * scalar
inline v2  operator* (r32 s, v2 vec) {  return(vec2(vec.x*s, vec.y*s)); } // scalar * v2

inline v2& operator*=(v2& vec, r32 s) { return(vec = vec * s); }

inline v2  operator/ (v2  vec, r32 s) { return(vec*(1.0f/s)); } // v2 / scalar
inline v2& operator/=(v2& vec, r32 s) { return(vec = vec / s); }

inline v2 operator+ (v2 a, v2 b) { return(vec2(a.x + b.x, a.y + b.y)); } // v2 + v2
inline v2 operator- (v2 a, v2 b) { return(vec2(a.x - b.x, a.y - b.y)); } // v2 - v2

inline v2& operator+=(v2& a, v2 b) { return(a = a + b); }
inline v2& operator-=(v2& a, v2 b) { return(a = a - b); }

inline v2 v2::operator- () { return(vec2(-x,-y)); }

// v3

inline v3  operator* (v3 vec, r32 s) { return(vec3(vec.x*s, vec.y*s, vec.z*s)); } // v3 * scalar
inline v3  operator* (r32 s, v3 vec) { return(vec3(vec.x*s, vec.y*s, vec.z*s)); } // scalar * v3

inline v3& operator*=(v3& vec, r32 s) { return(vec = vec * s); }

inline v3  operator/ (v3& vec, r32 s) { return(vec*(1.0f/s));   } // v3 / scalar
inline v3& operator/=(v3& vec, r32 s) { return(vec = vec / s);  }

inline v3 operator+ (v3 a, v3 b) { return(vec3(a.x + b.x, a.y + b.y, a.z + b.z)); } // v3 + v3
inline v3 operator- (v3 a, v3 b) { return(vec3(a.x - b.x, a.y - b.y, a.z - b.z)); } // v3 - v3

inline v3& operator+=(v3& a, v3 b) { return(a = a + b); }
inline v3& operator-=(v3& a, v3 b) { return(a = a - b); }

inline v3 v3::operator- () { return(vec3(-x, -y, -z)); }

// v4

inline v4  operator* (v4 vec, r32 s) { return(vec4(vec.x*s, vec.y*s, vec.z*s, vec.w*s)); } // v4 * scalar
inline v4  operator* (r32 s, v4 vec) { return(vec4(vec.x*s, vec.y*s, vec.z*s, vec.w*s)); } // scalar * v4

inline v4& operator*=(v4& vec, r32 s) { return(vec = vec * s); }

inline v4  operator/ (v4& vec, r32 s) { return(vec*(1.0f/s));   } // v4 / scalar
inline v4& operator/=(v4& vec, r32 s) { return(vec = vec / s);  }

inline v4 operator+(v4 a, v4 b) {  return(vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w)); } // v4 + v4
inline v4 operator-(v4 a, v4 b) {  return(vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w)); } // v4 - v4

inline v4& operator+=(v4& a, v4 b) { return(a = a + b); }
inline v4& operator-=(v4& a, v4 b) { return(a = a - b); }

inline v4 v4::operator- () { return(vec4(-x, -y, -z, -w)); }

// operations
                          
r32 calc_dot  (v3 a, v3 b) { return((a.x * b.x) + (a.y * b.y) + (a.z * b.z)); }
v3  calc_cross(v3 a, v3 b) { return(vec3((a.y * b.z) - (a.z * b.y), (a.z * b.x) - (a.x * b.z), (a.x * b.y) - (a.y * b.x))); }

r32 calc_length(v2 a)  { return(sqrtf( (a.x * a.x) + (a.y * a.y) ) ); }
r32 calc_length(v3 a)  { return(sqrtf( (a.x * a.x) + (a.y * a.y) + (a.z * a.z) ) ); }
r32 calc_length(v4 a)  { return(sqrtf( (a.x * a.x) + (a.y * a.y) + (a.z * a.z) + (a.w * a.w) ) ); }

v2  calc_normalise(v2 a) { return(a/calc_length(a)); }
v3  calc_normalise(v3 a) { return(a/calc_length(a)); }
v4  calc_normalise(v4 a) { return(a/calc_length(a)); }

// misc
inline r32 calc_degrees(r32 rad) { return(rad * (180.0f/PI)); }
inline r32 calc_radians(r32 deg) { return(deg * (PI/180.0f)); }

inline s32 calc_floor(r32 n) { return (s32)(n); }
inline s32 calc_ceil (r32 n) { return (s32)(n + 1); }
inline s32 calc_round(r32 n) { return (s32)(n + 0.5f); }

inline r32 calc_abs(r32 n) { return((n > 0) ? n : -n); }
inline s32 calc_abs(s32 n) { return((n > 0) ? n : -n); }

inline v2 calc_abs(v2 v) { return(vec2(calc_abs(v.x), calc_abs(v.y))); }
inline v3 calc_abs(v3 v) { return(vec3(calc_abs(v.x), calc_abs(v.y), calc_abs(v.z))); }
inline v4 calc_abs(v4 v) { return(vec4(calc_abs(v.x), calc_abs(v.y), calc_abs(v.z), calc_abs(v.w))); }

inline r32 calc_max(r32 a, r32 b) { return((a > b) ? a : b ); }
inline r32 calc_min(r32 a, r32 b) { return((a < b) ? a : b ); }

inline s32 calc_max(s32 a, s32 b) { return((a > b) ? a : b ); }
inline s32 calc_min(s32 a, s32 b) { return((a < b) ? a : b ); }

r32 calc_clamp(r32 n, r32 max, r32 min)
{
    if(n < min) { n = min; }
    if(n > max) { n = max; }
    return(n);
}
r32 calc_wrap(r32 n, r32 max, r32 min)
{
    if(n > max) { n = min + (n - max); }
    if(n < min) { n = max + (min - n); }
    return(n);
}

inline r32 calc_lerp(r32 n, r32 max, r32 min) { return ((n - min)/(max - min)); }

// note: colours

v3 calc_darken(r32 r, r32 g, r32 b, r32 factor)
{
    v3 colour = {};
    colour.r = calc_clamp(r - (r * factor), 1.0, 0.0);
    colour.g = calc_clamp(g - (g * factor), 1.0, 0.0);
    colour.b = calc_clamp(b - (b * factor), 1.0, 0.0);
    return(colour);
}
inline v3 calc_darken(v3 colour, r32 factor) // darken colour by %? (0.?)
{
    return(calc_darken(colour.r, colour.g, colour.b, factor));
}
v4 calc_darken(v4 colour, r32 factor) // darken colour by %? (0.?)
{
    colour.r = calc_clamp(colour.r - (colour.r * factor), 1.0, 0.0);
    colour.g = calc_clamp(colour.g - (colour.g * factor), 1.0, 0.0);
    colour.b = calc_clamp(colour.b - (colour.b * factor), 1.0, 0.0);
    return(colour);
}

v3 calc_brighten(v3 colour, r32 factor) // brighten colour by %? (0.?)
{
    colour.r = calc_clamp(colour.r + (colour.r * factor), 1.0, 0.0);
    colour.g = calc_clamp(colour.g + (colour.g * factor), 1.0, 0.0);
    colour.b = calc_clamp(colour.b + (colour.b * factor), 1.0, 0.0);
    return(colour);
}
v4 calc_brighten(v4 colour, r32 factor) // brighten colour by %? (0.?)
{
    colour.r = calc_clamp(colour.r + (colour.r * factor), 1.0, 0.0);
    colour.g = calc_clamp(colour.g + (colour.g * factor), 1.0, 0.0);
    colour.b = calc_clamp(colour.b + (colour.b * factor), 1.0, 0.0);
    return(colour);
}

u32 calc_argb(r32 r, r32 g, r32 b, r32 a) { return( ((u32)(a*255) << 24) | ((u32)(r*255) << 16) | ((u32)(g*255) << 8) | (u32)(b*255)); }


/* note: matrices 
   column major/column vector (in use)

   | 0  | 4  | 8  | 12 |   
   | 1  | 5  | 9  | 13 |   
   | 2  | 6  | 10 | 14 |  
   | 3  | 7  | 11 | 15 |   

   row major/row vector

   | 0  | 1  | 2  | 3  |   
   | 4  | 5  | 6  | 7  |   
   | 8  | 9  | 10 | 11 |   
   | 12 | 13 | 14 | 15 |   

   note: in memory
   0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15

   affine
   preserves the parallelism of lines, but not necessarily lengths and angles.


   an orthoganal matrix's inverse is it's transpose.

*/

struct m4
{
    r32 matrix[16] =
    {
	1.0, 0.0, 0.0, 0.0, // column [0]
	0.0, 1.0, 0.0, 0.0, // column [1]
	0.0, 0.0, 1.0, 0.0, // column [2]
	0.0, 0.0, 0.0, 1.0  // column [3]
    };
    
    r32& operator[] (u32 n)
    {
	return matrix[n];
    }
};
struct m3
{
    r32 matrix[9] =
    {
	1.0, 0.0, 0.0, // column [0]
	0.0, 1.0, 0.0, // column [1]
	0.0, 0.0, 1.0  // column [2]
    };
    
    r32& operator[] (u32 n)
    {
	return matrix[n];
    }
};

m4 operator* (m4 a, m4 b)
{
    /*
      |a b c d|   |A B C D|     |a*A + b*E + c*I + d*M  a*B + b*F + c*J + d*N  a*C + b*G + c*K + d*O  a*D + b*H + c*L + d*P|   |a' b' c' d'|
      |e f g h| * |E F G H|  =  |e*A + f*E + g*I + h*M  e*B + f*F + g*J + h*N  e*C + f*G + g*K + h*O  e*D + f*H + g*L + h*P| = |b' f' g' h'|
      |i j k l|   |I J K L|     |i*A + j*E + k*I + l*M  i*B + j*F + k*J + l*N  i*C + j*G + k*K + l*O  i*D + j*H + k*L + l*P|   |i' j' k' l'|
      |m n o p|   |M N O P|     |m*A + n*E + o*I + p*M  m*B + n*F + o*J + p*N  m*C + n*G + o*K + p*O  m*D + n*H + o*L + p*P|   |m' n' o' p'|
    */
    m4 m;
    m[0] = (a[0] * b[0]) + (a[4] * b[1]) + (a[8]  * b[2]) + (a[12] * b[3]);
    m[1] = (a[1] * b[0]) + (a[5] * b[1]) + (a[9]  * b[2]) + (a[13] * b[3]);
    m[2] = (a[2] * b[0]) + (a[6] * b[1]) + (a[10] * b[2]) + (a[14] * b[3]);
    m[3] = (a[3] * b[0]) + (a[7] * b[1]) + (a[11] * b[2]) + (a[15] * b[3]);

    m[4] = (a[0] * b[4]) + (a[4] * b[5]) + (a[8]  * b[6]) + (a[12] * b[7]);
    m[5] = (a[1] * b[4]) + (a[5] * b[5]) + (a[9]  * b[6]) + (a[13] * b[7]);
    m[6] = (a[2] * b[4]) + (a[6] * b[5]) + (a[10] * b[6]) + (a[14] * b[7]);
    m[7] = (a[3] * b[4]) + (a[7] * b[5]) + (a[11] * b[6]) + (a[15] * b[7]);

    m[8]  = (a[0] * b[8]) + (a[4] * b[9]) + (a[8]  * b[10]) + (a[12] * b[11]);
    m[9]  = (a[1] * b[8]) + (a[5] * b[9]) + (a[9]  * b[10]) + (a[13] * b[11]);
    m[10] = (a[2] * b[8]) + (a[6] * b[9]) + (a[10] * b[10]) + (a[14] * b[11]);
    m[11] = (a[3] * b[8]) + (a[7] * b[9]) + (a[11] * b[10]) + (a[15] * b[11]);

    m[12] = (a[0] * b[12]) + (a[4] * b[13]) + (a[8]  * b[14]) + (a[12] * b[15]);
    m[13] = (a[1] * b[12]) + (a[5] * b[13]) + (a[9]  * b[14]) + (a[13] * b[15]);
    m[14] = (a[2] * b[12]) + (a[6] * b[13]) + (a[10] * b[14]) + (a[14] * b[15]);
    m[15] = (a[3] * b[12]) + (a[7] * b[13]) + (a[11] * b[14]) + (a[15] * b[15]);
    return(m);
}
m3 operator* (m3 a, m3 b)
{
    /*
      |a b c|   |A B C|     |a*A + b*D + c*G  a*B + b*E + c*H  a*C + b*F + c*I|   |a' b' c'|
      |d e f| * |D E F|  =  |d*A + e*D + f*G  d*B + e*E + f*H  d*C + e*F + f*I| = |d' e' f'|
      |g h i|   |G H I|     |g*A + h*D + i*G  g*B + h*E + i*H  g*C + h*F + i*I|   |g' h' i'|
    */
    m3 m;
    m[0] = (a[0] * b[0]) + (a[3] * b[1]) + (a[6] * b[2]);
    m[1] = (a[1] * b[0]) + (a[4] * b[1]) + (a[7] * b[2]);
    m[2] = (a[2] * b[0]) + (a[5] * b[1]) + (a[8] * b[2]);

    m[3] = (a[0] * b[3]) + (a[3] * b[4]) + (a[6] * b[5]);
    m[4] = (a[1] * b[3]) + (a[4] * b[4]) + (a[7] * b[5]);
    m[5] = (a[2] * b[3]) + (a[5] * b[4]) + (a[8] * b[5]);

    m[6] = (a[0] * b[6]) + (a[3] * b[7]) + (a[6] * b[8]);
    m[7] = (a[1] * b[6]) + (a[4] * b[7]) + (a[7] * b[8]);
    m[8] = (a[2] * b[6]) + (a[5] * b[7]) + (a[8] * b[8]);
    return(m);
}

m4 operator* (m4 m, r32 s)
{
    m[0] *= s;
    m[1] *= s;
    m[2] *= s;
    m[3] *= s;

    m[4] *= s;
    m[5] *= s;
    m[6] *= s;
    m[7] *= s;

    m[8]  *= s;
    m[9]  *= s;
    m[10] *= s;
    m[11] *= s;

    m[12] *= s;
    m[13] *= s;
    m[14] *= s;
    m[15] *= s;

    return(m);
}
m3 operator* (m3 m, r32 s)
{
    m[0] *= s;
    m[1] *= s;
    m[2] *= s;

    m[3] *= s;
    m[4] *= s;
    m[5] *= s;

    m[6] *= s;
    m[7] *= s;
    m[8] *= s;

    return(m);
}

v4 operator* (m4 m, v4 v)
{
    /*
      |a b c d|   |x|     |a*x + b*y + c*z + d*w|   |x'|
      |e f g h| * |y|  =  |e*x + f*y + g*z + h*w| = |y'|
      |i j k l|   |z|     |i*x + j*y + k*z + l*w|   |z'|
      |m n o p|   |w|     |m*x + n*y + o*z + p*w|   |w'|
    */
    
    v4 result;
    result.x = (m[0] * v.x) + (m[4] * v.y) + (m[8]  * v.z) + (m[12] * v.w);
    result.y = (m[1] * v.x) + (m[5] * v.y) + (m[9]  * v.z) + (m[13] * v.w);
    result.z = (m[2] * v.x) + (m[6] * v.y) + (m[10] * v.z) + (m[14] * v.w);
    result.w = (m[3] * v.x) + (m[7] * v.y) + (m[11] * v.z) + (m[15] * v.w);
    return(result);
}
v3 operator* (m3 m, v3 v)
{
    /*
      |a b c|   |x|     |a*x + b*y + c*z|   |x'|
      |d e f| * |y|  =  |d*x + e*y + f*z| = |y'|
      |g h i|   |z|     |g*x + h*y + i*z|   |z'|
    */
    v3 result;
    result.x = (m[0] * v.x) + (m[3] * v.y) + (m[6] * v.z);
    result.y = (m[1] * v.x) + (m[4] * v.y) + (m[7] * v.z);
    result.z = (m[2] * v.x) + (m[5] * v.y) + (m[8] * v.z);
    return(result);
}

// matrices //
m4 calc_transpose(m4 m_0)
{
    /*
      M                      M(t)
      | 0 | 4 |  8 | 12 |    | 0  | 1  | 2  | 3  |
      | 1 | 5 |  9 | 13 |    | 4  | 5  | 6  | 7  |
      | 2 | 6 | 10 | 14 |    | 8  | 9  | 10 | 11 |
      | 3 | 7 | 11 | 15 |    | 12 | 13 | 14 | 15 |

      each row becomes the others coloumn
    */
    m4 m;
    m[0] = m_0[0];  m[4] = m_0[1];  m[8]  = m_0[2];  m[12] = m_0[3];
    m[1] = m_0[4];  m[5] = m_0[5];  m[9]  = m_0[6];  m[13] = m_0[7];
    m[2] = m_0[8];  m[6] = m_0[9];  m[10] = m_0[10]; m[14] = m_0[11];
    m[3] = m_0[12]; m[7] = m_0[13]; m[11] = m_0[14]; m[15] = m_0[15];
    return(m);
}

r32 calc_determinant(m3 m)
{
    /* note: calculating the determinant of a 3x3 matrix
       | a  b  c |
       | d  e  f |  = ((a * e * i) + (b * f * g) + (d * h * c))  -  ((c * e * g) - (b * d * i) - (f * h * a))
       | g  h  i |  =   a((e * i) - (f * h)) + b((f * g) - (d * i)) + c((d * h) - (e * g))
    */
    return(m[0]*((m[4]*m[8]) - (m[7]*m[5])) + m[3]*((m[7]*m[2]) - (m[1]*m[8])) + m[6]*((m[1]*m[5]) - (m[4]*m[2])));
}
r32 calc_minor(m4 m, u32 row, u32 colomn)
{
    /* note: minor
       delete any row and colomn you want from a matrix, the minor is the determinant of the remaining matrix 

       M                                   M{12}
       | a  b  c  d |    | ~  ~  ~  ~ |    | e  g  h |     
       | e  f  g  h |    | e  ~  g  h |    | i  k  l | = e((k * p) - (l * o)) + g((l * m) - (i * p)) + h((i * o) - (k * m))
       | i  j  k  l |    | i  ~  k  l |    | m  o  p |
       | m  n  o  p |    | m  ~  o  p |
    */
    
    m3 minor;

    u32 minor_entry = 0;
    for(s32 e = 0; e < 16; e++)
    {
	u32 m_row    = e%4;
	u32 m_colomn = e/4;

	if(m_row == row || m_colomn == colomn) continue;

	minor[minor_entry++] = m[e];
    }
    
    return(calc_determinant(minor));
}
r32 calc_cofactor(m4 m, u32 row, u32 colomn)
{
    /* note: cofactor
       C{ij} = (-1)^i+j * M{ij}
       same as the minor of corresponding row and colomn, may be negated depending on it's location in matrix
   
       M                       M{12}
       | 0  | 4  | 7  | 9  |   | 10 | 5  | 8  |
       | 10 | 1  | 5  | 8  |   | 13 | 2  | 6  | =  10((2 * 3) - (6 * 12)) + 5((6 * 15) - (13 * 3)) + 8((13 * 12) - (2 * 15))
       | 13 | 11 | 2  | 6  |   | 15 | 12 | 3  | =  10(6 - 72)             + 5(90 - 39)             + 8(156 - 30)
       | 15 | 14 | 12 | 3  |                    =  10(-66)                + 5(51)                  + 8(126)
       = -660                    + 255                    + 1008
       =  603 (minor)
       C{12} = (-1)^1+2 * 603
       = (-1)^3         * 603
       = (-1 * -1 * -1) * 603
       = -1             * 603
       = -603 (cofactor)   
    */
    r32 minor = calc_minor(m, row, colomn);
    return(powf(-1, (row+1)+(colomn+1)) * minor);
}
r32 calc_determinant(m4 m)
{
    /*
      calculating the determinant of a 4x4 matrix (or any n x n matrix)
      |M| = (n sum j = 1) mij * C{ij}
      any row or colomn is picked, each element is multiplied with it's corresponding cofactor, sum
    
      | a  b  c  d |      M{11}
      | e  f  g  h |      | f  g  h | = f((k * p) - (l * o)) + g((l * n) - (j * p)) + h((j * o) - (k * n))
      | i  j  k  l |      | j  k  l |
      | m  n  o  p |      | n  o  p |
  
      C{11} = (-1)^2 * M{11}
      =  M{11}

      M{12}
      | e  g  h | = e((k * p) - (l * o)) + g((l * m) - (i * p)) + h((i * o) - (k * m))
      | i  k  l |
      | m  o  p |

      C{12} = (-1)^3 * M{12}
      =  -M{12}

      M{13}
      | e  f  h | = e((j * p) - (l * n)) + f((l * m) - (i * p)) + h((i * n) - (j * m))
      | i  j  l |
      | m  n  p |

      C{13} = (-1)^4 * M{13}
      =  M{13}

      M{14}
      | e  f  g | = e((j * o) - (k * n)) + f((k * m) - (i * o)) + g((i * n) - (j * m))
      | i  j  k |
      | m  n  o |

      C{14} = (-1)^5 * M{14}
      = -M{14}

      |M| = (a * C{11}) + (b * C{12}) + (c * C{13}) + (d * C{14})

    */
    
    r32 cofactor_00 = calc_cofactor(m, 0, 0);
    r32 cofactor_01 = calc_cofactor(m, 0, 1);
    r32 cofactor_02 = calc_cofactor(m, 0, 2);
    r32 cofactor_03 = calc_cofactor(m, 0, 3);

    return((m[0]*cofactor_00) + (m[4]*cofactor_01) + (m[8]*cofactor_02) + (m[12]*cofactor_03));
}

m4 calc_inverse(m4 m)
{
    m4 adj_m;

    adj_m[0] = calc_cofactor(m, 0,0);
    adj_m[1] = calc_cofactor(m, 1,0);
    adj_m[2] = calc_cofactor(m, 2,0);
    adj_m[3] = calc_cofactor(m, 3,0);

    adj_m[4] = calc_cofactor(m, 0,1);
    adj_m[5] = calc_cofactor(m, 1,1);
    adj_m[6] = calc_cofactor(m, 2,1);
    adj_m[7] = calc_cofactor(m, 3,1);

    adj_m[8]  = calc_cofactor(m, 0,2);
    adj_m[9]  = calc_cofactor(m, 1,2);
    adj_m[10] = calc_cofactor(m, 2,2);
    adj_m[11] = calc_cofactor(m, 3,2);

    adj_m[12] = calc_cofactor(m, 0,3);
    adj_m[13] = calc_cofactor(m, 1,3);
    adj_m[14] = calc_cofactor(m, 2,3);
    adj_m[15] = calc_cofactor(m, 3,3);

    adj_m = calc_transpose(adj_m);
    
    r32 det_m = calc_determinant(m);
    
    return(adj_m * (1.0/det_m));
    
    /*
      classical adjoint
      every element in the matrix replaced with it's corresponding cofactor, the matrix of cofactors is then transposed
        
      M                                                    adj M
      | a  b  c  d |     | C{11}  C{12}  C{13}  C{14} |     | C{11}  C{21}  C{31}  C{41} |
      | e  f  g  h |  =  | C{21}  C{22}  C{23}  C{24} |  =  | C{12}  C{22}  C{32}  C{42} |
      | i  j  k  l |     | C{31}  C{32}  C{33}  C{34} |     | C{13}  C{23}  C{33}  C{43} |
      | m  n  o  p |     | C{41}  C{42}  C{43}  C{44} |     | C{14}  C{24}  C{34}  C{44} | 

      ------------------------------------------------------------------------------------------------------------------

      inverse: classical adjoint method                           
      M^-1 = adj M / |M|

      *note: in order to divide matrix by a scalar we use the reciprocal of the value
      
      M-1 =  | C{11}  C{21}  C{31}  C{41} |
      | C{12}  C{22}  C{32}  C{42} |  *  1 / |M|
      | C{13}  C{23}  C{33}  C{43} |
      | C{14}  C{24}  C{34}  C{44} | 

      =  | C{11} * 1/|M|   C{21} * 1/|M|   C{31} * 1/|M|   C{41} * 1/|M||
      | C{12} * 1/|M|   C{22} * 1/|M|   C{32} * 1/|M|   C{42} * 1/|M||  
      | C{13} * 1/|M|   C{23} * 1/|M|   C{33} * 1/|M|   C{43} * 1/|M||
      | C{14} * 1/|M|   C{24} * 1/|M|   C{34} * 1/|M|   C{44} * 1/|M|| 
    */
}


/* left handed coordinate system (in use)
   . x-axis (1,0,0) 
   . y-axis (0,1,0)
   . z-axis (0,0,1)
*/

// matrices: model
m4 calc_translate(v3 position)
{
    /*
      T
      | 1 | 0 | 0 | position.x |    
      | 0 | 1 | 0 | position.y |    
      | 0 | 0 | 1 | position.z |    
      | 0 | 0 | 0 |      1     |    
    */
    m4 m;
    m[12] = position.x;
    m[13] = position.y;
    m[14] = position.z;
    return(m);
    
}
m4 calc_rotate_x(r32 rad) 
{
    /* note:  R(x)  = rotate _about_ the x-axis. (clockwise)
 
       note: imagine a cube with a red line, x-axis,
       cutting through the centre from left to right.
       how would it teeter?
	 
       x   y     z
       | 1   0     0   0 |   
       | 0  cos  -sin  0 |  
       | 0  sin   cos  0 | 
       | 0   0     0   1 | */
    m4 m;
    m[5]  = cosf(rad);
    m[6]  = sinf(rad);
    m[9]  = -sinf(rad);
    m[10] =  cosf(rad);
    return(m);
}
m4 calc_rotate_y(r32 rad)
{
    /* note:  R(y)  = rotate _about_ the y-axis. (clockwise)

       x    y    z
       |  cos   0  sin  0 |   
       |   0    1   0   0 |  
       | -sin   0  cos  0 | 
       |   0    0   0   1 | */
    
    m4 m;
    m[0]  =  cosf(rad);
    m[2]  = -sinf(rad);
    m[8]  =  sinf(rad);
    m[10] =  cosf(rad);
    return(m);
}
m4 calc_rotate_z(r32 rad)
{
    /* note:  R(z)  = rotate _about_ the z-axis. (clockwise)
 
       x    y   z
       |  cos  sin  0  0 |   
       | -sin  cos  0  0 |  
       |   0    0   1  0 | 
       |   0    0   0  1 | */
    m4 m;
    m[0] =  cosf(rad);
    m[1] = -sinf(rad);
    m[4] =  sinf(rad);
    m[5] =  cosf(rad);
    return(m);
}
m4 calc_scale(v3 scale)
{
    /*
      S
      | scale.x |    0    |    0    | 0 |    
      |    0    | scale.y |    0    | 0 |    
      |    0    |    0    | scale.z | 0 |    
      |    0    |    0    |    0    | 1 |    
    */
    m4 m;
    m[0]  = scale.x;
    m[5]  = scale.y;
    m[10] = scale.z;
    return(m);
}

m4 calc_model_world (v3 position, v3 rotation, v3 scale)
{
    /*
      TRS = Translate * Rotate * Scale
    */
    m4 m = calc_scale(scale)  *
    calc_rotate_z(rotation.z) *
    calc_rotate_y(rotation.y) *
    calc_rotate_x(rotation.x) *
    calc_translate(position);
    return(m);
}

// matrices: camera / view
// 
// the camera matrix moves the camera to the origin. the camera is simply a convient concept; it does not exist.
// we move the objects in the scene in relation to the 'camera'.
//
// e.g an object (in this case, a camera) is at (5, 3, 2) in the world.
//
//     | 1 0 0 5 |
//     | 0 1 0 3 |
//     | 0 0 1 2 |
//     | 0 0 0 1 |
//
//    the camera is moved to the origin (0, 0, 0). it has been translated (0 - 5, 0 - 3, 0 - 2) -> (-5, -3, -2).
//    the objects in the scene move in relation to the 'camera'. they all must translated (-5, -3, -2).
//
//    | 1 0 0 -(5) |
//    | 0 1 0 -(3) |
//    | 0 0 1 -(2) |
//    | 0 0 0   1  |
//
//   this is the camera matrix. as you can see the camera matrix is the inverse of the camera's model matrix.
// 
//
m4 calc_view(r32 rad, v3 right, v3 up, v3 forward, v3 position)
{
    /*
      |  right.x   up.x   forward.z   -position.x |
      |  right.y   up.y   forward.z   -position.y |
      |  right.z   up.z   forward.z   -position.z |
      |    0        0        0             1      | 
    */
   
    m4 mat = {};
    mat[0]  = right.x;
    mat[1]  = right.y;
    mat[2]  = right.z;
    
    mat[4]  = up.x;
    mat[5]  = up.y;
    mat[6]  = up.z;
    
    mat[8]  = forward.x;
    mat[9]  = forward.y;
    mat[10] = forward.z;

    mat[12] = -position.x;
    mat[13] = -position.y;
    mat[14] = -position.z;

    mat = mat * calc_rotate_y(rad);

    return(mat);
}
m4 calc_camera(v3 camera_position, v3 camera_up, v3 camera_aim)
{
    /*
      x  | cam x-axis (x) cam x-axis (y) cam x-axis (z) -dot(cam x-axis, camera_position) |
      y  | cam y-axis (x) cam y-axis (y) cam y-axis (z) -dot(cam y-axis, camera_position) |
      z  | cam z-axis (x) cam z-axis (y) cam z-axis (z) -dot(cam z-axis, camera_position) |
      |       0                   0       0                       1                    |
    */
    v3 cam_zaxis = calc_normalise(camera_aim - camera_position);
    v3 cam_xaxis = calc_normalise(calc_cross(camera_up, cam_zaxis));
    v3 cam_yaxis = calc_cross(cam_zaxis, cam_xaxis);
    
    m4 m;
    m[0] = cam_xaxis.x;
    m[4] = cam_xaxis.y;
    m[8] = cam_xaxis.z;
    
    m[1] = cam_yaxis.x;
    m[5] = cam_yaxis.y;
    m[9] = cam_yaxis.z;
    
    m[2]  = cam_zaxis.x;
    m[6]  = cam_zaxis.y;
    m[10] = cam_zaxis.z;
    
    m[12] = -calc_dot(cam_xaxis, camera_position);
    m[13] = -calc_dot(cam_yaxis, camera_position);
    m[14] = -calc_dot(cam_zaxis, camera_position);
    return(m);
}
m4 calc_camera(v3 camera_position,
	       v3 camera_right,
	       v3 camera_up,
	       v3 camera_forward,
              m4 m)
{

    /*
    m4 m;
    m[0] = camera_right.x;
    m[1] = camera_right.y;
    m[2] = camera_right.z;

    m[4] = camera_up.x;
    m[5] = camera_up.y;
    m[6] = camera_up.z;

    m[8]  = camera_forward.x;
    m[9]  = camera_forward.y;
    m[10] = camera_forward.z;

    m[12] = camera_position.x;
    m[13] = camera_position.y;
    m[14] = camera_position.z;
    */

    return(calc_inverse(m));
}

m4 calc_view(r32 deg, v3 position)
{
    m4 rotation = calc_rotate_y(calc_radians(deg));
	
    m4 m;
    m[12] = -position.x;
    m[13] = -position.y;
    m[14] = -position.z;

    return(m * rotation);
}

// matrices: projection
m4 calc_perspective(r32 near_plane, r32 far_plane, r32 fov, r32 aspect_ratio)
{
    /*
      1. point in camera/view space is projected onto the image plane/near plane
      P.x' = near * (P.x / P.z)
      P.y' = near * (P.y / P.z)
      *in real life we do this last... (perspective divide, see 5.)

      2. point converted to ndc co-ordinates [-1, 1]
      P.x' = 2P.x /(right - left) - left + right /(right - left)
      P.y' = 2P.y /(top - bottom) - bottom + top /(top - bottom)

      3. point adjusted by field of view
      P.x' = ( P.x * 1/tan(fov/2) ) * near
      P.y' = ( P.y * 1/tan(fov/2) ) * near

      now this is the best case senario, however we use matrices, and if you take a look at our matrix, there's
      no mention of FOV, why is that?

      the point is adjusted implicitly through the values passed for [top, bottom, right, left]
      we calculate them with the FOV in mind.

      we know that:
      tan(angle)   = opposite / adjacent
      tan(angle/2) = BC / AB 
      (imagine a right angle triangle, 
      'A' being the camera/eye, 'B' being the on the image plane, 'C' being the top of image plane)

      BC is the distance from the origin to the top, so we can say BC = top
      AB is the distance from the eye/camera (which is at the origin) to the near plane/image plane, so we can say AB = near
      therefore...
      tan(angle/2)        = top / near
      tan(angle/2) * near = top

      bottom = -top (self explanitory)

      just know that...
      aspect ratio = width / height
      right = top    * aspect ratio
      left  = bottom * aspect ratio

      4. normalising the z-coordinate [-1, 1]
      P.z' =  P.z * ( far + near / (far - near)  - (2 * far * near) / (far - near) )
	 
      you won't get a value between -1 & 1 when inserting values into this equation because it assumes that the perspective divide
      will happen after this step, meaning if your you had a z value that was 12 and the far plane was 12 when plugging 12 into this 
      equation you will get... 12, but then when the perspective divide happens 12/12 = 1, you'd get -1 if you'd plugged in a z value
      that was the same as the near plane

      5. the strange 'one' located at [11]
      it's purpose it to 'copy' over the z value into the w co-ordinate, basically linear algebra..., the 4D vector (x,y,z,w) converted to 3D vector
      is (x/w, y/w, z/w) there is of course (w/w but that is obviously 1) 
      this property is actually quite nice because of the perspective divide, we can just put the z value in the w place and get a 'free' divide

      | 2*near / (right-left) |          0            | right+left / (right-left) |             0              |
      |          0            | 2*near / (top-bottom) | top+bottom / (top-bottom) |             0              |
      |          0            |          0            | far+near   / (far-near)   | -(2*far*near) / (far-near) |
      |          0            |          0            |            1              |             0              |
    */
      
    r32 top    = tanf(calc_radians(fov/(r32)2)) * near_plane;
    r32 bottom = -top;

    r32 right = top    * aspect_ratio;
    r32 left  = bottom * aspect_ratio;

    m4 m  = {};
    m[0]  = (2 * near_plane) / (right - left);
    m[5]  = (2 * near_plane) / (top - bottom);
    m[8]  = (right + left) / (right - left);
    m[9]  = (top + bottom) / (top - bottom);
    m[10] = (far_plane + near_plane)/(far_plane - near_plane);
    m[11] = 1;
    m[14] = -(2 * far_plane * near_plane)/(far_plane - near_plane);
    m[15] = 0;
    return(m);
}
m4 calc_orthographic(r32 near_plane, r32 far_plane, r32 height, r32 aspect_ratio)
{
    /*
      we are attempting to parallel project points to the screen (no fov adjustment)

      1. normalising the x, y (identical to perspective projection)
      P.x' = 
      P.y' = 

      2. normalising the z
      with the perspective projection matrix, the z normalisation never 'fully' took place 
      until the z-divide (refer to perspective notes)

      in the case of orthographic projection there will be no z-divide 
      (since it is the z-divide that creates the illusion of depth)

      we therefore can't use the same equation as before, our new equation has to be similar to the 
      x, y equations

      P.z' =

      3. inspecting z values
      if you took the time to create a 'play-play' set of vertices and multiply them by this orthographic
      matrix you would see that all the z-values of the vertices are the same.
      ...

      | 2 / (right - left) |          0         |         0        | (right + left) / (right - left) |
      |         0          | 2 / (top - bottom) |         0        | (top + bottom) / (top - bottom) |
      |         0          |          0         | 2 / (far - near) |  -(far + near) / (far - near)   |
      |         0          |          0         |         0        |                1                |
          
    */
    r32 top    =  height;
    r32 bottom = -height;

    r32 right = top    * aspect_ratio;
    r32 left  = bottom * aspect_ratio;

    m4 m;
    m[0]  = 2.0 / (right - left);
    m[5]  = 2.0 / (top - bottom);
    m[10] = 2.0 / (far_plane - near_plane);
    m[12] = (right + left) / (right - left);
    m[13] = (top + bottom) / (top - bottom);
    m[14] = -(far_plane + near_plane) / (far_plane - near_plane);
    return(m);
}

