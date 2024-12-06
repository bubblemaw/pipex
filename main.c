/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:08:43 by maw               #+#    #+#             */
/*   Updated: 2024/12/06 17:00:21 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	

}

// #include <sys/types.h>
// #include <unistd.h>
// #include <stdio.h>

// int main() {
//     pid_t pid;

//     pid = fork(); // Fork creates a new process

//     if (pid == -1) {
//         perror("fork failed");
//         return 1;
//     }

//     if (pid == 0) {
//         // Child process
//         printf("I am the child process. My PID is %d\n", getpid());
//     } else {
//         // Parent process
//         printf("I am the parent process. My PID is %d, and my child's PID is %d\n", getpid(), pid);
//     }

//     return 0;
// }
