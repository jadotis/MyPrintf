/* Convert the integer D to a string and save the string in BUF. If
   BASE is equal to 'd', interpret that D is decimal, and if BASE is
   equal to 'x', interpret that D is hexadecimal. */

//Provided by Rich West
void itoa (char *buf, int base, int d)
{
  char *p = buf;
  char *p1, *p2;
  unsigned long ud = d;
  int divisor = 10;
     
  /* If %d is specified and D is minus, put `-' in the head. */
  if (base == 'd' && d < 0)
    {
      *p++ = '-';
      buf++;
      ud = -d;
    }
  else if (base == 'x')
    divisor = 16;
     
  /* Divide UD by DIVISOR until UD == 0. */
  do
    {
      int remainder = ud % divisor;
     
      *p++ = (remainder < 10) ? remainder + '0' : remainder + 'a' - 10;
    }
  while (ud /= divisor);
     
  /* Terminate BUF. */
  *p = 0;
     
  /* Reverse BUF. */
  p1 = buf;
  p2 = p - 1;
  while (p1 < p2)
    {
      char tmp = *p1;
      *p1 = *p2;
      *p2 = tmp;
      p1++;
      p2--;
    }
}

void ultoa(unsigned long number, char*buffer)
{
  int i = 0;
  char temporaryBuffer[50];
  if(number == 0)
  {
    temporaryBuffer[i++] = '0';
    temporaryBuffer[i] = 0;
    return;
  }
  while(number != 0)
  {
    int remainder  = number % 10;
    temporaryBuffer[i++] = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';
    number = number / 10;
  }
  temporaryBuffer[i] = 0;
  i--;
  int count = 0;
  while( i > -1)
  {
    buffer[count++] = temporaryBuffer[i--];
  }
  buffer[count] = 0;
}