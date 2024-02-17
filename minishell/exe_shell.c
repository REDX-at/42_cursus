/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:41:35 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/17 19:12:52 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_shell.h"

int main(int argc, char **argv, char **envp)
{
	envp = NULL;
    char cwd[255];
	// char *const args[] = {"ls", "/Users/aitaouss/Desktop/cursus/minishell", NULL};
	const char *filename = "/Users/aitaouss/Desktop/remove.txt";
    struct stat file_info;
    const char *home_directory = getenv("HOME");
	int flag = 0;
    const char *filefd = "./file_utils/test.txt";
    const char *filestat = "./file_utils/stat.txt";
    const char *fileslstat = "./file_utils/lstat_link";
    int fd = open(filefd, O_RDONLY);
	// for the dup
	int fd2 = open(filefd, O_RDONLY);
	int new_fd = dup(fd2);
	// for the dir functions
	// const char *dirname = "/Users/aitaouss/Desktop";
	// DIR *dir;
    
    // dir = opendir(dirname);
    // // Read and print the contents of the directory
    // struct dirent *entry = readdir(dir);
    // while ((entry = readdir(dir)) != NULL)
	// {
    //     printf(RED"Name : "RESET"%s | "GREEN"Type : "RESET"%d\n"RESET, entry->d_name, entry->d_type);
	// }
	// if (closedir(dir) == -1)
	// {
	// 	printf("Error: Could not close directory\n");
	// 	return 1;
	// }
	// exit(0);

	// for the getenv
	// const char	*str;
	// str = "PWD";
	// char *homeDirectory = getenv(str);
	// if (homeDirectory != NULL)
	// 	printf(RED"%s directory: "W"%s\n", str, homeDirectory);
	// else
	// 	printf("%s environment variable not set.\n", str);
	// exit(0);
	// for the SHELL
	while (1)
	{
		flag = 0;
        char *input = readline(RED"aitaouss@aitaouss:~$ "RESET);
        
        if (input == NULL)
		{
            printf("\n");
            break;
        }
        if (strcmp(input, "ls") == 0)
        {
            pid_t pid = fork();

            if (pid == -1)
            {
                printf("Error: Could not fork\n");
                exit(EXIT_FAILURE);
            }
            else if (pid == 0)
            {
                // Child process
                char *const args[] = {"ls", "/Users/aitaouss/Desktop", NULL};
                if (execve("/bin/ls", args, envp) == -1)
                {
                    printf("Error: Could not execute ls\n");
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                // Parent process
                int status;
                waitpid(-1, &status, 0);
            }
            flag = 1;
        }
		if (strncmp(input, "echo", 4) == 0)
		{
			pid_t pid = fork();
			if (pid == -1)
			{
				printf("Error: Could not fork\n");
				exit(EXIT_FAILURE);
			}

			if (pid == 0)
			{
				// Child process
				int i = 1;
				char **res = ft_split(input, ' ');
				// while (res[i])
				// {
				// 	printf("the res : %s\n", res[i]);
				// 	i++;
				// }
				// exit(0);
				// i = 1;
				while (res[i] != NULL)
				{
					printf("the res : %s\n", res[i]);
					char *const argf[] = {"echo", res[i], NULL};
					if (execve("/bin/echo", argf, envp) == -1)
					{
						printf("Error: Could not execute echo\n");
						exit(EXIT_FAILURE);
					}
					printf("the res : %s\n", res[i]);
					i++;
				}
			}
			else
			{
				// Parent process
				int status;
				waitpid(-1, &status, 0);
			}
			flag = 1;
		}
		if (strcmp(input, "unlink") == 0)
		{
			if (unlink(filename) == 0)
        		printf("File %s removed successfully.\n", filename);
			else
        		printf("Error: Could not remove file %s\n", filename);
			flag = 1;
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
			if (stat(filestat, &file_info) == 0)
			{
        		// Access information in file_info structure
        		printf("File size: %lld bytes\n", (long long)file_info.st_size);
        		printf("Permissions: %o\n", file_info.st_mode & 0777);
			}
			flag = 1;
		}
		if (strcmp(input, "lstat") == 0)
		{
		    if (lstat(fileslstat, &file_info) == 0)
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
	close(fd2);
	close(new_fd);
	close(fd);
    return 0;
}
