#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

char	*get_next_line(int fd);
char	*THE_READER(int fd,char *unreal);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
int	    ft_strlen(char *s);
char    *EXTRACTEUR_THE_LINE(char *BIG_LINE);
char    *UPDATE_42(char *META);

#endif