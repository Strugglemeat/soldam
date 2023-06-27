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
	int myNumBitSwap[3];

	for(int i=0x0;i<=0xFFFF;i++)
	{
		printf("[%04X]",i);

		myNumBitSwap[0]=BITSWAP16(i,0xd,0xe,0xf,0x0,0x1,0x8,0x9,0xa,0xb,0xc,0x5,0x6,0x7,0x2,0x3,0x4);
		myNumBitSwap[1]=BITSWAP16(i,0xf,0xd,0xb,0x9,0x7,0x5,0x3,0x1,0xe,0xc,0xa,0x8,0x6,0x4,0x2,0x0);
		myNumBitSwap[2]=BITSWAP16(i,0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0xb,0xa,0x9,0x8,0xf,0xe,0xd,0xc);

		for(int j=0;j<3;j++)printf(" %04X ",myNumBitSwap[j]);

		printf("\n");
	}
	return 0;
}