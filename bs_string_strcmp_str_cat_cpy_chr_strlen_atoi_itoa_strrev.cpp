#include <stdio.h>
#include <string.h>
#define SZS 128

void my_strcpy(char *src, char *dest)
{
   while (*src != '\0') {
      *dest = *src;
      src++;
      dest++;
   }
   *dest = '\0';
}

void my_strcmp(char *str1, char str2)
{
   int i = 0;
   while (str1[i] != '\0') {
      if (str1[i] != str2[i]) break;
      i++;
   }
   return (str1[i] - str2[i]);
}

int my_atoi(char *str)
{
   int ret_val = 0;
   int digit = 0;
   int c;
   bool minus = false;
   while((c = *str++) != '\0') {
      if (c >= '0' && c <= '9')
         digit = c - '0';
      else if (c == '-')
         minus = true;
      else
         break;
      ret_val = ret_val*10 + digit;
   }
   return (minus)?-(ret_val): ret_val;
}

void my_strrev(char *str)
{
   int len;
   for (len = 0; str[len]; len++);
   char tmp;
   int i;
   for (i = 1; i <= (len-1)/2; i++)
   {
      tmp = str[i], str[i] = str[len-2-i], str[len-2-i] = tmp;
   }
}

void my_itoa(int n, char *str) 
{
   int i = 0;
   if (n < 0) {
      str[i++] = '-';
      (n) = -(n);
   }
   while (n > 0) {
      int k = n%10;
      // do something with k
      str[i++] = k+'\0';
      n /= 10;
   }
   str[i] = '\0';
   my_strrev(str);
}

bool is_pallindrome(char *str, int len)
{
      int i;
      int to = len/2;
      for (i = 0; i < to; i++)
      {
	      if (str[i] != str[len-1-i])
	      {
		      return false;
	      }
      }

      return true;
}

void main()
{
   char s1[80], s2[80];

   gets_s(s1);
   gets_s(s2);

   printf("Lengths : %d %d\n", strlen(s1), strlen(s2));

   if (!strcmp(s1, s2)) printf("The strings are equal.\n");

   strcat(s1, s2);
   printf("%s\n", s1);

   strcpy(s1, "This is a test.\n");
   printf(s1);

   if (strchr("hello", 'e')) printf("e is in hello.\n");
   if (strstr("hi there", "hi")) printf("found hi.\n");

   // String -> Number
   char ss[SZS];
   scanf("%s", ss);
   int num;
   sscanf(sz, "%d", &num);
   printf("converted number = (%d)\n", num);

   // Number -> String
   int num;
   scanf("%d", &num);
   char ss2[SZS];
   sprintf(ss2, "%d", num);
   printf("converted string = (%s)\n", ss2);

}
