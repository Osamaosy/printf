#include "main.h"

/**
 * It clears the fields of the "params" structure and resets the buffer.
 * @params: a pointer to the parameters structure.
 * 
 * @ap: a pointer to the arguments.
 * Return: void.
 */
void init_params(params_t *params, va_list ap)
{
	params->unsign = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)ap;
}
