# Profiling-Shell
This is a course project in CS111: Operating System.
http://cs.ucla.edu/classes/winter15/cs111/assign/lab1.html

We implemented a shell, which is a simplified version of Linux Bash. It also has a profiling feature,
which can provide useful timing information about commands.

The project is divided to 3 stages.

1) Implement Shell reader.
By understanding definition of different types of commands, parse the input into a linked list of complete
commands where each complete command has a recursive tree structure (containing more commands)

2) Implement Shell execution model
After parsing the commands, implement command execution. Make use of recursive call. The base case would be 
execuate a simple command, which is done by forking and calling execvp. 

3) Implement profiling feature.
Make use of Linux timing API, time at appropriate places.
