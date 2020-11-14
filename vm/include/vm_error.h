/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_ERROR_H
# define VM_ERROR_H

/*
** number of errors
*/
# define NOE_FD 2

/*
** corewar
*/
# define E_ERR "Error: "
# define E_USAGE "usage: bla-bla-bla"

/*
** functions
*/
# define E_READ "couldn't read bytecode"
# define E_MALLOC "in malloc"
# define E_SSPLIT "in ft_strsplit"
# define E_STRSUB "in strsub"

/*
** parse files
*/
# define E_PAR_MAGIC_HEADER "Error magic header"
# define E_PAR_NAME "Read name"
# define E_PAR_CHAMP_SIZE "Read champ size"
# define E_PAR_COMMENT "Read comment"

#endif
