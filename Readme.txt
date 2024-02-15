Main functions:

check_nl: 
  Checks if there is a '\n' in string str
  - returns index of '\n' if yes
  - returns 0 if not

get_str: 
  As long as `\n' not found in string str, string buffer is added to string str using ft_strjoin

get_line:
  Copies all characters of string str to string line until '\n' or the end of string str if there is no '\n'

get_newstr:
  Checks if string str = string line, in which case there is nothing to be done (we are at the end of the file)
  Copies remaining of string str after '\n' to newstr

My change.
