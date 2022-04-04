/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_qwerty.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:49:48 by juan              #+#    #+#             */
/*   Updated: 2021/11/24 18:49:49 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_QWERTY_H
# define KEYCODE_QWERTY_H

# ifdef __linux__
#  define KEY_Q 113
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_ECHAP 65307
# elif __APPLE__
#  define PI 3.14159265359
#  define DR 0.01745329252
#  define KEY_ESCAPE 53
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_W 13
#  define KEY_D 2
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define MAPTILE 64
# endif

#endif
