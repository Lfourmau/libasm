NAME = libasm.a

CC = nasm

FLAGS = -f elf64 #macho64

SRCS = 	srcs/ft_read.s \
		srcs/ft_strcmp.s \
		srcs/ft_strcpy.s \
		srcs/ft_strdup.s \
		srcs/ft_strlen.s \
		srcs/ft_write.s \

OBJS = ${SRCS:.s=.o}

RM = rm -f

%.o : %.s
	${CC} ${FLAGS} $< -o $@

$(NAME) : ${OBJS}
	ar -rcs ${NAME} $?

all : ${NAME}

clean : 
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re