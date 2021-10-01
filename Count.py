# Python implementation to compute number of characters, words, spaces and lines in a file

# importing os module
import os

def counter(fname):
	
	num_words = 0
	
	num_lines = 0
	
	num_charc = 0
	
	num_spaces = 0
	
	with open(fname, 'r') as f:
	
		for line in f:
			
			line = line.strip(os.linesep)
			
			
			wordslist = line.split()
			
			num_lines = num_lines + 1
			
			
			num_words = num_words + len(wordslist)
			
			num_charc = num_charc + sum(1 for c in line
						if c not in (os.linesep, ' '))
		
			num_spaces = num_spaces + sum(1 for s in line
								if s in (os.linesep, ' '))
	
	print("Number of words in text file: ", num_words)
	
	print("Number of lines in text file: ", num_lines)
	
	print("Number of characters in text file: ", num_charc)
	
	print("Number of spaces in text file: ", num_spaces)
  
if __name__ == '__main__':
	fname = 'File1.txt'
	try:
		counter(fname)
	except:
		print('File not found')
