/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:54:01 by user              #+#    #+#             */
/*   Updated: 2022/11/29 15:13:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
    int i ;
    i = 0 ;
    if(!s)
        return(0);
    while(s[i] != '\0')
        i++;
    return(i);
}

char    *ft_strchr(char *s, int c)
{
    int     i;
    
    i = 0;
    if (!s)
        return (0);
    if (c == '\0')
        return ((char *)&s[ft_strlen(s)]);
    while (s[i] != '\0')
    {
        if(s[i] == (char) c)
            return ((char *)&s[i]);
        i++;
    }
    return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char    *EXTRACTEUR_THE_LINE(char *BIG_LINE)
{
    char        *str;
    int         i;
    i = 0;
    if (BIG_LINE[i] == '\0')
        return (NULL);
    while (BIG_LINE[i] && BIG_LINE[i] != '\n')
        i++; 
    /* Dans Cette while nous avons calculer len de BIG_LINE Equivalent de strlen*/
    str = (char *)malloc(sizeof(char) * (i + 2)); 
    if (!str)
        return(NULL);
    /* Nous avons allocer avec le size que on a calculer.
     i + 2 ------> une de '\0' et l'autre de converter du index au longeur */
    i = 0;
    while (BIG_LINE[i] != '\0' && BIG_LINE[i] != '\n') 
    {
        str[i] = BIG_LINE[i];
        i++;
    }
    /*il a remplisser le str avec le str de BIG_LINE jusau'a le '\n' || '\0'  
    ex = pedro 1337\toto -----> res = pedro 1337 */
    
    if (BIG_LINE[i] == '\n')
    {
        str[i] = BIG_LINE[i];
        i++;
    }
    str[i] = '\0';
    /* si la raison de ton sorti dans la premiere while et '\n' , remplir encore une fois le str avec '\n' seulement 
    et sort et incrementer pour que je pourrai fermer mon str avec '\0'*/
    return (str);
}
/* Dans cette fonction je stracte le contenue que j'ai donner jusqu'a quelle trouve '\n' or '\0' 
et le pointeur que j'ai declarer c'est le statique variable que je stock qui est Lue par DONCTION READER 
(VA VOIR LA FUNCTION READER )*/

char    *UPDATE_42(char *META)
{
    int i;
    int k;
    char    *str;
    char    *btr;

    i = 0;
    while (META[i] && META[i] != '\n')
        i++;
    if (META[i] == '\0')
    {
        free(META);
        return(NULL);
    }
    /* Si nous n'avons pas trouvé dans le string '\n' on freee le META et on renvoie NULL*/
    btr = (char *)malloc(sizeof(char) * (ft_strlen(META) - i + 1)); 
    /* j'ai allocer le string qui apres '\n' donc nous avonc calculer le size aue nous avons et Nous avons raté i et nous avons ajouter une pour le '\0' */
    if (!btr)
        return (NULL); /*Protection Malloc*/
    i++; /*  */
    k = 0;
    while (META[i]) 
        btr[k++] = META[i++];
    btr[k] = '\0'; /* Nous replissons le btr avec le string qui est apres le '\n' et nous ajoutons '\0' a la fin */
    free(META); /* ON FREE LE META Pour la prochaine operation*/
    return(btr); /* on a returner le "btr" ----->  le string qui apres '\n'*/
}
/* Cette fonction  */
