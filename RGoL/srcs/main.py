# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/19 09:29:25 by mwooden           #+#    #+#              #
#    Updated: 2017/07/19 09:29:27 by mwooden          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import numpy as np

if len(sys.argv) <= 1:
	sys.exit(0)

f_lines = []

with open(sys.argv[1], "r") as file:
	for line in file:
		f_lines.append(line)

start = True if f_lines[0].find("start") != -1 else False
stop = True if f_lines[0].find("stop") != -1 else False

if start == True :
	if stop == True :
		mode = 1
	else :
		mode = 2
elif stop == True :
	mode = 3

# function definitions #

def parse(original, ) :
	split = 
