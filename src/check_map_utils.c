/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgimon-c <mgimon-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 05:00:30 by mgimon-c          #+#    #+#             */
/*   Updated: 2024/12/13 20:26:46 by mgimon-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int get_full_height(char **matrix)
{
    int i;

    i = 0;
    while (matrix[i])
        i++;
    return (i);
}

int check_line_ends(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (1);
    while (str[i] == ' ')
        i++;
    if (str[i] != '1')
        return (1);
    i = ft_strlen(str) - 1;
    while (i >= 0 && str[i] == ' ')
        i--;
    if (str[i] != '1')
        return (1);
    return (0);
}

int get_num_rows(char **matrix)
{
    int rows = 0;
    while (matrix[rows] != NULL)
        rows++;
    return rows;
}

int even_map(char **matrix)
{
    int i;
    int j;
    int k;

    i = 0;
    k = ft_strlen(matrix[i]);
    while (matrix[i])
    {
        j = 0;
        while (matrix[i][j])
            j++;
        if (j != k)
            return (0);
        i++;
    }
    return (1);
}

int validate_holes(char **matrix)
{
    int i, j;

    i = 0;
    while (matrix[i] != NULL)
    {
        j = 0;
        while (matrix[i][j] != '\0')
        {
            if (matrix[i][j] == '0')
            {
                if (matrix[i + 1] != NULL && matrix[i + 1][j] == ' ')
                    return 0;
                if (i > 0 && matrix[i - 1][j] == ' ')
                    return 0;

                if (j > 0 && matrix[i][j - 1] == ' ')
                    return 0;
                if (matrix[i][j + 1] == ' ')
                    return 0;
            }
            j++;
        }
        i++;
    }
    return 1;
}

int validate_chars(char **matrix)
{
    int i;
    int j;

    i = 0;
    if (!matrix)
        return (1);
    while (matrix[i])
    {
        j = 0;
        while (matrix[i][j])
        {
            if (matrix[i][j] != '1' && matrix[i][j] != '0' && matrix[i][j] != ' '
                && matrix[i][j] != 'W' && matrix[i][j] != 'E'
                && matrix[i][j] != 'S' && matrix[i][j] != 'N')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int is_line_empty(char *line)
{
    int i;

    i = 0;
    if (!line)
        return (1);
    if (line[i] == '\0')
        return (1);
    if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
        return (0);
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    if (line[i] == '\0')
        return (1);
    return (0);
}

int map_full_to_bottom(char **matrix)
{
    int i;

    i = 0;
    while(matrix[i])
    {
        if (is_line_empty(matrix[i]))
            return (0);
        i++;
    }
    return (1);
}