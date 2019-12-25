#include <stdio.h>
#include "../includes/cube3d.h"

int main(int argc, char *argv[])
{
   FILE *fout;
   int i;

   if ((fout = fopen(argv[1], "w")) == NULL)
   {
    perror("fopen: Could not open file for writing");
	return (false_ret(__func__));
   }

}
