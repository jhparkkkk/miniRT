/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:27:35 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/12 18:10:18 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"



/*  description : if arg is valid return 0 else print "error\n"
    proto       : int check_arg(char *s) */

/*  description : open file descriptor and while parsing, before allocating any memory
                  check if arg is correct.
    proto       : int parse_arg(int file)
    sub func    : open(int fd), get_next_line(int fd), strcmp(char *s1, char *s2),
                  close(int fd) */

