#include <stdio.h>

/**
 * @fn ft_numlen_base
 * @brief calculate the amount of digits of a number
 * @param num an integer to calculate (int or unsigned int)
 * @param base a base number (2, 8, 10, 16, etc.)
 * @return the amount of digits
 */
int	ft_numlen_base(long num, int base)
{
	int	len;

	if (base < 2)
		return (0); // invalid base
	if (num == 0)
		return (1); // zero is one digit
	len = 0;
	if (num < 0)
	{
		num = -num; // convert to unsigned (long is safe)
		len++;      // include minus sign
	}
	while (num)
	{
		num /= base;
		len++;
	}
	return (len);
}
