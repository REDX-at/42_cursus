/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:41:35 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/16 20:35:33 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_shell.h"

int main(int argc, char **argv, char **envp)
{
    char cwd[255];
	const char *filename = "/Users/aitaouss/Desktop/mylink";
    struct stat file_info;
    const char *home_directory = getenv("HOME");
	int flag = 0;
    const char *filefd = "test.txt";
    int fd = open(filefd, O_RDONLY);
    while (1)
	{
        char *input = readline("aitaouss@aitaouss:~$ ");
        
        if (input == NULL)
		{
            printf("\n");
            break;
        }
		if (strcmp(input, "fstat") == 0)
		{
			if (fstat(fd, &file_info) == 0)
			{
        		// Access information in the file_info structure
        		printf("File size: %lld bytes\n", (long long)file_info.st_size);
        		printf("File permissions: %o\n", file_info.st_mode & 0777);
			}
			else
				printf("Error: Could not get file information\n");
			flag = 1;
		}
		if (strcmp(input, "stat") == 0)
		{
			if (stat(filename, &file_info) == 0)
			{
        		// Access information in file_info structure
        		printf("File size: %lld bytes\n", (long long)file_info.st_size);
        		printf("Permissions: %o\n", file_info.st_mode & 0777);
			}
			flag = 1;
		}
		if (strcmp(input, "lstat") == 0)
		{
		    if (lstat(filename, &file_info) == 0)
			{
        		// Access information in the file_info structure
        		printf("File size: %lld bytes\n", (long long)file_info.st_size);
        		printf("Permissions: %o\n", file_info.st_mode & 0777);
			}
			flag = 1;
		}
        if (strcmp(input, "cd") == 0)
		{
            if (home_directory != NULL)
			{
                if (chdir(home_directory) != 0)
                    printf("Error: Could not change to home directory\n");
				else
                    printf("Changed working directory to: %s\n", home_directory);
            }
			else
                printf("Error: HOME environment variable not set\n");
			flag = 1;
        }
		else if (strcmp(input, "exit") == 0)
		{
            printf("The end of the shell\n");
            free(input);
            break;
        }
		else if (strcmp(input, "pwd") == 0)
		{
            if (getcwd(cwd, sizeof(cwd)) != NULL)
                printf("%s\n", cwd);
			flag = 1;
        }
		else if (flag == 0)
            printf("Unknown command: %s\n", input);

        free(input);
    }
	close(fd);
    return 0;
}
