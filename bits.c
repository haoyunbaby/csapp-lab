/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~((~((~x)&y))&(~((~y)&x)));
  //the same as use nand gate to make xor gate
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return (1<<31);//return (~0)<<31;
  //just need a single 1 as the most significant bit and mask with 0
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  return (!((x+1)^(~x)))&(!!((x+1)|0));
  //test 2 property
  //1: Tmax+1 is identical with ~Tmax
  //2: as -1 has the same property 1, we also need make sure x+1 != 0
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
	x=x&(x>>16);
	x=x&(x>>8);
	x=x&(x>>4);
	x=x&(x>>2);
	x=(x>>1)&1;
  return x;
  //divide and conquer
  //every time x&the higher half of x examines the odd-numbered bits
  //finaly get the "1" position number by x>>1&0x1
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ((~x)+1);
  //method 1: formula
  //method 2: ~x+x is all 1, in other words, interpreted as -1
  //so ~x+x+1=0 ie negate x = ~x+1
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  return (!((x>>4)^0x3))&((!(((x>>1)&0x7)^0x4))|(!((x>>3)&0x1)));
  //first examine 3
  //second examine not over 9
  //if the hex starts with 100
  //or starts with 0
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  x=(!!x)<<31>>31;
	y&=x;
	z&=(~x);
  return y+z;
  //mask x with 1 or 0
  //if 1 reserve y and desert z and vice versa
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	int mx=(x>>31)&0x1;
	int my=(y>>31)&0x1;
	int md=((x+(~y)+1)>>31)&0x1;
  return (md&(!(mx^my)))|((mx^my)&mx)|(!(x^y));
  //fisrt x<y:
  //if not overflow x-y<0 most significant position of difference is 1
  //overflow situation: most significant of x and y are different and mx==1
  //second x==y
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
	x=x|x>>16;
	x=x|x>>8;
	x=x|x>>4;
	x=x|x>>2;
	x=(x|x>>1)&0x1;
  return x^0x1;	
  //divide and conquer
  //examine whether there is 1 in x
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
	int i,j,k,l,m,n;
	int ans;
	int sign=x>>31;
	x=((~x)&sign)+(x&(~sign));
	i = ((!!(x>>16))<<4);
	x=x>>i;
	j = ((!!(x>>8))<<3);
	x=x>>j;
	k = ((!!(x>>4))<<2);
	x=x>>k;
	l = ((!!(x>>2))<<1);
	x=x>>l;
	m = (!!(x>>1));
	x=x>>m;
	n=x&0x1;
	ans=i+j+k+l+m+n+1;
  return ans;
  //as ~x and x need same amount of bits
  //so if x<0 x=~x
  //then examine whether there is 1 in x as logicalNeg did
  //if upper part has 1 then desert lower part and examine more precisely
  //if not check for lower part more precisely
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
	unsigned int e = (uf>>23)&0xff;
	unsigned int f = uf&0x7fffff;
	unsigned int s = (uf>>31&0x1);
	unsigned int ans;
	if(!e)
	{
		unsigned int firstf = (uf>>22)&0x1;
		if(firstf)
		{
			e++;
			f=(f<<1)&0x7fffff;
		}
		else
		f=f<<1;
		e<<=23;
		s=s<<31;
		ans=s+e+f;
	}
	else if(e==0xff) ans=uf;
	else
	{
		e++;
		e=e<<23;
		s=s<<31;
		ans=s+e+f;
	}	
  return ans;
  //first of all split s, e and f
  //if denormalized value
  //  if f starts with 1
  //    becomes normalized value
  //  else f<<1
  //if normalized value
  //  e++
  //if others return argument
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
	unsigned int e = (uf>>23)&0xff;
	unsigned int f = uf&0x7fffff;
	unsigned int s = (uf>>31&0x1);
	unsigned int ans;
	if((!e)||e<0x7f) ans=0;
	else if(e==0xff||e>0x87) ans=0x80000000u;
	else
	{
		e=e-0x7f;
		f=0x800000+f;
		ans=f<<e>>23;
		ans=s?(-ans):ans;
	}
	return ans;
  //first of all split s, e and f
  //if e too small or denormalized value return 0
  //if e nan or infinity or too large return 0x80000000u
  //then use formula ans=(-1)^s*2^(e-bias)^1.f
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
	unsigned int ans;
	if(x<-149) ans=0;
	else if(x>127)ans=0x7f800000;
	else
	{
		if(x>=-126) ans=((x+127)&0xff)<<23;
		else ans=(1<<(x+149));
	}
  return ans;
  //if x too big or too small return 0 or +INF seperately
  //if normalized value f=0
  //if denormalized value find where 1 is
}
