# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwooden <mwooden@student.42.us>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/20 15:32:35 by mwooden           #+#    #+#              #
#    Updated: 2017/07/20 15:32:37 by mwooden          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

if len(sys.argv) >= 1:
	sys.exit(0)

print "This is the name of the script: ", sys.argv[0]
print "Number of arguments: ", len(sys.argv)
print "The arguments are: " , sys.argv[1]
