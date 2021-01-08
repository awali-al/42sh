/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 23:23:11 by afaraji           #+#    #+#             */
/*   Updated: 2020/12/16 12:58:58 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "ft_21sh.h"

# define STDIN	0
# define STDOUT	1
# define STDERR	2
# define SETDFL	1
# define GETDFL	0
# define SPACE	-1
# define QUOTE	-2
# define DQUOTE	-3
# define SMCLN	-4
# define ANDLG	-5
# define ORLG	-6
# define PIP	-10
# define BGJOB	-11
# define ESCAPE	-12
# define GRT	-20
# define GRTGRT	-21
# define SML	-22
# define SMLSML	-30
# define SMLAND	-24
# define GRTAND	-25
# define WORD	-42
# define BUILTINS	"echo|export|cd|set|setenv|unset|unsetenv|env|exit|alias|"
# define BUILTINS2	"unalias|jobs|fg|bg|test|hash|fc|type"
# define RSRVDWORD	"case|do|done|elif|else|esac|fi|for|if|in|then|until|while"
# ifdef STR
# endif

int				main_parse(char *line);
int				ft_or(int m, int a, int b, int c);
int				ft_print(int fd, char *format, ...);
int				ft_exit(char **av);
void			exit_status(int status);
char			**env_to_tab(t_variable *var, int all);
char			**paths_from_env(void);
int				run_cmd(char **cmd);
int				builtins(char *cmd, char **av, char **env);
int				cd_builtin(char **av, char **env);
t_variable		*get_env(char *s, int typ);
char			*get_var_from_tab(char **env, char *str);
char			*ft_appendstr(char *s1, char *s2);
char			*ft_strsub_delimit(char *s, char c);
int				alias_infinit_loop(char *str, char *s, t_alias *aliases);
int				alias_sub(t_list_token *word, t_alias *aliases);
int				is_reserved(char *str);
int				insert_alias(char *key, char *sub);
t_list_token	*ft_tokenize(char *str);
void			token_print(t_list_token *node);
void			parse_and_replace(t_list_token **cmd_token, t_list_token *node);
int				keywords_alias_sub(t_list_token **cmd_token);
char			*fetch_variables(char *key, int typ);
int				is_assword(char *str);
int				tilde_sub(t_list_token **cmd_token);
int				is_dollar(char *s);
int				end_dollar_word(char *s, int start);
char			*get_dollar_var(char *s, int start, int end);
char			*str_dollar_sub(char *str);
int				dollar_sub(t_list_token **cmd_token);
char			*get_pwd(char **env);
int				lexer(t_list_token **cmd_token);
void			bg_jobs(void);
int				ft_alias(char **av);
int				ft_unalias(char **av);
void			ft_signal(void);
int				init_shell(char **env);
t_hist			*create_history(void);
char			*delete_escape(char *str);
int				system_calls(char *func, int ret, int failure_value);
void			replace_node(t_list_token **dst, t_list_token **src);
char			*fc_history_remove(void);
void			fc_history_add(char *s, int l);
void			*ft_malloc(size_t	size);
int				is_char_in_str(char c, char *s);
int				list_count(t_l *list);
char			**strsplit_str(char const *s, char *c);
char			*free_remove_quot(char *s);
char			*alias_check(char *s, t_alias *list);
char			*err_list_1(int err);
char			*err_list_2(int err);
char			*err_list_3(int err);
char			*err_list_4(int err);
char			*err_list_5(int err);
int				close_quotes(t_list_token *node);
char			*read_to_append(t_list_token *node);
int				history_sub(t_list_token *tokens);
void			singl_quote_escape(char *s);

#endif
