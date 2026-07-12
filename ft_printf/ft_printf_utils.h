/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:42:23 by vlnikola          #+#    #+#             */
/*   Updated: 2025/11/16 15:42:24 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <stdlib.h>
// utils_1.c
size_t	ft_strlen(char *str);
size_t	ft_putchar_printf(char c);
size_t	ft_putstr_printf(char *str);
void	ft_putnbr_uns_printf(unsigned int n, size_t *len);
void	ft_putnbr_printf(int n, size_t *len);
// utils_2.c
void	ft_putnbr_base_printf(size_t n, char *base, size_t *len);
void	ft_putptr(void *ptr, size_t *len);

#endif
