
check_nl: 
Checks if there is a '\n' in str
- returns index of '\n' if yes
- returns 0 if not

get_str: 
As long as `\n' not found, adds buffer to str using ft_strjoin

get_line:
copies all characters of str to res until '\n' or the end of str if there is no '\n'

get_newstr:
Checks if str = line, in which case there is nothing to be done (we are at the end of the file)
Copies remaining of str after '\n' to newstr