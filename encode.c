#include <stdio.h>

int BITSWAP16(int n, 														
				  int bit15, int bit14, int bit13, int bit12, int bit11, int bit10, int bit09, int bit08,	
				  int bit07, int bit06, int bit05, int bit04, int bit03, int bit02,int  bit01,int  bit00)
{

	int m=
		(((((n) >> (bit15)) & 1) << 15) | 									
		 ((((n) >> (bit14)) & 1) << 14) | 									
		 ((((n) >> (bit13)) & 1) << 13) | 									
		 ((((n) >> (bit12)) & 1) << 12) | 									
		 ((((n) >> (bit11)) & 1) << 11) | 									
		 ((((n) >> (bit10)) & 1) << 10) | 									
		 ((((n) >> (bit09)) & 1) <<  9) | 									
		 ((((n) >> (bit08)) & 1) <<  8) | 									
		 ((((n) >> (bit07)) & 1) <<  7) | 									
		 ((((n) >> (bit06)) & 1) <<  6) | 									
		 ((((n) >> (bit05)) & 1) <<  5) | 									
		 ((((n) >> (bit04)) & 1) <<  4) | 									
		 ((((n) >> (bit03)) & 1) <<  3) | 									
		 ((((n) >> (bit02)) & 1) <<  2) | 									
		 ((((n) >> (bit01)) & 1) <<  1) | 									
		 ((((n) >> (bit00)) & 1) <<  0));

	return m;
}

int main (int argc, char** argv[])
{
	int myNum;

	printf("word: ");

	scanf("%X", &myNum);

	myNum  = ( ( myNum & 0xFF ) << 8 ) | ( ( myNum >> 8 ) & 0xFF );

	int myNumBitSwap[3];

//encode with inverted and reversed order
	myNumBitSwap[0]=BITSWAP16(myNum,0xb,0xc,0xd,0x8,0x9,0xa,0x3,0x4,0x5,0x6,0x7,0xe,0xf,0x0,0x1,0x2);
	myNumBitSwap[1]=BITSWAP16(myNum,0xf,0xd,0xb,0x9,0x7,0x5,0x3,0x1,0xe,0xc,0xa,0x8,0x6,0x4,0x2,0x0);
	myNumBitSwap[2]=BITSWAP16(myNum,0x3,0x2,0x1,0x0,0x7,0x6,0x5,0x4,0x8,0x9,0xa,0xb,0xc,0xd,0xe,0xf);

	for(int i=0;i<3;i++)
	{
		myNumBitSwap[i]=( ( myNumBitSwap[i] & 0xFF ) << 8 ) | ( ( myNumBitSwap[i] >> 8 ) & 0xFF );

		printf("bitswap %d: %04X\n", i,myNumBitSwap[i]);
	}

	return 0;
}