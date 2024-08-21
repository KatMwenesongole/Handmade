internal u32
string_size(s8* str)       // .use on null terminated strings only!
{
    if(!str) return(0);
    u32 count = 0;
    s8 character = str[0];

    while (character != '\0') //note: returns size, including '\0'
    {
	character = str[count];
	count++;
    }
    return (count);
}

internal u8
string_digitcount(s8* str) // .number of digits in a number from a string (only for integers!)
{
    u8 count = 0;
    u8 index = 0;

    while(str[index] > '/' && str[index] < ':')
    {
	count++;
	index++;
    }
    return(count);
}
internal u8
string_digitcount(s32 n)   // .number of digits in a number from an integer
{
    u8 c = 1;
    while (n > 9)
    {
	n = n / 10;
	c++;
    }
    return(c);
}

// conversions. from to.

internal s32
string_to_integer(s8* str) // .string to signed integer
{
    s32 value = 0;
    b32 neg = false;

    if(str[0] == '-') { str++; neg = true; };
    
    u8 digit_count = string_digitcount(str);

    for(u32 current_digit = 0; current_digit < digit_count; current_digit++)
    {
	u32 digit = str[current_digit] - 48;

	if(digit)
	{
	    value += digit * powf(10, digit_count - (current_digit + 1));	    
	}
	else if(!digit && !current_digit) return(0);
    }

    if(neg) value = -value;

    return(value);
}
internal r32
string_to_real(s8* str)   // .string to real
{
    r64 value = 0; // this is a double because of some floating point precision problems we don't understand yet!
    b32 neg   = 0;

    if(str[0] == '-') { str++; neg = true; }
    
    s32 whole = string_to_integer(str);
    value += whole;

    u32 whole_count    = string_digitcount(str);
    s32 fraction_count = string_digitcount(&str[whole_count + 1]);
    
    r32 fraction = string_to_integer(&str[whole_count + 1]) * (powf(0.1f, fraction_count));
    value += fraction;

    if(neg) value = -value;

    return(value);
}
internal u32
string_to_hexadecimal(s8* str) //TODO: write the damn function
{
    return(3735928559);
}

// conversions. to from.
internal void
integer_to_string(s32 n, s8* str, s32* size)           
{
    b32 neg = (n < 0) ? true : false;

    n = abs(n);
    u32 count = string_digitcount(n);

    if(size) *size = (neg) ? (count + 2) : (count + 1);

    if (neg) { *str++ = '-'; }

    for (s8 i = count - 1; i > -1; i--)
    {
	u32 deviser = (u32)powf(10, i);
	u32 digit   = n / deviser;

	n -= deviser * digit;

	*str++ = (s8)(48 + digit);
    }
}
internal void
real_to_string   (r32 n, s8* str, s32* size, u32 sgf)
{
    b32 neg = (n < 0) ? true : false;
 
    n = calc_abs(n);

    r32 real    = (u32)n;
    u32 decimal = (u32)((n - real) * (powf(10, sgf)));

    u8 count_real    = string_digitcount((u32)real);
    u8 count_decimal = string_digitcount(decimal);

    u8 padding = sgf - count_decimal;

    if(size) *size = (neg) ? ((count_decimal + count_real + padding) + 3) : ((count_decimal + count_real + padding) + 2);

    if (neg) { *str++ = '-'; } 

    for (s8 i = count_real - 1; i > -1; i--)
    {
	u32 deviser = (u32)powf(10, i);
	u64 digit   = n / deviser;

	n -= deviser * digit;

	*str++ = (s8)(48 + digit);
    }
    *str++ = '.';

    for (u8 i = 0; i < padding; i++)
    {
	*str++ = '0';
    }

    for (s64 i = count_decimal - 1; i > -1; i--)
    {
	u32 deviser = powf(10, i);
	u32 digit   = decimal / deviser;

	decimal -= deviser * digit;

	*str++ = (s8)(48 + digit);
    }
}
internal void
hex_to_string    (u32 n, s8* str, s32* size)
{
    *size = 11;
    
    *str       = '0';
    *(str + 1) = 'x';

    str += 2;
    
    for(u32 index = 0; index < 4; index++)
    {
	u8 byte = (n >> (8 * (3 - index))); // |0|1|0|0| |1|1|0|1| |0|1|1|0| |1|1|0|0| -> |0|0|0|0| |0|1|0|0| |1|1|0|1| |0|1|1|0|

	u8 high  = (byte >> 4);
	u8 low   = ((u8)(byte << 4) >> 4);
	if(high > 9)
	{
	    //hex
	    *str++ = (s8)(65 + (high - 10));
	}
	else
	{
	    //decimal
	    *str++ = (s8)(48 + high);
	}

	if(low > 9)
	{
	    //hex
	    *str++ = (s8)(65 + (low - 10));
	}
	else
	{
	    //decimal
	    *str++ = (s8)(48 + low);
	}
    }
}

typedef s8* arg_list;
#define LIST_ADDRESS_OF(parse) (&(parse))
#define LIST_INTSIZE_OF(n)     ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define list_start(list, parse) ((void)(list = (arg_list)LIST_ADDRESS_OF(parse) + LIST_INTSIZE_OF(parse)))
#define list_arg(list, type)						\
    ((sizeof(type) > sizeof(__int64) || (sizeof(type) & (sizeof(type) - 1)) != 0) \
     ? **(type**)((list += sizeof(__int64)) - sizeof(__int64))		\
     :  *(type* )((list += sizeof(__int64)) - sizeof(__int64)))
#define list_end(list) ((void)(list = (arg_list)0))

internal u32
string_print(s8* out_str, s8* parse_str, arg_list list)
{
    u32 size   = string_size(parse_str);
    u32 offset = 0;
    
    for(u32 i = 0; i < size; i++)
    {
	s8 c_0 = *(&parse_str[i]);

	if(c_0 == '%')
	{
	    s8 c_1 = *(&parse_str[i] + 1);

	    switch(c_1)
	    {
	    case 's'://note, string
	    {
		s8* str = list_arg(list, s8*);
		s32 count = string_size(str) ? (string_size(str) - 1) :  0;

		mem_copy(str, &out_str[offset], count); //bad! bad!
		offset += count;
	    }
	    break;
	    case 'r'://note, real 
	    {
		r32 real  = list_arg(list, r64);
		s32 count = 0;
		real_to_string(real, &out_str[offset], &count, 1);
		offset += (count - 1);
	    }
	    break;
	    case 'i'://note, integer
	    {
		s32 integer = list_arg(list, s32);
		s32 count = 0;
		
		integer_to_string(integer, &out_str[offset], &count);
		offset += (count - 1);
	    }
	    break;
	    case 'h'://note, hexadecimal
	    {
		u32 hex_digit = list_arg(list, u32);
		s32 count = 0;
		
		hex_to_string(hex_digit, &out_str[offset], &count);
		offset += (count - 1);
	    }
	    break;
	    }
	    
	    i += 1;
	    
	    continue;
	}

	out_str[offset++] = c_0;
    }
    
    out_str[offset] = '\0';

    return(offset);
}
internal u32
string_print(s8* out_str, s8* parse_str, ...)
{
    arg_list list = 0;
    
    list_start(list, parse_str);
    u32 offset = string_print(out_str, parse_str, list);
    list_end(list);

    return(offset);
}


#define STRING_MAX_SIZE 256
struct string
{
    s8  s[STRING_MAX_SIZE] = {};
    s32 size = 0; // .excluding '\0'

    string () { }
    string (s8* in_str) { set(in_str); }

    void set(s8* in_str)
    {
	size = string_size(in_str)-1;
	mem_clear(s, STRING_MAX_SIZE);
	mem_copy (in_str, s, size);
    }
    void clear()
    {
	mem_clear(s, STRING_MAX_SIZE);
	size = 0;
    }
};


