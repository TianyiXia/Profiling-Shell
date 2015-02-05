// UCLA CS 111 Lab 1 command reading

// Copyright 2012-2014 Paul Eggert.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "command.h"
#include "command-internals.h"
#include <error.h>

int CAPACITY=4096*4096; //assume static for now

/* FIXME: You may need to add #include directives, macro definitions,
   static function definitions, etc.  */
struct cmd_node
{
	command_t cmd;
    struct cmd_node* next;
};

struct command_stream
{
     struct cmd_node* head;
};

command_stream_t init_cmd_stream()
{
    command_stream_t cmd_stream = (command_stream_t) checked_malloc(sizeof(struct command_stream));
    return cmd_stream;
}

/* FIXME: Define the type 'struct command_stream' here.  This should
   complete the incomplete type declaration in command.h.  */
command_stream_t
make_command_stream (int (*get_next_byte) (void *),
		     void *get_next_byte_argument)
{
	/*a string to hold input char*/
	char* buffer=(char *) checked_malloc(CAPACITY*sizeof(char));//static for now
	int buff_size=0;

	/*Read in input to buffer, delete comment, ckeck paren,*/
	buffer=preprocessing(int (*get_next_byte) (void *),void *get_next_byte_argument,&buff_size);
	
	/*make a list of tree's root node, each tree is a complete command*/
	cmd_stream=makeTreeList(buffer);
	
	return cmd_stream;
}

command_t
read_command_stream (command_stream_t s)
{
  /* FIXME: Replace this with your implementation too.  */
  error (1, 0, "command reading not yet implemented");
  return 0;
}

char* preprocessing(int (*get_next_byte) (void *),void *get_next_byte_argument,int* buff_size)
{
	char* buffer;
	char curr_char;
	while ((curr_char = get_next_byte(get_next_byte_argument)) != EOF)
	{
		/*if comment, ignore the entir line*/
		/*change to ptr type*/
		if(curr_char=="#" && (*buff_size==0 || buffer[*buff_size-1]==" " || buffer[*buff_size-1]=="\t"))
		{
			while (((c=get_next_byte(get_next_byte_argument)) != EOF) && (c != '\n'))
			{
				continue;
			}
		}
	
		if(isWord(curr_char) || isSpecialToken(curr_char) || curr_char==" " || curr_char=="\t")
		{
			buffer[*buff_size-1]=curr_char;
			*buff_size+=1;		
		}
	}
}

command_stream_t makeTreeList(char* buffer)
{
	/*command stream initilization*/
	command_stream_t cmd_stream = init_cmd_stream();
	/*		
		if(curr_char=='\n')
		{
			//if prev char is | (pipeline operator), no effect
			
			//if prev is not operator, trate \n as ;, which could be a sequence command
			
			//if prev is new line, i.e two new line, this should be a compelete command
		}*/
}