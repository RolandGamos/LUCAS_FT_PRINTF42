/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 16:50:20 by lweglarz          #+#    #+#             */
/*   Updated: 2020/07/23 16:06:29 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

// Structure de comptage des caractere imprime et de parsin sur le format

typedef struct		s_struct
{
	int		index;
	int		res;

	int		prec;
	int		minus;
	int		width;
	int		zero;
	int		star;
	int		dot;
}					t_struct;

// Structure de mon tableau de fonctions de conversion de caractere

typedef struct		s_tab
{
	char	conv;
	void	(*tabcfunc)(va_list *, t_struct *);
}					t_tab;

//Proto Printf

int			ft_printf(const char *str, ...);

// Fonctions de parsing

void		ft_parse_subspec(const char *str, t_struct *strct, va_list *args);
void		ft_parse(const char *str, t_struct *strct, va_list *args);

//Fonctions de conversions de caractere

void		conv_s(va_list *list, t_struct *strct);
void		conv_id(va_list *list, t_struct *strct);
void		conv_c(va_list *list, t_struct *strct);
void		conv_u(va_list *list, t_struct *strct);
void		conv_x(va_list *list, t_struct *strct);
void		conv_capsx(va_list *list, t_struct *strct);
void		conv_p(va_list *list, t_struct *strct);
void		conv_per(va_list *list, t_struct *strct);

// Fonctions de traitement des specfiers

void		conv_flag_dot(char *str, va_list *args, t_struct *strct);
void		conv_flag_minus(t_struct *strct);
void		conv_flag_star(va_list *args, t_struct *strct);
void		conv_flag_digit(char c, t_struct *strct);

// Utilitaires d'affichage

void		ft_putchar(char c, t_struct *strct);
void		print_string(char *str, t_struct *strct);
void		ft_putstr(char *str, t_struct *strct);
void		ft_putnbr(int nb, t_struct *strct);
void		ft_putnbrprec(int nb, int size, t_struct *strct);
void		ft_puthexax(unsigned long long nbr, t_struct *strct);
void		ft_puthexcapsx(unsigned long long nbr, t_struct *strct);
void		ft_putptr(void *nbr, t_struct *strct);
void		ft_putstrprec(char *str, int size, t_struct *strct);
void		ft_putunsigned(unsigned int nbr, t_struct *strct);
void		print_string(char *str, t_struct *strct);
void	ft_putwidth(t_struct *strct, int width, int size);
void		print_char(char c, t_struct *strct);
int   print_pointer(unsigned long long nbr, t_struct *strct);
void		print_id(int nbr, t_struct *strct);

// Autre utilitaires

size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
long long	number_size(long long nb);
int			ft_isconv(int c);
void		struct_init(t_struct *strct);
void		flags_init(t_struct *strct);
int			ft_is_flag(int c);
int			ft_tolower(int c);
void		ft_print_string(char *str, t_struct *strct);
void		ft_put_minus(char *str, t_struct *strct);
char		*ft_itoa_hexa(unsigned long long n);
void		ft_put_minuspointer(char *str, t_struct *strct);
char		*ft_strdup(const char *s);
void		ft_lowerstr(char *str);
#endif
