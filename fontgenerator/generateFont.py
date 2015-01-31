#!/usr/bin/python

import os
from PIL import Image

# welcome to magic number world... 
originalH = 253 # the original heigth of the pics
cropBottom = 14 # how many pixels to chop off at the bottom (253-239)
cropTop    = 46 # how many pixels to chop off at the top    (239-193) 

# the amount of characters in with for the printer
printerW = 42;

# grayscale
# color = "MNHQ$OC?7>!:-;. "
color = "MNmdhyso+/:-.` "


# all characters to convert
charset = " 0123456789.!?:()/ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"


print "Charset: " + charset


# generate all images
# filename = ASCII-Code
for char in charset:

	# generate one pic per char
	cmd = "convert -background white -fill black "
	cmd += "-font ./fonts/SourceCodePro-Bold.otf -pointsize 200 label:\"" + char + "\" "
	cmd += "-compress lzw "
	cmd += "./output/img/temp.tif"
	# cmd += "./output/img/" + str(ord(char)) + ".tif"
	os.system(cmd)

	# crop away the empty pixels
	cmd = "convert ./output/img/temp.tif -gravity south -chop 0x" + str(cropBottom) + " ./output/img/temp2.tif"
	os.system(cmd)
	cmd = "convert ./output/img/temp2.tif -gravity north -chop 0x" + str(cropTop) + " ./output/img/temp3.tif"
	os.system(cmd)
	cmd = "convert ./output/img/temp2.tif -gravity north -chop 0x" + str(cropTop) + " ./output/img/temp3.tif"
	os.system(cmd)

	# resize the pic
	imgname = "./output/img/" + str(ord(char)) + ".png"
	cmd = "convert -resize x" + str(printerW) + " ./output/img/temp3.tif -depth 8 -type truecolor -set colorspace RGB -rotate 90 " 
	cmd += imgname
	os.system(cmd)

    #convert to ASCII

	img = Image.open(imgname)
	try:
	    img = Image.open(imgname)
	except IOError:
	    exit("File not found: " + imgname)


	width, height = img.size

	# get pixels
	pixel = img.load()

	colorLength = len( color ) 

	string = ""

	for h in xrange(height):  # first go through the height,  otherwise will roate
	    for w in xrange(width):
	        rgb = pixel[w, h]
	        string += color[int(sum(rgb) / 3.0 / 256.0 * colorLength)]
	    string += "\n"

	print string


	f = open( "./output/txt/" + str(ord(char)) + ".txt", 'w')
	f.write(string);
	f.close()


print "end"



