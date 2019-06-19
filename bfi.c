#include <stdio.h>
#include <stdlib.h>
#include "config.h"

int  p, r;
char a[TAPE_LEN], f[TAPE_LEN], b, o, *s=f;

void interpret(char *c)
{
	char *d;
	r++;
	while(*c) {
		switch(o = 1, *c++) {
		case '<': p--;                              break;
		case '>': p++;                              break;
		case '+': a[p]++;                           break;
		case '-': a[p]--;                           break;
		case '.': putchar(a[p]);    fflush(stdout); break;
		case ',': a[p] = getchar(); fflush(stdout); break;
		case '[':
			for( b=1,d=c; b && *c; c++ )
				b += *c == '[', b -= *c == ']';
			if(!b) {
				c[-1] = 0;
				while(a[p]) interpret(d);
				c[-1] = ']';
				break;
			}
		case ']': puts("UNBALANCED BRACKETS"), exit(0);
		default: o = 0;
		}
		if(p < 0 || p > 100) puts("RANGE ERROR"), exit(0);
	}
	r--;
}

int main(int argc,char **argv)
{
	FILE *z;
	if((z = fopen(argv[1],"r"))) {
		while((b=getc(z)) > 0) *s++ = b;
		*s = 0;
		interpret(f);
	}
}
