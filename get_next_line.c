#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

char	*THE_READER(int fd,char *unreal)
{
	char *buff;
	int		count_bytes;

buff = malloc((BUFFER_SIZE + 1) * sizeof(char)); /*Nous avon allocer avec le size de BUFFER SIZE que nous avons donner dans le main
 et multiplier par combien de charactere  */
if (!buff)
	return (NULL);

count_bytes = 1; /* debugger variable si counteur de bytes a envoyer -1 ca veut dire que READ() a Failed
si le c_b a envoyer le 0 ca veut dire que n'a rien trouver de liser ou nous avons donner un BUFFER_SIZE plus
grans que le contenu qui faut lire 
et dans le cas normale il faut envoyer une valeur inferieur de 0*/
while (ft_strchr(unreal,'\n') == NULL && count_bytes != 0)
{
	count_bytes = read(fd,buff,BUFFER_SIZE); 
	if (count_bytes == -1)
	{
		free(buff); /* nous avons free le buff car nous avons allocer il est remplie avec un Garbage-value*/
		return (NULL);
	}
	buff[count_bytes] = '\0';
	unreal = ft_strjoin(unreal,buff); /* nous avons joyner car la valeur de static variable et la nouvelle valeur que nous avons lu  */
}
free(buff);
return (unreal);
}
/*j' ai cree cette FUNCTION pour que j'appel la function READ de systeme
 qu'elle Ouvre un fichier descriptor pour me le lire avec un size_buffer specifier
  et elle stock dans le BUFF et le BUFF nous le stockons dans static variable  */

char *get_next_line(int fd)
{
	char	*line;
	static	char	*MINI_LINE; /* le role de statique vaiable est de stocker le contenue envoyer par BUff
	 jusqu'a que la ligne printer et la ligne printer se ecraser du BUFF */

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	MINI_LINE = THE_READER(fd,MINI_LINE); /* nous remplisser le static variable (MINI_LINE)
	 que READ il a lu avec le BUFFER_SIZE que nous avons donne  et il a stocker a le variable unreal et on a renvoier unreal pour 
	 que le static char (mini_line prend la valeur de unreal)*/
	if ( MINI_LINE == NULL)
		return (NULL);
	line = EXTRACTEUR_THE_LINE(MINI_LINE); 
	MINI_LINE = UPDATE_42(MINI_LINE);
	return (line);
}
/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/